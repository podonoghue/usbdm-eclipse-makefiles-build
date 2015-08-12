/**
 * @file      pin_mapping.h (derived from pin_mapping-MKL25Z4.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKL25Z4
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

// <h> TPM Clock settings

// TPM_SC.CMOD ================================
//
//   <o> TPM_SC.CMOD Clock source 
//   <i> Selects the clock source for the TPM module. [TPM_SC.CMOD]
//     <0=> Disabled
//     <1=> Internal clock
//     <2=> External clock
//     <3=> Reserved
//     <1=> Default
// TPM_SC.PS ================================
//
//   <o1> TPM_SC.PS Clock prescaler 
//   <i> Selects the prescaler for the TPM module. [TPM_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
#define TPM_SC               (TPM_SC_CMOD(0x1)|TPM_SC_PS(0x0))

// </h>

#define ADC0_CLOCK_REG       SIM->SCGC6          
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC0_MASK 
#define CMP_CLOCK_REG        SIM->SCGC4          
#define CMP_CLOCK_MASK       SIM_SCGC4_CMP_MASK  
#define DAC0_CLOCK_REG       SIM->SCGC6          
#define DAC0_CLOCK_MASK      SIM_SCGC6_DAC0_MASK 
#define DMA_CLOCK_REG        SIM->SCGC7          
#define DMA_CLOCK_MASK       SIM_SCGC7_DMA_MASK  
#define DMAMUX_CLOCK_REG     SIM->SCGC6          
#define DMAMUX_CLOCK_MASK    SIM_SCGC6_DMAMUX_MASK
#define I2C0_CLOCK_REG       SIM->SCGC4          
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK 
#define I2C1_CLOCK_REG       SIM->SCGC4          
#define I2C1_CLOCK_MASK      SIM_SCGC4_I2C1_MASK 
#define LPTMR0_CLOCK_REG     SIM->SCGC5          
#define LPTMR0_CLOCK_MASK    SIM_SCGC5_LPTMR_MASK
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
#define RTC_CLOCK_REG        SIM->SCGC6          
#define RTC_CLOCK_MASK       SIM_SCGC6_RTC_MASK  
#define SPI0_CLOCK_REG       SIM->SCGC4          
#define SPI0_CLOCK_MASK      SIM_SCGC4_SPI0_MASK 
#define SPI1_CLOCK_REG       SIM->SCGC4          
#define SPI1_CLOCK_MASK      SIM_SCGC4_SPI1_MASK 
#define TPM0_CLOCK_REG       SIM->SCGC6          
#define TPM0_CLOCK_MASK      SIM_SCGC6_TPM0_MASK 
#define TPM1_CLOCK_REG       SIM->SCGC6          
#define TPM1_CLOCK_MASK      SIM_SCGC6_TPM1_MASK 
#define TPM2_CLOCK_REG       SIM->SCGC6          
#define TPM2_CLOCK_MASK      SIM_SCGC6_TPM2_MASK 
#define TSI_CLOCK_REG        SIM->SCGC5          
#define TSI_CLOCK_MASK       SIM_SCGC5_TSI_MASK  
#define UART0_CLOCK_REG      SIM->SCGC4          
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define UART1_CLOCK_REG      SIM->SCGC4          
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define UART2_CLOCK_REG      SIM->SCGC4          
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define USBOTG_CLOCK_REG     SIM->SCGC4          
#define USBOTG_CLOCK_MASK    SIM_SCGC4_USBOTG_MASK
#define PORT_CLOCK_REG       SIM->SCGC5          

// <h> Pin Peripheral mapping

// ADC0_0 maps to [Disabled, PTE20]
//   <o> ADC0_0 Pin Selection [PTE20(A11)] <constant>
//   <i> Selects which pin is used for ADC0_0
//     <0=> Disabled
//     <1=> PTE20 (Alias: A11)
//     <1=> Default
#define ADC0_0_SEL           1                   

// ADC0_3 maps to [Disabled, PTE22]
//   <o> ADC0_3 Pin Selection [PTE22(A9)] <constant>
//   <i> Selects which pin is used for ADC0_3
//     <0=> Disabled
//     <1=> PTE22 (Alias: A9)
//     <1=> Default
#define ADC0_3_SEL           1                   

// ADC0_4 maps to [Disabled, PTE29]
//   <o> ADC0_4 Pin Selection [PTE29(A7)] <constant>
//   <i> Selects which pin is used for ADC0_4
//     <0=> Disabled
//     <1=> PTE29 (Alias: A7)
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
//   <o> ADC0_6 Pin Selection [PTD5(D9)] <constant>
//   <i> Selects which pin is used for ADC0_6
//     <0=> Disabled
//     <1=> PTD5 (Alias: D9)
//     <1=> Default
#define ADC0_6_SEL           1                   

// ADC0_7 maps to [Disabled, PTD6]
//   <o> ADC0_7 Pin Selection [PTD6(D32)] <constant>
//   <i> Selects which pin is used for ADC0_7
//     <0=> Disabled
//     <1=> PTD6 (Alias: D32)
//     <1=> Default
#define ADC0_7_SEL           1                   

// ADC0_8 maps to [Disabled, PTB0]
//   <o> ADC0_8 Pin Selection [PTB0(A0)] <constant>
//   <i> Selects which pin is used for ADC0_8
//     <0=> Disabled
//     <1=> PTB0 (Alias: A0)
//     <1=> Default
#define ADC0_8_SEL           1                   

// ADC0_9 maps to [Disabled, PTB1]
//   <o> ADC0_9 Pin Selection [PTB1(A1)] <constant>
//   <i> Selects which pin is used for ADC0_9
//     <0=> Disabled
//     <1=> PTB1 (Alias: A1)
//     <1=> Default
#define ADC0_9_SEL           1                   

// ADC0_11 maps to [Disabled, PTC2]
//   <o> ADC0_11 Pin Selection [PTC2(A4)] <constant>
//   <i> Selects which pin is used for ADC0_11
//     <0=> Disabled
//     <1=> PTC2 (Alias: A4)
//     <1=> Default
#define ADC0_11_SEL          1                   

// ADC0_12 maps to [Disabled, PTB2]
//   <o> ADC0_12 Pin Selection [PTB2(A2)] <constant>
//   <i> Selects which pin is used for ADC0_12
//     <0=> Disabled
//     <1=> PTB2 (Alias: A2)
//     <1=> Default
#define ADC0_12_SEL          1                   

// ADC0_13 maps to [Disabled, PTB3]
//   <o> ADC0_13 Pin Selection [PTB3(A3)] <constant>
//   <i> Selects which pin is used for ADC0_13
//     <0=> Disabled
//     <1=> PTB3 (Alias: A3)
//     <1=> Default
#define ADC0_13_SEL          1                   

// ADC0_14 maps to [Disabled, PTC0]
//   <o> ADC0_14 Pin Selection [PTC0(D17)] <constant>
//   <i> Selects which pin is used for ADC0_14
//     <0=> Disabled
//     <1=> PTC0 (Alias: D17)
//     <1=> Default
#define ADC0_14_SEL          1                   

// ADC0_15 maps to [Disabled, PTC1]
//   <o> ADC0_15 Pin Selection [PTC1(A5)] <constant>
//   <i> Selects which pin is used for ADC0_15
//     <0=> Disabled
//     <1=> PTC1 (Alias: A5)
//     <1=> Default
#define ADC0_15_SEL          1                   

// ADC0_23 maps to [Disabled, PTE30]
//   <o> ADC0_23 Pin Selection [PTE30(A6)] <constant>
//   <i> Selects which pin is used for ADC0_23
//     <0=> Disabled
//     <1=> PTE30 (Alias: A6)
//     <1=> Default
#define ADC0_23_SEL          1                   

// I2C0_SCL maps to [Disabled, PTB0, PTB2, PTC8, PTE24]
//   <o> I2C0_SCL Pin Selection [PTB0(A0), PTB2(A2), PTC8(D6), PTE24] 
//   <i> Selects which pin is used for I2C0_SCL
//     <0=> Disabled
//     <1=> PTB0 (Alias: A0)
//     <2=> PTB2 (Alias: A2)
//     <3=> PTC8 (Alias: D6)
//     <4=> PTE24
//     <4=> Default
#define I2C0_SCL_SEL         4                   

// I2C0_SDA maps to [Disabled, PTB1, PTB3, PTC9, PTE25]
//   <o> I2C0_SDA Pin Selection [PTB1(A1), PTB3(A3), PTC9(D7), PTE25] 
//   <i> Selects which pin is used for I2C0_SDA
//     <0=> Disabled
//     <1=> PTB1 (Alias: A1)
//     <2=> PTB3 (Alias: A3)
//     <3=> PTC9 (Alias: D7)
//     <4=> PTE25
//     <4=> Default
#define I2C0_SDA_SEL         4                   

// I2C1_SDA maps to [Disabled, PTA4, PTC2, PTC11, PTE0]
//   <o> I2C1_SDA Pin Selection [PTA4(D4), PTC2(A4), PTC11(D23), PTE0(D15)] 
//   <i> Selects which pin is used for I2C1_SDA
//     <0=> Disabled
//     <1=> PTA4 (Alias: D4)
//     <2=> PTC2 (Alias: A4)
//     <3=> PTC11 (Alias: D23)
//     <4=> PTE0 (Alias: D15)
//     <4=> Default
#define I2C1_SDA_SEL         4                   

// I2C1_SCL maps to [Disabled, PTA3, PTC1, PTC10, PTE1]
//   <o> I2C1_SCL Pin Selection [PTA3, PTC1(A5), PTC10(D22), PTE1(D14)] 
//   <i> Selects which pin is used for I2C1_SCL
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTC1 (Alias: A5)
//     <3=> PTC10 (Alias: D22)
//     <4=> PTE1 (Alias: D14)
//     <4=> Default
#define I2C1_SCL_SEL         4                   

// LPTMR0_1 maps to [Disabled, PTA19]
//   <o> LPTMR0_1 Pin Selection [PTA19] 
//   <i> Selects which pin is used for LPTMR0_1
//     <0=> Disabled
//     <1=> PTA19
//     <0=> Default
#define LPTMR0_1_SEL         0                   

// LPTMR0_2 maps to [Disabled, PTC5]
//   <o> LPTMR0_2 Pin Selection [PTC5(D20)] 
//   <i> Selects which pin is used for LPTMR0_2
//     <0=> Disabled
//     <1=> PTC5 (Alias: D20)
//     <0=> Default
#define LPTMR0_2_SEL         0                   

// SPI0_MISO maps to [Disabled, PTA16, PTA17, PTC6, PTC7, PTD2, PTD3]
//   <o> SPI0_MISO Pin Selection [PTA16(D28), PTA17(D29), PTC6(D21), PTC7(D16), PTD2(D11), PTD3(D12)] 
//   <i> Selects which pin is used for SPI0_MISO
//     <0=> Disabled
//     <1=> PTA16 (Alias: D28)
//     <2=> PTA17 (Alias: D29)
//     <3=> PTC6 (Alias: D21)
//     <4=> PTC7 (Alias: D16)
//     <5=> PTD2 (Alias: D11)
//     <6=> PTD3 (Alias: D12)
//     <6=> Default
#define SPI0_MISO_SEL        6                   

// SPI0_MOSI maps to [Disabled, PTA16, PTA17, PTC6, PTC7, PTD2, PTD3]
//   <o> SPI0_MOSI Pin Selection [PTA16(D28), PTA17(D29), PTC6(D21), PTC7(D16), PTD2(D11), PTD3(D12)] 
//   <i> Selects which pin is used for SPI0_MOSI
//     <0=> Disabled
//     <1=> PTA16 (Alias: D28)
//     <2=> PTA17 (Alias: D29)
//     <3=> PTC6 (Alias: D21)
//     <4=> PTC7 (Alias: D16)
//     <5=> PTD2 (Alias: D11)
//     <6=> PTD3 (Alias: D12)
//     <5=> Default
#define SPI0_MOSI_SEL        5                   

// SPI0_PCS0 maps to [Disabled, PTA14, PTC4, PTD0]
//   <o> SPI0_PCS0 Pin Selection [PTA14, PTC4(D19), PTD0(D10)] 
//   <i> Selects which pin is used for SPI0_PCS0
//     <0=> Disabled
//     <1=> PTA14
//     <2=> PTC4 (Alias: D19)
//     <3=> PTD0 (Alias: D10)
//     <0=> Default
#define SPI0_PCS0_SEL        0                   

// SPI0_SCK maps to [Disabled, PTA15, PTC5, PTD1]
//   <o> SPI0_SCK Pin Selection [PTA15, PTC5(D20), PTD1(D13)] 
//   <i> Selects which pin is used for SPI0_SCK
//     <0=> Disabled
//     <1=> PTA15
//     <2=> PTC5 (Alias: D20)
//     <3=> PTD1 (Alias: D13)
//     <3=> Default
#define SPI0_SCK_SEL         3                   

// SPI1_MISO maps to [Disabled, PTB16, PTB17, PTD6, PTD7, PTE1, PTE3]
//   <o> SPI1_MISO Pin Selection [PTB16, PTB17, PTD6(D32), PTD7(D33), PTE1(D14), PTE3(A15)] 
//   <i> Selects which pin is used for SPI1_MISO
//     <0=> Disabled
//     <1=> PTB16
//     <2=> PTB17
//     <3=> PTD6 (Alias: D32)
//     <4=> PTD7 (Alias: D33)
//     <5=> PTE1 (Alias: D14)
//     <6=> PTE3 (Alias: A15)
//     <1=> Default
#define SPI1_MISO_SEL        1                   

// SPI1_MOSI maps to [Disabled, PTB16, PTB17, PTD6, PTD7, PTE1, PTE3]
//   <o> SPI1_MOSI Pin Selection [PTB16, PTB17, PTD6(D32), PTD7(D33), PTE1(D14), PTE3(A15)] 
//   <i> Selects which pin is used for SPI1_MOSI
//     <0=> Disabled
//     <1=> PTB16
//     <2=> PTB17
//     <3=> PTD6 (Alias: D32)
//     <4=> PTD7 (Alias: D33)
//     <5=> PTE1 (Alias: D14)
//     <6=> PTE3 (Alias: A15)
//     <2=> Default
#define SPI1_MOSI_SEL        2                   

// SPI1_PCS0 maps to [Disabled, PTB10, PTD4, PTE4]
//   <o> SPI1_PCS0 Pin Selection [PTB10(A18), PTD4(D2), PTE4(A14)] 
//   <i> Selects which pin is used for SPI1_PCS0
//     <0=> Disabled
//     <1=> PTB10 (Alias: A18)
//     <2=> PTD4 (Alias: D2)
//     <3=> PTE4 (Alias: A14)
//     <0=> Default
#define SPI1_PCS0_SEL        0                   

// SPI1_SCK maps to [Disabled, PTB11, PTD5, PTE2]
//   <o> SPI1_SCK Pin Selection [PTB11(A17), PTD5(D9), PTE2(A16)] 
//   <i> Selects which pin is used for SPI1_SCK
//     <0=> Disabled
//     <1=> PTB11 (Alias: A17)
//     <2=> PTD5 (Alias: D9)
//     <3=> PTE2 (Alias: A16)
//     <1=> Default
#define SPI1_SCK_SEL         1                   

// TPM0_0 maps to [Disabled, PTA3, PTC1, PTD0, PTE24]
//   <o> TPM0_0 Pin Selection [PTA3, PTC1(A5), PTD0(D10), PTE24] 
//   <i> Selects which pin is used for TPM0_0
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTC1 (Alias: A5)
//     <3=> PTD0 (Alias: D10)
//     <4=> PTE24
//     <3=> Default
#define TPM0_0_SEL           3                   

// TPM0_1 maps to [Disabled, PTA4, PTC2, PTD1, PTE25]
//   <o> TPM0_1 Pin Selection [PTA4(D4), PTC2(A4), PTD1(D13), PTE25] 
//   <i> Selects which pin is used for TPM0_1
//     <0=> Disabled
//     <1=> PTA4 (Alias: D4)
//     <2=> PTC2 (Alias: A4)
//     <3=> PTD1 (Alias: D13)
//     <4=> PTE25
//     <3=> Default
#define TPM0_1_SEL           3                   

// TPM0_2 maps to [Disabled, PTA5, PTC3, PTD2, PTE29]
//   <o> TPM0_2 Pin Selection [PTA5(D5), PTC3(D18), PTD2(D11), PTE29(A7)] 
//   <i> Selects which pin is used for TPM0_2
//     <0=> Disabled
//     <1=> PTA5 (Alias: D5)
//     <2=> PTC3 (Alias: D18)
//     <3=> PTD2 (Alias: D11)
//     <4=> PTE29 (Alias: A7)
//     <1=> Default
#define TPM0_2_SEL           1                   

// TPM0_3 maps to [Disabled, PTC4, PTD3, PTE30]
//   <o> TPM0_3 Pin Selection [PTC4(D19), PTD3(D12), PTE30(A6)] 
//   <i> Selects which pin is used for TPM0_3
//     <0=> Disabled
//     <1=> PTC4 (Alias: D19)
//     <2=> PTD3 (Alias: D12)
//     <3=> PTE30 (Alias: A6)
//     <1=> Default
#define TPM0_3_SEL           1                   

// TPM0_4 maps to [Disabled, PTC8, PTD4, PTE31]
//   <o> TPM0_4 Pin Selection [PTC8(D6), PTD4(D2), PTE31(D30)] 
//   <i> Selects which pin is used for TPM0_4
//     <0=> Disabled
//     <1=> PTC8 (Alias: D6)
//     <2=> PTD4 (Alias: D2)
//     <3=> PTE31 (Alias: D30)
//     <1=> Default
#define TPM0_4_SEL           1                   

// TPM0_5 maps to [Disabled, PTA0, PTC9, PTD5]
//   <o> TPM0_5 Pin Selection [PTA0, PTC9(D7), PTD5(D9)] 
//   <i> Selects which pin is used for TPM0_5
//     <0=> Disabled
//     <1=> PTA0
//     <2=> PTC9 (Alias: D7)
//     <3=> PTD5 (Alias: D9)
//     <2=> Default
#define TPM0_5_SEL           2                   

// TPM1_0 maps to [Disabled, PTA12, PTB0, PTE20]
//   <o> TPM1_0 Pin Selection [PTA12(D3), PTB0(A0), PTE20(A11)] 
//   <i> Selects which pin is used for TPM1_0
//     <0=> Disabled
//     <1=> PTA12 (Alias: D3)
//     <2=> PTB0 (Alias: A0)
//     <3=> PTE20 (Alias: A11)
//     <1=> Default
#define TPM1_0_SEL           1                   

// TPM1_1 maps to [Disabled, PTA13, PTB1, PTE21]
//   <o> TPM1_1 Pin Selection [PTA13(D8), PTB1(A1), PTE21(A10)] 
//   <i> Selects which pin is used for TPM1_1
//     <0=> Disabled
//     <1=> PTA13 (Alias: D8)
//     <2=> PTB1 (Alias: A1)
//     <3=> PTE21 (Alias: A10)
//     <1=> Default
#define TPM1_1_SEL           1                   

// TPM2_0 maps to [Disabled, PTA1, PTB2, PTB18, PTE22]
//   <o> TPM2_0 Pin Selection [PTA1(D0), PTB2(A2), PTB18, PTE22(A9)] 
//   <i> Selects which pin is used for TPM2_0
//     <0=> Disabled
//     <1=> PTA1 (Alias: D0)
//     <2=> PTB2 (Alias: A2)
//     <3=> PTB18
//     <4=> PTE22 (Alias: A9)
//     <1=> Default
#define TPM2_0_SEL           1                   

// TPM2_1 maps to [Disabled, PTA2, PTB3, PTB19, PTE23]
//   <o> TPM2_1 Pin Selection [PTA2(D1), PTB3(A3), PTB19, PTE23(A8)] 
//   <i> Selects which pin is used for TPM2_1
//     <0=> Disabled
//     <1=> PTA2 (Alias: D1)
//     <2=> PTB3 (Alias: A3)
//     <3=> PTB19
//     <4=> PTE23 (Alias: A8)
//     <1=> Default
#define TPM2_1_SEL           1                   

// </h>

// PTA0 = GPIOA_0,TPM0_5
#define PTA0_GPIO_NAME             A     //!< PTA0 GPIO name
#define PTA0_GPIO_BIT              0     //!< PTA0 GPIO bit number
#define PTA0_GPIO_FN               1     //!< PTA0 Pin multiplexor for GPIO
#if TPM0_5_SEL == 1
#define PTA0_TPM_NUM               0     //!< PTA0 TPM number
#define PTA0_TPM_CH                5     //!< PTA0 TPM channel
#define PTA0_TPM_FN                3     //!< PTA0 Pin multiplexor for TPM
#endif

// PTA1 = GPIOA_1,TPM2_0 (Alias: D0)
#define PTA1_GPIO_NAME             A     //!< PTA1 GPIO name
#define PTA1_GPIO_BIT              1     //!< PTA1 GPIO bit number
#define PTA1_GPIO_FN               1     //!< PTA1 Pin multiplexor for GPIO
#if TPM2_0_SEL == 1
#define PTA1_TPM_NUM               2     //!< PTA1 TPM number
#define PTA1_TPM_CH                0     //!< PTA1 TPM channel
#define PTA1_TPM_FN                3     //!< PTA1 Pin multiplexor for TPM
#endif

// PTA2 = GPIOA_2,TPM2_1 (Alias: D1)
#define PTA2_GPIO_NAME             A     //!< PTA2 GPIO name
#define PTA2_GPIO_BIT              2     //!< PTA2 GPIO bit number
#define PTA2_GPIO_FN               1     //!< PTA2 Pin multiplexor for GPIO
#if TPM2_1_SEL == 1
#define PTA2_TPM_NUM               2     //!< PTA2 TPM number
#define PTA2_TPM_CH                1     //!< PTA2 TPM channel
#define PTA2_TPM_FN                3     //!< PTA2 Pin multiplexor for TPM
#endif

// PTA3 = GPIOA_3,TPM0_0,I2C1_SCL
#define PTA3_GPIO_NAME             A     //!< PTA3 GPIO name
#define PTA3_GPIO_BIT              3     //!< PTA3 GPIO bit number
#define PTA3_GPIO_FN               1     //!< PTA3 Pin multiplexor for GPIO
#if TPM0_0_SEL == 1
#define PTA3_TPM_NUM               0     //!< PTA3 TPM number
#define PTA3_TPM_CH                0     //!< PTA3 TPM channel
#define PTA3_TPM_FN                3     //!< PTA3 Pin multiplexor for TPM
#endif
#if I2C1_SCL_SEL == 1
#define I2C1_SCL_FN                2     //!< PTA3 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTA3   //!< PTA3 I2C GPIO
#endif

// PTA4 = GPIOA_4,TPM0_1,I2C1_SDA (Alias: D4)
#define PTA4_GPIO_NAME             A     //!< PTA4 GPIO name
#define PTA4_GPIO_BIT              4     //!< PTA4 GPIO bit number
#define PTA4_GPIO_FN               1     //!< PTA4 Pin multiplexor for GPIO
#if TPM0_1_SEL == 1
#define PTA4_TPM_NUM               0     //!< PTA4 TPM number
#define PTA4_TPM_CH                1     //!< PTA4 TPM channel
#define PTA4_TPM_FN                3     //!< PTA4 Pin multiplexor for TPM
#endif
#if I2C1_SDA_SEL == 1
#define I2C1_SDA_FN                2     //!< PTA4 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTA4   //!< PTA4 I2C GPIO
#endif

// PTA5 = GPIOA_5,TPM0_2 (Alias: D5)
#define PTA5_GPIO_NAME             A     //!< PTA5 GPIO name
#define PTA5_GPIO_BIT              5     //!< PTA5 GPIO bit number
#define PTA5_GPIO_FN               1     //!< PTA5 Pin multiplexor for GPIO
#if TPM0_2_SEL == 1
#define PTA5_TPM_NUM               0     //!< PTA5 TPM number
#define PTA5_TPM_CH                2     //!< PTA5 TPM channel
#define PTA5_TPM_FN                3     //!< PTA5 Pin multiplexor for TPM
#endif

// PTA12 = GPIOA_12,TPM1_0 (Alias: D3)
#define PTA12_GPIO_NAME            A     //!< PTA12 GPIO name
#define PTA12_GPIO_BIT             12    //!< PTA12 GPIO bit number
#define PTA12_GPIO_FN              1     //!< PTA12 Pin multiplexor for GPIO
#if TPM1_0_SEL == 1
#define PTA12_TPM_NUM              1     //!< PTA12 TPM number
#define PTA12_TPM_CH               0     //!< PTA12 TPM channel
#define PTA12_TPM_FN               3     //!< PTA12 Pin multiplexor for TPM
#endif

// PTA13 = GPIOA_13,TPM1_1 (Alias: D8)
#define PTA13_GPIO_NAME            A     //!< PTA13 GPIO name
#define PTA13_GPIO_BIT             13    //!< PTA13 GPIO bit number
#define PTA13_GPIO_FN              1     //!< PTA13 Pin multiplexor for GPIO
#if TPM1_1_SEL == 1
#define PTA13_TPM_NUM              1     //!< PTA13 TPM number
#define PTA13_TPM_CH               1     //!< PTA13 TPM channel
#define PTA13_TPM_FN               3     //!< PTA13 Pin multiplexor for TPM
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

// PTA16 = GPIOA_16,SPI0_MOSI,SPI0_MISO (Alias: D28)
#define PTA16_GPIO_NAME            A     //!< PTA16 GPIO name
#define PTA16_GPIO_BIT             16    //!< PTA16 GPIO bit number
#define PTA16_GPIO_FN              1     //!< PTA16 Pin multiplexor for GPIO
#if SPI0_MOSI_SEL == 1
#define SPI0_MOSI_FN               2     //!< PTA16 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTA16   //!< PTA16 SPI GPIO
#endif
#if SPI0_MISO_SEL == 1
#define SPI0_MISO_FN               5     //!< PTA16 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTA16   //!< PTA16 SPI GPIO
#endif

// PTA17 = GPIOA_17,SPI0_MISO,SPI0_MOSI (Alias: D29)
#define PTA17_GPIO_NAME            A     //!< PTA17 GPIO name
#define PTA17_GPIO_BIT             17    //!< PTA17 GPIO bit number
#define PTA17_GPIO_FN              1     //!< PTA17 Pin multiplexor for GPIO
#if SPI0_MISO_SEL == 2
#define SPI0_MISO_FN               2     //!< PTA17 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTA17   //!< PTA17 SPI GPIO
#endif
#if SPI0_MOSI_SEL == 2
#define SPI0_MOSI_FN               5     //!< PTA17 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTA17   //!< PTA17 SPI GPIO
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

// PTA20 = GPIOA_20
#define PTA20_GPIO_NAME            A     //!< PTA20 GPIO name
#define PTA20_GPIO_BIT             20    //!< PTA20 GPIO bit number
#define PTA20_GPIO_FN              1     //!< PTA20 Pin multiplexor for GPIO

// PTB0 = GPIOB_0,ADC0_8,TPM1_0,I2C0_SCL (Alias: A0)
#define PTB0_GPIO_NAME             B     //!< PTB0 GPIO name
#define PTB0_GPIO_BIT              0     //!< PTB0 GPIO bit number
#define PTB0_GPIO_FN               1     //!< PTB0 Pin multiplexor for GPIO
#define PTB0_ADC_NUM               0     //!< PTB0 ADC number
#define PTB0_ADC_CH                8     //!< PTB0 ADC channel
#define PTB0_ADC_FN                0     //!< PTB0 Pin multiplexor for ADC
#if TPM1_0_SEL == 2
#define PTB0_TPM_NUM               1     //!< PTB0 TPM number
#define PTB0_TPM_CH                0     //!< PTB0 TPM channel
#define PTB0_TPM_FN                3     //!< PTB0 Pin multiplexor for TPM
#endif
#if I2C0_SCL_SEL == 1
#define I2C0_SCL_FN                2     //!< PTB0 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB0   //!< PTB0 I2C GPIO
#endif

// PTB1 = GPIOB_1,ADC0_9,TPM1_1,I2C0_SDA (Alias: A1)
#define PTB1_GPIO_NAME             B     //!< PTB1 GPIO name
#define PTB1_GPIO_BIT              1     //!< PTB1 GPIO bit number
#define PTB1_GPIO_FN               1     //!< PTB1 Pin multiplexor for GPIO
#define PTB1_ADC_NUM               0     //!< PTB1 ADC number
#define PTB1_ADC_CH                9     //!< PTB1 ADC channel
#define PTB1_ADC_FN                0     //!< PTB1 Pin multiplexor for ADC
#if TPM1_1_SEL == 2
#define PTB1_TPM_NUM               1     //!< PTB1 TPM number
#define PTB1_TPM_CH                1     //!< PTB1 TPM channel
#define PTB1_TPM_FN                3     //!< PTB1 Pin multiplexor for TPM
#endif
#if I2C0_SDA_SEL == 1
#define I2C0_SDA_FN                2     //!< PTB1 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB1   //!< PTB1 I2C GPIO
#endif

// PTB2 = GPIOB_2,ADC0_12,TPM2_0,I2C0_SCL (Alias: A2)
#define PTB2_GPIO_NAME             B     //!< PTB2 GPIO name
#define PTB2_GPIO_BIT              2     //!< PTB2 GPIO bit number
#define PTB2_GPIO_FN               1     //!< PTB2 Pin multiplexor for GPIO
#define PTB2_ADC_NUM               0     //!< PTB2 ADC number
#define PTB2_ADC_CH                12    //!< PTB2 ADC channel
#define PTB2_ADC_FN                0     //!< PTB2 Pin multiplexor for ADC
#if TPM2_0_SEL == 2
#define PTB2_TPM_NUM               2     //!< PTB2 TPM number
#define PTB2_TPM_CH                0     //!< PTB2 TPM channel
#define PTB2_TPM_FN                3     //!< PTB2 Pin multiplexor for TPM
#endif
#if I2C0_SCL_SEL == 2
#define I2C0_SCL_FN                2     //!< PTB2 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB2   //!< PTB2 I2C GPIO
#endif

// PTB3 = GPIOB_3,ADC0_13,TPM2_1,I2C0_SDA (Alias: A3)
#define PTB3_GPIO_NAME             B     //!< PTB3 GPIO name
#define PTB3_GPIO_BIT              3     //!< PTB3 GPIO bit number
#define PTB3_GPIO_FN               1     //!< PTB3 Pin multiplexor for GPIO
#define PTB3_ADC_NUM               0     //!< PTB3 ADC number
#define PTB3_ADC_CH                13    //!< PTB3 ADC channel
#define PTB3_ADC_FN                0     //!< PTB3 Pin multiplexor for ADC
#if TPM2_1_SEL == 2
#define PTB3_TPM_NUM               2     //!< PTB3 TPM number
#define PTB3_TPM_CH                1     //!< PTB3 TPM channel
#define PTB3_TPM_FN                3     //!< PTB3 Pin multiplexor for TPM
#endif
#if I2C0_SDA_SEL == 2
#define I2C0_SDA_FN                2     //!< PTB3 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB3   //!< PTB3 I2C GPIO
#endif

// PTB8 = GPIOB_8 (Alias: A20)
#define PTB8_GPIO_NAME             B     //!< PTB8 GPIO name
#define PTB8_GPIO_BIT              8     //!< PTB8 GPIO bit number
#define PTB8_GPIO_FN               1     //!< PTB8 Pin multiplexor for GPIO

// PTB9 = GPIOB_9 (Alias: A19)
#define PTB9_GPIO_NAME             B     //!< PTB9 GPIO name
#define PTB9_GPIO_BIT              9     //!< PTB9 GPIO bit number
#define PTB9_GPIO_FN               1     //!< PTB9 Pin multiplexor for GPIO

// PTB10 = GPIOB_10,SPI1_PCS0 (Alias: A18)
#define PTB10_GPIO_NAME            B     //!< PTB10 GPIO name
#define PTB10_GPIO_BIT             10    //!< PTB10 GPIO bit number
#define PTB10_GPIO_FN              1     //!< PTB10 Pin multiplexor for GPIO
#if SPI1_PCS0_SEL == 1
#define SPI1_PCS0_FN               2     //!< PTB10 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTB10   //!< PTB10 SPI GPIO
#endif

// PTB11 = GPIOB_11,SPI1_SCK (Alias: A17)
#define PTB11_GPIO_NAME            B     //!< PTB11 GPIO name
#define PTB11_GPIO_BIT             11    //!< PTB11 GPIO bit number
#define PTB11_GPIO_FN              1     //!< PTB11 Pin multiplexor for GPIO
#if SPI1_SCK_SEL == 1
#define SPI1_SCK_FN                2     //!< PTB11 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTB11   //!< PTB11 SPI GPIO
#endif

// PTB16 = GPIOB_16,SPI1_MOSI,SPI1_MISO
#define PTB16_GPIO_NAME            B     //!< PTB16 GPIO name
#define PTB16_GPIO_BIT             16    //!< PTB16 GPIO bit number
#define PTB16_GPIO_FN              1     //!< PTB16 Pin multiplexor for GPIO
#if SPI1_MOSI_SEL == 1
#define SPI1_MOSI_FN               2     //!< PTB16 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTB16   //!< PTB16 SPI GPIO
#endif
#if SPI1_MISO_SEL == 1
#define SPI1_MISO_FN               5     //!< PTB16 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTB16   //!< PTB16 SPI GPIO
#endif

// PTB17 = GPIOB_17,SPI1_MISO,SPI1_MOSI
#define PTB17_GPIO_NAME            B     //!< PTB17 GPIO name
#define PTB17_GPIO_BIT             17    //!< PTB17 GPIO bit number
#define PTB17_GPIO_FN              1     //!< PTB17 Pin multiplexor for GPIO
#if SPI1_MISO_SEL == 2
#define SPI1_MISO_FN               2     //!< PTB17 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTB17   //!< PTB17 SPI GPIO
#endif
#if SPI1_MOSI_SEL == 2
#define SPI1_MOSI_FN               5     //!< PTB17 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTB17   //!< PTB17 SPI GPIO
#endif

// PTB18 = GPIOB_18,TPM2_0
#define PTB18_GPIO_NAME            B     //!< PTB18 GPIO name
#define PTB18_GPIO_BIT             18    //!< PTB18 GPIO bit number
#define PTB18_GPIO_FN              1     //!< PTB18 Pin multiplexor for GPIO
#if TPM2_0_SEL == 3
#define PTB18_TPM_NUM              2     //!< PTB18 TPM number
#define PTB18_TPM_CH               0     //!< PTB18 TPM channel
#define PTB18_TPM_FN               3     //!< PTB18 Pin multiplexor for TPM
#endif

// PTB19 = GPIOB_19,TPM2_1
#define PTB19_GPIO_NAME            B     //!< PTB19 GPIO name
#define PTB19_GPIO_BIT             19    //!< PTB19 GPIO bit number
#define PTB19_GPIO_FN              1     //!< PTB19 Pin multiplexor for GPIO
#if TPM2_1_SEL == 3
#define PTB19_TPM_NUM              2     //!< PTB19 TPM number
#define PTB19_TPM_CH               1     //!< PTB19 TPM channel
#define PTB19_TPM_FN               3     //!< PTB19 Pin multiplexor for TPM
#endif

// PTC0 = GPIOC_0,ADC0_14 (Alias: D17)
#define PTC0_GPIO_NAME             C     //!< PTC0 GPIO name
#define PTC0_GPIO_BIT              0     //!< PTC0 GPIO bit number
#define PTC0_GPIO_FN               1     //!< PTC0 Pin multiplexor for GPIO
#define PTC0_ADC_NUM               0     //!< PTC0 ADC number
#define PTC0_ADC_CH                14    //!< PTC0 ADC channel
#define PTC0_ADC_FN                0     //!< PTC0 Pin multiplexor for ADC

// PTC1 = GPIOC_1,ADC0_15,TPM0_0,I2C1_SCL (Alias: A5)
#define PTC1_GPIO_NAME             C     //!< PTC1 GPIO name
#define PTC1_GPIO_BIT              1     //!< PTC1 GPIO bit number
#define PTC1_GPIO_FN               1     //!< PTC1 Pin multiplexor for GPIO
#define PTC1_ADC_NUM               0     //!< PTC1 ADC number
#define PTC1_ADC_CH                15    //!< PTC1 ADC channel
#define PTC1_ADC_FN                0     //!< PTC1 Pin multiplexor for ADC
#if TPM0_0_SEL == 2
#define PTC1_TPM_NUM               0     //!< PTC1 TPM number
#define PTC1_TPM_CH                0     //!< PTC1 TPM channel
#define PTC1_TPM_FN                4     //!< PTC1 Pin multiplexor for TPM
#endif
#if I2C1_SCL_SEL == 2
#define I2C1_SCL_FN                2     //!< PTC1 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTC1   //!< PTC1 I2C GPIO
#endif

// PTC2 = GPIOC_2,ADC0_11,TPM0_1,I2C1_SDA (Alias: A4)
#define PTC2_GPIO_NAME             C     //!< PTC2 GPIO name
#define PTC2_GPIO_BIT              2     //!< PTC2 GPIO bit number
#define PTC2_GPIO_FN               1     //!< PTC2 Pin multiplexor for GPIO
#define PTC2_ADC_NUM               0     //!< PTC2 ADC number
#define PTC2_ADC_CH                11    //!< PTC2 ADC channel
#define PTC2_ADC_FN                0     //!< PTC2 Pin multiplexor for ADC
#if TPM0_1_SEL == 2
#define PTC2_TPM_NUM               0     //!< PTC2 TPM number
#define PTC2_TPM_CH                1     //!< PTC2 TPM channel
#define PTC2_TPM_FN                4     //!< PTC2 Pin multiplexor for TPM
#endif
#if I2C1_SDA_SEL == 2
#define I2C1_SDA_FN                2     //!< PTC2 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTC2   //!< PTC2 I2C GPIO
#endif

// PTC3 = GPIOC_3,TPM0_2 (Alias: D18)
#define PTC3_GPIO_NAME             C     //!< PTC3 GPIO name
#define PTC3_GPIO_BIT              3     //!< PTC3 GPIO bit number
#define PTC3_GPIO_FN               1     //!< PTC3 Pin multiplexor for GPIO
#if TPM0_2_SEL == 2
#define PTC3_TPM_NUM               0     //!< PTC3 TPM number
#define PTC3_TPM_CH                2     //!< PTC3 TPM channel
#define PTC3_TPM_FN                4     //!< PTC3 Pin multiplexor for TPM
#endif

// PTC4 = GPIOC_4,TPM0_3,SPI0_PCS0 (Alias: D19)
#define PTC4_GPIO_NAME             C     //!< PTC4 GPIO name
#define PTC4_GPIO_BIT              4     //!< PTC4 GPIO bit number
#define PTC4_GPIO_FN               1     //!< PTC4 Pin multiplexor for GPIO
#if TPM0_3_SEL == 1
#define PTC4_TPM_NUM               0     //!< PTC4 TPM number
#define PTC4_TPM_CH                3     //!< PTC4 TPM channel
#define PTC4_TPM_FN                4     //!< PTC4 Pin multiplexor for TPM
#endif
#if SPI0_PCS0_SEL == 2
#define SPI0_PCS0_FN               2     //!< PTC4 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTC4   //!< PTC4 SPI GPIO
#endif

// PTC5 = GPIOC_5,LPTMR0_2,SPI0_SCK (Alias: D20)
#define PTC5_GPIO_NAME             C     //!< PTC5 GPIO name
#define PTC5_GPIO_BIT              5     //!< PTC5 GPIO bit number
#define PTC5_GPIO_FN               1     //!< PTC5 Pin multiplexor for GPIO
#if LPTMR0_2_SEL == 1
#define LPTMR0_2_FN                3     //!< PTC5 Pin multiplexor for LPTMR
#define LPTMR0_2_GPIO              digitalIO_PTC5   //!< PTC5 LPTMR GPIO
#endif
#if SPI0_SCK_SEL == 2
#define SPI0_SCK_FN                2     //!< PTC5 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTC5   //!< PTC5 SPI GPIO
#endif

// PTC6 = GPIOC_6,SPI0_MOSI,SPI0_MISO (Alias: D21)
#define PTC6_GPIO_NAME             C     //!< PTC6 GPIO name
#define PTC6_GPIO_BIT              6     //!< PTC6 GPIO bit number
#define PTC6_GPIO_FN               1     //!< PTC6 Pin multiplexor for GPIO
#if SPI0_MOSI_SEL == 3
#define SPI0_MOSI_FN               2     //!< PTC6 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTC6   //!< PTC6 SPI GPIO
#endif
#if SPI0_MISO_SEL == 3
#define SPI0_MISO_FN               5     //!< PTC6 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTC6   //!< PTC6 SPI GPIO
#endif

// PTC7 = GPIOC_7,SPI0_MISO,SPI0_MOSI (Alias: D16)
#define PTC7_GPIO_NAME             C     //!< PTC7 GPIO name
#define PTC7_GPIO_BIT              7     //!< PTC7 GPIO bit number
#define PTC7_GPIO_FN               1     //!< PTC7 Pin multiplexor for GPIO
#if SPI0_MISO_SEL == 4
#define SPI0_MISO_FN               2     //!< PTC7 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTC7   //!< PTC7 SPI GPIO
#endif
#if SPI0_MOSI_SEL == 4
#define SPI0_MOSI_FN               5     //!< PTC7 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTC7   //!< PTC7 SPI GPIO
#endif

// PTC8 = GPIOC_8,TPM0_4,I2C0_SCL (Alias: D6)
#define PTC8_GPIO_NAME             C     //!< PTC8 GPIO name
#define PTC8_GPIO_BIT              8     //!< PTC8 GPIO bit number
#define PTC8_GPIO_FN               1     //!< PTC8 Pin multiplexor for GPIO
#if TPM0_4_SEL == 1
#define PTC8_TPM_NUM               0     //!< PTC8 TPM number
#define PTC8_TPM_CH                4     //!< PTC8 TPM channel
#define PTC8_TPM_FN                3     //!< PTC8 Pin multiplexor for TPM
#endif
#if I2C0_SCL_SEL == 3
#define I2C0_SCL_FN                2     //!< PTC8 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTC8   //!< PTC8 I2C GPIO
#endif

// PTC9 = GPIOC_9,TPM0_5,I2C0_SDA (Alias: D7)
#define PTC9_GPIO_NAME             C     //!< PTC9 GPIO name
#define PTC9_GPIO_BIT              9     //!< PTC9 GPIO bit number
#define PTC9_GPIO_FN               1     //!< PTC9 Pin multiplexor for GPIO
#if TPM0_5_SEL == 2
#define PTC9_TPM_NUM               0     //!< PTC9 TPM number
#define PTC9_TPM_CH                5     //!< PTC9 TPM channel
#define PTC9_TPM_FN                3     //!< PTC9 Pin multiplexor for TPM
#endif
#if I2C0_SDA_SEL == 3
#define I2C0_SDA_FN                2     //!< PTC9 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTC9   //!< PTC9 I2C GPIO
#endif

// PTC10 = GPIOC_10,I2C1_SCL (Alias: D22)
#define PTC10_GPIO_NAME            C     //!< PTC10 GPIO name
#define PTC10_GPIO_BIT             10    //!< PTC10 GPIO bit number
#define PTC10_GPIO_FN              1     //!< PTC10 Pin multiplexor for GPIO
#if I2C1_SCL_SEL == 3
#define I2C1_SCL_FN                2     //!< PTC10 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTC10   //!< PTC10 I2C GPIO
#endif

// PTC11 = GPIOC_11,I2C1_SDA (Alias: D23)
#define PTC11_GPIO_NAME            C     //!< PTC11 GPIO name
#define PTC11_GPIO_BIT             11    //!< PTC11 GPIO bit number
#define PTC11_GPIO_FN              1     //!< PTC11 Pin multiplexor for GPIO
#if I2C1_SDA_SEL == 3
#define I2C1_SDA_FN                2     //!< PTC11 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTC11   //!< PTC11 I2C GPIO
#endif

// PTC12 = GPIOC_12 (Alias: D24)
#define PTC12_GPIO_NAME            C     //!< PTC12 GPIO name
#define PTC12_GPIO_BIT             12    //!< PTC12 GPIO bit number
#define PTC12_GPIO_FN              1     //!< PTC12 Pin multiplexor for GPIO

// PTC13 = GPIOC_13 (Alias: D25)
#define PTC13_GPIO_NAME            C     //!< PTC13 GPIO name
#define PTC13_GPIO_BIT             13    //!< PTC13 GPIO bit number
#define PTC13_GPIO_FN              1     //!< PTC13 Pin multiplexor for GPIO

// PTC16 = GPIOC_16 (Alias: D26)
#define PTC16_GPIO_NAME            C     //!< PTC16 GPIO name
#define PTC16_GPIO_BIT             16    //!< PTC16 GPIO bit number
#define PTC16_GPIO_FN              1     //!< PTC16 Pin multiplexor for GPIO

// PTC17 = GPIOC_17 (Alias: D27)
#define PTC17_GPIO_NAME            C     //!< PTC17 GPIO name
#define PTC17_GPIO_BIT             17    //!< PTC17 GPIO bit number
#define PTC17_GPIO_FN              1     //!< PTC17 Pin multiplexor for GPIO

// PTD0 = GPIOD_0,TPM0_0,SPI0_PCS0 (Alias: D10)
#define PTD0_GPIO_NAME             D     //!< PTD0 GPIO name
#define PTD0_GPIO_BIT              0     //!< PTD0 GPIO bit number
#define PTD0_GPIO_FN               1     //!< PTD0 Pin multiplexor for GPIO
#if TPM0_0_SEL == 3
#define PTD0_TPM_NUM               0     //!< PTD0 TPM number
#define PTD0_TPM_CH                0     //!< PTD0 TPM channel
#define PTD0_TPM_FN                4     //!< PTD0 Pin multiplexor for TPM
#endif
#if SPI0_PCS0_SEL == 3
#define SPI0_PCS0_FN               2     //!< PTD0 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTD0   //!< PTD0 SPI GPIO
#endif

// PTD1 = GPIOD_1,ADC0_5,TPM0_1,SPI0_SCK (Alias: D13)
#define PTD1_GPIO_NAME             D     //!< PTD1 GPIO name
#define PTD1_GPIO_BIT              1     //!< PTD1 GPIO bit number
#define PTD1_GPIO_FN               1     //!< PTD1 Pin multiplexor for GPIO
#define PTD1_ADC_NUM               0     //!< PTD1 ADC number
#define PTD1_ADC_CH                5     //!< PTD1 ADC channel
#define PTD1_ADC_FN                0     //!< PTD1 Pin multiplexor for ADC
#if TPM0_1_SEL == 3
#define PTD1_TPM_NUM               0     //!< PTD1 TPM number
#define PTD1_TPM_CH                1     //!< PTD1 TPM channel
#define PTD1_TPM_FN                4     //!< PTD1 Pin multiplexor for TPM
#endif
#if SPI0_SCK_SEL == 3
#define SPI0_SCK_FN                2     //!< PTD1 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTD1   //!< PTD1 SPI GPIO
#endif

// PTD2 = GPIOD_2,TPM0_2,SPI0_MOSI,SPI0_MISO (Alias: D11)
#define PTD2_GPIO_NAME             D     //!< PTD2 GPIO name
#define PTD2_GPIO_BIT              2     //!< PTD2 GPIO bit number
#define PTD2_GPIO_FN               1     //!< PTD2 Pin multiplexor for GPIO
#if TPM0_2_SEL == 3
#define PTD2_TPM_NUM               0     //!< PTD2 TPM number
#define PTD2_TPM_CH                2     //!< PTD2 TPM channel
#define PTD2_TPM_FN                4     //!< PTD2 Pin multiplexor for TPM
#endif
#if SPI0_MOSI_SEL == 5
#define SPI0_MOSI_FN               2     //!< PTD2 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTD2   //!< PTD2 SPI GPIO
#endif
#if SPI0_MISO_SEL == 5
#define SPI0_MISO_FN               5     //!< PTD2 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTD2   //!< PTD2 SPI GPIO
#endif

// PTD3 = GPIOD_3,TPM0_3,SPI0_MISO,SPI0_MOSI (Alias: D12)
#define PTD3_GPIO_NAME             D     //!< PTD3 GPIO name
#define PTD3_GPIO_BIT              3     //!< PTD3 GPIO bit number
#define PTD3_GPIO_FN               1     //!< PTD3 Pin multiplexor for GPIO
#if TPM0_3_SEL == 2
#define PTD3_TPM_NUM               0     //!< PTD3 TPM number
#define PTD3_TPM_CH                3     //!< PTD3 TPM channel
#define PTD3_TPM_FN                4     //!< PTD3 Pin multiplexor for TPM
#endif
#if SPI0_MISO_SEL == 6
#define SPI0_MISO_FN               2     //!< PTD3 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTD3   //!< PTD3 SPI GPIO
#endif
#if SPI0_MOSI_SEL == 6
#define SPI0_MOSI_FN               5     //!< PTD3 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTD3   //!< PTD3 SPI GPIO
#endif

// PTD4 = GPIOD_4,TPM0_4,SPI1_PCS0 (Alias: D2)
#define PTD4_GPIO_NAME             D     //!< PTD4 GPIO name
#define PTD4_GPIO_BIT              4     //!< PTD4 GPIO bit number
#define PTD4_GPIO_FN               1     //!< PTD4 Pin multiplexor for GPIO
#if TPM0_4_SEL == 2
#define PTD4_TPM_NUM               0     //!< PTD4 TPM number
#define PTD4_TPM_CH                4     //!< PTD4 TPM channel
#define PTD4_TPM_FN                4     //!< PTD4 Pin multiplexor for TPM
#endif
#if SPI1_PCS0_SEL == 2
#define SPI1_PCS0_FN               2     //!< PTD4 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTD4   //!< PTD4 SPI GPIO
#endif

// PTD5 = GPIOD_5,ADC0_6,TPM0_5,SPI1_SCK (Alias: D9)
#define PTD5_GPIO_NAME             D     //!< PTD5 GPIO name
#define PTD5_GPIO_BIT              5     //!< PTD5 GPIO bit number
#define PTD5_GPIO_FN               1     //!< PTD5 Pin multiplexor for GPIO
#define PTD5_ADC_NUM               0     //!< PTD5 ADC number
#define PTD5_ADC_CH                6     //!< PTD5 ADC channel
#define PTD5_ADC_FN                0     //!< PTD5 Pin multiplexor for ADC
#if TPM0_5_SEL == 3
#define PTD5_TPM_NUM               0     //!< PTD5 TPM number
#define PTD5_TPM_CH                5     //!< PTD5 TPM channel
#define PTD5_TPM_FN                4     //!< PTD5 Pin multiplexor for TPM
#endif
#if SPI1_SCK_SEL == 2
#define SPI1_SCK_FN                2     //!< PTD5 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTD5   //!< PTD5 SPI GPIO
#endif

// PTD6 = GPIOD_6,ADC0_7,SPI1_MOSI,SPI1_MISO (Alias: D32)
#define PTD6_GPIO_NAME             D     //!< PTD6 GPIO name
#define PTD6_GPIO_BIT              6     //!< PTD6 GPIO bit number
#define PTD6_GPIO_FN               1     //!< PTD6 Pin multiplexor for GPIO
#define PTD6_ADC_NUM               0     //!< PTD6 ADC number
#define PTD6_ADC_CH                7     //!< PTD6 ADC channel
#define PTD6_ADC_FN                0     //!< PTD6 Pin multiplexor for ADC
#if SPI1_MOSI_SEL == 3
#define SPI1_MOSI_FN               2     //!< PTD6 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTD6   //!< PTD6 SPI GPIO
#endif
#if SPI1_MISO_SEL == 3
#define SPI1_MISO_FN               5     //!< PTD6 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTD6   //!< PTD6 SPI GPIO
#endif

// PTD7 = GPIOD_7,SPI1_MISO,SPI1_MOSI (Alias: D33)
#define PTD7_GPIO_NAME             D     //!< PTD7 GPIO name
#define PTD7_GPIO_BIT              7     //!< PTD7 GPIO bit number
#define PTD7_GPIO_FN               1     //!< PTD7 Pin multiplexor for GPIO
#if SPI1_MISO_SEL == 4
#define SPI1_MISO_FN               2     //!< PTD7 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTD7   //!< PTD7 SPI GPIO
#endif
#if SPI1_MOSI_SEL == 4
#define SPI1_MOSI_FN               5     //!< PTD7 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTD7   //!< PTD7 SPI GPIO
#endif

// PTE0 = GPIOE_0,I2C1_SDA (Alias: D15)
#define PTE0_GPIO_NAME             E     //!< PTE0 GPIO name
#define PTE0_GPIO_BIT              0     //!< PTE0 GPIO bit number
#define PTE0_GPIO_FN               1     //!< PTE0 Pin multiplexor for GPIO
#if I2C1_SDA_SEL == 4
#define I2C1_SDA_FN                6     //!< PTE0 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTE0   //!< PTE0 I2C GPIO
#endif

// PTE1 = GPIOE_1,SPI1_MOSI,SPI1_MISO,I2C1_SCL (Alias: D14)
#define PTE1_GPIO_NAME             E     //!< PTE1 GPIO name
#define PTE1_GPIO_BIT              1     //!< PTE1 GPIO bit number
#define PTE1_GPIO_FN               1     //!< PTE1 Pin multiplexor for GPIO
#if SPI1_MOSI_SEL == 5
#define SPI1_MOSI_FN               2     //!< PTE1 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTE1   //!< PTE1 SPI GPIO
#endif
#if SPI1_MISO_SEL == 5
#define SPI1_MISO_FN               5     //!< PTE1 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTE1   //!< PTE1 SPI GPIO
#endif
#if I2C1_SCL_SEL == 4
#define I2C1_SCL_FN                6     //!< PTE1 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTE1   //!< PTE1 I2C GPIO
#endif

// PTE2 = GPIOE_2,SPI1_SCK (Alias: A16)
#define PTE2_GPIO_NAME             E     //!< PTE2 GPIO name
#define PTE2_GPIO_BIT              2     //!< PTE2 GPIO bit number
#define PTE2_GPIO_FN               1     //!< PTE2 Pin multiplexor for GPIO
#if SPI1_SCK_SEL == 3
#define SPI1_SCK_FN                2     //!< PTE2 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTE2   //!< PTE2 SPI GPIO
#endif

// PTE3 = GPIOE_3,SPI1_MISO,SPI1_MOSI (Alias: A15)
#define PTE3_GPIO_NAME             E     //!< PTE3 GPIO name
#define PTE3_GPIO_BIT              3     //!< PTE3 GPIO bit number
#define PTE3_GPIO_FN               1     //!< PTE3 Pin multiplexor for GPIO
#if SPI1_MISO_SEL == 6
#define SPI1_MISO_FN               2     //!< PTE3 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTE3   //!< PTE3 SPI GPIO
#endif
#if SPI1_MOSI_SEL == 6
#define SPI1_MOSI_FN               5     //!< PTE3 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTE3   //!< PTE3 SPI GPIO
#endif

// PTE4 = GPIOE_4,SPI1_PCS0 (Alias: A14)
#define PTE4_GPIO_NAME             E     //!< PTE4 GPIO name
#define PTE4_GPIO_BIT              4     //!< PTE4 GPIO bit number
#define PTE4_GPIO_FN               1     //!< PTE4 Pin multiplexor for GPIO
#if SPI1_PCS0_SEL == 3
#define SPI1_PCS0_FN               2     //!< PTE4 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTE4   //!< PTE4 SPI GPIO
#endif

// PTE5 = GPIOE_5 (Alias: A13)
#define PTE5_GPIO_NAME             E     //!< PTE5 GPIO name
#define PTE5_GPIO_BIT              5     //!< PTE5 GPIO bit number
#define PTE5_GPIO_FN               1     //!< PTE5 Pin multiplexor for GPIO

// PTE20 = GPIOE_20,ADC0_0,TPM1_0 (Alias: A11)
#define PTE20_GPIO_NAME            E     //!< PTE20 GPIO name
#define PTE20_GPIO_BIT             20    //!< PTE20 GPIO bit number
#define PTE20_GPIO_FN              1     //!< PTE20 Pin multiplexor for GPIO
#define PTE20_ADC_NUM              0     //!< PTE20 ADC number
#define PTE20_ADC_CH               0     //!< PTE20 ADC channel
#define PTE20_ADC_FN               0     //!< PTE20 Pin multiplexor for ADC
#if TPM1_0_SEL == 3
#define PTE20_TPM_NUM              1     //!< PTE20 TPM number
#define PTE20_TPM_CH               0     //!< PTE20 TPM channel
#define PTE20_TPM_FN               3     //!< PTE20 Pin multiplexor for TPM
#endif

// PTE21 = GPIOE_21,TPM1_1 (Alias: A10)
#define PTE21_GPIO_NAME            E     //!< PTE21 GPIO name
#define PTE21_GPIO_BIT             21    //!< PTE21 GPIO bit number
#define PTE21_GPIO_FN              1     //!< PTE21 Pin multiplexor for GPIO
#if TPM1_1_SEL == 3
#define PTE21_TPM_NUM              1     //!< PTE21 TPM number
#define PTE21_TPM_CH               1     //!< PTE21 TPM channel
#define PTE21_TPM_FN               3     //!< PTE21 Pin multiplexor for TPM
#endif

// PTE22 = GPIOE_22,ADC0_3,TPM2_0 (Alias: A9)
#define PTE22_GPIO_NAME            E     //!< PTE22 GPIO name
#define PTE22_GPIO_BIT             22    //!< PTE22 GPIO bit number
#define PTE22_GPIO_FN              1     //!< PTE22 Pin multiplexor for GPIO
#define PTE22_ADC_NUM              0     //!< PTE22 ADC number
#define PTE22_ADC_CH               3     //!< PTE22 ADC channel
#define PTE22_ADC_FN               0     //!< PTE22 Pin multiplexor for ADC
#if TPM2_0_SEL == 4
#define PTE22_TPM_NUM              2     //!< PTE22 TPM number
#define PTE22_TPM_CH               0     //!< PTE22 TPM channel
#define PTE22_TPM_FN               3     //!< PTE22 Pin multiplexor for TPM
#endif

// PTE23 = GPIOE_23,TPM2_1 (Alias: A8)
#define PTE23_GPIO_NAME            E     //!< PTE23 GPIO name
#define PTE23_GPIO_BIT             23    //!< PTE23 GPIO bit number
#define PTE23_GPIO_FN              1     //!< PTE23 Pin multiplexor for GPIO
#if TPM2_1_SEL == 4
#define PTE23_TPM_NUM              2     //!< PTE23 TPM number
#define PTE23_TPM_CH               1     //!< PTE23 TPM channel
#define PTE23_TPM_FN               3     //!< PTE23 Pin multiplexor for TPM
#endif

// PTE24 = GPIOE_24,TPM0_0,I2C0_SCL
#define PTE24_GPIO_NAME            E     //!< PTE24 GPIO name
#define PTE24_GPIO_BIT             24    //!< PTE24 GPIO bit number
#define PTE24_GPIO_FN              1     //!< PTE24 Pin multiplexor for GPIO
#if TPM0_0_SEL == 4
#define PTE24_TPM_NUM              0     //!< PTE24 TPM number
#define PTE24_TPM_CH               0     //!< PTE24 TPM channel
#define PTE24_TPM_FN               3     //!< PTE24 Pin multiplexor for TPM
#endif
#if I2C0_SCL_SEL == 4
#define I2C0_SCL_FN                5     //!< PTE24 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTE24   //!< PTE24 I2C GPIO
#endif

// PTE25 = GPIOE_25,TPM0_1,I2C0_SDA
#define PTE25_GPIO_NAME            E     //!< PTE25 GPIO name
#define PTE25_GPIO_BIT             25    //!< PTE25 GPIO bit number
#define PTE25_GPIO_FN              1     //!< PTE25 Pin multiplexor for GPIO
#if TPM0_1_SEL == 4
#define PTE25_TPM_NUM              0     //!< PTE25 TPM number
#define PTE25_TPM_CH               1     //!< PTE25 TPM channel
#define PTE25_TPM_FN               3     //!< PTE25 Pin multiplexor for TPM
#endif
#if I2C0_SDA_SEL == 4
#define I2C0_SDA_FN                5     //!< PTE25 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTE25   //!< PTE25 I2C GPIO
#endif

// PTE29 = GPIOE_29,ADC0_4,TPM0_2 (Alias: A7)
#define PTE29_GPIO_NAME            E     //!< PTE29 GPIO name
#define PTE29_GPIO_BIT             29    //!< PTE29 GPIO bit number
#define PTE29_GPIO_FN              1     //!< PTE29 Pin multiplexor for GPIO
#define PTE29_ADC_NUM              0     //!< PTE29 ADC number
#define PTE29_ADC_CH               4     //!< PTE29 ADC channel
#define PTE29_ADC_FN               0     //!< PTE29 Pin multiplexor for ADC
#if TPM0_2_SEL == 4
#define PTE29_TPM_NUM              0     //!< PTE29 TPM number
#define PTE29_TPM_CH               2     //!< PTE29 TPM channel
#define PTE29_TPM_FN               3     //!< PTE29 Pin multiplexor for TPM
#endif

// PTE30 = GPIOE_30,ADC0_23,TPM0_3 (Alias: A6)
#define PTE30_GPIO_NAME            E     //!< PTE30 GPIO name
#define PTE30_GPIO_BIT             30    //!< PTE30 GPIO bit number
#define PTE30_GPIO_FN              1     //!< PTE30 Pin multiplexor for GPIO
#define PTE30_ADC_NUM              0     //!< PTE30 ADC number
#define PTE30_ADC_CH               23    //!< PTE30 ADC channel
#define PTE30_ADC_FN               0     //!< PTE30 Pin multiplexor for ADC
#if TPM0_3_SEL == 3
#define PTE30_TPM_NUM              0     //!< PTE30 TPM number
#define PTE30_TPM_CH               3     //!< PTE30 TPM channel
#define PTE30_TPM_FN               3     //!< PTE30 Pin multiplexor for TPM
#endif

// PTE31 = GPIOE_31,TPM0_4 (Alias: D30)
#define PTE31_GPIO_NAME            E     //!< PTE31 GPIO name
#define PTE31_GPIO_BIT             31    //!< PTE31 GPIO bit number
#define PTE31_GPIO_FN              1     //!< PTE31 Pin multiplexor for GPIO
#if TPM0_4_SEL == 3
#define PTE31_TPM_NUM              0     //!< PTE31 TPM number
#define PTE31_TPM_CH               4     //!< PTE31 TPM channel
#define PTE31_TPM_FN               3     //!< PTE31 Pin multiplexor for TPM
#endif

#define DEFAULT_ADC_FN   0 //!< Fixed ADC Multiplexing value for pins
#define DEFAULT_GPIO_FN  1 //!< Fixed GPIO Multiplexing value for pins

#endif /* PIN_MAPPING_H_ */
