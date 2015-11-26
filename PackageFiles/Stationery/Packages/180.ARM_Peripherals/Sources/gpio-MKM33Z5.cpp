 /**
  * @file     gpio.cpp (from gpio-MKM33Z5.cpp)
  *
  * @brief   Pin declarations for MKM33Z5
  */

#include "gpio.h"
#include "pin_mapping.h"

#if USBDM_USE_NAMESPACES
namespace USBDM {
#endif
const USBDM::GpioA<0>     gpioA_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<1>     gpioA_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<2>     gpioA_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<3>     gpioA_3;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<4>     gpioA_4;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<5>     gpioA_5;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<6>     gpioA_6;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<7>     gpioA_7;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<0>     gpioB_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<1>     gpioB_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<2>     gpioB_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<3>     gpioB_3;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<4>     gpioB_4;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<5>     gpioB_5;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<6>     gpioB_6;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<7>     gpioB_7;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<0>     gpioC_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<1>     gpioC_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<2>     gpioC_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<3>     gpioC_3;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<4>     gpioC_4;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<5>     gpioC_5;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<6>     gpioC_6;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<7>     gpioC_7;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioD<0>     gpioD_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioD<1>     gpioD_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioD<2>     gpioD_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioD<3>     gpioD_3;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioD<4>     gpioD_4;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioD<5>     gpioD_5;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioD<6>     gpioD_6;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioD<7>     gpioD_7;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<0>     gpioE_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<1>     gpioE_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<2>     gpioE_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<3>     gpioE_3;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<4>     gpioE_4;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<5>     gpioE_5;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<6>     gpioE_6;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<7>     gpioE_7;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioF<0>     gpioF_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioF<1>     gpioF_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioF<2>     gpioF_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioF<3>     gpioF_3;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioF<4>     gpioF_4;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioF<5>     gpioF_5;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioF<6>     gpioF_6;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioF<7>     gpioF_7;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioG<0>     gpioG_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioG<1>     gpioG_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioG<2>     gpioG_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioG<3>     gpioG_3;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioG<4>     gpioG_4;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioG<5>     gpioG_5;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioG<6>     gpioG_6;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioG<7>     gpioG_7;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioH<0>     gpioH_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioH<1>     gpioH_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioH<2>     gpioH_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioH<3>     gpioH_3;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioH<4>     gpioH_4;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioH<5>     gpioH_5;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioH<6>     gpioH_6;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioH<7>     gpioH_7;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioI<0>     gpioI_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioI<1>     gpioI_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioI<2>     gpioI_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioI<3>     gpioI_3;             //!< See @ref USBDM::DigitalIOT
#if (PTC5_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),   0> adc0_se0;
#endif
#if (PTC6_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[6]),   1> adc0_se1;
#endif
#if (PTC7_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[7]),   2> adc0_se2;
#endif
#if (PTD4_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   3> adc0_se3;
#endif
#if (PTD5_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4> adc0_se4;
#endif
#if (PTD6_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   5> adc0_se5;
#endif
#if (PTE7_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[7]),   6> adc0_se6;
#endif
#if (PTF0_SIG_SEL == 0)
const USBDM::Adc0<PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[0]),   7> adc0_se7;
#endif
#if (PTF1_SIG_SEL == 0)
const USBDM::Adc0<PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[1]),   8> adc0_se8;
#endif
#if (PTF2_SIG_SEL == 0)
const USBDM::Adc0<PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[2]),   9> adc0_se9;
#endif
#if (PTG1_SIG_SEL == 0)
const USBDM::Adc0<PORTG_CLOCK_MASK, PORTG_BasePtr+offsetof(PORT_Type,PCR[1]),  10> adc0_se10;
#endif
#if (PTG2_SIG_SEL == 0)
const USBDM::Adc0<PORTG_CLOCK_MASK, PORTG_BasePtr+offsetof(PORT_Type,PCR[2]),  11> adc0_se11;
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

#if USBDM_USE_NAMESPACES
} // End namespace USBDM
#endif
