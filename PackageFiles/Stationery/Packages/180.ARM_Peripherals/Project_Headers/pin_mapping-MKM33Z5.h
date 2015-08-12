/**
 * @file      pin_mapping.h (derived from pin_mapping-MKM33Z5.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKM33Z5
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

#define ADC0_CLOCK_REG       SIM->SCGC6          
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC_MASK  
#define AFE_CLOCK_REG        SIM->SCGC6          
#define AFE_CLOCK_MASK       SIM_SCGC6_AFE_MASK  
#define CMP0_CLOCK_REG       SIM->SCGC4          
#define CMP0_CLOCK_MASK      SIM_SCGC4_CMP0_MASK 
#define CMP1_CLOCK_REG       SIM->SCGC4          
#define CMP1_CLOCK_MASK      SIM_SCGC4_CMP1_MASK 
#define CRC_CLOCK_REG        SIM->SCGC6          
#define CRC_CLOCK_MASK       SIM_SCGC6_CRC_MASK  
#define DMA_CLOCK_REG        SIM->SCGC7          
#define DMA_CLOCK_MASK       SIM_SCGC7_DMA_MASK  
#define DMAMUX0_CLOCK_REG    SIM->SCGC6          
#define DMAMUX0_CLOCK_MASK   SIM_SCGC6_DMAMUX0_MASK
#define DMAMUX1_CLOCK_REG    SIM->SCGC6          
#define DMAMUX1_CLOCK_MASK   SIM_SCGC6_DMAMUX1_MASK
#define DMAMUX2_CLOCK_REG    SIM->SCGC6          
#define DMAMUX2_CLOCK_MASK   SIM_SCGC6_DMAMUX2_MASK
#define DMAMUX3_CLOCK_REG    SIM->SCGC6          
#define DMAMUX3_CLOCK_MASK   SIM_SCGC6_DMAMUX3_MASK
#define EWM_CLOCK_REG        SIM->SCGC4          
#define EWM_CLOCK_MASK       SIM_SCGC4_EWM_MASK  
#define I2C0_CLOCK_REG       SIM->SCGC4          
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK 
#define I2C1_CLOCK_REG       SIM->SCGC4          
#define I2C1_CLOCK_MASK      SIM_SCGC4_I2C1_MASK 
#define IRTC_CLOCK_REG       SIM->SCGC5          
#define IRTC_CLOCK_MASK      SIM_SCGC5_IRTC_MASK 
#define IRTCREGFILE_CLOCK_REG SIM->SCGC5          
#define IRTCREGFILE_CLOCK_MASK SIM_SCGC5_IRTCREGFILE_MASK
#define LPTMR0_CLOCK_REG     SIM->SCGC6          
#define LPTMR0_CLOCK_MASK    SIM_SCGC6_LPTMR_MASK
#define MCG_CLOCK_REG        SIM->SCGC4          
#define MCG_CLOCK_MASK       SIM_SCGC4_MCG_MASK  
#define MPU_CLOCK_REG        SIM->SCGC7          
#define MPU_CLOCK_MASK       SIM_SCGC7_MPU_MASK  
#define OSC_CLOCK_REG        SIM->SCGC4          
#define OSC_CLOCK_MASK       SIM_SCGC4_OSC_MASK  
#define PIT0_CLOCK_REG       SIM->SCGC6          
#define PIT0_CLOCK_MASK      SIM_SCGC6_PIT0_MASK 
#define PIT1_CLOCK_REG       SIM->SCGC6          
#define PIT1_CLOCK_MASK      SIM_SCGC6_PIT1_MASK 
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
#define PORTF_CLOCK_REG      SIM->SCGC5          
#define PORTF_CLOCK_MASK     SIM_SCGC5_PORTF_MASK
#define PORTG_CLOCK_REG      SIM->SCGC5          
#define PORTG_CLOCK_MASK     SIM_SCGC5_PORTG_MASK
#define PORTH_CLOCK_REG      SIM->SCGC5          
#define PORTH_CLOCK_MASK     SIM_SCGC5_PORTH_MASK
#define PORTI_CLOCK_REG      SIM->SCGC5          
#define PORTI_CLOCK_MASK     SIM_SCGC5_PORTI_MASK
#define RNGA_CLOCK_REG       SIM->SCGC6          
#define RNGA_CLOCK_MASK      SIM_SCGC6_RNGA_MASK 
#define SIM_HP_CLOCK_REG     SIM->SCGC6          
#define SIM_HP_CLOCK_MASK    SIM_SCGC6_SIM_HP_MASK
#define SIM_LP_CLOCK_REG     SIM->SCGC6          
#define SIM_LP_CLOCK_MASK    SIM_SCGC6_SIM_LP_MASK
#define SLCD_CLOCK_REG       SIM->SCGC5          
#define SLCD_CLOCK_MASK      SIM_SCGC5_SLCD_MASK 
#define SPI0_CLOCK_REG       SIM->SCGC4          
#define SPI0_CLOCK_MASK      SIM_SCGC4_SPI0_MASK 
#define SPI1_CLOCK_REG       SIM->SCGC4          
#define SPI1_CLOCK_MASK      SIM_SCGC4_SPI1_MASK 
#define TMR0_CLOCK_REG       SIM->SCGC5          
#define TMR0_CLOCK_MASK      SIM_SCGC5_TMR0_MASK 
#define TMR1_CLOCK_REG       SIM->SCGC5          
#define TMR1_CLOCK_MASK      SIM_SCGC5_TMR1_MASK 
#define TMR2_CLOCK_REG       SIM->SCGC5          
#define TMR2_CLOCK_MASK      SIM_SCGC5_TMR2_MASK 
#define TMR3_CLOCK_REG       SIM->SCGC5          
#define TMR3_CLOCK_MASK      SIM_SCGC5_TMR3_MASK 
#define UART0_CLOCK_REG      SIM->SCGC4          
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define UART1_CLOCK_REG      SIM->SCGC4          
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define UART2_CLOCK_REG      SIM->SCGC4          
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define UART3_CLOCK_REG      SIM->SCGC4          
#define UART3_CLOCK_MASK     SIM_SCGC4_UART3_MASK
#define VREF_CLOCK_REG       SIM->SCGC4          
#define VREF_CLOCK_MASK      SIM_SCGC4_VREF_MASK 
#define WDOG_CLOCK_REG       SIM->SCGC5          
#define WDOG_CLOCK_MASK      SIM_SCGC5_WDOG_MASK 
#define XBAR_CLOCK_REG       SIM->SCGC5          
#define XBAR_CLOCK_MASK      SIM_SCGC5_XBAR_MASK 
#define PORT_CLOCK_REG       SIM->SCGC5          

// <h> Pin Peripheral mapping

// ADC0_0 maps to [Disabled, PTC5]
//   <o> ADC0_0 Pin Selection [PTC5] <constant>
//   <i> Selects which pin is used for ADC0_0
//     <0=> Disabled
//     <1=> PTC5
//     <1=> Default
#define ADC0_0_SEL           1                   

// ADC0_1 maps to [Disabled, PTC6]
//   <o> ADC0_1 Pin Selection [PTC6] <constant>
//   <i> Selects which pin is used for ADC0_1
//     <0=> Disabled
//     <1=> PTC6
//     <1=> Default
#define ADC0_1_SEL           1                   

// ADC0_2 maps to [Disabled, PTC7]
//   <o> ADC0_2 Pin Selection [PTC7] <constant>
//   <i> Selects which pin is used for ADC0_2
//     <0=> Disabled
//     <1=> PTC7
//     <1=> Default
#define ADC0_2_SEL           1                   

// ADC0_3 maps to [Disabled, PTD4]
//   <o> ADC0_3 Pin Selection [PTD4] <constant>
//   <i> Selects which pin is used for ADC0_3
//     <0=> Disabled
//     <1=> PTD4
//     <1=> Default
#define ADC0_3_SEL           1                   

// ADC0_4 maps to [Disabled, PTD5]
//   <o> ADC0_4 Pin Selection [PTD5] <constant>
//   <i> Selects which pin is used for ADC0_4
//     <0=> Disabled
//     <1=> PTD5
//     <1=> Default
#define ADC0_4_SEL           1                   

// ADC0_5 maps to [Disabled, PTD6]
//   <o> ADC0_5 Pin Selection [PTD6] <constant>
//   <i> Selects which pin is used for ADC0_5
//     <0=> Disabled
//     <1=> PTD6
//     <1=> Default
#define ADC0_5_SEL           1                   

// ADC0_6 maps to [Disabled, PTE7]
//   <o> ADC0_6 Pin Selection [PTE7] <constant>
//   <i> Selects which pin is used for ADC0_6
//     <0=> Disabled
//     <1=> PTE7
//     <1=> Default
#define ADC0_6_SEL           1                   

// ADC0_7 maps to [Disabled, PTF0]
//   <o> ADC0_7 Pin Selection [PTF0] <constant>
//   <i> Selects which pin is used for ADC0_7
//     <0=> Disabled
//     <1=> PTF0
//     <1=> Default
#define ADC0_7_SEL           1                   

// ADC0_8 maps to [Disabled, PTF1]
//   <o> ADC0_8 Pin Selection [PTF1] <constant>
//   <i> Selects which pin is used for ADC0_8
//     <0=> Disabled
//     <1=> PTF1
//     <1=> Default
#define ADC0_8_SEL           1                   

// ADC0_9 maps to [Disabled, PTF2]
//   <o> ADC0_9 Pin Selection [PTF2] <constant>
//   <i> Selects which pin is used for ADC0_9
//     <0=> Disabled
//     <1=> PTF2
//     <1=> Default
#define ADC0_9_SEL           1                   

// ADC0_10 maps to [Disabled, PTG1]
//   <o> ADC0_10 Pin Selection [PTG1] <constant>
//   <i> Selects which pin is used for ADC0_10
//     <0=> Disabled
//     <1=> PTG1
//     <1=> Default
#define ADC0_10_SEL          1                   

// ADC0_11 maps to [Disabled, PTG2]
//   <o> ADC0_11 Pin Selection [PTG2] <constant>
//   <i> Selects which pin is used for ADC0_11
//     <0=> Disabled
//     <1=> PTG2
//     <1=> Default
#define ADC0_11_SEL          1                   

// I2C0_SCL maps to [Disabled, PTD7, PTE6, PTG3]
//   <o> I2C0_SCL Pin Selection [PTD7, PTE6, PTG3] 
//   <i> Selects which pin is used for I2C0_SCL
//     <0=> Disabled
//     <1=> PTD7
//     <2=> PTE6
//     <3=> PTG3
//     <0=> Default
#define I2C0_SCL_SEL         0                   

// I2C0_SDA maps to [Disabled, PTE0, PTE7, PTG4]
//   <o> I2C0_SDA Pin Selection [PTE0, PTE7, PTG4] 
//   <i> Selects which pin is used for I2C0_SDA
//     <0=> Disabled
//     <1=> PTE0
//     <2=> PTE7
//     <3=> PTG4
//     <0=> Default
#define I2C0_SDA_SEL         0                   

// I2C1_SDA maps to [Disabled, PTE2, PTF6]
//   <o> I2C1_SDA Pin Selection [PTE2, PTF6] 
//   <i> Selects which pin is used for I2C1_SDA
//     <0=> Disabled
//     <1=> PTE2
//     <2=> PTF6
//     <0=> Default
#define I2C1_SDA_SEL         0                   

// I2C1_SCL maps to [Disabled, PTE3, PTF5]
//   <o> I2C1_SCL Pin Selection [PTE3, PTF5] 
//   <i> Selects which pin is used for I2C1_SCL
//     <0=> Disabled
//     <1=> PTE3
//     <2=> PTF5
//     <0=> Default
#define I2C1_SCL_SEL         0                   

// SPI0_MISO maps to [Disabled, PTD4, PTG5]
//   <o> SPI0_MISO Pin Selection [PTD4, PTG5] 
//   <i> Selects which pin is used for SPI0_MISO
//     <0=> Disabled
//     <1=> PTD4
//     <2=> PTG5
//     <0=> Default
#define SPI0_MISO_SEL        0                   

// SPI0_MOSI maps to [Disabled, PTD3, PTG4]
//   <o> SPI0_MOSI Pin Selection [PTD3, PTG4] 
//   <i> Selects which pin is used for SPI0_MOSI
//     <0=> Disabled
//     <1=> PTD3
//     <2=> PTG4
//     <0=> Default
#define SPI0_MOSI_SEL        0                   

// SPI0_SCK maps to [Disabled, PTD2, PTG3]
//   <o> SPI0_SCK Pin Selection [PTD2, PTG3] 
//   <i> Selects which pin is used for SPI0_SCK
//     <0=> Disabled
//     <1=> PTD2
//     <2=> PTG3
//     <0=> Default
#define SPI0_SCK_SEL         0                   

// SPI1_MISO maps to [Disabled, PTF5, PTI0, PTI1]
//   <o> SPI1_MISO Pin Selection [PTF5, PTI0, PTI1] 
//   <i> Selects which pin is used for SPI1_MISO
//     <0=> Disabled
//     <1=> PTF5
//     <2=> PTI0
//     <3=> PTI1
//     <0=> Default
#define SPI1_MISO_SEL        0                   

// SPI1_MOSI maps to [Disabled, PTF6, PTI0, PTI1]
//   <o> SPI1_MOSI Pin Selection [PTF6, PTI0, PTI1] 
//   <i> Selects which pin is used for SPI1_MOSI
//     <0=> Disabled
//     <1=> PTF6
//     <2=> PTI0
//     <3=> PTI1
//     <0=> Default
#define SPI1_MOSI_SEL        0                   

// SPI1_SCK maps to [Disabled, PTF4, PTH7]
//   <o> SPI1_SCK Pin Selection [PTF4, PTH7] 
//   <i> Selects which pin is used for SPI1_SCK
//     <0=> Disabled
//     <1=> PTF4
//     <2=> PTH7
//     <0=> Default
#define SPI1_SCK_SEL         0                   

// </h>

// PTA0 = GPIOA_0
#define PTA0_GPIO_NAME             A     //!< PTA0 GPIO name
#define PTA0_GPIO_BIT              0     //!< PTA0 GPIO bit number
#define PTA0_GPIO_FN               1     //!< PTA0 Pin multiplexor for GPIO

// PTA1 = GPIOA_1
#define PTA1_GPIO_NAME             A     //!< PTA1 GPIO name
#define PTA1_GPIO_BIT              1     //!< PTA1 GPIO bit number
#define PTA1_GPIO_FN               1     //!< PTA1 Pin multiplexor for GPIO

// PTA2 = GPIOA_2
#define PTA2_GPIO_NAME             A     //!< PTA2 GPIO name
#define PTA2_GPIO_BIT              2     //!< PTA2 GPIO bit number
#define PTA2_GPIO_FN               1     //!< PTA2 Pin multiplexor for GPIO

// PTA3 = GPIOA_3
#define PTA3_GPIO_NAME             A     //!< PTA3 GPIO name
#define PTA3_GPIO_BIT              3     //!< PTA3 GPIO bit number
#define PTA3_GPIO_FN               1     //!< PTA3 Pin multiplexor for GPIO

// PTA4 = GPIOA_4
#define PTA4_GPIO_NAME             A     //!< PTA4 GPIO name
#define PTA4_GPIO_BIT              4     //!< PTA4 GPIO bit number
#define PTA4_GPIO_FN               1     //!< PTA4 Pin multiplexor for GPIO

// PTA5 = GPIOA_5
#define PTA5_GPIO_NAME             A     //!< PTA5 GPIO name
#define PTA5_GPIO_BIT              5     //!< PTA5 GPIO bit number
#define PTA5_GPIO_FN               1     //!< PTA5 Pin multiplexor for GPIO

// PTA6 = GPIOA_6
#define PTA6_GPIO_NAME             A     //!< PTA6 GPIO name
#define PTA6_GPIO_BIT              6     //!< PTA6 GPIO bit number
#define PTA6_GPIO_FN               1     //!< PTA6 Pin multiplexor for GPIO

// PTA7 = GPIOA_7
#define PTA7_GPIO_NAME             A     //!< PTA7 GPIO name
#define PTA7_GPIO_BIT              7     //!< PTA7 GPIO bit number
#define PTA7_GPIO_FN               1     //!< PTA7 Pin multiplexor for GPIO

// PTB0 = GPIOB_0
#define PTB0_GPIO_NAME             B     //!< PTB0 GPIO name
#define PTB0_GPIO_BIT              0     //!< PTB0 GPIO bit number
#define PTB0_GPIO_FN               1     //!< PTB0 Pin multiplexor for GPIO

// PTB1 = GPIOB_1
#define PTB1_GPIO_NAME             B     //!< PTB1 GPIO name
#define PTB1_GPIO_BIT              1     //!< PTB1 GPIO bit number
#define PTB1_GPIO_FN               1     //!< PTB1 Pin multiplexor for GPIO

// PTB2 = GPIOB_2
#define PTB2_GPIO_NAME             B     //!< PTB2 GPIO name
#define PTB2_GPIO_BIT              2     //!< PTB2 GPIO bit number
#define PTB2_GPIO_FN               1     //!< PTB2 Pin multiplexor for GPIO

// PTB3 = GPIOB_3
#define PTB3_GPIO_NAME             B     //!< PTB3 GPIO name
#define PTB3_GPIO_BIT              3     //!< PTB3 GPIO bit number
#define PTB3_GPIO_FN               1     //!< PTB3 Pin multiplexor for GPIO

// PTB4 = GPIOB_4
#define PTB4_GPIO_NAME             B     //!< PTB4 GPIO name
#define PTB4_GPIO_BIT              4     //!< PTB4 GPIO bit number
#define PTB4_GPIO_FN               1     //!< PTB4 Pin multiplexor for GPIO

// PTB5 = GPIOB_5
#define PTB5_GPIO_NAME             B     //!< PTB5 GPIO name
#define PTB5_GPIO_BIT              5     //!< PTB5 GPIO bit number
#define PTB5_GPIO_FN               1     //!< PTB5 Pin multiplexor for GPIO

// PTB6 = GPIOB_6
#define PTB6_GPIO_NAME             B     //!< PTB6 GPIO name
#define PTB6_GPIO_BIT              6     //!< PTB6 GPIO bit number
#define PTB6_GPIO_FN               1     //!< PTB6 Pin multiplexor for GPIO

// PTB7 = GPIOB_7
#define PTB7_GPIO_NAME             B     //!< PTB7 GPIO name
#define PTB7_GPIO_BIT              7     //!< PTB7 GPIO bit number
#define PTB7_GPIO_FN               1     //!< PTB7 Pin multiplexor for GPIO

// PTC0 = GPIOC_0
#define PTC0_GPIO_NAME             C     //!< PTC0 GPIO name
#define PTC0_GPIO_BIT              0     //!< PTC0 GPIO bit number
#define PTC0_GPIO_FN               1     //!< PTC0 Pin multiplexor for GPIO

// PTC1 = GPIOC_1
#define PTC1_GPIO_NAME             C     //!< PTC1 GPIO name
#define PTC1_GPIO_BIT              1     //!< PTC1 GPIO bit number
#define PTC1_GPIO_FN               1     //!< PTC1 Pin multiplexor for GPIO

// PTC2 = GPIOC_2
#define PTC2_GPIO_NAME             C     //!< PTC2 GPIO name
#define PTC2_GPIO_BIT              2     //!< PTC2 GPIO bit number
#define PTC2_GPIO_FN               1     //!< PTC2 Pin multiplexor for GPIO

// PTC3 = GPIOC_3
#define PTC3_GPIO_NAME             C     //!< PTC3 GPIO name
#define PTC3_GPIO_BIT              3     //!< PTC3 GPIO bit number
#define PTC3_GPIO_FN               1     //!< PTC3 Pin multiplexor for GPIO

// PTC4 = GPIOC_4
#define PTC4_GPIO_NAME             C     //!< PTC4 GPIO name
#define PTC4_GPIO_BIT              4     //!< PTC4 GPIO bit number
#define PTC4_GPIO_FN               1     //!< PTC4 Pin multiplexor for GPIO

// PTC5 = GPIOC_5,ADC0_0
#define PTC5_GPIO_NAME             C     //!< PTC5 GPIO name
#define PTC5_GPIO_BIT              5     //!< PTC5 GPIO bit number
#define PTC5_GPIO_FN               1     //!< PTC5 Pin multiplexor for GPIO
#define PTC5_ADC_NUM               0     //!< PTC5 ADC number
#define PTC5_ADC_CH                0     //!< PTC5 ADC channel
#define PTC5_ADC_FN                0     //!< PTC5 Pin multiplexor for ADC

// PTC6 = GPIOC_6,ADC0_1
#define PTC6_GPIO_NAME             C     //!< PTC6 GPIO name
#define PTC6_GPIO_BIT              6     //!< PTC6 GPIO bit number
#define PTC6_GPIO_FN               1     //!< PTC6 Pin multiplexor for GPIO
#define PTC6_ADC_NUM               0     //!< PTC6 ADC number
#define PTC6_ADC_CH                1     //!< PTC6 ADC channel
#define PTC6_ADC_FN                0     //!< PTC6 Pin multiplexor for ADC

// PTC7 = GPIOC_7,ADC0_2
#define PTC7_GPIO_NAME             C     //!< PTC7 GPIO name
#define PTC7_GPIO_BIT              7     //!< PTC7 GPIO bit number
#define PTC7_GPIO_FN               1     //!< PTC7 Pin multiplexor for GPIO
#define PTC7_ADC_NUM               0     //!< PTC7 ADC number
#define PTC7_ADC_CH                2     //!< PTC7 ADC channel
#define PTC7_ADC_FN                0     //!< PTC7 Pin multiplexor for ADC

// PTD0 = GPIOD_0
#define PTD0_GPIO_NAME             D     //!< PTD0 GPIO name
#define PTD0_GPIO_BIT              0     //!< PTD0 GPIO bit number
#define PTD0_GPIO_FN               1     //!< PTD0 Pin multiplexor for GPIO

// PTD1 = GPIOD_1
#define PTD1_GPIO_NAME             D     //!< PTD1 GPIO name
#define PTD1_GPIO_BIT              1     //!< PTD1 GPIO bit number
#define PTD1_GPIO_FN               1     //!< PTD1 Pin multiplexor for GPIO

// PTD2 = GPIOD_2,SPI0_SCK
#define PTD2_GPIO_NAME             D     //!< PTD2 GPIO name
#define PTD2_GPIO_BIT              2     //!< PTD2 GPIO bit number
#define PTD2_GPIO_FN               1     //!< PTD2 Pin multiplexor for GPIO
#if SPI0_SCK_SEL == 1
#define SPI0_SCK_FN                3     //!< PTD2 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTD2   //!< PTD2 SPI GPIO
#endif

// PTD3 = GPIOD_3,SPI0_MOSI
#define PTD3_GPIO_NAME             D     //!< PTD3 GPIO name
#define PTD3_GPIO_BIT              3     //!< PTD3 GPIO bit number
#define PTD3_GPIO_FN               1     //!< PTD3 Pin multiplexor for GPIO
#if SPI0_MOSI_SEL == 1
#define SPI0_MOSI_FN               3     //!< PTD3 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTD3   //!< PTD3 SPI GPIO
#endif

// PTD4 = GPIOD_4,ADC0_3,SPI0_MISO
#define PTD4_GPIO_NAME             D     //!< PTD4 GPIO name
#define PTD4_GPIO_BIT              4     //!< PTD4 GPIO bit number
#define PTD4_GPIO_FN               1     //!< PTD4 Pin multiplexor for GPIO
#define PTD4_ADC_NUM               0     //!< PTD4 ADC number
#define PTD4_ADC_CH                3     //!< PTD4 ADC channel
#define PTD4_ADC_FN                0     //!< PTD4 Pin multiplexor for ADC
#if SPI0_MISO_SEL == 1
#define SPI0_MISO_FN               3     //!< PTD4 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTD4   //!< PTD4 SPI GPIO
#endif

// PTD5 = GPIOD_5,ADC0_4
#define PTD5_GPIO_NAME             D     //!< PTD5 GPIO name
#define PTD5_GPIO_BIT              5     //!< PTD5 GPIO bit number
#define PTD5_GPIO_FN               1     //!< PTD5 Pin multiplexor for GPIO
#define PTD5_ADC_NUM               0     //!< PTD5 ADC number
#define PTD5_ADC_CH                4     //!< PTD5 ADC channel
#define PTD5_ADC_FN                0     //!< PTD5 Pin multiplexor for ADC

// PTD6 = GPIOD_6,ADC0_5
#define PTD6_GPIO_NAME             D     //!< PTD6 GPIO name
#define PTD6_GPIO_BIT              6     //!< PTD6 GPIO bit number
#define PTD6_GPIO_FN               1     //!< PTD6 Pin multiplexor for GPIO
#define PTD6_ADC_NUM               0     //!< PTD6 ADC number
#define PTD6_ADC_CH                5     //!< PTD6 ADC channel
#define PTD6_ADC_FN                0     //!< PTD6 Pin multiplexor for ADC

// PTD7 = GPIOD_7,I2C0_SCL
#define PTD7_GPIO_NAME             D     //!< PTD7 GPIO name
#define PTD7_GPIO_BIT              7     //!< PTD7 GPIO bit number
#define PTD7_GPIO_FN               1     //!< PTD7 Pin multiplexor for GPIO
#if I2C0_SCL_SEL == 1
#define I2C0_SCL_FN                2     //!< PTD7 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTD7   //!< PTD7 I2C GPIO
#endif

// PTE0 = GPIOE_0,I2C0_SDA
#define PTE0_GPIO_NAME             E     //!< PTE0 GPIO name
#define PTE0_GPIO_BIT              0     //!< PTE0 GPIO bit number
#define PTE0_GPIO_FN               1     //!< PTE0 Pin multiplexor for GPIO
#if I2C0_SDA_SEL == 1
#define I2C0_SDA_FN                2     //!< PTE0 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTE0   //!< PTE0 I2C GPIO
#endif

// PTE1 = GPIOE_1
#define PTE1_GPIO_NAME             E     //!< PTE1 GPIO name
#define PTE1_GPIO_BIT              1     //!< PTE1 GPIO bit number
#define PTE1_GPIO_FN               1     //!< PTE1 Pin multiplexor for GPIO

// PTE2 = GPIOE_2,I2C1_SDA
#define PTE2_GPIO_NAME             E     //!< PTE2 GPIO name
#define PTE2_GPIO_BIT              2     //!< PTE2 GPIO bit number
#define PTE2_GPIO_FN               1     //!< PTE2 Pin multiplexor for GPIO
#if I2C1_SDA_SEL == 1
#define I2C1_SDA_FN                4     //!< PTE2 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTE2   //!< PTE2 I2C GPIO
#endif

// PTE3 = GPIOE_3,I2C1_SCL
#define PTE3_GPIO_NAME             E     //!< PTE3 GPIO name
#define PTE3_GPIO_BIT              3     //!< PTE3 GPIO bit number
#define PTE3_GPIO_FN               1     //!< PTE3 Pin multiplexor for GPIO
#if I2C1_SCL_SEL == 1
#define I2C1_SCL_FN                4     //!< PTE3 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTE3   //!< PTE3 I2C GPIO
#endif

// PTE4 = GPIOE_4
#define PTE4_GPIO_NAME             E     //!< PTE4 GPIO name
#define PTE4_GPIO_BIT              4     //!< PTE4 GPIO bit number
#define PTE4_GPIO_FN               1     //!< PTE4 Pin multiplexor for GPIO

// PTE5 = GPIOE_5
#define PTE5_GPIO_NAME             E     //!< PTE5 GPIO name
#define PTE5_GPIO_BIT              5     //!< PTE5 GPIO bit number
#define PTE5_GPIO_FN               1     //!< PTE5 Pin multiplexor for GPIO

// PTE6 = GPIOE_6,I2C0_SCL
#define PTE6_GPIO_NAME             E     //!< PTE6 GPIO name
#define PTE6_GPIO_BIT              6     //!< PTE6 GPIO bit number
#define PTE6_GPIO_FN               1     //!< PTE6 Pin multiplexor for GPIO
#if I2C0_SCL_SEL == 2
#define I2C0_SCL_FN                5     //!< PTE6 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTE6   //!< PTE6 I2C GPIO
#endif

// PTE7 = GPIOE_7,ADC0_6,I2C0_SDA
#define PTE7_GPIO_NAME             E     //!< PTE7 GPIO name
#define PTE7_GPIO_BIT              7     //!< PTE7 GPIO bit number
#define PTE7_GPIO_FN               1     //!< PTE7 Pin multiplexor for GPIO
#define PTE7_ADC_NUM               0     //!< PTE7 ADC number
#define PTE7_ADC_CH                6     //!< PTE7 ADC channel
#define PTE7_ADC_FN                0     //!< PTE7 Pin multiplexor for ADC
#if I2C0_SDA_SEL == 2
#define I2C0_SDA_FN                5     //!< PTE7 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTE7   //!< PTE7 I2C GPIO
#endif

// PTF0 = GPIOF_0,ADC0_7
#define PTF0_GPIO_NAME             F     //!< PTF0 GPIO name
#define PTF0_GPIO_BIT              0     //!< PTF0 GPIO bit number
#define PTF0_GPIO_FN               1     //!< PTF0 Pin multiplexor for GPIO
#define PTF0_ADC_NUM               0     //!< PTF0 ADC number
#define PTF0_ADC_CH                7     //!< PTF0 ADC channel
#define PTF0_ADC_FN                0     //!< PTF0 Pin multiplexor for ADC

// PTF1 = GPIOF_1,ADC0_8
#define PTF1_GPIO_NAME             F     //!< PTF1 GPIO name
#define PTF1_GPIO_BIT              1     //!< PTF1 GPIO bit number
#define PTF1_GPIO_FN               1     //!< PTF1 Pin multiplexor for GPIO
#define PTF1_ADC_NUM               0     //!< PTF1 ADC number
#define PTF1_ADC_CH                8     //!< PTF1 ADC channel
#define PTF1_ADC_FN                0     //!< PTF1 Pin multiplexor for ADC

// PTF2 = GPIOF_2,ADC0_9
#define PTF2_GPIO_NAME             F     //!< PTF2 GPIO name
#define PTF2_GPIO_BIT              2     //!< PTF2 GPIO bit number
#define PTF2_GPIO_FN               1     //!< PTF2 Pin multiplexor for GPIO
#define PTF2_ADC_NUM               0     //!< PTF2 ADC number
#define PTF2_ADC_CH                9     //!< PTF2 ADC channel
#define PTF2_ADC_FN                0     //!< PTF2 Pin multiplexor for ADC

// PTF3 = GPIOF_3
#define PTF3_GPIO_NAME             F     //!< PTF3 GPIO name
#define PTF3_GPIO_BIT              3     //!< PTF3 GPIO bit number
#define PTF3_GPIO_FN               1     //!< PTF3 Pin multiplexor for GPIO

// PTF4 = GPIOF_4,SPI1_SCK
#define PTF4_GPIO_NAME             F     //!< PTF4 GPIO name
#define PTF4_GPIO_BIT              4     //!< PTF4 GPIO bit number
#define PTF4_GPIO_FN               1     //!< PTF4 Pin multiplexor for GPIO
#if SPI1_SCK_SEL == 1
#define SPI1_SCK_FN                2     //!< PTF4 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTF4   //!< PTF4 SPI GPIO
#endif

// PTF5 = GPIOF_5,SPI1_MISO,I2C1_SCL
#define PTF5_GPIO_NAME             F     //!< PTF5 GPIO name
#define PTF5_GPIO_BIT              5     //!< PTF5 GPIO bit number
#define PTF5_GPIO_FN               1     //!< PTF5 Pin multiplexor for GPIO
#if SPI1_MISO_SEL == 1
#define SPI1_MISO_FN               2     //!< PTF5 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTF5   //!< PTF5 SPI GPIO
#endif
#if I2C1_SCL_SEL == 2
#define I2C1_SCL_FN                3     //!< PTF5 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTF5   //!< PTF5 I2C GPIO
#endif

// PTF6 = GPIOF_6,SPI1_MOSI,I2C1_SDA
#define PTF6_GPIO_NAME             F     //!< PTF6 GPIO name
#define PTF6_GPIO_BIT              6     //!< PTF6 GPIO bit number
#define PTF6_GPIO_FN               1     //!< PTF6 Pin multiplexor for GPIO
#if SPI1_MOSI_SEL == 1
#define SPI1_MOSI_FN               2     //!< PTF6 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTF6   //!< PTF6 SPI GPIO
#endif
#if I2C1_SDA_SEL == 2
#define I2C1_SDA_FN                3     //!< PTF6 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTF6   //!< PTF6 I2C GPIO
#endif

// PTF7 = GPIOF_7
#define PTF7_GPIO_NAME             F     //!< PTF7 GPIO name
#define PTF7_GPIO_BIT              7     //!< PTF7 GPIO bit number
#define PTF7_GPIO_FN               1     //!< PTF7 Pin multiplexor for GPIO

// PTG0 = GPIOG_0
#define PTG0_GPIO_NAME             G     //!< PTG0 GPIO name
#define PTG0_GPIO_BIT              0     //!< PTG0 GPIO bit number
#define PTG0_GPIO_FN               1     //!< PTG0 Pin multiplexor for GPIO

// PTG1 = GPIOG_1,ADC0_10
#define PTG1_GPIO_NAME             G     //!< PTG1 GPIO name
#define PTG1_GPIO_BIT              1     //!< PTG1 GPIO bit number
#define PTG1_GPIO_FN               1     //!< PTG1 Pin multiplexor for GPIO
#define PTG1_ADC_NUM               0     //!< PTG1 ADC number
#define PTG1_ADC_CH                10    //!< PTG1 ADC channel
#define PTG1_ADC_FN                0     //!< PTG1 Pin multiplexor for ADC

// PTG2 = GPIOG_2,ADC0_11
#define PTG2_GPIO_NAME             G     //!< PTG2 GPIO name
#define PTG2_GPIO_BIT              2     //!< PTG2 GPIO bit number
#define PTG2_GPIO_FN               1     //!< PTG2 Pin multiplexor for GPIO
#define PTG2_ADC_NUM               0     //!< PTG2 ADC number
#define PTG2_ADC_CH                11    //!< PTG2 ADC channel
#define PTG2_ADC_FN                0     //!< PTG2 Pin multiplexor for ADC

// PTG3 = GPIOG_3,SPI0_SCK,I2C0_SCL
#define PTG3_GPIO_NAME             G     //!< PTG3 GPIO name
#define PTG3_GPIO_BIT              3     //!< PTG3 GPIO bit number
#define PTG3_GPIO_FN               1     //!< PTG3 Pin multiplexor for GPIO
#if SPI0_SCK_SEL == 2
#define SPI0_SCK_FN                2     //!< PTG3 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTG3   //!< PTG3 SPI GPIO
#endif
#if I2C0_SCL_SEL == 3
#define I2C0_SCL_FN                3     //!< PTG3 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTG3   //!< PTG3 I2C GPIO
#endif

// PTG4 = GPIOG_4,SPI0_MOSI,I2C0_SDA
#define PTG4_GPIO_NAME             G     //!< PTG4 GPIO name
#define PTG4_GPIO_BIT              4     //!< PTG4 GPIO bit number
#define PTG4_GPIO_FN               1     //!< PTG4 Pin multiplexor for GPIO
#if SPI0_MOSI_SEL == 2
#define SPI0_MOSI_FN               2     //!< PTG4 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTG4   //!< PTG4 SPI GPIO
#endif
#if I2C0_SDA_SEL == 3
#define I2C0_SDA_FN                3     //!< PTG4 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTG4   //!< PTG4 I2C GPIO
#endif

// PTG5 = GPIOG_5,SPI0_MISO
#define PTG5_GPIO_NAME             G     //!< PTG5 GPIO name
#define PTG5_GPIO_BIT              5     //!< PTG5 GPIO bit number
#define PTG5_GPIO_FN               1     //!< PTG5 Pin multiplexor for GPIO
#if SPI0_MISO_SEL == 2
#define SPI0_MISO_FN               2     //!< PTG5 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTG5   //!< PTG5 SPI GPIO
#endif

// PTG6 = GPIOG_6
#define PTG6_GPIO_NAME             G     //!< PTG6 GPIO name
#define PTG6_GPIO_BIT              6     //!< PTG6 GPIO bit number
#define PTG6_GPIO_FN               1     //!< PTG6 Pin multiplexor for GPIO

// PTG7 = GPIOG_7
#define PTG7_GPIO_NAME             G     //!< PTG7 GPIO name
#define PTG7_GPIO_BIT              7     //!< PTG7 GPIO bit number
#define PTG7_GPIO_FN               1     //!< PTG7 Pin multiplexor for GPIO

// PTH0 = GPIOH_0
#define PTH0_GPIO_NAME             H     //!< PTH0 GPIO name
#define PTH0_GPIO_BIT              0     //!< PTH0 GPIO bit number
#define PTH0_GPIO_FN               1     //!< PTH0 Pin multiplexor for GPIO

// PTH1 = GPIOH_1
#define PTH1_GPIO_NAME             H     //!< PTH1 GPIO name
#define PTH1_GPIO_BIT              1     //!< PTH1 GPIO bit number
#define PTH1_GPIO_FN               1     //!< PTH1 Pin multiplexor for GPIO

// PTH2 = GPIOH_2
#define PTH2_GPIO_NAME             H     //!< PTH2 GPIO name
#define PTH2_GPIO_BIT              2     //!< PTH2 GPIO bit number
#define PTH2_GPIO_FN               1     //!< PTH2 Pin multiplexor for GPIO

// PTH3 = GPIOH_3
#define PTH3_GPIO_NAME             H     //!< PTH3 GPIO name
#define PTH3_GPIO_BIT              3     //!< PTH3 GPIO bit number
#define PTH3_GPIO_FN               1     //!< PTH3 Pin multiplexor for GPIO

// PTH4 = GPIOH_4
#define PTH4_GPIO_NAME             H     //!< PTH4 GPIO name
#define PTH4_GPIO_BIT              4     //!< PTH4 GPIO bit number
#define PTH4_GPIO_FN               1     //!< PTH4 Pin multiplexor for GPIO

// PTH5 = GPIOH_5
#define PTH5_GPIO_NAME             H     //!< PTH5 GPIO name
#define PTH5_GPIO_BIT              5     //!< PTH5 GPIO bit number
#define PTH5_GPIO_FN               1     //!< PTH5 Pin multiplexor for GPIO

// PTH6 = GPIOH_6
#define PTH6_GPIO_NAME             H     //!< PTH6 GPIO name
#define PTH6_GPIO_BIT              6     //!< PTH6 GPIO bit number
#define PTH6_GPIO_FN               1     //!< PTH6 Pin multiplexor for GPIO

// PTH7 = GPIOH_7,SPI1_SCK
#define PTH7_GPIO_NAME             H     //!< PTH7 GPIO name
#define PTH7_GPIO_BIT              7     //!< PTH7 GPIO bit number
#define PTH7_GPIO_FN               1     //!< PTH7 Pin multiplexor for GPIO
#if SPI1_SCK_SEL == 2
#define SPI1_SCK_FN                3     //!< PTH7 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTH7   //!< PTH7 SPI GPIO
#endif

// PTI0 = GPIOI_0,SPI1_MISO,SPI1_MOSI
#define PTI0_GPIO_NAME             I     //!< PTI0 GPIO name
#define PTI0_GPIO_BIT              0     //!< PTI0 GPIO bit number
#define PTI0_GPIO_FN               1     //!< PTI0 Pin multiplexor for GPIO
#if SPI1_MISO_SEL == 2
#define SPI1_MISO_FN               4     //!< PTI0 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTI0   //!< PTI0 SPI GPIO
#endif
#if SPI1_MOSI_SEL == 2
#define SPI1_MOSI_FN               5     //!< PTI0 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTI0   //!< PTI0 SPI GPIO
#endif

// PTI1 = GPIOI_1,SPI1_MOSI,SPI1_MISO
#define PTI1_GPIO_NAME             I     //!< PTI1 GPIO name
#define PTI1_GPIO_BIT              1     //!< PTI1 GPIO bit number
#define PTI1_GPIO_FN               1     //!< PTI1 Pin multiplexor for GPIO
#if SPI1_MOSI_SEL == 3
#define SPI1_MOSI_FN               4     //!< PTI1 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTI1   //!< PTI1 SPI GPIO
#endif
#if SPI1_MISO_SEL == 3
#define SPI1_MISO_FN               5     //!< PTI1 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTI1   //!< PTI1 SPI GPIO
#endif

// PTI2 = GPIOI_2
#define PTI2_GPIO_NAME             I     //!< PTI2 GPIO name
#define PTI2_GPIO_BIT              2     //!< PTI2 GPIO bit number
#define PTI2_GPIO_FN               1     //!< PTI2 Pin multiplexor for GPIO

// PTI3 = GPIOI_3
#define PTI3_GPIO_NAME             I     //!< PTI3 GPIO name
#define PTI3_GPIO_BIT              3     //!< PTI3 GPIO bit number
#define PTI3_GPIO_FN               1     //!< PTI3 Pin multiplexor for GPIO

// SAR_VDDA

// SAR_VSSA

// SDADM0

// SDADM1

// SDADM2/ CMP1P3

// SDADM3/ CMP1P5

// SDADP0

// SDADP1

// SDADP2/ CMP1P2

// SDADP3/ CMP1P4

#define DEFAULT_ADC_FN   0 //!< Fixed ADC Multiplexing value for pins
#define DEFAULT_GPIO_FN  1 //!< Fixed GPIO Multiplexing value for pins

#endif /* PIN_MAPPING_H_ */
