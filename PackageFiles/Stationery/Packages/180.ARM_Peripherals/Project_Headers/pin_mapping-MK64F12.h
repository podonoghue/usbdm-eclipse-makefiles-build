/**
 * @file      pin_mapping.h (derived from pin_mapping-MK64F12.h)
 * @version   1.0.0
 * @brief     Pin declarations for MK64F12
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

#define ADC0_CLOCK_REG       SIM->SCGC6          
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC0_MASK 
#define ADC1_CLOCK_REG       SIM->SCGC3          
#define ADC1_CLOCK_MASK      SIM_SCGC3_ADC1_MASK 
#define CMP_CLOCK_REG        SIM->SCGC4          
#define CMP_CLOCK_MASK       SIM_SCGC4_CMP_MASK  
#define CMT_CLOCK_REG        SIM->SCGC4          
#define CMT_CLOCK_MASK       SIM_SCGC4_CMT_MASK  
#define DAC0_CLOCK_REG       SIM->SCGC6          
#define DAC0_CLOCK_MASK      SIM_SCGC6_DAC0_MASK 
#define DAC1_CLOCK_REG       SIM->SCGC2          
#define DAC1_CLOCK_MASK      SIM_SCGC2_DAC1_MASK 
#define DMA_CLOCK_REG        SIM->SCGC7          
#define DMA_CLOCK_MASK       SIM_SCGC7_DMA_MASK  
#define DMAMUX_CLOCK_REG     SIM->SCGC6          
#define DMAMUX_CLOCK_MASK    SIM_SCGC6_DMAMUX_MASK
#define ENET_CLOCK_REG       SIM->SCGC2          
#define ENET_CLOCK_MASK      SIM_SCGC2_ENET_MASK 
#define EWM_CLOCK_REG        SIM->SCGC4          
#define EWM_CLOCK_MASK       SIM_SCGC4_EWM_MASK  
#define FLEXBUS_CLOCK_REG    SIM->SCGC7          
#define FLEXBUS_CLOCK_MASK   SIM_SCGC7_FLEXBUS_MASK
#define FLEXCAN_CLOCK_REG    SIM->SCGC6          
#define FLEXCAN_CLOCK_MASK   SIM_SCGC6_FLEXCAN_MASK
#define FTM0_CLOCK_REG       SIM->SCGC6          
#define FTM0_CLOCK_MASK      SIM_SCGC6_FTM0_MASK 
#define FTM1_CLOCK_REG       SIM->SCGC6          
#define FTM1_CLOCK_MASK      SIM_SCGC6_FTM1_MASK 
#define FTM2_CLOCK_REG       SIM->SCGC6          
#define FTM2_CLOCK_MASK      SIM_SCGC6_FTM2_MASK 
#define FTM3_CLOCK_REG       SIM->SCGC3          
#define FTM3_CLOCK_MASK      SIM_SCGC3_FTM3_MASK 
#define I2C0_CLOCK_REG       SIM->SCGC4          
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK 
#define I2C1_CLOCK_REG       SIM->SCGC4          
#define I2C1_CLOCK_MASK      SIM_SCGC4_I2C1_MASK 
#define I2C2_CLOCK_REG       SIM->SCGC1          
#define I2C2_CLOCK_MASK      SIM_SCGC1_I2C2_MASK 
#define I2S0_CLOCK_REG       SIM->SCGC6          
#define I2S0_CLOCK_MASK      SIM_SCGC6_I2S0_MASK 
#define LPTMR0_CLOCK_REG     SIM->SCGC5          
#define LPTMR0_CLOCK_MASK    SIM_SCGC5_LPTMR_MASK
#define MPU_CLOCK_REG        SIM->SCGC7          
#define MPU_CLOCK_MASK       SIM_SCGC7_MPU_MASK  
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
#define SDHC0_CLOCK_REG      SIM->SCGC3          
#define SDHC0_CLOCK_MASK     SIM_SCGC3_SDHC0_MASK
#define SPI0_CLOCK_REG       SIM->SCGC6          
#define SPI0_CLOCK_MASK      SIM_SCGC6_SPI0_MASK 
#define SPI1_CLOCK_REG       SIM->SCGC6          
#define SPI1_CLOCK_MASK      SIM_SCGC6_SPI1_MASK 
#define SPI2_CLOCK_REG       SIM->SCGC3          
#define SPI2_CLOCK_MASK      SIM_SCGC3_SPI2_MASK 
#define UART0_CLOCK_REG      SIM->SCGC4          
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define UART1_CLOCK_REG      SIM->SCGC4          
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define UART2_CLOCK_REG      SIM->SCGC4          
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define UART3_CLOCK_REG      SIM->SCGC4          
#define UART3_CLOCK_MASK     SIM_SCGC4_UART3_MASK
#define UART4_CLOCK_REG      SIM->SCGC1          
#define UART4_CLOCK_MASK     SIM_SCGC1_UART4_MASK
#define UART5_CLOCK_REG      SIM->SCGC1          
#define UART5_CLOCK_MASK     SIM_SCGC1_UART5_MASK
#define USBDCD_CLOCK_REG     SIM->SCGC6          
#define USBDCD_CLOCK_MASK    SIM_SCGC6_USBDCD_MASK
#define USBOTG_CLOCK_REG     SIM->SCGC4          
#define USBOTG_CLOCK_MASK    SIM_SCGC4_USBOTG_MASK
#define VREF_CLOCK_REG       SIM->SCGC4          
#define VREF_CLOCK_MASK      SIM_SCGC4_VREF_MASK 
#define PORT_CLOCK_REG       SIM->SCGC5          

// <h> Pin Peripheral mapping

// ADC0_DM0 Pin Mapping
//   <o> ADC0_DM0 Pin Selection [ADC0_DM0] <constant>
//   <i> Selects which pin is used for ADC0_DM0
//     <0=> Disabled
//     <1=> ADC0_DM0
//     <1=> Default
#define ADC0_DM0_SEL         1                   

// ADC0_DM1 Pin Mapping
//   <o> ADC0_DM1 Pin Selection [ADC0_DM1] <constant>
//   <i> Selects which pin is used for ADC0_DM1
//     <0=> Disabled
//     <1=> ADC0_DM1
//     <1=> Default
#define ADC0_DM1_SEL         1                   

// ADC0_DM2 Pin Mapping
//   <o> ADC0_DM2 Pin Selection [PTE3] <constant>
//   <i> Selects which pin is used for ADC0_DM2
//     <0=> Disabled
//     <1=> PTE3
//     <1=> Default
#define ADC0_DM2_SEL         1                   

// ADC0_DM3 Pin Mapping
//   <o> ADC0_DM3 Pin Selection [ADC1_DM0] <constant>
//   <i> Selects which pin is used for ADC0_DM3
//     <0=> Disabled
//     <1=> ADC1_DM0
//     <1=> Default
#define ADC0_DM3_SEL         1                   

// ADC0_DP0 Pin Mapping
//   <o> ADC0_DP0 Pin Selection [ADC0_DP0] <constant>
//   <i> Selects which pin is used for ADC0_DP0
//     <0=> Disabled
//     <1=> ADC0_DP0
//     <1=> Default
#define ADC0_DP0_SEL         1                   

// ADC0_DP1 Pin Mapping
//   <o> ADC0_DP1 Pin Selection [ADC0_DP1] <constant>
//   <i> Selects which pin is used for ADC0_DP1
//     <0=> Disabled
//     <1=> ADC0_DP1
//     <1=> Default
#define ADC0_DP1_SEL         1                   

// ADC0_DP2 Pin Mapping
//   <o> ADC0_DP2 Pin Selection [PTE2] <constant>
//   <i> Selects which pin is used for ADC0_DP2
//     <0=> Disabled
//     <1=> PTE2
//     <1=> Default
#define ADC0_DP2_SEL         1                   

// ADC0_DP3 Pin Mapping
//   <o> ADC0_DP3 Pin Selection [ADC1_DP0] <constant>
//   <i> Selects which pin is used for ADC0_DP3
//     <0=> Disabled
//     <1=> ADC1_DP0
//     <1=> Default
#define ADC0_DP3_SEL         1                   

// ADC0_SE4b Pin Mapping
//   <o> ADC0_SE4b Pin Selection [PTC2(D6)] <constant>
//   <i> Selects which pin is used for ADC0_SE4b
//     <0=> Disabled
//     <1=> PTC2 (Alias: D6)
//     <1=> Default
#define ADC0_SE4b_SEL        1                   

// ADC0_SE5b Pin Mapping
//   <o> ADC0_SE5b Pin Selection [PTD1(D13)] <constant>
//   <i> Selects which pin is used for ADC0_SE5b
//     <0=> Disabled
//     <1=> PTD1 (Alias: D13)
//     <1=> Default
#define ADC0_SE5b_SEL        1                   

// ADC0_SE6b Pin Mapping
//   <o> ADC0_SE6b Pin Selection [PTD5(nRF24L01_sck)] <constant>
//   <i> Selects which pin is used for ADC0_SE6b
//     <0=> Disabled
//     <1=> PTD5 (Alias: nRF24L01_sck)
//     <1=> Default
#define ADC0_SE6b_SEL        1                   

// ADC0_SE7b Pin Mapping
//   <o> ADC0_SE7b Pin Selection [PTD6(nRF24L01_mosi)] <constant>
//   <i> Selects which pin is used for ADC0_SE7b
//     <0=> Disabled
//     <1=> PTD6 (Alias: nRF24L01_mosi)
//     <1=> Default
#define ADC0_SE7b_SEL        1                   

// ADC0_SE8 Pin Mapping
//   <o> ADC0_SE8 Pin Selection [PTB0] <constant>
//   <i> Selects which pin is used for ADC0_SE8
//     <0=> Disabled
//     <1=> PTB0
//     <1=> Default
#define ADC0_SE8_SEL         1                   

// ADC0_SE9 Pin Mapping
//   <o> ADC0_SE9 Pin Selection [PTB1] <constant>
//   <i> Selects which pin is used for ADC0_SE9
//     <0=> Disabled
//     <1=> PTB1
//     <1=> Default
#define ADC0_SE9_SEL         1                   

// ADC0_SE10 Pin Mapping
//   <o> ADC0_SE10 Pin Selection [PTA7] <constant>
//   <i> Selects which pin is used for ADC0_SE10
//     <0=> Disabled
//     <1=> PTA7
//     <1=> Default
#define ADC0_SE10_SEL        1                   

// ADC0_SE11 Pin Mapping
//   <o> ADC0_SE11 Pin Selection [PTA8] <constant>
//   <i> Selects which pin is used for ADC0_SE11
//     <0=> Disabled
//     <1=> PTA8
//     <1=> Default
#define ADC0_SE11_SEL        1                   

// ADC0_SE12 Pin Mapping
//   <o> ADC0_SE12 Pin Selection [PTB2(A0)] <constant>
//   <i> Selects which pin is used for ADC0_SE12
//     <0=> Disabled
//     <1=> PTB2 (Alias: A0)
//     <1=> Default
#define ADC0_SE12_SEL        1                   

// ADC0_SE13 Pin Mapping
//   <o> ADC0_SE13 Pin Selection [PTB3(A1)] <constant>
//   <i> Selects which pin is used for ADC0_SE13
//     <0=> Disabled
//     <1=> PTB3 (Alias: A1)
//     <1=> Default
#define ADC0_SE13_SEL        1                   

// ADC0_SE14 Pin Mapping
//   <o> ADC0_SE14 Pin Selection [PTC0] <constant>
//   <i> Selects which pin is used for ADC0_SE14
//     <0=> Disabled
//     <1=> PTC0
//     <1=> Default
#define ADC0_SE14_SEL        1                   

// ADC0_SE15 Pin Mapping
//   <o> ADC0_SE15 Pin Selection [PTC1] <constant>
//   <i> Selects which pin is used for ADC0_SE15
//     <0=> Disabled
//     <1=> PTC1
//     <1=> Default
#define ADC0_SE15_SEL        1                   

// ADC0_SE16 Pin Mapping
//   <o> ADC0_SE16 Pin Selection [ADC0_SE16] <constant>
//   <i> Selects which pin is used for ADC0_SE16
//     <0=> Disabled
//     <1=> ADC0_SE16
//     <1=> Default
#define ADC0_SE16_SEL        1                   

// ADC0_SE17 Pin Mapping
//   <o> ADC0_SE17 Pin Selection [PTE24(D15)] <constant>
//   <i> Selects which pin is used for ADC0_SE17
//     <0=> Disabled
//     <1=> PTE24 (Alias: D15)
//     <1=> Default
#define ADC0_SE17_SEL        1                   

// ADC0_SE18 Pin Mapping
//   <o> ADC0_SE18 Pin Selection [PTE25(D14)] <constant>
//   <i> Selects which pin is used for ADC0_SE18
//     <0=> Disabled
//     <1=> PTE25 (Alias: D14)
//     <1=> Default
#define ADC0_SE18_SEL        1                   

// ADC0_SE21 Pin Mapping
//   <o> ADC0_SE21 Pin Selection [ADC0_SE16] <constant>
//   <i> Selects which pin is used for ADC0_SE21
//     <0=> Disabled
//     <1=> ADC0_SE16
//     <1=> Default
#define ADC0_SE21_SEL        1                   

// ADC0_SE22 Pin Mapping
//   <o> ADC0_SE22 Pin Selection [ADC1_SE16] <constant>
//   <i> Selects which pin is used for ADC0_SE22
//     <0=> Disabled
//     <1=> ADC1_SE16
//     <1=> Default
#define ADC0_SE22_SEL        1                   

// ADC0_SE23 Pin Mapping
//   <o> ADC0_SE23 Pin Selection [ADC0_SE23] <constant>
//   <i> Selects which pin is used for ADC0_SE23
//     <0=> Disabled
//     <1=> ADC0_SE23
//     <1=> Default
#define ADC0_SE23_SEL        1                   

// ADC1_DM0 Pin Mapping
//   <o> ADC1_DM0 Pin Selection [ADC1_DM0] <constant>
//   <i> Selects which pin is used for ADC1_DM0
//     <0=> Disabled
//     <1=> ADC1_DM0
//     <1=> Default
#define ADC1_DM0_SEL         1                   

// ADC1_DM1 Pin Mapping
//   <o> ADC1_DM1 Pin Selection [ADC1_DM1] <constant>
//   <i> Selects which pin is used for ADC1_DM1
//     <0=> Disabled
//     <1=> ADC1_DM1
//     <1=> Default
#define ADC1_DM1_SEL         1                   

// ADC1_DM3 Pin Mapping
//   <o> ADC1_DM3 Pin Selection [ADC0_DM0] <constant>
//   <i> Selects which pin is used for ADC1_DM3
//     <0=> Disabled
//     <1=> ADC0_DM0
//     <1=> Default
#define ADC1_DM3_SEL         1                   

// ADC1_DP0 Pin Mapping
//   <o> ADC1_DP0 Pin Selection [ADC1_DP0] <constant>
//   <i> Selects which pin is used for ADC1_DP0
//     <0=> Disabled
//     <1=> ADC1_DP0
//     <1=> Default
#define ADC1_DP0_SEL         1                   

// ADC1_DP1 Pin Mapping
//   <o> ADC1_DP1 Pin Selection [ADC1_DP1] <constant>
//   <i> Selects which pin is used for ADC1_DP1
//     <0=> Disabled
//     <1=> ADC1_DP1
//     <1=> Default
#define ADC1_DP1_SEL         1                   

// ADC1_DP3 Pin Mapping
//   <o> ADC1_DP3 Pin Selection [ADC0_DP0] <constant>
//   <i> Selects which pin is used for ADC1_DP3
//     <0=> Disabled
//     <1=> ADC0_DP0
//     <1=> Default
#define ADC1_DP3_SEL         1                   

// ADC1_SE4a Pin Mapping
//   <o> ADC1_SE4a Pin Selection [PTE0] <constant>
//   <i> Selects which pin is used for ADC1_SE4a
//     <0=> Disabled
//     <1=> PTE0
//     <1=> Default
#define ADC1_SE4a_SEL        1                   

// ADC1_SE4b Pin Mapping
//   <o> ADC1_SE4b Pin Selection [PTC8] <constant>
//   <i> Selects which pin is used for ADC1_SE4b
//     <0=> Disabled
//     <1=> PTC8
//     <1=> Default
#define ADC1_SE4b_SEL        1                   

// ADC1_SE5a Pin Mapping
//   <o> ADC1_SE5a Pin Selection [PTE1] <constant>
//   <i> Selects which pin is used for ADC1_SE5a
//     <0=> Disabled
//     <1=> PTE1
//     <1=> Default
#define ADC1_SE5a_SEL        1                   

// ADC1_SE5b Pin Mapping
//   <o> ADC1_SE5b Pin Selection [PTC9] <constant>
//   <i> Selects which pin is used for ADC1_SE5b
//     <0=> Disabled
//     <1=> PTC9
//     <1=> Default
#define ADC1_SE5b_SEL        1                   

// ADC1_SE6a Pin Mapping
//   <o> ADC1_SE6a Pin Selection [PTE2] <constant>
//   <i> Selects which pin is used for ADC1_SE6a
//     <0=> Disabled
//     <1=> PTE2
//     <1=> Default
#define ADC1_SE6a_SEL        1                   

// ADC1_SE6b Pin Mapping
//   <o> ADC1_SE6b Pin Selection [PTC10(A5)] <constant>
//   <i> Selects which pin is used for ADC1_SE6b
//     <0=> Disabled
//     <1=> PTC10 (Alias: A5)
//     <1=> Default
#define ADC1_SE6b_SEL        1                   

// ADC1_SE7a Pin Mapping
//   <o> ADC1_SE7a Pin Selection [PTE3] <constant>
//   <i> Selects which pin is used for ADC1_SE7a
//     <0=> Disabled
//     <1=> PTE3
//     <1=> Default
#define ADC1_SE7a_SEL        1                   

// ADC1_SE7b Pin Mapping
//   <o> ADC1_SE7b Pin Selection [PTC11(A4)] <constant>
//   <i> Selects which pin is used for ADC1_SE7b
//     <0=> Disabled
//     <1=> PTC11 (Alias: A4)
//     <1=> Default
#define ADC1_SE7b_SEL        1                   

// ADC1_SE8 Pin Mapping
//   <o> ADC1_SE8 Pin Selection [PTB0] <constant>
//   <i> Selects which pin is used for ADC1_SE8
//     <0=> Disabled
//     <1=> PTB0
//     <1=> Default
#define ADC1_SE8_SEL         1                   

// ADC1_SE9 Pin Mapping
//   <o> ADC1_SE9 Pin Selection [PTB1] <constant>
//   <i> Selects which pin is used for ADC1_SE9
//     <0=> Disabled
//     <1=> PTB1
//     <1=> Default
#define ADC1_SE9_SEL         1                   

// ADC1_SE10 Pin Mapping
//   <o> ADC1_SE10 Pin Selection [PTB4] <constant>
//   <i> Selects which pin is used for ADC1_SE10
//     <0=> Disabled
//     <1=> PTB4
//     <1=> Default
#define ADC1_SE10_SEL        1                   

// ADC1_SE11 Pin Mapping
//   <o> ADC1_SE11 Pin Selection [PTB5] <constant>
//   <i> Selects which pin is used for ADC1_SE11
//     <0=> Disabled
//     <1=> PTB5
//     <1=> Default
#define ADC1_SE11_SEL        1                   

// ADC1_SE12 Pin Mapping
//   <o> ADC1_SE12 Pin Selection [PTB6] <constant>
//   <i> Selects which pin is used for ADC1_SE12
//     <0=> Disabled
//     <1=> PTB6
//     <1=> Default
#define ADC1_SE12_SEL        1                   

// ADC1_SE13 Pin Mapping
//   <o> ADC1_SE13 Pin Selection [PTB7] <constant>
//   <i> Selects which pin is used for ADC1_SE13
//     <0=> Disabled
//     <1=> PTB7
//     <1=> Default
#define ADC1_SE13_SEL        1                   

// ADC1_SE14 Pin Mapping
//   <o> ADC1_SE14 Pin Selection [PTB10(A2)] <constant>
//   <i> Selects which pin is used for ADC1_SE14
//     <0=> Disabled
//     <1=> PTB10 (Alias: A2)
//     <1=> Default
#define ADC1_SE14_SEL        1                   

// ADC1_SE15 Pin Mapping
//   <o> ADC1_SE15 Pin Selection [PTB11(A3)] <constant>
//   <i> Selects which pin is used for ADC1_SE15
//     <0=> Disabled
//     <1=> PTB11 (Alias: A3)
//     <1=> Default
#define ADC1_SE15_SEL        1                   

// ADC1_SE16 Pin Mapping
//   <o> ADC1_SE16 Pin Selection [ADC1_SE16] <constant>
//   <i> Selects which pin is used for ADC1_SE16
//     <0=> Disabled
//     <1=> ADC1_SE16
//     <1=> Default
#define ADC1_SE16_SEL        1                   

// ADC1_SE17 Pin Mapping
//   <o> ADC1_SE17 Pin Selection [PTA17] <constant>
//   <i> Selects which pin is used for ADC1_SE17
//     <0=> Disabled
//     <1=> PTA17
//     <1=> Default
#define ADC1_SE17_SEL        1                   

// ADC1_SE18 Pin Mapping
//   <o> ADC1_SE18 Pin Selection [ADC1_SE18] <constant>
//   <i> Selects which pin is used for ADC1_SE18
//     <0=> Disabled
//     <1=> ADC1_SE18
//     <1=> Default
#define ADC1_SE18_SEL        1                   

// ADC1_SE23 Pin Mapping
//   <o> ADC1_SE23 Pin Selection [ADC1_SE23] <constant>
//   <i> Selects which pin is used for ADC1_SE23
//     <0=> Disabled
//     <1=> ADC1_SE23
//     <1=> Default
#define ADC1_SE23_SEL        1                   

// FTM0_CH0 Pin Mapping
//   <o> FTM0_CH0 Pin Selection [PTA3, PTC1] 
//   <i> Selects which pin is used for FTM0_CH0
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTC1
//     <2=> Default
#define FTM0_CH0_SEL         2                   

// FTM0_CH1 Pin Mapping
//   <o> FTM0_CH1 Pin Selection [PTA4, PTC2(D6)] 
//   <i> Selects which pin is used for FTM0_CH1
//     <0=> Disabled
//     <1=> PTA4
//     <2=> PTC2 (Alias: D6)
//     <2=> Default
#define FTM0_CH1_SEL         2                   

// FTM0_CH2 Pin Mapping
//   <o> FTM0_CH2 Pin Selection [PTA5, PTC3(D7), PTC5] 
//   <i> Selects which pin is used for FTM0_CH2
//     <0=> Disabled
//     <1=> PTA5
//     <2=> PTC3 (Alias: D7)
//     <3=> PTC5
//     <2=> Default
#define FTM0_CH2_SEL         2                   

// FTM0_CH3 Pin Mapping
//   <o> FTM0_CH3 Pin Selection [PTA6, PTC4(D9)] 
//   <i> Selects which pin is used for FTM0_CH3
//     <0=> Disabled
//     <1=> PTA6
//     <2=> PTC4 (Alias: D9)
//     <2=> Default
#define FTM0_CH3_SEL         2                   

// FTM0_CH4 Pin Mapping
//   <o> FTM0_CH4 Pin Selection [PTA7, PTB12, PTD4(nRF24L01_cs)] 
//   <i> Selects which pin is used for FTM0_CH4
//     <0=> Disabled
//     <1=> PTA7
//     <2=> PTB12
//     <3=> PTD4 (Alias: nRF24L01_cs)
//     <1=> Default
#define FTM0_CH4_SEL         1                   

// FTM0_CH5 Pin Mapping
//   <o> FTM0_CH5 Pin Selection [PTA0(D8), PTB13, PTD5(nRF24L01_sck)] 
//   <i> Selects which pin is used for FTM0_CH5
//     <0=> Disabled
//     <1=> PTA0 (Alias: D8)
//     <2=> PTB13
//     <3=> PTD5 (Alias: nRF24L01_sck)
//     <1=> Default
#define FTM0_CH5_SEL         1                   

// FTM0_CH6 Pin Mapping
//   <o> FTM0_CH6 Pin Selection [PTA1(D3), PTD6(nRF24L01_mosi)] 
//   <i> Selects which pin is used for FTM0_CH6
//     <0=> Disabled
//     <1=> PTA1 (Alias: D3)
//     <2=> PTD6 (Alias: nRF24L01_mosi)
//     <1=> Default
#define FTM0_CH6_SEL         1                   

// FTM0_CH7 Pin Mapping
//   <o> FTM0_CH7 Pin Selection [PTA2(D5), PTD7(nRF24L01_miso)] 
//   <i> Selects which pin is used for FTM0_CH7
//     <0=> Disabled
//     <1=> PTA2 (Alias: D5)
//     <2=> PTD7 (Alias: nRF24L01_miso)
//     <1=> Default
#define FTM0_CH7_SEL         1                   

// FTM1_CH0 Pin Mapping
//   <o> FTM1_CH0 Pin Selection [PTA8, PTA12, PTB0, PTB12] 
//   <i> Selects which pin is used for FTM1_CH0
//     <0=> Disabled
//     <1=> PTA8
//     <2=> PTA12
//     <3=> PTB0
//     <4=> PTB12
//     <1=> Default
#define FTM1_CH0_SEL         1                   

// FTM1_CH1 Pin Mapping
//   <o> FTM1_CH1 Pin Selection [PTA9, PTA13, PTB1, PTB13] 
//   <i> Selects which pin is used for FTM1_CH1
//     <0=> Disabled
//     <1=> PTA9
//     <2=> PTA13
//     <3=> PTB1
//     <4=> PTB13
//     <1=> Default
#define FTM1_CH1_SEL         1                   

// FTM2_CH0 Pin Mapping
//   <o> FTM2_CH0 Pin Selection [PTA10, PTB18] 
//   <i> Selects which pin is used for FTM2_CH0
//     <0=> Disabled
//     <1=> PTA10
//     <2=> PTB18
//     <1=> Default
#define FTM2_CH0_SEL         1                   

// FTM2_CH1 Pin Mapping
//   <o> FTM2_CH1 Pin Selection [PTA11, PTB19] 
//   <i> Selects which pin is used for FTM2_CH1
//     <0=> Disabled
//     <1=> PTA11
//     <2=> PTB19
//     <1=> Default
#define FTM2_CH1_SEL         1                   

// FTM3_CH0 Pin Mapping
//   <o> FTM3_CH0 Pin Selection [PTD0(D10), PTE5] 
//   <i> Selects which pin is used for FTM3_CH0
//     <0=> Disabled
//     <1=> PTD0 (Alias: D10)
//     <2=> PTE5
//     <1=> Default
#define FTM3_CH0_SEL         1                   

// FTM3_CH1 Pin Mapping
//   <o> FTM3_CH1 Pin Selection [PTD1(D13), PTE6] 
//   <i> Selects which pin is used for FTM3_CH1
//     <0=> Disabled
//     <1=> PTD1 (Alias: D13)
//     <2=> PTE6
//     <1=> Default
#define FTM3_CH1_SEL         1                   

// FTM3_CH2 Pin Mapping
//   <o> FTM3_CH2 Pin Selection [PTD2(D11), PTE7] 
//   <i> Selects which pin is used for FTM3_CH2
//     <0=> Disabled
//     <1=> PTD2 (Alias: D11)
//     <2=> PTE7
//     <1=> Default
#define FTM3_CH2_SEL         1                   

// FTM3_CH3 Pin Mapping
//   <o> FTM3_CH3 Pin Selection [PTD3(D12), PTE8] 
//   <i> Selects which pin is used for FTM3_CH3
//     <0=> Disabled
//     <1=> PTD3 (Alias: D12)
//     <2=> PTE8
//     <1=> Default
#define FTM3_CH3_SEL         1                   

// FTM3_CH4 Pin Mapping
//   <o> FTM3_CH4 Pin Selection [PTC8, PTE9] 
//   <i> Selects which pin is used for FTM3_CH4
//     <0=> Disabled
//     <1=> PTC8
//     <2=> PTE9
//     <1=> Default
#define FTM3_CH4_SEL         1                   

// FTM3_CH5 Pin Mapping
//   <o> FTM3_CH5 Pin Selection [PTC9, PTE10] 
//   <i> Selects which pin is used for FTM3_CH5
//     <0=> Disabled
//     <1=> PTC9
//     <2=> PTE10
//     <1=> Default
#define FTM3_CH5_SEL         1                   

// FTM3_CH6 Pin Mapping
//   <o> FTM3_CH6 Pin Selection [PTC10(A5), PTE11] 
//   <i> Selects which pin is used for FTM3_CH6
//     <0=> Disabled
//     <1=> PTC10 (Alias: A5)
//     <2=> PTE11
//     <1=> Default
#define FTM3_CH6_SEL         1                   

// FTM3_CH7 Pin Mapping
//   <o> FTM3_CH7 Pin Selection [PTC11(A4), PTE12] 
//   <i> Selects which pin is used for FTM3_CH7
//     <0=> Disabled
//     <1=> PTC11 (Alias: A4)
//     <2=> PTE12
//     <1=> Default
#define FTM3_CH7_SEL         1                   

// I2C0_SCL Pin Mapping
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

// I2C0_SDA Pin Mapping
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

// I2C1_SDA Pin Mapping
//   <o> I2C1_SDA Pin Selection [PTC11(A4), PTE0] 
//   <i> Selects which pin is used for I2C1_SDA
//     <0=> Disabled
//     <1=> PTC11 (Alias: A4)
//     <2=> PTE0
//     <1=> Default
#define I2C1_SDA_SEL         1                   

// I2C1_SCL Pin Mapping
//   <o> I2C1_SCL Pin Selection [PTC10(A5), PTE1] 
//   <i> Selects which pin is used for I2C1_SCL
//     <0=> Disabled
//     <1=> PTC10 (Alias: A5)
//     <2=> PTE1
//     <1=> Default
#define I2C1_SCL_SEL         1                   

// I2C2_SDA Pin Mapping
//   <o> I2C2_SDA Pin Selection [PTA11, PTA13] 
//   <i> Selects which pin is used for I2C2_SDA
//     <0=> Disabled
//     <1=> PTA11
//     <2=> PTA13
//     <1=> Default
#define I2C2_SDA_SEL         1                   

// I2C2_SCL Pin Mapping
//   <o> I2C2_SCL Pin Selection [PTA12, PTA14] 
//   <i> Selects which pin is used for I2C2_SCL
//     <0=> Disabled
//     <1=> PTA12
//     <2=> PTA14
//     <1=> Default
#define I2C2_SCL_SEL         1                   

// LPTMR0_ALT1 Pin Mapping
//   <o> LPTMR0_ALT1 Pin Selection [PTA19] 
//   <i> Selects which pin is used for LPTMR0_ALT1
//     <0=> Disabled
//     <1=> PTA19
//     <0=> Default
#define LPTMR0_ALT1_SEL      0                   

// LPTMR0_ALT2 Pin Mapping
//   <o> LPTMR0_ALT2 Pin Selection [PTC5] 
//   <i> Selects which pin is used for LPTMR0_ALT2
//     <0=> Disabled
//     <1=> PTC5
//     <0=> Default
#define LPTMR0_ALT2_SEL      0                   

// SPI0_PCS0 Pin Mapping
//   <o> SPI0_PCS0 Pin Selection [PTA14, PTC4(D9), PTD0(D10)] 
//   <i> Selects which pin is used for SPI0_PCS0
//     <0=> Disabled
//     <1=> PTA14
//     <2=> PTC4 (Alias: D9)
//     <3=> PTD0 (Alias: D10)
//     <0=> Default
#define SPI0_PCS0_SEL        0                   

// SPI0_PCS1 Pin Mapping
//   <o> SPI0_PCS1 Pin Selection [PTC3(D7), PTD4(nRF24L01_cs)] 
//   <i> Selects which pin is used for SPI0_PCS1
//     <0=> Disabled
//     <1=> PTC3 (Alias: D7)
//     <2=> PTD4 (Alias: nRF24L01_cs)
//     <0=> Default
#define SPI0_PCS1_SEL        0                   

// SPI0_PCS2 Pin Mapping
//   <o> SPI0_PCS2 Pin Selection [PTC2(D6), PTD5(nRF24L01_sck)] 
//   <i> Selects which pin is used for SPI0_PCS2
//     <0=> Disabled
//     <1=> PTC2 (Alias: D6)
//     <2=> PTD5 (Alias: nRF24L01_sck)
//     <0=> Default
#define SPI0_PCS2_SEL        0                   

// SPI0_PCS3 Pin Mapping
//   <o> SPI0_PCS3 Pin Selection [PTC1, PTD6(nRF24L01_mosi)] 
//   <i> Selects which pin is used for SPI0_PCS3
//     <0=> Disabled
//     <1=> PTC1
//     <2=> PTD6 (Alias: nRF24L01_mosi)
//     <0=> Default
#define SPI0_PCS3_SEL        0                   

// SPI0_PCS4 Pin Mapping
//   <o> SPI0_PCS4 Pin Selection [PTC0] 
//   <i> Selects which pin is used for SPI0_PCS4
//     <0=> Disabled
//     <1=> PTC0
//     <0=> Default
#define SPI0_PCS4_SEL        0                   

// SPI0_PCS5 Pin Mapping
//   <o> SPI0_PCS5 Pin Selection [PTB23(D4)] 
//   <i> Selects which pin is used for SPI0_PCS5
//     <0=> Disabled
//     <1=> PTB23 (Alias: D4)
//     <0=> Default
#define SPI0_PCS5_SEL        0                   

// SPI0_SCK Pin Mapping
//   <o> SPI0_SCK Pin Selection [PTA15, PTC5, PTD1(D13)] 
//   <i> Selects which pin is used for SPI0_SCK
//     <0=> Disabled
//     <1=> PTA15
//     <2=> PTC5
//     <3=> PTD1 (Alias: D13)
//     <3=> Default
#define SPI0_SCK_SEL         3                   

// SPI0_SIN Pin Mapping
//   <o> SPI0_SIN Pin Selection [PTA17, PTC7, PTD3(D12)] 
//   <i> Selects which pin is used for SPI0_SIN
//     <0=> Disabled
//     <1=> PTA17
//     <2=> PTC7
//     <3=> PTD3 (Alias: D12)
//     <3=> Default
#define SPI0_SIN_SEL         3                   

// SPI0_SOUT Pin Mapping
//   <o> SPI0_SOUT Pin Selection [PTA16, PTC6, PTD2(D11)] 
//   <i> Selects which pin is used for SPI0_SOUT
//     <0=> Disabled
//     <1=> PTA16
//     <2=> PTC6
//     <3=> PTD2 (Alias: D11)
//     <3=> Default
#define SPI0_SOUT_SEL        3                   

// SPI1_PCS0 Pin Mapping
//   <o> SPI1_PCS0 Pin Selection [PTB10(A2), PTD4(nRF24L01_cs), PTE4] 
//   <i> Selects which pin is used for SPI1_PCS0
//     <0=> Disabled
//     <1=> PTB10 (Alias: A2)
//     <2=> PTD4 (Alias: nRF24L01_cs)
//     <3=> PTE4
//     <2=> Default
#define SPI1_PCS0_SEL        2                   

// SPI1_PCS1 Pin Mapping
//   <o> SPI1_PCS1 Pin Selection [PTB9(D2), PTE0] 
//   <i> Selects which pin is used for SPI1_PCS1
//     <0=> Disabled
//     <1=> PTB9 (Alias: D2)
//     <2=> PTE0
//     <0=> Default
#define SPI1_PCS1_SEL        0                   

// SPI1_PCS2 Pin Mapping
//   <o> SPI1_PCS2 Pin Selection [PTE5] 
//   <i> Selects which pin is used for SPI1_PCS2
//     <0=> Disabled
//     <1=> PTE5
//     <0=> Default
#define SPI1_PCS2_SEL        0                   

// SPI1_PCS3 Pin Mapping
//   <o> SPI1_PCS3 Pin Selection [PTE6] 
//   <i> Selects which pin is used for SPI1_PCS3
//     <0=> Disabled
//     <1=> PTE6
//     <0=> Default
#define SPI1_PCS3_SEL        0                   

// SPI1_SCK Pin Mapping
//   <o> SPI1_SCK Pin Selection [PTB11(A3), PTD5(nRF24L01_sck), PTE2] 
//   <i> Selects which pin is used for SPI1_SCK
//     <0=> Disabled
//     <1=> PTB11 (Alias: A3)
//     <2=> PTD5 (Alias: nRF24L01_sck)
//     <3=> PTE2
//     <2=> Default
#define SPI1_SCK_SEL         2                   

// SPI1_SIN Pin Mapping
//   <o> SPI1_SIN Pin Selection [PTB17, PTD7(nRF24L01_miso), PTE1, PTE3] 
//   <i> Selects which pin is used for SPI1_SIN
//     <0=> Disabled
//     <1=> PTB17
//     <2=> PTD7 (Alias: nRF24L01_miso)
//     <3=> PTE1
//     <4=> PTE3
//     <2=> Default
#define SPI1_SIN_SEL         2                   

// SPI1_SOUT Pin Mapping
//   <o> SPI1_SOUT Pin Selection [PTB16, PTD6(nRF24L01_mosi), PTE1, PTE3] 
//   <i> Selects which pin is used for SPI1_SOUT
//     <0=> Disabled
//     <1=> PTB16
//     <2=> PTD6 (Alias: nRF24L01_mosi)
//     <3=> PTE1
//     <4=> PTE3
//     <2=> Default
#define SPI1_SOUT_SEL        2                   

// SPI2_PCS0 Pin Mapping
//   <o> SPI2_PCS0 Pin Selection [PTB20, PTD11] 
//   <i> Selects which pin is used for SPI2_PCS0
//     <0=> Disabled
//     <1=> PTB20
//     <2=> PTD11
//     <0=> Default
#define SPI2_PCS0_SEL        0                   

// SPI2_PCS1 Pin Mapping
//   <o> SPI2_PCS1 Pin Selection [PTD15] 
//   <i> Selects which pin is used for SPI2_PCS1
//     <0=> Disabled
//     <1=> PTD15
//     <0=> Default
#define SPI2_PCS1_SEL        0                   

// SPI2_SCK Pin Mapping
//   <o> SPI2_SCK Pin Selection [PTB21, PTD12] 
//   <i> Selects which pin is used for SPI2_SCK
//     <0=> Disabled
//     <1=> PTB21
//     <2=> PTD12
//     <1=> Default
#define SPI2_SCK_SEL         1                   

// SPI2_SIN Pin Mapping
//   <o> SPI2_SIN Pin Selection [PTB23(D4), PTD14] 
//   <i> Selects which pin is used for SPI2_SIN
//     <0=> Disabled
//     <1=> PTB23 (Alias: D4)
//     <2=> PTD14
//     <1=> Default
#define SPI2_SIN_SEL         1                   

// SPI2_SOUT Pin Mapping
//   <o> SPI2_SOUT Pin Selection [PTB22, PTD13] 
//   <i> Selects which pin is used for SPI2_SOUT
//     <0=> Disabled
//     <1=> PTB22
//     <2=> PTD13
//     <1=> Default
#define SPI2_SOUT_SEL        1                   

// </h>

//-------- <<< end of configuration section >>> -----------------  

// ADC0_DM0 = ADC0_DM0,ADC1_DM3
#define ADC0_DM0_ADC_NUM           0     //!< ADC0_DM0 ADC number
#define ADC0_DM0_ADC_CH            0     //!< ADC0_DM0 ADC channel
#define ADC0_DM0_ADC_FN            0     //!< ADC0_DM0 Pin multiplexor for ADC
#define ADC0_DM0_ADC_NUM_1         1     //!< ADC0_DM0 ADC number
#define ADC0_DM0_ADC_CH_1          3     //!< ADC0_DM0 ADC channel
#define ADC0_DM0_ADC_FN_1          0     //!< ADC0_DM0 Pin multiplexor for ADC

// ADC0_DM1 = ADC0_DM1
#define ADC0_DM1_ADC_NUM           0     //!< ADC0_DM1 ADC number
#define ADC0_DM1_ADC_CH            1     //!< ADC0_DM1 ADC channel
#define ADC0_DM1_ADC_FN            0     //!< ADC0_DM1 Pin multiplexor for ADC

// ADC0_DP0 = ADC0_DP0,ADC1_DP3
#define ADC0_DP0_ADC_NUM           0     //!< ADC0_DP0 ADC number
#define ADC0_DP0_ADC_CH            0     //!< ADC0_DP0 ADC channel
#define ADC0_DP0_ADC_FN            0     //!< ADC0_DP0 Pin multiplexor for ADC
#define ADC0_DP0_ADC_NUM_1         1     //!< ADC0_DP0 ADC number
#define ADC0_DP0_ADC_CH_1          3     //!< ADC0_DP0 ADC channel
#define ADC0_DP0_ADC_FN_1          0     //!< ADC0_DP0 Pin multiplexor for ADC

// ADC0_DP1 = ADC0_DP1
#define ADC0_DP1_ADC_NUM           0     //!< ADC0_DP1 ADC number
#define ADC0_DP1_ADC_CH            1     //!< ADC0_DP1 ADC channel
#define ADC0_DP1_ADC_FN            0     //!< ADC0_DP1 Pin multiplexor for ADC

// ADC0_SE16 = ADC0_SE16,ADC0_SE21
#define ADC0_SE16_ADC_NUM          0     //!< ADC0_SE16 ADC number
#define ADC0_SE16_ADC_CH           16    //!< ADC0_SE16 ADC channel
#define ADC0_SE16_ADC_FN           0     //!< ADC0_SE16 Pin multiplexor for ADC
#define ADC0_SE16_ADC_NUM_1         0     //!< ADC0_SE16 ADC number
#define ADC0_SE16_ADC_CH_1         21    //!< ADC0_SE16 ADC channel
#define ADC0_SE16_ADC_FN_1         0     //!< ADC0_SE16 Pin multiplexor for ADC

// ADC0_SE23 = ADC0_SE23
#define ADC0_SE23_ADC_NUM          0     //!< ADC0_SE23 ADC number
#define ADC0_SE23_ADC_CH           23    //!< ADC0_SE23 ADC channel
#define ADC0_SE23_ADC_FN           0     //!< ADC0_SE23 Pin multiplexor for ADC

// ADC1_DM0 = ADC1_DM0,ADC0_DM3
#define ADC1_DM0_ADC_NUM           1     //!< ADC1_DM0 ADC number
#define ADC1_DM0_ADC_CH            0     //!< ADC1_DM0 ADC channel
#define ADC1_DM0_ADC_FN            0     //!< ADC1_DM0 Pin multiplexor for ADC
#define ADC1_DM0_ADC_NUM_1         0     //!< ADC1_DM0 ADC number
#define ADC1_DM0_ADC_CH_1          3     //!< ADC1_DM0 ADC channel
#define ADC1_DM0_ADC_FN_1          0     //!< ADC1_DM0 Pin multiplexor for ADC

// ADC1_DM1 = ADC1_DM1
#define ADC1_DM1_ADC_NUM           1     //!< ADC1_DM1 ADC number
#define ADC1_DM1_ADC_CH            1     //!< ADC1_DM1 ADC channel
#define ADC1_DM1_ADC_FN            0     //!< ADC1_DM1 Pin multiplexor for ADC

// ADC1_DP0 = ADC1_DP0,ADC0_DP3
#define ADC1_DP0_ADC_NUM           1     //!< ADC1_DP0 ADC number
#define ADC1_DP0_ADC_CH            0     //!< ADC1_DP0 ADC channel
#define ADC1_DP0_ADC_FN            0     //!< ADC1_DP0 Pin multiplexor for ADC
#define ADC1_DP0_ADC_NUM_1         0     //!< ADC1_DP0 ADC number
#define ADC1_DP0_ADC_CH_1          3     //!< ADC1_DP0 ADC channel
#define ADC1_DP0_ADC_FN_1          0     //!< ADC1_DP0 Pin multiplexor for ADC

// ADC1_DP1 = ADC1_DP1
#define ADC1_DP1_ADC_NUM           1     //!< ADC1_DP1 ADC number
#define ADC1_DP1_ADC_CH            1     //!< ADC1_DP1 ADC channel
#define ADC1_DP1_ADC_FN            0     //!< ADC1_DP1 Pin multiplexor for ADC

// ADC1_SE16 = ADC1_SE16,ADC0_SE22
#define ADC1_SE16_ADC_NUM          1     //!< ADC1_SE16 ADC number
#define ADC1_SE16_ADC_CH           16    //!< ADC1_SE16 ADC channel
#define ADC1_SE16_ADC_FN           0     //!< ADC1_SE16 Pin multiplexor for ADC
#define ADC1_SE16_ADC_NUM_1         0     //!< ADC1_SE16 ADC number
#define ADC1_SE16_ADC_CH_1         22    //!< ADC1_SE16 ADC channel
#define ADC1_SE16_ADC_FN_1         0     //!< ADC1_SE16 Pin multiplexor for ADC

// ADC1_SE18 = ADC1_SE18
#define ADC1_SE18_ADC_NUM          1     //!< ADC1_SE18 ADC number
#define ADC1_SE18_ADC_CH           18    //!< ADC1_SE18 ADC channel
#define ADC1_SE18_ADC_FN           0     //!< ADC1_SE18 Pin multiplexor for ADC

// ADC1_SE23 = ADC1_SE23
#define ADC1_SE23_ADC_NUM          1     //!< ADC1_SE23 ADC number
#define ADC1_SE23_ADC_CH           23    //!< ADC1_SE23 ADC channel
#define ADC1_SE23_ADC_FN           0     //!< ADC1_SE23 Pin multiplexor for ADC

// PTA0 = GPIOA_0,FTM0_CH5 (Alias: D8)
#define PTA0_GPIO_NAME             A     //!< PTA0 GPIO name
#define PTA0_GPIO_BIT              0     //!< PTA0 GPIO bit number
#define PTA0_GPIO_FN               1     //!< PTA0 Pin multiplexor for GPIO
#if FTM0_CH5_SEL == 1
#define PTA0_FTM_NUM               0     //!< PTA0 FTM number
#define PTA0_FTM_CH                5     //!< PTA0 FTM channel
#define PTA0_FTM_FN                3     //!< PTA0 Pin multiplexor for FTM
#endif

// PTA1 = GPIOA_1,FTM0_CH6 (Alias: D3)
#define PTA1_GPIO_NAME             A     //!< PTA1 GPIO name
#define PTA1_GPIO_BIT              1     //!< PTA1 GPIO bit number
#define PTA1_GPIO_FN               1     //!< PTA1 Pin multiplexor for GPIO
#if FTM0_CH6_SEL == 1
#define PTA1_FTM_NUM               0     //!< PTA1 FTM number
#define PTA1_FTM_CH                6     //!< PTA1 FTM channel
#define PTA1_FTM_FN                3     //!< PTA1 Pin multiplexor for FTM
#endif

// PTA2 = GPIOA_2,FTM0_CH7 (Alias: D5)
#define PTA2_GPIO_NAME             A     //!< PTA2 GPIO name
#define PTA2_GPIO_BIT              2     //!< PTA2 GPIO bit number
#define PTA2_GPIO_FN               1     //!< PTA2 Pin multiplexor for GPIO
#if FTM0_CH7_SEL == 1
#define PTA2_FTM_NUM               0     //!< PTA2 FTM number
#define PTA2_FTM_CH                7     //!< PTA2 FTM channel
#define PTA2_FTM_FN                3     //!< PTA2 Pin multiplexor for FTM
#endif

// PTA3 = GPIOA_3,FTM0_CH0
#define PTA3_GPIO_NAME             A     //!< PTA3 GPIO name
#define PTA3_GPIO_BIT              3     //!< PTA3 GPIO bit number
#define PTA3_GPIO_FN               1     //!< PTA3 Pin multiplexor for GPIO
#if FTM0_CH0_SEL == 1
#define PTA3_FTM_NUM               0     //!< PTA3 FTM number
#define PTA3_FTM_CH                0     //!< PTA3 FTM channel
#define PTA3_FTM_FN                3     //!< PTA3 Pin multiplexor for FTM
#endif

// PTA4 = GPIOA_4,FTM0_CH1
#define PTA4_GPIO_NAME             A     //!< PTA4 GPIO name
#define PTA4_GPIO_BIT              4     //!< PTA4 GPIO bit number
#define PTA4_GPIO_FN               1     //!< PTA4 Pin multiplexor for GPIO
#if FTM0_CH1_SEL == 1
#define PTA4_FTM_NUM               0     //!< PTA4 FTM number
#define PTA4_FTM_CH                1     //!< PTA4 FTM channel
#define PTA4_FTM_FN                3     //!< PTA4 Pin multiplexor for FTM
#endif

// PTA5 = GPIOA_5,FTM0_CH2
#define PTA5_GPIO_NAME             A     //!< PTA5 GPIO name
#define PTA5_GPIO_BIT              5     //!< PTA5 GPIO bit number
#define PTA5_GPIO_FN               1     //!< PTA5 Pin multiplexor for GPIO
#if FTM0_CH2_SEL == 1
#define PTA5_FTM_NUM               0     //!< PTA5 FTM number
#define PTA5_FTM_CH                2     //!< PTA5 FTM channel
#define PTA5_FTM_FN                3     //!< PTA5 Pin multiplexor for FTM
#endif

// PTA6 = GPIOA_6,FTM0_CH3
#define PTA6_GPIO_NAME             A     //!< PTA6 GPIO name
#define PTA6_GPIO_BIT              6     //!< PTA6 GPIO bit number
#define PTA6_GPIO_FN               1     //!< PTA6 Pin multiplexor for GPIO
#if FTM0_CH3_SEL == 1
#define PTA6_FTM_NUM               0     //!< PTA6 FTM number
#define PTA6_FTM_CH                3     //!< PTA6 FTM channel
#define PTA6_FTM_FN                3     //!< PTA6 Pin multiplexor for FTM
#endif

// PTA7 = ADC0_SE10,GPIOA_7,FTM0_CH4
#define PTA7_GPIO_NAME             A     //!< PTA7 GPIO name
#define PTA7_GPIO_BIT              7     //!< PTA7 GPIO bit number
#define PTA7_GPIO_FN               1     //!< PTA7 Pin multiplexor for GPIO
#define PTA7_ADC_NUM               0     //!< PTA7 ADC number
#define PTA7_ADC_CH                10    //!< PTA7 ADC channel
#define PTA7_ADC_FN                0     //!< PTA7 Pin multiplexor for ADC
#if FTM0_CH4_SEL == 1
#define PTA7_FTM_NUM               0     //!< PTA7 FTM number
#define PTA7_FTM_CH                4     //!< PTA7 FTM channel
#define PTA7_FTM_FN                3     //!< PTA7 Pin multiplexor for FTM
#endif

// PTA8 = ADC0_SE11,GPIOA_8,FTM1_CH0
#define PTA8_GPIO_NAME             A     //!< PTA8 GPIO name
#define PTA8_GPIO_BIT              8     //!< PTA8 GPIO bit number
#define PTA8_GPIO_FN               1     //!< PTA8 Pin multiplexor for GPIO
#define PTA8_ADC_NUM               0     //!< PTA8 ADC number
#define PTA8_ADC_CH                11    //!< PTA8 ADC channel
#define PTA8_ADC_FN                0     //!< PTA8 Pin multiplexor for ADC
#if FTM1_CH0_SEL == 1
#define PTA8_FTM_NUM               1     //!< PTA8 FTM number
#define PTA8_FTM_CH                0     //!< PTA8 FTM channel
#define PTA8_FTM_FN                3     //!< PTA8 Pin multiplexor for FTM
#endif

// PTA9 = GPIOA_9,FTM1_CH1
#define PTA9_GPIO_NAME             A     //!< PTA9 GPIO name
#define PTA9_GPIO_BIT              9     //!< PTA9 GPIO bit number
#define PTA9_GPIO_FN               1     //!< PTA9 Pin multiplexor for GPIO
#if FTM1_CH1_SEL == 1
#define PTA9_FTM_NUM               1     //!< PTA9 FTM number
#define PTA9_FTM_CH                1     //!< PTA9 FTM channel
#define PTA9_FTM_FN                3     //!< PTA9 Pin multiplexor for FTM
#endif

// PTA10 = GPIOA_10,FTM2_CH0
#define PTA10_GPIO_NAME            A     //!< PTA10 GPIO name
#define PTA10_GPIO_BIT             10    //!< PTA10 GPIO bit number
#define PTA10_GPIO_FN              1     //!< PTA10 Pin multiplexor for GPIO
#if FTM2_CH0_SEL == 1
#define PTA10_FTM_NUM              2     //!< PTA10 FTM number
#define PTA10_FTM_CH               0     //!< PTA10 FTM channel
#define PTA10_FTM_FN               3     //!< PTA10 Pin multiplexor for FTM
#endif

// PTA11 = GPIOA_11,FTM2_CH1,I2C2_SDA
#define PTA11_GPIO_NAME            A     //!< PTA11 GPIO name
#define PTA11_GPIO_BIT             11    //!< PTA11 GPIO bit number
#define PTA11_GPIO_FN              1     //!< PTA11 Pin multiplexor for GPIO
#if FTM2_CH1_SEL == 1
#define PTA11_FTM_NUM              2     //!< PTA11 FTM number
#define PTA11_FTM_CH               1     //!< PTA11 FTM channel
#define PTA11_FTM_FN               3     //!< PTA11 Pin multiplexor for FTM
#endif
#if I2C2_SDA_SEL == 1
#define I2C2_SDA_FN                5     //!< PTA11 Pin multiplexor for I2C
#define I2C2_SDA_GPIO              digitalIO_PTA11   //!< PTA11 I2C GPIO
#endif

// PTA12 = GPIOA_12,FTM1_CH0,I2C2_SCL
#define PTA12_GPIO_NAME            A     //!< PTA12 GPIO name
#define PTA12_GPIO_BIT             12    //!< PTA12 GPIO bit number
#define PTA12_GPIO_FN              1     //!< PTA12 Pin multiplexor for GPIO
#if FTM1_CH0_SEL == 2
#define PTA12_FTM_NUM              1     //!< PTA12 FTM number
#define PTA12_FTM_CH               0     //!< PTA12 FTM channel
#define PTA12_FTM_FN               3     //!< PTA12 Pin multiplexor for FTM
#endif
#if I2C2_SCL_SEL == 1
#define I2C2_SCL_FN                5     //!< PTA12 Pin multiplexor for I2C
#define I2C2_SCL_GPIO              digitalIO_PTA12   //!< PTA12 I2C GPIO
#endif

// PTA13 = GPIOA_13,FTM1_CH1,I2C2_SDA
#define PTA13_GPIO_NAME            A     //!< PTA13 GPIO name
#define PTA13_GPIO_BIT             13    //!< PTA13 GPIO bit number
#define PTA13_GPIO_FN              1     //!< PTA13 Pin multiplexor for GPIO
#if FTM1_CH1_SEL == 2
#define PTA13_FTM_NUM              1     //!< PTA13 FTM number
#define PTA13_FTM_CH               1     //!< PTA13 FTM channel
#define PTA13_FTM_FN               3     //!< PTA13 Pin multiplexor for FTM
#endif
#if I2C2_SDA_SEL == 2
#define I2C2_SDA_FN                5     //!< PTA13 Pin multiplexor for I2C
#define I2C2_SDA_GPIO              digitalIO_PTA13   //!< PTA13 I2C GPIO
#endif

// PTA14 = GPIOA_14,SPI0_PCS0,I2C2_SCL
#define PTA14_GPIO_NAME            A     //!< PTA14 GPIO name
#define PTA14_GPIO_BIT             14    //!< PTA14 GPIO bit number
#define PTA14_GPIO_FN              1     //!< PTA14 Pin multiplexor for GPIO
#if SPI0_PCS0_SEL == 1
#define SPI0_PCS0_FN               2     //!< PTA14 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTA14   //!< PTA14 SPI GPIO
#endif
#if I2C2_SCL_SEL == 2
#define I2C2_SCL_FN                5     //!< PTA14 Pin multiplexor for I2C
#define I2C2_SCL_GPIO              digitalIO_PTA14   //!< PTA14 I2C GPIO
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

// PTA17 = ADC1_SE17,GPIOA_17,SPI0_SIN
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

// PTA19 = GPIOA_19,LPTMR0_ALT1
#define PTA19_GPIO_NAME            A     //!< PTA19 GPIO name
#define PTA19_GPIO_BIT             19    //!< PTA19 GPIO bit number
#define PTA19_GPIO_FN              1     //!< PTA19 Pin multiplexor for GPIO
#if LPTMR0_ALT1_SEL == 1
#define LPTMR0_ALT1_FN             6     //!< PTA19 Pin multiplexor for LPTMR
#define LPTMR0_ALT1_GPIO           digitalIO_PTA19   //!< PTA19 LPTMR GPIO
#endif

// PTA24 = GPIOA_24
#define PTA24_GPIO_NAME            A     //!< PTA24 GPIO name
#define PTA24_GPIO_BIT             24    //!< PTA24 GPIO bit number
#define PTA24_GPIO_FN              1     //!< PTA24 Pin multiplexor for GPIO

// PTA25 = GPIOA_25
#define PTA25_GPIO_NAME            A     //!< PTA25 GPIO name
#define PTA25_GPIO_BIT             25    //!< PTA25 GPIO bit number
#define PTA25_GPIO_FN              1     //!< PTA25 Pin multiplexor for GPIO

// PTA26 = GPIOA_26
#define PTA26_GPIO_NAME            A     //!< PTA26 GPIO name
#define PTA26_GPIO_BIT             26    //!< PTA26 GPIO bit number
#define PTA26_GPIO_FN              1     //!< PTA26 Pin multiplexor for GPIO

// PTA27 = GPIOA_27
#define PTA27_GPIO_NAME            A     //!< PTA27 GPIO name
#define PTA27_GPIO_BIT             27    //!< PTA27 GPIO bit number
#define PTA27_GPIO_FN              1     //!< PTA27 Pin multiplexor for GPIO

// PTA28 = GPIOA_28
#define PTA28_GPIO_NAME            A     //!< PTA28 GPIO name
#define PTA28_GPIO_BIT             28    //!< PTA28 GPIO bit number
#define PTA28_GPIO_FN              1     //!< PTA28 Pin multiplexor for GPIO

// PTA29 = GPIOA_29
#define PTA29_GPIO_NAME            A     //!< PTA29 GPIO name
#define PTA29_GPIO_BIT             29    //!< PTA29 GPIO bit number
#define PTA29_GPIO_FN              1     //!< PTA29 Pin multiplexor for GPIO

// PTB0 = ADC0_SE8,ADC1_SE8,GPIOB_0,I2C0_SCL,FTM1_CH0
#define PTB0_GPIO_NAME             B     //!< PTB0 GPIO name
#define PTB0_GPIO_BIT              0     //!< PTB0 GPIO bit number
#define PTB0_GPIO_FN               1     //!< PTB0 Pin multiplexor for GPIO
#define PTB0_ADC_NUM               0     //!< PTB0 ADC number
#define PTB0_ADC_CH                8     //!< PTB0 ADC channel
#define PTB0_ADC_FN                0     //!< PTB0 Pin multiplexor for ADC
#define PTB0_ADC_NUM_1             1     //!< PTB0 ADC number
#define PTB0_ADC_CH_1              8     //!< PTB0 ADC channel
#define PTB0_ADC_FN_1              0     //!< PTB0 Pin multiplexor for ADC
#if FTM1_CH0_SEL == 3
#define PTB0_FTM_NUM               1     //!< PTB0 FTM number
#define PTB0_FTM_CH                0     //!< PTB0 FTM channel
#define PTB0_FTM_FN                3     //!< PTB0 Pin multiplexor for FTM
#endif
#if I2C0_SCL_SEL == 1
#define I2C0_SCL_FN                2     //!< PTB0 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB0   //!< PTB0 I2C GPIO
#endif

// PTB1 = ADC0_SE9,ADC1_SE9,GPIOB_1,I2C0_SDA,FTM1_CH1
#define PTB1_GPIO_NAME             B     //!< PTB1 GPIO name
#define PTB1_GPIO_BIT              1     //!< PTB1 GPIO bit number
#define PTB1_GPIO_FN               1     //!< PTB1 Pin multiplexor for GPIO
#define PTB1_ADC_NUM               0     //!< PTB1 ADC number
#define PTB1_ADC_CH                9     //!< PTB1 ADC channel
#define PTB1_ADC_FN                0     //!< PTB1 Pin multiplexor for ADC
#define PTB1_ADC_NUM_1             1     //!< PTB1 ADC number
#define PTB1_ADC_CH_1              9     //!< PTB1 ADC channel
#define PTB1_ADC_FN_1              0     //!< PTB1 Pin multiplexor for ADC
#if FTM1_CH1_SEL == 3
#define PTB1_FTM_NUM               1     //!< PTB1 FTM number
#define PTB1_FTM_CH                1     //!< PTB1 FTM channel
#define PTB1_FTM_FN                3     //!< PTB1 Pin multiplexor for FTM
#endif
#if I2C0_SDA_SEL == 1
#define I2C0_SDA_FN                2     //!< PTB1 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB1   //!< PTB1 I2C GPIO
#endif

// PTB2 = ADC0_SE12,GPIOB_2,I2C0_SCL (Alias: A0)
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

// PTB3 = ADC0_SE13,GPIOB_3,I2C0_SDA (Alias: A1)
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

// PTB4 = ADC1_SE10,GPIOB_4
#define PTB4_GPIO_NAME             B     //!< PTB4 GPIO name
#define PTB4_GPIO_BIT              4     //!< PTB4 GPIO bit number
#define PTB4_GPIO_FN               1     //!< PTB4 Pin multiplexor for GPIO
#define PTB4_ADC_NUM               1     //!< PTB4 ADC number
#define PTB4_ADC_CH                10    //!< PTB4 ADC channel
#define PTB4_ADC_FN                0     //!< PTB4 Pin multiplexor for ADC

// PTB5 = ADC1_SE11,GPIOB_5
#define PTB5_GPIO_NAME             B     //!< PTB5 GPIO name
#define PTB5_GPIO_BIT              5     //!< PTB5 GPIO bit number
#define PTB5_GPIO_FN               1     //!< PTB5 Pin multiplexor for GPIO
#define PTB5_ADC_NUM               1     //!< PTB5 ADC number
#define PTB5_ADC_CH                11    //!< PTB5 ADC channel
#define PTB5_ADC_FN                0     //!< PTB5 Pin multiplexor for ADC

// PTB6 = ADC1_SE12,GPIOB_6
#define PTB6_GPIO_NAME             B     //!< PTB6 GPIO name
#define PTB6_GPIO_BIT              6     //!< PTB6 GPIO bit number
#define PTB6_GPIO_FN               1     //!< PTB6 Pin multiplexor for GPIO
#define PTB6_ADC_NUM               1     //!< PTB6 ADC number
#define PTB6_ADC_CH                12    //!< PTB6 ADC channel
#define PTB6_ADC_FN                0     //!< PTB6 Pin multiplexor for ADC

// PTB7 = ADC1_SE13,GPIOB_7
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

// PTB9 = GPIOB_9,SPI1_PCS1 (Alias: D2)
#define PTB9_GPIO_NAME             B     //!< PTB9 GPIO name
#define PTB9_GPIO_BIT              9     //!< PTB9 GPIO bit number
#define PTB9_GPIO_FN               1     //!< PTB9 Pin multiplexor for GPIO
#if SPI1_PCS1_SEL == 1
#define SPI1_PCS1_FN               2     //!< PTB9 Pin multiplexor for SPI
#define SPI1_PCS1_GPIO             digitalIO_PTB9   //!< PTB9 SPI GPIO
#endif

// PTB10 = ADC1_SE14,GPIOB_10,SPI1_PCS0 (Alias: A2)
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

// PTB11 = ADC1_SE15,GPIOB_11,SPI1_SCK (Alias: A3)
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

// PTB12 = GPIOB_12,FTM1_CH0,FTM0_CH4
#define PTB12_GPIO_NAME            B     //!< PTB12 GPIO name
#define PTB12_GPIO_BIT             12    //!< PTB12 GPIO bit number
#define PTB12_GPIO_FN              1     //!< PTB12 Pin multiplexor for GPIO
#if FTM1_CH0_SEL == 4
#define PTB12_FTM_NUM              1     //!< PTB12 FTM number
#define PTB12_FTM_CH               0     //!< PTB12 FTM channel
#define PTB12_FTM_FN               3     //!< PTB12 Pin multiplexor for FTM
#endif
#if FTM0_CH4_SEL == 2
#define PTB12_FTM_NUM              0     //!< PTB12 FTM number
#define PTB12_FTM_CH               4     //!< PTB12 FTM channel
#define PTB12_FTM_FN               4     //!< PTB12 Pin multiplexor for FTM
#endif

// PTB13 = GPIOB_13,FTM1_CH1,FTM0_CH5
#define PTB13_GPIO_NAME            B     //!< PTB13 GPIO name
#define PTB13_GPIO_BIT             13    //!< PTB13 GPIO bit number
#define PTB13_GPIO_FN              1     //!< PTB13 Pin multiplexor for GPIO
#if FTM1_CH1_SEL == 4
#define PTB13_FTM_NUM              1     //!< PTB13 FTM number
#define PTB13_FTM_CH               1     //!< PTB13 FTM channel
#define PTB13_FTM_FN               3     //!< PTB13 Pin multiplexor for FTM
#endif
#if FTM0_CH5_SEL == 2
#define PTB13_FTM_NUM              0     //!< PTB13 FTM number
#define PTB13_FTM_CH               5     //!< PTB13 FTM channel
#define PTB13_FTM_FN               4     //!< PTB13 Pin multiplexor for FTM
#endif

// PTB16 = GPIOB_16,SPI1_SOUT
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

// PTB18 = GPIOB_18,FTM2_CH0
#define PTB18_GPIO_NAME            B     //!< PTB18 GPIO name
#define PTB18_GPIO_BIT             18    //!< PTB18 GPIO bit number
#define PTB18_GPIO_FN              1     //!< PTB18 Pin multiplexor for GPIO
#if FTM2_CH0_SEL == 2
#define PTB18_FTM_NUM              2     //!< PTB18 FTM number
#define PTB18_FTM_CH               0     //!< PTB18 FTM channel
#define PTB18_FTM_FN               3     //!< PTB18 Pin multiplexor for FTM
#endif

// PTB19 = GPIOB_19,FTM2_CH1
#define PTB19_GPIO_NAME            B     //!< PTB19 GPIO name
#define PTB19_GPIO_BIT             19    //!< PTB19 GPIO bit number
#define PTB19_GPIO_FN              1     //!< PTB19 Pin multiplexor for GPIO
#if FTM2_CH1_SEL == 2
#define PTB19_FTM_NUM              2     //!< PTB19 FTM number
#define PTB19_FTM_CH               1     //!< PTB19 FTM channel
#define PTB19_FTM_FN               3     //!< PTB19 Pin multiplexor for FTM
#endif

// PTB20 = GPIOB_20,SPI2_PCS0
#define PTB20_GPIO_NAME            B     //!< PTB20 GPIO name
#define PTB20_GPIO_BIT             20    //!< PTB20 GPIO bit number
#define PTB20_GPIO_FN              1     //!< PTB20 Pin multiplexor for GPIO
#if SPI2_PCS0_SEL == 1
#define SPI2_PCS0_FN               2     //!< PTB20 Pin multiplexor for SPI
#define SPI2_PCS0_GPIO             digitalIO_PTB20   //!< PTB20 SPI GPIO
#endif

// PTB21 = GPIOB_21,SPI2_SCK
#define PTB21_GPIO_NAME            B     //!< PTB21 GPIO name
#define PTB21_GPIO_BIT             21    //!< PTB21 GPIO bit number
#define PTB21_GPIO_FN              1     //!< PTB21 Pin multiplexor for GPIO
#if SPI2_SCK_SEL == 1
#define SPI2_SCK_FN                2     //!< PTB21 Pin multiplexor for SPI
#define SPI2_SCK_GPIO              digitalIO_PTB21   //!< PTB21 SPI GPIO
#endif

// PTB22 = GPIOB_22,SPI2_SOUT
#define PTB22_GPIO_NAME            B     //!< PTB22 GPIO name
#define PTB22_GPIO_BIT             22    //!< PTB22 GPIO bit number
#define PTB22_GPIO_FN              1     //!< PTB22 Pin multiplexor for GPIO
#if SPI2_SOUT_SEL == 1
#define SPI2_SOUT_FN               2     //!< PTB22 Pin multiplexor for SPI
#define SPI2_SOUT_GPIO             digitalIO_PTB22   //!< PTB22 SPI GPIO
#endif

// PTB23 = GPIOB_23,SPI2_SIN,SPI0_PCS5 (Alias: D4)
#define PTB23_GPIO_NAME            B     //!< PTB23 GPIO name
#define PTB23_GPIO_BIT             23    //!< PTB23 GPIO bit number
#define PTB23_GPIO_FN              1     //!< PTB23 Pin multiplexor for GPIO
#if SPI2_SIN_SEL == 1
#define SPI2_SIN_FN                2     //!< PTB23 Pin multiplexor for SPI
#define SPI2_SIN_GPIO              digitalIO_PTB23   //!< PTB23 SPI GPIO
#endif
#if SPI0_PCS5_SEL == 1
#define SPI0_PCS5_FN               3     //!< PTB23 Pin multiplexor for SPI
#define SPI0_PCS5_GPIO             digitalIO_PTB23   //!< PTB23 SPI GPIO
#endif

// PTC0 = ADC0_SE14,GPIOC_0,SPI0_PCS4
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

// PTC1 = ADC0_SE15,GPIOC_1,SPI0_PCS3,FTM0_CH0
#define PTC1_GPIO_NAME             C     //!< PTC1 GPIO name
#define PTC1_GPIO_BIT              1     //!< PTC1 GPIO bit number
#define PTC1_GPIO_FN               1     //!< PTC1 Pin multiplexor for GPIO
#define PTC1_ADC_NUM               0     //!< PTC1 ADC number
#define PTC1_ADC_CH                15    //!< PTC1 ADC channel
#define PTC1_ADC_FN                0     //!< PTC1 Pin multiplexor for ADC
#if FTM0_CH0_SEL == 2
#define PTC1_FTM_NUM               0     //!< PTC1 FTM number
#define PTC1_FTM_CH                0     //!< PTC1 FTM channel
#define PTC1_FTM_FN                4     //!< PTC1 Pin multiplexor for FTM
#endif
#if SPI0_PCS3_SEL == 1
#define SPI0_PCS3_FN               2     //!< PTC1 Pin multiplexor for SPI
#define SPI0_PCS3_GPIO             digitalIO_PTC1   //!< PTC1 SPI GPIO
#endif

// PTC2 = ADC0_SE4b,GPIOC_2,SPI0_PCS2,FTM0_CH1 (Alias: D6)
#define PTC2_GPIO_NAME             C     //!< PTC2 GPIO name
#define PTC2_GPIO_BIT              2     //!< PTC2 GPIO bit number
#define PTC2_GPIO_FN               1     //!< PTC2 Pin multiplexor for GPIO
#define PTC2_ADC_NUM               0     //!< PTC2 ADC number
#define PTC2_ADC_CH                4     //!< PTC2 ADC channel
#define PTC2_ADC_FN                0     //!< PTC2 Pin multiplexor for ADC
#if FTM0_CH1_SEL == 2
#define PTC2_FTM_NUM               0     //!< PTC2 FTM number
#define PTC2_FTM_CH                1     //!< PTC2 FTM channel
#define PTC2_FTM_FN                4     //!< PTC2 Pin multiplexor for FTM
#endif
#if SPI0_PCS2_SEL == 1
#define SPI0_PCS2_FN               2     //!< PTC2 Pin multiplexor for SPI
#define SPI0_PCS2_GPIO             digitalIO_PTC2   //!< PTC2 SPI GPIO
#endif

// PTC3 = GPIOC_3,SPI0_PCS1,FTM0_CH2 (Alias: D7)
#define PTC3_GPIO_NAME             C     //!< PTC3 GPIO name
#define PTC3_GPIO_BIT              3     //!< PTC3 GPIO bit number
#define PTC3_GPIO_FN               1     //!< PTC3 Pin multiplexor for GPIO
#if FTM0_CH2_SEL == 2
#define PTC3_FTM_NUM               0     //!< PTC3 FTM number
#define PTC3_FTM_CH                2     //!< PTC3 FTM channel
#define PTC3_FTM_FN                4     //!< PTC3 Pin multiplexor for FTM
#endif
#if SPI0_PCS1_SEL == 1
#define SPI0_PCS1_FN               2     //!< PTC3 Pin multiplexor for SPI
#define SPI0_PCS1_GPIO             digitalIO_PTC3   //!< PTC3 SPI GPIO
#endif

// PTC4 = GPIOC_4,SPI0_PCS0,FTM0_CH3 (Alias: D9)
#define PTC4_GPIO_NAME             C     //!< PTC4 GPIO name
#define PTC4_GPIO_BIT              4     //!< PTC4 GPIO bit number
#define PTC4_GPIO_FN               1     //!< PTC4 Pin multiplexor for GPIO
#if FTM0_CH3_SEL == 2
#define PTC4_FTM_NUM               0     //!< PTC4 FTM number
#define PTC4_FTM_CH                3     //!< PTC4 FTM channel
#define PTC4_FTM_FN                4     //!< PTC4 Pin multiplexor for FTM
#endif
#if SPI0_PCS0_SEL == 2
#define SPI0_PCS0_FN               2     //!< PTC4 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTC4   //!< PTC4 SPI GPIO
#endif

// PTC5 = GPIOC_5,SPI0_SCK,LPTMR0_ALT2,FTM0_CH2
#define PTC5_GPIO_NAME             C     //!< PTC5 GPIO name
#define PTC5_GPIO_BIT              5     //!< PTC5 GPIO bit number
#define PTC5_GPIO_FN               1     //!< PTC5 Pin multiplexor for GPIO
#if FTM0_CH2_SEL == 3
#define PTC5_FTM_NUM               0     //!< PTC5 FTM number
#define PTC5_FTM_CH                2     //!< PTC5 FTM channel
#define PTC5_FTM_FN                7     //!< PTC5 Pin multiplexor for FTM
#endif
#if LPTMR0_ALT2_SEL == 1
#define LPTMR0_ALT2_FN             3     //!< PTC5 Pin multiplexor for LPTMR
#define LPTMR0_ALT2_GPIO           digitalIO_PTC5   //!< PTC5 LPTMR GPIO
#endif
#if SPI0_SCK_SEL == 2
#define SPI0_SCK_FN                2     //!< PTC5 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTC5   //!< PTC5 SPI GPIO
#endif

// PTC6 = GPIOC_6,SPI0_SOUT
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

// PTC8 = ADC1_SE4b,GPIOC_8,FTM3_CH4
#define PTC8_GPIO_NAME             C     //!< PTC8 GPIO name
#define PTC8_GPIO_BIT              8     //!< PTC8 GPIO bit number
#define PTC8_GPIO_FN               1     //!< PTC8 Pin multiplexor for GPIO
#define PTC8_ADC_NUM               1     //!< PTC8 ADC number
#define PTC8_ADC_CH                4     //!< PTC8 ADC channel
#define PTC8_ADC_FN                0     //!< PTC8 Pin multiplexor for ADC
#if FTM3_CH4_SEL == 1
#define PTC8_FTM_NUM               3     //!< PTC8 FTM number
#define PTC8_FTM_CH                4     //!< PTC8 FTM channel
#define PTC8_FTM_FN                3     //!< PTC8 Pin multiplexor for FTM
#endif

// PTC9 = ADC1_SE5b,GPIOC_9,FTM3_CH5
#define PTC9_GPIO_NAME             C     //!< PTC9 GPIO name
#define PTC9_GPIO_BIT              9     //!< PTC9 GPIO bit number
#define PTC9_GPIO_FN               1     //!< PTC9 Pin multiplexor for GPIO
#define PTC9_ADC_NUM               1     //!< PTC9 ADC number
#define PTC9_ADC_CH                5     //!< PTC9 ADC channel
#define PTC9_ADC_FN                0     //!< PTC9 Pin multiplexor for ADC
#if FTM3_CH5_SEL == 1
#define PTC9_FTM_NUM               3     //!< PTC9 FTM number
#define PTC9_FTM_CH                5     //!< PTC9 FTM channel
#define PTC9_FTM_FN                3     //!< PTC9 Pin multiplexor for FTM
#endif

// PTC10 = ADC1_SE6b,GPIOC_10,I2C1_SCL,FTM3_CH6 (Alias: A5)
#define PTC10_GPIO_NAME            C     //!< PTC10 GPIO name
#define PTC10_GPIO_BIT             10    //!< PTC10 GPIO bit number
#define PTC10_GPIO_FN              1     //!< PTC10 Pin multiplexor for GPIO
#define PTC10_ADC_NUM              1     //!< PTC10 ADC number
#define PTC10_ADC_CH               6     //!< PTC10 ADC channel
#define PTC10_ADC_FN               0     //!< PTC10 Pin multiplexor for ADC
#if FTM3_CH6_SEL == 1
#define PTC10_FTM_NUM              3     //!< PTC10 FTM number
#define PTC10_FTM_CH               6     //!< PTC10 FTM channel
#define PTC10_FTM_FN               3     //!< PTC10 Pin multiplexor for FTM
#endif
#if I2C1_SCL_SEL == 1
#define I2C1_SCL_FN                2     //!< PTC10 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTC10   //!< PTC10 I2C GPIO
#endif

// PTC11 = ADC1_SE7b,GPIOC_11,I2C1_SDA,FTM3_CH7 (Alias: A4)
#define PTC11_GPIO_NAME            C     //!< PTC11 GPIO name
#define PTC11_GPIO_BIT             11    //!< PTC11 GPIO bit number
#define PTC11_GPIO_FN              1     //!< PTC11 Pin multiplexor for GPIO
#define PTC11_ADC_NUM              1     //!< PTC11 ADC number
#define PTC11_ADC_CH               7     //!< PTC11 ADC channel
#define PTC11_ADC_FN               0     //!< PTC11 Pin multiplexor for ADC
#if FTM3_CH7_SEL == 1
#define PTC11_FTM_NUM              3     //!< PTC11 FTM number
#define PTC11_FTM_CH               7     //!< PTC11 FTM channel
#define PTC11_FTM_FN               3     //!< PTC11 Pin multiplexor for FTM
#endif
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

// PTC16 = GPIOC_16 (Alias: D0)
#define PTC16_GPIO_NAME            C     //!< PTC16 GPIO name
#define PTC16_GPIO_BIT             16    //!< PTC16 GPIO bit number
#define PTC16_GPIO_FN              1     //!< PTC16 Pin multiplexor for GPIO

// PTC17 = GPIOC_17 (Alias: D1)
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

// PTD0 = GPIOD_0,SPI0_PCS0,FTM3_CH0 (Alias: D10)
#define PTD0_GPIO_NAME             D     //!< PTD0 GPIO name
#define PTD0_GPIO_BIT              0     //!< PTD0 GPIO bit number
#define PTD0_GPIO_FN               1     //!< PTD0 Pin multiplexor for GPIO
#if FTM3_CH0_SEL == 1
#define PTD0_FTM_NUM               3     //!< PTD0 FTM number
#define PTD0_FTM_CH                0     //!< PTD0 FTM channel
#define PTD0_FTM_FN                4     //!< PTD0 Pin multiplexor for FTM
#endif
#if SPI0_PCS0_SEL == 3
#define SPI0_PCS0_FN               2     //!< PTD0 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTD0   //!< PTD0 SPI GPIO
#endif

// PTD1 = ADC0_SE5b,GPIOD_1,SPI0_SCK,FTM3_CH1 (Alias: D13)
#define PTD1_GPIO_NAME             D     //!< PTD1 GPIO name
#define PTD1_GPIO_BIT              1     //!< PTD1 GPIO bit number
#define PTD1_GPIO_FN               1     //!< PTD1 Pin multiplexor for GPIO
#define PTD1_ADC_NUM               0     //!< PTD1 ADC number
#define PTD1_ADC_CH                5     //!< PTD1 ADC channel
#define PTD1_ADC_FN                0     //!< PTD1 Pin multiplexor for ADC
#if FTM3_CH1_SEL == 1
#define PTD1_FTM_NUM               3     //!< PTD1 FTM number
#define PTD1_FTM_CH                1     //!< PTD1 FTM channel
#define PTD1_FTM_FN                4     //!< PTD1 Pin multiplexor for FTM
#endif
#if SPI0_SCK_SEL == 3
#define SPI0_SCK_FN                2     //!< PTD1 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTD1   //!< PTD1 SPI GPIO
#endif

// PTD2 = GPIOD_2,SPI0_SOUT,FTM3_CH2,I2C0_SCL (Alias: D11)
#define PTD2_GPIO_NAME             D     //!< PTD2 GPIO name
#define PTD2_GPIO_BIT              2     //!< PTD2 GPIO bit number
#define PTD2_GPIO_FN               1     //!< PTD2 Pin multiplexor for GPIO
#if FTM3_CH2_SEL == 1
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

// PTD3 = GPIOD_3,SPI0_SIN,FTM3_CH3,I2C0_SDA (Alias: D12)
#define PTD3_GPIO_NAME             D     //!< PTD3 GPIO name
#define PTD3_GPIO_BIT              3     //!< PTD3 GPIO bit number
#define PTD3_GPIO_FN               1     //!< PTD3 Pin multiplexor for GPIO
#if FTM3_CH3_SEL == 1
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

// PTD4 = GPIOD_4,SPI0_PCS1,FTM0_CH4,SPI1_PCS0 (Alias: nRF24L01_cs)
#define PTD4_GPIO_NAME             D     //!< PTD4 GPIO name
#define PTD4_GPIO_BIT              4     //!< PTD4 GPIO bit number
#define PTD4_GPIO_FN               1     //!< PTD4 Pin multiplexor for GPIO
#if FTM0_CH4_SEL == 3
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

// PTD5 = ADC0_SE6b,GPIOD_5,SPI0_PCS2,FTM0_CH5,SPI1_SCK (Alias: nRF24L01_sck)
#define PTD5_GPIO_NAME             D     //!< PTD5 GPIO name
#define PTD5_GPIO_BIT              5     //!< PTD5 GPIO bit number
#define PTD5_GPIO_FN               1     //!< PTD5 Pin multiplexor for GPIO
#define PTD5_ADC_NUM               0     //!< PTD5 ADC number
#define PTD5_ADC_CH                6     //!< PTD5 ADC channel
#define PTD5_ADC_FN                0     //!< PTD5 Pin multiplexor for ADC
#if FTM0_CH5_SEL == 3
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

// PTD6 = ADC0_SE7b,GPIOD_6,SPI0_PCS3,FTM0_CH6,SPI1_SOUT (Alias: nRF24L01_mosi)
#define PTD6_GPIO_NAME             D     //!< PTD6 GPIO name
#define PTD6_GPIO_BIT              6     //!< PTD6 GPIO bit number
#define PTD6_GPIO_FN               1     //!< PTD6 Pin multiplexor for GPIO
#define PTD6_ADC_NUM               0     //!< PTD6 ADC number
#define PTD6_ADC_CH                7     //!< PTD6 ADC channel
#define PTD6_ADC_FN                0     //!< PTD6 Pin multiplexor for ADC
#if FTM0_CH6_SEL == 2
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

// PTD7 = GPIOD_7,FTM0_CH7,SPI1_SIN (Alias: nRF24L01_miso)
#define PTD7_GPIO_NAME             D     //!< PTD7 GPIO name
#define PTD7_GPIO_BIT              7     //!< PTD7 GPIO bit number
#define PTD7_GPIO_FN               1     //!< PTD7 Pin multiplexor for GPIO
#if FTM0_CH7_SEL == 2
#define PTD7_FTM_NUM               0     //!< PTD7 FTM number
#define PTD7_FTM_CH                7     //!< PTD7 FTM channel
#define PTD7_FTM_FN                4     //!< PTD7 Pin multiplexor for FTM
#endif
#if SPI1_SIN_SEL == 2
#define SPI1_SIN_FN                7     //!< PTD7 Pin multiplexor for SPI
#define SPI1_SIN_GPIO              digitalIO_PTD7   //!< PTD7 SPI GPIO
#endif

// PTD8 = GPIOD_8,I2C0_SCL
#define PTD8_GPIO_NAME             D     //!< PTD8 GPIO name
#define PTD8_GPIO_BIT              8     //!< PTD8 GPIO bit number
#define PTD8_GPIO_FN               1     //!< PTD8 Pin multiplexor for GPIO
#if I2C0_SCL_SEL == 4
#define I2C0_SCL_FN                2     //!< PTD8 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTD8   //!< PTD8 I2C GPIO
#endif

// PTD9 = GPIOD_9,I2C0_SDA
#define PTD9_GPIO_NAME             D     //!< PTD9 GPIO name
#define PTD9_GPIO_BIT              9     //!< PTD9 GPIO bit number
#define PTD9_GPIO_FN               1     //!< PTD9 Pin multiplexor for GPIO
#if I2C0_SDA_SEL == 4
#define I2C0_SDA_FN                2     //!< PTD9 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTD9   //!< PTD9 I2C GPIO
#endif

// PTD10 = GPIOD_10
#define PTD10_GPIO_NAME            D     //!< PTD10 GPIO name
#define PTD10_GPIO_BIT             10    //!< PTD10 GPIO bit number
#define PTD10_GPIO_FN              1     //!< PTD10 Pin multiplexor for GPIO

// PTD11 = GPIOD_11,SPI2_PCS0,SDHC0_CLKIN
#define PTD11_GPIO_NAME            D     //!< PTD11 GPIO name
#define PTD11_GPIO_BIT             11    //!< PTD11 GPIO bit number
#define PTD11_GPIO_FN              1     //!< PTD11 Pin multiplexor for GPIO
#if SPI2_PCS0_SEL == 2
#define SPI2_PCS0_FN               2     //!< PTD11 Pin multiplexor for SPI
#define SPI2_PCS0_GPIO             digitalIO_PTD11   //!< PTD11 SPI GPIO
#endif
#if SDHC0_CLKIN_SEL == 1
#define SDHC0_CLKIN_FN             4     //!< PTD11 Pin multiplexor for SDHC
#define SDHC0_CLKIN_GPIO           digitalIO_PTD11   //!< PTD11 SDHC GPIO
#endif

// PTD12 = GPIOD_12,SPI2_SCK,SDHC0_D4
#define PTD12_GPIO_NAME            D     //!< PTD12 GPIO name
#define PTD12_GPIO_BIT             12    //!< PTD12 GPIO bit number
#define PTD12_GPIO_FN              1     //!< PTD12 Pin multiplexor for GPIO
#if SPI2_SCK_SEL == 2
#define SPI2_SCK_FN                2     //!< PTD12 Pin multiplexor for SPI
#define SPI2_SCK_GPIO              digitalIO_PTD12   //!< PTD12 SPI GPIO
#endif
#if SDHC0_D4_SEL == 1
#define SDHC0_D4_FN                4     //!< PTD12 Pin multiplexor for SDHC
#define SDHC0_D4_GPIO              digitalIO_PTD12   //!< PTD12 SDHC GPIO
#endif

// PTD13 = GPIOD_13,SPI2_SOUT,SDHC0_D5
#define PTD13_GPIO_NAME            D     //!< PTD13 GPIO name
#define PTD13_GPIO_BIT             13    //!< PTD13 GPIO bit number
#define PTD13_GPIO_FN              1     //!< PTD13 Pin multiplexor for GPIO
#if SPI2_SOUT_SEL == 2
#define SPI2_SOUT_FN               2     //!< PTD13 Pin multiplexor for SPI
#define SPI2_SOUT_GPIO             digitalIO_PTD13   //!< PTD13 SPI GPIO
#endif
#if SDHC0_D5_SEL == 1
#define SDHC0_D5_FN                4     //!< PTD13 Pin multiplexor for SDHC
#define SDHC0_D5_GPIO              digitalIO_PTD13   //!< PTD13 SDHC GPIO
#endif

// PTD14 = GPIOD_14,SPI2_SIN,SDHC0_D6
#define PTD14_GPIO_NAME            D     //!< PTD14 GPIO name
#define PTD14_GPIO_BIT             14    //!< PTD14 GPIO bit number
#define PTD14_GPIO_FN              1     //!< PTD14 Pin multiplexor for GPIO
#if SPI2_SIN_SEL == 2
#define SPI2_SIN_FN                2     //!< PTD14 Pin multiplexor for SPI
#define SPI2_SIN_GPIO              digitalIO_PTD14   //!< PTD14 SPI GPIO
#endif
#if SDHC0_D6_SEL == 1
#define SDHC0_D6_FN                4     //!< PTD14 Pin multiplexor for SDHC
#define SDHC0_D6_GPIO              digitalIO_PTD14   //!< PTD14 SDHC GPIO
#endif

// PTD15 = GPIOD_15,SPI2_PCS1,SDHC0_D7
#define PTD15_GPIO_NAME            D     //!< PTD15 GPIO name
#define PTD15_GPIO_BIT             15    //!< PTD15 GPIO bit number
#define PTD15_GPIO_FN              1     //!< PTD15 Pin multiplexor for GPIO
#if SPI2_PCS1_SEL == 1
#define SPI2_PCS1_FN               2     //!< PTD15 Pin multiplexor for SPI
#define SPI2_PCS1_GPIO             digitalIO_PTD15   //!< PTD15 SPI GPIO
#endif
#if SDHC0_D7_SEL == 1
#define SDHC0_D7_FN                4     //!< PTD15 Pin multiplexor for SDHC
#define SDHC0_D7_GPIO              digitalIO_PTD15   //!< PTD15 SDHC GPIO
#endif

// PTE0 = ADC1_SE4a,GPIOE_0,SPI1_PCS1,SDHC0_D1,I2C1_SDA
#define PTE0_GPIO_NAME             E     //!< PTE0 GPIO name
#define PTE0_GPIO_BIT              0     //!< PTE0 GPIO bit number
#define PTE0_GPIO_FN               1     //!< PTE0 Pin multiplexor for GPIO
#define PTE0_ADC_NUM               1     //!< PTE0 ADC number
#define PTE0_ADC_CH                4     //!< PTE0 ADC channel
#define PTE0_ADC_FN                0     //!< PTE0 Pin multiplexor for ADC
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

// PTE1 = ADC1_SE5a,GPIOE_1,SPI1_SOUT,SDHC0_D0,I2C1_SCL,SPI1_SIN
#define PTE1_GPIO_NAME             E     //!< PTE1 GPIO name
#define PTE1_GPIO_BIT              1     //!< PTE1 GPIO bit number
#define PTE1_GPIO_FN               1     //!< PTE1 Pin multiplexor for GPIO
#define PTE1_ADC_NUM               1     //!< PTE1 ADC number
#define PTE1_ADC_CH                5     //!< PTE1 ADC channel
#define PTE1_ADC_FN                0     //!< PTE1 Pin multiplexor for ADC
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

// PTE2 = ADC0_DP2,ADC1_SE6a,GPIOE_2,SPI1_SCK,SDHC0_DCLK
#define PTE2_GPIO_NAME             E     //!< PTE2 GPIO name
#define PTE2_GPIO_BIT              2     //!< PTE2 GPIO bit number
#define PTE2_GPIO_FN               1     //!< PTE2 Pin multiplexor for GPIO
#define PTE2_ADC_NUM               0     //!< PTE2 ADC number
#define PTE2_ADC_CH                2     //!< PTE2 ADC channel
#define PTE2_ADC_FN                0     //!< PTE2 Pin multiplexor for ADC
#define PTE2_ADC_NUM_1             1     //!< PTE2 ADC number
#define PTE2_ADC_CH_1              6     //!< PTE2 ADC channel
#define PTE2_ADC_FN_1              0     //!< PTE2 Pin multiplexor for ADC
#if SPI1_SCK_SEL == 3
#define SPI1_SCK_FN                2     //!< PTE2 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTE2   //!< PTE2 SPI GPIO
#endif
#if SDHC0_DCLK_SEL == 1
#define SDHC0_DCLK_FN              4     //!< PTE2 Pin multiplexor for SDHC
#define SDHC0_DCLK_GPIO            digitalIO_PTE2   //!< PTE2 SDHC GPIO
#endif

// PTE3 = ADC0_DM2,ADC1_SE7a,GPIOE_3,SPI1_SIN,SDHC0_CMD,SPI1_SOUT
#define PTE3_GPIO_NAME             E     //!< PTE3 GPIO name
#define PTE3_GPIO_BIT              3     //!< PTE3 GPIO bit number
#define PTE3_GPIO_FN               1     //!< PTE3 Pin multiplexor for GPIO
#define PTE3_ADC_NUM               0     //!< PTE3 ADC number
#define PTE3_ADC_CH                2     //!< PTE3 ADC channel
#define PTE3_ADC_FN                0     //!< PTE3 Pin multiplexor for ADC
#define PTE3_ADC_NUM_1             1     //!< PTE3 ADC number
#define PTE3_ADC_CH_1              7     //!< PTE3 ADC channel
#define PTE3_ADC_FN_1              0     //!< PTE3 Pin multiplexor for ADC
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

// PTE4 = GPIOE_4,SPI1_PCS0,SDHC0_D3
#define PTE4_GPIO_NAME             E     //!< PTE4 GPIO name
#define PTE4_GPIO_BIT              4     //!< PTE4 GPIO bit number
#define PTE4_GPIO_FN               1     //!< PTE4 Pin multiplexor for GPIO
#if SPI1_PCS0_SEL == 3
#define SPI1_PCS0_FN               2     //!< PTE4 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTE4   //!< PTE4 SPI GPIO
#endif
#if SDHC0_D3_SEL == 1
#define SDHC0_D3_FN                4     //!< PTE4 Pin multiplexor for SDHC
#define SDHC0_D3_GPIO              digitalIO_PTE4   //!< PTE4 SDHC GPIO
#endif

// PTE5 = GPIOE_5,SPI1_PCS2,SDHC0_D2,FTM3_CH0
#define PTE5_GPIO_NAME             E     //!< PTE5 GPIO name
#define PTE5_GPIO_BIT              5     //!< PTE5 GPIO bit number
#define PTE5_GPIO_FN               1     //!< PTE5 Pin multiplexor for GPIO
#if FTM3_CH0_SEL == 2
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

// PTE6 = GPIOE_6,SPI1_PCS3,FTM3_CH1
#define PTE6_GPIO_NAME             E     //!< PTE6 GPIO name
#define PTE6_GPIO_BIT              6     //!< PTE6 GPIO bit number
#define PTE6_GPIO_FN               1     //!< PTE6 Pin multiplexor for GPIO
#if FTM3_CH1_SEL == 2
#define PTE6_FTM_NUM               3     //!< PTE6 FTM number
#define PTE6_FTM_CH                1     //!< PTE6 FTM channel
#define PTE6_FTM_FN                6     //!< PTE6 Pin multiplexor for FTM
#endif
#if SPI1_PCS3_SEL == 1
#define SPI1_PCS3_FN               2     //!< PTE6 Pin multiplexor for SPI
#define SPI1_PCS3_GPIO             digitalIO_PTE6   //!< PTE6 SPI GPIO
#endif

// PTE7 = GPIOE_7,FTM3_CH2
#define PTE7_GPIO_NAME             E     //!< PTE7 GPIO name
#define PTE7_GPIO_BIT              7     //!< PTE7 GPIO bit number
#define PTE7_GPIO_FN               1     //!< PTE7 Pin multiplexor for GPIO
#if FTM3_CH2_SEL == 2
#define PTE7_FTM_NUM               3     //!< PTE7 FTM number
#define PTE7_FTM_CH                2     //!< PTE7 FTM channel
#define PTE7_FTM_FN                6     //!< PTE7 Pin multiplexor for FTM
#endif

// PTE8 = GPIOE_8,FTM3_CH3
#define PTE8_GPIO_NAME             E     //!< PTE8 GPIO name
#define PTE8_GPIO_BIT              8     //!< PTE8 GPIO bit number
#define PTE8_GPIO_FN               1     //!< PTE8 Pin multiplexor for GPIO
#if FTM3_CH3_SEL == 2
#define PTE8_FTM_NUM               3     //!< PTE8 FTM number
#define PTE8_FTM_CH                3     //!< PTE8 FTM channel
#define PTE8_FTM_FN                6     //!< PTE8 Pin multiplexor for FTM
#endif

// PTE9 = GPIOE_9,FTM3_CH4
#define PTE9_GPIO_NAME             E     //!< PTE9 GPIO name
#define PTE9_GPIO_BIT              9     //!< PTE9 GPIO bit number
#define PTE9_GPIO_FN               1     //!< PTE9 Pin multiplexor for GPIO
#if FTM3_CH4_SEL == 2
#define PTE9_FTM_NUM               3     //!< PTE9 FTM number
#define PTE9_FTM_CH                4     //!< PTE9 FTM channel
#define PTE9_FTM_FN                6     //!< PTE9 Pin multiplexor for FTM
#endif

// PTE10 = GPIOE_10,FTM3_CH5
#define PTE10_GPIO_NAME            E     //!< PTE10 GPIO name
#define PTE10_GPIO_BIT             10    //!< PTE10 GPIO bit number
#define PTE10_GPIO_FN              1     //!< PTE10 Pin multiplexor for GPIO
#if FTM3_CH5_SEL == 2
#define PTE10_FTM_NUM              3     //!< PTE10 FTM number
#define PTE10_FTM_CH               5     //!< PTE10 FTM channel
#define PTE10_FTM_FN               6     //!< PTE10 Pin multiplexor for FTM
#endif

// PTE11 = GPIOE_11,FTM3_CH6
#define PTE11_GPIO_NAME            E     //!< PTE11 GPIO name
#define PTE11_GPIO_BIT             11    //!< PTE11 GPIO bit number
#define PTE11_GPIO_FN              1     //!< PTE11 Pin multiplexor for GPIO
#if FTM3_CH6_SEL == 2
#define PTE11_FTM_NUM              3     //!< PTE11 FTM number
#define PTE11_FTM_CH               6     //!< PTE11 FTM channel
#define PTE11_FTM_FN               6     //!< PTE11 Pin multiplexor for FTM
#endif

// PTE12 = GPIOE_12,FTM3_CH7
#define PTE12_GPIO_NAME            E     //!< PTE12 GPIO name
#define PTE12_GPIO_BIT             12    //!< PTE12 GPIO bit number
#define PTE12_GPIO_FN              1     //!< PTE12 Pin multiplexor for GPIO
#if FTM3_CH7_SEL == 2
#define PTE12_FTM_NUM              3     //!< PTE12 FTM number
#define PTE12_FTM_CH               7     //!< PTE12 FTM channel
#define PTE12_FTM_FN               6     //!< PTE12 Pin multiplexor for FTM
#endif

// PTE24 = ADC0_SE17,GPIOE_24,I2C0_SCL (Alias: D15)
#define PTE24_GPIO_NAME            E     //!< PTE24 GPIO name
#define PTE24_GPIO_BIT             24    //!< PTE24 GPIO bit number
#define PTE24_GPIO_FN              1     //!< PTE24 Pin multiplexor for GPIO
#define PTE24_ADC_NUM              0     //!< PTE24 ADC number
#define PTE24_ADC_CH               17    //!< PTE24 ADC channel
#define PTE24_ADC_FN               0     //!< PTE24 Pin multiplexor for ADC
#if I2C0_SCL_SEL == 5
#define I2C0_SCL_FN                5     //!< PTE24 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTE24   //!< PTE24 I2C GPIO
#endif

// PTE25 = ADC0_SE18,GPIOE_25,I2C0_SDA (Alias: D14)
#define PTE25_GPIO_NAME            E     //!< PTE25 GPIO name
#define PTE25_GPIO_BIT             25    //!< PTE25 GPIO bit number
#define PTE25_GPIO_FN              1     //!< PTE25 Pin multiplexor for GPIO
#define PTE25_ADC_NUM              0     //!< PTE25 ADC number
#define PTE25_ADC_CH               18    //!< PTE25 ADC channel
#define PTE25_ADC_FN               0     //!< PTE25 Pin multiplexor for ADC
#if I2C0_SDA_SEL == 5
#define I2C0_SDA_FN                5     //!< PTE25 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTE25   //!< PTE25 I2C GPIO
#endif

// PTE26 = GPIOE_26
#define PTE26_GPIO_NAME            E     //!< PTE26 GPIO name
#define PTE26_GPIO_BIT             26    //!< PTE26 GPIO bit number
#define PTE26_GPIO_FN              1     //!< PTE26 Pin multiplexor for GPIO

// PTE27 = GPIOE_27
#define PTE27_GPIO_NAME            E     //!< PTE27 GPIO name
#define PTE27_GPIO_BIT             27    //!< PTE27 GPIO bit number
#define PTE27_GPIO_FN              1     //!< PTE27 Pin multiplexor for GPIO

// PTE28 = GPIOE_28
#define PTE28_GPIO_NAME            E     //!< PTE28 GPIO name
#define PTE28_GPIO_BIT             28    //!< PTE28 GPIO bit number
#define PTE28_GPIO_FN              1     //!< PTE28 Pin multiplexor for GPIO

#define DEFAULT_ADC_FN   0 //!< Fixed ADC Multiplexing value for pins
#define DEFAULT_GPIO_FN  1 //!< Fixed GPIO Multiplexing value for pins
#define DEFAULT_PORT_CLOCK_REG  SIM->SCGC5 //!< Fixed PORT Clock varies with port

#endif /* PIN_MAPPING_H_ */
