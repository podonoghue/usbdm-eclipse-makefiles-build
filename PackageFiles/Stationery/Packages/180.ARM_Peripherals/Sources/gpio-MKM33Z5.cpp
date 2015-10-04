 /**
  * @file     gpio.cpp (from gpio-MKM33Z5.cpp)
  *
  * @brief   Pin declarations for MKM33Z5
  */

#include "utilities.h"
#include "gpio.h"
#include "pin_mapping.h"

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

const DigitalIO digitalIO_PTA0     = {{&PORTA->PCR[0],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<0)};
const DigitalIO digitalIO_PTA1     = {{&PORTA->PCR[1],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<1)};
const DigitalIO digitalIO_PTA2     = {{&PORTA->PCR[2],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<2)};
const DigitalIO digitalIO_PTA3     = {{&PORTA->PCR[3],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<3)};
const DigitalIO digitalIO_PTA4     = {{&PORTA->PCR[4],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<4)};
const DigitalIO digitalIO_PTA5     = {{&PORTA->PCR[5],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<5)};
const DigitalIO digitalIO_PTA6     = {{&PORTA->PCR[6],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<6)};
const DigitalIO digitalIO_PTA7     = {{&PORTA->PCR[7],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<7)};
const DigitalIO digitalIO_PTB0     = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<0)};
const DigitalIO digitalIO_PTB1     = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<1)};
const DigitalIO digitalIO_PTB2     = {{&PORTB->PCR[2],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<2)};
const DigitalIO digitalIO_PTB3     = {{&PORTB->PCR[3],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<3)};
const DigitalIO digitalIO_PTB4     = {{&PORTB->PCR[4],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<4)};
const DigitalIO digitalIO_PTB5     = {{&PORTB->PCR[5],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<5)};
const DigitalIO digitalIO_PTB6     = {{&PORTB->PCR[6],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<6)};
const DigitalIO digitalIO_PTB7     = {{&PORTB->PCR[7],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<7)};
const DigitalIO digitalIO_PTC0     = {{&PORTC->PCR[0],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<0)};
const DigitalIO digitalIO_PTC1     = {{&PORTC->PCR[1],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<1)};
const DigitalIO digitalIO_PTC2     = {{&PORTC->PCR[2],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<2)};
const DigitalIO digitalIO_PTC3     = {{&PORTC->PCR[3],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<3)};
const DigitalIO digitalIO_PTC4     = {{&PORTC->PCR[4],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<4)};
const DigitalIO digitalIO_PTC5     = {{&PORTC->PCR[5],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<5)};
const DigitalIO digitalIO_PTC6     = {{&PORTC->PCR[6],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<6)};
const DigitalIO digitalIO_PTC7     = {{&PORTC->PCR[7],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<7)};
const DigitalIO digitalIO_PTD0     = {{&PORTD->PCR[0],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<0)};
const DigitalIO digitalIO_PTD1     = {{&PORTD->PCR[1],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<1)};
const DigitalIO digitalIO_PTD2     = {{&PORTD->PCR[2],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<2)};
const DigitalIO digitalIO_PTD3     = {{&PORTD->PCR[3],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<3)};
const DigitalIO digitalIO_PTD4     = {{&PORTD->PCR[4],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<4)};
const DigitalIO digitalIO_PTD5     = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<5)};
const DigitalIO digitalIO_PTD6     = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<6)};
const DigitalIO digitalIO_PTD7     = {{&PORTD->PCR[7],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<7)};
const DigitalIO digitalIO_PTE0     = {{&PORTE->PCR[0],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<0)};
const DigitalIO digitalIO_PTE1     = {{&PORTE->PCR[1],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<1)};
const DigitalIO digitalIO_PTE2     = {{&PORTE->PCR[2],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<2)};
const DigitalIO digitalIO_PTE3     = {{&PORTE->PCR[3],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<3)};
const DigitalIO digitalIO_PTE4     = {{&PORTE->PCR[4],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<4)};
const DigitalIO digitalIO_PTE5     = {{&PORTE->PCR[5],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<5)};
const DigitalIO digitalIO_PTE6     = {{&PORTE->PCR[6],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<6)};
const DigitalIO digitalIO_PTE7     = {{&PORTE->PCR[7],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<7)};
const DigitalIO digitalIO_PTF0     = {{&PORTF->PCR[0],   PORTF_CLOCK_MASK}, GPIOF,  (1UL<<0)};
const DigitalIO digitalIO_PTF1     = {{&PORTF->PCR[1],   PORTF_CLOCK_MASK}, GPIOF,  (1UL<<1)};
const DigitalIO digitalIO_PTF2     = {{&PORTF->PCR[2],   PORTF_CLOCK_MASK}, GPIOF,  (1UL<<2)};
const DigitalIO digitalIO_PTF3     = {{&PORTF->PCR[3],   PORTF_CLOCK_MASK}, GPIOF,  (1UL<<3)};
const DigitalIO digitalIO_PTF4     = {{&PORTF->PCR[4],   PORTF_CLOCK_MASK}, GPIOF,  (1UL<<4)};
const DigitalIO digitalIO_PTF5     = {{&PORTF->PCR[5],   PORTF_CLOCK_MASK}, GPIOF,  (1UL<<5)};
const DigitalIO digitalIO_PTF6     = {{&PORTF->PCR[6],   PORTF_CLOCK_MASK}, GPIOF,  (1UL<<6)};
const DigitalIO digitalIO_PTF7     = {{&PORTF->PCR[7],   PORTF_CLOCK_MASK}, GPIOF,  (1UL<<7)};
const DigitalIO digitalIO_PTG0     = {{&PORTG->PCR[0],   PORTG_CLOCK_MASK}, GPIOG,  (1UL<<0)};
const DigitalIO digitalIO_PTG1     = {{&PORTG->PCR[1],   PORTG_CLOCK_MASK}, GPIOG,  (1UL<<1)};
const DigitalIO digitalIO_PTG2     = {{&PORTG->PCR[2],   PORTG_CLOCK_MASK}, GPIOG,  (1UL<<2)};
const DigitalIO digitalIO_PTG3     = {{&PORTG->PCR[3],   PORTG_CLOCK_MASK}, GPIOG,  (1UL<<3)};
const DigitalIO digitalIO_PTG4     = {{&PORTG->PCR[4],   PORTG_CLOCK_MASK}, GPIOG,  (1UL<<4)};
const DigitalIO digitalIO_PTG5     = {{&PORTG->PCR[5],   PORTG_CLOCK_MASK}, GPIOG,  (1UL<<5)};
const DigitalIO digitalIO_PTG6     = {{&PORTG->PCR[6],   PORTG_CLOCK_MASK}, GPIOG,  (1UL<<6)};
const DigitalIO digitalIO_PTG7     = {{&PORTG->PCR[7],   PORTG_CLOCK_MASK}, GPIOG,  (1UL<<7)};
const DigitalIO digitalIO_PTH0     = {{&PORTH->PCR[0],   PORTH_CLOCK_MASK}, GPIOH,  (1UL<<0)};
const DigitalIO digitalIO_PTH1     = {{&PORTH->PCR[1],   PORTH_CLOCK_MASK}, GPIOH,  (1UL<<1)};
const DigitalIO digitalIO_PTH2     = {{&PORTH->PCR[2],   PORTH_CLOCK_MASK}, GPIOH,  (1UL<<2)};
const DigitalIO digitalIO_PTH3     = {{&PORTH->PCR[3],   PORTH_CLOCK_MASK}, GPIOH,  (1UL<<3)};
const DigitalIO digitalIO_PTH4     = {{&PORTH->PCR[4],   PORTH_CLOCK_MASK}, GPIOH,  (1UL<<4)};
const DigitalIO digitalIO_PTH5     = {{&PORTH->PCR[5],   PORTH_CLOCK_MASK}, GPIOH,  (1UL<<5)};
const DigitalIO digitalIO_PTH6     = {{&PORTH->PCR[6],   PORTH_CLOCK_MASK}, GPIOH,  (1UL<<6)};
const DigitalIO digitalIO_PTH7     = {{&PORTH->PCR[7],   PORTH_CLOCK_MASK}, GPIOH,  (1UL<<7)};
const DigitalIO digitalIO_PTI0     = {{&PORTI->PCR[0],   PORTI_CLOCK_MASK}, GPIOI,  (1UL<<0)};
const DigitalIO digitalIO_PTI1     = {{&PORTI->PCR[1],   PORTI_CLOCK_MASK}, GPIOI,  (1UL<<1)};
const DigitalIO digitalIO_PTI2     = {{&PORTI->PCR[2],   PORTI_CLOCK_MASK}, GPIOI,  (1UL<<2)};
const DigitalIO digitalIO_PTI3     = {{&PORTI->PCR[3],   PORTI_CLOCK_MASK}, GPIOI,  (1UL<<3)};
const AnalogueIO analogueIO_PTC5           = {{&PORTC->PCR[5],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    0};
const AnalogueIO analogueIO_PTC6           = {{&PORTC->PCR[6],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    1};
const AnalogueIO analogueIO_PTC7           = {{&PORTC->PCR[7],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    2};
const AnalogueIO analogueIO_PTD4           = {{&PORTD->PCR[4],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    3};
const AnalogueIO analogueIO_PTD5           = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    4};
const AnalogueIO analogueIO_PTD6           = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    5};
const AnalogueIO analogueIO_PTE7           = {{&PORTE->PCR[7],   PORTE_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    6};
const AnalogueIO analogueIO_PTF0           = {{&PORTF->PCR[0],   PORTF_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    7};
const AnalogueIO analogueIO_PTF1           = {{&PORTF->PCR[1],   PORTF_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    8};
const AnalogueIO analogueIO_PTF2           = {{&PORTF->PCR[2],   PORTF_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    9};
const AnalogueIO analogueIO_PTG1           = {{&PORTG->PCR[1],   PORTG_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    10};
const AnalogueIO analogueIO_PTG2           = {{&PORTG->PCR[2],   PORTG_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    11};
