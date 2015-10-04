 /**
  * @file     gpio.cpp (from gpio-MKE06Z4.cpp)
  *
  * @brief   Pin declarations for MKE06Z4
  */

#include "utilities.h"
#include "gpio.h"
#include "pin_mapping.h"

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
#define PORT_CLOCK_REG       SIM->SCGC5          

const DigitalIO digitalIO_PTA0     = {(volatile GPIO_Type*)GPIOA,(1UL<<0)};
;
const DigitalIO digitalIO_PTA1     = {(volatile GPIO_Type*)GPIOA,(1UL<<1)};
;
const DigitalIO digitalIO_PTA2     = {(volatile GPIO_Type*)GPIOA,(1UL<<2)};
;
const DigitalIO digitalIO_PTA3     = {(volatile GPIO_Type*)GPIOA,(1UL<<3)};
;
const DigitalIO digitalIO_PTA5     = {(volatile GPIO_Type*)GPIOA,(1UL<<5)};
;
const DigitalIO digitalIO_PTA6     = {(volatile GPIO_Type*)GPIOA,(1UL<<6)};
;
const DigitalIO digitalIO_PTA7     = {(volatile GPIO_Type*)GPIOA,(1UL<<7)};
;
const DigitalIO digitalIO_PTB0     = {(volatile GPIO_Type*)GPIOA,(1UL<<8)};
;
const DigitalIO digitalIO_PTB1     = {(volatile GPIO_Type*)GPIOA,(1UL<<9)};
;
const DigitalIO digitalIO_PTB2     = {(volatile GPIO_Type*)GPIOA,(1UL<<10)};
;
const DigitalIO digitalIO_PTB3     = {(volatile GPIO_Type*)GPIOA,(1UL<<11)};
;
const DigitalIO digitalIO_PTB4     = {(volatile GPIO_Type*)GPIOA,(1UL<<12)};
;
const DigitalIO digitalIO_PTB5     = {(volatile GPIO_Type*)GPIOA,(1UL<<13)};
;
const DigitalIO digitalIO_PTB6     = {(volatile GPIO_Type*)GPIOA,(1UL<<14)};
;
const DigitalIO digitalIO_PTB7     = {(volatile GPIO_Type*)GPIOA,(1UL<<15)};
;
const DigitalIO digitalIO_PTC0     = {(volatile GPIO_Type*)GPIOA,(1UL<<16)};
;
const DigitalIO digitalIO_PTC1     = {(volatile GPIO_Type*)GPIOA,(1UL<<17)};
;
const DigitalIO digitalIO_PTC2     = {(volatile GPIO_Type*)GPIOA,(1UL<<18)};
;
const DigitalIO digitalIO_PTC3     = {(volatile GPIO_Type*)GPIOA,(1UL<<19)};
;
const DigitalIO digitalIO_PTC4     = {(volatile GPIO_Type*)GPIOA,(1UL<<20)};
;
const DigitalIO digitalIO_PTC5     = {(volatile GPIO_Type*)GPIOA,(1UL<<21)};
;
const DigitalIO digitalIO_PTC6     = {(volatile GPIO_Type*)GPIOA,(1UL<<22)};
;
const DigitalIO digitalIO_PTC7     = {(volatile GPIO_Type*)GPIOA,(1UL<<23)};
;
const DigitalIO digitalIO_PTD0     = {(volatile GPIO_Type*)GPIOA,(1UL<<24)};
;
const DigitalIO digitalIO_PTD1     = {(volatile GPIO_Type*)GPIOA,(1UL<<25)};
;
const DigitalIO digitalIO_PTD2     = {(volatile GPIO_Type*)GPIOA,(1UL<<26)};
;
const DigitalIO digitalIO_PTD3     = {(volatile GPIO_Type*)GPIOA,(1UL<<27)};
;
const DigitalIO digitalIO_PTD4     = {(volatile GPIO_Type*)GPIOA,(1UL<<28)};
;
const DigitalIO digitalIO_PTD5     = {(volatile GPIO_Type*)GPIOA,(1UL<<29)};
;
const DigitalIO digitalIO_PTD6     = {(volatile GPIO_Type*)GPIOA,(1UL<<30)};
;
const DigitalIO digitalIO_PTD7     = {(volatile GPIO_Type*)GPIOA,(1UL<<31)};
;
const DigitalIO digitalIO_PTE0     = {(volatile GPIO_Type*)GPIOB,(1UL<<0)};
;
const DigitalIO digitalIO_PTE1     = {(volatile GPIO_Type*)GPIOB,(1UL<<1)};
;
const DigitalIO digitalIO_PTE2     = {(volatile GPIO_Type*)GPIOB,(1UL<<2)};
;
const DigitalIO digitalIO_PTE3     = {(volatile GPIO_Type*)GPIOB,(1UL<<3)};
;
const DigitalIO digitalIO_PTE4     = {(volatile GPIO_Type*)GPIOB,(1UL<<4)};
;
const DigitalIO digitalIO_PTE5     = {(volatile GPIO_Type*)GPIOB,(1UL<<5)};
;
const DigitalIO digitalIO_PTE6     = {(volatile GPIO_Type*)GPIOB,(1UL<<6)};
;
const DigitalIO digitalIO_PTE7     = {(volatile GPIO_Type*)GPIOB,(1UL<<7)};
;
const DigitalIO digitalIO_PTF0     = {(volatile GPIO_Type*)GPIOB,(1UL<<8)};
;
const DigitalIO digitalIO_PTF1     = {(volatile GPIO_Type*)GPIOB,(1UL<<9)};
;
const DigitalIO digitalIO_PTF2     = {(volatile GPIO_Type*)GPIOB,(1UL<<10)};
;
const DigitalIO digitalIO_PTF3     = {(volatile GPIO_Type*)GPIOB,(1UL<<11)};
;
const DigitalIO digitalIO_PTF4     = {(volatile GPIO_Type*)GPIOB,(1UL<<12)};
;
const DigitalIO digitalIO_PTF5     = {(volatile GPIO_Type*)GPIOB,(1UL<<13)};
;
const DigitalIO digitalIO_PTF6     = {(volatile GPIO_Type*)GPIOB,(1UL<<14)};
;
const DigitalIO digitalIO_PTF7     = {(volatile GPIO_Type*)GPIOB,(1UL<<15)};
;
const DigitalIO digitalIO_PTG0     = {(volatile GPIO_Type*)GPIOB,(1UL<<16)};
;
const DigitalIO digitalIO_PTG1     = {(volatile GPIO_Type*)GPIOB,(1UL<<17)};
;
const DigitalIO digitalIO_PTG2     = {(volatile GPIO_Type*)GPIOB,(1UL<<18)};
;
const DigitalIO digitalIO_PTG3     = {(volatile GPIO_Type*)GPIOB,(1UL<<19)};
;
const DigitalIO digitalIO_PTG4     = {(volatile GPIO_Type*)GPIOB,(1UL<<20)};
;
const DigitalIO digitalIO_PTG5     = {(volatile GPIO_Type*)GPIOB,(1UL<<21)};
;
const DigitalIO digitalIO_PTG6     = {(volatile GPIO_Type*)GPIOB,(1UL<<22)};
;
const DigitalIO digitalIO_PTG7     = {(volatile GPIO_Type*)GPIOB,(1UL<<23)};
;
const DigitalIO digitalIO_PTH0     = {(volatile GPIO_Type*)GPIOB,(1UL<<24)};
;
const DigitalIO digitalIO_PTH1     = {(volatile GPIO_Type*)GPIOB,(1UL<<25)};
;
const DigitalIO digitalIO_PTH2     = {(volatile GPIO_Type*)GPIOB,(1UL<<26)};
;
const DigitalIO digitalIO_PTH3     = {(volatile GPIO_Type*)GPIOB,(1UL<<27)};
;
const DigitalIO digitalIO_PTH4     = {(volatile GPIO_Type*)GPIOB,(1UL<<28)};
;
const DigitalIO digitalIO_PTH5     = {(volatile GPIO_Type*)GPIOB,(1UL<<29)};
;
const DigitalIO digitalIO_PTH6     = {(volatile GPIO_Type*)GPIOB,(1UL<<30)};
;
const DigitalIO digitalIO_PTH7     = {(volatile GPIO_Type*)GPIOB,(1UL<<31)};
;
const DigitalIO digitalIO_PTI0     = {(volatile GPIO_Type*)GPIOC,(1UL<<0)};
;
const DigitalIO digitalIO_PTI1     = {(volatile GPIO_Type*)GPIOC,(1UL<<1)};
;
const DigitalIO digitalIO_PTI2     = {(volatile GPIO_Type*)GPIOC,(1UL<<2)};
;
const DigitalIO digitalIO_PTI3     = {(volatile GPIO_Type*)GPIOC,(1UL<<3)};
;
const DigitalIO digitalIO_PTI4     = {(volatile GPIO_Type*)GPIOC,(1UL<<4)};
;
const DigitalIO digitalIO_PTI5     = {(volatile GPIO_Type*)GPIOC,(1UL<<5)};
;
const DigitalIO digitalIO_PTI6     = {(volatile GPIO_Type*)GPIOC,(1UL<<6)};
;
