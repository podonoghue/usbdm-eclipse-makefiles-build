 /**
  * @file     gpio.cpp (from gpio-MKL25Z4.cpp)
  *
  * @brief   Pin declarations for MKL25Z4
  */

#include "gpio.h"
#include "pin_mapping.h"

const USBDM::PortA_T<0>   digitalIO_PTA0;      //!< See @ref DigitalIO
const USBDM::PortA_T<1>   digitalIO_PTA1;      //!< See @ref DigitalIO
const USBDM::PortA_T<2>   digitalIO_PTA2;      //!< See @ref DigitalIO
const USBDM::PortA_T<3>   digitalIO_PTA3;      //!< See @ref DigitalIO
const USBDM::PortA_T<4>   digitalIO_PTA4;      //!< See @ref DigitalIO
const USBDM::PortA_T<5>   digitalIO_PTA5;      //!< See @ref DigitalIO
const USBDM::PortA_T<12>  digitalIO_PTA12;     //!< See @ref DigitalIO
const USBDM::PortA_T<13>  digitalIO_PTA13;     //!< See @ref DigitalIO
const USBDM::PortA_T<14>  digitalIO_PTA14;     //!< See @ref DigitalIO
const USBDM::PortA_T<15>  digitalIO_PTA15;     //!< See @ref DigitalIO
const USBDM::PortA_T<16>  digitalIO_PTA16;     //!< See @ref DigitalIO
const USBDM::PortA_T<17>  digitalIO_PTA17;     //!< See @ref DigitalIO
const USBDM::PortA_T<18>  digitalIO_PTA18;     //!< See @ref DigitalIO
const USBDM::PortA_T<19>  digitalIO_PTA19;     //!< See @ref DigitalIO
const USBDM::PortA_T<20>  digitalIO_PTA20;     //!< See @ref DigitalIO
const USBDM::PortB_T<0>   digitalIO_PTB0;      //!< See @ref DigitalIO
const USBDM::PortB_T<1>   digitalIO_PTB1;      //!< See @ref DigitalIO
const USBDM::PortB_T<2>   digitalIO_PTB2;      //!< See @ref DigitalIO
const USBDM::PortB_T<3>   digitalIO_PTB3;      //!< See @ref DigitalIO
const USBDM::PortB_T<8>   digitalIO_PTB8;      //!< See @ref DigitalIO
const USBDM::PortB_T<9>   digitalIO_PTB9;      //!< See @ref DigitalIO
const USBDM::PortB_T<10>  digitalIO_PTB10;     //!< See @ref DigitalIO
const USBDM::PortB_T<11>  digitalIO_PTB11;     //!< See @ref DigitalIO
const USBDM::PortB_T<16>  digitalIO_PTB16;     //!< See @ref DigitalIO
const USBDM::PortB_T<17>  digitalIO_PTB17;     //!< See @ref DigitalIO
const USBDM::PortB_T<18>  digitalIO_PTB18;     //!< See @ref DigitalIO
const USBDM::PortB_T<19>  digitalIO_PTB19;     //!< See @ref DigitalIO
const USBDM::PortC_T<0>   digitalIO_PTC0;      //!< See @ref DigitalIO
const USBDM::PortC_T<1>   digitalIO_PTC1;      //!< See @ref DigitalIO
const USBDM::PortC_T<2>   digitalIO_PTC2;      //!< See @ref DigitalIO
const USBDM::PortC_T<3>   digitalIO_PTC3;      //!< See @ref DigitalIO
const USBDM::PortC_T<4>   digitalIO_PTC4;      //!< See @ref DigitalIO
const USBDM::PortC_T<5>   digitalIO_PTC5;      //!< See @ref DigitalIO
const USBDM::PortC_T<6>   digitalIO_PTC6;      //!< See @ref DigitalIO
const USBDM::PortC_T<7>   digitalIO_PTC7;      //!< See @ref DigitalIO
const USBDM::PortC_T<8>   digitalIO_PTC8;      //!< See @ref DigitalIO
const USBDM::PortC_T<9>   digitalIO_PTC9;      //!< See @ref DigitalIO
const USBDM::PortC_T<10>  digitalIO_PTC10;     //!< See @ref DigitalIO
const USBDM::PortC_T<11>  digitalIO_PTC11;     //!< See @ref DigitalIO
const USBDM::PortC_T<12>  digitalIO_PTC12;     //!< See @ref DigitalIO
const USBDM::PortC_T<13>  digitalIO_PTC13;     //!< See @ref DigitalIO
const USBDM::PortC_T<16>  digitalIO_PTC16;     //!< See @ref DigitalIO
const USBDM::PortC_T<17>  digitalIO_PTC17;     //!< See @ref DigitalIO
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
const USBDM::PortE_T<20>  digitalIO_PTE20;     //!< See @ref DigitalIO
const USBDM::PortE_T<21>  digitalIO_PTE21;     //!< See @ref DigitalIO
const USBDM::PortE_T<22>  digitalIO_PTE22;     //!< See @ref DigitalIO
const USBDM::PortE_T<23>  digitalIO_PTE23;     //!< See @ref DigitalIO
const USBDM::PortE_T<24>  digitalIO_PTE24;     //!< See @ref DigitalIO
const USBDM::PortE_T<25>  digitalIO_PTE25;     //!< See @ref DigitalIO
const USBDM::PortE_T<29>  digitalIO_PTE29;     //!< See @ref DigitalIO
const USBDM::PortE_T<30>  digitalIO_PTE30;     //!< See @ref DigitalIO
const USBDM::PortE_T<31>  digitalIO_PTE31;     //!< See @ref DigitalIO
#if (PTB0_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 8> analogueIO_ADC0_SE8;
#endif
#if (PTB1_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 9> analogueIO_ADC0_SE9;
#endif
#if (PTB2_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,12> analogueIO_ADC0_SE12;
#endif
#if (PTB3_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,13> analogueIO_ADC0_SE13;
#endif
#if (PTC0_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,14> analogueIO_ADC0_SE14;
#endif
#if (PTC1_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,15> analogueIO_ADC0_SE15;
#endif
#if (PTC2_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,11> analogueIO_ADC0_SE11;
#endif
#if (PTD1_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 5> analogueIO_ADC0_SE5b;
#endif
#if (PTD5_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 6> analogueIO_ADC0_SE6b;
#endif
#if (PTD6_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 7> analogueIO_ADC0_SE7b;
#endif
#if (PTE20_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 0> analogueIO_ADC0_SE0;
#endif
#if (PTE21_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 4> analogueIO_ADC0_SE4a;
#endif
#if (PTE22_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 3> analogueIO_ADC0_SE3;
#endif
#if (PTE23_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 7> analogueIO_ADC0_SE7a;
#endif
#if (PTE29_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 4> analogueIO_ADC0_SE4b;
#endif
#if (PTE30_SIG_SEL == 0)
const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,23> analogueIO_ADC0_SE23;
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
    (defined(PTB8_SIG_SEL) && (PTB8_SIG_SEL>=0)) || \
    (defined(PTB9_SIG_SEL) && (PTB9_SIG_SEL>=0)) || \
    (defined(PTB10_SIG_SEL) && (PTB10_SIG_SEL>=0)) || \
    (defined(PTB11_SIG_SEL) && (PTB11_SIG_SEL>=0)) || \
    (defined(PTB16_SIG_SEL) && (PTB16_SIG_SEL>=0)) || \
    (defined(PTB17_SIG_SEL) && (PTB17_SIG_SEL>=0)) || \
    (defined(PTB18_SIG_SEL) && (PTB18_SIG_SEL>=0)) || \
    (defined(PTB19_SIG_SEL) && (PTB19_SIG_SEL>=0))

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
    (defined(PTC17_SIG_SEL) && (PTC17_SIG_SEL>=0))

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
    (defined(PTE20_SIG_SEL) && (PTE20_SIG_SEL>=0)) || \
    (defined(PTE21_SIG_SEL) && (PTE21_SIG_SEL>=0)) || \
    (defined(PTE22_SIG_SEL) && (PTE22_SIG_SEL>=0)) || \
    (defined(PTE23_SIG_SEL) && (PTE23_SIG_SEL>=0)) || \
    (defined(PTE24_SIG_SEL) && (PTE24_SIG_SEL>=0)) || \
    (defined(PTE25_SIG_SEL) && (PTE25_SIG_SEL>=0)) || \
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

