/**
 * @file      pin_mapping.h (derived from pin_mapping-MKE06Z4.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKE06Z4
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

#define ACMP0_CLOCK_REG      SIM->SCGC           
#define ACMP0_CLOCK_MASK     SIM_SCGC_ACMP0_MASK 
#define ACMP1_CLOCK_REG      SIM->SCGC           
#define ACMP1_CLOCK_MASK     SIM_SCGC_ACMP1_MASK 
#define ADC0_CLOCK_REG       SIM->SCGC           
#define ADC0_CLOCK_MASK      SIM_SCGC_ADC0_MASK  
#define CRC_CLOCK_REG        SIM->SCGC           
#define CRC_CLOCK_MASK       SIM_SCGC_CRC_MASK   
#define FTM0_CLOCK_REG       SIM->SCGC           
#define FTM0_CLOCK_MASK      SIM_SCGC_FTM0_MASK  
#define FTM1_CLOCK_REG       SIM->SCGC           
#define FTM1_CLOCK_MASK      SIM_SCGC_FTM1_MASK  
#define FTM2_CLOCK_REG       SIM->SCGC           
#define FTM2_CLOCK_MASK      SIM_SCGC_FTM2_MASK  
#define I2C0_CLOCK_REG       SIM->SCGC           
#define I2C0_CLOCK_MASK      SIM_SCGC_I2C0_MASK  
#define I2C1_CLOCK_REG       SIM->SCGC           
#define I2C1_CLOCK_MASK      SIM_SCGC_I2C1_MASK  
#define IRQ_CLOCK_REG        SIM->SCGC           
#define IRQ_CLOCK_MASK       SIM_SCGC_IRQ_MASK   
#define KBI0_CLOCK_REG       SIM->SCGC           
#define KBI0_CLOCK_MASK      SIM_SCGC_KBI0_MASK  
#define KBI1_CLOCK_REG       SIM->SCGC           
#define KBI1_CLOCK_MASK      SIM_SCGC_KBI1_MASK  
#define MSCAN_CLOCK_REG      SIM->SCGC           
#define MSCAN_CLOCK_MASK     SIM_SCGC_MSCAN_MASK 
#define PIT_CLOCK_REG        SIM->SCGC           
#define PIT_CLOCK_MASK       SIM_SCGC_PIT_MASK   
#define PWT_CLOCK_REG        SIM->SCGC           
#define PWT_CLOCK_MASK       SIM_SCGC_PWT_MASK   
#define RTC_CLOCK_REG        SIM->SCGC           
#define RTC_CLOCK_MASK       SIM_SCGC_RTC_MASK   
#define SPI0_CLOCK_REG       SIM->SCGC           
#define SPI0_CLOCK_MASK      SIM_SCGC_SPI0_MASK  
#define SPI1_CLOCK_REG       SIM->SCGC           
#define SPI1_CLOCK_MASK      SIM_SCGC_SPI1_MASK  
#define SWD_CLOCK_REG        SIM->SCGC           
#define SWD_CLOCK_MASK       SIM_SCGC_SWD_MASK   
#define UART0_CLOCK_REG      SIM->SCGC           
#define UART0_CLOCK_MASK     SIM_SCGC_UART0_MASK 
#define UART1_CLOCK_REG      SIM->SCGC           
#define UART1_CLOCK_MASK     SIM_SCGC_UART1_MASK 
#define UART2_CLOCK_REG      SIM->SCGC           
#define UART2_CLOCK_MASK     SIM_SCGC_UART2_MASK 
#define PORT_CLOCK_REG       null                

// <h> Pin Peripheral mapping

// </h>

// PTA0 = GPIOA_0
#define PTA0_GPIO_NAME             A     //!< PTA0 GPIO name
#define PTA0_GPIO_BIT              0     //!< PTA0 GPIO bit number
#define PTA0_GPIO_FN               0     //!< PTA0 Pin multiplexor for GPIO

// PTA1 = GPIOA_1
#define PTA1_GPIO_NAME             A     //!< PTA1 GPIO name
#define PTA1_GPIO_BIT              1     //!< PTA1 GPIO bit number
#define PTA1_GPIO_FN               0     //!< PTA1 Pin multiplexor for GPIO

// PTA2 = GPIOA_2
#define PTA2_GPIO_NAME             A     //!< PTA2 GPIO name
#define PTA2_GPIO_BIT              2     //!< PTA2 GPIO bit number
#define PTA2_GPIO_FN               0     //!< PTA2 Pin multiplexor for GPIO

// PTA3 = GPIOA_3
#define PTA3_GPIO_NAME             A     //!< PTA3 GPIO name
#define PTA3_GPIO_BIT              3     //!< PTA3 GPIO bit number
#define PTA3_GPIO_FN               0     //!< PTA3 Pin multiplexor for GPIO

// PTA5 = GPIOA_5
#define PTA5_GPIO_NAME             A     //!< PTA5 GPIO name
#define PTA5_GPIO_BIT              5     //!< PTA5 GPIO bit number
#define PTA5_GPIO_FN               0     //!< PTA5 Pin multiplexor for GPIO

// PTA6 = GPIOA_6
#define PTA6_GPIO_NAME             A     //!< PTA6 GPIO name
#define PTA6_GPIO_BIT              6     //!< PTA6 GPIO bit number
#define PTA6_GPIO_FN               0     //!< PTA6 Pin multiplexor for GPIO

// PTA7 = GPIOA_7
#define PTA7_GPIO_NAME             A     //!< PTA7 GPIO name
#define PTA7_GPIO_BIT              7     //!< PTA7 GPIO bit number
#define PTA7_GPIO_FN               0     //!< PTA7 Pin multiplexor for GPIO

// PTB0 = GPIOA_8
#define PTB0_GPIO_NAME             A     //!< PTB0 GPIO name
#define PTB0_GPIO_BIT              8     //!< PTB0 GPIO bit number
#define PTB0_GPIO_FN               0     //!< PTB0 Pin multiplexor for GPIO

// PTB1 = GPIOA_9
#define PTB1_GPIO_NAME             A     //!< PTB1 GPIO name
#define PTB1_GPIO_BIT              9     //!< PTB1 GPIO bit number
#define PTB1_GPIO_FN               0     //!< PTB1 Pin multiplexor for GPIO

// PTB2 = GPIOA_10
#define PTB2_GPIO_NAME             A     //!< PTB2 GPIO name
#define PTB2_GPIO_BIT              10    //!< PTB2 GPIO bit number
#define PTB2_GPIO_FN               0     //!< PTB2 Pin multiplexor for GPIO

// PTB3 = GPIOA_11
#define PTB3_GPIO_NAME             A     //!< PTB3 GPIO name
#define PTB3_GPIO_BIT              11    //!< PTB3 GPIO bit number
#define PTB3_GPIO_FN               0     //!< PTB3 Pin multiplexor for GPIO

// PTB4 = GPIOA_12
#define PTB4_GPIO_NAME             A     //!< PTB4 GPIO name
#define PTB4_GPIO_BIT              12    //!< PTB4 GPIO bit number
#define PTB4_GPIO_FN               0     //!< PTB4 Pin multiplexor for GPIO

// PTB5 = GPIOA_13
#define PTB5_GPIO_NAME             A     //!< PTB5 GPIO name
#define PTB5_GPIO_BIT              13    //!< PTB5 GPIO bit number
#define PTB5_GPIO_FN               0     //!< PTB5 Pin multiplexor for GPIO

// PTB6 = GPIOA_14
#define PTB6_GPIO_NAME             A     //!< PTB6 GPIO name
#define PTB6_GPIO_BIT              14    //!< PTB6 GPIO bit number
#define PTB6_GPIO_FN               0     //!< PTB6 Pin multiplexor for GPIO

// PTB7 = GPIOA_15
#define PTB7_GPIO_NAME             A     //!< PTB7 GPIO name
#define PTB7_GPIO_BIT              15    //!< PTB7 GPIO bit number
#define PTB7_GPIO_FN               0     //!< PTB7 Pin multiplexor for GPIO

// PTC0 = GPIOA_16
#define PTC0_GPIO_NAME             A     //!< PTC0 GPIO name
#define PTC0_GPIO_BIT              16    //!< PTC0 GPIO bit number
#define PTC0_GPIO_FN               0     //!< PTC0 Pin multiplexor for GPIO

// PTC1 = GPIOA_17
#define PTC1_GPIO_NAME             A     //!< PTC1 GPIO name
#define PTC1_GPIO_BIT              17    //!< PTC1 GPIO bit number
#define PTC1_GPIO_FN               0     //!< PTC1 Pin multiplexor for GPIO

// PTC2 = GPIOA_18
#define PTC2_GPIO_NAME             A     //!< PTC2 GPIO name
#define PTC2_GPIO_BIT              18    //!< PTC2 GPIO bit number
#define PTC2_GPIO_FN               0     //!< PTC2 Pin multiplexor for GPIO

// PTC3 = GPIOA_19
#define PTC3_GPIO_NAME             A     //!< PTC3 GPIO name
#define PTC3_GPIO_BIT              19    //!< PTC3 GPIO bit number
#define PTC3_GPIO_FN               0     //!< PTC3 Pin multiplexor for GPIO

// PTC4 = GPIOA_20
#define PTC4_GPIO_NAME             A     //!< PTC4 GPIO name
#define PTC4_GPIO_BIT              20    //!< PTC4 GPIO bit number
#define PTC4_GPIO_FN               0     //!< PTC4 Pin multiplexor for GPIO

// PTC5 = GPIOA_21
#define PTC5_GPIO_NAME             A     //!< PTC5 GPIO name
#define PTC5_GPIO_BIT              21    //!< PTC5 GPIO bit number
#define PTC5_GPIO_FN               0     //!< PTC5 Pin multiplexor for GPIO

// PTC6 = GPIOA_22
#define PTC6_GPIO_NAME             A     //!< PTC6 GPIO name
#define PTC6_GPIO_BIT              22    //!< PTC6 GPIO bit number
#define PTC6_GPIO_FN               0     //!< PTC6 Pin multiplexor for GPIO

// PTC7 = GPIOA_23
#define PTC7_GPIO_NAME             A     //!< PTC7 GPIO name
#define PTC7_GPIO_BIT              23    //!< PTC7 GPIO bit number
#define PTC7_GPIO_FN               0     //!< PTC7 Pin multiplexor for GPIO

// PTD0 = GPIOA_24
#define PTD0_GPIO_NAME             A     //!< PTD0 GPIO name
#define PTD0_GPIO_BIT              24    //!< PTD0 GPIO bit number
#define PTD0_GPIO_FN               0     //!< PTD0 Pin multiplexor for GPIO

// PTD1 = GPIOA_25
#define PTD1_GPIO_NAME             A     //!< PTD1 GPIO name
#define PTD1_GPIO_BIT              25    //!< PTD1 GPIO bit number
#define PTD1_GPIO_FN               0     //!< PTD1 Pin multiplexor for GPIO

// PTD2 = GPIOA_26
#define PTD2_GPIO_NAME             A     //!< PTD2 GPIO name
#define PTD2_GPIO_BIT              26    //!< PTD2 GPIO bit number
#define PTD2_GPIO_FN               0     //!< PTD2 Pin multiplexor for GPIO

// PTD3 = GPIOA_27
#define PTD3_GPIO_NAME             A     //!< PTD3 GPIO name
#define PTD3_GPIO_BIT              27    //!< PTD3 GPIO bit number
#define PTD3_GPIO_FN               0     //!< PTD3 Pin multiplexor for GPIO

// PTD4 = GPIOA_28
#define PTD4_GPIO_NAME             A     //!< PTD4 GPIO name
#define PTD4_GPIO_BIT              28    //!< PTD4 GPIO bit number
#define PTD4_GPIO_FN               0     //!< PTD4 Pin multiplexor for GPIO

// PTD5 = GPIOA_29
#define PTD5_GPIO_NAME             A     //!< PTD5 GPIO name
#define PTD5_GPIO_BIT              29    //!< PTD5 GPIO bit number
#define PTD5_GPIO_FN               0     //!< PTD5 Pin multiplexor for GPIO

// PTD6 = GPIOA_30
#define PTD6_GPIO_NAME             A     //!< PTD6 GPIO name
#define PTD6_GPIO_BIT              30    //!< PTD6 GPIO bit number
#define PTD6_GPIO_FN               0     //!< PTD6 Pin multiplexor for GPIO

// PTD7 = GPIOA_31
#define PTD7_GPIO_NAME             A     //!< PTD7 GPIO name
#define PTD7_GPIO_BIT              31    //!< PTD7 GPIO bit number
#define PTD7_GPIO_FN               0     //!< PTD7 Pin multiplexor for GPIO

// PTE0 = GPIOB_0
#define PTE0_GPIO_NAME             B     //!< PTE0 GPIO name
#define PTE0_GPIO_BIT              0     //!< PTE0 GPIO bit number
#define PTE0_GPIO_FN               0     //!< PTE0 Pin multiplexor for GPIO

// PTE1 = GPIOB_1
#define PTE1_GPIO_NAME             B     //!< PTE1 GPIO name
#define PTE1_GPIO_BIT              1     //!< PTE1 GPIO bit number
#define PTE1_GPIO_FN               0     //!< PTE1 Pin multiplexor for GPIO

// PTE2 = GPIOB_2
#define PTE2_GPIO_NAME             B     //!< PTE2 GPIO name
#define PTE2_GPIO_BIT              2     //!< PTE2 GPIO bit number
#define PTE2_GPIO_FN               0     //!< PTE2 Pin multiplexor for GPIO

// PTE3 = GPIOB_3
#define PTE3_GPIO_NAME             B     //!< PTE3 GPIO name
#define PTE3_GPIO_BIT              3     //!< PTE3 GPIO bit number
#define PTE3_GPIO_FN               0     //!< PTE3 Pin multiplexor for GPIO

// PTE4 = GPIOB_4
#define PTE4_GPIO_NAME             B     //!< PTE4 GPIO name
#define PTE4_GPIO_BIT              4     //!< PTE4 GPIO bit number
#define PTE4_GPIO_FN               0     //!< PTE4 Pin multiplexor for GPIO

// PTE5 = GPIOB_5
#define PTE5_GPIO_NAME             B     //!< PTE5 GPIO name
#define PTE5_GPIO_BIT              5     //!< PTE5 GPIO bit number
#define PTE5_GPIO_FN               0     //!< PTE5 Pin multiplexor for GPIO

// PTE6 = GPIOB_6
#define PTE6_GPIO_NAME             B     //!< PTE6 GPIO name
#define PTE6_GPIO_BIT              6     //!< PTE6 GPIO bit number
#define PTE6_GPIO_FN               0     //!< PTE6 Pin multiplexor for GPIO

// PTE7 = GPIOB_7
#define PTE7_GPIO_NAME             B     //!< PTE7 GPIO name
#define PTE7_GPIO_BIT              7     //!< PTE7 GPIO bit number
#define PTE7_GPIO_FN               0     //!< PTE7 Pin multiplexor for GPIO

// PTF0 = GPIOB_8
#define PTF0_GPIO_NAME             B     //!< PTF0 GPIO name
#define PTF0_GPIO_BIT              8     //!< PTF0 GPIO bit number
#define PTF0_GPIO_FN               0     //!< PTF0 Pin multiplexor for GPIO

// PTF1 = GPIOB_9
#define PTF1_GPIO_NAME             B     //!< PTF1 GPIO name
#define PTF1_GPIO_BIT              9     //!< PTF1 GPIO bit number
#define PTF1_GPIO_FN               0     //!< PTF1 Pin multiplexor for GPIO

// PTF2 = GPIOB_10
#define PTF2_GPIO_NAME             B     //!< PTF2 GPIO name
#define PTF2_GPIO_BIT              10    //!< PTF2 GPIO bit number
#define PTF2_GPIO_FN               0     //!< PTF2 Pin multiplexor for GPIO

// PTF3 = GPIOB_11
#define PTF3_GPIO_NAME             B     //!< PTF3 GPIO name
#define PTF3_GPIO_BIT              11    //!< PTF3 GPIO bit number
#define PTF3_GPIO_FN               0     //!< PTF3 Pin multiplexor for GPIO

// PTF4 = GPIOB_12
#define PTF4_GPIO_NAME             B     //!< PTF4 GPIO name
#define PTF4_GPIO_BIT              12    //!< PTF4 GPIO bit number
#define PTF4_GPIO_FN               0     //!< PTF4 Pin multiplexor for GPIO

// PTF5 = GPIOB_13
#define PTF5_GPIO_NAME             B     //!< PTF5 GPIO name
#define PTF5_GPIO_BIT              13    //!< PTF5 GPIO bit number
#define PTF5_GPIO_FN               0     //!< PTF5 Pin multiplexor for GPIO

// PTF6 = GPIOB_14
#define PTF6_GPIO_NAME             B     //!< PTF6 GPIO name
#define PTF6_GPIO_BIT              14    //!< PTF6 GPIO bit number
#define PTF6_GPIO_FN               0     //!< PTF6 Pin multiplexor for GPIO

// PTF7 = GPIOB_15
#define PTF7_GPIO_NAME             B     //!< PTF7 GPIO name
#define PTF7_GPIO_BIT              15    //!< PTF7 GPIO bit number
#define PTF7_GPIO_FN               0     //!< PTF7 Pin multiplexor for GPIO

// PTG0 = GPIOB_16
#define PTG0_GPIO_NAME             B     //!< PTG0 GPIO name
#define PTG0_GPIO_BIT              16    //!< PTG0 GPIO bit number
#define PTG0_GPIO_FN               0     //!< PTG0 Pin multiplexor for GPIO

// PTG1 = GPIOB_17
#define PTG1_GPIO_NAME             B     //!< PTG1 GPIO name
#define PTG1_GPIO_BIT              17    //!< PTG1 GPIO bit number
#define PTG1_GPIO_FN               0     //!< PTG1 Pin multiplexor for GPIO

// PTG2 = GPIOB_18
#define PTG2_GPIO_NAME             B     //!< PTG2 GPIO name
#define PTG2_GPIO_BIT              18    //!< PTG2 GPIO bit number
#define PTG2_GPIO_FN               0     //!< PTG2 Pin multiplexor for GPIO

// PTG3 = GPIOB_19
#define PTG3_GPIO_NAME             B     //!< PTG3 GPIO name
#define PTG3_GPIO_BIT              19    //!< PTG3 GPIO bit number
#define PTG3_GPIO_FN               0     //!< PTG3 Pin multiplexor for GPIO

// PTG4 = GPIOB_20
#define PTG4_GPIO_NAME             B     //!< PTG4 GPIO name
#define PTG4_GPIO_BIT              20    //!< PTG4 GPIO bit number
#define PTG4_GPIO_FN               0     //!< PTG4 Pin multiplexor for GPIO

// PTG5 = GPIOB_21
#define PTG5_GPIO_NAME             B     //!< PTG5 GPIO name
#define PTG5_GPIO_BIT              21    //!< PTG5 GPIO bit number
#define PTG5_GPIO_FN               0     //!< PTG5 Pin multiplexor for GPIO

// PTG6 = GPIOB_22
#define PTG6_GPIO_NAME             B     //!< PTG6 GPIO name
#define PTG6_GPIO_BIT              22    //!< PTG6 GPIO bit number
#define PTG6_GPIO_FN               0     //!< PTG6 Pin multiplexor for GPIO

// PTG7 = GPIOB_23
#define PTG7_GPIO_NAME             B     //!< PTG7 GPIO name
#define PTG7_GPIO_BIT              23    //!< PTG7 GPIO bit number
#define PTG7_GPIO_FN               0     //!< PTG7 Pin multiplexor for GPIO

// PTH0 = GPIOB_24
#define PTH0_GPIO_NAME             B     //!< PTH0 GPIO name
#define PTH0_GPIO_BIT              24    //!< PTH0 GPIO bit number
#define PTH0_GPIO_FN               0     //!< PTH0 Pin multiplexor for GPIO

// PTH1 = GPIOB_25
#define PTH1_GPIO_NAME             B     //!< PTH1 GPIO name
#define PTH1_GPIO_BIT              25    //!< PTH1 GPIO bit number
#define PTH1_GPIO_FN               0     //!< PTH1 Pin multiplexor for GPIO

// PTH2 = GPIOB_26
#define PTH2_GPIO_NAME             B     //!< PTH2 GPIO name
#define PTH2_GPIO_BIT              26    //!< PTH2 GPIO bit number
#define PTH2_GPIO_FN               0     //!< PTH2 Pin multiplexor for GPIO

// PTH3 = GPIOB_27
#define PTH3_GPIO_NAME             B     //!< PTH3 GPIO name
#define PTH3_GPIO_BIT              27    //!< PTH3 GPIO bit number
#define PTH3_GPIO_FN               0     //!< PTH3 Pin multiplexor for GPIO

// PTH4 = GPIOB_28
#define PTH4_GPIO_NAME             B     //!< PTH4 GPIO name
#define PTH4_GPIO_BIT              28    //!< PTH4 GPIO bit number
#define PTH4_GPIO_FN               0     //!< PTH4 Pin multiplexor for GPIO

// PTH5 = GPIOB_29
#define PTH5_GPIO_NAME             B     //!< PTH5 GPIO name
#define PTH5_GPIO_BIT              29    //!< PTH5 GPIO bit number
#define PTH5_GPIO_FN               0     //!< PTH5 Pin multiplexor for GPIO

// PTH6 = GPIOB_30
#define PTH6_GPIO_NAME             B     //!< PTH6 GPIO name
#define PTH6_GPIO_BIT              30    //!< PTH6 GPIO bit number
#define PTH6_GPIO_FN               0     //!< PTH6 Pin multiplexor for GPIO

// PTH7 = GPIOB_31
#define PTH7_GPIO_NAME             B     //!< PTH7 GPIO name
#define PTH7_GPIO_BIT              31    //!< PTH7 GPIO bit number
#define PTH7_GPIO_FN               0     //!< PTH7 Pin multiplexor for GPIO

// PTI0 = GPIOC_0
#define PTI0_GPIO_NAME             C     //!< PTI0 GPIO name
#define PTI0_GPIO_BIT              0     //!< PTI0 GPIO bit number
#define PTI0_GPIO_FN               0     //!< PTI0 Pin multiplexor for GPIO

// PTI1 = GPIOC_1
#define PTI1_GPIO_NAME             C     //!< PTI1 GPIO name
#define PTI1_GPIO_BIT              1     //!< PTI1 GPIO bit number
#define PTI1_GPIO_FN               0     //!< PTI1 Pin multiplexor for GPIO

// PTI2 = GPIOC_2
#define PTI2_GPIO_NAME             C     //!< PTI2 GPIO name
#define PTI2_GPIO_BIT              2     //!< PTI2 GPIO bit number
#define PTI2_GPIO_FN               0     //!< PTI2 Pin multiplexor for GPIO

// PTI3 = GPIOC_3
#define PTI3_GPIO_NAME             C     //!< PTI3 GPIO name
#define PTI3_GPIO_BIT              3     //!< PTI3 GPIO bit number
#define PTI3_GPIO_FN               0     //!< PTI3 Pin multiplexor for GPIO

// PTI4 = GPIOC_4
#define PTI4_GPIO_NAME             C     //!< PTI4 GPIO name
#define PTI4_GPIO_BIT              4     //!< PTI4 GPIO bit number
#define PTI4_GPIO_FN               0     //!< PTI4 Pin multiplexor for GPIO

// PTI5 = GPIOC_5
#define PTI5_GPIO_NAME             C     //!< PTI5 GPIO name
#define PTI5_GPIO_BIT              5     //!< PTI5 GPIO bit number
#define PTI5_GPIO_FN               0     //!< PTI5 Pin multiplexor for GPIO

// PTI6 = GPIOC_6
#define PTI6_GPIO_NAME             C     //!< PTI6 GPIO name
#define PTI6_GPIO_BIT              6     //!< PTI6 GPIO bit number
#define PTI6_GPIO_FN               0     //!< PTI6 Pin multiplexor for GPIO

#define DEFAULT_ADC_FN   0 //!< Fixed ADC Multiplexing value for pins
#define GPIO_FN_CHANGES     //!< Indicates GPIO Multiplexing varies with pin

#endif /* PIN_MAPPING_H_ */
