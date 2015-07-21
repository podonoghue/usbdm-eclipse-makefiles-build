/**
 * @file      pin_mapping.h
 * @version   1.0.0
 * @brief     Pin declarations for MK64F12
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

// <h> FTM Clock settings

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

#define RTC_CLOCK_REG        SIM->SCGC6          
#define RTC_CLOCK_MASK       SIM_SCGC6_RTC_MASK  
#define SPI2_CLOCK_REG       SIM->SCGC3          
#define SPI2_CLOCK_MASK      SIM_SCGC3_SPI2_MASK 
#define SPI0_CLOCK_REG       SIM->SCGC6          
#define SPI0_CLOCK_MASK      SIM_SCGC6_SPI0_MASK 
#define SPI1_CLOCK_REG       SIM->SCGC6          
#define SPI1_CLOCK_MASK      SIM_SCGC6_SPI1_MASK 
#define PDB0_CLOCK_REG       SIM->SCGC6          
#define PDB0_CLOCK_MASK      SIM_SCGC6_PDB0_MASK 
#define FLEXCAN_CLOCK_REG    SIM->SCGC6          
#define FLEXCAN_CLOCK_MASK   SIM_SCGC6_FLEXCAN_MASK
#define MPU_CLOCK_REG        SIM->SCGC7          
#define MPU_CLOCK_MASK       SIM_SCGC7_MPU_MASK  
#define DAC1_CLOCK_REG       SIM->SCGC2          
#define DAC1_CLOCK_MASK      SIM_SCGC2_DAC1_MASK 
#define DAC0_CLOCK_REG       SIM->SCGC6          
#define DAC0_CLOCK_MASK      SIM_SCGC6_DAC0_MASK 
#define SDHC0_CLOCK_REG      SIM->SCGC3          
#define SDHC0_CLOCK_MASK     SIM_SCGC3_SDHC0_MASK
#define DMA_CLOCK_REG        SIM->SCGC7          
#define DMA_CLOCK_MASK       SIM_SCGC7_DMA_MASK  
#define EWM_CLOCK_REG        SIM->SCGC4          
#define EWM_CLOCK_MASK       SIM_SCGC4_EWM_MASK  
#define FLEXBUS_CLOCK_REG    SIM->SCGC7          
#define FLEXBUS_CLOCK_MASK   SIM_SCGC7_FLEXBUS_MASK
#define USBOTG_CLOCK_REG     SIM->SCGC4          
#define USBOTG_CLOCK_MASK    SIM_SCGC4_USBOTG_MASK
#define LPTMR0_CLOCK_REG     SIM->SCGC5          
#define LPTMR0_CLOCK_MASK    SIM_SCGC5_LPTMR_MASK
#define CMP_CLOCK_REG        SIM->SCGC4          
#define CMP_CLOCK_MASK       SIM_SCGC4_CMP_MASK  
#define I2S0_CLOCK_REG       SIM->SCGC6          
#define I2S0_CLOCK_MASK      SIM_SCGC6_I2S0_MASK 
#define UART2_CLOCK_REG      SIM->SCGC4          
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define UART3_CLOCK_REG      SIM->SCGC4          
#define UART3_CLOCK_MASK     SIM_SCGC4_UART3_MASK
#define UART4_CLOCK_REG      SIM->SCGC1          
#define UART4_CLOCK_MASK     SIM_SCGC1_UART4_MASK
#define CMT_CLOCK_REG        SIM->SCGC4          
#define CMT_CLOCK_MASK       SIM_SCGC4_CMT_MASK  
#define UART5_CLOCK_REG      SIM->SCGC1          
#define UART5_CLOCK_MASK     SIM_SCGC1_UART5_MASK
#define ADC0_CLOCK_REG       SIM->SCGC6          
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC0_MASK 
#define UART0_CLOCK_REG      SIM->SCGC4          
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define ADC1_CLOCK_REG       SIM->SCGC3          
#define ADC1_CLOCK_MASK      SIM_SCGC3_ADC1_MASK 
#define UART1_CLOCK_REG      SIM->SCGC4          
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define FTM0_CLOCK_REG       SIM->SCGC6          
#define FTM0_CLOCK_MASK      SIM_SCGC6_FTM0_MASK 
#define RNGA_CLOCK_REG       SIM->SCGC6          
#define RNGA_CLOCK_MASK      SIM_SCGC6_RNGA_MASK 
#define FTM2_CLOCK_REG       SIM->SCGC6          
#define FTM2_CLOCK_MASK      SIM_SCGC6_FTM2_MASK 
#define FTM1_CLOCK_REG       SIM->SCGC6          
#define FTM1_CLOCK_MASK      SIM_SCGC6_FTM1_MASK 
#define FTM3_CLOCK_REG       SIM->SCGC3          
#define FTM3_CLOCK_MASK      SIM_SCGC3_FTM3_MASK 
#define VREF_CLOCK_REG       SIM->SCGC4          
#define VREF_CLOCK_MASK      SIM_SCGC4_VREF_MASK 
#define I2C1_CLOCK_REG       SIM->SCGC4          
#define I2C1_CLOCK_MASK      SIM_SCGC4_I2C1_MASK 
#define I2C0_CLOCK_REG       SIM->SCGC4          
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK 
#define ENET_CLOCK_REG       SIM->SCGC2          
#define ENET_CLOCK_MASK      SIM_SCGC2_ENET_MASK 
#define I2C2_CLOCK_REG       SIM->SCGC1          
#define I2C2_CLOCK_MASK      SIM_SCGC1_I2C2_MASK 
#define PIT_CLOCK_REG        SIM->SCGC6          
#define PIT_CLOCK_MASK       SIM_SCGC6_PIT_MASK  
#define DMAMUX_CLOCK_REG     SIM->SCGC6          
#define DMAMUX_CLOCK_MASK    SIM_SCGC6_DMAMUX_MASK
#define USBDCD_CLOCK_REG     SIM->SCGC6          
#define USBDCD_CLOCK_MASK    SIM_SCGC6_USBDCD_MASK

// <h> Pin Peripheral mapping

// ADC0_10 maps to [Disabled, PTA7]
//   <o> ADC0_10 Pin Selection [PTA7] <constant>
//   <i> Selects which pin is used for ADC0_10
//     <0=> Disabled
//     <1=> PTA7
//     <1=> Default
#define ADC0_10_SEL          1                   

// ADC0_11 maps to [Disabled, PTA8]
//   <o> ADC0_11 Pin Selection [PTA8] <constant>
//   <i> Selects which pin is used for ADC0_11
//     <0=> Disabled
//     <1=> PTA8
//     <1=> Default
#define ADC0_11_SEL          1                   

// ADC0_12 maps to [Disabled, PTB2]
//   <o> ADC0_12 Pin Selection [PTB2(A0)] <constant>
//   <i> Selects which pin is used for ADC0_12
//     <0=> Disabled
//     <1=> PTB2 (Alias: A0)
//     <1=> Default
#define ADC0_12_SEL          1                   

// ADC0_13 maps to [Disabled, PTB3]
//   <o> ADC0_13 Pin Selection [PTB3(A1)] <constant>
//   <i> Selects which pin is used for ADC0_13
//     <0=> Disabled
//     <1=> PTB3 (Alias: A1)
//     <1=> Default
#define ADC0_13_SEL          1                   

// ADC0_14 maps to [Disabled, PTC0]
//   <o> ADC0_14 Pin Selection [PTC0] <constant>
//   <i> Selects which pin is used for ADC0_14
//     <0=> Disabled
//     <1=> PTC0
//     <1=> Default
#define ADC0_14_SEL          1                   

// ADC0_15 maps to [Disabled, PTC1]
//   <o> ADC0_15 Pin Selection [PTC1] <constant>
//   <i> Selects which pin is used for ADC0_15
//     <0=> Disabled
//     <1=> PTC1
//     <1=> Default
#define ADC0_15_SEL          1                   

// ADC0_17 maps to [Disabled, PTE24]
//   <o> ADC0_17 Pin Selection [PTE24(D15)] <constant>
//   <i> Selects which pin is used for ADC0_17
//     <0=> Disabled
//     <1=> PTE24 (Alias: D15)
//     <1=> Default
#define ADC0_17_SEL          1                   

// ADC0_18 maps to [Disabled, PTE25]
//   <o> ADC0_18 Pin Selection [PTE25(D14)] <constant>
//   <i> Selects which pin is used for ADC0_18
//     <0=> Disabled
//     <1=> PTE25 (Alias: D14)
//     <1=> Default
#define ADC0_18_SEL          1                   

// ADC0_21 maps to [Disabled, ADC0_SE16]
//   <o> ADC0_21 Pin Selection [ADC0_SE16] <constant>
//   <i> Selects which pin is used for ADC0_21
//     <0=> Disabled
//     <1=> ADC0_SE16
//     <1=> Default
#define ADC0_21_SEL          1                   

// ADC0_22 maps to [Disabled, ADC1_SE16]
//   <o> ADC0_22 Pin Selection [ADC1_SE16] <constant>
//   <i> Selects which pin is used for ADC0_22
//     <0=> Disabled
//     <1=> ADC1_SE16
//     <1=> Default
#define ADC0_22_SEL          1                   

// ADC0_23 maps to [Disabled, ADC0_SE23]
//   <o> ADC0_23 Pin Selection [ADC0_SE23] <constant>
//   <i> Selects which pin is used for ADC0_23
//     <0=> Disabled
//     <1=> ADC0_SE23
//     <1=> Default
#define ADC0_23_SEL          1                   

// ADC0_4 maps to [Disabled, PTC2]
//   <o> ADC0_4 Pin Selection [PTC2(D6)] <constant>
//   <i> Selects which pin is used for ADC0_4
//     <0=> Disabled
//     <1=> PTC2 (Alias: D6)
//     <1=> Default
#define ADC0_4_SEL           1                   

// ADC0_5 maps to [Disabled, PTD1]
//   <o> ADC0_5 Pin Selection [PTD1(D13)] <constant>
//   <i> Selects which pin is used for ADC0_5
//     <0=> Disabled
//     <1=> PTD1 (Alias: D13)
//     <1=> Default
#define ADC0_5_SEL           1                   

// ADC0_6 maps to [Disabled, PTD5]
//   <o> ADC0_6 Pin Selection [PTD5(nRF24L01_sck)] <constant>
//   <i> Selects which pin is used for ADC0_6
//     <0=> Disabled
//     <1=> PTD5 (Alias: nRF24L01_sck)
//     <1=> Default
#define ADC0_6_SEL           1                   

// ADC0_7 maps to [Disabled, PTD6]
//   <o> ADC0_7 Pin Selection [PTD6(nRF24L01_mosi)] <constant>
//   <i> Selects which pin is used for ADC0_7
//     <0=> Disabled
//     <1=> PTD6 (Alias: nRF24L01_mosi)
//     <1=> Default
#define ADC0_7_SEL           1                   

// ADC1_10 maps to [Disabled, PTB4]
//   <o> ADC1_10 Pin Selection [PTB4] <constant>
//   <i> Selects which pin is used for ADC1_10
//     <0=> Disabled
//     <1=> PTB4
//     <1=> Default
#define ADC1_10_SEL          1                   

// ADC1_11 maps to [Disabled, PTB5]
//   <o> ADC1_11 Pin Selection [PTB5] <constant>
//   <i> Selects which pin is used for ADC1_11
//     <0=> Disabled
//     <1=> PTB5
//     <1=> Default
#define ADC1_11_SEL          1                   

// ADC1_12 maps to [Disabled, PTB6]
//   <o> ADC1_12 Pin Selection [PTB6] <constant>
//   <i> Selects which pin is used for ADC1_12
//     <0=> Disabled
//     <1=> PTB6
//     <1=> Default
#define ADC1_12_SEL          1                   

// ADC1_13 maps to [Disabled, PTB7]
//   <o> ADC1_13 Pin Selection [PTB7] <constant>
//   <i> Selects which pin is used for ADC1_13
//     <0=> Disabled
//     <1=> PTB7
//     <1=> Default
#define ADC1_13_SEL          1                   

// ADC1_14 maps to [Disabled, PTB10]
//   <o> ADC1_14 Pin Selection [PTB10(A2)] <constant>
//   <i> Selects which pin is used for ADC1_14
//     <0=> Disabled
//     <1=> PTB10 (Alias: A2)
//     <1=> Default
#define ADC1_14_SEL          1                   

// ADC1_15 maps to [Disabled, PTB11]
//   <o> ADC1_15 Pin Selection [PTB11(A3)] <constant>
//   <i> Selects which pin is used for ADC1_15
//     <0=> Disabled
//     <1=> PTB11 (Alias: A3)
//     <1=> Default
#define ADC1_15_SEL          1                   

// ADC1_17 maps to [Disabled, PTA17]
//   <o> ADC1_17 Pin Selection [PTA17] <constant>
//   <i> Selects which pin is used for ADC1_17
//     <0=> Disabled
//     <1=> PTA17
//     <1=> Default
#define ADC1_17_SEL          1                   

// ADC1_18 maps to [Disabled, ADC1_SE18]
//   <o> ADC1_18 Pin Selection [ADC1_SE18] <constant>
//   <i> Selects which pin is used for ADC1_18
//     <0=> Disabled
//     <1=> ADC1_SE18
//     <1=> Default
#define ADC1_18_SEL          1                   

// ADC1_23 maps to [Disabled, ADC1_SE23]
//   <o> ADC1_23 Pin Selection [ADC1_SE23] <constant>
//   <i> Selects which pin is used for ADC1_23
//     <0=> Disabled
//     <1=> ADC1_SE23
//     <1=> Default
#define ADC1_23_SEL          1                   

// ADC1_4 maps to [Disabled, PTC8]
//   <o> ADC1_4 Pin Selection [PTC8] <constant>
//   <i> Selects which pin is used for ADC1_4
//     <0=> Disabled
//     <1=> PTC8
//     <1=> Default
#define ADC1_4_SEL           1                   

// ADC1_5 maps to [Disabled, PTC9]
//   <o> ADC1_5 Pin Selection [PTC9] <constant>
//   <i> Selects which pin is used for ADC1_5
//     <0=> Disabled
//     <1=> PTC9
//     <1=> Default
#define ADC1_5_SEL           1                   

// ADC1_6 maps to [Disabled, PTC10]
//   <o> ADC1_6 Pin Selection [PTC10(A5)] <constant>
//   <i> Selects which pin is used for ADC1_6
//     <0=> Disabled
//     <1=> PTC10 (Alias: A5)
//     <1=> Default
#define ADC1_6_SEL           1                   

// ADC1_7 maps to [Disabled, PTC11]
//   <o> ADC1_7 Pin Selection [PTC11(A4)] <constant>
//   <i> Selects which pin is used for ADC1_7
//     <0=> Disabled
//     <1=> PTC11 (Alias: A4)
//     <1=> Default
#define ADC1_7_SEL           1                   

// ADC1_8 maps to [Disabled, PTB0]
//   <o> ADC1_8 Pin Selection [PTB0] <constant>
//   <i> Selects which pin is used for ADC1_8
//     <0=> Disabled
//     <1=> PTB0
//     <1=> Default
#define ADC1_8_SEL           1                   

// ADC1_9 maps to [Disabled, PTB1]
//   <o> ADC1_9 Pin Selection [PTB1] <constant>
//   <i> Selects which pin is used for ADC1_9
//     <0=> Disabled
//     <1=> PTB1
//     <1=> Default
#define ADC1_9_SEL           1                   

// FTM0_0 maps to [Disabled, PTA3, PTC1]
//   <o> FTM0_0 Pin Selection [PTA3, PTC1] 
//   <i> Selects which pin is used for FTM0_0
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTC1
//     <2=> Default
#define FTM0_0_SEL           2                   

// FTM0_1 maps to [Disabled, PTA4, PTC2]
//   <o> FTM0_1 Pin Selection [PTA4, PTC2(D6)] 
//   <i> Selects which pin is used for FTM0_1
//     <0=> Disabled
//     <1=> PTA4
//     <2=> PTC2 (Alias: D6)
//     <2=> Default
#define FTM0_1_SEL           2                   

// FTM0_2 maps to [Disabled, PTA5, PTC3, PTC5]
//   <o> FTM0_2 Pin Selection [PTA5, PTC3(D7), PTC5] 
//   <i> Selects which pin is used for FTM0_2
//     <0=> Disabled
//     <1=> PTA5
//     <2=> PTC3 (Alias: D7)
//     <3=> PTC5
//     <2=> Default
#define FTM0_2_SEL           2                   

// FTM0_3 maps to [Disabled, PTA6, PTC4]
//   <o> FTM0_3 Pin Selection [PTA6, PTC4(D9)] 
//   <i> Selects which pin is used for FTM0_3
//     <0=> Disabled
//     <1=> PTA6
//     <2=> PTC4 (Alias: D9)
//     <2=> Default
#define FTM0_3_SEL           2                   

// FTM0_4 maps to [Disabled, PTA7, PTB12, PTD4]
//   <o> FTM0_4 Pin Selection [PTA7, PTB12, PTD4(nRF24L01_cs)] 
//   <i> Selects which pin is used for FTM0_4
//     <0=> Disabled
//     <1=> PTA7
//     <2=> PTB12
//     <3=> PTD4 (Alias: nRF24L01_cs)
//     <1=> Default
#define FTM0_4_SEL           1                   

// FTM0_5 maps to [Disabled, PTA0, PTB13, PTD5]
//   <o> FTM0_5 Pin Selection [PTA0(D8), PTB13, PTD5(nRF24L01_sck)] 
//   <i> Selects which pin is used for FTM0_5
//     <0=> Disabled
//     <1=> PTA0 (Alias: D8)
//     <2=> PTB13
//     <3=> PTD5 (Alias: nRF24L01_sck)
//     <1=> Default
#define FTM0_5_SEL           1                   

// FTM0_6 maps to [Disabled, PTA1, PTD6]
//   <o> FTM0_6 Pin Selection [PTA1(D3), PTD6(nRF24L01_mosi)] 
//   <i> Selects which pin is used for FTM0_6
//     <0=> Disabled
//     <1=> PTA1 (Alias: D3)
//     <2=> PTD6 (Alias: nRF24L01_mosi)
//     <1=> Default
#define FTM0_6_SEL           1                   

// FTM0_7 maps to [Disabled, PTA2, PTD7]
//   <o> FTM0_7 Pin Selection [PTA2(D5), PTD7(nRF24L01_miso)] 
//   <i> Selects which pin is used for FTM0_7
//     <0=> Disabled
//     <1=> PTA2 (Alias: D5)
//     <2=> PTD7 (Alias: nRF24L01_miso)
//     <1=> Default
#define FTM0_7_SEL           1                   

// FTM1_0 maps to [Disabled, PTA8, PTA12, PTB0, PTB12]
//   <o> FTM1_0 Pin Selection [PTA8, PTA12, PTB0, PTB12] 
//   <i> Selects which pin is used for FTM1_0
//     <0=> Disabled
//     <1=> PTA8
//     <2=> PTA12
//     <3=> PTB0
//     <4=> PTB12
//     <1=> Default
#define FTM1_0_SEL           1                   

// FTM1_1 maps to [Disabled, PTA9, PTA13, PTB1, PTB13]
//   <o> FTM1_1 Pin Selection [PTA9, PTA13, PTB1, PTB13] 
//   <i> Selects which pin is used for FTM1_1
//     <0=> Disabled
//     <1=> PTA9
//     <2=> PTA13
//     <3=> PTB1
//     <4=> PTB13
//     <1=> Default
#define FTM1_1_SEL           1                   

// FTM2_0 maps to [Disabled, PTA10, PTB18]
//   <o> FTM2_0 Pin Selection [PTA10, PTB18] 
//   <i> Selects which pin is used for FTM2_0
//     <0=> Disabled
//     <1=> PTA10
//     <2=> PTB18
//     <1=> Default
#define FTM2_0_SEL           1                   

// FTM2_1 maps to [Disabled, PTA11, PTB19]
//   <o> FTM2_1 Pin Selection [PTA11, PTB19] 
//   <i> Selects which pin is used for FTM2_1
//     <0=> Disabled
//     <1=> PTA11
//     <2=> PTB19
//     <1=> Default
#define FTM2_1_SEL           1                   

// FTM3_0 maps to [Disabled, PTD0, PTE5]
//   <o> FTM3_0 Pin Selection [PTD0(D10), PTE5] 
//   <i> Selects which pin is used for FTM3_0
//     <0=> Disabled
//     <1=> PTD0 (Alias: D10)
//     <2=> PTE5
//     <1=> Default
#define FTM3_0_SEL           1                   

// FTM3_1 maps to [Disabled, PTD1, PTE6]
//   <o> FTM3_1 Pin Selection [PTD1(D13), PTE6] 
//   <i> Selects which pin is used for FTM3_1
//     <0=> Disabled
//     <1=> PTD1 (Alias: D13)
//     <2=> PTE6
//     <1=> Default
#define FTM3_1_SEL           1                   

// FTM3_2 maps to [Disabled, PTD2, PTE7]
//   <o> FTM3_2 Pin Selection [PTD2(D11), PTE7] 
//   <i> Selects which pin is used for FTM3_2
//     <0=> Disabled
//     <1=> PTD2 (Alias: D11)
//     <2=> PTE7
//     <1=> Default
#define FTM3_2_SEL           1                   

// FTM3_3 maps to [Disabled, PTD3, PTE8]
//   <o> FTM3_3 Pin Selection [PTD3(D12), PTE8] 
//   <i> Selects which pin is used for FTM3_3
//     <0=> Disabled
//     <1=> PTD3 (Alias: D12)
//     <2=> PTE8
//     <1=> Default
#define FTM3_3_SEL           1                   

// FTM3_4 maps to [Disabled, PTC8, PTE9]
//   <o> FTM3_4 Pin Selection [PTC8, PTE9] 
//   <i> Selects which pin is used for FTM3_4
//     <0=> Disabled
//     <1=> PTC8
//     <2=> PTE9
//     <1=> Default
#define FTM3_4_SEL           1                   

// FTM3_5 maps to [Disabled, PTC9, PTE10]
//   <o> FTM3_5 Pin Selection [PTC9, PTE10] 
//   <i> Selects which pin is used for FTM3_5
//     <0=> Disabled
//     <1=> PTC9
//     <2=> PTE10
//     <1=> Default
#define FTM3_5_SEL           1                   

// FTM3_6 maps to [Disabled, PTC10, PTE11]
//   <o> FTM3_6 Pin Selection [PTC10(A5), PTE11] 
//   <i> Selects which pin is used for FTM3_6
//     <0=> Disabled
//     <1=> PTC10 (Alias: A5)
//     <2=> PTE11
//     <1=> Default
#define FTM3_6_SEL           1                   

// FTM3_7 maps to [Disabled, PTC11, PTE12]
//   <o> FTM3_7 Pin Selection [PTC11(A4), PTE12] 
//   <i> Selects which pin is used for FTM3_7
//     <0=> Disabled
//     <1=> PTC11 (Alias: A4)
//     <2=> PTE12
//     <1=> Default
#define FTM3_7_SEL           1                   

// I2C0_SCL maps to [Disabled, PTB0, PTB2, PTD2, PTD8, PTE24]
//   <o> I2C0_SCL Pin Selection [PTB0, PTB2(A0), PTD2(D11), PTD8, PTE24(D15)] 
//   <i> Selects which pin is used for I2C0_SCL
//     <0=> Disabled
//     <1=> PTB0
//     <2=> PTB2 (Alias: A0)
//     <3=> PTD2 (Alias: D11)
//     <4=> PTD8
//     <5=> PTE24 (Alias: D15)
//     <5=> Default
#define I2C0_SCL_SEL         5                   

// I2C0_SDA maps to [Disabled, PTB1, PTB3, PTD3, PTD9, PTE25]
//   <o> I2C0_SDA Pin Selection [PTB1, PTB3(A1), PTD3(D12), PTD9, PTE25(D14)] 
//   <i> Selects which pin is used for I2C0_SDA
//     <0=> Disabled
//     <1=> PTB1
//     <2=> PTB3 (Alias: A1)
//     <3=> PTD3 (Alias: D12)
//     <4=> PTD9
//     <5=> PTE25 (Alias: D14)
//     <5=> Default
#define I2C0_SDA_SEL         5                   

// I2C1_SCL maps to [Disabled, PTC10, PTE1]
//   <o> I2C1_SCL Pin Selection [PTC10(A5), PTE1] 
//   <i> Selects which pin is used for I2C1_SCL
//     <0=> Disabled
//     <1=> PTC10 (Alias: A5)
//     <2=> PTE1
//     <1=> Default
#define I2C1_SCL_SEL         1                   

// I2C1_SDA maps to [Disabled, PTC11, PTE0]
//   <o> I2C1_SDA Pin Selection [PTC11(A4), PTE0] 
//   <i> Selects which pin is used for I2C1_SDA
//     <0=> Disabled
//     <1=> PTC11 (Alias: A4)
//     <2=> PTE0
//     <1=> Default
#define I2C1_SDA_SEL         1                   

// I2C2_SCL maps to [Disabled, PTA12, PTA14]
//   <o> I2C2_SCL Pin Selection [PTA12, PTA14] 
//   <i> Selects which pin is used for I2C2_SCL
//     <0=> Disabled
//     <1=> PTA12
//     <2=> PTA14
//     <1=> Default
#define I2C2_SCL_SEL         1                   

// I2C2_SDA maps to [Disabled, PTA11, PTA13]
//   <o> I2C2_SDA Pin Selection [PTA11, PTA13] 
//   <i> Selects which pin is used for I2C2_SDA
//     <0=> Disabled
//     <1=> PTA11
//     <2=> PTA13
//     <1=> Default
#define I2C2_SDA_SEL         1                   

// LPTMR0_1 maps to [Disabled, PTA19]
//   <o> LPTMR0_1 Pin Selection [PTA19] 
//   <i> Selects which pin is used for LPTMR0_1
//     <0=> Disabled
//     <1=> PTA19
//     <0=> Default
#define LPTMR0_1_SEL         0                   

// LPTMR0_2 maps to [Disabled, PTC5]
//   <o> LPTMR0_2 Pin Selection [PTC5] 
//   <i> Selects which pin is used for LPTMR0_2
//     <0=> Disabled
//     <1=> PTC5
//     <0=> Default
#define LPTMR0_2_SEL         0                   

// SDHC0_CLKIN maps to [Disabled, PTD11]
//   <o> SDHC0_CLKIN Pin Selection [PTD11] 
//   <i> Selects which pin is used for SDHC0_CLKIN
//     <0=> Disabled
//     <1=> PTD11
//     <0=> Default
#define SDHC0_CLKIN_SEL      0                   

// SDHC0_CMD maps to [Disabled, PTE3]
//   <o> SDHC0_CMD Pin Selection [PTE3] 
//   <i> Selects which pin is used for SDHC0_CMD
//     <0=> Disabled
//     <1=> PTE3
//     <0=> Default
#define SDHC0_CMD_SEL        0                   

// SDHC0_D0 maps to [Disabled, PTE1]
//   <o> SDHC0_D0 Pin Selection [PTE1] 
//   <i> Selects which pin is used for SDHC0_D0
//     <0=> Disabled
//     <1=> PTE1
//     <0=> Default
#define SDHC0_D0_SEL         0                   

// SDHC0_D1 maps to [Disabled, PTE0]
//   <o> SDHC0_D1 Pin Selection [PTE0] 
//   <i> Selects which pin is used for SDHC0_D1
//     <0=> Disabled
//     <1=> PTE0
//     <0=> Default
#define SDHC0_D1_SEL         0                   

// SDHC0_D2 maps to [Disabled, PTE5]
//   <o> SDHC0_D2 Pin Selection [PTE5] 
//   <i> Selects which pin is used for SDHC0_D2
//     <0=> Disabled
//     <1=> PTE5
//     <0=> Default
#define SDHC0_D2_SEL         0                   

// SDHC0_D3 maps to [Disabled, PTE4]
//   <o> SDHC0_D3 Pin Selection [PTE4] 
//   <i> Selects which pin is used for SDHC0_D3
//     <0=> Disabled
//     <1=> PTE4
//     <0=> Default
#define SDHC0_D3_SEL         0                   

// SDHC0_D4 maps to [Disabled, PTD12]
//   <o> SDHC0_D4 Pin Selection [PTD12] 
//   <i> Selects which pin is used for SDHC0_D4
//     <0=> Disabled
//     <1=> PTD12
//     <0=> Default
#define SDHC0_D4_SEL         0                   

// SDHC0_D5 maps to [Disabled, PTD13]
//   <o> SDHC0_D5 Pin Selection [PTD13] 
//   <i> Selects which pin is used for SDHC0_D5
//     <0=> Disabled
//     <1=> PTD13
//     <0=> Default
#define SDHC0_D5_SEL         0                   

// SDHC0_D6 maps to [Disabled, PTD14]
//   <o> SDHC0_D6 Pin Selection [PTD14] 
//   <i> Selects which pin is used for SDHC0_D6
//     <0=> Disabled
//     <1=> PTD14
//     <0=> Default
#define SDHC0_D6_SEL         0                   

// SDHC0_D7 maps to [Disabled, PTD15]
//   <o> SDHC0_D7 Pin Selection [PTD15] 
//   <i> Selects which pin is used for SDHC0_D7
//     <0=> Disabled
//     <1=> PTD15
//     <0=> Default
#define SDHC0_D7_SEL         0                   

// SDHC0_DCLK maps to [Disabled, PTE2]
//   <o> SDHC0_DCLK Pin Selection [PTE2] 
//   <i> Selects which pin is used for SDHC0_DCLK
//     <0=> Disabled
//     <1=> PTE2
//     <0=> Default
#define SDHC0_DCLK_SEL       0                   

// SPI0_PCS0 maps to [Disabled, PTA14, PTC4, PTD0]
//   <o> SPI0_PCS0 Pin Selection [PTA14, PTC4(D9), PTD0(D10)] 
//   <i> Selects which pin is used for SPI0_PCS0
//     <0=> Disabled
//     <1=> PTA14
//     <2=> PTC4 (Alias: D9)
//     <3=> PTD0 (Alias: D10)
//     <0=> Default
#define SPI0_PCS0_SEL        0                   

// SPI0_PCS1 maps to [Disabled, PTC3, PTD4]
//   <o> SPI0_PCS1 Pin Selection [PTC3(D7), PTD4(nRF24L01_cs)] 
//   <i> Selects which pin is used for SPI0_PCS1
//     <0=> Disabled
//     <1=> PTC3 (Alias: D7)
//     <2=> PTD4 (Alias: nRF24L01_cs)
//     <0=> Default
#define SPI0_PCS1_SEL        0                   

// SPI0_PCS2 maps to [Disabled, PTC2, PTD5]
//   <o> SPI0_PCS2 Pin Selection [PTC2(D6), PTD5(nRF24L01_sck)] 
//   <i> Selects which pin is used for SPI0_PCS2
//     <0=> Disabled
//     <1=> PTC2 (Alias: D6)
//     <2=> PTD5 (Alias: nRF24L01_sck)
//     <0=> Default
#define SPI0_PCS2_SEL        0                   

// SPI0_PCS3 maps to [Disabled, PTC1, PTD6]
//   <o> SPI0_PCS3 Pin Selection [PTC1, PTD6(nRF24L01_mosi)] 
//   <i> Selects which pin is used for SPI0_PCS3
//     <0=> Disabled
//     <1=> PTC1
//     <2=> PTD6 (Alias: nRF24L01_mosi)
//     <0=> Default
#define SPI0_PCS3_SEL        0                   

// SPI0_PCS4 maps to [Disabled, PTC0]
//   <o> SPI0_PCS4 Pin Selection [PTC0] 
//   <i> Selects which pin is used for SPI0_PCS4
//     <0=> Disabled
//     <1=> PTC0
//     <0=> Default
#define SPI0_PCS4_SEL        0                   

// SPI0_PCS5 maps to [Disabled, PTB23]
//   <o> SPI0_PCS5 Pin Selection [PTB23(D4)] 
//   <i> Selects which pin is used for SPI0_PCS5
//     <0=> Disabled
//     <1=> PTB23 (Alias: D4)
//     <0=> Default
#define SPI0_PCS5_SEL        0                   

// SPI0_SCK maps to [Disabled, PTA15, PTC5, PTD1]
//   <o> SPI0_SCK Pin Selection [PTA15, PTC5, PTD1(D13)] 
//   <i> Selects which pin is used for SPI0_SCK
//     <0=> Disabled
//     <1=> PTA15
//     <2=> PTC5
//     <3=> PTD1 (Alias: D13)
//     <3=> Default
#define SPI0_SCK_SEL         3                   

// SPI0_SIN maps to [Disabled, PTA17, PTC7, PTD3]
//   <o> SPI0_SIN Pin Selection [PTA17, PTC7, PTD3(D12)] 
//   <i> Selects which pin is used for SPI0_SIN
//     <0=> Disabled
//     <1=> PTA17
//     <2=> PTC7
//     <3=> PTD3 (Alias: D12)
//     <3=> Default
#define SPI0_SIN_SEL         3                   

// SPI0_SOUT maps to [Disabled, PTA16, PTC6, PTD2]
//   <o> SPI0_SOUT Pin Selection [PTA16, PTC6, PTD2(D11)] 
//   <i> Selects which pin is used for SPI0_SOUT
//     <0=> Disabled
//     <1=> PTA16
//     <2=> PTC6
//     <3=> PTD2 (Alias: D11)
//     <3=> Default
#define SPI0_SOUT_SEL        3                   

// SPI1_PCS0 maps to [Disabled, PTB10, PTD4, PTE4]
//   <o> SPI1_PCS0 Pin Selection [PTB10(A2), PTD4(nRF24L01_cs), PTE4] 
//   <i> Selects which pin is used for SPI1_PCS0
//     <0=> Disabled
//     <1=> PTB10 (Alias: A2)
//     <2=> PTD4 (Alias: nRF24L01_cs)
//     <3=> PTE4
//     <2=> Default
#define SPI1_PCS0_SEL        2                   

// SPI1_PCS1 maps to [Disabled, PTB9, PTE0]
//   <o> SPI1_PCS1 Pin Selection [PTB9(D2), PTE0] 
//   <i> Selects which pin is used for SPI1_PCS1
//     <0=> Disabled
//     <1=> PTB9 (Alias: D2)
//     <2=> PTE0
//     <0=> Default
#define SPI1_PCS1_SEL        0                   

// SPI1_PCS2 maps to [Disabled, PTE5]
//   <o> SPI1_PCS2 Pin Selection [PTE5] 
//   <i> Selects which pin is used for SPI1_PCS2
//     <0=> Disabled
//     <1=> PTE5
//     <0=> Default
#define SPI1_PCS2_SEL        0                   

// SPI1_PCS3 maps to [Disabled, PTE6]
//   <o> SPI1_PCS3 Pin Selection [PTE6] 
//   <i> Selects which pin is used for SPI1_PCS3
//     <0=> Disabled
//     <1=> PTE6
//     <0=> Default
#define SPI1_PCS3_SEL        0                   

// SPI1_SCK maps to [Disabled, PTB11, PTD5, PTE2]
//   <o> SPI1_SCK Pin Selection [PTB11(A3), PTD5(nRF24L01_sck), PTE2] 
//   <i> Selects which pin is used for SPI1_SCK
//     <0=> Disabled
//     <1=> PTB11 (Alias: A3)
//     <2=> PTD5 (Alias: nRF24L01_sck)
//     <3=> PTE2
//     <2=> Default
#define SPI1_SCK_SEL         2                   

// SPI1_SIN maps to [Disabled, PTB17, PTD7, PTE1, PTE3]
//   <o> SPI1_SIN Pin Selection [PTB17, PTD7(nRF24L01_miso), PTE1, PTE3] 
//   <i> Selects which pin is used for SPI1_SIN
//     <0=> Disabled
//     <1=> PTB17
//     <2=> PTD7 (Alias: nRF24L01_miso)
//     <3=> PTE1
//     <4=> PTE3
//     <2=> Default
#define SPI1_SIN_SEL         2                   

// SPI1_SOUT maps to [Disabled, PTB16, PTD6, PTE1, PTE3]
//   <o> SPI1_SOUT Pin Selection [PTB16, PTD6(nRF24L01_mosi), PTE1, PTE3] 
//   <i> Selects which pin is used for SPI1_SOUT
//     <0=> Disabled
//     <1=> PTB16
//     <2=> PTD6 (Alias: nRF24L01_mosi)
//     <3=> PTE1
//     <4=> PTE3
//     <2=> Default
#define SPI1_SOUT_SEL        2                   

// SPI2_PCS0 maps to [Disabled, PTB20, PTD11]
//   <o> SPI2_PCS0 Pin Selection [PTB20, PTD11] 
//   <i> Selects which pin is used for SPI2_PCS0
//     <0=> Disabled
//     <1=> PTB20
//     <2=> PTD11
//     <0=> Default
#define SPI2_PCS0_SEL        0                   

// SPI2_PCS1 maps to [Disabled, PTD15]
//   <o> SPI2_PCS1 Pin Selection [PTD15] 
//   <i> Selects which pin is used for SPI2_PCS1
//     <0=> Disabled
//     <1=> PTD15
//     <0=> Default
#define SPI2_PCS1_SEL        0                   

// SPI2_SCK maps to [Disabled, PTB21, PTD12]
//   <o> SPI2_SCK Pin Selection [PTB21, PTD12] 
//   <i> Selects which pin is used for SPI2_SCK
//     <0=> Disabled
//     <1=> PTB21
//     <2=> PTD12
//     <1=> Default
#define SPI2_SCK_SEL         1                   

// SPI2_SIN maps to [Disabled, PTB23, PTD14]
//   <o> SPI2_SIN Pin Selection [PTB23(D4), PTD14] 
//   <i> Selects which pin is used for SPI2_SIN
//     <0=> Disabled
//     <1=> PTB23 (Alias: D4)
//     <2=> PTD14
//     <1=> Default
#define SPI2_SIN_SEL         1                   

// SPI2_SOUT maps to [Disabled, PTB22, PTD13]
//   <o> SPI2_SOUT Pin Selection [PTB22, PTD13] 
//   <i> Selects which pin is used for SPI2_SOUT
//     <0=> Disabled
//     <1=> PTB22
//     <2=> PTD13
//     <1=> Default
#define SPI2_SOUT_SEL        1                   

// ADC0_DM0

// ADC0_DM1

// ADC0_DP0

// ADC0_DP1

// ADC0_SE16 = ADC0_21
#define ADC0_SE16_ADC_NUM          0     //!< ADC0_SE16 ADC number
#define ADC0_SE16_ADC_CH           21    //!< ADC0_SE16 ADC channel

// ADC0_SE23 = ADC0_23
#define ADC0_SE23_ADC_NUM          0     //!< ADC0_SE23 ADC number
#define ADC0_SE23_ADC_CH           23    //!< ADC0_SE23 ADC channel

// ADC1_DM0

// ADC1_DM1

// ADC1_DP0

// ADC1_DP1

// ADC1_SE16 = ADC0_22
#define ADC1_SE16_ADC_NUM          0     //!< ADC1_SE16 ADC number
#define ADC1_SE16_ADC_CH           22    //!< ADC1_SE16 ADC channel

// ADC1_SE18 = ADC1_18
#define ADC1_SE18_ADC_NUM          1     //!< ADC1_SE18 ADC number
#define ADC1_SE18_ADC_CH           18    //!< ADC1_SE18 ADC channel

// ADC1_SE23 = ADC1_23
#define ADC1_SE23_ADC_NUM          1     //!< ADC1_SE23 ADC number
#define ADC1_SE23_ADC_CH           23    //!< ADC1_SE23 ADC channel

// PTA0 = FTM0_5 (Alias: D8)
#define PTA0_PORT                  A     //!< PTA0 Port name
#define PTA0_NUM                   0     //!< PTA0 Port number
#if FTM0_5_SEL == 1
#define PTA0_FTM_NUM               0     //!< PTA0 FTM number
#define PTA0_FTM_CH                5     //!< PTA0 FTM channel
#define PTA0_FTM_FN                3     //!< PTA0 Pin multiplexor for FTM
#endif

// PTA1 = FTM0_6 (Alias: D3)
#define PTA1_PORT                  A     //!< PTA1 Port name
#define PTA1_NUM                   1     //!< PTA1 Port number
#if FTM0_6_SEL == 1
#define PTA1_FTM_NUM               0     //!< PTA1 FTM number
#define PTA1_FTM_CH                6     //!< PTA1 FTM channel
#define PTA1_FTM_FN                3     //!< PTA1 Pin multiplexor for FTM
#endif

// PTA2 = FTM0_7 (Alias: D5)
#define PTA2_PORT                  A     //!< PTA2 Port name
#define PTA2_NUM                   2     //!< PTA2 Port number
#if FTM0_7_SEL == 1
#define PTA2_FTM_NUM               0     //!< PTA2 FTM number
#define PTA2_FTM_CH                7     //!< PTA2 FTM channel
#define PTA2_FTM_FN                3     //!< PTA2 Pin multiplexor for FTM
#endif

// PTA3 = FTM0_0
#define PTA3_PORT                  A     //!< PTA3 Port name
#define PTA3_NUM                   3     //!< PTA3 Port number
#if FTM0_0_SEL == 1
#define PTA3_FTM_NUM               0     //!< PTA3 FTM number
#define PTA3_FTM_CH                0     //!< PTA3 FTM channel
#define PTA3_FTM_FN                3     //!< PTA3 Pin multiplexor for FTM
#endif

// PTA4 = FTM0_1
#define PTA4_PORT                  A     //!< PTA4 Port name
#define PTA4_NUM                   4     //!< PTA4 Port number
#if FTM0_1_SEL == 1
#define PTA4_FTM_NUM               0     //!< PTA4 FTM number
#define PTA4_FTM_CH                1     //!< PTA4 FTM channel
#define PTA4_FTM_FN                3     //!< PTA4 Pin multiplexor for FTM
#endif

// PTA5 = FTM0_2
#define PTA5_PORT                  A     //!< PTA5 Port name
#define PTA5_NUM                   5     //!< PTA5 Port number
#if FTM0_2_SEL == 1
#define PTA5_FTM_NUM               0     //!< PTA5 FTM number
#define PTA5_FTM_CH                2     //!< PTA5 FTM channel
#define PTA5_FTM_FN                3     //!< PTA5 Pin multiplexor for FTM
#endif

// PTA6 = FTM0_3
#define PTA6_PORT                  A     //!< PTA6 Port name
#define PTA6_NUM                   6     //!< PTA6 Port number
#if FTM0_3_SEL == 1
#define PTA6_FTM_NUM               0     //!< PTA6 FTM number
#define PTA6_FTM_CH                3     //!< PTA6 FTM channel
#define PTA6_FTM_FN                3     //!< PTA6 Pin multiplexor for FTM
#endif

// PTA7 = ADC0_10,FTM0_4
#define PTA7_PORT                  A     //!< PTA7 Port name
#define PTA7_NUM                   7     //!< PTA7 Port number
#define PTA7_ADC_NUM               0     //!< PTA7 ADC number
#define PTA7_ADC_CH                10    //!< PTA7 ADC channel
#if FTM0_4_SEL == 1
#define PTA7_FTM_NUM               0     //!< PTA7 FTM number
#define PTA7_FTM_CH                4     //!< PTA7 FTM channel
#define PTA7_FTM_FN                3     //!< PTA7 Pin multiplexor for FTM
#endif

// PTA8 = ADC0_11,FTM1_0
#define PTA8_PORT                  A     //!< PTA8 Port name
#define PTA8_NUM                   8     //!< PTA8 Port number
#define PTA8_ADC_NUM               0     //!< PTA8 ADC number
#define PTA8_ADC_CH                11    //!< PTA8 ADC channel
#if FTM1_0_SEL == 1
#define PTA8_FTM_NUM               1     //!< PTA8 FTM number
#define PTA8_FTM_CH                0     //!< PTA8 FTM channel
#define PTA8_FTM_FN                3     //!< PTA8 Pin multiplexor for FTM
#endif

// PTA9 = FTM1_1
#define PTA9_PORT                  A     //!< PTA9 Port name
#define PTA9_NUM                   9     //!< PTA9 Port number
#if FTM1_1_SEL == 1
#define PTA9_FTM_NUM               1     //!< PTA9 FTM number
#define PTA9_FTM_CH                1     //!< PTA9 FTM channel
#define PTA9_FTM_FN                3     //!< PTA9 Pin multiplexor for FTM
#endif

// PTA10 = FTM2_0
#define PTA10_PORT                 A     //!< PTA10 Port name
#define PTA10_NUM                  10    //!< PTA10 Port number
#if FTM2_0_SEL == 1
#define PTA10_FTM_NUM              2     //!< PTA10 FTM number
#define PTA10_FTM_CH               0     //!< PTA10 FTM channel
#define PTA10_FTM_FN               3     //!< PTA10 Pin multiplexor for FTM
#endif

// PTA11 = FTM2_1,I2C2_SDA
#define PTA11_PORT                 A     //!< PTA11 Port name
#define PTA11_NUM                  11    //!< PTA11 Port number
#if FTM2_1_SEL == 1
#define PTA11_FTM_NUM              2     //!< PTA11 FTM number
#define PTA11_FTM_CH               1     //!< PTA11 FTM channel
#define PTA11_FTM_FN               3     //!< PTA11 Pin multiplexor for FTM
#endif
#if I2C2_SDA_SEL == 1
#define I2C2_SDA_FN                5     //!< PTA11 Pin multiplexor for I2C
#define I2C2_SDA_GPIO              digitalIO_PTA11   //!< PTA11 I2C GPIO
#endif

// PTA12 = FTM1_0,I2C2_SCL
#define PTA12_PORT                 A     //!< PTA12 Port name
#define PTA12_NUM                  12    //!< PTA12 Port number
#if FTM1_0_SEL == 2
#define PTA12_FTM_NUM              1     //!< PTA12 FTM number
#define PTA12_FTM_CH               0     //!< PTA12 FTM channel
#define PTA12_FTM_FN               3     //!< PTA12 Pin multiplexor for FTM
#endif
#if I2C2_SCL_SEL == 1
#define I2C2_SCL_FN                5     //!< PTA12 Pin multiplexor for I2C
#define I2C2_SCL_GPIO              digitalIO_PTA12   //!< PTA12 I2C GPIO
#endif

// PTA13 = FTM1_1,I2C2_SDA
#define PTA13_PORT                 A     //!< PTA13 Port name
#define PTA13_NUM                  13    //!< PTA13 Port number
#if FTM1_1_SEL == 2
#define PTA13_FTM_NUM              1     //!< PTA13 FTM number
#define PTA13_FTM_CH               1     //!< PTA13 FTM channel
#define PTA13_FTM_FN               3     //!< PTA13 Pin multiplexor for FTM
#endif
#if I2C2_SDA_SEL == 2
#define I2C2_SDA_FN                5     //!< PTA13 Pin multiplexor for I2C
#define I2C2_SDA_GPIO              digitalIO_PTA13   //!< PTA13 I2C GPIO
#endif

// PTA14 = SPI0_PCS0,I2C2_SCL
#define PTA14_PORT                 A     //!< PTA14 Port name
#define PTA14_NUM                  14    //!< PTA14 Port number
#if SPI0_PCS0_SEL == 1
#define SPI0_PCS0_FN               2     //!< PTA14 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTA14   //!< PTA14 SPI GPIO
#endif
#if I2C2_SCL_SEL == 2
#define I2C2_SCL_FN                5     //!< PTA14 Pin multiplexor for I2C
#define I2C2_SCL_GPIO              digitalIO_PTA14   //!< PTA14 I2C GPIO
#endif

// PTA15 = SPI0_SCK
#define PTA15_PORT                 A     //!< PTA15 Port name
#define PTA15_NUM                  15    //!< PTA15 Port number
#if SPI0_SCK_SEL == 1
#define SPI0_SCK_FN                2     //!< PTA15 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTA15   //!< PTA15 SPI GPIO
#endif

// PTA16 = SPI0_SOUT
#define PTA16_PORT                 A     //!< PTA16 Port name
#define PTA16_NUM                  16    //!< PTA16 Port number
#if SPI0_SOUT_SEL == 1
#define SPI0_SOUT_FN               2     //!< PTA16 Pin multiplexor for SPI
#define SPI0_SOUT_GPIO             digitalIO_PTA16   //!< PTA16 SPI GPIO
#endif

// PTA17 = ADC1_17,SPI0_SIN
#define PTA17_PORT                 A     //!< PTA17 Port name
#define PTA17_NUM                  17    //!< PTA17 Port number
#define PTA17_ADC_NUM              1     //!< PTA17 ADC number
#define PTA17_ADC_CH               17    //!< PTA17 ADC channel
#if SPI0_SIN_SEL == 1
#define SPI0_SIN_FN                2     //!< PTA17 Pin multiplexor for SPI
#define SPI0_SIN_GPIO              digitalIO_PTA17   //!< PTA17 SPI GPIO
#endif

// PTA18
#define PTA18_PORT                 A     //!< PTA18 Port name
#define PTA18_NUM                  18    //!< PTA18 Port number

// PTA19 = LPTMR0_1
#define PTA19_PORT                 A     //!< PTA19 Port name
#define PTA19_NUM                  19    //!< PTA19 Port number
#if LPTMR0_1_SEL == 1
#define LPTMR0_1_FN                6     //!< PTA19 Pin multiplexor for LPTMR
#define LPTMR0_1_GPIO              digitalIO_PTA19   //!< PTA19 LPTMR GPIO
#endif

// PTA24
#define PTA24_PORT                 A     //!< PTA24 Port name
#define PTA24_NUM                  24    //!< PTA24 Port number

// PTA25
#define PTA25_PORT                 A     //!< PTA25 Port name
#define PTA25_NUM                  25    //!< PTA25 Port number

// PTA26
#define PTA26_PORT                 A     //!< PTA26 Port name
#define PTA26_NUM                  26    //!< PTA26 Port number

// PTA27
#define PTA27_PORT                 A     //!< PTA27 Port name
#define PTA27_NUM                  27    //!< PTA27 Port number

// PTA28
#define PTA28_PORT                 A     //!< PTA28 Port name
#define PTA28_NUM                  28    //!< PTA28 Port number

// PTA29
#define PTA29_PORT                 A     //!< PTA29 Port name
#define PTA29_NUM                  29    //!< PTA29 Port number

// PTB0 = ADC1_8,FTM1_0,I2C0_SCL
#define PTB0_PORT                  B     //!< PTB0 Port name
#define PTB0_NUM                   0     //!< PTB0 Port number
#define PTB0_ADC_NUM               1     //!< PTB0 ADC number
#define PTB0_ADC_CH                8     //!< PTB0 ADC channel
#if FTM1_0_SEL == 3
#define PTB0_FTM_NUM               1     //!< PTB0 FTM number
#define PTB0_FTM_CH                0     //!< PTB0 FTM channel
#define PTB0_FTM_FN                3     //!< PTB0 Pin multiplexor for FTM
#endif
#if I2C0_SCL_SEL == 1
#define I2C0_SCL_FN                2     //!< PTB0 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB0   //!< PTB0 I2C GPIO
#endif

// PTB1 = ADC1_9,FTM1_1,I2C0_SDA
#define PTB1_PORT                  B     //!< PTB1 Port name
#define PTB1_NUM                   1     //!< PTB1 Port number
#define PTB1_ADC_NUM               1     //!< PTB1 ADC number
#define PTB1_ADC_CH                9     //!< PTB1 ADC channel
#if FTM1_1_SEL == 3
#define PTB1_FTM_NUM               1     //!< PTB1 FTM number
#define PTB1_FTM_CH                1     //!< PTB1 FTM channel
#define PTB1_FTM_FN                3     //!< PTB1 Pin multiplexor for FTM
#endif
#if I2C0_SDA_SEL == 1
#define I2C0_SDA_FN                2     //!< PTB1 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB1   //!< PTB1 I2C GPIO
#endif

// PTB2 = ADC0_12,I2C0_SCL (Alias: A0)
#define PTB2_PORT                  B     //!< PTB2 Port name
#define PTB2_NUM                   2     //!< PTB2 Port number
#define PTB2_ADC_NUM               0     //!< PTB2 ADC number
#define PTB2_ADC_CH                12    //!< PTB2 ADC channel
#if I2C0_SCL_SEL == 2
#define I2C0_SCL_FN                2     //!< PTB2 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB2   //!< PTB2 I2C GPIO
#endif

// PTB3 = ADC0_13,I2C0_SDA (Alias: A1)
#define PTB3_PORT                  B     //!< PTB3 Port name
#define PTB3_NUM                   3     //!< PTB3 Port number
#define PTB3_ADC_NUM               0     //!< PTB3 ADC number
#define PTB3_ADC_CH                13    //!< PTB3 ADC channel
#if I2C0_SDA_SEL == 2
#define I2C0_SDA_FN                2     //!< PTB3 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB3   //!< PTB3 I2C GPIO
#endif

// PTB4 = ADC1_10
#define PTB4_PORT                  B     //!< PTB4 Port name
#define PTB4_NUM                   4     //!< PTB4 Port number
#define PTB4_ADC_NUM               1     //!< PTB4 ADC number
#define PTB4_ADC_CH                10    //!< PTB4 ADC channel

// PTB5 = ADC1_11
#define PTB5_PORT                  B     //!< PTB5 Port name
#define PTB5_NUM                   5     //!< PTB5 Port number
#define PTB5_ADC_NUM               1     //!< PTB5 ADC number
#define PTB5_ADC_CH                11    //!< PTB5 ADC channel

// PTB6 = ADC1_12
#define PTB6_PORT                  B     //!< PTB6 Port name
#define PTB6_NUM                   6     //!< PTB6 Port number
#define PTB6_ADC_NUM               1     //!< PTB6 ADC number
#define PTB6_ADC_CH                12    //!< PTB6 ADC channel

// PTB7 = ADC1_13
#define PTB7_PORT                  B     //!< PTB7 Port name
#define PTB7_NUM                   7     //!< PTB7 Port number
#define PTB7_ADC_NUM               1     //!< PTB7 ADC number
#define PTB7_ADC_CH                13    //!< PTB7 ADC channel

// PTB8
#define PTB8_PORT                  B     //!< PTB8 Port name
#define PTB8_NUM                   8     //!< PTB8 Port number

// PTB9 = SPI1_PCS1 (Alias: D2)
#define PTB9_PORT                  B     //!< PTB9 Port name
#define PTB9_NUM                   9     //!< PTB9 Port number
#if SPI1_PCS1_SEL == 1
#define SPI1_PCS1_FN               2     //!< PTB9 Pin multiplexor for SPI
#define SPI1_PCS1_GPIO             digitalIO_PTB9   //!< PTB9 SPI GPIO
#endif

// PTB10 = ADC1_14,SPI1_PCS0 (Alias: A2)
#define PTB10_PORT                 B     //!< PTB10 Port name
#define PTB10_NUM                  10    //!< PTB10 Port number
#define PTB10_ADC_NUM              1     //!< PTB10 ADC number
#define PTB10_ADC_CH               14    //!< PTB10 ADC channel
#if SPI1_PCS0_SEL == 1
#define SPI1_PCS0_FN               2     //!< PTB10 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTB10   //!< PTB10 SPI GPIO
#endif

// PTB11 = ADC1_15,SPI1_SCK (Alias: A3)
#define PTB11_PORT                 B     //!< PTB11 Port name
#define PTB11_NUM                  11    //!< PTB11 Port number
#define PTB11_ADC_NUM              1     //!< PTB11 ADC number
#define PTB11_ADC_CH               15    //!< PTB11 ADC channel
#if SPI1_SCK_SEL == 1
#define SPI1_SCK_FN                2     //!< PTB11 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTB11   //!< PTB11 SPI GPIO
#endif

// PTB12 = FTM1_0,FTM0_4
#define PTB12_PORT                 B     //!< PTB12 Port name
#define PTB12_NUM                  12    //!< PTB12 Port number
#if FTM1_0_SEL == 4
#define PTB12_FTM_NUM              1     //!< PTB12 FTM number
#define PTB12_FTM_CH               0     //!< PTB12 FTM channel
#define PTB12_FTM_FN               3     //!< PTB12 Pin multiplexor for FTM
#endif
#if FTM0_4_SEL == 2
#define PTB12_FTM_NUM              0     //!< PTB12 FTM number
#define PTB12_FTM_CH               4     //!< PTB12 FTM channel
#define PTB12_FTM_FN               4     //!< PTB12 Pin multiplexor for FTM
#endif

// PTB13 = FTM1_1,FTM0_5
#define PTB13_PORT                 B     //!< PTB13 Port name
#define PTB13_NUM                  13    //!< PTB13 Port number
#if FTM1_1_SEL == 4
#define PTB13_FTM_NUM              1     //!< PTB13 FTM number
#define PTB13_FTM_CH               1     //!< PTB13 FTM channel
#define PTB13_FTM_FN               3     //!< PTB13 Pin multiplexor for FTM
#endif
#if FTM0_5_SEL == 2
#define PTB13_FTM_NUM              0     //!< PTB13 FTM number
#define PTB13_FTM_CH               5     //!< PTB13 FTM channel
#define PTB13_FTM_FN               4     //!< PTB13 Pin multiplexor for FTM
#endif

// PTB16 = SPI1_SOUT
#define PTB16_PORT                 B     //!< PTB16 Port name
#define PTB16_NUM                  16    //!< PTB16 Port number
#if SPI1_SOUT_SEL == 1
#define SPI1_SOUT_FN               2     //!< PTB16 Pin multiplexor for SPI
#define SPI1_SOUT_GPIO             digitalIO_PTB16   //!< PTB16 SPI GPIO
#endif

// PTB17 = SPI1_SIN
#define PTB17_PORT                 B     //!< PTB17 Port name
#define PTB17_NUM                  17    //!< PTB17 Port number
#if SPI1_SIN_SEL == 1
#define SPI1_SIN_FN                2     //!< PTB17 Pin multiplexor for SPI
#define SPI1_SIN_GPIO              digitalIO_PTB17   //!< PTB17 SPI GPIO
#endif

// PTB18 = FTM2_0
#define PTB18_PORT                 B     //!< PTB18 Port name
#define PTB18_NUM                  18    //!< PTB18 Port number
#if FTM2_0_SEL == 2
#define PTB18_FTM_NUM              2     //!< PTB18 FTM number
#define PTB18_FTM_CH               0     //!< PTB18 FTM channel
#define PTB18_FTM_FN               3     //!< PTB18 Pin multiplexor for FTM
#endif

// PTB19 = FTM2_1
#define PTB19_PORT                 B     //!< PTB19 Port name
#define PTB19_NUM                  19    //!< PTB19 Port number
#if FTM2_1_SEL == 2
#define PTB19_FTM_NUM              2     //!< PTB19 FTM number
#define PTB19_FTM_CH               1     //!< PTB19 FTM channel
#define PTB19_FTM_FN               3     //!< PTB19 Pin multiplexor for FTM
#endif

// PTB20 = SPI2_PCS0
#define PTB20_PORT                 B     //!< PTB20 Port name
#define PTB20_NUM                  20    //!< PTB20 Port number
#if SPI2_PCS0_SEL == 1
#define SPI2_PCS0_FN               2     //!< PTB20 Pin multiplexor for SPI
#define SPI2_PCS0_GPIO             digitalIO_PTB20   //!< PTB20 SPI GPIO
#endif

// PTB21 = SPI2_SCK
#define PTB21_PORT                 B     //!< PTB21 Port name
#define PTB21_NUM                  21    //!< PTB21 Port number
#if SPI2_SCK_SEL == 1
#define SPI2_SCK_FN                2     //!< PTB21 Pin multiplexor for SPI
#define SPI2_SCK_GPIO              digitalIO_PTB21   //!< PTB21 SPI GPIO
#endif

// PTB22 = SPI2_SOUT
#define PTB22_PORT                 B     //!< PTB22 Port name
#define PTB22_NUM                  22    //!< PTB22 Port number
#if SPI2_SOUT_SEL == 1
#define SPI2_SOUT_FN               2     //!< PTB22 Pin multiplexor for SPI
#define SPI2_SOUT_GPIO             digitalIO_PTB22   //!< PTB22 SPI GPIO
#endif

// PTB23 = SPI2_SIN,SPI0_PCS5 (Alias: D4)
#define PTB23_PORT                 B     //!< PTB23 Port name
#define PTB23_NUM                  23    //!< PTB23 Port number
#if SPI2_SIN_SEL == 1
#define SPI2_SIN_FN                2     //!< PTB23 Pin multiplexor for SPI
#define SPI2_SIN_GPIO              digitalIO_PTB23   //!< PTB23 SPI GPIO
#endif
#if SPI0_PCS5_SEL == 1
#define SPI0_PCS5_FN               3     //!< PTB23 Pin multiplexor for SPI
#define SPI0_PCS5_GPIO             digitalIO_PTB23   //!< PTB23 SPI GPIO
#endif

// PTC0 = ADC0_14,SPI0_PCS4
#define PTC0_PORT                  C     //!< PTC0 Port name
#define PTC0_NUM                   0     //!< PTC0 Port number
#define PTC0_ADC_NUM               0     //!< PTC0 ADC number
#define PTC0_ADC_CH                14    //!< PTC0 ADC channel
#if SPI0_PCS4_SEL == 1
#define SPI0_PCS4_FN               2     //!< PTC0 Pin multiplexor for SPI
#define SPI0_PCS4_GPIO             digitalIO_PTC0   //!< PTC0 SPI GPIO
#endif

// PTC1 = ADC0_15,FTM0_0,SPI0_PCS3
#define PTC1_PORT                  C     //!< PTC1 Port name
#define PTC1_NUM                   1     //!< PTC1 Port number
#define PTC1_ADC_NUM               0     //!< PTC1 ADC number
#define PTC1_ADC_CH                15    //!< PTC1 ADC channel
#if FTM0_0_SEL == 2
#define PTC1_FTM_NUM               0     //!< PTC1 FTM number
#define PTC1_FTM_CH                0     //!< PTC1 FTM channel
#define PTC1_FTM_FN                4     //!< PTC1 Pin multiplexor for FTM
#endif
#if SPI0_PCS3_SEL == 1
#define SPI0_PCS3_FN               2     //!< PTC1 Pin multiplexor for SPI
#define SPI0_PCS3_GPIO             digitalIO_PTC1   //!< PTC1 SPI GPIO
#endif

// PTC2 = ADC0_4,FTM0_1,SPI0_PCS2 (Alias: D6)
#define PTC2_PORT                  C     //!< PTC2 Port name
#define PTC2_NUM                   2     //!< PTC2 Port number
#define PTC2_ADC_NUM               0     //!< PTC2 ADC number
#define PTC2_ADC_CH                4     //!< PTC2 ADC channel
#if FTM0_1_SEL == 2
#define PTC2_FTM_NUM               0     //!< PTC2 FTM number
#define PTC2_FTM_CH                1     //!< PTC2 FTM channel
#define PTC2_FTM_FN                4     //!< PTC2 Pin multiplexor for FTM
#endif
#if SPI0_PCS2_SEL == 1
#define SPI0_PCS2_FN               2     //!< PTC2 Pin multiplexor for SPI
#define SPI0_PCS2_GPIO             digitalIO_PTC2   //!< PTC2 SPI GPIO
#endif

// PTC3 = FTM0_2,SPI0_PCS1 (Alias: D7)
#define PTC3_PORT                  C     //!< PTC3 Port name
#define PTC3_NUM                   3     //!< PTC3 Port number
#if FTM0_2_SEL == 2
#define PTC3_FTM_NUM               0     //!< PTC3 FTM number
#define PTC3_FTM_CH                2     //!< PTC3 FTM channel
#define PTC3_FTM_FN                4     //!< PTC3 Pin multiplexor for FTM
#endif
#if SPI0_PCS1_SEL == 1
#define SPI0_PCS1_FN               2     //!< PTC3 Pin multiplexor for SPI
#define SPI0_PCS1_GPIO             digitalIO_PTC3   //!< PTC3 SPI GPIO
#endif

// PTC4 = FTM0_3,SPI0_PCS0 (Alias: D9)
#define PTC4_PORT                  C     //!< PTC4 Port name
#define PTC4_NUM                   4     //!< PTC4 Port number
#if FTM0_3_SEL == 2
#define PTC4_FTM_NUM               0     //!< PTC4 FTM number
#define PTC4_FTM_CH                3     //!< PTC4 FTM channel
#define PTC4_FTM_FN                4     //!< PTC4 Pin multiplexor for FTM
#endif
#if SPI0_PCS0_SEL == 2
#define SPI0_PCS0_FN               2     //!< PTC4 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTC4   //!< PTC4 SPI GPIO
#endif

// PTC5 = FTM0_2,LPTMR0_2,SPI0_SCK
#define PTC5_PORT                  C     //!< PTC5 Port name
#define PTC5_NUM                   5     //!< PTC5 Port number
#if FTM0_2_SEL == 3
#define PTC5_FTM_NUM               0     //!< PTC5 FTM number
#define PTC5_FTM_CH                2     //!< PTC5 FTM channel
#define PTC5_FTM_FN                7     //!< PTC5 Pin multiplexor for FTM
#endif
#if LPTMR0_2_SEL == 1
#define LPTMR0_2_FN                3     //!< PTC5 Pin multiplexor for LPTMR
#define LPTMR0_2_GPIO              digitalIO_PTC5   //!< PTC5 LPTMR GPIO
#endif
#if SPI0_SCK_SEL == 2
#define SPI0_SCK_FN                2     //!< PTC5 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTC5   //!< PTC5 SPI GPIO
#endif

// PTC6 = SPI0_SOUT
#define PTC6_PORT                  C     //!< PTC6 Port name
#define PTC6_NUM                   6     //!< PTC6 Port number
#if SPI0_SOUT_SEL == 2
#define SPI0_SOUT_FN               2     //!< PTC6 Pin multiplexor for SPI
#define SPI0_SOUT_GPIO             digitalIO_PTC6   //!< PTC6 SPI GPIO
#endif

// PTC7 = SPI0_SIN
#define PTC7_PORT                  C     //!< PTC7 Port name
#define PTC7_NUM                   7     //!< PTC7 Port number
#if SPI0_SIN_SEL == 2
#define SPI0_SIN_FN                2     //!< PTC7 Pin multiplexor for SPI
#define SPI0_SIN_GPIO              digitalIO_PTC7   //!< PTC7 SPI GPIO
#endif

// PTC8 = ADC1_4,FTM3_4
#define PTC8_PORT                  C     //!< PTC8 Port name
#define PTC8_NUM                   8     //!< PTC8 Port number
#define PTC8_ADC_NUM               1     //!< PTC8 ADC number
#define PTC8_ADC_CH                4     //!< PTC8 ADC channel
#if FTM3_4_SEL == 1
#define PTC8_FTM_NUM               3     //!< PTC8 FTM number
#define PTC8_FTM_CH                4     //!< PTC8 FTM channel
#define PTC8_FTM_FN                3     //!< PTC8 Pin multiplexor for FTM
#endif

// PTC9 = ADC1_5,FTM3_5
#define PTC9_PORT                  C     //!< PTC9 Port name
#define PTC9_NUM                   9     //!< PTC9 Port number
#define PTC9_ADC_NUM               1     //!< PTC9 ADC number
#define PTC9_ADC_CH                5     //!< PTC9 ADC channel
#if FTM3_5_SEL == 1
#define PTC9_FTM_NUM               3     //!< PTC9 FTM number
#define PTC9_FTM_CH                5     //!< PTC9 FTM channel
#define PTC9_FTM_FN                3     //!< PTC9 Pin multiplexor for FTM
#endif

// PTC10 = ADC1_6,FTM3_6,I2C1_SCL (Alias: A5)
#define PTC10_PORT                 C     //!< PTC10 Port name
#define PTC10_NUM                  10    //!< PTC10 Port number
#define PTC10_ADC_NUM              1     //!< PTC10 ADC number
#define PTC10_ADC_CH               6     //!< PTC10 ADC channel
#if FTM3_6_SEL == 1
#define PTC10_FTM_NUM              3     //!< PTC10 FTM number
#define PTC10_FTM_CH               6     //!< PTC10 FTM channel
#define PTC10_FTM_FN               3     //!< PTC10 Pin multiplexor for FTM
#endif
#if I2C1_SCL_SEL == 1
#define I2C1_SCL_FN                2     //!< PTC10 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTC10   //!< PTC10 I2C GPIO
#endif

// PTC11 = ADC1_7,FTM3_7,I2C1_SDA (Alias: A4)
#define PTC11_PORT                 C     //!< PTC11 Port name
#define PTC11_NUM                  11    //!< PTC11 Port number
#define PTC11_ADC_NUM              1     //!< PTC11 ADC number
#define PTC11_ADC_CH               7     //!< PTC11 ADC channel
#if FTM3_7_SEL == 1
#define PTC11_FTM_NUM              3     //!< PTC11 FTM number
#define PTC11_FTM_CH               7     //!< PTC11 FTM channel
#define PTC11_FTM_FN               3     //!< PTC11 Pin multiplexor for FTM
#endif
#if I2C1_SDA_SEL == 1
#define I2C1_SDA_FN                2     //!< PTC11 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTC11   //!< PTC11 I2C GPIO
#endif

// PTC12
#define PTC12_PORT                 C     //!< PTC12 Port name
#define PTC12_NUM                  12    //!< PTC12 Port number

// PTC13
#define PTC13_PORT                 C     //!< PTC13 Port name
#define PTC13_NUM                  13    //!< PTC13 Port number

// PTC14
#define PTC14_PORT                 C     //!< PTC14 Port name
#define PTC14_NUM                  14    //!< PTC14 Port number

// PTC15
#define PTC15_PORT                 C     //!< PTC15 Port name
#define PTC15_NUM                  15    //!< PTC15 Port number

// PTC16 (Alias: D0)
#define PTC16_PORT                 C     //!< PTC16 Port name
#define PTC16_NUM                  16    //!< PTC16 Port number

// PTC17 (Alias: D1)
#define PTC17_PORT                 C     //!< PTC17 Port name
#define PTC17_NUM                  17    //!< PTC17 Port number

// PTC18
#define PTC18_PORT                 C     //!< PTC18 Port name
#define PTC18_NUM                  18    //!< PTC18 Port number

// PTC19
#define PTC19_PORT                 C     //!< PTC19 Port name
#define PTC19_NUM                  19    //!< PTC19 Port number

// PTD0 = FTM3_0,SPI0_PCS0 (Alias: D10)
#define PTD0_PORT                  D     //!< PTD0 Port name
#define PTD0_NUM                   0     //!< PTD0 Port number
#if FTM3_0_SEL == 1
#define PTD0_FTM_NUM               3     //!< PTD0 FTM number
#define PTD0_FTM_CH                0     //!< PTD0 FTM channel
#define PTD0_FTM_FN                4     //!< PTD0 Pin multiplexor for FTM
#endif
#if SPI0_PCS0_SEL == 3
#define SPI0_PCS0_FN               2     //!< PTD0 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTD0   //!< PTD0 SPI GPIO
#endif

// PTD1 = ADC0_5,FTM3_1,SPI0_SCK (Alias: D13)
#define PTD1_PORT                  D     //!< PTD1 Port name
#define PTD1_NUM                   1     //!< PTD1 Port number
#define PTD1_ADC_NUM               0     //!< PTD1 ADC number
#define PTD1_ADC_CH                5     //!< PTD1 ADC channel
#if FTM3_1_SEL == 1
#define PTD1_FTM_NUM               3     //!< PTD1 FTM number
#define PTD1_FTM_CH                1     //!< PTD1 FTM channel
#define PTD1_FTM_FN                4     //!< PTD1 Pin multiplexor for FTM
#endif
#if SPI0_SCK_SEL == 3
#define SPI0_SCK_FN                2     //!< PTD1 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTD1   //!< PTD1 SPI GPIO
#endif

// PTD2 = FTM3_2,SPI0_SOUT,I2C0_SCL (Alias: D11)
#define PTD2_PORT                  D     //!< PTD2 Port name
#define PTD2_NUM                   2     //!< PTD2 Port number
#if FTM3_2_SEL == 1
#define PTD2_FTM_NUM               3     //!< PTD2 FTM number
#define PTD2_FTM_CH                2     //!< PTD2 FTM channel
#define PTD2_FTM_FN                4     //!< PTD2 Pin multiplexor for FTM
#endif
#if SPI0_SOUT_SEL == 3
#define SPI0_SOUT_FN               2     //!< PTD2 Pin multiplexor for SPI
#define SPI0_SOUT_GPIO             digitalIO_PTD2   //!< PTD2 SPI GPIO
#endif
#if I2C0_SCL_SEL == 3
#define I2C0_SCL_FN                7     //!< PTD2 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTD2   //!< PTD2 I2C GPIO
#endif

// PTD3 = FTM3_3,SPI0_SIN,I2C0_SDA (Alias: D12)
#define PTD3_PORT                  D     //!< PTD3 Port name
#define PTD3_NUM                   3     //!< PTD3 Port number
#if FTM3_3_SEL == 1
#define PTD3_FTM_NUM               3     //!< PTD3 FTM number
#define PTD3_FTM_CH                3     //!< PTD3 FTM channel
#define PTD3_FTM_FN                4     //!< PTD3 Pin multiplexor for FTM
#endif
#if SPI0_SIN_SEL == 3
#define SPI0_SIN_FN                2     //!< PTD3 Pin multiplexor for SPI
#define SPI0_SIN_GPIO              digitalIO_PTD3   //!< PTD3 SPI GPIO
#endif
#if I2C0_SDA_SEL == 3
#define I2C0_SDA_FN                7     //!< PTD3 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTD3   //!< PTD3 I2C GPIO
#endif

// PTD4 = FTM0_4,SPI0_PCS1,SPI1_PCS0 (Alias: nRF24L01_cs)
#define PTD4_PORT                  D     //!< PTD4 Port name
#define PTD4_NUM                   4     //!< PTD4 Port number
#if FTM0_4_SEL == 3
#define PTD4_FTM_NUM               0     //!< PTD4 FTM number
#define PTD4_FTM_CH                4     //!< PTD4 FTM channel
#define PTD4_FTM_FN                4     //!< PTD4 Pin multiplexor for FTM
#endif
#if SPI0_PCS1_SEL == 2
#define SPI0_PCS1_FN               2     //!< PTD4 Pin multiplexor for SPI
#define SPI0_PCS1_GPIO             digitalIO_PTD4   //!< PTD4 SPI GPIO
#endif
#if SPI1_PCS0_SEL == 2
#define SPI1_PCS0_FN               7     //!< PTD4 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTD4   //!< PTD4 SPI GPIO
#endif

// PTD5 = ADC0_6,FTM0_5,SPI0_PCS2,SPI1_SCK (Alias: nRF24L01_sck)
#define PTD5_PORT                  D     //!< PTD5 Port name
#define PTD5_NUM                   5     //!< PTD5 Port number
#define PTD5_ADC_NUM               0     //!< PTD5 ADC number
#define PTD5_ADC_CH                6     //!< PTD5 ADC channel
#if FTM0_5_SEL == 3
#define PTD5_FTM_NUM               0     //!< PTD5 FTM number
#define PTD5_FTM_CH                5     //!< PTD5 FTM channel
#define PTD5_FTM_FN                4     //!< PTD5 Pin multiplexor for FTM
#endif
#if SPI0_PCS2_SEL == 2
#define SPI0_PCS2_FN               2     //!< PTD5 Pin multiplexor for SPI
#define SPI0_PCS2_GPIO             digitalIO_PTD5   //!< PTD5 SPI GPIO
#endif
#if SPI1_SCK_SEL == 2
#define SPI1_SCK_FN                7     //!< PTD5 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTD5   //!< PTD5 SPI GPIO
#endif

// PTD6 = ADC0_7,FTM0_6,SPI0_PCS3,SPI1_SOUT (Alias: nRF24L01_mosi)
#define PTD6_PORT                  D     //!< PTD6 Port name
#define PTD6_NUM                   6     //!< PTD6 Port number
#define PTD6_ADC_NUM               0     //!< PTD6 ADC number
#define PTD6_ADC_CH                7     //!< PTD6 ADC channel
#if FTM0_6_SEL == 2
#define PTD6_FTM_NUM               0     //!< PTD6 FTM number
#define PTD6_FTM_CH                6     //!< PTD6 FTM channel
#define PTD6_FTM_FN                4     //!< PTD6 Pin multiplexor for FTM
#endif
#if SPI0_PCS3_SEL == 2
#define SPI0_PCS3_FN               2     //!< PTD6 Pin multiplexor for SPI
#define SPI0_PCS3_GPIO             digitalIO_PTD6   //!< PTD6 SPI GPIO
#endif
#if SPI1_SOUT_SEL == 2
#define SPI1_SOUT_FN               7     //!< PTD6 Pin multiplexor for SPI
#define SPI1_SOUT_GPIO             digitalIO_PTD6   //!< PTD6 SPI GPIO
#endif

// PTD7 = FTM0_7,SPI1_SIN (Alias: nRF24L01_miso)
#define PTD7_PORT                  D     //!< PTD7 Port name
#define PTD7_NUM                   7     //!< PTD7 Port number
#if FTM0_7_SEL == 2
#define PTD7_FTM_NUM               0     //!< PTD7 FTM number
#define PTD7_FTM_CH                7     //!< PTD7 FTM channel
#define PTD7_FTM_FN                4     //!< PTD7 Pin multiplexor for FTM
#endif
#if SPI1_SIN_SEL == 2
#define SPI1_SIN_FN                7     //!< PTD7 Pin multiplexor for SPI
#define SPI1_SIN_GPIO              digitalIO_PTD7   //!< PTD7 SPI GPIO
#endif

// PTD8 = I2C0_SCL
#define PTD8_PORT                  D     //!< PTD8 Port name
#define PTD8_NUM                   8     //!< PTD8 Port number
#if I2C0_SCL_SEL == 4
#define I2C0_SCL_FN                2     //!< PTD8 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTD8   //!< PTD8 I2C GPIO
#endif

// PTD9 = I2C0_SDA
#define PTD9_PORT                  D     //!< PTD9 Port name
#define PTD9_NUM                   9     //!< PTD9 Port number
#if I2C0_SDA_SEL == 4
#define I2C0_SDA_FN                2     //!< PTD9 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTD9   //!< PTD9 I2C GPIO
#endif

// PTD10
#define PTD10_PORT                 D     //!< PTD10 Port name
#define PTD10_NUM                  10    //!< PTD10 Port number

// PTD11 = SDHC0_CLKIN,SPI2_PCS0
#define PTD11_PORT                 D     //!< PTD11 Port name
#define PTD11_NUM                  11    //!< PTD11 Port number
#if SPI2_PCS0_SEL == 2
#define SPI2_PCS0_FN               2     //!< PTD11 Pin multiplexor for SPI
#define SPI2_PCS0_GPIO             digitalIO_PTD11   //!< PTD11 SPI GPIO
#endif
#if SDHC0_CLKIN_SEL == 1
#define SDHC0_CLKIN_FN             4     //!< PTD11 Pin multiplexor for SDHC
#define SDHC0_CLKIN_GPIO           digitalIO_PTD11   //!< PTD11 SDHC GPIO
#endif

// PTD12 = SDHC0_D4,SPI2_SCK
#define PTD12_PORT                 D     //!< PTD12 Port name
#define PTD12_NUM                  12    //!< PTD12 Port number
#if SPI2_SCK_SEL == 2
#define SPI2_SCK_FN                2     //!< PTD12 Pin multiplexor for SPI
#define SPI2_SCK_GPIO              digitalIO_PTD12   //!< PTD12 SPI GPIO
#endif
#if SDHC0_D4_SEL == 1
#define SDHC0_D4_FN                4     //!< PTD12 Pin multiplexor for SDHC
#define SDHC0_D4_GPIO              digitalIO_PTD12   //!< PTD12 SDHC GPIO
#endif

// PTD13 = SDHC0_D5,SPI2_SOUT
#define PTD13_PORT                 D     //!< PTD13 Port name
#define PTD13_NUM                  13    //!< PTD13 Port number
#if SPI2_SOUT_SEL == 2
#define SPI2_SOUT_FN               2     //!< PTD13 Pin multiplexor for SPI
#define SPI2_SOUT_GPIO             digitalIO_PTD13   //!< PTD13 SPI GPIO
#endif
#if SDHC0_D5_SEL == 1
#define SDHC0_D5_FN                4     //!< PTD13 Pin multiplexor for SDHC
#define SDHC0_D5_GPIO              digitalIO_PTD13   //!< PTD13 SDHC GPIO
#endif

// PTD14 = SDHC0_D6,SPI2_SIN
#define PTD14_PORT                 D     //!< PTD14 Port name
#define PTD14_NUM                  14    //!< PTD14 Port number
#if SPI2_SIN_SEL == 2
#define SPI2_SIN_FN                2     //!< PTD14 Pin multiplexor for SPI
#define SPI2_SIN_GPIO              digitalIO_PTD14   //!< PTD14 SPI GPIO
#endif
#if SDHC0_D6_SEL == 1
#define SDHC0_D6_FN                4     //!< PTD14 Pin multiplexor for SDHC
#define SDHC0_D6_GPIO              digitalIO_PTD14   //!< PTD14 SDHC GPIO
#endif

// PTD15 = SDHC0_D7,SPI2_PCS1
#define PTD15_PORT                 D     //!< PTD15 Port name
#define PTD15_NUM                  15    //!< PTD15 Port number
#if SPI2_PCS1_SEL == 1
#define SPI2_PCS1_FN               2     //!< PTD15 Pin multiplexor for SPI
#define SPI2_PCS1_GPIO             digitalIO_PTD15   //!< PTD15 SPI GPIO
#endif
#if SDHC0_D7_SEL == 1
#define SDHC0_D7_FN                4     //!< PTD15 Pin multiplexor for SDHC
#define SDHC0_D7_GPIO              digitalIO_PTD15   //!< PTD15 SDHC GPIO
#endif

// PTE0 = SDHC0_D1,SPI1_PCS1,I2C1_SDA
#define PTE0_PORT                  E     //!< PTE0 Port name
#define PTE0_NUM                   0     //!< PTE0 Port number
#if SPI1_PCS1_SEL == 2
#define SPI1_PCS1_FN               2     //!< PTE0 Pin multiplexor for SPI
#define SPI1_PCS1_GPIO             digitalIO_PTE0   //!< PTE0 SPI GPIO
#endif
#if I2C1_SDA_SEL == 2
#define I2C1_SDA_FN                6     //!< PTE0 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTE0   //!< PTE0 I2C GPIO
#endif
#if SDHC0_D1_SEL == 1
#define SDHC0_D1_FN                4     //!< PTE0 Pin multiplexor for SDHC
#define SDHC0_D1_GPIO              digitalIO_PTE0   //!< PTE0 SDHC GPIO
#endif

// PTE1 = SDHC0_D0,SPI1_SOUT,SPI1_SIN,I2C1_SCL
#define PTE1_PORT                  E     //!< PTE1 Port name
#define PTE1_NUM                   1     //!< PTE1 Port number
#if SPI1_SOUT_SEL == 3
#define SPI1_SOUT_FN               2     //!< PTE1 Pin multiplexor for SPI
#define SPI1_SOUT_GPIO             digitalIO_PTE1   //!< PTE1 SPI GPIO
#endif
#if SPI1_SIN_SEL == 3
#define SPI1_SIN_FN                7     //!< PTE1 Pin multiplexor for SPI
#define SPI1_SIN_GPIO              digitalIO_PTE1   //!< PTE1 SPI GPIO
#endif
#if I2C1_SCL_SEL == 2
#define I2C1_SCL_FN                6     //!< PTE1 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTE1   //!< PTE1 I2C GPIO
#endif
#if SDHC0_D0_SEL == 1
#define SDHC0_D0_FN                4     //!< PTE1 Pin multiplexor for SDHC
#define SDHC0_D0_GPIO              digitalIO_PTE1   //!< PTE1 SDHC GPIO
#endif

// PTE2 = SDHC0_DCLK,SPI1_SCK
#define PTE2_PORT                  E     //!< PTE2 Port name
#define PTE2_NUM                   2     //!< PTE2 Port number
#if SPI1_SCK_SEL == 3
#define SPI1_SCK_FN                2     //!< PTE2 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTE2   //!< PTE2 SPI GPIO
#endif
#if SDHC0_DCLK_SEL == 1
#define SDHC0_DCLK_FN              4     //!< PTE2 Pin multiplexor for SDHC
#define SDHC0_DCLK_GPIO            digitalIO_PTE2   //!< PTE2 SDHC GPIO
#endif

// PTE3 = SDHC0_CMD,SPI1_SIN,SPI1_SOUT
#define PTE3_PORT                  E     //!< PTE3 Port name
#define PTE3_NUM                   3     //!< PTE3 Port number
#if SPI1_SIN_SEL == 4
#define SPI1_SIN_FN                2     //!< PTE3 Pin multiplexor for SPI
#define SPI1_SIN_GPIO              digitalIO_PTE3   //!< PTE3 SPI GPIO
#endif
#if SPI1_SOUT_SEL == 4
#define SPI1_SOUT_FN               7     //!< PTE3 Pin multiplexor for SPI
#define SPI1_SOUT_GPIO             digitalIO_PTE3   //!< PTE3 SPI GPIO
#endif
#if SDHC0_CMD_SEL == 1
#define SDHC0_CMD_FN               4     //!< PTE3 Pin multiplexor for SDHC
#define SDHC0_CMD_GPIO             digitalIO_PTE3   //!< PTE3 SDHC GPIO
#endif

// PTE4 = SDHC0_D3,SPI1_PCS0
#define PTE4_PORT                  E     //!< PTE4 Port name
#define PTE4_NUM                   4     //!< PTE4 Port number
#if SPI1_PCS0_SEL == 3
#define SPI1_PCS0_FN               2     //!< PTE4 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTE4   //!< PTE4 SPI GPIO
#endif
#if SDHC0_D3_SEL == 1
#define SDHC0_D3_FN                4     //!< PTE4 Pin multiplexor for SDHC
#define SDHC0_D3_GPIO              digitalIO_PTE4   //!< PTE4 SDHC GPIO
#endif

// PTE5 = FTM3_0,SDHC0_D2,SPI1_PCS2
#define PTE5_PORT                  E     //!< PTE5 Port name
#define PTE5_NUM                   5     //!< PTE5 Port number
#if FTM3_0_SEL == 2
#define PTE5_FTM_NUM               3     //!< PTE5 FTM number
#define PTE5_FTM_CH                0     //!< PTE5 FTM channel
#define PTE5_FTM_FN                6     //!< PTE5 Pin multiplexor for FTM
#endif
#if SPI1_PCS2_SEL == 1
#define SPI1_PCS2_FN               2     //!< PTE5 Pin multiplexor for SPI
#define SPI1_PCS2_GPIO             digitalIO_PTE5   //!< PTE5 SPI GPIO
#endif
#if SDHC0_D2_SEL == 1
#define SDHC0_D2_FN                4     //!< PTE5 Pin multiplexor for SDHC
#define SDHC0_D2_GPIO              digitalIO_PTE5   //!< PTE5 SDHC GPIO
#endif

// PTE6 = FTM3_1,SPI1_PCS3
#define PTE6_PORT                  E     //!< PTE6 Port name
#define PTE6_NUM                   6     //!< PTE6 Port number
#if FTM3_1_SEL == 2
#define PTE6_FTM_NUM               3     //!< PTE6 FTM number
#define PTE6_FTM_CH                1     //!< PTE6 FTM channel
#define PTE6_FTM_FN                6     //!< PTE6 Pin multiplexor for FTM
#endif
#if SPI1_PCS3_SEL == 1
#define SPI1_PCS3_FN               2     //!< PTE6 Pin multiplexor for SPI
#define SPI1_PCS3_GPIO             digitalIO_PTE6   //!< PTE6 SPI GPIO
#endif

// PTE7 = FTM3_2
#define PTE7_PORT                  E     //!< PTE7 Port name
#define PTE7_NUM                   7     //!< PTE7 Port number
#if FTM3_2_SEL == 2
#define PTE7_FTM_NUM               3     //!< PTE7 FTM number
#define PTE7_FTM_CH                2     //!< PTE7 FTM channel
#define PTE7_FTM_FN                6     //!< PTE7 Pin multiplexor for FTM
#endif

// PTE8 = FTM3_3
#define PTE8_PORT                  E     //!< PTE8 Port name
#define PTE8_NUM                   8     //!< PTE8 Port number
#if FTM3_3_SEL == 2
#define PTE8_FTM_NUM               3     //!< PTE8 FTM number
#define PTE8_FTM_CH                3     //!< PTE8 FTM channel
#define PTE8_FTM_FN                6     //!< PTE8 Pin multiplexor for FTM
#endif

// PTE9 = FTM3_4
#define PTE9_PORT                  E     //!< PTE9 Port name
#define PTE9_NUM                   9     //!< PTE9 Port number
#if FTM3_4_SEL == 2
#define PTE9_FTM_NUM               3     //!< PTE9 FTM number
#define PTE9_FTM_CH                4     //!< PTE9 FTM channel
#define PTE9_FTM_FN                6     //!< PTE9 Pin multiplexor for FTM
#endif

// PTE10 = FTM3_5
#define PTE10_PORT                 E     //!< PTE10 Port name
#define PTE10_NUM                  10    //!< PTE10 Port number
#if FTM3_5_SEL == 2
#define PTE10_FTM_NUM              3     //!< PTE10 FTM number
#define PTE10_FTM_CH               5     //!< PTE10 FTM channel
#define PTE10_FTM_FN               6     //!< PTE10 Pin multiplexor for FTM
#endif

// PTE11 = FTM3_6
#define PTE11_PORT                 E     //!< PTE11 Port name
#define PTE11_NUM                  11    //!< PTE11 Port number
#if FTM3_6_SEL == 2
#define PTE11_FTM_NUM              3     //!< PTE11 FTM number
#define PTE11_FTM_CH               6     //!< PTE11 FTM channel
#define PTE11_FTM_FN               6     //!< PTE11 Pin multiplexor for FTM
#endif

// PTE12 = FTM3_7
#define PTE12_PORT                 E     //!< PTE12 Port name
#define PTE12_NUM                  12    //!< PTE12 Port number
#if FTM3_7_SEL == 2
#define PTE12_FTM_NUM              3     //!< PTE12 FTM number
#define PTE12_FTM_CH               7     //!< PTE12 FTM channel
#define PTE12_FTM_FN               6     //!< PTE12 Pin multiplexor for FTM
#endif

// PTE24 = ADC0_17,I2C0_SCL (Alias: D15)
#define PTE24_PORT                 E     //!< PTE24 Port name
#define PTE24_NUM                  24    //!< PTE24 Port number
#define PTE24_ADC_NUM              0     //!< PTE24 ADC number
#define PTE24_ADC_CH               17    //!< PTE24 ADC channel
#if I2C0_SCL_SEL == 5
#define I2C0_SCL_FN                5     //!< PTE24 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTE24   //!< PTE24 I2C GPIO
#endif

// PTE25 = ADC0_18,I2C0_SDA (Alias: D14)
#define PTE25_PORT                 E     //!< PTE25 Port name
#define PTE25_NUM                  25    //!< PTE25 Port number
#define PTE25_ADC_NUM              0     //!< PTE25 ADC number
#define PTE25_ADC_CH               18    //!< PTE25 ADC channel
#if I2C0_SDA_SEL == 5
#define I2C0_SDA_FN                5     //!< PTE25 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTE25   //!< PTE25 I2C GPIO
#endif

// PTE26
#define PTE26_PORT                 E     //!< PTE26 Port name
#define PTE26_NUM                  26    //!< PTE26 Port number

// PTE27
#define PTE27_PORT                 E     //!< PTE27 Port name
#define PTE27_NUM                  27    //!< PTE27 Port number

// PTE28
#define PTE28_PORT                 E     //!< PTE28 Port name
#define PTE28_NUM                  28    //!< PTE28 Port number

// </h>


#endif /* PIN_MAPPING_H_ */
