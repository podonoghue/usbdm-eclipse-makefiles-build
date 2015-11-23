 /**
  * @file     gpio.cpp (from gpio-MKM33Z5.cpp)
  *
  * @brief   Pin declarations for MKM33Z5
  */

#include "gpio.h"
#include "pin_mapping.h"

const USBDM::PortA_T<0>   digitalIO_PTA0;      //!< See @ref DigitalIO
const USBDM::PortA_T<1>   digitalIO_PTA1;      //!< See @ref DigitalIO
const USBDM::PortA_T<2>   digitalIO_PTA2;      //!< See @ref DigitalIO
const USBDM::PortA_T<3>   digitalIO_PTA3;      //!< See @ref DigitalIO
const USBDM::PortA_T<4>   digitalIO_PTA4;      //!< See @ref DigitalIO
const USBDM::PortA_T<5>   digitalIO_PTA5;      //!< See @ref DigitalIO
const USBDM::PortA_T<6>   digitalIO_PTA6;      //!< See @ref DigitalIO
const USBDM::PortA_T<7>   digitalIO_PTA7;      //!< See @ref DigitalIO
const USBDM::PortB_T<0>   digitalIO_PTB0;      //!< See @ref DigitalIO
const USBDM::PortB_T<1>   digitalIO_PTB1;      //!< See @ref DigitalIO
const USBDM::PortB_T<2>   digitalIO_PTB2;      //!< See @ref DigitalIO
const USBDM::PortB_T<3>   digitalIO_PTB3;      //!< See @ref DigitalIO
const USBDM::PortB_T<4>   digitalIO_PTB4;      //!< See @ref DigitalIO
const USBDM::PortB_T<5>   digitalIO_PTB5;      //!< See @ref DigitalIO
const USBDM::PortB_T<6>   digitalIO_PTB6;      //!< See @ref DigitalIO
const USBDM::PortB_T<7>   digitalIO_PTB7;      //!< See @ref DigitalIO
const USBDM::PortC_T<0>   digitalIO_PTC0;      //!< See @ref DigitalIO
const USBDM::PortC_T<1>   digitalIO_PTC1;      //!< See @ref DigitalIO
const USBDM::PortC_T<2>   digitalIO_PTC2;      //!< See @ref DigitalIO
const USBDM::PortC_T<3>   digitalIO_PTC3;      //!< See @ref DigitalIO
const USBDM::PortC_T<4>   digitalIO_PTC4;      //!< See @ref DigitalIO
const USBDM::PortC_T<5>   digitalIO_PTC5;      //!< See @ref DigitalIO
const USBDM::PortC_T<6>   digitalIO_PTC6;      //!< See @ref DigitalIO
const USBDM::PortC_T<7>   digitalIO_PTC7;      //!< See @ref DigitalIO
const USBDM::PortD_T<0>   digitalIO_PTD0;      //!< See @ref DigitalIO
const USBDM::PortD_T<1>   digitalIO_PTD1;      //!< See @ref DigitalIO
const USBDM::PortD_T<2>   digitalIO_PTD2;      //!< See @ref DigitalIO
const USBDM::PortD_T<3>   digitalIO_PTD3;      //!< See @ref DigitalIO
const USBDM::PortD_T<4>   digitalIO_PTD4;      //!< See @ref DigitalIO
const USBDM::PortD_T<5>   digitalIO_PTD5;      //!< See @ref DigitalIO
const USBDM::PortD_T<6>   digitalIO_PTD6;      //!< See @ref DigitalIO
const USBDM::PortD_T<7>   digitalIO_PTD7;      //!< See @ref DigitalIO
const USBDM::PortE_T<0>   digitalIO_PTE0;      //!< See @ref DigitalIO
const USBDM::PortE_T<1>   digitalIO_PTE1;      //!< See @ref DigitalIO
const USBDM::PortE_T<2>   digitalIO_PTE2;      //!< See @ref DigitalIO
const USBDM::PortE_T<3>   digitalIO_PTE3;      //!< See @ref DigitalIO
const USBDM::PortE_T<4>   digitalIO_PTE4;      //!< See @ref DigitalIO
const USBDM::PortE_T<5>   digitalIO_PTE5;      //!< See @ref DigitalIO
const USBDM::PortE_T<6>   digitalIO_PTE6;      //!< See @ref DigitalIO
const USBDM::PortE_T<7>   digitalIO_PTE7;      //!< See @ref DigitalIO
const USBDM::PortF_T<0>   digitalIO_PTF0;      //!< See @ref DigitalIO
const USBDM::PortF_T<1>   digitalIO_PTF1;      //!< See @ref DigitalIO
const USBDM::PortF_T<2>   digitalIO_PTF2;      //!< See @ref DigitalIO
const USBDM::PortF_T<3>   digitalIO_PTF3;      //!< See @ref DigitalIO
const USBDM::PortF_T<4>   digitalIO_PTF4;      //!< See @ref DigitalIO
const USBDM::PortF_T<5>   digitalIO_PTF5;      //!< See @ref DigitalIO
const USBDM::PortF_T<6>   digitalIO_PTF6;      //!< See @ref DigitalIO
const USBDM::PortF_T<7>   digitalIO_PTF7;      //!< See @ref DigitalIO
const USBDM::PortG_T<0>   digitalIO_PTG0;      //!< See @ref DigitalIO
const USBDM::PortG_T<1>   digitalIO_PTG1;      //!< See @ref DigitalIO
const USBDM::PortG_T<2>   digitalIO_PTG2;      //!< See @ref DigitalIO
const USBDM::PortG_T<3>   digitalIO_PTG3;      //!< See @ref DigitalIO
const USBDM::PortG_T<4>   digitalIO_PTG4;      //!< See @ref DigitalIO
const USBDM::PortG_T<5>   digitalIO_PTG5;      //!< See @ref DigitalIO
const USBDM::PortG_T<6>   digitalIO_PTG6;      //!< See @ref DigitalIO
const USBDM::PortG_T<7>   digitalIO_PTG7;      //!< See @ref DigitalIO
const USBDM::PortH_T<0>   digitalIO_PTH0;      //!< See @ref DigitalIO
const USBDM::PortH_T<1>   digitalIO_PTH1;      //!< See @ref DigitalIO
const USBDM::PortH_T<2>   digitalIO_PTH2;      //!< See @ref DigitalIO
const USBDM::PortH_T<3>   digitalIO_PTH3;      //!< See @ref DigitalIO
const USBDM::PortH_T<4>   digitalIO_PTH4;      //!< See @ref DigitalIO
const USBDM::PortH_T<5>   digitalIO_PTH5;      //!< See @ref DigitalIO
const USBDM::PortH_T<6>   digitalIO_PTH6;      //!< See @ref DigitalIO
const USBDM::PortH_T<7>   digitalIO_PTH7;      //!< See @ref DigitalIO
const USBDM::PortI_T<0>   digitalIO_PTI0;      //!< See @ref DigitalIO
const USBDM::PortI_T<1>   digitalIO_PTI1;      //!< See @ref DigitalIO
const USBDM::PortI_T<2>   digitalIO_PTI2;      //!< See @ref DigitalIO
const USBDM::PortI_T<3>   digitalIO_PTI3;      //!< See @ref DigitalIO
#if (PTC5_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 0> analogueIO_ADC0_SE0;
#endif
#if (PTC6_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[6]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 1> analogueIO_ADC0_SE1;
#endif
#if (PTC7_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[7]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 2> analogueIO_ADC0_SE2;
#endif
#if (PTD4_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 3> analogueIO_ADC0_SE3;
#endif
#if (PTD5_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 4> analogueIO_ADC0_SE4;
#endif
#if (PTD6_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 5> analogueIO_ADC0_SE5;
#endif
#if (PTE7_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[7]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 6> analogueIO_ADC0_SE6;
#endif
#if (PTF0_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[0]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 7> analogueIO_ADC0_SE7;
#endif
#if (PTF1_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 8> analogueIO_ADC0_SE8;
#endif
#if (PTF2_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 9> analogueIO_ADC0_SE9;
#endif
#if (PTG1_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTG_CLOCK_MASK, PORTG_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,10> analogueIO_ADC0_SE10;
#endif
#if (PTG2_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTG_CLOCK_MASK, PORTG_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,11> analogueIO_ADC0_SE11;
#endif

#if defined(DO_MAP_PINS_ON_RESET) && (DO_MAP_PINS_ON_RESET>0)
struct PinInit {
   uint32_t pcrValue;
   uint32_t volatile *pcr;
};

static const PinInit pinInit[] = {
#if defined(PTA0_SIG_SEL) && (PTA0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[0]},
#endif
#if defined(PTA1_SIG_SEL) && (PTA1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[1]},
#endif
#if defined(PTA2_SIG_SEL) && (PTA2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[2]},
#endif
#if defined(PTA3_SIG_SEL) && (PTA3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[3]},
#endif
#if defined(PTA4_SIG_SEL) && (PTA4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[4]},
#endif
#if defined(PTA5_SIG_SEL) && (PTA5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[5]},
#endif
#if defined(PTA6_SIG_SEL) && (PTA6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[6]},
#endif
#if defined(PTA7_SIG_SEL) && (PTA7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[7]},
#endif
#if defined(PTB0_SIG_SEL) && (PTB0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[0]},
#endif
#if defined(PTB1_SIG_SEL) && (PTB1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[1]},
#endif
#if defined(PTB2_SIG_SEL) && (PTB2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[2]},
#endif
#if defined(PTB3_SIG_SEL) && (PTB3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[3]},
#endif
#if defined(PTB4_SIG_SEL) && (PTB4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[4]},
#endif
#if defined(PTB5_SIG_SEL) && (PTB5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[5]},
#endif
#if defined(PTB6_SIG_SEL) && (PTB6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[6]},
#endif
#if defined(PTB7_SIG_SEL) && (PTB7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[7]},
#endif
#if defined(PTC0_SIG_SEL) && (PTC0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[0]},
#endif
#if defined(PTC1_SIG_SEL) && (PTC1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[1]},
#endif
#if defined(PTC2_SIG_SEL) && (PTC2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[2]},
#endif
#if defined(PTC3_SIG_SEL) && (PTC3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[3]},
#endif
#if defined(PTC4_SIG_SEL) && (PTC4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[4]},
#endif
#if defined(PTC5_SIG_SEL) && (PTC5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[5]},
#endif
#if defined(PTC6_SIG_SEL) && (PTC6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[6]},
#endif
#if defined(PTC7_SIG_SEL) && (PTC7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[7]},
#endif
#if defined(PTD0_SIG_SEL) && (PTD0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[0]},
#endif
#if defined(PTD1_SIG_SEL) && (PTD1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[1]},
#endif
#if defined(PTD2_SIG_SEL) && (PTD2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[2]},
#endif
#if defined(PTD3_SIG_SEL) && (PTD3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[3]},
#endif
#if defined(PTD4_SIG_SEL) && (PTD4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[4]},
#endif
#if defined(PTD5_SIG_SEL) && (PTD5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[5]},
#endif
#if defined(PTD6_SIG_SEL) && (PTD6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[6]},
#endif
#if defined(PTD7_SIG_SEL) && (PTD7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTD->PCR[7]},
#endif
#if defined(PTE0_SIG_SEL) && (PTE0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[0]},
#endif
#if defined(PTE1_SIG_SEL) && (PTE1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[1]},
#endif
#if defined(PTE2_SIG_SEL) && (PTE2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[2]},
#endif
#if defined(PTE3_SIG_SEL) && (PTE3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[3]},
#endif
#if defined(PTE4_SIG_SEL) && (PTE4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[4]},
#endif
#if defined(PTE5_SIG_SEL) && (PTE5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[5]},
#endif
#if defined(PTE6_SIG_SEL) && (PTE6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[6]},
#endif
#if defined(PTE7_SIG_SEL) && (PTE7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[7]},
#endif
#if defined(PTF0_SIG_SEL) && (PTF0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTF->PCR[0]},
#endif
#if defined(PTF1_SIG_SEL) && (PTF1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTF->PCR[1]},
#endif
#if defined(PTF2_SIG_SEL) && (PTF2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTF->PCR[2]},
#endif
#if defined(PTF3_SIG_SEL) && (PTF3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTF->PCR[3]},
#endif
#if defined(PTF4_SIG_SEL) && (PTF4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTF->PCR[4]},
#endif
#if defined(PTF5_SIG_SEL) && (PTF5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTF->PCR[5]},
#endif
#if defined(PTF6_SIG_SEL) && (PTF6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTF->PCR[6]},
#endif
#if defined(PTF7_SIG_SEL) && (PTF7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTF->PCR[7]},
#endif
#if defined(PTG0_SIG_SEL) && (PTG0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTG->PCR[0]},
#endif
#if defined(PTG1_SIG_SEL) && (PTG1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTG->PCR[1]},
#endif
#if defined(PTG2_SIG_SEL) && (PTG2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTG->PCR[2]},
#endif
#if defined(PTG3_SIG_SEL) && (PTG3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTG->PCR[3]},
#endif
#if defined(PTG4_SIG_SEL) && (PTG4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTG->PCR[4]},
#endif
#if defined(PTG5_SIG_SEL) && (PTG5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTG->PCR[5]},
#endif
#if defined(PTG6_SIG_SEL) && (PTG6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTG->PCR[6]},
#endif
#if defined(PTG7_SIG_SEL) && (PTG7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTG->PCR[7]},
#endif
#if defined(PTH0_SIG_SEL) && (PTH0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTH->PCR[0]},
#endif
#if defined(PTH1_SIG_SEL) && (PTH1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTH->PCR[1]},
#endif
#if defined(PTH2_SIG_SEL) && (PTH2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTH->PCR[2]},
#endif
#if defined(PTH3_SIG_SEL) && (PTH3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTH->PCR[3]},
#endif
#if defined(PTH4_SIG_SEL) && (PTH4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH4_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTH->PCR[4]},
#endif
#if defined(PTH5_SIG_SEL) && (PTH5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH5_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTH->PCR[5]},
#endif
#if defined(PTH6_SIG_SEL) && (PTH6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTH->PCR[6]},
#endif
#if defined(PTH7_SIG_SEL) && (PTH7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTH->PCR[7]},
#endif
#if defined(PTI0_SIG_SEL) && (PTI0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI0_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTI->PCR[0]},
#endif
#if defined(PTI1_SIG_SEL) && (PTI1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI1_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTI->PCR[1]},
#endif
#if defined(PTI2_SIG_SEL) && (PTI2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI2_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTI->PCR[2]},
#endif
#if defined(PTI3_SIG_SEL) && (PTI3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI3_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTI->PCR[3]},
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

   SIM->FIXED_PORT_CLOCK_REG |= PORTA_CLOCK_MASK;
#endif

#if (defined(PTB0_SIG_SEL) && (PTB0_SIG_SEL>=0)) || \
    (defined(PTB1_SIG_SEL) && (PTB1_SIG_SEL>=0)) || \
    (defined(PTB2_SIG_SEL) && (PTB2_SIG_SEL>=0)) || \
    (defined(PTB3_SIG_SEL) && (PTB3_SIG_SEL>=0)) || \
    (defined(PTB4_SIG_SEL) && (PTB4_SIG_SEL>=0)) || \
    (defined(PTB5_SIG_SEL) && (PTB5_SIG_SEL>=0)) || \
    (defined(PTB6_SIG_SEL) && (PTB6_SIG_SEL>=0)) || \
    (defined(PTB7_SIG_SEL) && (PTB7_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTB_CLOCK_MASK;
#endif

#if (defined(PTC0_SIG_SEL) && (PTC0_SIG_SEL>=0)) || \
    (defined(PTC1_SIG_SEL) && (PTC1_SIG_SEL>=0)) || \
    (defined(PTC2_SIG_SEL) && (PTC2_SIG_SEL>=0)) || \
    (defined(PTC3_SIG_SEL) && (PTC3_SIG_SEL>=0)) || \
    (defined(PTC4_SIG_SEL) && (PTC4_SIG_SEL>=0)) || \
    (defined(PTC5_SIG_SEL) && (PTC5_SIG_SEL>=0)) || \
    (defined(PTC6_SIG_SEL) && (PTC6_SIG_SEL>=0)) || \
    (defined(PTC7_SIG_SEL) && (PTC7_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTC_CLOCK_MASK;
#endif

#if (defined(PTD0_SIG_SEL) && (PTD0_SIG_SEL>=0)) || \
    (defined(PTD1_SIG_SEL) && (PTD1_SIG_SEL>=0)) || \
    (defined(PTD2_SIG_SEL) && (PTD2_SIG_SEL>=0)) || \
    (defined(PTD3_SIG_SEL) && (PTD3_SIG_SEL>=0)) || \
    (defined(PTD4_SIG_SEL) && (PTD4_SIG_SEL>=0)) || \
    (defined(PTD5_SIG_SEL) && (PTD5_SIG_SEL>=0)) || \
    (defined(PTD6_SIG_SEL) && (PTD6_SIG_SEL>=0)) || \
    (defined(PTD7_SIG_SEL) && (PTD7_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTD_CLOCK_MASK;
#endif

#if (defined(PTE0_SIG_SEL) && (PTE0_SIG_SEL>=0)) || \
    (defined(PTE1_SIG_SEL) && (PTE1_SIG_SEL>=0)) || \
    (defined(PTE2_SIG_SEL) && (PTE2_SIG_SEL>=0)) || \
    (defined(PTE3_SIG_SEL) && (PTE3_SIG_SEL>=0)) || \
    (defined(PTE4_SIG_SEL) && (PTE4_SIG_SEL>=0)) || \
    (defined(PTE5_SIG_SEL) && (PTE5_SIG_SEL>=0)) || \
    (defined(PTE6_SIG_SEL) && (PTE6_SIG_SEL>=0)) || \
    (defined(PTE7_SIG_SEL) && (PTE7_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTE_CLOCK_MASK;
#endif

#if (defined(PTF0_SIG_SEL) && (PTF0_SIG_SEL>=0)) || \
    (defined(PTF1_SIG_SEL) && (PTF1_SIG_SEL>=0)) || \
    (defined(PTF2_SIG_SEL) && (PTF2_SIG_SEL>=0)) || \
    (defined(PTF3_SIG_SEL) && (PTF3_SIG_SEL>=0)) || \
    (defined(PTF4_SIG_SEL) && (PTF4_SIG_SEL>=0)) || \
    (defined(PTF5_SIG_SEL) && (PTF5_SIG_SEL>=0)) || \
    (defined(PTF6_SIG_SEL) && (PTF6_SIG_SEL>=0)) || \
    (defined(PTF7_SIG_SEL) && (PTF7_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTF_CLOCK_MASK;
#endif

#if (defined(PTG0_SIG_SEL) && (PTG0_SIG_SEL>=0)) || \
    (defined(PTG1_SIG_SEL) && (PTG1_SIG_SEL>=0)) || \
    (defined(PTG2_SIG_SEL) && (PTG2_SIG_SEL>=0)) || \
    (defined(PTG3_SIG_SEL) && (PTG3_SIG_SEL>=0)) || \
    (defined(PTG4_SIG_SEL) && (PTG4_SIG_SEL>=0)) || \
    (defined(PTG5_SIG_SEL) && (PTG5_SIG_SEL>=0)) || \
    (defined(PTG6_SIG_SEL) && (PTG6_SIG_SEL>=0)) || \
    (defined(PTG7_SIG_SEL) && (PTG7_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTG_CLOCK_MASK;
#endif

#if (defined(PTH0_SIG_SEL) && (PTH0_SIG_SEL>=0)) || \
    (defined(PTH1_SIG_SEL) && (PTH1_SIG_SEL>=0)) || \
    (defined(PTH2_SIG_SEL) && (PTH2_SIG_SEL>=0)) || \
    (defined(PTH3_SIG_SEL) && (PTH3_SIG_SEL>=0)) || \
    (defined(PTH4_SIG_SEL) && (PTH4_SIG_SEL>=0)) || \
    (defined(PTH5_SIG_SEL) && (PTH5_SIG_SEL>=0)) || \
    (defined(PTH6_SIG_SEL) && (PTH6_SIG_SEL>=0)) || \
    (defined(PTH7_SIG_SEL) && (PTH7_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTH_CLOCK_MASK;
#endif

#if (defined(PTI0_SIG_SEL) && (PTI0_SIG_SEL>=0)) || \
    (defined(PTI1_SIG_SEL) && (PTI1_SIG_SEL>=0)) || \
    (defined(PTI2_SIG_SEL) && (PTI2_SIG_SEL>=0)) || \
    (defined(PTI3_SIG_SEL) && (PTI3_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTI_CLOCK_MASK;

#endif

   for (const PinInit *p=pinInit; p<(pinInit+(sizeof(pinInit)/sizeof(pinInit[0]))); p++) {
      *(p->pcr) = p->pcrValue;
   }
}
#endif

