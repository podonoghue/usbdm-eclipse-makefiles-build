/**
 * @file      pin_mapping.h (derived from pin_mapping-MK20D5.h)
 * @version   1.0.0
 * @brief     Pin declarations for MK20D5
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
#define CMP_CLOCK_REG        SIM->SCGC4          
#define CMP_CLOCK_MASK       SIM_SCGC4_CMP_MASK  
#define CMT_CLOCK_REG        SIM->SCGC4          
#define CMT_CLOCK_MASK       SIM_SCGC4_CMT_MASK  
#define CRC_CLOCK_REG        SIM->SCGC6          
#define CRC_CLOCK_MASK       SIM_SCGC6_CRC_MASK  
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
#define I2C0_CLOCK_REG       SIM->SCGC4          
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK 
#define I2S0_CLOCK_REG       SIM->SCGC6          
#define I2S0_CLOCK_MASK      SIM_SCGC6_I2S0_MASK 
#define LPTMR0_CLOCK_REG     SIM->SCGC5          
#define LPTMR0_CLOCK_MASK    SIM_SCGC5_LPTMR_MASK
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
#define RTC_CLOCK_REG        SIM->SCGC6          
#define RTC_CLOCK_MASK       SIM_SCGC6_RTC_MASK  
#define SPI0_CLOCK_REG       SIM->SCGC6          
#define SPI0_CLOCK_MASK      SIM_SCGC6_SPI0_MASK 
#define TSI_CLOCK_REG        SIM->SCGC5          
#define TSI_CLOCK_MASK       SIM_SCGC5_TSI_MASK  
#define UART0_CLOCK_REG      SIM->SCGC4          
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define UART1_CLOCK_REG      SIM->SCGC4          
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define UART2_CLOCK_REG      SIM->SCGC4          
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define USBDCD_CLOCK_REG     SIM->SCGC6          
#define USBDCD_CLOCK_MASK    SIM_SCGC6_USBDCD_MASK
#define USBOTG_CLOCK_REG     SIM->SCGC4          
#define USBOTG_CLOCK_MASK    SIM_SCGC4_USBOTG_MASK
#define VREF_CLOCK_REG       SIM->SCGC4          
#define VREF_CLOCK_MASK      SIM_SCGC4_VREF_MASK 
#define PORT_CLOCK_REG       SIM->SCGC5          

// <h> Pin Peripheral mapping

// ADC0_4 maps to [Disabled, PTC2]
//   <o> ADC0_4 Pin Selection [PTC2(D10)] <constant>
//   <i> Selects which pin is used for ADC0_4
//     <0=> Disabled
//     <1=> PTC2 (Alias: D10)
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
//   <o> ADC0_6 Pin Selection [PTD5(A3)] <constant>
//   <i> Selects which pin is used for ADC0_6
//     <0=> Disabled
//     <1=> PTD5 (Alias: A3)
//     <1=> Default
#define ADC0_6_SEL           1                   

// ADC0_7 maps to [Disabled, PTD6]
//   <o> ADC0_7 Pin Selection [PTD6(A2)] <constant>
//   <i> Selects which pin is used for ADC0_7
//     <0=> Disabled
//     <1=> PTD6 (Alias: A2)
//     <1=> Default
#define ADC0_7_SEL           1                   

// ADC0_8 maps to [Disabled, PTB0]
//   <o> ADC0_8 Pin Selection [PTB0(A5,ACC_SCL)] <constant>
//   <i> Selects which pin is used for ADC0_8
//     <0=> Disabled
//     <1=> PTB0 (Alias: A5,ACC_SCL)
//     <1=> Default
#define ADC0_8_SEL           1                   

// ADC0_9 maps to [Disabled, PTB1]
//   <o> ADC0_9 Pin Selection [PTB1(A4,ACC_SDA)] <constant>
//   <i> Selects which pin is used for ADC0_9
//     <0=> Disabled
//     <1=> PTB1 (Alias: A4,ACC_SDA)
//     <1=> Default
#define ADC0_9_SEL           1                   

// ADC0_12 maps to [Disabled, PTB2]
//   <o> ADC0_12 Pin Selection [PTB2(D15)] <constant>
//   <i> Selects which pin is used for ADC0_12
//     <0=> Disabled
//     <1=> PTB2 (Alias: D15)
//     <1=> Default
#define ADC0_12_SEL          1                   

// ADC0_13 maps to [Disabled, PTB3]
//   <o> ADC0_13 Pin Selection [PTB3(D14)] <constant>
//   <i> Selects which pin is used for ADC0_13
//     <0=> Disabled
//     <1=> PTB3 (Alias: D14)
//     <1=> Default
#define ADC0_13_SEL          1                   

// ADC0_14 maps to [Disabled, PTC0]
//   <o> ADC0_14 Pin Selection [PTC0(A0)] <constant>
//   <i> Selects which pin is used for ADC0_14
//     <0=> Disabled
//     <1=> PTC0 (Alias: A0)
//     <1=> Default
#define ADC0_14_SEL          1                   

// ADC0_15 maps to [Disabled, PTC1]
//   <o> ADC0_15 Pin Selection [PTC1(A1)] <constant>
//   <i> Selects which pin is used for ADC0_15
//     <0=> Disabled
//     <1=> PTC1 (Alias: A1)
//     <1=> Default
#define ADC0_15_SEL          1                   

// ADC0_23 maps to [Disabled, ADC0_SE23]
//   <o> ADC0_23 Pin Selection [ADC0_SE23] <constant>
//   <i> Selects which pin is used for ADC0_23
//     <0=> Disabled
//     <1=> ADC0_SE23
//     <1=> Default
#define ADC0_23_SEL          1                   

// FTM0_0 maps to [Disabled, PTA3, PTC1]
//   <o> FTM0_0 Pin Selection [PTA3, PTC1(A1)] 
//   <i> Selects which pin is used for FTM0_0
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTC1 (Alias: A1)
//     <2=> Default
#define FTM0_0_SEL           2                   

// FTM0_1 maps to [Disabled, PTA4, PTC2]
//   <o> FTM0_1 Pin Selection [PTA4(D21), PTC2(D10)] 
//   <i> Selects which pin is used for FTM0_1
//     <0=> Disabled
//     <1=> PTA4 (Alias: D21)
//     <2=> PTC2 (Alias: D10)
//     <2=> Default
#define FTM0_1_SEL           2                   

// FTM0_2 maps to [Disabled, PTA5, PTC3]
//   <o> FTM0_2 Pin Selection [PTA5(D2), PTC3(D6,LED_RED)] 
//   <i> Selects which pin is used for FTM0_2
//     <0=> Disabled
//     <1=> PTA5 (Alias: D2)
//     <2=> PTC3 (Alias: D6,LED_RED)
//     <2=> Default
#define FTM0_2_SEL           2                   

// FTM0_3 maps to [Disabled, PTC4]
//   <o> FTM0_3 Pin Selection [PTC4(D7)] <constant>
//   <i> Selects which pin is used for FTM0_3
//     <0=> Disabled
//     <1=> PTC4 (Alias: D7)
//     <1=> Default
#define FTM0_3_SEL           1                   

// FTM0_4 maps to [Disabled, PTD4]
//   <o> FTM0_4 Pin Selection [PTD4(D3,LED_GREEN)] <constant>
//   <i> Selects which pin is used for FTM0_4
//     <0=> Disabled
//     <1=> PTD4 (Alias: D3,LED_GREEN)
//     <1=> Default
#define FTM0_4_SEL           1                   

// FTM0_5 maps to [Disabled, PTA0, PTD5]
//   <o> FTM0_5 Pin Selection [PTA0, PTD5(A3)] 
//   <i> Selects which pin is used for FTM0_5
//     <0=> Disabled
//     <1=> PTA0
//     <2=> PTD5 (Alias: A3)
//     <2=> Default
#define FTM0_5_SEL           2                   

// FTM0_6 maps to [Disabled, PTA1, PTD6]
//   <o> FTM0_6 Pin Selection [PTA1(D5), PTD6(A2)] 
//   <i> Selects which pin is used for FTM0_6
//     <0=> Disabled
//     <1=> PTA1 (Alias: D5)
//     <2=> PTD6 (Alias: A2)
//     <1=> Default
#define FTM0_6_SEL           1                   

// FTM0_7 maps to [Disabled, PTA2, PTD7]
//   <o> FTM0_7 Pin Selection [PTA2(D9,LED_BLUE), PTD7(D22)] 
//   <i> Selects which pin is used for FTM0_7
//     <0=> Disabled
//     <1=> PTA2 (Alias: D9,LED_BLUE)
//     <2=> PTD7 (Alias: D22)
//     <1=> Default
#define FTM0_7_SEL           1                   

// FTM1_0 maps to [Disabled, PTA12, PTB0]
//   <o> FTM1_0 Pin Selection [PTA12(D8), PTB0(A5,ACC_SCL)] 
//   <i> Selects which pin is used for FTM1_0
//     <0=> Disabled
//     <1=> PTA12 (Alias: D8)
//     <2=> PTB0 (Alias: A5,ACC_SCL)
//     <1=> Default
#define FTM1_0_SEL           1                   

// FTM1_1 maps to [Disabled, PTA13, PTB1]
//   <o> FTM1_1 Pin Selection [PTA13(D24), PTB1(A4,ACC_SDA)] 
//   <i> Selects which pin is used for FTM1_1
//     <0=> Disabled
//     <1=> PTA13 (Alias: D24)
//     <2=> PTB1 (Alias: A4,ACC_SDA)
//     <1=> Default
#define FTM1_1_SEL           1                   

// I2C0_SCL maps to [Disabled, PTB0, PTB2]
//   <o> I2C0_SCL Pin Selection [PTB0(A5,ACC_SCL), PTB2(D15)] 
//   <i> Selects which pin is used for I2C0_SCL
//     <0=> Disabled
//     <1=> PTB0 (Alias: A5,ACC_SCL)
//     <2=> PTB2 (Alias: D15)
//     <1=> Default
#define I2C0_SCL_SEL         1                   

// I2C0_SDA maps to [Disabled, PTB1, PTB3]
//   <o> I2C0_SDA Pin Selection [PTB1(A4,ACC_SDA), PTB3(D14)] 
//   <i> Selects which pin is used for I2C0_SDA
//     <0=> Disabled
//     <1=> PTB1 (Alias: A4,ACC_SDA)
//     <2=> PTB3 (Alias: D14)
//     <1=> Default
#define I2C0_SDA_SEL         1                   

// LPTMR0_1 maps to [Disabled, PTA19]
//   <o> LPTMR0_1 Pin Selection [PTA19] 
//   <i> Selects which pin is used for LPTMR0_1
//     <0=> Disabled
//     <1=> PTA19
//     <0=> Default
#define LPTMR0_1_SEL         0                   

// LPTMR0_2 maps to [Disabled, PTC5]
//   <o> LPTMR0_2 Pin Selection [PTC5(D18)] 
//   <i> Selects which pin is used for LPTMR0_2
//     <0=> Disabled
//     <1=> PTC5 (Alias: D18)
//     <0=> Default
#define LPTMR0_2_SEL         0                   

// SPI0_PCS0 maps to [Disabled, PTC4, PTD0]
//   <o> SPI0_PCS0 Pin Selection [PTC4(D7), PTD0(D16)] 
//   <i> Selects which pin is used for SPI0_PCS0
//     <0=> Disabled
//     <1=> PTC4 (Alias: D7)
//     <2=> PTD0 (Alias: D16)
//     <0=> Default
#define SPI0_PCS0_SEL        0                   

// SPI0_PCS1 maps to [Disabled, PTC3, PTD4]
//   <o> SPI0_PCS1 Pin Selection [PTC3(D6,LED_RED), PTD4(D3,LED_GREEN)] 
//   <i> Selects which pin is used for SPI0_PCS1
//     <0=> Disabled
//     <1=> PTC3 (Alias: D6,LED_RED)
//     <2=> PTD4 (Alias: D3,LED_GREEN)
//     <0=> Default
#define SPI0_PCS1_SEL        0                   

// SPI0_PCS2 maps to [Disabled, PTC2, PTD5]
//   <o> SPI0_PCS2 Pin Selection [PTC2(D10), PTD5(A3)] 
//   <i> Selects which pin is used for SPI0_PCS2
//     <0=> Disabled
//     <1=> PTC2 (Alias: D10)
//     <2=> PTD5 (Alias: A3)
//     <0=> Default
#define SPI0_PCS2_SEL        0                   

// SPI0_PCS3 maps to [Disabled, PTC1, PTD6]
//   <o> SPI0_PCS3 Pin Selection [PTC1(A1), PTD6(A2)] 
//   <i> Selects which pin is used for SPI0_PCS3
//     <0=> Disabled
//     <1=> PTC1 (Alias: A1)
//     <2=> PTD6 (Alias: A2)
//     <0=> Default
#define SPI0_PCS3_SEL        0                   

// SPI0_PCS4 maps to [Disabled, PTC0]
//   <o> SPI0_PCS4 Pin Selection [PTC0(A0)] 
//   <i> Selects which pin is used for SPI0_PCS4
//     <0=> Disabled
//     <1=> PTC0 (Alias: A0)
//     <0=> Default
#define SPI0_PCS4_SEL        0                   

// SPI0_SCK maps to [Disabled, PTC5, PTD1]
//   <o> SPI0_SCK Pin Selection [PTC5(D18), PTD1(D13)] 
//   <i> Selects which pin is used for SPI0_SCK
//     <0=> Disabled
//     <1=> PTC5 (Alias: D18)
//     <2=> PTD1 (Alias: D13)
//     <2=> Default
#define SPI0_SCK_SEL         2                   

// SPI0_SIN maps to [Disabled, PTC7, PTD3]
//   <o> SPI0_SIN Pin Selection [PTC7(D20), PTD3(D12)] 
//   <i> Selects which pin is used for SPI0_SIN
//     <0=> Disabled
//     <1=> PTC7 (Alias: D20)
//     <2=> PTD3 (Alias: D12)
//     <2=> Default
#define SPI0_SIN_SEL         2                   

// SPI0_SOUT maps to [Disabled, PTC6, PTD2]
//   <o> SPI0_SOUT Pin Selection [PTC6(ACC_INT2,D19), PTD2(D11)] 
//   <i> Selects which pin is used for SPI0_SOUT
//     <0=> Disabled
//     <1=> PTC6 (Alias: ACC_INT2,D19)
//     <2=> PTD2 (Alias: D11)
//     <2=> Default
#define SPI0_SOUT_SEL        2                   

// </h>

// ADC0_DM0

// ADC0_DM3

// ADC0_DP0

// ADC0_DP3

// ADC0_SE23 = ADC0_23
#define ADC0_SE23_ADC_NUM          0     //!< ADC0_SE23 ADC number
#define ADC0_SE23_ADC_CH           23    //!< ADC0_SE23 ADC channel
#define ADC0_SE23_ADC_FN           0     //!< ADC0_SE23 Pin multiplexor for ADC

// PTA0 = GPIOA_0,FTM0_5
#define PTA0_GPIO_NAME             A     //!< PTA0 GPIO name
#define PTA0_GPIO_BIT              0     //!< PTA0 GPIO bit number
#define PTA0_GPIO_FN               1     //!< PTA0 Pin multiplexor for GPIO
#if FTM0_5_SEL == 1
#define PTA0_FTM_NUM               0     //!< PTA0 FTM number
#define PTA0_FTM_CH                5     //!< PTA0 FTM channel
#define PTA0_FTM_FN                3     //!< PTA0 Pin multiplexor for FTM
#endif

// PTA1 = GPIOA_1,FTM0_6 (Alias: D5)
#define PTA1_GPIO_NAME             A     //!< PTA1 GPIO name
#define PTA1_GPIO_BIT              1     //!< PTA1 GPIO bit number
#define PTA1_GPIO_FN               1     //!< PTA1 Pin multiplexor for GPIO
#if FTM0_6_SEL == 1
#define PTA1_FTM_NUM               0     //!< PTA1 FTM number
#define PTA1_FTM_CH                6     //!< PTA1 FTM channel
#define PTA1_FTM_FN                3     //!< PTA1 Pin multiplexor for FTM
#endif

// PTA2 = GPIOA_2,FTM0_7 (Alias: D9,LED_BLUE)
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

// PTA4 = GPIOA_4,FTM0_1 (Alias: D21)
#define PTA4_GPIO_NAME             A     //!< PTA4 GPIO name
#define PTA4_GPIO_BIT              4     //!< PTA4 GPIO bit number
#define PTA4_GPIO_FN               1     //!< PTA4 Pin multiplexor for GPIO
#if FTM0_1_SEL == 1
#define PTA4_FTM_NUM               0     //!< PTA4 FTM number
#define PTA4_FTM_CH                1     //!< PTA4 FTM channel
#define PTA4_FTM_FN                3     //!< PTA4 Pin multiplexor for FTM
#endif

// PTA5 = GPIOA_5,FTM0_2 (Alias: D2)
#define PTA5_GPIO_NAME             A     //!< PTA5 GPIO name
#define PTA5_GPIO_BIT              5     //!< PTA5 GPIO bit number
#define PTA5_GPIO_FN               1     //!< PTA5 Pin multiplexor for GPIO
#if FTM0_2_SEL == 1
#define PTA5_FTM_NUM               0     //!< PTA5 FTM number
#define PTA5_FTM_CH                2     //!< PTA5 FTM channel
#define PTA5_FTM_FN                3     //!< PTA5 Pin multiplexor for FTM
#endif

// PTA12 = GPIOA_12,FTM1_0 (Alias: D8)
#define PTA12_GPIO_NAME            A     //!< PTA12 GPIO name
#define PTA12_GPIO_BIT             12    //!< PTA12 GPIO bit number
#define PTA12_GPIO_FN              1     //!< PTA12 Pin multiplexor for GPIO
#if FTM1_0_SEL == 1
#define PTA12_FTM_NUM              1     //!< PTA12 FTM number
#define PTA12_FTM_CH               0     //!< PTA12 FTM channel
#define PTA12_FTM_FN               3     //!< PTA12 Pin multiplexor for FTM
#endif

// PTA13 = GPIOA_13,FTM1_1 (Alias: D24)
#define PTA13_GPIO_NAME            A     //!< PTA13 GPIO name
#define PTA13_GPIO_BIT             13    //!< PTA13 GPIO bit number
#define PTA13_GPIO_FN              1     //!< PTA13 Pin multiplexor for GPIO
#if FTM1_1_SEL == 1
#define PTA13_FTM_NUM              1     //!< PTA13 FTM number
#define PTA13_FTM_CH               1     //!< PTA13 FTM channel
#define PTA13_FTM_FN               3     //!< PTA13 Pin multiplexor for FTM
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

// PTB0 = GPIOB_0,ADC0_8,FTM1_0,I2C0_SCL (Alias: A5,ACC_SCL)
#define PTB0_GPIO_NAME             B     //!< PTB0 GPIO name
#define PTB0_GPIO_BIT              0     //!< PTB0 GPIO bit number
#define PTB0_GPIO_FN               1     //!< PTB0 Pin multiplexor for GPIO
#define PTB0_ADC_NUM               0     //!< PTB0 ADC number
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

// PTB1 = GPIOB_1,ADC0_9,FTM1_1,I2C0_SDA (Alias: A4,ACC_SDA)
#define PTB1_GPIO_NAME             B     //!< PTB1 GPIO name
#define PTB1_GPIO_BIT              1     //!< PTB1 GPIO bit number
#define PTB1_GPIO_FN               1     //!< PTB1 Pin multiplexor for GPIO
#define PTB1_ADC_NUM               0     //!< PTB1 ADC number
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

// PTB2 = GPIOB_2,ADC0_12,I2C0_SCL (Alias: D15)
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

// PTB3 = GPIOB_3,ADC0_13,I2C0_SDA (Alias: D14)
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

// PTB16 = GPIOB_16
#define PTB16_GPIO_NAME            B     //!< PTB16 GPIO name
#define PTB16_GPIO_BIT             16    //!< PTB16 GPIO bit number
#define PTB16_GPIO_FN              1     //!< PTB16 Pin multiplexor for GPIO

// PTB17 = GPIOB_17
#define PTB17_GPIO_NAME            B     //!< PTB17 GPIO name
#define PTB17_GPIO_BIT             17    //!< PTB17 GPIO bit number
#define PTB17_GPIO_FN              1     //!< PTB17 Pin multiplexor for GPIO

// PTB18 = GPIOB_18
#define PTB18_GPIO_NAME            B     //!< PTB18 GPIO name
#define PTB18_GPIO_BIT             18    //!< PTB18 GPIO bit number
#define PTB18_GPIO_FN              1     //!< PTB18 Pin multiplexor for GPIO

// PTB19 = GPIOB_19
#define PTB19_GPIO_NAME            B     //!< PTB19 GPIO name
#define PTB19_GPIO_BIT             19    //!< PTB19 GPIO bit number
#define PTB19_GPIO_FN              1     //!< PTB19 Pin multiplexor for GPIO

// PTC0 = GPIOC_0,ADC0_14,SPI0_PCS4 (Alias: A0)
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

// PTC1 = GPIOC_1,ADC0_15,FTM0_0,SPI0_PCS3 (Alias: A1)
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

// PTC2 = GPIOC_2,ADC0_4,FTM0_1,SPI0_PCS2 (Alias: D10)
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

// PTC3 = GPIOC_3,FTM0_2,SPI0_PCS1 (Alias: D6,LED_RED)
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

// PTC4 = GPIOC_4,FTM0_3,SPI0_PCS0 (Alias: D7)
#define PTC4_GPIO_NAME             C     //!< PTC4 GPIO name
#define PTC4_GPIO_BIT              4     //!< PTC4 GPIO bit number
#define PTC4_GPIO_FN               1     //!< PTC4 Pin multiplexor for GPIO
#define PTC4_FTM_NUM               0     //!< PTC4 FTM number
#define PTC4_FTM_CH                3     //!< PTC4 FTM channel
#define PTC4_FTM_FN                4     //!< PTC4 Pin multiplexor for FTM
#if SPI0_PCS0_SEL == 1
#define SPI0_PCS0_FN               2     //!< PTC4 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTC4   //!< PTC4 SPI GPIO
#endif

// PTC5 = GPIOC_5,LPTMR0_2,SPI0_SCK (Alias: D18)
#define PTC5_GPIO_NAME             C     //!< PTC5 GPIO name
#define PTC5_GPIO_BIT              5     //!< PTC5 GPIO bit number
#define PTC5_GPIO_FN               1     //!< PTC5 Pin multiplexor for GPIO
#if LPTMR0_2_SEL == 1
#define LPTMR0_2_FN                3     //!< PTC5 Pin multiplexor for LPTMR
#define LPTMR0_2_GPIO              digitalIO_PTC5   //!< PTC5 LPTMR GPIO
#endif
#if SPI0_SCK_SEL == 1
#define SPI0_SCK_FN                2     //!< PTC5 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTC5   //!< PTC5 SPI GPIO
#endif

// PTC6 = GPIOC_6,SPI0_SOUT (Alias: ACC_INT2,D19)
#define PTC6_GPIO_NAME             C     //!< PTC6 GPIO name
#define PTC6_GPIO_BIT              6     //!< PTC6 GPIO bit number
#define PTC6_GPIO_FN               1     //!< PTC6 Pin multiplexor for GPIO
#if SPI0_SOUT_SEL == 1
#define SPI0_SOUT_FN               2     //!< PTC6 Pin multiplexor for SPI
#define SPI0_SOUT_GPIO             digitalIO_PTC6   //!< PTC6 SPI GPIO
#endif

// PTC7 = GPIOC_7,SPI0_SIN (Alias: D20)
#define PTC7_GPIO_NAME             C     //!< PTC7 GPIO name
#define PTC7_GPIO_BIT              7     //!< PTC7 GPIO bit number
#define PTC7_GPIO_FN               1     //!< PTC7 Pin multiplexor for GPIO
#if SPI0_SIN_SEL == 1
#define SPI0_SIN_FN                2     //!< PTC7 Pin multiplexor for SPI
#define SPI0_SIN_GPIO              digitalIO_PTC7   //!< PTC7 SPI GPIO
#endif

// PTC8 = GPIOC_8 (Alias: D4)
#define PTC8_GPIO_NAME             C     //!< PTC8 GPIO name
#define PTC8_GPIO_BIT              8     //!< PTC8 GPIO bit number
#define PTC8_GPIO_FN               1     //!< PTC8 Pin multiplexor for GPIO

// PTC9 = GPIOC_9 (Alias: D23)
#define PTC9_GPIO_NAME             C     //!< PTC9 GPIO name
#define PTC9_GPIO_BIT              9     //!< PTC9 GPIO bit number
#define PTC9_GPIO_FN               1     //!< PTC9 Pin multiplexor for GPIO

// PTC10 = GPIOC_10 (Alias: D25)
#define PTC10_GPIO_NAME            C     //!< PTC10 GPIO name
#define PTC10_GPIO_BIT             10    //!< PTC10 GPIO bit number
#define PTC10_GPIO_FN              1     //!< PTC10 Pin multiplexor for GPIO

// PTC11 = GPIOC_11 (Alias: ACC_INT1,D17)
#define PTC11_GPIO_NAME            C     //!< PTC11 GPIO name
#define PTC11_GPIO_BIT             11    //!< PTC11 GPIO bit number
#define PTC11_GPIO_FN              1     //!< PTC11 Pin multiplexor for GPIO

// PTD0 = GPIOD_0,SPI0_PCS0 (Alias: D16)
#define PTD0_GPIO_NAME             D     //!< PTD0 GPIO name
#define PTD0_GPIO_BIT              0     //!< PTD0 GPIO bit number
#define PTD0_GPIO_FN               1     //!< PTD0 Pin multiplexor for GPIO
#if SPI0_PCS0_SEL == 2
#define SPI0_PCS0_FN               2     //!< PTD0 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTD0   //!< PTD0 SPI GPIO
#endif

// PTD1 = GPIOD_1,ADC0_5,SPI0_SCK (Alias: D13)
#define PTD1_GPIO_NAME             D     //!< PTD1 GPIO name
#define PTD1_GPIO_BIT              1     //!< PTD1 GPIO bit number
#define PTD1_GPIO_FN               1     //!< PTD1 Pin multiplexor for GPIO
#define PTD1_ADC_NUM               0     //!< PTD1 ADC number
#define PTD1_ADC_CH                5     //!< PTD1 ADC channel
#define PTD1_ADC_FN                0     //!< PTD1 Pin multiplexor for ADC
#if SPI0_SCK_SEL == 2
#define SPI0_SCK_FN                2     //!< PTD1 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTD1   //!< PTD1 SPI GPIO
#endif

// PTD2 = GPIOD_2,SPI0_SOUT (Alias: D11)
#define PTD2_GPIO_NAME             D     //!< PTD2 GPIO name
#define PTD2_GPIO_BIT              2     //!< PTD2 GPIO bit number
#define PTD2_GPIO_FN               1     //!< PTD2 Pin multiplexor for GPIO
#if SPI0_SOUT_SEL == 2
#define SPI0_SOUT_FN               2     //!< PTD2 Pin multiplexor for SPI
#define SPI0_SOUT_GPIO             digitalIO_PTD2   //!< PTD2 SPI GPIO
#endif

// PTD3 = GPIOD_3,SPI0_SIN (Alias: D12)
#define PTD3_GPIO_NAME             D     //!< PTD3 GPIO name
#define PTD3_GPIO_BIT              3     //!< PTD3 GPIO bit number
#define PTD3_GPIO_FN               1     //!< PTD3 Pin multiplexor for GPIO
#if SPI0_SIN_SEL == 2
#define SPI0_SIN_FN                2     //!< PTD3 Pin multiplexor for SPI
#define SPI0_SIN_GPIO              digitalIO_PTD3   //!< PTD3 SPI GPIO
#endif

// PTD4 = GPIOD_4,FTM0_4,SPI0_PCS1 (Alias: D3,LED_GREEN)
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

// PTD5 = GPIOD_5,ADC0_6,FTM0_5,SPI0_PCS2 (Alias: A3)
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

// PTD6 = GPIOD_6,ADC0_7,FTM0_6,SPI0_PCS3 (Alias: A2)
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

// PTD7 = GPIOD_7,FTM0_7 (Alias: D22)
#define PTD7_GPIO_NAME             D     //!< PTD7 GPIO name
#define PTD7_GPIO_BIT              7     //!< PTD7 GPIO bit number
#define PTD7_GPIO_FN               1     //!< PTD7 Pin multiplexor for GPIO
#if FTM0_7_SEL == 2
#define PTD7_FTM_NUM               0     //!< PTD7 FTM number
#define PTD7_FTM_CH                7     //!< PTD7 FTM channel
#define PTD7_FTM_FN                4     //!< PTD7 Pin multiplexor for FTM
#endif

// PTE0 = GPIOE_0 (Alias: D1)
#define PTE0_GPIO_NAME             E     //!< PTE0 GPIO name
#define PTE0_GPIO_BIT              0     //!< PTE0 GPIO bit number
#define PTE0_GPIO_FN               1     //!< PTE0 Pin multiplexor for GPIO

// PTE1 = GPIOE_1 (Alias: D0)
#define PTE1_GPIO_NAME             E     //!< PTE1 GPIO name
#define PTE1_GPIO_BIT              1     //!< PTE1 GPIO bit number
#define PTE1_GPIO_FN               1     //!< PTE1 Pin multiplexor for GPIO

#define DEFAULT_ADC_FN   0 //!< Fixed ADC Multiplexing value for pins
#define DEFAULT_GPIO_FN  1 //!< Fixed GPIO Multiplexing value for pins

#endif /* PIN_MAPPING_H_ */
