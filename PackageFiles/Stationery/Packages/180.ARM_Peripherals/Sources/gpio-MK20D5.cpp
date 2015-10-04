 /**
  * @file     gpio.cpp (from gpio-MK20D5.cpp)
  *
  * @brief   Pin declarations for MK20D5
  */

#include "utilities.h"
#include "gpio.h"
#include "pin_mapping.h"

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

const DigitalIO digitalIO_PTA0     = {{&PORTA->PCR[0],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<0)};
const DigitalIO digitalIO_PTA1     = {{&PORTA->PCR[1],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<1)};
const DigitalIO digitalIO_PTA2     = {{&PORTA->PCR[2],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<2)};
const DigitalIO digitalIO_PTA3     = {{&PORTA->PCR[3],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<3)};
const DigitalIO digitalIO_PTA4     = {{&PORTA->PCR[4],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<4)};
const DigitalIO digitalIO_PTA5     = {{&PORTA->PCR[5],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<5)};
const DigitalIO digitalIO_PTA12    = {{&PORTA->PCR[12],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<12)};
const DigitalIO digitalIO_PTA13    = {{&PORTA->PCR[13],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<13)};
const DigitalIO digitalIO_PTA18    = {{&PORTA->PCR[18],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<18)};
const DigitalIO digitalIO_PTA19    = {{&PORTA->PCR[19],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<19)};
const DigitalIO digitalIO_PTB0     = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<0)};
const DigitalIO digitalIO_PTB1     = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<1)};
const DigitalIO digitalIO_PTB2     = {{&PORTB->PCR[2],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<2)};
const DigitalIO digitalIO_PTB3     = {{&PORTB->PCR[3],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<3)};
const DigitalIO digitalIO_PTB16    = {{&PORTB->PCR[16],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<16)};
const DigitalIO digitalIO_PTB17    = {{&PORTB->PCR[17],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<17)};
const DigitalIO digitalIO_PTB18    = {{&PORTB->PCR[18],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<18)};
const DigitalIO digitalIO_PTB19    = {{&PORTB->PCR[19],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<19)};
const DigitalIO digitalIO_PTC0     = {{&PORTC->PCR[0],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<0)};
const DigitalIO digitalIO_PTC1     = {{&PORTC->PCR[1],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<1)};
const DigitalIO digitalIO_PTC2     = {{&PORTC->PCR[2],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<2)};
const DigitalIO digitalIO_PTC3     = {{&PORTC->PCR[3],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<3)};
const DigitalIO digitalIO_PTC4     = {{&PORTC->PCR[4],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<4)};
const DigitalIO digitalIO_PTC5     = {{&PORTC->PCR[5],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<5)};
const DigitalIO digitalIO_PTC6     = {{&PORTC->PCR[6],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<6)};
const DigitalIO digitalIO_PTC7     = {{&PORTC->PCR[7],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<7)};
const DigitalIO digitalIO_PTC8     = {{&PORTC->PCR[8],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<8)};
const DigitalIO digitalIO_PTC9     = {{&PORTC->PCR[9],   PORTC_CLOCK_MASK}, GPIOC,  (1UL<<9)};
const DigitalIO digitalIO_PTC10    = {{&PORTC->PCR[10],  PORTC_CLOCK_MASK}, GPIOC,  (1UL<<10)};
const DigitalIO digitalIO_PTC11    = {{&PORTC->PCR[11],  PORTC_CLOCK_MASK}, GPIOC,  (1UL<<11)};
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
const AnalogueIO analogueIO_ADC0_DM0       = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    0};
const AnalogueIO analogueIO_ADC0_DM3       = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    3};
const AnalogueIO analogueIO_ADC0_DP0       = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    0};
const AnalogueIO analogueIO_ADC0_DP3       = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    3};
const AnalogueIO analogueIO_ADC0_SE23      = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    23};
const AnalogueIO analogueIO_PTB0           = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    8};
const AnalogueIO analogueIO_PTB1           = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    9};
const AnalogueIO analogueIO_PTB2           = {{&PORTB->PCR[2],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    12};
const AnalogueIO analogueIO_PTB3           = {{&PORTB->PCR[3],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    13};
const AnalogueIO analogueIO_PTC0           = {{&PORTC->PCR[0],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    14};
const AnalogueIO analogueIO_PTC1           = {{&PORTC->PCR[1],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    15};
const AnalogueIO analogueIO_PTC2           = {{&PORTC->PCR[2],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    4};
const AnalogueIO analogueIO_PTD1           = {{&PORTD->PCR[1],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    5};
const AnalogueIO analogueIO_PTD5           = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    6};
const AnalogueIO analogueIO_PTD6           = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    7};
const PwmIO  pwmIO_PTA0      = {{&PORTA->PCR[0],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   5,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA1      = {{&PORTA->PCR[1],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   6,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA2      = {{&PORTA->PCR[2],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   7,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA3      = {{&PORTA->PCR[3],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   0,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA4      = {{&PORTA->PCR[4],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   1,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA5      = {{&PORTA->PCR[5],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   2,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA12     = {{&PORTA->PCR[12],  PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM1,   0,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTA13     = {{&PORTA->PCR[13],  PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM1,   1,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTB0      = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM1,   0,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTB1      = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM1,   1,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTC1      = {{&PORTC->PCR[1],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   0,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTC2      = {{&PORTC->PCR[2],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   1,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTC3      = {{&PORTC->PCR[3],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   2,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTC4      = {{&PORTC->PCR[4],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   3,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTD4      = {{&PORTD->PCR[4],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   4,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTD5      = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   5,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTD6      = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   6,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTD7      = {{&PORTD->PCR[7],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   7,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
