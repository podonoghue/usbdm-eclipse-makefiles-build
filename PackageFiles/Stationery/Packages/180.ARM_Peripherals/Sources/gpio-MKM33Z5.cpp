 /**
  * @file     gpio.cpp (from gpio-MKM33Z5.cpp)
  *
  * @brief   Pin declarations for MKM33Z5
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
#if (PTC5_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE0       = {{&PORTC->PCR[5],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    0};
#endif
#if (PTC6_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE1       = {{&PORTC->PCR[6],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    1};
#endif
#if (PTC7_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE2       = {{&PORTC->PCR[7],   PORTC_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    2};
#endif
#if (PTD4_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE3       = {{&PORTD->PCR[4],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    3};
#endif
#if (PTD5_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE4       = {{&PORTD->PCR[5],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    4};
#endif
#if (PTD6_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE5       = {{&PORTD->PCR[6],   PORTD_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    5};
#endif
#if (PTE7_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE6       = {{&PORTE->PCR[7],   PORTE_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    6};
#endif
#if (PTF0_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE7       = {{&PORTF->PCR[0],   PORTF_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    7};
#endif
#if (PTF1_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE8       = {{&PORTF->PCR[1],   PORTF_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    8};
#endif
#if (PTF2_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE9       = {{&PORTF->PCR[2],   PORTF_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    9};
#endif
#if (PTG1_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE10      = {{&PORTG->PCR[1],   PORTG_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    10};
#endif
#if (PTG2_SIG_SEL == 0)
const AnalogueIO analogueIO_ADC0_SE11      = {{&PORTG->PCR[2],   PORTG_CLOCK_MASK}, ADC0,     &ADC0_CLOCK_REG,    ADC0_CLOCK_MASK,    11};
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
#if defined(PTA6_SIG_SEL) && (PTA6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA6_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[6]},
#endif
#if defined(PTA7_SIG_SEL) && (PTA7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA7_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTA->PCR[7]},
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
#if defined(PTB4_SIG_SEL) && (PTB4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB4_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[4]},
#endif
#if defined(PTB5_SIG_SEL) && (PTB5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB5_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[5]},
#endif
#if defined(PTB6_SIG_SEL) && (PTB6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB6_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[6]},
#endif
#if defined(PTB7_SIG_SEL) && (PTB7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB7_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTB->PCR[7]},
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
#if defined(PTE7_SIG_SEL) && (PTE7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE7_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTE->PCR[7]},
#endif
#if defined(PTF0_SIG_SEL) && (PTF0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF0_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTF->PCR[0]},
#endif
#if defined(PTF1_SIG_SEL) && (PTF1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF1_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTF->PCR[1]},
#endif
#if defined(PTF2_SIG_SEL) && (PTF2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF2_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTF->PCR[2]},
#endif
#if defined(PTF3_SIG_SEL) && (PTF3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF3_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTF->PCR[3]},
#endif
#if defined(PTF4_SIG_SEL) && (PTF4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF4_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTF->PCR[4]},
#endif
#if defined(PTF5_SIG_SEL) && (PTF5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF5_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTF->PCR[5]},
#endif
#if defined(PTF6_SIG_SEL) && (PTF6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF6_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTF->PCR[6]},
#endif
#if defined(PTF7_SIG_SEL) && (PTF7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF7_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTF->PCR[7]},
#endif
#if defined(PTG0_SIG_SEL) && (PTG0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG0_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTG->PCR[0]},
#endif
#if defined(PTG1_SIG_SEL) && (PTG1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG1_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTG->PCR[1]},
#endif
#if defined(PTG2_SIG_SEL) && (PTG2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG2_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTG->PCR[2]},
#endif
#if defined(PTG3_SIG_SEL) && (PTG3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG3_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTG->PCR[3]},
#endif
#if defined(PTG4_SIG_SEL) && (PTG4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG4_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTG->PCR[4]},
#endif
#if defined(PTG5_SIG_SEL) && (PTG5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG5_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTG->PCR[5]},
#endif
#if defined(PTG6_SIG_SEL) && (PTG6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG6_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTG->PCR[6]},
#endif
#if defined(PTG7_SIG_SEL) && (PTG7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG7_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTG->PCR[7]},
#endif
#if defined(PTH0_SIG_SEL) && (PTH0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH0_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTH->PCR[0]},
#endif
#if defined(PTH1_SIG_SEL) && (PTH1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH1_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTH->PCR[1]},
#endif
#if defined(PTH2_SIG_SEL) && (PTH2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH2_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTH->PCR[2]},
#endif
#if defined(PTH3_SIG_SEL) && (PTH3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH3_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTH->PCR[3]},
#endif
#if defined(PTH4_SIG_SEL) && (PTH4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH4_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTH->PCR[4]},
#endif
#if defined(PTH5_SIG_SEL) && (PTH5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH5_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTH->PCR[5]},
#endif
#if defined(PTH6_SIG_SEL) && (PTH6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH6_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTH->PCR[6]},
#endif
#if defined(PTH7_SIG_SEL) && (PTH7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH7_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTH->PCR[7]},
#endif
#if defined(PTI0_SIG_SEL) && (PTI0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI0_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTI->PCR[0]},
#endif
#if defined(PTI1_SIG_SEL) && (PTI1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI1_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTI->PCR[1]},
#endif
#if defined(PTI2_SIG_SEL) && (PTI2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI2_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTI->PCR[2]},
#endif
#if defined(PTI3_SIG_SEL) && (PTI3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI3_SIG_SEL)|DigitalIO::DEFAULT_PCR, &PORTI->PCR[3]},
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
    (defined(PTA6_SIG_SEL) && (PTA6_SIG_SEL>=0)) || \
    (defined(PTA7_SIG_SEL) && (PTA7_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTA_MASK;
#endif

#if (defined(PTB0_SIG_SEL) && (PTB0_SIG_SEL>=0)) || \
    (defined(PTB1_SIG_SEL) && (PTB1_SIG_SEL>=0)) || \
    (defined(PTB2_SIG_SEL) && (PTB2_SIG_SEL>=0)) || \
    (defined(PTB3_SIG_SEL) && (PTB3_SIG_SEL>=0)) || \
    (defined(PTB4_SIG_SEL) && (PTB4_SIG_SEL>=0)) || \
    (defined(PTB5_SIG_SEL) && (PTB5_SIG_SEL>=0)) || \
    (defined(PTB6_SIG_SEL) && (PTB6_SIG_SEL>=0)) || \
    (defined(PTB7_SIG_SEL) && (PTB7_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTB_MASK;
#endif

#if (defined(PTC0_SIG_SEL) && (PTC0_SIG_SEL>=0)) || \
    (defined(PTC1_SIG_SEL) && (PTC1_SIG_SEL>=0)) || \
    (defined(PTC2_SIG_SEL) && (PTC2_SIG_SEL>=0)) || \
    (defined(PTC3_SIG_SEL) && (PTC3_SIG_SEL>=0)) || \
    (defined(PTC4_SIG_SEL) && (PTC4_SIG_SEL>=0)) || \
    (defined(PTC5_SIG_SEL) && (PTC5_SIG_SEL>=0)) || \
    (defined(PTC6_SIG_SEL) && (PTC6_SIG_SEL>=0)) || \
    (defined(PTC7_SIG_SEL) && (PTC7_SIG_SEL>=0))

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
    (defined(PTE7_SIG_SEL) && (PTE7_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTE_MASK;
#endif

#if (defined(PTF0_SIG_SEL) && (PTF0_SIG_SEL>=0)) || \
    (defined(PTF1_SIG_SEL) && (PTF1_SIG_SEL>=0)) || \
    (defined(PTF2_SIG_SEL) && (PTF2_SIG_SEL>=0)) || \
    (defined(PTF3_SIG_SEL) && (PTF3_SIG_SEL>=0)) || \
    (defined(PTF4_SIG_SEL) && (PTF4_SIG_SEL>=0)) || \
    (defined(PTF5_SIG_SEL) && (PTF5_SIG_SEL>=0)) || \
    (defined(PTF6_SIG_SEL) && (PTF6_SIG_SEL>=0)) || \
    (defined(PTF7_SIG_SEL) && (PTF7_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTF_MASK;
#endif

#if (defined(PTG0_SIG_SEL) && (PTG0_SIG_SEL>=0)) || \
    (defined(PTG1_SIG_SEL) && (PTG1_SIG_SEL>=0)) || \
    (defined(PTG2_SIG_SEL) && (PTG2_SIG_SEL>=0)) || \
    (defined(PTG3_SIG_SEL) && (PTG3_SIG_SEL>=0)) || \
    (defined(PTG4_SIG_SEL) && (PTG4_SIG_SEL>=0)) || \
    (defined(PTG5_SIG_SEL) && (PTG5_SIG_SEL>=0)) || \
    (defined(PTG6_SIG_SEL) && (PTG6_SIG_SEL>=0)) || \
    (defined(PTG7_SIG_SEL) && (PTG7_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTG_MASK;
#endif

#if (defined(PTH0_SIG_SEL) && (PTH0_SIG_SEL>=0)) || \
    (defined(PTH1_SIG_SEL) && (PTH1_SIG_SEL>=0)) || \
    (defined(PTH2_SIG_SEL) && (PTH2_SIG_SEL>=0)) || \
    (defined(PTH3_SIG_SEL) && (PTH3_SIG_SEL>=0)) || \
    (defined(PTH4_SIG_SEL) && (PTH4_SIG_SEL>=0)) || \
    (defined(PTH5_SIG_SEL) && (PTH5_SIG_SEL>=0)) || \
    (defined(PTH6_SIG_SEL) && (PTH6_SIG_SEL>=0)) || \
    (defined(PTH7_SIG_SEL) && (PTH7_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTH_MASK;
#endif

#if (defined(PTI0_SIG_SEL) && (PTI0_SIG_SEL>=0)) || \
    (defined(PTI1_SIG_SEL) && (PTI1_SIG_SEL>=0)) || \
    (defined(PTI2_SIG_SEL) && (PTI2_SIG_SEL>=0)) || \
    (defined(PTI3_SIG_SEL) && (PTI3_SIG_SEL>=0))

   FIXED_PORT_CLOCK_REG |= SIM_SCGC5_PORTI_MASK;

#endif

   for (const PinInit *p=pinInit; p<(pinInit+(sizeof(pinInit)/sizeof(pinInit[0]))); p++) {
      *(p->pcr) = p->pcrValue;
   }
}
#endif

