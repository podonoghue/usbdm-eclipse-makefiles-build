 /**
  * @file     gpio.cpp (from gpio-MKL46Z4.cpp)
  *
  * @brief   Pin declarations for MKL46Z4
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
const USBDM::GpioA<12>    gpioA_12;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<13>    gpioA_13;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<14>    gpioA_14;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<15>    gpioA_15;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<16>    gpioA_16;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<17>    gpioA_17;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<18>    gpioA_18;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<19>    gpioA_19;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioA<20>    gpioA_20;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<0>     gpioB_0;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<1>     gpioB_1;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<2>     gpioB_2;             //!< See @ref USBDM::DigitalIOT
const USBDM::GpioB<3>     gpioB_3;             //!< See @ref USBDM::DigitalIOT
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
const USBDM::GpioC<16>    gpioC_16;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<17>    gpioC_17;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioC<18>    gpioC_18;            //!< See @ref USBDM::DigitalIOT
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
const USBDM::GpioE<16>    gpioE_16;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<17>    gpioE_17;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<18>    gpioE_18;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<19>    gpioE_19;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<20>    gpioE_20;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<21>    gpioE_21;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<22>    gpioE_22;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<23>    gpioE_23;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<24>    gpioE_24;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<25>    gpioE_25;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<26>    gpioE_26;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<29>    gpioE_29;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<30>    gpioE_30;            //!< See @ref USBDM::DigitalIOT
const USBDM::GpioE<31>    gpioE_31;            //!< See @ref USBDM::DigitalIOT
#if (PTB0_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc0_se8;
#endif
#if (PTB1_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc0_se9;
#endif
#if (PTB2_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc0_se12;
#endif
#if (PTB3_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc0_se13;
#endif
#if (PTC0_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  14> adc0_se14;
#endif
#if (PTC1_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc0_se15;
#endif
#if (PTC2_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  11> adc0_se11;
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
#if (PTE16_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[16]),  1> adc0_se1;
#endif
#if (PTE17_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[17]),  5> adc0_se5;
#endif
#if (PTE18_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[18]),  2> adc0_se2;
#endif
#if (PTE19_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[19]),  6> adc0_se6;
#endif
#if (PTE20_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]),  0> adc0_se0;
#endif
#if (PTE21_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]),  4> adc0_se4;
#endif
#if (PTE22_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]),  3> adc0_se3;
#endif
#if (PTE23_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]),  7> adc0_se7;
#endif
#if (PTE29_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]),  4> adc0_se4;
#endif
#if (PTE30_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), 23> adc0_se23;
#endif
#if (PTA0_SIG_SEL == 3)
const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  3> pwmIO_TPM0_CH5;
#endif
#if (PTA1_SIG_SEL == 3)
const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#endif
#if (PTA2_SIG_SEL == 3)
const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#endif
#if (PTA3_SIG_SEL == 3)
const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  3> pwmIO_TPM0_CH0;
#endif
#if (PTA4_SIG_SEL == 3)
const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  3> pwmIO_TPM0_CH1;
#endif
#if (PTA5_SIG_SEL == 3)
const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  3> pwmIO_TPM0_CH2;
#endif
#if (PTA6_SIG_SEL == 3)
const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[6]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  3> pwmIO_TPM0_CH3;
#endif
#if (PTA7_SIG_SEL == 3)
const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[7]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  3> pwmIO_TPM0_CH4;
#endif
#if (PTA12_SIG_SEL == 3)
const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 0,  3> pwmIO_TPM1_CH0;
#endif
#if (PTA13_SIG_SEL == 3)
const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 1,  3> pwmIO_TPM1_CH1;
#endif
#if (PTB0_SIG_SEL == 3)
const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 0,  3> pwmIO_TPM1_CH0;
#endif
#if (PTB1_SIG_SEL == 3)
const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 1,  3> pwmIO_TPM1_CH1;
#endif
#if (PTB2_SIG_SEL == 3)
const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#endif
#if (PTB3_SIG_SEL == 3)
const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#endif
#if (PTB18_SIG_SEL == 3)
const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#endif
#if (PTB19_SIG_SEL == 3)
const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#endif
#if (PTC1_SIG_SEL == 4)
const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  4> pwmIO_TPM0_CH0;
#endif
#if (PTC2_SIG_SEL == 4)
const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  4> pwmIO_TPM0_CH1;
#endif
#if (PTC3_SIG_SEL == 4)
const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  4> pwmIO_TPM0_CH2;
#endif
#if (PTC4_SIG_SEL == 4)
const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  4> pwmIO_TPM0_CH3;
#endif
#if (PTC8_SIG_SEL == 3)
const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  3> pwmIO_TPM0_CH4;
#endif
#if (PTC9_SIG_SEL == 3)
const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  3> pwmIO_TPM0_CH5;
#endif
#if (PTD0_SIG_SEL == 4)
const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[0]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  4> pwmIO_TPM0_CH0;
#endif
#if (PTD1_SIG_SEL == 4)
const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  4> pwmIO_TPM0_CH1;
#endif
#if (PTD2_SIG_SEL == 4)
const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  4> pwmIO_TPM0_CH2;
#endif
#if (PTD3_SIG_SEL == 4)
const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  4> pwmIO_TPM0_CH3;
#endif
#if (PTD4_SIG_SEL == 4)
const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  4> pwmIO_TPM0_CH4;
#endif
#if (PTD5_SIG_SEL == 4)
const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  4> pwmIO_TPM0_CH5;
#endif
#if (PTE20_SIG_SEL == 3)
const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 0,  3> pwmIO_TPM1_CH0;
#endif
#if (PTE21_SIG_SEL == 3)
const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 1,  3> pwmIO_TPM1_CH1;
#endif
#if (PTE22_SIG_SEL == 3)
const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#endif
#if (PTE23_SIG_SEL == 3)
const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#endif
#if (PTE24_SIG_SEL == 3)
const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  3> pwmIO_TPM0_CH0;
#endif
#if (PTE25_SIG_SEL == 3)
const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  3> pwmIO_TPM0_CH1;
#endif
#if (PTE26_SIG_SEL == 3)
const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[26]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  3> pwmIO_TPM0_CH5;
#endif
#if (PTE29_SIG_SEL == 3)
const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  3> pwmIO_TPM0_CH2;
#endif
#if (PTE30_SIG_SEL == 3)
const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  3> pwmIO_TPM0_CH3;
#endif
#if (PTE31_SIG_SEL == 3)
const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[31]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  3> pwmIO_TPM0_CH4;
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
#if defined(PTA20_SIG_SEL) && (PTA20_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA20_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTA->PCR[20]},
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
#if defined(PTC16_SIG_SEL) && (PTC16_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC16_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[16]},
#endif
#if defined(PTC17_SIG_SEL) && (PTC17_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC17_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[17]},
#endif
#if defined(PTC18_SIG_SEL) && (PTC18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC18_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTC->PCR[18]},
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
#if defined(PTE16_SIG_SEL) && (PTE16_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE16_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[16]},
#endif
#if defined(PTE17_SIG_SEL) && (PTE17_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE17_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[17]},
#endif
#if defined(PTE18_SIG_SEL) && (PTE18_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE18_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[18]},
#endif
#if defined(PTE19_SIG_SEL) && (PTE19_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE19_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[19]},
#endif
#if defined(PTE20_SIG_SEL) && (PTE20_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE20_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[20]},
#endif
#if defined(PTE21_SIG_SEL) && (PTE21_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE21_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[21]},
#endif
#if defined(PTE22_SIG_SEL) && (PTE22_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE22_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[22]},
#endif
#if defined(PTE23_SIG_SEL) && (PTE23_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE23_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[23]},
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
#if defined(PTE29_SIG_SEL) && (PTE29_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE29_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[29]},
#endif
#if defined(PTE30_SIG_SEL) && (PTE30_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE30_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[30]},
#endif
#if defined(PTE31_SIG_SEL) && (PTE31_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE31_SIG_SEL)|USBDM::DigitalIO::DEFAULT_PCR, &PORTE->PCR[31]},
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
    (defined(PTA7_SIG_SEL) && (PTA7_SIG_SEL>=0)) || \
    (defined(PTA12_SIG_SEL) && (PTA12_SIG_SEL>=0)) || \
    (defined(PTA13_SIG_SEL) && (PTA13_SIG_SEL>=0)) || \
    (defined(PTA14_SIG_SEL) && (PTA14_SIG_SEL>=0)) || \
    (defined(PTA15_SIG_SEL) && (PTA15_SIG_SEL>=0)) || \
    (defined(PTA16_SIG_SEL) && (PTA16_SIG_SEL>=0)) || \
    (defined(PTA17_SIG_SEL) && (PTA17_SIG_SEL>=0)) || \
    (defined(PTA18_SIG_SEL) && (PTA18_SIG_SEL>=0)) || \
    (defined(PTA19_SIG_SEL) && (PTA19_SIG_SEL>=0)) || \
    (defined(PTA20_SIG_SEL) && (PTA20_SIG_SEL>=0))

   SIM->FIXED_PORT_CLOCK_REG |= PORTA_CLOCK_MASK;
#endif

#if (defined(PTB0_SIG_SEL) && (PTB0_SIG_SEL>=0)) || \
    (defined(PTB1_SIG_SEL) && (PTB1_SIG_SEL>=0)) || \
    (defined(PTB2_SIG_SEL) && (PTB2_SIG_SEL>=0)) || \
    (defined(PTB3_SIG_SEL) && (PTB3_SIG_SEL>=0)) || \
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
    (defined(PTC16_SIG_SEL) && (PTC16_SIG_SEL>=0)) || \
    (defined(PTC17_SIG_SEL) && (PTC17_SIG_SEL>=0)) || \
    (defined(PTC18_SIG_SEL) && (PTC18_SIG_SEL>=0))

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
    (defined(PTE16_SIG_SEL) && (PTE16_SIG_SEL>=0)) || \
    (defined(PTE17_SIG_SEL) && (PTE17_SIG_SEL>=0)) || \
    (defined(PTE18_SIG_SEL) && (PTE18_SIG_SEL>=0)) || \
    (defined(PTE19_SIG_SEL) && (PTE19_SIG_SEL>=0)) || \
    (defined(PTE20_SIG_SEL) && (PTE20_SIG_SEL>=0)) || \
    (defined(PTE21_SIG_SEL) && (PTE21_SIG_SEL>=0)) || \
    (defined(PTE22_SIG_SEL) && (PTE22_SIG_SEL>=0)) || \
    (defined(PTE23_SIG_SEL) && (PTE23_SIG_SEL>=0)) || \
    (defined(PTE24_SIG_SEL) && (PTE24_SIG_SEL>=0)) || \
    (defined(PTE25_SIG_SEL) && (PTE25_SIG_SEL>=0)) || \
    (defined(PTE26_SIG_SEL) && (PTE26_SIG_SEL>=0)) || \
    (defined(PTE29_SIG_SEL) && (PTE29_SIG_SEL>=0)) || \
    (defined(PTE30_SIG_SEL) && (PTE30_SIG_SEL>=0)) || \
    (defined(PTE31_SIG_SEL) && (PTE31_SIG_SEL>=0))

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
