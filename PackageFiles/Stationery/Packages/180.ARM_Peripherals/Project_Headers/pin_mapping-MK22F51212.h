/**
 * @file      pin_mapping.h (derived from pin_mapping-MK22F51212.h)
 * @version   1.0.0
 * @brief     Pin declarations for MK22F51212
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

#define ADC0_CLOCK_REG       SIM->SCGC6          
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC0_MASK 
#define ADC1_CLOCK_REG       SIM->SCGC6          
#define ADC1_CLOCK_MASK      SIM_SCGC6_ADC1_MASK 
#define CMP_CLOCK_REG        SIM->SCGC4          
#define CMP_CLOCK_MASK       SIM_SCGC4_CMP_MASK  
#define DAC0_CLOCK_REG       SIM->SCGC6          
#define DAC0_CLOCK_MASK      SIM_SCGC6_DAC0_MASK 
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
#define FTM2_CLOCK_REG       SIM->SCGC6          
#define FTM2_CLOCK_MASK      SIM_SCGC6_FTM2_MASK 
#define I2C0_CLOCK_REG       SIM->SCGC4          
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK 
#define I2C1_CLOCK_REG       SIM->SCGC4          
#define I2C1_CLOCK_MASK      SIM_SCGC4_I2C1_MASK 
#define I2S0_CLOCK_REG       SIM->SCGC6          
#define I2S0_CLOCK_MASK      SIM_SCGC6_I2S0_MASK 
#define LPTMR0_CLOCK_REG     SIM->SCGC5          
#define LPTMR0_CLOCK_MASK    SIM_SCGC5_LPTMR_MASK
#define LPUART0_CLOCK_REG    SIM->SCGC6          
#define LPUART0_CLOCK_MASK   SIM_SCGC6_LPUART0_MASK
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
#define RNGA_CLOCK_REG       SIM->SCGC6          
#define RNGA_CLOCK_MASK      SIM_SCGC6_RNGA_MASK 
#define RTC_CLOCK_REG        SIM->SCGC6          
#define RTC_CLOCK_MASK       SIM_SCGC6_RTC_MASK  
#define SPI0_CLOCK_REG       SIM->SCGC6          
#define SPI0_CLOCK_MASK      SIM_SCGC6_SPI0_MASK 
#define SPI1_CLOCK_REG       SIM->SCGC6          
#define SPI1_CLOCK_MASK      SIM_SCGC6_SPI1_MASK 
#define UART0_CLOCK_REG      SIM->SCGC4          
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define UART1_CLOCK_REG      SIM->SCGC4          
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define UART2_CLOCK_REG      SIM->SCGC4          
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define USBOTG_CLOCK_REG     SIM->SCGC4          
#define USBOTG_CLOCK_MASK    SIM_SCGC4_USBOTG_MASK
#define VREF_CLOCK_REG       SIM->SCGC4          
#define VREF_CLOCK_MASK      SIM_SCGC4_VREF_MASK 
#define PORT_CLOCK_REG       SIM->SCGC5          

// <h> Pin Peripheral mapping

// ADC0_4 maps to [Disabled, PTC2]
//   <o> ADC0_4 Pin Selection [PTC2(A3)] <constant>
//   <i> Selects which pin is used for ADC0_4
//     <0=> Disabled
//     <1=> PTC2 (Alias: A3)
//     <1=> Default
#define ADC0_4_SEL           1                   

// ADC0_5 maps to [Disabled, PTD1]
//   <o> ADC0_5 Pin Selection [PTD1] <constant>
//   <i> Selects which pin is used for ADC0_5
//     <0=> Disabled
//     <1=> PTD1
//     <1=> Default
#define ADC0_5_SEL           1                   

// ADC0_6 maps to [Disabled, PTD5]
//   <o> ADC0_6 Pin Selection [PTD5(D13)] <constant>
//   <i> Selects which pin is used for ADC0_6
//     <0=> Disabled
//     <1=> PTD5 (Alias: D13)
//     <1=> Default
#define ADC0_6_SEL           1                   

// ADC0_7 maps to [Disabled, PTD6]
//   <o> ADC0_7 Pin Selection [PTD6(D11)] <constant>
//   <i> Selects which pin is used for ADC0_7
//     <0=> Disabled
//     <1=> PTD6 (Alias: D11)
//     <1=> Default
#define ADC0_7_SEL           1                   

// ADC0_12 maps to [Disabled, PTB2]
//   <o> ADC0_12 Pin Selection [PTB2(A5)] <constant>
//   <i> Selects which pin is used for ADC0_12
//     <0=> Disabled
//     <1=> PTB2 (Alias: A5)
//     <1=> Default
#define ADC0_12_SEL          1                   

// ADC0_13 maps to [Disabled, PTB3]
//   <o> ADC0_13 Pin Selection [PTB3(A4)] <constant>
//   <i> Selects which pin is used for ADC0_13
//     <0=> Disabled
//     <1=> PTB3 (Alias: A4)
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
//   <o> ADC0_15 Pin Selection [PTC1(A2)] <constant>
//   <i> Selects which pin is used for ADC0_15
//     <0=> Disabled
//     <1=> PTC1 (Alias: A2)
//     <1=> Default
#define ADC0_15_SEL          1                   

// ADC0_17 maps to [Disabled, PTE24]
//   <o> ADC0_17 Pin Selection [PTE24] <constant>
//   <i> Selects which pin is used for ADC0_17
//     <0=> Disabled
//     <1=> PTE24
//     <1=> Default
#define ADC0_17_SEL          1                   

// ADC0_18 maps to [Disabled, PTE25]
//   <o> ADC0_18 Pin Selection [PTE25] <constant>
//   <i> Selects which pin is used for ADC0_18
//     <0=> Disabled
//     <1=> PTE25
//     <1=> Default
#define ADC0_18_SEL          1                   

// ADC0_23 maps to [Disabled, ADC0_SE23]
//   <o> ADC0_23 Pin Selection [ADC0_SE23] <constant>
//   <i> Selects which pin is used for ADC0_23
//     <0=> Disabled
//     <1=> ADC0_SE23
//     <1=> Default
#define ADC0_23_SEL          1                   

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
//   <o> ADC1_6 Pin Selection [PTC10] <constant>
//   <i> Selects which pin is used for ADC1_6
//     <0=> Disabled
//     <1=> PTC10
//     <1=> Default
#define ADC1_6_SEL           1                   

// ADC1_7 maps to [Disabled, PTC11]
//   <o> ADC1_7 Pin Selection [PTC11] <constant>
//   <i> Selects which pin is used for ADC1_7
//     <0=> Disabled
//     <1=> PTC11
//     <1=> Default
#define ADC1_7_SEL           1                   

// ADC1_8 maps to [Disabled, PTB0]
//   <o> ADC1_8 Pin Selection [PTB0(A0)] <constant>
//   <i> Selects which pin is used for ADC1_8
//     <0=> Disabled
//     <1=> PTB0 (Alias: A0)
//     <1=> Default
#define ADC1_8_SEL           1                   

// ADC1_9 maps to [Disabled, PTB1]
//   <o> ADC1_9 Pin Selection [PTB1(A1)] <constant>
//   <i> Selects which pin is used for ADC1_9
//     <0=> Disabled
//     <1=> PTB1 (Alias: A1)
//     <1=> Default
#define ADC1_9_SEL           1                   

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
//   <o> ADC1_14 Pin Selection [PTB10] <constant>
//   <i> Selects which pin is used for ADC1_14
//     <0=> Disabled
//     <1=> PTB10
//     <1=> Default
#define ADC1_14_SEL          1                   

// ADC1_15 maps to [Disabled, PTB11]
//   <o> ADC1_15 Pin Selection [PTB11] <constant>
//   <i> Selects which pin is used for ADC1_15
//     <0=> Disabled
//     <1=> PTB11
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

// FTM0_0 maps to [Disabled, PTA3, PTC1]
//   <o> FTM0_0 Pin Selection [PTA3, PTC1(A2)] 
//   <i> Selects which pin is used for FTM0_0
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTC1 (Alias: A2)
//     <2=> Default
#define FTM0_0_SEL           2                   

// FTM0_1 maps to [Disabled, PTA4, PTC2]
//   <o> FTM0_1 Pin Selection [PTA4(D4), PTC2(A3)] 
//   <i> Selects which pin is used for FTM0_1
//     <0=> Disabled
//     <1=> PTA4 (Alias: D4)
//     <2=> PTC2 (Alias: A3)
//     <1=> Default
#define FTM0_1_SEL           1                   

// FTM0_2 maps to [Disabled, PTA5, PTC3, PTC5]
//   <o> FTM0_2 Pin Selection [PTA5, PTC3(D6), PTC5] 
//   <i> Selects which pin is used for FTM0_2
//     <0=> Disabled
//     <1=> PTA5
//     <2=> PTC3 (Alias: D6)
//     <3=> PTC5
//     <2=> Default
#define FTM0_2_SEL           2                   

// FTM0_3 maps to [Disabled, PTC4]
//   <o> FTM0_3 Pin Selection [PTC4] <constant>
//   <i> Selects which pin is used for FTM0_3
//     <0=> Disabled
//     <1=> PTC4
//     <1=> Default
#define FTM0_3_SEL           1                   

// FTM0_4 maps to [Disabled, PTD4]
//   <o> FTM0_4 Pin Selection [PTD4(D10)] <constant>
//   <i> Selects which pin is used for FTM0_4
//     <0=> Disabled
//     <1=> PTD4 (Alias: D10)
//     <1=> Default
#define FTM0_4_SEL           1                   

// FTM0_5 maps to [Disabled, PTA0, PTD5]
//   <o> FTM0_5 Pin Selection [PTA0, PTD5(D13)] 
//   <i> Selects which pin is used for FTM0_5
//     <0=> Disabled
//     <1=> PTA0
//     <2=> PTD5 (Alias: D13)
//     <2=> Default
#define FTM0_5_SEL           2                   

// FTM0_6 maps to [Disabled, PTA1, PTD6]
//   <o> FTM0_6 Pin Selection [PTA1(D9), PTD6(D11)] 
//   <i> Selects which pin is used for FTM0_6
//     <0=> Disabled
//     <1=> PTA1 (Alias: D9)
//     <2=> PTD6 (Alias: D11)
//     <1=> Default
#define FTM0_6_SEL           1                   

// FTM0_7 maps to [Disabled, PTA2, PTD7]
//   <o> FTM0_7 Pin Selection [PTA2(D3), PTD7(D12)] 
//   <i> Selects which pin is used for FTM0_7
//     <0=> Disabled
//     <1=> PTA2 (Alias: D3)
//     <2=> PTD7 (Alias: D12)
//     <1=> Default
#define FTM0_7_SEL           1                   

// FTM1_0 maps to [Disabled, PTA12, PTB0]
//   <o> FTM1_0 Pin Selection [PTA12, PTB0(A0)] 
//   <i> Selects which pin is used for FTM1_0
//     <0=> Disabled
//     <1=> PTA12
//     <2=> PTB0 (Alias: A0)
//     <2=> Default
#define FTM1_0_SEL           2                   

// FTM1_1 maps to [Disabled, PTA13, PTB1]
//   <o> FTM1_1 Pin Selection [PTA13, PTB1(A1)] 
//   <i> Selects which pin is used for FTM1_1
//     <0=> Disabled
//     <1=> PTA13
//     <2=> PTB1 (Alias: A1)
//     <2=> Default
#define FTM1_1_SEL           2                   

// FTM2_0 maps to [Disabled, PTB18]
//   <o> FTM2_0 Pin Selection [PTB18(D5)] <constant>
//   <i> Selects which pin is used for FTM2_0
//     <0=> Disabled
//     <1=> PTB18 (Alias: D5)
//     <1=> Default
#define FTM2_0_SEL           1                   

// FTM2_1 maps to [Disabled, PTB19]
//   <o> FTM2_1 Pin Selection [PTB19(D8)] <constant>
//   <i> Selects which pin is used for FTM2_1
//     <0=> Disabled
//     <1=> PTB19 (Alias: D8)
//     <1=> Default
#define FTM2_1_SEL           1                   

// I2C0_SCL maps to [Disabled, PTB0, PTB2, PTD2, PTE24]
//   <o> I2C0_SCL Pin Selection [PTB0(A0), PTB2(A5), PTD2(D0), PTE24] 
//   <i> Selects which pin is used for I2C0_SCL
//     <0=> Disabled
//     <1=> PTB0 (Alias: A0)
//     <2=> PTB2 (Alias: A5)
//     <3=> PTD2 (Alias: D0)
//     <4=> PTE24
//     <2=> Default
#define I2C0_SCL_SEL         2                   

// I2C0_SDA maps to [Disabled, PTB1, PTB3, PTD3, PTE25]
//   <o> I2C0_SDA Pin Selection [PTB1(A1), PTB3(A4), PTD3(D1), PTE25] 
//   <i> Selects which pin is used for I2C0_SDA
//     <0=> Disabled
//     <1=> PTB1 (Alias: A1)
//     <2=> PTB3 (Alias: A4)
//     <3=> PTD3 (Alias: D1)
//     <4=> PTE25
//     <2=> Default
#define I2C0_SDA_SEL         2                   

// I2C1_SDA maps to [Disabled, PTC11, PTE0]
//   <o> I2C1_SDA Pin Selection [PTC11, PTE0(D14)] 
//   <i> Selects which pin is used for I2C1_SDA
//     <0=> Disabled
//     <1=> PTC11
//     <2=> PTE0 (Alias: D14)
//     <2=> Default
#define I2C1_SDA_SEL         2                   

// I2C1_SCL maps to [Disabled, PTC10, PTE1]
//   <o> I2C1_SCL Pin Selection [PTC10, PTE1(D15)] 
//   <i> Selects which pin is used for I2C1_SCL
//     <0=> Disabled
//     <1=> PTC10
//     <2=> PTE1 (Alias: D15)
//     <2=> Default
#define I2C1_SCL_SEL         2                   

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

// SPI0_PCS0 maps to [Disabled, PTA14, PTC4, PTD0]
//   <o> SPI0_PCS0 Pin Selection [PTA14, PTC4, PTD0] 
//   <i> Selects which pin is used for SPI0_PCS0
//     <0=> Disabled
//     <1=> PTA14
//     <2=> PTC4
//     <3=> PTD0
//     <0=> Default
#define SPI0_PCS0_SEL        0                   

// SPI0_PCS1 maps to [Disabled, PTC3, PTD4]
//   <o> SPI0_PCS1 Pin Selection [PTC3(D6), PTD4(D10)] 
//   <i> Selects which pin is used for SPI0_PCS1
//     <0=> Disabled
//     <1=> PTC3 (Alias: D6)
//     <2=> PTD4 (Alias: D10)
//     <0=> Default
#define SPI0_PCS1_SEL        0                   

// SPI0_PCS2 maps to [Disabled, PTC2, PTD5]
//   <o> SPI0_PCS2 Pin Selection [PTC2(A3), PTD5(D13)] 
//   <i> Selects which pin is used for SPI0_PCS2
//     <0=> Disabled
//     <1=> PTC2 (Alias: A3)
//     <2=> PTD5 (Alias: D13)
//     <0=> Default
#define SPI0_PCS2_SEL        0                   

// SPI0_PCS3 maps to [Disabled, PTC1, PTD6]
//   <o> SPI0_PCS3 Pin Selection [PTC1(A2), PTD6(D11)] 
//   <i> Selects which pin is used for SPI0_PCS3
//     <0=> Disabled
//     <1=> PTC1 (Alias: A2)
//     <2=> PTD6 (Alias: D11)
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
//   <o> SPI0_PCS5 Pin Selection [PTB23] 
//   <i> Selects which pin is used for SPI0_PCS5
//     <0=> Disabled
//     <1=> PTB23
//     <0=> Default
#define SPI0_PCS5_SEL        0                   

// SPI0_SCK maps to [Disabled, PTA15, PTC5, PTD1]
//   <o> SPI0_SCK Pin Selection [PTA15, PTC5, PTD1] 
//   <i> Selects which pin is used for SPI0_SCK
//     <0=> Disabled
//     <1=> PTA15
//     <2=> PTC5
//     <3=> PTD1
//     <1=> Default
#define SPI0_SCK_SEL         1                   

// SPI0_SIN maps to [Disabled, PTA17, PTC7, PTD3]
//   <o> SPI0_SIN Pin Selection [PTA17, PTC7, PTD3(D1)] 
//   <i> Selects which pin is used for SPI0_SIN
//     <0=> Disabled
//     <1=> PTA17
//     <2=> PTC7
//     <3=> PTD3 (Alias: D1)
//     <1=> Default
#define SPI0_SIN_SEL         1                   

// SPI0_SOUT maps to [Disabled, PTA16, PTC6, PTD2]
//   <o> SPI0_SOUT Pin Selection [PTA16, PTC6(D7), PTD2(D0)] 
//   <i> Selects which pin is used for SPI0_SOUT
//     <0=> Disabled
//     <1=> PTA16
//     <2=> PTC6 (Alias: D7)
//     <3=> PTD2 (Alias: D0)
//     <1=> Default
#define SPI0_SOUT_SEL        1                   

// SPI1_PCS0 maps to [Disabled, PTB10, PTD4, PTE4]
//   <o> SPI1_PCS0 Pin Selection [PTB10, PTD4(D10), PTE4] 
//   <i> Selects which pin is used for SPI1_PCS0
//     <0=> Disabled
//     <1=> PTB10
//     <2=> PTD4 (Alias: D10)
//     <3=> PTE4
//     <0=> Default
#define SPI1_PCS0_SEL        0                   

// SPI1_PCS1 maps to [Disabled, PTB9, PTE0]
//   <o> SPI1_PCS1 Pin Selection [PTB9, PTE0(D14)] 
//   <i> Selects which pin is used for SPI1_PCS1
//     <0=> Disabled
//     <1=> PTB9
//     <2=> PTE0 (Alias: D14)
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
//   <o> SPI1_SCK Pin Selection [PTB11, PTD5(D13), PTE2] 
//   <i> Selects which pin is used for SPI1_SCK
//     <0=> Disabled
//     <1=> PTB11
//     <2=> PTD5 (Alias: D13)
//     <3=> PTE2
//     <2=> Default
#define SPI1_SCK_SEL         2                   

// SPI1_SIN maps to [Disabled, PTB17, PTD7, PTE1, PTE3]
//   <o> SPI1_SIN Pin Selection [PTB17, PTD7(D12), PTE1(D15), PTE3] 
//   <i> Selects which pin is used for SPI1_SIN
//     <0=> Disabled
//     <1=> PTB17
//     <2=> PTD7 (Alias: D12)
//     <3=> PTE1 (Alias: D15)
//     <4=> PTE3
//     <2=> Default
#define SPI1_SIN_SEL         2                   

// SPI1_SOUT maps to [Disabled, PTB16, PTD6, PTE1, PTE3]
//   <o> SPI1_SOUT Pin Selection [PTB16(D2), PTD6(D11), PTE1(D15), PTE3] 
//   <i> Selects which pin is used for SPI1_SOUT
//     <0=> Disabled
//     <1=> PTB16 (Alias: D2)
//     <2=> PTD6 (Alias: D11)
//     <3=> PTE1 (Alias: D15)
//     <4=> PTE3
//     <2=> Default
#define SPI1_SOUT_SEL        2                   

// </h>

// ADC0_DM0

// ADC0_DM1

// ADC0_DP0

// ADC0_DP1

// ADC0_SE23 = ADC0_23
#define ADC0_SE23_ADC_NUM          0     //!< ADC0_SE23 ADC number
#define ADC0_SE23_ADC_CH           23    //!< ADC0_SE23 ADC channel
#define ADC0_SE23_ADC_FN           0     //!< ADC0_SE23 Pin multiplexor for ADC

// ADC1_DM0

// ADC1_DM1

// ADC1_DP0

// ADC1_DP1

// ADC1_SE18 = ADC1_18
#define ADC1_SE18_ADC_NUM          1     //!< ADC1_SE18 ADC number
#define ADC1_SE18_ADC_CH           18    //!< ADC1_SE18 ADC channel
#define ADC1_SE18_ADC_FN           0     //!< ADC1_SE18 Pin multiplexor for ADC

// ADC1_SE23 = ADC1_23
#define ADC1_SE23_ADC_NUM          1     //!< ADC1_SE23 ADC number
#define ADC1_SE23_ADC_CH           23    //!< ADC1_SE23 ADC channel
#define ADC1_SE23_ADC_FN           0     //!< ADC1_SE23 Pin multiplexor for ADC

// PTA0 = GPIOA_0,FTM0_5
#define PTA0_GPIO_NAME             A     //!< PTA0 GPIO name
#define PTA0_GPIO_BIT              0     //!< PTA0 GPIO bit number
#define PTA0_GPIO_FN               1     //!< PTA0 Pin multiplexor for GPIO
#if FTM0_5_SEL == 1
#define PTA0_FTM_NUM               0     //!< PTA0 FTM number
#define PTA0_FTM_CH                5     //!< PTA0 FTM channel
#define PTA0_FTM_FN                3     //!< PTA0 Pin multiplexor for FTM
#endif

// PTA1 = GPIOA_1,FTM0_6 (Alias: D9)
#define PTA1_GPIO_NAME             A     //!< PTA1 GPIO name
#define PTA1_GPIO_BIT              1     //!< PTA1 GPIO bit number
#define PTA1_GPIO_FN               1     //!< PTA1 Pin multiplexor for GPIO
#if FTM0_6_SEL == 1
#define PTA1_FTM_NUM               0     //!< PTA1 FTM number
#define PTA1_FTM_CH                6     //!< PTA1 FTM channel
#define PTA1_FTM_FN                3     //!< PTA1 Pin multiplexor for FTM
#endif

// PTA2 = GPIOA_2,FTM0_7 (Alias: D3)
#define PTA2_GPIO_NAME             A     //!< PTA2 GPIO name
#define PTA2_GPIO_BIT              2     //!< PTA2 GPIO bit number
#define PTA2_GPIO_FN               1     //!< PTA2 Pin multiplexor for GPIO
#if FTM0_7_SEL == 1
#define PTA2_FTM_NUM               0     //!< PTA2 FTM number
#define PTA2_FTM_CH                7     //!< PTA2 FTM channel
#define PTA2_FTM_FN                3     //!< PTA2 Pin multiplexor for FTM
#endif

// PTA3 = GPIOA_3,FTM0_0
#define PTA3_GPIO_NAME             A     //!< PTA3 GPIO name
#define PTA3_GPIO_BIT              3     //!< PTA3 GPIO bit number
#define PTA3_GPIO_FN               1     //!< PTA3 Pin multiplexor for GPIO
#if FTM0_0_SEL == 1
#define PTA3_FTM_NUM               0     //!< PTA3 FTM number
#define PTA3_FTM_CH                0     //!< PTA3 FTM channel
#define PTA3_FTM_FN                3     //!< PTA3 Pin multiplexor for FTM
#endif

// PTA4 = GPIOA_4,FTM0_1 (Alias: D4)
#define PTA4_GPIO_NAME             A     //!< PTA4 GPIO name
#define PTA4_GPIO_BIT              4     //!< PTA4 GPIO bit number
#define PTA4_GPIO_FN               1     //!< PTA4 Pin multiplexor for GPIO
#if FTM0_1_SEL == 1
#define PTA4_FTM_NUM               0     //!< PTA4 FTM number
#define PTA4_FTM_CH                1     //!< PTA4 FTM channel
#define PTA4_FTM_FN                3     //!< PTA4 Pin multiplexor for FTM
#endif

// PTA5 = GPIOA_5,FTM0_2
#define PTA5_GPIO_NAME             A     //!< PTA5 GPIO name
#define PTA5_GPIO_BIT              5     //!< PTA5 GPIO bit number
#define PTA5_GPIO_FN               1     //!< PTA5 Pin multiplexor for GPIO
#if FTM0_2_SEL == 1
#define PTA5_FTM_NUM               0     //!< PTA5 FTM number
#define PTA5_FTM_CH                2     //!< PTA5 FTM channel
#define PTA5_FTM_FN                3     //!< PTA5 Pin multiplexor for FTM
#endif

// PTA12 = GPIOA_12,FTM1_0
#define PTA12_GPIO_NAME            A     //!< PTA12 GPIO name
#define PTA12_GPIO_BIT             12    //!< PTA12 GPIO bit number
#define PTA12_GPIO_FN              1     //!< PTA12 Pin multiplexor for GPIO
#if FTM1_0_SEL == 1
#define PTA12_FTM_NUM              1     //!< PTA12 FTM number
#define PTA12_FTM_CH               0     //!< PTA12 FTM channel
#define PTA12_FTM_FN               3     //!< PTA12 Pin multiplexor for FTM
#endif

// PTA13 = GPIOA_13,FTM1_1
#define PTA13_GPIO_NAME            A     //!< PTA13 GPIO name
#define PTA13_GPIO_BIT             13    //!< PTA13 GPIO bit number
#define PTA13_GPIO_FN              1     //!< PTA13 Pin multiplexor for GPIO
#if FTM1_1_SEL == 1
#define PTA13_FTM_NUM              1     //!< PTA13 FTM number
#define PTA13_FTM_CH               1     //!< PTA13 FTM channel
#define PTA13_FTM_FN               3     //!< PTA13 Pin multiplexor for FTM
#endif

// PTA14 = GPIOA_14,SPI0_PCS0
#define PTA14_GPIO_NAME            A     //!< PTA14 GPIO name
#define PTA14_GPIO_BIT             14    //!< PTA14 GPIO bit number
#define PTA14_GPIO_FN              1     //!< PTA14 Pin multiplexor for GPIO
#if SPI0_PCS0_SEL == 1
#define SPI0_PCS0_FN               2     //!< PTA14 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTA14   //!< PTA14 SPI GPIO
#endif

// PTA15 = GPIOA_15,SPI0_SCK
#define PTA15_GPIO_NAME            A     //!< PTA15 GPIO name
#define PTA15_GPIO_BIT             15    //!< PTA15 GPIO bit number
#define PTA15_GPIO_FN              1     //!< PTA15 Pin multiplexor for GPIO
#if SPI0_SCK_SEL == 1
#define SPI0_SCK_FN                2     //!< PTA15 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTA15   //!< PTA15 SPI GPIO
#endif

// PTA16 = GPIOA_16,SPI0_SOUT
#define PTA16_GPIO_NAME            A     //!< PTA16 GPIO name
#define PTA16_GPIO_BIT             16    //!< PTA16 GPIO bit number
#define PTA16_GPIO_FN              1     //!< PTA16 Pin multiplexor for GPIO
#if SPI0_SOUT_SEL == 1
#define SPI0_SOUT_FN               2     //!< PTA16 Pin multiplexor for SPI
#define SPI0_SOUT_GPIO             digitalIO_PTA16   //!< PTA16 SPI GPIO
#endif

// PTA17 = GPIOA_17,ADC1_17,SPI0_SIN
#define PTA17_GPIO_NAME            A     //!< PTA17 GPIO name
#define PTA17_GPIO_BIT             17    //!< PTA17 GPIO bit number
#define PTA17_GPIO_FN              1     //!< PTA17 Pin multiplexor for GPIO
#define PTA17_ADC_NUM              1     //!< PTA17 ADC number
#define PTA17_ADC_CH               17    //!< PTA17 ADC channel
#define PTA17_ADC_FN               0     //!< PTA17 Pin multiplexor for ADC
#if SPI0_SIN_SEL == 1
#define SPI0_SIN_FN                2     //!< PTA17 Pin multiplexor for SPI
#define SPI0_SIN_GPIO              digitalIO_PTA17   //!< PTA17 SPI GPIO
#endif

// PTA18 = GPIOA_18
#define PTA18_GPIO_NAME            A     //!< PTA18 GPIO name
#define PTA18_GPIO_BIT             18    //!< PTA18 GPIO bit number
#define PTA18_GPIO_FN              1     //!< PTA18 Pin multiplexor for GPIO

// PTA19 = GPIOA_19,LPTMR0_1
#define PTA19_GPIO_NAME            A     //!< PTA19 GPIO name
#define PTA19_GPIO_BIT             19    //!< PTA19 GPIO bit number
#define PTA19_GPIO_FN              1     //!< PTA19 Pin multiplexor for GPIO
#if LPTMR0_1_SEL == 1
#define LPTMR0_1_FN                6     //!< PTA19 Pin multiplexor for LPTMR
#define LPTMR0_1_GPIO              digitalIO_PTA19   //!< PTA19 LPTMR GPIO
#endif

// PTB0 = GPIOB_0,ADC1_8,FTM1_0,I2C0_SCL (Alias: A0)
#define PTB0_GPIO_NAME             B     //!< PTB0 GPIO name
#define PTB0_GPIO_BIT              0     //!< PTB0 GPIO bit number
#define PTB0_GPIO_FN               1     //!< PTB0 Pin multiplexor for GPIO
#define PTB0_ADC_NUM               1     //!< PTB0 ADC number
#define PTB0_ADC_CH                8     //!< PTB0 ADC channel
#define PTB0_ADC_FN                0     //!< PTB0 Pin multiplexor for ADC
#if FTM1_0_SEL == 2
#define PTB0_FTM_NUM               1     //!< PTB0 FTM number
#define PTB0_FTM_CH                0     //!< PTB0 FTM channel
#define PTB0_FTM_FN                3     //!< PTB0 Pin multiplexor for FTM
#endif
#if I2C0_SCL_SEL == 1
#define I2C0_SCL_FN                2     //!< PTB0 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB0   //!< PTB0 I2C GPIO
#endif

// PTB1 = GPIOB_1,ADC1_9,FTM1_1,I2C0_SDA (Alias: A1)
#define PTB1_GPIO_NAME             B     //!< PTB1 GPIO name
#define PTB1_GPIO_BIT              1     //!< PTB1 GPIO bit number
#define PTB1_GPIO_FN               1     //!< PTB1 Pin multiplexor for GPIO
#define PTB1_ADC_NUM               1     //!< PTB1 ADC number
#define PTB1_ADC_CH                9     //!< PTB1 ADC channel
#define PTB1_ADC_FN                0     //!< PTB1 Pin multiplexor for ADC
#if FTM1_1_SEL == 2
#define PTB1_FTM_NUM               1     //!< PTB1 FTM number
#define PTB1_FTM_CH                1     //!< PTB1 FTM channel
#define PTB1_FTM_FN                3     //!< PTB1 Pin multiplexor for FTM
#endif
#if I2C0_SDA_SEL == 1
#define I2C0_SDA_FN                2     //!< PTB1 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB1   //!< PTB1 I2C GPIO
#endif

// PTB2 = GPIOB_2,ADC0_12,I2C0_SCL (Alias: A5)
#define PTB2_GPIO_NAME             B     //!< PTB2 GPIO name
#define PTB2_GPIO_BIT              2     //!< PTB2 GPIO bit number
#define PTB2_GPIO_FN               1     //!< PTB2 Pin multiplexor for GPIO
#define PTB2_ADC_NUM               0     //!< PTB2 ADC number
#define PTB2_ADC_CH                12    //!< PTB2 ADC channel
#define PTB2_ADC_FN                0     //!< PTB2 Pin multiplexor for ADC
#if I2C0_SCL_SEL == 2
#define I2C0_SCL_FN                2     //!< PTB2 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB2   //!< PTB2 I2C GPIO
#endif

// PTB3 = GPIOB_3,ADC0_13,I2C0_SDA (Alias: A4)
#define PTB3_GPIO_NAME             B     //!< PTB3 GPIO name
#define PTB3_GPIO_BIT              3     //!< PTB3 GPIO bit number
#define PTB3_GPIO_FN               1     //!< PTB3 Pin multiplexor for GPIO
#define PTB3_ADC_NUM               0     //!< PTB3 ADC number
#define PTB3_ADC_CH                13    //!< PTB3 ADC channel
#define PTB3_ADC_FN                0     //!< PTB3 Pin multiplexor for ADC
#if I2C0_SDA_SEL == 2
#define I2C0_SDA_FN                2     //!< PTB3 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB3   //!< PTB3 I2C GPIO
#endif

// PTB6 = GPIOB_6,ADC1_12
#define PTB6_GPIO_NAME             B     //!< PTB6 GPIO name
#define PTB6_GPIO_BIT              6     //!< PTB6 GPIO bit number
#define PTB6_GPIO_FN               1     //!< PTB6 Pin multiplexor for GPIO
#define PTB6_ADC_NUM               1     //!< PTB6 ADC number
#define PTB6_ADC_CH                12    //!< PTB6 ADC channel
#define PTB6_ADC_FN                0     //!< PTB6 Pin multiplexor for ADC

// PTB7 = GPIOB_7,ADC1_13
#define PTB7_GPIO_NAME             B     //!< PTB7 GPIO name
#define PTB7_GPIO_BIT              7     //!< PTB7 GPIO bit number
#define PTB7_GPIO_FN               1     //!< PTB7 Pin multiplexor for GPIO
#define PTB7_ADC_NUM               1     //!< PTB7 ADC number
#define PTB7_ADC_CH                13    //!< PTB7 ADC channel
#define PTB7_ADC_FN                0     //!< PTB7 Pin multiplexor for ADC

// PTB8 = GPIOB_8
#define PTB8_GPIO_NAME             B     //!< PTB8 GPIO name
#define PTB8_GPIO_BIT              8     //!< PTB8 GPIO bit number
#define PTB8_GPIO_FN               1     //!< PTB8 Pin multiplexor for GPIO

// PTB9 = GPIOB_9,SPI1_PCS1
#define PTB9_GPIO_NAME             B     //!< PTB9 GPIO name
#define PTB9_GPIO_BIT              9     //!< PTB9 GPIO bit number
#define PTB9_GPIO_FN               1     //!< PTB9 Pin multiplexor for GPIO
#if SPI1_PCS1_SEL == 1
#define SPI1_PCS1_FN               2     //!< PTB9 Pin multiplexor for SPI
#define SPI1_PCS1_GPIO             digitalIO_PTB9   //!< PTB9 SPI GPIO
#endif

// PTB10 = GPIOB_10,ADC1_14,SPI1_PCS0
#define PTB10_GPIO_NAME            B     //!< PTB10 GPIO name
#define PTB10_GPIO_BIT             10    //!< PTB10 GPIO bit number
#define PTB10_GPIO_FN              1     //!< PTB10 Pin multiplexor for GPIO
#define PTB10_ADC_NUM              1     //!< PTB10 ADC number
#define PTB10_ADC_CH               14    //!< PTB10 ADC channel
#define PTB10_ADC_FN               0     //!< PTB10 Pin multiplexor for ADC
#if SPI1_PCS0_SEL == 1
#define SPI1_PCS0_FN               2     //!< PTB10 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTB10   //!< PTB10 SPI GPIO
#endif

// PTB11 = GPIOB_11,ADC1_15,SPI1_SCK
#define PTB11_GPIO_NAME            B     //!< PTB11 GPIO name
#define PTB11_GPIO_BIT             11    //!< PTB11 GPIO bit number
#define PTB11_GPIO_FN              1     //!< PTB11 Pin multiplexor for GPIO
#define PTB11_ADC_NUM              1     //!< PTB11 ADC number
#define PTB11_ADC_CH               15    //!< PTB11 ADC channel
#define PTB11_ADC_FN               0     //!< PTB11 Pin multiplexor for ADC
#if SPI1_SCK_SEL == 1
#define SPI1_SCK_FN                2     //!< PTB11 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTB11   //!< PTB11 SPI GPIO
#endif

// PTB16 = GPIOB_16,SPI1_SOUT (Alias: D2)
#define PTB16_GPIO_NAME            B     //!< PTB16 GPIO name
#define PTB16_GPIO_BIT             16    //!< PTB16 GPIO bit number
#define PTB16_GPIO_FN              1     //!< PTB16 Pin multiplexor for GPIO
#if SPI1_SOUT_SEL == 1
#define SPI1_SOUT_FN               2     //!< PTB16 Pin multiplexor for SPI
#define SPI1_SOUT_GPIO             digitalIO_PTB16   //!< PTB16 SPI GPIO
#endif

// PTB17 = GPIOB_17,SPI1_SIN
#define PTB17_GPIO_NAME            B     //!< PTB17 GPIO name
#define PTB17_GPIO_BIT             17    //!< PTB17 GPIO bit number
#define PTB17_GPIO_FN              1     //!< PTB17 Pin multiplexor for GPIO
#if SPI1_SIN_SEL == 1
#define SPI1_SIN_FN                2     //!< PTB17 Pin multiplexor for SPI
#define SPI1_SIN_GPIO              digitalIO_PTB17   //!< PTB17 SPI GPIO
#endif

// PTB18 = GPIOB_18,FTM2_0 (Alias: D5)
#define PTB18_GPIO_NAME            B     //!< PTB18 GPIO name
#define PTB18_GPIO_BIT             18    //!< PTB18 GPIO bit number
#define PTB18_GPIO_FN              1     //!< PTB18 Pin multiplexor for GPIO
#define PTB18_FTM_NUM              2     //!< PTB18 FTM number
#define PTB18_FTM_CH               0     //!< PTB18 FTM channel
#define PTB18_FTM_FN               3     //!< PTB18 Pin multiplexor for FTM

// PTB19 = GPIOB_19,FTM2_1 (Alias: D8)
#define PTB19_GPIO_NAME            B     //!< PTB19 GPIO name
#define PTB19_GPIO_BIT             19    //!< PTB19 GPIO bit number
#define PTB19_GPIO_FN              1     //!< PTB19 Pin multiplexor for GPIO
#define PTB19_FTM_NUM              2     //!< PTB19 FTM number
#define PTB19_FTM_CH               1     //!< PTB19 FTM channel
#define PTB19_FTM_FN               3     //!< PTB19 Pin multiplexor for FTM

// PTB20 = GPIOB_20
#define PTB20_GPIO_NAME            B     //!< PTB20 GPIO name
#define PTB20_GPIO_BIT             20    //!< PTB20 GPIO bit number
#define PTB20_GPIO_FN              1     //!< PTB20 Pin multiplexor for GPIO

// PTB21 = GPIOB_21
#define PTB21_GPIO_NAME            B     //!< PTB21 GPIO name
#define PTB21_GPIO_BIT             21    //!< PTB21 GPIO bit number
#define PTB21_GPIO_FN              1     //!< PTB21 Pin multiplexor for GPIO

// PTB22 = GPIOB_22
#define PTB22_GPIO_NAME            B     //!< PTB22 GPIO name
#define PTB22_GPIO_BIT             22    //!< PTB22 GPIO bit number
#define PTB22_GPIO_FN              1     //!< PTB22 Pin multiplexor for GPIO

// PTB23 = GPIOB_23,SPI0_PCS5
#define PTB23_GPIO_NAME            B     //!< PTB23 GPIO name
#define PTB23_GPIO_BIT             23    //!< PTB23 GPIO bit number
#define PTB23_GPIO_FN              1     //!< PTB23 Pin multiplexor for GPIO
#if SPI0_PCS5_SEL == 1
#define SPI0_PCS5_FN               3     //!< PTB23 Pin multiplexor for SPI
#define SPI0_PCS5_GPIO             digitalIO_PTB23   //!< PTB23 SPI GPIO
#endif

// PTC0 = GPIOC_0,ADC0_14,SPI0_PCS4
#define PTC0_GPIO_NAME             C     //!< PTC0 GPIO name
#define PTC0_GPIO_BIT              0     //!< PTC0 GPIO bit number
#define PTC0_GPIO_FN               1     //!< PTC0 Pin multiplexor for GPIO
#define PTC0_ADC_NUM               0     //!< PTC0 ADC number
#define PTC0_ADC_CH                14    //!< PTC0 ADC channel
#define PTC0_ADC_FN                0     //!< PTC0 Pin multiplexor for ADC
#if SPI0_PCS4_SEL == 1
#define SPI0_PCS4_FN               2     //!< PTC0 Pin multiplexor for SPI
#define SPI0_PCS4_GPIO             digitalIO_PTC0   //!< PTC0 SPI GPIO
#endif

// PTC1 = GPIOC_1,ADC0_15,FTM0_0,SPI0_PCS3 (Alias: A2)
#define PTC1_GPIO_NAME             C     //!< PTC1 GPIO name
#define PTC1_GPIO_BIT              1     //!< PTC1 GPIO bit number
#define PTC1_GPIO_FN               1     //!< PTC1 Pin multiplexor for GPIO
#define PTC1_ADC_NUM               0     //!< PTC1 ADC number
#define PTC1_ADC_CH                15    //!< PTC1 ADC channel
#define PTC1_ADC_FN                0     //!< PTC1 Pin multiplexor for ADC
#if FTM0_0_SEL == 2
#define PTC1_FTM_NUM               0     //!< PTC1 FTM number
#define PTC1_FTM_CH                0     //!< PTC1 FTM channel
#define PTC1_FTM_FN                4     //!< PTC1 Pin multiplexor for FTM
#endif
#if SPI0_PCS3_SEL == 1
#define SPI0_PCS3_FN               2     //!< PTC1 Pin multiplexor for SPI
#define SPI0_PCS3_GPIO             digitalIO_PTC1   //!< PTC1 SPI GPIO
#endif

// PTC2 = GPIOC_2,ADC0_4,FTM0_1,SPI0_PCS2 (Alias: A3)
#define PTC2_GPIO_NAME             C     //!< PTC2 GPIO name
#define PTC2_GPIO_BIT              2     //!< PTC2 GPIO bit number
#define PTC2_GPIO_FN               1     //!< PTC2 Pin multiplexor for GPIO
#define PTC2_ADC_NUM               0     //!< PTC2 ADC number
#define PTC2_ADC_CH                4     //!< PTC2 ADC channel
#define PTC2_ADC_FN                0     //!< PTC2 Pin multiplexor for ADC
#if FTM0_1_SEL == 2
#define PTC2_FTM_NUM               0     //!< PTC2 FTM number
#define PTC2_FTM_CH                1     //!< PTC2 FTM channel
#define PTC2_FTM_FN                4     //!< PTC2 Pin multiplexor for FTM
#endif
#if SPI0_PCS2_SEL == 1
#define SPI0_PCS2_FN               2     //!< PTC2 Pin multiplexor for SPI
#define SPI0_PCS2_GPIO             digitalIO_PTC2   //!< PTC2 SPI GPIO
#endif

// PTC3 = GPIOC_3,FTM0_2,SPI0_PCS1 (Alias: D6)
#define PTC3_GPIO_NAME             C     //!< PTC3 GPIO name
#define PTC3_GPIO_BIT              3     //!< PTC3 GPIO bit number
#define PTC3_GPIO_FN               1     //!< PTC3 Pin multiplexor for GPIO
#if FTM0_2_SEL == 2
#define PTC3_FTM_NUM               0     //!< PTC3 FTM number
#define PTC3_FTM_CH                2     //!< PTC3 FTM channel
#define PTC3_FTM_FN                4     //!< PTC3 Pin multiplexor for FTM
#endif
#if SPI0_PCS1_SEL == 1
#define SPI0_PCS1_FN               2     //!< PTC3 Pin multiplexor for SPI
#define SPI0_PCS1_GPIO             digitalIO_PTC3   //!< PTC3 SPI GPIO
#endif

// PTC4 = GPIOC_4,FTM0_3,SPI0_PCS0
#define PTC4_GPIO_NAME             C     //!< PTC4 GPIO name
#define PTC4_GPIO_BIT              4     //!< PTC4 GPIO bit number
#define PTC4_GPIO_FN               1     //!< PTC4 Pin multiplexor for GPIO
#define PTC4_FTM_NUM               0     //!< PTC4 FTM number
#define PTC4_FTM_CH                3     //!< PTC4 FTM channel
#define PTC4_FTM_FN                4     //!< PTC4 Pin multiplexor for FTM
#if SPI0_PCS0_SEL == 2
#define SPI0_PCS0_FN               2     //!< PTC4 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTC4   //!< PTC4 SPI GPIO
#endif

// PTC5 = GPIOC_5,FTM0_2,LPTMR0_2,SPI0_SCK
#define PTC5_GPIO_NAME             C     //!< PTC5 GPIO name
#define PTC5_GPIO_BIT              5     //!< PTC5 GPIO bit number
#define PTC5_GPIO_FN               1     //!< PTC5 Pin multiplexor for GPIO
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

// PTC6 = GPIOC_6,SPI0_SOUT (Alias: D7)
#define PTC6_GPIO_NAME             C     //!< PTC6 GPIO name
#define PTC6_GPIO_BIT              6     //!< PTC6 GPIO bit number
#define PTC6_GPIO_FN               1     //!< PTC6 Pin multiplexor for GPIO
#if SPI0_SOUT_SEL == 2
#define SPI0_SOUT_FN               2     //!< PTC6 Pin multiplexor for SPI
#define SPI0_SOUT_GPIO             digitalIO_PTC6   //!< PTC6 SPI GPIO
#endif

// PTC7 = GPIOC_7,SPI0_SIN
#define PTC7_GPIO_NAME             C     //!< PTC7 GPIO name
#define PTC7_GPIO_BIT              7     //!< PTC7 GPIO bit number
#define PTC7_GPIO_FN               1     //!< PTC7 Pin multiplexor for GPIO
#if SPI0_SIN_SEL == 2
#define SPI0_SIN_FN                2     //!< PTC7 Pin multiplexor for SPI
#define SPI0_SIN_GPIO              digitalIO_PTC7   //!< PTC7 SPI GPIO
#endif

// PTC8 = GPIOC_8,ADC1_4
#define PTC8_GPIO_NAME             C     //!< PTC8 GPIO name
#define PTC8_GPIO_BIT              8     //!< PTC8 GPIO bit number
#define PTC8_GPIO_FN               1     //!< PTC8 Pin multiplexor for GPIO
#define PTC8_ADC_NUM               1     //!< PTC8 ADC number
#define PTC8_ADC_CH                4     //!< PTC8 ADC channel
#define PTC8_ADC_FN                0     //!< PTC8 Pin multiplexor for ADC

// PTC9 = GPIOC_9,ADC1_5
#define PTC9_GPIO_NAME             C     //!< PTC9 GPIO name
#define PTC9_GPIO_BIT              9     //!< PTC9 GPIO bit number
#define PTC9_GPIO_FN               1     //!< PTC9 Pin multiplexor for GPIO
#define PTC9_ADC_NUM               1     //!< PTC9 ADC number
#define PTC9_ADC_CH                5     //!< PTC9 ADC channel
#define PTC9_ADC_FN                0     //!< PTC9 Pin multiplexor for ADC

// PTC10 = GPIOC_10,ADC1_6,I2C1_SCL
#define PTC10_GPIO_NAME            C     //!< PTC10 GPIO name
#define PTC10_GPIO_BIT             10    //!< PTC10 GPIO bit number
#define PTC10_GPIO_FN              1     //!< PTC10 Pin multiplexor for GPIO
#define PTC10_ADC_NUM              1     //!< PTC10 ADC number
#define PTC10_ADC_CH               6     //!< PTC10 ADC channel
#define PTC10_ADC_FN               0     //!< PTC10 Pin multiplexor for ADC
#if I2C1_SCL_SEL == 1
#define I2C1_SCL_FN                2     //!< PTC10 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTC10   //!< PTC10 I2C GPIO
#endif

// PTC11 = GPIOC_11,ADC1_7,I2C1_SDA
#define PTC11_GPIO_NAME            C     //!< PTC11 GPIO name
#define PTC11_GPIO_BIT             11    //!< PTC11 GPIO bit number
#define PTC11_GPIO_FN              1     //!< PTC11 Pin multiplexor for GPIO
#define PTC11_ADC_NUM              1     //!< PTC11 ADC number
#define PTC11_ADC_CH               7     //!< PTC11 ADC channel
#define PTC11_ADC_FN               0     //!< PTC11 Pin multiplexor for ADC
#if I2C1_SDA_SEL == 1
#define I2C1_SDA_FN                2     //!< PTC11 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTC11   //!< PTC11 I2C GPIO
#endif

// PTC12 = GPIOC_12
#define PTC12_GPIO_NAME            C     //!< PTC12 GPIO name
#define PTC12_GPIO_BIT             12    //!< PTC12 GPIO bit number
#define PTC12_GPIO_FN              1     //!< PTC12 Pin multiplexor for GPIO

// PTC13 = GPIOC_13
#define PTC13_GPIO_NAME            C     //!< PTC13 GPIO name
#define PTC13_GPIO_BIT             13    //!< PTC13 GPIO bit number
#define PTC13_GPIO_FN              1     //!< PTC13 Pin multiplexor for GPIO

// PTC14 = GPIOC_14
#define PTC14_GPIO_NAME            C     //!< PTC14 GPIO name
#define PTC14_GPIO_BIT             14    //!< PTC14 GPIO bit number
#define PTC14_GPIO_FN              1     //!< PTC14 Pin multiplexor for GPIO

// PTC15 = GPIOC_15
#define PTC15_GPIO_NAME            C     //!< PTC15 GPIO name
#define PTC15_GPIO_BIT             15    //!< PTC15 GPIO bit number
#define PTC15_GPIO_FN              1     //!< PTC15 Pin multiplexor for GPIO

// PTC16 = GPIOC_16
#define PTC16_GPIO_NAME            C     //!< PTC16 GPIO name
#define PTC16_GPIO_BIT             16    //!< PTC16 GPIO bit number
#define PTC16_GPIO_FN              1     //!< PTC16 Pin multiplexor for GPIO

// PTC17 = GPIOC_17
#define PTC17_GPIO_NAME            C     //!< PTC17 GPIO name
#define PTC17_GPIO_BIT             17    //!< PTC17 GPIO bit number
#define PTC17_GPIO_FN              1     //!< PTC17 Pin multiplexor for GPIO

// PTC18 = GPIOC_18
#define PTC18_GPIO_NAME            C     //!< PTC18 GPIO name
#define PTC18_GPIO_BIT             18    //!< PTC18 GPIO bit number
#define PTC18_GPIO_FN              1     //!< PTC18 Pin multiplexor for GPIO

// PTC19 = GPIOC_19
#define PTC19_GPIO_NAME            C     //!< PTC19 GPIO name
#define PTC19_GPIO_BIT             19    //!< PTC19 GPIO bit number
#define PTC19_GPIO_FN              1     //!< PTC19 Pin multiplexor for GPIO

// PTD0 = GPIOD_0,SPI0_PCS0
#define PTD0_GPIO_NAME             D     //!< PTD0 GPIO name
#define PTD0_GPIO_BIT              0     //!< PTD0 GPIO bit number
#define PTD0_GPIO_FN               1     //!< PTD0 Pin multiplexor for GPIO
#if SPI0_PCS0_SEL == 3
#define SPI0_PCS0_FN               2     //!< PTD0 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTD0   //!< PTD0 SPI GPIO
#endif

// PTD1 = GPIOD_1,ADC0_5,SPI0_SCK
#define PTD1_GPIO_NAME             D     //!< PTD1 GPIO name
#define PTD1_GPIO_BIT              1     //!< PTD1 GPIO bit number
#define PTD1_GPIO_FN               1     //!< PTD1 Pin multiplexor for GPIO
#define PTD1_ADC_NUM               0     //!< PTD1 ADC number
#define PTD1_ADC_CH                5     //!< PTD1 ADC channel
#define PTD1_ADC_FN                0     //!< PTD1 Pin multiplexor for ADC
#if SPI0_SCK_SEL == 3
#define SPI0_SCK_FN                2     //!< PTD1 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTD1   //!< PTD1 SPI GPIO
#endif

// PTD2 = GPIOD_2,SPI0_SOUT,I2C0_SCL (Alias: D0)
#define PTD2_GPIO_NAME             D     //!< PTD2 GPIO name
#define PTD2_GPIO_BIT              2     //!< PTD2 GPIO bit number
#define PTD2_GPIO_FN               1     //!< PTD2 Pin multiplexor for GPIO
#if SPI0_SOUT_SEL == 3
#define SPI0_SOUT_FN               2     //!< PTD2 Pin multiplexor for SPI
#define SPI0_SOUT_GPIO             digitalIO_PTD2   //!< PTD2 SPI GPIO
#endif
#if I2C0_SCL_SEL == 3
#define I2C0_SCL_FN                7     //!< PTD2 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTD2   //!< PTD2 I2C GPIO
#endif

// PTD3 = GPIOD_3,SPI0_SIN,I2C0_SDA (Alias: D1)
#define PTD3_GPIO_NAME             D     //!< PTD3 GPIO name
#define PTD3_GPIO_BIT              3     //!< PTD3 GPIO bit number
#define PTD3_GPIO_FN               1     //!< PTD3 Pin multiplexor for GPIO
#if SPI0_SIN_SEL == 3
#define SPI0_SIN_FN                2     //!< PTD3 Pin multiplexor for SPI
#define SPI0_SIN_GPIO              digitalIO_PTD3   //!< PTD3 SPI GPIO
#endif
#if I2C0_SDA_SEL == 3
#define I2C0_SDA_FN                7     //!< PTD3 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTD3   //!< PTD3 I2C GPIO
#endif

// PTD4 = GPIOD_4,FTM0_4,SPI0_PCS1,SPI1_PCS0 (Alias: D10)
#define PTD4_GPIO_NAME             D     //!< PTD4 GPIO name
#define PTD4_GPIO_BIT              4     //!< PTD4 GPIO bit number
#define PTD4_GPIO_FN               1     //!< PTD4 Pin multiplexor for GPIO
#define PTD4_FTM_NUM               0     //!< PTD4 FTM number
#define PTD4_FTM_CH                4     //!< PTD4 FTM channel
#define PTD4_FTM_FN                4     //!< PTD4 Pin multiplexor for FTM
#if SPI0_PCS1_SEL == 2
#define SPI0_PCS1_FN               2     //!< PTD4 Pin multiplexor for SPI
#define SPI0_PCS1_GPIO             digitalIO_PTD4   //!< PTD4 SPI GPIO
#endif
#if SPI1_PCS0_SEL == 2
#define SPI1_PCS0_FN               7     //!< PTD4 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTD4   //!< PTD4 SPI GPIO
#endif

// PTD5 = GPIOD_5,ADC0_6,FTM0_5,SPI0_PCS2,SPI1_SCK (Alias: D13)
#define PTD5_GPIO_NAME             D     //!< PTD5 GPIO name
#define PTD5_GPIO_BIT              5     //!< PTD5 GPIO bit number
#define PTD5_GPIO_FN               1     //!< PTD5 Pin multiplexor for GPIO
#define PTD5_ADC_NUM               0     //!< PTD5 ADC number
#define PTD5_ADC_CH                6     //!< PTD5 ADC channel
#define PTD5_ADC_FN                0     //!< PTD5 Pin multiplexor for ADC
#if FTM0_5_SEL == 2
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

// PTD6 = GPIOD_6,ADC0_7,FTM0_6,SPI0_PCS3,SPI1_SOUT (Alias: D11)
#define PTD6_GPIO_NAME             D     //!< PTD6 GPIO name
#define PTD6_GPIO_BIT              6     //!< PTD6 GPIO bit number
#define PTD6_GPIO_FN               1     //!< PTD6 Pin multiplexor for GPIO
#define PTD6_ADC_NUM               0     //!< PTD6 ADC number
#define PTD6_ADC_CH                7     //!< PTD6 ADC channel
#define PTD6_ADC_FN                0     //!< PTD6 Pin multiplexor for ADC
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

// PTD7 = GPIOD_7,FTM0_7,SPI1_SIN (Alias: D12)
#define PTD7_GPIO_NAME             D     //!< PTD7 GPIO name
#define PTD7_GPIO_BIT              7     //!< PTD7 GPIO bit number
#define PTD7_GPIO_FN               1     //!< PTD7 Pin multiplexor for GPIO
#if FTM0_7_SEL == 2
#define PTD7_FTM_NUM               0     //!< PTD7 FTM number
#define PTD7_FTM_CH                7     //!< PTD7 FTM channel
#define PTD7_FTM_FN                4     //!< PTD7 Pin multiplexor for FTM
#endif
#if SPI1_SIN_SEL == 2
#define SPI1_SIN_FN                7     //!< PTD7 Pin multiplexor for SPI
#define SPI1_SIN_GPIO              digitalIO_PTD7   //!< PTD7 SPI GPIO
#endif

// PTE0 = GPIOE_0,SPI1_PCS1,I2C1_SDA (Alias: D14)
#define PTE0_GPIO_NAME             E     //!< PTE0 GPIO name
#define PTE0_GPIO_BIT              0     //!< PTE0 GPIO bit number
#define PTE0_GPIO_FN               1     //!< PTE0 Pin multiplexor for GPIO
#if SPI1_PCS1_SEL == 2
#define SPI1_PCS1_FN               2     //!< PTE0 Pin multiplexor for SPI
#define SPI1_PCS1_GPIO             digitalIO_PTE0   //!< PTE0 SPI GPIO
#endif
#if I2C1_SDA_SEL == 2
#define I2C1_SDA_FN                6     //!< PTE0 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTE0   //!< PTE0 I2C GPIO
#endif

// PTE1 = GPIOE_1,SPI1_SOUT,SPI1_SIN,I2C1_SCL (Alias: D15)
#define PTE1_GPIO_NAME             E     //!< PTE1 GPIO name
#define PTE1_GPIO_BIT              1     //!< PTE1 GPIO bit number
#define PTE1_GPIO_FN               1     //!< PTE1 Pin multiplexor for GPIO
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

// PTE2 = GPIOE_2,SPI1_SCK
#define PTE2_GPIO_NAME             E     //!< PTE2 GPIO name
#define PTE2_GPIO_BIT              2     //!< PTE2 GPIO bit number
#define PTE2_GPIO_FN               1     //!< PTE2 Pin multiplexor for GPIO
#if SPI1_SCK_SEL == 3
#define SPI1_SCK_FN                2     //!< PTE2 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTE2   //!< PTE2 SPI GPIO
#endif

// PTE3 = GPIOE_3,SPI1_SIN,SPI1_SOUT
#define PTE3_GPIO_NAME             E     //!< PTE3 GPIO name
#define PTE3_GPIO_BIT              3     //!< PTE3 GPIO bit number
#define PTE3_GPIO_FN               1     //!< PTE3 Pin multiplexor for GPIO
#if SPI1_SIN_SEL == 4
#define SPI1_SIN_FN                2     //!< PTE3 Pin multiplexor for SPI
#define SPI1_SIN_GPIO              digitalIO_PTE3   //!< PTE3 SPI GPIO
#endif
#if SPI1_SOUT_SEL == 4
#define SPI1_SOUT_FN               7     //!< PTE3 Pin multiplexor for SPI
#define SPI1_SOUT_GPIO             digitalIO_PTE3   //!< PTE3 SPI GPIO
#endif

// PTE4 = GPIOE_4,SPI1_PCS0
#define PTE4_GPIO_NAME             E     //!< PTE4 GPIO name
#define PTE4_GPIO_BIT              4     //!< PTE4 GPIO bit number
#define PTE4_GPIO_FN               1     //!< PTE4 Pin multiplexor for GPIO
#if SPI1_PCS0_SEL == 3
#define SPI1_PCS0_FN               2     //!< PTE4 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTE4   //!< PTE4 SPI GPIO
#endif

// PTE5 = GPIOE_5,SPI1_PCS2
#define PTE5_GPIO_NAME             E     //!< PTE5 GPIO name
#define PTE5_GPIO_BIT              5     //!< PTE5 GPIO bit number
#define PTE5_GPIO_FN               1     //!< PTE5 Pin multiplexor for GPIO
#if SPI1_PCS2_SEL == 1
#define SPI1_PCS2_FN               2     //!< PTE5 Pin multiplexor for SPI
#define SPI1_PCS2_GPIO             digitalIO_PTE5   //!< PTE5 SPI GPIO
#endif

// PTE6 = GPIOE_6,SPI1_PCS3
#define PTE6_GPIO_NAME             E     //!< PTE6 GPIO name
#define PTE6_GPIO_BIT              6     //!< PTE6 GPIO bit number
#define PTE6_GPIO_FN               1     //!< PTE6 Pin multiplexor for GPIO
#if SPI1_PCS3_SEL == 1
#define SPI1_PCS3_FN               2     //!< PTE6 Pin multiplexor for SPI
#define SPI1_PCS3_GPIO             digitalIO_PTE6   //!< PTE6 SPI GPIO
#endif

// PTE24 = GPIOE_24,ADC0_17,I2C0_SCL
#define PTE24_GPIO_NAME            E     //!< PTE24 GPIO name
#define PTE24_GPIO_BIT             24    //!< PTE24 GPIO bit number
#define PTE24_GPIO_FN              1     //!< PTE24 Pin multiplexor for GPIO
#define PTE24_ADC_NUM              0     //!< PTE24 ADC number
#define PTE24_ADC_CH               17    //!< PTE24 ADC channel
#define PTE24_ADC_FN               0     //!< PTE24 Pin multiplexor for ADC
#if I2C0_SCL_SEL == 4
#define I2C0_SCL_FN                5     //!< PTE24 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTE24   //!< PTE24 I2C GPIO
#endif

// PTE25 = GPIOE_25,ADC0_18,I2C0_SDA
#define PTE25_GPIO_NAME            E     //!< PTE25 GPIO name
#define PTE25_GPIO_BIT             25    //!< PTE25 GPIO bit number
#define PTE25_GPIO_FN              1     //!< PTE25 Pin multiplexor for GPIO
#define PTE25_ADC_NUM              0     //!< PTE25 ADC number
#define PTE25_ADC_CH               18    //!< PTE25 ADC channel
#define PTE25_ADC_FN               0     //!< PTE25 Pin multiplexor for ADC
#if I2C0_SDA_SEL == 4
#define I2C0_SDA_FN                5     //!< PTE25 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTE25   //!< PTE25 I2C GPIO
#endif

// PTE26 = GPIOE_26
#define PTE26_GPIO_NAME            E     //!< PTE26 GPIO name
#define PTE26_GPIO_BIT             26    //!< PTE26 GPIO bit number
#define PTE26_GPIO_FN              1     //!< PTE26 Pin multiplexor for GPIO

#define DEFAULT_ADC_FN   0 //!< Fixed ADC Multiplexing value for pins
#define DEFAULT_GPIO_FN  1 //!< Fixed GPIO Multiplexing value for pins

#endif /* PIN_MAPPING_H_ */
