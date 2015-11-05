 /**
  * @file     gpio.cpp (from gpio-MK20D5.cpp)
  *
  * @brief   Pin declarations for MK20D5
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
const AnalogueIO analogueIO_ADC0_SE19      = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    19};
const AnalogueIO analogueIO_ADC0_SE21      = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    21};
const AnalogueIO analogueIO_ADC0_SE0       = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    0};
const AnalogueIO analogueIO_ADC0_SE3       = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    3};
const AnalogueIO analogueIO_ADC0_SE23      = {{0,                0         }, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    23};
#if (PTB0_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE8       = {{&PORTB->PCR[0],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    8};
#endif
#if (PTB1_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE9       = {{&PORTB->PCR[1],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    9};
#endif
#if (PTB2_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE12      = {{&PORTB->PCR[2],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    12};
#endif
#if (PTB3_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE13      = {{&PORTB->PCR[3],   PORTB_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    13};
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
#if (PTD1_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE5b      = {{&PORTD->PCR[1],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    5};
#endif
#if (PTD5_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE6b      = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    6};
#endif
#if (PTD6_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE7b      = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    7};
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
    (defined(PTA18_SIG_SEL) && (PTA18_SIG_SEL>=0)) || \
    (defined(PTA19_SIG_SEL) && (PTA19_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTA_MASK;
#endif

#if (defined(PTB0_SIG_SEL) && (PTB0_SIG_SEL>=0)) || \
    (defined(PTB1_SIG_SEL) && (PTB1_SIG_SEL>=0)) || \
    (defined(PTB2_SIG_SEL) && (PTB2_SIG_SEL>=0)) || \
    (defined(PTB3_SIG_SEL) && (PTB3_SIG_SEL>=0)) || \
    (defined(PTB16_SIG_SEL) && (PTB16_SIG_SEL>=0)) || \
    (defined(PTB17_SIG_SEL) && (PTB17_SIG_SEL>=0)) || \
    (defined(PTB18_SIG_SEL) && (PTB18_SIG_SEL>=0)) || \
    (defined(PTB19_SIG_SEL) && (PTB19_SIG_SEL>=0))

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
    (defined(PTC11_SIG_SEL) && (PTC11_SIG_SEL>=0))

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
    (defined(PTE1_SIG_SEL) && (PTE1_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTE_MASK;

#endif

   for (const PinInit *p=pinInit; p<(pinInit+(sizeof(pinInit)/sizeof(pinInit[0]))); p++) {
      *(p->pcr) = p->pcrValue;
   }
}
#endif

