/**
 * @file      gpio.h (derived from gpio-MKL46Z4.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKL46Z4
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stddef.h>
#include "derivative.h"
#include "pin_mapping.h"
#include "gpio_defs.h"

#if defined(USE_USBDM_NAMESPACE) && USE_USBDM_NAMESPACE
namespace USBDM {
#endif
/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
extern const USBDM::PortA_T<0>   digitalIO_PTA0;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<1>   digitalIO_PTA1;      //!< See @ref DigitalIO
#define digitalIO_D0             digitalIO_PTA1       //!< Alias for @ref USBDM::digitalIO_PTA1
extern const USBDM::PortA_T<2>   digitalIO_PTA2;      //!< See @ref DigitalIO
#define digitalIO_D1             digitalIO_PTA2       //!< Alias for @ref USBDM::digitalIO_PTA2
extern const USBDM::PortA_T<3>   digitalIO_PTA3;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<4>   digitalIO_PTA4;      //!< See @ref DigitalIO
#define digitalIO_D4             digitalIO_PTA4       //!< Alias for @ref USBDM::digitalIO_PTA4
extern const USBDM::PortA_T<5>   digitalIO_PTA5;      //!< See @ref DigitalIO
#define digitalIO_D5             digitalIO_PTA5       //!< Alias for @ref USBDM::digitalIO_PTA5
extern const USBDM::PortA_T<6>   digitalIO_PTA6;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<7>   digitalIO_PTA7;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<12>  digitalIO_PTA12;     //!< See @ref DigitalIO
#define digitalIO_D3             digitalIO_PTA12      //!< Alias for @ref USBDM::digitalIO_PTA12
extern const USBDM::PortA_T<13>  digitalIO_PTA13;     //!< See @ref DigitalIO
#define digitalIO_D8             digitalIO_PTA13      //!< Alias for @ref USBDM::digitalIO_PTA13
extern const USBDM::PortA_T<14>  digitalIO_PTA14;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<15>  digitalIO_PTA15;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<16>  digitalIO_PTA16;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<17>  digitalIO_PTA17;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<18>  digitalIO_PTA18;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<19>  digitalIO_PTA19;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<20>  digitalIO_PTA20;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<0>   digitalIO_PTB0;      //!< See @ref DigitalIO
#define digitalIO_A0             digitalIO_PTB0       //!< Alias for @ref USBDM::digitalIO_PTB0
extern const USBDM::PortB_T<1>   digitalIO_PTB1;      //!< See @ref DigitalIO
#define digitalIO_A1             digitalIO_PTB1       //!< Alias for @ref USBDM::digitalIO_PTB1
extern const USBDM::PortB_T<2>   digitalIO_PTB2;      //!< See @ref DigitalIO
#define digitalIO_A2             digitalIO_PTB2       //!< Alias for @ref USBDM::digitalIO_PTB2
extern const USBDM::PortB_T<3>   digitalIO_PTB3;      //!< See @ref DigitalIO
#define digitalIO_A3             digitalIO_PTB3       //!< Alias for @ref USBDM::digitalIO_PTB3
extern const USBDM::PortB_T<7>   digitalIO_PTB7;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<8>   digitalIO_PTB8;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<9>   digitalIO_PTB9;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<10>  digitalIO_PTB10;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<11>  digitalIO_PTB11;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<16>  digitalIO_PTB16;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<17>  digitalIO_PTB17;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<18>  digitalIO_PTB18;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<19>  digitalIO_PTB19;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<20>  digitalIO_PTB20;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<21>  digitalIO_PTB21;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<22>  digitalIO_PTB22;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<23>  digitalIO_PTB23;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<0>   digitalIO_PTC0;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<1>   digitalIO_PTC1;      //!< See @ref DigitalIO
#define digitalIO_A5             digitalIO_PTC1       //!< Alias for @ref USBDM::digitalIO_PTC1
extern const USBDM::PortC_T<2>   digitalIO_PTC2;      //!< See @ref DigitalIO
#define digitalIO_A4             digitalIO_PTC2       //!< Alias for @ref USBDM::digitalIO_PTC2
extern const USBDM::PortC_T<3>   digitalIO_PTC3;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<4>   digitalIO_PTC4;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<5>   digitalIO_PTC5;      //!< See @ref DigitalIO
#define digitalIO_ACC_INT1       digitalIO_PTC5       //!< Alias for @ref USBDM::digitalIO_PTC5
extern const USBDM::PortC_T<6>   digitalIO_PTC6;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<7>   digitalIO_PTC7;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<8>   digitalIO_PTC8;      //!< See @ref DigitalIO
#define digitalIO_D6             digitalIO_PTC8       //!< Alias for @ref USBDM::digitalIO_PTC8
extern const USBDM::PortC_T<9>   digitalIO_PTC9;      //!< See @ref DigitalIO
#define digitalIO_D7             digitalIO_PTC9       //!< Alias for @ref USBDM::digitalIO_PTC9
extern const USBDM::PortC_T<10>  digitalIO_PTC10;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<11>  digitalIO_PTC11;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<12>  digitalIO_PTC12;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<13>  digitalIO_PTC13;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<16>  digitalIO_PTC16;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<17>  digitalIO_PTC17;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<18>  digitalIO_PTC18;     //!< See @ref DigitalIO
extern const USBDM::PortD_T<0>   digitalIO_PTD0;      //!< See @ref DigitalIO
extern const USBDM::PortD_T<1>   digitalIO_PTD1;      //!< See @ref DigitalIO
#define digitalIO_MAG_INT        digitalIO_PTD1       //!< Alias for @ref USBDM::digitalIO_PTD1
#define digitalIO_ACC_INT2       digitalIO_PTD1       //!< Alias for @ref USBDM::digitalIO_PTD1
#define digitalIO_LED_BLUE       digitalIO_PTD1       //!< Alias for @ref USBDM::digitalIO_PTD1
extern const USBDM::PortD_T<2>   digitalIO_PTD2;      //!< See @ref DigitalIO
#define digitalIO_D9             digitalIO_PTD2       //!< Alias for @ref USBDM::digitalIO_PTD2
extern const USBDM::PortD_T<3>   digitalIO_PTD3;      //!< See @ref DigitalIO
#define digitalIO_D2             digitalIO_PTD3       //!< Alias for @ref USBDM::digitalIO_PTD3
extern const USBDM::PortD_T<4>   digitalIO_PTD4;      //!< See @ref DigitalIO
#define digitalIO_D10            digitalIO_PTD4       //!< Alias for @ref USBDM::digitalIO_PTD4
extern const USBDM::PortD_T<5>   digitalIO_PTD5;      //!< See @ref DigitalIO
#define digitalIO_D13            digitalIO_PTD5       //!< Alias for @ref USBDM::digitalIO_PTD5
#define digitalIO_LED_GREEN      digitalIO_PTD5       //!< Alias for @ref USBDM::digitalIO_PTD5
extern const USBDM::PortD_T<6>   digitalIO_PTD6;      //!< See @ref DigitalIO
#define digitalIO_D11            digitalIO_PTD6       //!< Alias for @ref USBDM::digitalIO_PTD6
extern const USBDM::PortD_T<7>   digitalIO_PTD7;      //!< See @ref DigitalIO
#define digitalIO_D12            digitalIO_PTD7       //!< Alias for @ref USBDM::digitalIO_PTD7
extern const USBDM::PortE_T<0>   digitalIO_PTE0;      //!< See @ref DigitalIO
#define digitalIO_D14            digitalIO_PTE0       //!< Alias for @ref USBDM::digitalIO_PTE0
extern const USBDM::PortE_T<1>   digitalIO_PTE1;      //!< See @ref DigitalIO
#define digitalIO_D15            digitalIO_PTE1       //!< Alias for @ref USBDM::digitalIO_PTE1
extern const USBDM::PortE_T<2>   digitalIO_PTE2;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<3>   digitalIO_PTE3;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<4>   digitalIO_PTE4;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<5>   digitalIO_PTE5;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<6>   digitalIO_PTE6;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<16>  digitalIO_PTE16;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<17>  digitalIO_PTE17;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<18>  digitalIO_PTE18;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<19>  digitalIO_PTE19;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<20>  digitalIO_PTE20;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<21>  digitalIO_PTE21;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<22>  digitalIO_PTE22;     //!< See @ref DigitalIO
#define digitalIO_LIGHT_SENS     digitalIO_PTE22      //!< Alias for @ref USBDM::digitalIO_PTE22
extern const USBDM::PortE_T<23>  digitalIO_PTE23;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<24>  digitalIO_PTE24;     //!< See @ref DigitalIO
#define digitalIO_MAG_SCL        digitalIO_PTE24      //!< Alias for @ref USBDM::digitalIO_PTE24
#define digitalIO_ACC_SCL        digitalIO_PTE24      //!< Alias for @ref USBDM::digitalIO_PTE24
extern const USBDM::PortE_T<25>  digitalIO_PTE25;     //!< See @ref DigitalIO
#define digitalIO_MAG_SDA        digitalIO_PTE25      //!< Alias for @ref USBDM::digitalIO_PTE25
#define digitalIO_ACC_SDA        digitalIO_PTE25      //!< Alias for @ref USBDM::digitalIO_PTE25
extern const USBDM::PortE_T<26>  digitalIO_PTE26;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<29>  digitalIO_PTE29;     //!< See @ref DigitalIO
#define digitalIO_LED_RED        digitalIO_PTE29      //!< Alias for @ref USBDM::digitalIO_PTE29
extern const USBDM::PortE_T<30>  digitalIO_PTE30;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<31>  digitalIO_PTE31;     //!< See @ref DigitalIO
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTB0_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 8> analogueIO_ADC0_SE8;
#define analogueIO_A0            analogueIO_ADC0_SE8  //!< Alias for @ref USBDM::analogueIO_ADC0_SE8
#endif
#if (PTB1_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 9> analogueIO_ADC0_SE9;
#define analogueIO_A1            analogueIO_ADC0_SE9  //!< Alias for @ref USBDM::analogueIO_ADC0_SE9
#endif
#if (PTB2_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,12> analogueIO_ADC0_SE12;
#define analogueIO_A2            analogueIO_ADC0_SE12 //!< Alias for @ref USBDM::analogueIO_ADC0_SE12
#endif
#if (PTB3_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,13> analogueIO_ADC0_SE13;
#define analogueIO_A3            analogueIO_ADC0_SE13 //!< Alias for @ref USBDM::analogueIO_ADC0_SE13
#endif
#if (PTC0_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,14> analogueIO_ADC0_SE14;
#endif
#if (PTC1_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,15> analogueIO_ADC0_SE15;
#define analogueIO_A5            analogueIO_ADC0_SE15 //!< Alias for @ref USBDM::analogueIO_ADC0_SE15
#endif
#if (PTC2_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,11> analogueIO_ADC0_SE11;
#define analogueIO_A4            analogueIO_ADC0_SE11 //!< Alias for @ref USBDM::analogueIO_ADC0_SE11
#endif
#if (PTD1_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 5> analogueIO_ADC0_SE5b;
#define analogueIO_MAG_INT       analogueIO_ADC0_SE5b //!< Alias for @ref USBDM::analogueIO_ADC0_SE5b
#define analogueIO_ACC_INT2      analogueIO_ADC0_SE5b //!< Alias for @ref USBDM::analogueIO_ADC0_SE5b
#define analogueIO_LED_BLUE      analogueIO_ADC0_SE5b //!< Alias for @ref USBDM::analogueIO_ADC0_SE5b
#endif
#if (PTD5_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 6> analogueIO_ADC0_SE6b;
#define analogueIO_D13           analogueIO_ADC0_SE6b //!< Alias for @ref USBDM::analogueIO_ADC0_SE6b
#define analogueIO_LED_GREEN     analogueIO_ADC0_SE6b //!< Alias for @ref USBDM::analogueIO_ADC0_SE6b
#endif
#if (PTD6_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 7> analogueIO_ADC0_SE7b;
#define analogueIO_D11           analogueIO_ADC0_SE7b //!< Alias for @ref USBDM::analogueIO_ADC0_SE7b
#endif
#if (PTE16_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[16]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 1> analogueIO_ADC0_SE1;
#endif
#if (PTE17_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[17]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 5> analogueIO_ADC0_SE5a;
#endif
#if (PTE18_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[18]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 2> analogueIO_ADC0_SE2;
#endif
#if (PTE19_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[19]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 6> analogueIO_ADC0_SE6a;
#endif
#if (PTE20_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 0> analogueIO_ADC0_SE0;
#endif
#if (PTE21_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 4> analogueIO_ADC0_SE4a;
#endif
#if (PTE22_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 3> analogueIO_ADC0_SE3;
#define analogueIO_LIGHT_SENS    analogueIO_ADC0_SE3  //!< Alias for @ref USBDM::analogueIO_ADC0_SE3
#endif
#if (PTE23_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 7> analogueIO_ADC0_SE7a;
#endif
#if (PTE29_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 4> analogueIO_ADC0_SE4b;
#define analogueIO_LED_RED       analogueIO_ADC0_SE4b //!< Alias for @ref USBDM::analogueIO_ADC0_SE4b
#endif
#if (PTE30_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,23> analogueIO_ADC0_SE23;
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA0_SIG_SEL == 3)
extern const PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  3> pwmIO_TPM0_CH5;
#endif
#if (PTA1_SIG_SEL == 3)
extern const PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#define pwmIO_D0                 pwmIO_TPM2_CH0       //!< Alias for @ref USBDM::pwmIO_TPM2_CH0
#endif
#if (PTA2_SIG_SEL == 3)
extern const PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#define pwmIO_D1                 pwmIO_TPM2_CH1       //!< Alias for @ref USBDM::pwmIO_TPM2_CH1
#endif
#if (PTA3_SIG_SEL == 3)
extern const PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  3> pwmIO_TPM0_CH0;
#endif
#if (PTA4_SIG_SEL == 3)
extern const PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  3> pwmIO_TPM0_CH1;
#define pwmIO_D4                 pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#endif
#if (PTA5_SIG_SEL == 3)
extern const PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  3> pwmIO_TPM0_CH2;
#define pwmIO_D5                 pwmIO_TPM0_CH2       //!< Alias for @ref USBDM::pwmIO_TPM0_CH2
#endif
#if (PTA6_SIG_SEL == 3)
extern const PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[6]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  3> pwmIO_TPM0_CH3;
#endif
#if (PTA7_SIG_SEL == 3)
extern const PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[7]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  3> pwmIO_TPM0_CH4;
#endif
#if (PTA12_SIG_SEL == 3)
extern const PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 0,  3> pwmIO_TPM1_CH0;
#define pwmIO_D3                 pwmIO_TPM1_CH0       //!< Alias for @ref USBDM::pwmIO_TPM1_CH0
#endif
#if (PTA13_SIG_SEL == 3)
extern const PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 1,  3> pwmIO_TPM1_CH1;
#define pwmIO_D8                 pwmIO_TPM1_CH1       //!< Alias for @ref USBDM::pwmIO_TPM1_CH1
#endif
#if (PTB0_SIG_SEL == 3)
extern const PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 0,  3> pwmIO_TPM1_CH0;
#define pwmIO_A0                 pwmIO_TPM1_CH0       //!< Alias for @ref USBDM::pwmIO_TPM1_CH0
#endif
#if (PTB1_SIG_SEL == 3)
extern const PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 1,  3> pwmIO_TPM1_CH1;
#define pwmIO_A1                 pwmIO_TPM1_CH1       //!< Alias for @ref USBDM::pwmIO_TPM1_CH1
#endif
#if (PTB2_SIG_SEL == 3)
extern const PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#define pwmIO_A2                 pwmIO_TPM2_CH0       //!< Alias for @ref USBDM::pwmIO_TPM2_CH0
#endif
#if (PTB3_SIG_SEL == 3)
extern const PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#define pwmIO_A3                 pwmIO_TPM2_CH1       //!< Alias for @ref USBDM::pwmIO_TPM2_CH1
#endif
#if (PTB18_SIG_SEL == 3)
extern const PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#endif
#if (PTB19_SIG_SEL == 3)
extern const PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#endif
#if (PTC1_SIG_SEL == 4)
extern const PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  4> pwmIO_TPM0_CH0;
#define pwmIO_A5                 pwmIO_TPM0_CH0       //!< Alias for @ref USBDM::pwmIO_TPM0_CH0
#endif
#if (PTC2_SIG_SEL == 4)
extern const PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  4> pwmIO_TPM0_CH1;
#define pwmIO_A4                 pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#endif
#if (PTC3_SIG_SEL == 4)
extern const PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  4> pwmIO_TPM0_CH2;
#endif
#if (PTC4_SIG_SEL == 4)
extern const PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  4> pwmIO_TPM0_CH3;
#endif
#if (PTC8_SIG_SEL == 3)
extern const PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  3> pwmIO_TPM0_CH4;
#define pwmIO_D6                 pwmIO_TPM0_CH4       //!< Alias for @ref USBDM::pwmIO_TPM0_CH4
#endif
#if (PTC9_SIG_SEL == 3)
extern const PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  3> pwmIO_TPM0_CH5;
#define pwmIO_D7                 pwmIO_TPM0_CH5       //!< Alias for @ref USBDM::pwmIO_TPM0_CH5
#endif
#if (PTD0_SIG_SEL == 4)
extern const PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[0]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  4> pwmIO_TPM0_CH0;
#endif
#if (PTD1_SIG_SEL == 4)
extern const PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  4> pwmIO_TPM0_CH1;
#define pwmIO_MAG_INT            pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#define pwmIO_ACC_INT2           pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#define pwmIO_LED_BLUE           pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#endif
#if (PTD2_SIG_SEL == 4)
extern const PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  4> pwmIO_TPM0_CH2;
#define pwmIO_D9                 pwmIO_TPM0_CH2       //!< Alias for @ref USBDM::pwmIO_TPM0_CH2
#endif
#if (PTD3_SIG_SEL == 4)
extern const PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  4> pwmIO_TPM0_CH3;
#define pwmIO_D2                 pwmIO_TPM0_CH3       //!< Alias for @ref USBDM::pwmIO_TPM0_CH3
#endif
#if (PTD4_SIG_SEL == 4)
extern const PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  4> pwmIO_TPM0_CH4;
#define pwmIO_D10                pwmIO_TPM0_CH4       //!< Alias for @ref USBDM::pwmIO_TPM0_CH4
#endif
#if (PTD5_SIG_SEL == 4)
extern const PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  4> pwmIO_TPM0_CH5;
#define pwmIO_D13                pwmIO_TPM0_CH5       //!< Alias for @ref USBDM::pwmIO_TPM0_CH5
#define pwmIO_LED_GREEN          pwmIO_TPM0_CH5       //!< Alias for @ref USBDM::pwmIO_TPM0_CH5
#endif
#if (PTE20_SIG_SEL == 3)
extern const PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 0,  3> pwmIO_TPM1_CH0;
#endif
#if (PTE21_SIG_SEL == 3)
extern const PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 1,  3> pwmIO_TPM1_CH1;
#endif
#if (PTE22_SIG_SEL == 3)
extern const PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#define pwmIO_LIGHT_SENS         pwmIO_TPM2_CH0       //!< Alias for @ref USBDM::pwmIO_TPM2_CH0
#endif
#if (PTE23_SIG_SEL == 3)
extern const PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#endif
#if (PTE24_SIG_SEL == 3)
extern const PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  3> pwmIO_TPM0_CH0;
#define pwmIO_MAG_SCL            pwmIO_TPM0_CH0       //!< Alias for @ref USBDM::pwmIO_TPM0_CH0
#define pwmIO_ACC_SCL            pwmIO_TPM0_CH0       //!< Alias for @ref USBDM::pwmIO_TPM0_CH0
#endif
#if (PTE25_SIG_SEL == 3)
extern const PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  3> pwmIO_TPM0_CH1;
#define pwmIO_MAG_SDA            pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#define pwmIO_ACC_SDA            pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#endif
#if (PTE26_SIG_SEL == 3)
extern const PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[26]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  3> pwmIO_TPM0_CH5;
#endif
#if (PTE29_SIG_SEL == 3)
extern const PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  3> pwmIO_TPM0_CH2;
#define pwmIO_LED_RED            pwmIO_TPM0_CH2       //!< Alias for @ref USBDM::pwmIO_TPM0_CH2
#endif
#if (PTE30_SIG_SEL == 3)
extern const PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  3> pwmIO_TPM0_CH3;
#endif
#if (PTE31_SIG_SEL == 3)
extern const PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[31]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  3> pwmIO_TPM0_CH4;
#endif
/**
 * @}
 */
#if defined(DO_MAP_PINS_ON_RESET) && (DO_MAP_PINS_ON_RESET>0)
/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
extern void usbdm_PinMapping();
#endif

/*
Clock Information 
ADC0       SCGC6        SIM_SCGC6_ADC0_MASK
CMP0       SCGC4        SIM_SCGC4_CMP0_MASK
DAC0       SCGC6        SIM_SCGC6_DAC0_MASK
DMA        SCGC7        SIM_SCGC7_DMA_MASK
DMAMUX     SCGC6        SIM_SCGC6_DMAMUX_MASK
I2C0       SCGC4        SIM_SCGC4_I2C0_MASK
I2C1       SCGC4        SIM_SCGC4_I2C1_MASK
I2S0       SCGC6        SIM_SCGC6_I2S0_MASK
LPTMR0     SCGC5        SIM_SCGC5_LPTMR_MASK
PIT        SCGC6        SIM_SCGC6_PIT_MASK
PORTA      SCGC5        SIM_SCGC5_PORTA_MASK
PORTB      SCGC5        SIM_SCGC5_PORTB_MASK
PORTC      SCGC5        SIM_SCGC5_PORTC_MASK
PORTD      SCGC5        SIM_SCGC5_PORTD_MASK
PORTE      SCGC5        SIM_SCGC5_PORTE_MASK
RTC        SCGC6        SIM_SCGC6_RTC_MASK
SLCD       SCGC5        SIM_SCGC5_SLCD_MASK
SPI0       SCGC4        SIM_SCGC4_SPI0_MASK
SPI1       SCGC4        SIM_SCGC4_SPI1_MASK
TPM0       SCGC6        SIM_SCGC6_TPM0_MASK
TPM1       SCGC6        SIM_SCGC6_TPM1_MASK
TPM2       SCGC6        SIM_SCGC6_TPM2_MASK
TSI        SCGC5        SIM_SCGC5_TSI_MASK
UART0      SCGC4        SIM_SCGC4_UART0_MASK
UART1      SCGC4        SIM_SCGC4_UART1_MASK
UART2      SCGC4        SIM_SCGC4_UART2_MASK
UART3      SCGC4        SIM_SCGC4_UART3_MASK
USB        SCGC4        SIM_SCGC4_USB_MASK
*/

#if defined(USE_USBDM_NAMESPACE) && USE_USBDM_NAMESPACE
} // End namespace USBDM
#endif

#endif /* GPIO_H_ */
