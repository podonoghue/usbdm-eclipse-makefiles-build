 /**
  * @file     gpio.cpp (from gpio-MK64F12.cpp)
  *
  * @brief   Pin declarations for MK64F12
  */

#include "utilities.h"
#include "gpio.h"
#include "pin_mapping.h"

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

const DigitalIO digitalIO_PTA0     = {{&PORTA->PCR[0],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<0)};
const DigitalIO digitalIO_PTA1     = {{&PORTA->PCR[1],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<1)};
const DigitalIO digitalIO_PTA2     = {{&PORTA->PCR[2],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<2)};
const DigitalIO digitalIO_PTA3     = {{&PORTA->PCR[3],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<3)};
const DigitalIO digitalIO_PTA4     = {{&PORTA->PCR[4],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<4)};
const DigitalIO digitalIO_PTA5     = {{&PORTA->PCR[5],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<5)};
const DigitalIO digitalIO_PTA6     = {{&PORTA->PCR[6],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<6)};
const DigitalIO digitalIO_PTA7     = {{&PORTA->PCR[7],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<7)};
const DigitalIO digitalIO_PTA8     = {{&PORTA->PCR[8],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<8)};
const DigitalIO digitalIO_PTA9     = {{&PORTA->PCR[9],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<9)};
const DigitalIO digitalIO_PTA10    = {{&PORTA->PCR[10],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<10)};
const DigitalIO digitalIO_PTA11    = {{&PORTA->PCR[11],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<11)};
const DigitalIO digitalIO_PTA12    = {{&PORTA->PCR[12],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<12)};
const DigitalIO digitalIO_PTA13    = {{&PORTA->PCR[13],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<13)};
const DigitalIO digitalIO_PTA14    = {{&PORTA->PCR[14],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<14)};
const DigitalIO digitalIO_PTA15    = {{&PORTA->PCR[15],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<15)};
const DigitalIO digitalIO_PTA16    = {{&PORTA->PCR[16],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<16)};
const DigitalIO digitalIO_PTA17    = {{&PORTA->PCR[17],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<17)};
const DigitalIO digitalIO_PTA18    = {{&PORTA->PCR[18],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<18)};
const DigitalIO digitalIO_PTA19    = {{&PORTA->PCR[19],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<19)};
const DigitalIO digitalIO_PTA24    = {{&PORTA->PCR[24],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<24)};
const DigitalIO digitalIO_PTA25    = {{&PORTA->PCR[25],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<25)};
const DigitalIO digitalIO_PTA26    = {{&PORTA->PCR[26],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<26)};
const DigitalIO digitalIO_PTA27    = {{&PORTA->PCR[27],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<27)};
const DigitalIO digitalIO_PTA28    = {{&PORTA->PCR[28],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<28)};
const DigitalIO digitalIO_PTA29    = {{&PORTA->PCR[29],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<29)};
const DigitalIO digitalIO_PTB0     = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<0)};
const DigitalIO digitalIO_PTB1     = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<1)};
const DigitalIO digitalIO_PTB2     = {{&PORTB->PCR[2],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<2)};
const DigitalIO digitalIO_PTB3     = {{&PORTB->PCR[3],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<3)};
const DigitalIO digitalIO_PTB4     = {{&PORTB->PCR[4],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<4)};
const DigitalIO digitalIO_PTB5     = {{&PORTB->PCR[5],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<5)};
const DigitalIO digitalIO_PTB6     = {{&PORTB->PCR[6],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<6)};
const DigitalIO digitalIO_PTB7     = {{&PORTB->PCR[7],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<7)};
const DigitalIO digitalIO_PTB8     = {{&PORTB->PCR[8],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<8)};
const DigitalIO digitalIO_PTB9     = {{&PORTB->PCR[9],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<9)};
const DigitalIO digitalIO_PTB10    = {{&PORTB->PCR[10],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<10)};
const DigitalIO digitalIO_PTB11    = {{&PORTB->PCR[11],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<11)};
const DigitalIO digitalIO_PTB12    = {{&PORTB->PCR[12],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<12)};
const DigitalIO digitalIO_PTB13    = {{&PORTB->PCR[13],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<13)};
const DigitalIO digitalIO_PTB16    = {{&PORTB->PCR[16],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<16)};
const DigitalIO digitalIO_PTB17    = {{&PORTB->PCR[17],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<17)};
const DigitalIO digitalIO_PTB18    = {{&PORTB->PCR[18],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<18)};
const DigitalIO digitalIO_PTB19    = {{&PORTB->PCR[19],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<19)};
const DigitalIO digitalIO_PTB20    = {{&PORTB->PCR[20],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<20)};
const DigitalIO digitalIO_PTB21    = {{&PORTB->PCR[21],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<21)};
const DigitalIO digitalIO_PTB22    = {{&PORTB->PCR[22],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<22)};
const DigitalIO digitalIO_PTB23    = {{&PORTB->PCR[23],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<23)};
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
const DigitalIO digitalIO_PTC12    = {{&PORTC->PCR[12],  PORTC_CLOCK_MASK}, GPIOC,  (1UL<<12)};
const DigitalIO digitalIO_PTC13    = {{&PORTC->PCR[13],  PORTC_CLOCK_MASK}, GPIOC,  (1UL<<13)};
const DigitalIO digitalIO_PTC14    = {{&PORTC->PCR[14],  PORTC_CLOCK_MASK}, GPIOC,  (1UL<<14)};
const DigitalIO digitalIO_PTC15    = {{&PORTC->PCR[15],  PORTC_CLOCK_MASK}, GPIOC,  (1UL<<15)};
const DigitalIO digitalIO_PTC16    = {{&PORTC->PCR[16],  PORTC_CLOCK_MASK}, GPIOC,  (1UL<<16)};
const DigitalIO digitalIO_PTC17    = {{&PORTC->PCR[17],  PORTC_CLOCK_MASK}, GPIOC,  (1UL<<17)};
const DigitalIO digitalIO_PTC18    = {{&PORTC->PCR[18],  PORTC_CLOCK_MASK}, GPIOC,  (1UL<<18)};
const DigitalIO digitalIO_PTC19    = {{&PORTC->PCR[19],  PORTC_CLOCK_MASK}, GPIOC,  (1UL<<19)};
const DigitalIO digitalIO_PTD0     = {{&PORTD->PCR[0],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<0)};
const DigitalIO digitalIO_PTD1     = {{&PORTD->PCR[1],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<1)};
const DigitalIO digitalIO_PTD2     = {{&PORTD->PCR[2],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<2)};
const DigitalIO digitalIO_PTD3     = {{&PORTD->PCR[3],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<3)};
const DigitalIO digitalIO_PTD4     = {{&PORTD->PCR[4],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<4)};
const DigitalIO digitalIO_PTD5     = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<5)};
const DigitalIO digitalIO_PTD6     = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<6)};
const DigitalIO digitalIO_PTD7     = {{&PORTD->PCR[7],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<7)};
const DigitalIO digitalIO_PTD8     = {{&PORTD->PCR[8],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<8)};
const DigitalIO digitalIO_PTD9     = {{&PORTD->PCR[9],   PORTD_CLOCK_MASK}, GPIOD,  (1UL<<9)};
const DigitalIO digitalIO_PTD10    = {{&PORTD->PCR[10],  PORTD_CLOCK_MASK}, GPIOD,  (1UL<<10)};
const DigitalIO digitalIO_PTD11    = {{&PORTD->PCR[11],  PORTD_CLOCK_MASK}, GPIOD,  (1UL<<11)};
const DigitalIO digitalIO_PTD12    = {{&PORTD->PCR[12],  PORTD_CLOCK_MASK}, GPIOD,  (1UL<<12)};
const DigitalIO digitalIO_PTD13    = {{&PORTD->PCR[13],  PORTD_CLOCK_MASK}, GPIOD,  (1UL<<13)};
const DigitalIO digitalIO_PTD14    = {{&PORTD->PCR[14],  PORTD_CLOCK_MASK}, GPIOD,  (1UL<<14)};
const DigitalIO digitalIO_PTD15    = {{&PORTD->PCR[15],  PORTD_CLOCK_MASK}, GPIOD,  (1UL<<15)};
const DigitalIO digitalIO_PTE0     = {{&PORTE->PCR[0],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<0)};
const DigitalIO digitalIO_PTE1     = {{&PORTE->PCR[1],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<1)};
const DigitalIO digitalIO_PTE2     = {{&PORTE->PCR[2],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<2)};
const DigitalIO digitalIO_PTE3     = {{&PORTE->PCR[3],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<3)};
const DigitalIO digitalIO_PTE4     = {{&PORTE->PCR[4],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<4)};
const DigitalIO digitalIO_PTE5     = {{&PORTE->PCR[5],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<5)};
const DigitalIO digitalIO_PTE6     = {{&PORTE->PCR[6],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<6)};
const DigitalIO digitalIO_PTE7     = {{&PORTE->PCR[7],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<7)};
const DigitalIO digitalIO_PTE8     = {{&PORTE->PCR[8],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<8)};
const DigitalIO digitalIO_PTE9     = {{&PORTE->PCR[9],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<9)};
const DigitalIO digitalIO_PTE10    = {{&PORTE->PCR[10],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<10)};
const DigitalIO digitalIO_PTE11    = {{&PORTE->PCR[11],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<11)};
const DigitalIO digitalIO_PTE12    = {{&PORTE->PCR[12],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<12)};
const DigitalIO digitalIO_PTE24    = {{&PORTE->PCR[24],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<24)};
const DigitalIO digitalIO_PTE25    = {{&PORTE->PCR[25],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<25)};
const DigitalIO digitalIO_PTE26    = {{&PORTE->PCR[26],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<26)};
const DigitalIO digitalIO_PTE27    = {{&PORTE->PCR[27],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<27)};
const DigitalIO digitalIO_PTE28    = {{&PORTE->PCR[28],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<28)};
const AnalogueIO analogueIO_ADC0_DM0       = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    0};
const AnalogueIO analogueIO_ADC0_DM0_1     = {{0,0}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    3};
const AnalogueIO analogueIO_ADC0_DM1       = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    1};
const AnalogueIO analogueIO_ADC0_DP0       = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    0};
const AnalogueIO analogueIO_ADC0_DP0_1     = {{0,0}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    3};
const AnalogueIO analogueIO_ADC0_DP1       = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    1};
const AnalogueIO analogueIO_ADC0_SE16      = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    16};
const AnalogueIO analogueIO_ADC0_SE16_1    = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    21};
const AnalogueIO analogueIO_ADC0_SE23      = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    23};
const AnalogueIO analogueIO_ADC1_DM0       = {{0,0}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    0};
const AnalogueIO analogueIO_ADC1_DM0_1     = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    3};
const AnalogueIO analogueIO_ADC1_DM1       = {{0,0}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    1};
const AnalogueIO analogueIO_ADC1_DP0       = {{0,0}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    0};
const AnalogueIO analogueIO_ADC1_DP0_1     = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    3};
const AnalogueIO analogueIO_ADC1_DP1       = {{0,0}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    1};
const AnalogueIO analogueIO_ADC1_SE16      = {{0,0}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    16};
const AnalogueIO analogueIO_ADC1_SE16_1    = {{0,0}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    22};
const AnalogueIO analogueIO_ADC1_SE18      = {{0,0}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    18};
const AnalogueIO analogueIO_ADC1_SE23      = {{0,0}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    23};
const AnalogueIO analogueIO_PTA7           = {{&PORTA->PCR[7],   PORTA_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    10};
const AnalogueIO analogueIO_PTA8           = {{&PORTA->PCR[8],   PORTA_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    11};
const AnalogueIO analogueIO_PTA17          = {{&PORTA->PCR[17],  PORTA_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    17};
const AnalogueIO analogueIO_PTB0           = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    8};
const AnalogueIO analogueIO_PTB0_1         = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    8};
const AnalogueIO analogueIO_PTB1           = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    9};
const AnalogueIO analogueIO_PTB1_1         = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    9};
const AnalogueIO analogueIO_PTB2           = {{&PORTB->PCR[2],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    12};
const AnalogueIO analogueIO_PTB3           = {{&PORTB->PCR[3],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    13};
const AnalogueIO analogueIO_PTB4           = {{&PORTB->PCR[4],   PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    10};
const AnalogueIO analogueIO_PTB5           = {{&PORTB->PCR[5],   PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    11};
const AnalogueIO analogueIO_PTB6           = {{&PORTB->PCR[6],   PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    12};
const AnalogueIO analogueIO_PTB7           = {{&PORTB->PCR[7],   PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    13};
const AnalogueIO analogueIO_PTB10          = {{&PORTB->PCR[10],  PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    14};
const AnalogueIO analogueIO_PTB11          = {{&PORTB->PCR[11],  PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    15};
const AnalogueIO analogueIO_PTC0           = {{&PORTC->PCR[0],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    14};
const AnalogueIO analogueIO_PTC1           = {{&PORTC->PCR[1],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    15};
const AnalogueIO analogueIO_PTC2           = {{&PORTC->PCR[2],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    4};
const AnalogueIO analogueIO_PTC8           = {{&PORTC->PCR[8],   PORTC_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    4};
const AnalogueIO analogueIO_PTC9           = {{&PORTC->PCR[9],   PORTC_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    5};
const AnalogueIO analogueIO_PTC10          = {{&PORTC->PCR[10],  PORTC_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    6};
const AnalogueIO analogueIO_PTC11          = {{&PORTC->PCR[11],  PORTC_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    7};
const AnalogueIO analogueIO_PTD1           = {{&PORTD->PCR[1],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    5};
const AnalogueIO analogueIO_PTD5           = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    6};
const AnalogueIO analogueIO_PTD6           = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    7};
const AnalogueIO analogueIO_PTE0           = {{&PORTE->PCR[0],   PORTE_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    4};
const AnalogueIO analogueIO_PTE1           = {{&PORTE->PCR[1],   PORTE_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    5};
const AnalogueIO analogueIO_PTE2           = {{&PORTE->PCR[2],   PORTE_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    2};
const AnalogueIO analogueIO_PTE2_1         = {{&PORTE->PCR[2],   PORTE_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    6};
const AnalogueIO analogueIO_PTE3           = {{&PORTE->PCR[3],   PORTE_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    2};
const AnalogueIO analogueIO_PTE3_1         = {{&PORTE->PCR[3],   PORTE_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    7};
const AnalogueIO analogueIO_PTE24          = {{&PORTE->PCR[24],  PORTE_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    17};
const AnalogueIO analogueIO_PTE25          = {{&PORTE->PCR[25],  PORTE_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    18};
const PwmIO  pwmIO_PTA0      = {{&PORTA->PCR[0],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   5,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA1      = {{&PORTA->PCR[1],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   6,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA2      = {{&PORTA->PCR[2],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   7,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA3      = {{&PORTA->PCR[3],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   0,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA4      = {{&PORTA->PCR[4],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   1,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA5      = {{&PORTA->PCR[5],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   2,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA6      = {{&PORTA->PCR[6],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   3,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA7      = {{&PORTA->PCR[7],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   4,    3,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTA8      = {{&PORTA->PCR[8],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM1,   0,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTA9      = {{&PORTA->PCR[9],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM1,   1,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTA10     = {{&PORTA->PCR[10],  PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM2,   0,    3,    &FTM2_CLOCK_REG,    FTM2_CLOCK_MASK, FTM2_SC};
const PwmIO  pwmIO_PTA11     = {{&PORTA->PCR[11],  PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM2,   1,    3,    &FTM2_CLOCK_REG,    FTM2_CLOCK_MASK, FTM2_SC};
const PwmIO  pwmIO_PTA12     = {{&PORTA->PCR[12],  PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM1,   0,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTA13     = {{&PORTA->PCR[13],  PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM1,   1,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTB0      = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM1,   0,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTB1      = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM1,   1,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTB12     = {{&PORTB->PCR[12],  PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM1,   0,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTB12     = {{&PORTB->PCR[12],  PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM0,   4,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTB13     = {{&PORTB->PCR[13],  PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM1,   1,    3,    &FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
const PwmIO  pwmIO_PTB13     = {{&PORTB->PCR[13],  PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM0,   5,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTB18     = {{&PORTB->PCR[18],  PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM2,   0,    3,    &FTM2_CLOCK_REG,    FTM2_CLOCK_MASK, FTM2_SC};
const PwmIO  pwmIO_PTB19     = {{&PORTB->PCR[19],  PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM2,   1,    3,    &FTM2_CLOCK_REG,    FTM2_CLOCK_MASK, FTM2_SC};
const PwmIO  pwmIO_PTC1      = {{&PORTC->PCR[1],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   0,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTC2      = {{&PORTC->PCR[2],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   1,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTC3      = {{&PORTC->PCR[3],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   2,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTC4      = {{&PORTC->PCR[4],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   3,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTC5      = {{&PORTC->PCR[5],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   2,    7,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTC8      = {{&PORTC->PCR[8],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM3,   4,    3,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTC9      = {{&PORTC->PCR[9],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM3,   5,    3,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTC10     = {{&PORTC->PCR[10],  PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM3,   6,    3,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTC11     = {{&PORTC->PCR[11],  PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM3,   7,    3,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTD0      = {{&PORTD->PCR[0],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM3,   0,    4,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTD1      = {{&PORTD->PCR[1],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM3,   1,    4,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTD2      = {{&PORTD->PCR[2],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM3,   2,    4,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTD3      = {{&PORTD->PCR[3],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM3,   3,    4,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTD4      = {{&PORTD->PCR[4],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   4,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTD5      = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   5,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTD6      = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   6,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTD7      = {{&PORTD->PCR[7],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   7,    4,    &FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
const PwmIO  pwmIO_PTE5      = {{&PORTE->PCR[5],   PORTE_CLOCK_MASK},(volatile FTM_Type*)FTM3,   0,    6,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTE6      = {{&PORTE->PCR[6],   PORTE_CLOCK_MASK},(volatile FTM_Type*)FTM3,   1,    6,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTE7      = {{&PORTE->PCR[7],   PORTE_CLOCK_MASK},(volatile FTM_Type*)FTM3,   2,    6,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTE8      = {{&PORTE->PCR[8],   PORTE_CLOCK_MASK},(volatile FTM_Type*)FTM3,   3,    6,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTE9      = {{&PORTE->PCR[9],   PORTE_CLOCK_MASK},(volatile FTM_Type*)FTM3,   4,    6,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTE10     = {{&PORTE->PCR[10],  PORTE_CLOCK_MASK},(volatile FTM_Type*)FTM3,   5,    6,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTE11     = {{&PORTE->PCR[11],  PORTE_CLOCK_MASK},(volatile FTM_Type*)FTM3,   6,    6,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
const PwmIO  pwmIO_PTE12     = {{&PORTE->PCR[12],  PORTE_CLOCK_MASK},(volatile FTM_Type*)FTM3,   7,    6,    &FTM3_CLOCK_REG,    FTM3_CLOCK_MASK, FTM3_SC};
