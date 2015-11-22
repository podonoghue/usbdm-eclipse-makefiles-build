 /**
  * @file     gpio.cpp (from gpio-MK22F51212.cpp)
  *
  * @brief   Pin declarations for MK22F51212
  */

#include "utilities.h"
#include "gpio.h"
#include "pin_mapping.h"

const DigitalIO digitalIO_PTA0     = {{&PORTA->PCR[0],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<0)};
const DigitalIO digitalIO_PTA1     = {{&PORTA->PCR[1],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<1)};
const DigitalIO digitalIO_PTA2     = {{&PORTA->PCR[2],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<2)};
const DigitalIO digitalIO_PTA3     = {{&PORTA->PCR[3],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<3)};
const DigitalIO digitalIO_PTA4     = {{&PORTA->PCR[4],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<4)};
const DigitalIO digitalIO_PTA5     = {{&PORTA->PCR[5],   PORTA_CLOCK_MASK}, GPIOA,  (1UL<<5)};
const DigitalIO digitalIO_PTA12    = {{&PORTA->PCR[12],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<12)};
const DigitalIO digitalIO_PTA13    = {{&PORTA->PCR[13],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<13)};
const DigitalIO digitalIO_PTA14    = {{&PORTA->PCR[14],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<14)};
const DigitalIO digitalIO_PTA15    = {{&PORTA->PCR[15],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<15)};
const DigitalIO digitalIO_PTA16    = {{&PORTA->PCR[16],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<16)};
const DigitalIO digitalIO_PTA17    = {{&PORTA->PCR[17],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<17)};
const DigitalIO digitalIO_PTA18    = {{&PORTA->PCR[18],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<18)};
const DigitalIO digitalIO_PTA19    = {{&PORTA->PCR[19],  PORTA_CLOCK_MASK}, GPIOA,  (1UL<<19)};
const DigitalIO digitalIO_PTB0     = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<0)};
const DigitalIO digitalIO_PTB1     = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<1)};
const DigitalIO digitalIO_PTB2     = {{&PORTB->PCR[2],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<2)};
const DigitalIO digitalIO_PTB3     = {{&PORTB->PCR[3],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<3)};
const DigitalIO digitalIO_PTB6     = {{&PORTB->PCR[6],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<6)};
const DigitalIO digitalIO_PTB7     = {{&PORTB->PCR[7],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<7)};
const DigitalIO digitalIO_PTB8     = {{&PORTB->PCR[8],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<8)};
const DigitalIO digitalIO_PTB9     = {{&PORTB->PCR[9],   PORTB_CLOCK_MASK}, GPIOB,  (1UL<<9)};
const DigitalIO digitalIO_PTB10    = {{&PORTB->PCR[10],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<10)};
const DigitalIO digitalIO_PTB11    = {{&PORTB->PCR[11],  PORTB_CLOCK_MASK}, GPIOB,  (1UL<<11)};
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
const DigitalIO digitalIO_PTE0     = {{&PORTE->PCR[0],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<0)};
const DigitalIO digitalIO_PTE1     = {{&PORTE->PCR[1],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<1)};
const DigitalIO digitalIO_PTE2     = {{&PORTE->PCR[2],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<2)};
const DigitalIO digitalIO_PTE3     = {{&PORTE->PCR[3],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<3)};
const DigitalIO digitalIO_PTE4     = {{&PORTE->PCR[4],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<4)};
const DigitalIO digitalIO_PTE5     = {{&PORTE->PCR[5],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<5)};
const DigitalIO digitalIO_PTE6     = {{&PORTE->PCR[6],   PORTE_CLOCK_MASK}, GPIOE,  (1UL<<6)};
const DigitalIO digitalIO_PTE24    = {{&PORTE->PCR[24],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<24)};
const DigitalIO digitalIO_PTE25    = {{&PORTE->PCR[25],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<25)};
const DigitalIO digitalIO_PTE26    = {{&PORTE->PCR[26],  PORTE_CLOCK_MASK}, GPIOE,  (1UL<<26)};
const AnalogueIO analogueIO_ADC0_SE19      = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    19};
const AnalogueIO analogueIO_ADC0_SE20      = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    20};
const AnalogueIO analogueIO_ADC1_SE19      = {{0,                0         }, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    19};
const AnalogueIO analogueIO_ADC0_SE0       = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    0};
const AnalogueIO analogueIO_ADC0_SE1       = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    1};
const AnalogueIO analogueIO_ADC1_SE0       = {{0,                0         }, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    0};
const AnalogueIO analogueIO_ADC0_SE3       = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    3};
const AnalogueIO analogueIO_ADC0_SE23      = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    23};
const AnalogueIO analogueIO_ADC1_SE20      = {{0,                0         }, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    20};
const AnalogueIO analogueIO_ADC1_SE1       = {{0,                0         }, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    1};
const AnalogueIO analogueIO_ADC0_SE2       = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    2};
const AnalogueIO analogueIO_ADC1_SE18      = {{0,                0         }, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    18};
const AnalogueIO analogueIO_ADC1_SE23      = {{0,                0         }, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    23};
#if (PTA17_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE17      = {{&PORTA->PCR[17],  PORTA_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    17};
#endif
#if (PTB0_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE8       = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    8};
#endif
#if (PTB0_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE8       = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    8};
#endif
#if (PTB1_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE9       = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    9};
#endif
#if (PTB1_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE9       = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    9};
#endif
#if (PTB2_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE12      = {{&PORTB->PCR[2],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    12};
#endif
#if (PTB3_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE13      = {{&PORTB->PCR[3],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    13};
#endif
#if (PTB6_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE12      = {{&PORTB->PCR[6],   PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    12};
#endif
#if (PTB7_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE13      = {{&PORTB->PCR[7],   PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    13};
#endif
#if (PTB10_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE14      = {{&PORTB->PCR[10],  PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    14};
#endif
#if (PTB11_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE15      = {{&PORTB->PCR[11],  PORTB_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    15};
#endif
#if (PTC0_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE14      = {{&PORTC->PCR[0],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    14};
#endif
#if (PTC1_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE15      = {{&PORTC->PCR[1],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    15};
#endif
#if (PTC2_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE4b      = {{&PORTC->PCR[2],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    4};
#endif
#if (PTC8_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE4b      = {{&PORTC->PCR[8],   PORTC_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    4};
#endif
#if (PTC9_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE5b      = {{&PORTC->PCR[9],   PORTC_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    5};
#endif
#if (PTC10_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE6b      = {{&PORTC->PCR[10],  PORTC_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    6};
#endif
#if (PTC11_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE7b      = {{&PORTC->PCR[11],  PORTC_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    7};
#endif
#if (PTD1_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE5b      = {{&PORTD->PCR[1],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    5};
#endif
#if (PTD5_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE6b      = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    6};
#endif
#if (PTD6_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE7b      = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    7};
#endif
#if (PTE0_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE4a      = {{&PORTE->PCR[0],   PORTE_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    4};
#endif
#if (PTE1_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE5a      = {{&PORTE->PCR[1],   PORTE_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    5};
#endif
#if (PTE2_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE6a      = {{&PORTE->PCR[2],   PORTE_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    6};
#endif
#if (PTE3_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC1_SE7a      = {{&PORTE->PCR[3],   PORTE_CLOCK_MASK}, ADC1,     &ADC1_CLOCK_REG,    ADC1_CLOCK_MASK,    7};
#endif
#if (PTE24_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE17      = {{&PORTE->PCR[24],  PORTE_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    17};
#endif
#if (PTE25_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE18      = {{&PORTE->PCR[25],  PORTE_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    18};
#endif
#if (PTA0_SIG_SEL == 3)
const PwmIO  pwmIO_FTM0_CH5  = {{&PORTA->PCR[0],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   5,    PORT_PCR_MUX(3),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTA1_SIG_SEL == 3)
const PwmIO  pwmIO_FTM0_CH6  = {{&PORTA->PCR[1],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   6,    PORT_PCR_MUX(3),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTA2_SIG_SEL == 3)
const PwmIO  pwmIO_FTM0_CH7  = {{&PORTA->PCR[2],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   7,    PORT_PCR_MUX(3),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTA3_SIG_SEL == 3)
const PwmIO  pwmIO_FTM0_CH0  = {{&PORTA->PCR[3],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   0,    PORT_PCR_MUX(3),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTA4_SIG_SEL == 3)
const PwmIO  pwmIO_FTM0_CH1  = {{&PORTA->PCR[4],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   1,    PORT_PCR_MUX(3),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTA5_SIG_SEL == 3)
const PwmIO  pwmIO_FTM0_CH2  = {{&PORTA->PCR[5],   PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM0,   2,    PORT_PCR_MUX(3),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTA12_SIG_SEL == 3)
const PwmIO  pwmIO_FTM1_CH0  = {{&PORTA->PCR[12],  PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM1,   0,    PORT_PCR_MUX(3),&FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
#endif
#if (PTA13_SIG_SEL == 3)
const PwmIO  pwmIO_FTM1_CH1  = {{&PORTA->PCR[13],  PORTA_CLOCK_MASK},(volatile FTM_Type*)FTM1,   1,    PORT_PCR_MUX(3),&FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
#endif
#if (PTB0_SIG_SEL == 3)
const PwmIO  pwmIO_FTM1_CH0  = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM1,   0,    PORT_PCR_MUX(3),&FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
#endif
#if (PTB1_SIG_SEL == 3)
const PwmIO  pwmIO_FTM1_CH1  = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM1,   1,    PORT_PCR_MUX(3),&FTM1_CLOCK_REG,    FTM1_CLOCK_MASK, FTM1_SC};
#endif
#if (PTB18_SIG_SEL == 3)
const PwmIO  pwmIO_FTM2_CH0  = {{&PORTB->PCR[18],  PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM2,   0,    PORT_PCR_MUX(3),&FTM2_CLOCK_REG,    FTM2_CLOCK_MASK, FTM2_SC};
#endif
#if (PTB19_SIG_SEL == 3)
const PwmIO  pwmIO_FTM2_CH1  = {{&PORTB->PCR[19],  PORTB_CLOCK_MASK},(volatile FTM_Type*)FTM2,   1,    PORT_PCR_MUX(3),&FTM2_CLOCK_REG,    FTM2_CLOCK_MASK, FTM2_SC};
#endif
#if (PTC1_SIG_SEL == 4)
const PwmIO  pwmIO_FTM0_CH0  = {{&PORTC->PCR[1],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   0,    PORT_PCR_MUX(4),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTC2_SIG_SEL == 4)
const PwmIO  pwmIO_FTM0_CH1  = {{&PORTC->PCR[2],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   1,    PORT_PCR_MUX(4),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTC3_SIG_SEL == 4)
const PwmIO  pwmIO_FTM0_CH2  = {{&PORTC->PCR[3],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   2,    PORT_PCR_MUX(4),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTC4_SIG_SEL == 4)
const PwmIO  pwmIO_FTM0_CH3  = {{&PORTC->PCR[4],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   3,    PORT_PCR_MUX(4),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTC5_SIG_SEL == 7)
const PwmIO  pwmIO_FTM0_CH2  = {{&PORTC->PCR[5],   PORTC_CLOCK_MASK},(volatile FTM_Type*)FTM0,   2,    PORT_PCR_MUX(7),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTD4_SIG_SEL == 4)
const PwmIO  pwmIO_FTM0_CH4  = {{&PORTD->PCR[4],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   4,    PORT_PCR_MUX(4),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTD5_SIG_SEL == 4)
const PwmIO  pwmIO_FTM0_CH5  = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   5,    PORT_PCR_MUX(4),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTD6_SIG_SEL == 4)
const PwmIO  pwmIO_FTM0_CH6  = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   6,    PORT_PCR_MUX(4),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif
#if (PTD7_SIG_SEL == 4)
const PwmIO  pwmIO_FTM0_CH7  = {{&PORTD->PCR[7],   PORTD_CLOCK_MASK},(volatile FTM_Type*)FTM0,   7,    PORT_PCR_MUX(4),&FTM0_CLOCK_REG,    FTM0_CLOCK_MASK, FTM0_SC};
#endif

#if defined(DO_MAP_PINS_ON_RESET) && (DO_MAP_PINS_ON_RESET>0)
struct PinInit {
   uint32_t pcrValue;
   uint32_t volatile *pcr;
};

static const PinInit pinInit[] = {
#if defined(PTA0_SIG_SEL) && (PTA0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA0_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[0]},
#endif
#if defined(PTA1_SIG_SEL) && (PTA1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA1_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[1]},
#endif
#if defined(PTA2_SIG_SEL) && (PTA2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA2_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[2]},
#endif
#if defined(PTA3_SIG_SEL) && (PTA3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA3_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[3]},
#endif
#if defined(PTA4_SIG_SEL) && (PTA4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA4_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[4]},
#endif
#if defined(PTA5_SIG_SEL) && (PTA5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA5_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[5]},
#endif
#if defined(PTA12_SIG_SEL) && (PTA12_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA12_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[12]},
#endif
#if defined(PTA13_SIG_SEL) && (PTA13_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA13_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[13]},
#endif
#if defined(PTA14_SIG_SEL) && (PTA14_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA14_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[14]},
#endif
#if defined(PTA15_SIG_SEL) && (PTA15_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA15_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[15]},
#endif
#if defined(PTA16_SIG_SEL) && (PTA16_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA16_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[16]},
#endif
#if defined(PTA17_SIG_SEL) && (PTA17_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA17_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[17]},
#endif
#if defined(PTA18_SIG_SEL) && (PTA18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA18_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[18]},
#endif
#if defined(PTA19_SIG_SEL) && (PTA19_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA19_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[19]},
#endif
#if defined(PTB0_SIG_SEL) && (PTB0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB0_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[0]},
#endif
#if defined(PTB1_SIG_SEL) && (PTB1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB1_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[1]},
#endif
#if defined(PTB2_SIG_SEL) && (PTB2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB2_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[2]},
#endif
#if defined(PTB3_SIG_SEL) && (PTB3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB3_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[3]},
#endif
#if defined(PTB6_SIG_SEL) && (PTB6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB6_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[6]},
#endif
#if defined(PTB7_SIG_SEL) && (PTB7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB7_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[7]},
#endif
#if defined(PTB8_SIG_SEL) && (PTB8_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB8_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[8]},
#endif
#if defined(PTB9_SIG_SEL) && (PTB9_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB9_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[9]},
#endif
#if defined(PTB10_SIG_SEL) && (PTB10_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB10_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[10]},
#endif
#if defined(PTB11_SIG_SEL) && (PTB11_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB11_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[11]},
#endif
#if defined(PTB16_SIG_SEL) && (PTB16_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB16_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[16]},
#endif
#if defined(PTB17_SIG_SEL) && (PTB17_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB17_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[17]},
#endif
#if defined(PTB18_SIG_SEL) && (PTB18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB18_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[18]},
#endif
#if defined(PTB19_SIG_SEL) && (PTB19_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB19_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[19]},
#endif
#if defined(PTB20_SIG_SEL) && (PTB20_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB20_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[20]},
#endif
#if defined(PTB21_SIG_SEL) && (PTB21_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB21_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[21]},
#endif
#if defined(PTB22_SIG_SEL) && (PTB22_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB22_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[22]},
#endif
#if defined(PTB23_SIG_SEL) && (PTB23_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB23_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[23]},
#endif
#if defined(PTC0_SIG_SEL) && (PTC0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC0_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[0]},
#endif
#if defined(PTC1_SIG_SEL) && (PTC1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC1_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[1]},
#endif
#if defined(PTC2_SIG_SEL) && (PTC2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC2_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[2]},
#endif
#if defined(PTC3_SIG_SEL) && (PTC3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC3_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[3]},
#endif
#if defined(PTC4_SIG_SEL) && (PTC4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC4_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[4]},
#endif
#if defined(PTC5_SIG_SEL) && (PTC5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC5_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[5]},
#endif
#if defined(PTC6_SIG_SEL) && (PTC6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC6_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[6]},
#endif
#if defined(PTC7_SIG_SEL) && (PTC7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC7_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[7]},
#endif
#if defined(PTC8_SIG_SEL) && (PTC8_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC8_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[8]},
#endif
#if defined(PTC9_SIG_SEL) && (PTC9_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC9_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[9]},
#endif
#if defined(PTC10_SIG_SEL) && (PTC10_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC10_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[10]},
#endif
#if defined(PTC11_SIG_SEL) && (PTC11_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC11_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[11]},
#endif
#if defined(PTC12_SIG_SEL) && (PTC12_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC12_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[12]},
#endif
#if defined(PTC13_SIG_SEL) && (PTC13_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC13_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[13]},
#endif
#if defined(PTC14_SIG_SEL) && (PTC14_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC14_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[14]},
#endif
#if defined(PTC15_SIG_SEL) && (PTC15_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC15_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[15]},
#endif
#if defined(PTC16_SIG_SEL) && (PTC16_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC16_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[16]},
#endif
#if defined(PTC17_SIG_SEL) && (PTC17_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC17_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[17]},
#endif
#if defined(PTC18_SIG_SEL) && (PTC18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC18_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[18]},
#endif
#if defined(PTC19_SIG_SEL) && (PTC19_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC19_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTC->PCR[19]},
#endif
#if defined(PTD0_SIG_SEL) && (PTD0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD0_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTD->PCR[0]},
#endif
#if defined(PTD1_SIG_SEL) && (PTD1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD1_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTD->PCR[1]},
#endif
#if defined(PTD2_SIG_SEL) && (PTD2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD2_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTD->PCR[2]},
#endif
#if defined(PTD3_SIG_SEL) && (PTD3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD3_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTD->PCR[3]},
#endif
#if defined(PTD4_SIG_SEL) && (PTD4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD4_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTD->PCR[4]},
#endif
#if defined(PTD5_SIG_SEL) && (PTD5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD5_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTD->PCR[5]},
#endif
#if defined(PTD6_SIG_SEL) && (PTD6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD6_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTD->PCR[6]},
#endif
#if defined(PTD7_SIG_SEL) && (PTD7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD7_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTD->PCR[7]},
#endif
#if defined(PTE0_SIG_SEL) && (PTE0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE0_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[0]},
#endif
#if defined(PTE1_SIG_SEL) && (PTE1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE1_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[1]},
#endif
#if defined(PTE2_SIG_SEL) && (PTE2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE2_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[2]},
#endif
#if defined(PTE3_SIG_SEL) && (PTE3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE3_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[3]},
#endif
#if defined(PTE4_SIG_SEL) && (PTE4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE4_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[4]},
#endif
#if defined(PTE5_SIG_SEL) && (PTE5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE5_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[5]},
#endif
#if defined(PTE6_SIG_SEL) && (PTE6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE6_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[6]},
#endif
#if defined(PTE24_SIG_SEL) && (PTE24_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE24_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[24]},
#endif
#if defined(PTE25_SIG_SEL) && (PTE25_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE25_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[25]},
#endif
#if defined(PTE26_SIG_SEL) && (PTE26_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE26_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[26]},
#endif
};

/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
void usbdm_PinMapping() {
#if (defined(PTA0_SIG_SEL) && (PTA0_SIG_SEL>=0)) || \
    (defined(PTA1_SIG_SEL) && (PTA1_SIG_SEL>=0)) || \
    (defined(PTA2_SIG_SEL) && (PTA2_SIG_SEL>=0)) || \
    (defined(PTA3_SIG_SEL) && (PTA3_SIG_SEL>=0)) || \
    (defined(PTA4_SIG_SEL) && (PTA4_SIG_SEL>=0)) || \
    (defined(PTA5_SIG_SEL) && (PTA5_SIG_SEL>=0)) || \
    (defined(PTA12_SIG_SEL) && (PTA12_SIG_SEL>=0)) || \
    (defined(PTA13_SIG_SEL) && (PTA13_SIG_SEL>=0)) || \
    (defined(PTA14_SIG_SEL) && (PTA14_SIG_SEL>=0)) || \
    (defined(PTA15_SIG_SEL) && (PTA15_SIG_SEL>=0)) || \
    (defined(PTA16_SIG_SEL) && (PTA16_SIG_SEL>=0)) || \
    (defined(PTA17_SIG_SEL) && (PTA17_SIG_SEL>=0)) || \
    (defined(PTA18_SIG_SEL) && (PTA18_SIG_SEL>=0)) || \
    (defined(PTA19_SIG_SEL) && (PTA19_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTA_MASK;
#endif

#if (defined(PTB0_SIG_SEL) && (PTB0_SIG_SEL>=0)) || \
    (defined(PTB1_SIG_SEL) && (PTB1_SIG_SEL>=0)) || \
    (defined(PTB2_SIG_SEL) && (PTB2_SIG_SEL>=0)) || \
    (defined(PTB3_SIG_SEL) && (PTB3_SIG_SEL>=0)) || \
    (defined(PTB6_SIG_SEL) && (PTB6_SIG_SEL>=0)) || \
    (defined(PTB7_SIG_SEL) && (PTB7_SIG_SEL>=0)) || \
    (defined(PTB8_SIG_SEL) && (PTB8_SIG_SEL>=0)) || \
    (defined(PTB9_SIG_SEL) && (PTB9_SIG_SEL>=0)) || \
    (defined(PTB10_SIG_SEL) && (PTB10_SIG_SEL>=0)) || \
    (defined(PTB11_SIG_SEL) && (PTB11_SIG_SEL>=0)) || \
    (defined(PTB16_SIG_SEL) && (PTB16_SIG_SEL>=0)) || \
    (defined(PTB17_SIG_SEL) && (PTB17_SIG_SEL>=0)) || \
    (defined(PTB18_SIG_SEL) && (PTB18_SIG_SEL>=0)) || \
    (defined(PTB19_SIG_SEL) && (PTB19_SIG_SEL>=0)) || \
    (defined(PTB20_SIG_SEL) && (PTB20_SIG_SEL>=0)) || \
    (defined(PTB21_SIG_SEL) && (PTB21_SIG_SEL>=0)) || \
    (defined(PTB22_SIG_SEL) && (PTB22_SIG_SEL>=0)) || \
    (defined(PTB23_SIG_SEL) && (PTB23_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTB_MASK;
#endif

#if (defined(PTC0_SIG_SEL) && (PTC0_SIG_SEL>=0)) || \
    (defined(PTC1_SIG_SEL) && (PTC1_SIG_SEL>=0)) || \
    (defined(PTC2_SIG_SEL) && (PTC2_SIG_SEL>=0)) || \
    (defined(PTC3_SIG_SEL) && (PTC3_SIG_SEL>=0)) || \
    (defined(PTC4_SIG_SEL) && (PTC4_SIG_SEL>=0)) || \
    (defined(PTC5_SIG_SEL) && (PTC5_SIG_SEL>=0)) || \
    (defined(PTC6_SIG_SEL) && (PTC6_SIG_SEL>=0)) || \
    (defined(PTC7_SIG_SEL) && (PTC7_SIG_SEL>=0)) || \
    (defined(PTC8_SIG_SEL) && (PTC8_SIG_SEL>=0)) || \
    (defined(PTC9_SIG_SEL) && (PTC9_SIG_SEL>=0)) || \
    (defined(PTC10_SIG_SEL) && (PTC10_SIG_SEL>=0)) || \
    (defined(PTC11_SIG_SEL) && (PTC11_SIG_SEL>=0)) || \
    (defined(PTC12_SIG_SEL) && (PTC12_SIG_SEL>=0)) || \
    (defined(PTC13_SIG_SEL) && (PTC13_SIG_SEL>=0)) || \
    (defined(PTC14_SIG_SEL) && (PTC14_SIG_SEL>=0)) || \
    (defined(PTC15_SIG_SEL) && (PTC15_SIG_SEL>=0)) || \
    (defined(PTC16_SIG_SEL) && (PTC16_SIG_SEL>=0)) || \
    (defined(PTC17_SIG_SEL) && (PTC17_SIG_SEL>=0)) || \
    (defined(PTC18_SIG_SEL) && (PTC18_SIG_SEL>=0)) || \
    (defined(PTC19_SIG_SEL) && (PTC19_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTC_MASK;
#endif

#if (defined(PTD0_SIG_SEL) && (PTD0_SIG_SEL>=0)) || \
    (defined(PTD1_SIG_SEL) && (PTD1_SIG_SEL>=0)) || \
    (defined(PTD2_SIG_SEL) && (PTD2_SIG_SEL>=0)) || \
    (defined(PTD3_SIG_SEL) && (PTD3_SIG_SEL>=0)) || \
    (defined(PTD4_SIG_SEL) && (PTD4_SIG_SEL>=0)) || \
    (defined(PTD5_SIG_SEL) && (PTD5_SIG_SEL>=0)) || \
    (defined(PTD6_SIG_SEL) && (PTD6_SIG_SEL>=0)) || \
    (defined(PTD7_SIG_SEL) && (PTD7_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTD_MASK;
#endif

#if (defined(PTE0_SIG_SEL) && (PTE0_SIG_SEL>=0)) || \
    (defined(PTE1_SIG_SEL) && (PTE1_SIG_SEL>=0)) || \
    (defined(PTE2_SIG_SEL) && (PTE2_SIG_SEL>=0)) || \
    (defined(PTE3_SIG_SEL) && (PTE3_SIG_SEL>=0)) || \
    (defined(PTE4_SIG_SEL) && (PTE4_SIG_SEL>=0)) || \
    (defined(PTE5_SIG_SEL) && (PTE5_SIG_SEL>=0)) || \
    (defined(PTE6_SIG_SEL) && (PTE6_SIG_SEL>=0)) || \
    (defined(PTE24_SIG_SEL) && (PTE24_SIG_SEL>=0)) || \
    (defined(PTE25_SIG_SEL) && (PTE25_SIG_SEL>=0)) || \
    (defined(PTE26_SIG_SEL) && (PTE26_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTE_MASK;

#endif

   for (const PinInit *p=pinInit; p<(pinInit+(sizeof(pinInit)/sizeof(pinInit[0]))); p++) {
      *(p->pcr) = p->pcrValue;
   }
}
#endif

