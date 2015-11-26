 /**
  * @file     gpio.cpp (from gpio-MK22F51212.cpp)
  *
  * @brief   Pin declarations for MK22F51212
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
const USBDM::GpioA<12>    gpioA_12;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<13>    gpioA_13;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<14>    gpioA_14;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<15>    gpioA_15;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<16>    gpioA_16;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<17>    gpioA_17;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<18>    gpioA_18;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<19>    gpioA_19;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<0>     gpioB_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<1>     gpioB_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<2>     gpioB_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<3>     gpioB_3;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<6>     gpioB_6;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<7>     gpioB_7;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<8>     gpioB_8;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<9>     gpioB_9;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<10>    gpioB_10;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<11>    gpioB_11;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<16>    gpioB_16;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<17>    gpioB_17;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<18>    gpioB_18;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<19>    gpioB_19;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<20>    gpioB_20;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<21>    gpioB_21;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<22>    gpioB_22;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<23>    gpioB_23;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<0>     gpioC_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<1>     gpioC_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<2>     gpioC_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<3>     gpioC_3;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<4>     gpioC_4;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<5>     gpioC_5;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<6>     gpioC_6;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<7>     gpioC_7;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<8>     gpioC_8;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<9>     gpioC_9;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<10>    gpioC_10;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<11>    gpioC_11;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<12>    gpioC_12;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<13>    gpioC_13;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<14>    gpioC_14;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<15>    gpioC_15;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<16>    gpioC_16;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<17>    gpioC_17;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<18>    gpioC_18;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<19>    gpioC_19;            //!< See @ref USBDM::DigitalIOT
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
const USBDM::GpioE<24>    gpioE_24;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<25>    gpioE_25;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<26>    gpioE_26;            //!< See @ref USBDM::DigitalIOT
const USBDM::Adc0<0,                0,                                         19> adc0_se19;
const USBDM::Adc0<0,                0,                                         20> adc0_se20;
const USBDM::Adc1<0,                0,                                         19> adc1_se19;
const USBDM::Adc0<0,                0,                                          0> adc0_se0;
const USBDM::Adc0<0,                0,                                          1> adc0_se1;
const USBDM::Adc1<0,                0,                                          0> adc1_se0;
const USBDM::Adc0<0,                0,                                          3> adc0_se3;
const USBDM::Adc0<0,                0,                                         23> adc0_se23;
const USBDM::Adc1<0,                0,                                         20> adc1_se20;
const USBDM::Adc1<0,                0,                                          1> adc1_se1;
const USBDM::Adc0<0,                0,                                          2> adc0_se2;
const USBDM::Adc1<0,                0,                                         18> adc1_se18;
const USBDM::Adc1<0,                0,                                         23> adc1_se23;
#if (PTA17_SIG_SEL == 0)
const USBDM::Adc1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[17]), 17> adc1_se17;
#endif
#if (PTB0_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc0_se8;
#endif
#if (PTB0_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc1_se8;
#endif
#if (PTB1_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc0_se9;
#endif
#if (PTB1_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc1_se9;
#endif
#if (PTB2_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc0_se12;
#endif
#if (PTB3_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc0_se13;
#endif
#if (PTB6_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[6]),  12> adc1_se12;
#endif
#if (PTB7_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[7]),  13> adc1_se13;
#endif
#if (PTB10_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[10]), 14> adc1_se14;
#endif
#if (PTB11_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[11]), 15> adc1_se15;
#endif
#if (PTC0_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  14> adc0_se14;
#endif
#if (PTC1_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc0_se15;
#endif
#if (PTC2_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4> adc0_se4;
#endif
#if (PTC8_SIG_SEL == 0)
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),   4> adc1_se4;
#endif
#if (PTC9_SIG_SEL == 0)
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),   5> adc1_se5;
#endif
#if (PTC10_SIG_SEL == 0)
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[10]),  6> adc1_se6;
#endif
#if (PTC11_SIG_SEL == 0)
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[11]),  7> adc1_se7;
#endif
#if (PTD1_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc0_se5;
#endif
#if (PTD5_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc0_se6;
#endif
#if (PTD6_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc0_se7;
#endif
#if (PTE0_SIG_SEL == 0)
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),   4> adc1_se4;
#endif
#if (PTE1_SIG_SEL == 0)
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc1_se5;
#endif
#if (PTE2_SIG_SEL == 0)
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[2]),   6> adc1_se6;
#endif
#if (PTE3_SIG_SEL == 0)
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[3]),   7> adc1_se7;
#endif
#if (PTE24_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), 17> adc0_se17;
#endif
#if (PTE25_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), 18> adc0_se18;
#endif
#if (PTA0_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  5>   ftm0_ch5;
#endif
#if (PTA1_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm0_ch6;
#endif
#if (PTA2_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  7>   ftm0_ch7;
#endif
#if (PTA3_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),   3,  0>   ftm0_ch0;
#endif
#if (PTA4_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),   3,  1>   ftm0_ch1;
#endif
#if (PTA5_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),   3,  2>   ftm0_ch2;
#endif
#if (PTA12_SIG_SEL == 3)
const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]),  3,  0>   ftm1_ch0;
#endif
#if (PTA13_SIG_SEL == 3)
const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]),  3,  1>   ftm1_ch1;
#endif
#if (PTB0_SIG_SEL == 3)
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   ftm1_ch0;
#endif
#if (PTB1_SIG_SEL == 3)
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   ftm1_ch1;
#endif
#if (PTB18_SIG_SEL == 3)
const USBDM::Ftm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]),  3,  0>   ftm2_ch0;
#endif
#if (PTB19_SIG_SEL == 3)
const USBDM::Ftm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]),  3,  1>   ftm2_ch1;
#endif
#if (PTC1_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  0>   ftm0_ch0;
#endif
#if (PTC2_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  1>   ftm0_ch1;
#endif
#if (PTC3_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   ftm0_ch2;
#endif
#if (PTC4_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  3>   ftm0_ch3;
#endif
#if (PTC5_SIG_SEL == 7)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),   7,  2>   ftm0_ch2;
#endif
#if (PTD4_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   ftm0_ch4;
#endif
#if (PTD5_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   ftm0_ch5;
#endif
#if (PTD6_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   4,  6>   ftm0_ch6;
#endif
#if (PTD7_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),   4,  7>   ftm0_ch7;
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
#if defined(PTA12_SIG_SEL) && (PTA12_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA12_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[12]},
#endif
#if defined(PTA13_SIG_SEL) && (PTA13_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA13_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[13]},
#endif
#if defined(PTA14_SIG_SEL) && (PTA14_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA14_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[14]},
#endif
#if defined(PTA15_SIG_SEL) && (PTA15_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA15_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[15]},
#endif
#if defined(PTA16_SIG_SEL) && (PTA16_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA16_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[16]},
#endif
#if defined(PTA17_SIG_SEL) && (PTA17_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA17_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[17]},
#endif
#if defined(PTA18_SIG_SEL) && (PTA18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA18_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[18]},
#endif
#if defined(PTA19_SIG_SEL) && (PTA19_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA19_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[19]},
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
#if defined(PTB6_SIG_SEL) && (PTB6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB6_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[6]},
#endif
#if defined(PTB7_SIG_SEL) && (PTB7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB7_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[7]},
#endif
#if defined(PTB8_SIG_SEL) && (PTB8_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB8_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[8]},
#endif
#if defined(PTB9_SIG_SEL) && (PTB9_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB9_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[9]},
#endif
#if defined(PTB10_SIG_SEL) && (PTB10_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB10_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[10]},
#endif
#if defined(PTB11_SIG_SEL) && (PTB11_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB11_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[11]},
#endif
#if defined(PTB16_SIG_SEL) && (PTB16_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB16_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[16]},
#endif
#if defined(PTB17_SIG_SEL) && (PTB17_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB17_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[17]},
#endif
#if defined(PTB18_SIG_SEL) && (PTB18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB18_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[18]},
#endif
#if defined(PTB19_SIG_SEL) && (PTB19_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB19_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[19]},
#endif
#if defined(PTB20_SIG_SEL) && (PTB20_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB20_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[20]},
#endif
#if defined(PTB21_SIG_SEL) && (PTB21_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB21_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[21]},
#endif
#if defined(PTB22_SIG_SEL) && (PTB22_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB22_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[22]},
#endif
#if defined(PTB23_SIG_SEL) && (PTB23_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB23_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTB->PCR[23]},
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
#if defined(PTC8_SIG_SEL) && (PTC8_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC8_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[8]},
#endif
#if defined(PTC9_SIG_SEL) && (PTC9_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC9_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[9]},
#endif
#if defined(PTC10_SIG_SEL) && (PTC10_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC10_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[10]},
#endif
#if defined(PTC11_SIG_SEL) && (PTC11_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC11_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[11]},
#endif
#if defined(PTC12_SIG_SEL) && (PTC12_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC12_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[12]},
#endif
#if defined(PTC13_SIG_SEL) && (PTC13_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC13_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[13]},
#endif
#if defined(PTC14_SIG_SEL) && (PTC14_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC14_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[14]},
#endif
#if defined(PTC15_SIG_SEL) && (PTC15_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC15_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[15]},
#endif
#if defined(PTC16_SIG_SEL) && (PTC16_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC16_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[16]},
#endif
#if defined(PTC17_SIG_SEL) && (PTC17_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC17_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[17]},
#endif
#if defined(PTC18_SIG_SEL) && (PTC18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC18_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[18]},
#endif
#if defined(PTC19_SIG_SEL) && (PTC19_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC19_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[19]},
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
#if defined(PTE24_SIG_SEL) && (PTE24_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE24_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[24]},
#endif
#if defined(PTE25_SIG_SEL) && (PTE25_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE25_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[25]},
#endif
#if defined(PTE26_SIG_SEL) && (PTE26_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE26_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[26]},
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

   SIM->FIXED_PORT_CLOCK_REG |= PORTA_CLOCK_MASK;
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

   SIM->FIXED_PORT_CLOCK_REG |= PORTB_CLOCK_MASK;
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
    (defined(PTE24_SIG_SEL) && (PTE24_SIG_SEL>=0)) || \
    (defined(PTE25_SIG_SEL) && (PTE25_SIG_SEL>=0)) || \
    (defined(PTE26_SIG_SEL) && (PTE26_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTE_CLOCK_MASK;

#endif

   for (const PinInit *p=pinInit; p<(pinInit+(sizeof(pinInit)/sizeof(pinInit[0]))); p++) {
      *(p->pcr) = p->pcrValue;
   }
}
#endif

#if USBDM_USE_NAMESPACES
} // End namespace USBDM
#endif
