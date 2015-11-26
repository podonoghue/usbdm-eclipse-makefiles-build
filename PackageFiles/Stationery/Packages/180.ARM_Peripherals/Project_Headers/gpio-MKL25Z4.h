/**
 * @file      gpio.h (derived from gpio-MKL25Z4.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKL25Z4
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stddef.h>
#include "derivative.h"
#include "pin_mapping.h"
#include "gpio_defs.h"

#if USBDM_USE_NAMESPACES
namespace USBDM {
#endif
/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
extern const USBDM::GpioA<0>     gpioA_0;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<1>     gpioA_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D0             gpioA_1              //!< Alias for @ref USBDM::gpioA_1
extern const USBDM::GpioA<2>     gpioA_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D1             gpioA_2              //!< Alias for @ref USBDM::gpioA_2
extern const USBDM::GpioA<3>     gpioA_3;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<4>     gpioA_4;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D4             gpioA_4              //!< Alias for @ref USBDM::gpioA_4
extern const USBDM::GpioA<5>     gpioA_5;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D5             gpioA_5              //!< Alias for @ref USBDM::gpioA_5
extern const USBDM::GpioA<12>    gpioA_12;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D3             gpioA_12             //!< Alias for @ref USBDM::gpioA_12
extern const USBDM::GpioA<13>    gpioA_13;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D8             gpioA_13             //!< Alias for @ref USBDM::gpioA_13
extern const USBDM::GpioA<14>    gpioA_14;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<15>    gpioA_15;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<16>    gpioA_16;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D28            gpioA_16             //!< Alias for @ref USBDM::gpioA_16
extern const USBDM::GpioA<17>    gpioA_17;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D29            gpioA_17             //!< Alias for @ref USBDM::gpioA_17
extern const USBDM::GpioA<18>    gpioA_18;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<19>    gpioA_19;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<20>    gpioA_20;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<0>     gpioB_0;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A0             gpioB_0              //!< Alias for @ref USBDM::gpioB_0
extern const USBDM::GpioB<1>     gpioB_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A1             gpioB_1              //!< Alias for @ref USBDM::gpioB_1
extern const USBDM::GpioB<2>     gpioB_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A2             gpioB_2              //!< Alias for @ref USBDM::gpioB_2
extern const USBDM::GpioB<3>     gpioB_3;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A3             gpioB_3              //!< Alias for @ref USBDM::gpioB_3
extern const USBDM::GpioB<8>     gpioB_8;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A20            gpioB_8              //!< Alias for @ref USBDM::gpioB_8
extern const USBDM::GpioB<9>     gpioB_9;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A19            gpioB_9              //!< Alias for @ref USBDM::gpioB_9
extern const USBDM::GpioB<10>    gpioB_10;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A18            gpioB_10             //!< Alias for @ref USBDM::gpioB_10
extern const USBDM::GpioB<11>    gpioB_11;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A17            gpioB_11             //!< Alias for @ref USBDM::gpioB_11
extern const USBDM::GpioB<16>    gpioB_16;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<17>    gpioB_17;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<18>    gpioB_18;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_LED_RED        gpioB_18             //!< Alias for @ref USBDM::gpioB_18
extern const USBDM::GpioB<19>    gpioB_19;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_LED_GREEN      gpioB_19             //!< Alias for @ref USBDM::gpioB_19
extern const USBDM::GpioC<0>     gpioC_0;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D17            gpioC_0              //!< Alias for @ref USBDM::gpioC_0
extern const USBDM::GpioC<1>     gpioC_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A5             gpioC_1              //!< Alias for @ref USBDM::gpioC_1
extern const USBDM::GpioC<2>     gpioC_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A4             gpioC_2              //!< Alias for @ref USBDM::gpioC_2
extern const USBDM::GpioC<3>     gpioC_3;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D18            gpioC_3              //!< Alias for @ref USBDM::gpioC_3
extern const USBDM::GpioC<4>     gpioC_4;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D19            gpioC_4              //!< Alias for @ref USBDM::gpioC_4
extern const USBDM::GpioC<5>     gpioC_5;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D20            gpioC_5              //!< Alias for @ref USBDM::gpioC_5
extern const USBDM::GpioC<6>     gpioC_6;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D21            gpioC_6              //!< Alias for @ref USBDM::gpioC_6
extern const USBDM::GpioC<7>     gpioC_7;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D16            gpioC_7              //!< Alias for @ref USBDM::gpioC_7
extern const USBDM::GpioC<8>     gpioC_8;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D6             gpioC_8              //!< Alias for @ref USBDM::gpioC_8
extern const USBDM::GpioC<9>     gpioC_9;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D7             gpioC_9              //!< Alias for @ref USBDM::gpioC_9
extern const USBDM::GpioC<10>    gpioC_10;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D22            gpioC_10             //!< Alias for @ref USBDM::gpioC_10
extern const USBDM::GpioC<11>    gpioC_11;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D23            gpioC_11             //!< Alias for @ref USBDM::gpioC_11
extern const USBDM::GpioC<12>    gpioC_12;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D24            gpioC_12             //!< Alias for @ref USBDM::gpioC_12
extern const USBDM::GpioC<13>    gpioC_13;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D25            gpioC_13             //!< Alias for @ref USBDM::gpioC_13
extern const USBDM::GpioC<16>    gpioC_16;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D26            gpioC_16             //!< Alias for @ref USBDM::gpioC_16
extern const USBDM::GpioC<17>    gpioC_17;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D27            gpioC_17             //!< Alias for @ref USBDM::gpioC_17
extern const USBDM::GpioD<0>     gpioD_0;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D10            gpioD_0              //!< Alias for @ref USBDM::gpioD_0
extern const USBDM::GpioD<1>     gpioD_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D13            gpioD_1              //!< Alias for @ref USBDM::gpioD_1
#define digitalIO_LED_BLUE       gpioD_1              //!< Alias for @ref USBDM::gpioD_1
extern const USBDM::GpioD<2>     gpioD_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D11            gpioD_2              //!< Alias for @ref USBDM::gpioD_2
extern const USBDM::GpioD<3>     gpioD_3;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D12            gpioD_3              //!< Alias for @ref USBDM::gpioD_3
extern const USBDM::GpioD<4>     gpioD_4;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D2             gpioD_4              //!< Alias for @ref USBDM::gpioD_4
extern const USBDM::GpioD<5>     gpioD_5;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D9             gpioD_5              //!< Alias for @ref USBDM::gpioD_5
extern const USBDM::GpioD<6>     gpioD_6;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D32            gpioD_6              //!< Alias for @ref USBDM::gpioD_6
extern const USBDM::GpioD<7>     gpioD_7;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D33            gpioD_7              //!< Alias for @ref USBDM::gpioD_7
extern const USBDM::GpioE<0>     gpioE_0;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D15            gpioE_0              //!< Alias for @ref USBDM::gpioE_0
extern const USBDM::GpioE<1>     gpioE_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D14            gpioE_1              //!< Alias for @ref USBDM::gpioE_1
extern const USBDM::GpioE<2>     gpioE_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A16            gpioE_2              //!< Alias for @ref USBDM::gpioE_2
extern const USBDM::GpioE<3>     gpioE_3;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A15            gpioE_3              //!< Alias for @ref USBDM::gpioE_3
extern const USBDM::GpioE<4>     gpioE_4;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A14            gpioE_4              //!< Alias for @ref USBDM::gpioE_4
extern const USBDM::GpioE<5>     gpioE_5;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A13            gpioE_5              //!< Alias for @ref USBDM::gpioE_5
extern const USBDM::GpioE<20>    gpioE_20;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A11            gpioE_20             //!< Alias for @ref USBDM::gpioE_20
extern const USBDM::GpioE<21>    gpioE_21;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A10            gpioE_21             //!< Alias for @ref USBDM::gpioE_21
extern const USBDM::GpioE<22>    gpioE_22;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A9             gpioE_22             //!< Alias for @ref USBDM::gpioE_22
extern const USBDM::GpioE<23>    gpioE_23;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A8             gpioE_23             //!< Alias for @ref USBDM::gpioE_23
extern const USBDM::GpioE<24>    gpioE_24;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_ACCEL_SCL      gpioE_24             //!< Alias for @ref USBDM::gpioE_24
extern const USBDM::GpioE<25>    gpioE_25;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_ACCEL_SDA      gpioE_25             //!< Alias for @ref USBDM::gpioE_25
extern const USBDM::GpioE<29>    gpioE_29;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A7             gpioE_29             //!< Alias for @ref USBDM::gpioE_29
extern const USBDM::GpioE<30>    gpioE_30;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A6             gpioE_30             //!< Alias for @ref USBDM::gpioE_30
extern const USBDM::GpioE<31>    gpioE_31;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D30            gpioE_31             //!< Alias for @ref USBDM::gpioE_31
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTB0_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc0_se8;
#define analogueIO_A0            adc0_se8             //!< Alias for @ref USBDM::adc0_se8
#endif
#if (PTB1_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc0_se9;
#define analogueIO_A1            adc0_se9             //!< Alias for @ref USBDM::adc0_se9
#endif
#if (PTB2_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc0_se12;
#define analogueIO_A2            adc0_se12            //!< Alias for @ref USBDM::adc0_se12
#endif
#if (PTB3_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc0_se13;
#define analogueIO_A3            adc0_se13            //!< Alias for @ref USBDM::adc0_se13
#endif
#if (PTC0_SIG_SEL == 0)
extern const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  14> adc0_se14;
#define analogueIO_D17           adc0_se14            //!< Alias for @ref USBDM::adc0_se14
#endif
#if (PTC1_SIG_SEL == 0)
extern const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc0_se15;
#define analogueIO_A5            adc0_se15            //!< Alias for @ref USBDM::adc0_se15
#endif
#if (PTC2_SIG_SEL == 0)
extern const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  11> adc0_se11;
#define analogueIO_A4            adc0_se11            //!< Alias for @ref USBDM::adc0_se11
#endif
#if (PTD1_SIG_SEL == 0)
extern const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc0_se5;
#define analogueIO_D13           adc0_se5             //!< Alias for @ref USBDM::adc0_se5
#define analogueIO_LED_BLUE      adc0_se5             //!< Alias for @ref USBDM::adc0_se5
#endif
#if (PTD5_SIG_SEL == 0)
extern const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc0_se6;
#define analogueIO_D9            adc0_se6             //!< Alias for @ref USBDM::adc0_se6
#endif
#if (PTD6_SIG_SEL == 0)
extern const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc0_se7;
#define analogueIO_D32           adc0_se7             //!< Alias for @ref USBDM::adc0_se7
#endif
#if (PTE20_SIG_SEL == 0)
extern const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]),  0> adc0_se0;
#define analogueIO_A11           adc0_se0             //!< Alias for @ref USBDM::adc0_se0
#endif
#if (PTE21_SIG_SEL == 0)
extern const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]),  4> adc0_se4;
#define analogueIO_A10           adc0_se4             //!< Alias for @ref USBDM::adc0_se4
#endif
#if (PTE22_SIG_SEL == 0)
extern const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]),  3> adc0_se3;
#define analogueIO_A9            adc0_se3             //!< Alias for @ref USBDM::adc0_se3
#endif
#if (PTE23_SIG_SEL == 0)
extern const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]),  7> adc0_se7;
#define analogueIO_A8            adc0_se7             //!< Alias for @ref USBDM::adc0_se7
#endif
#if (PTE29_SIG_SEL == 0)
extern const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]),  4> adc0_se4;
#define analogueIO_A7            adc0_se4             //!< Alias for @ref USBDM::adc0_se4
#endif
#if (PTE30_SIG_SEL == 0)
extern const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), 23> adc0_se23;
#define analogueIO_A6            adc0_se23            //!< Alias for @ref USBDM::adc0_se23
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
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  3> pwmIO_TPM0_CH5;
#endif
#if (PTA1_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#define pwmIO_D0                 pwmIO_TPM2_CH0       //!< Alias for @ref USBDM::pwmIO_TPM2_CH0
#endif
#if (PTA2_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#define pwmIO_D1                 pwmIO_TPM2_CH1       //!< Alias for @ref USBDM::pwmIO_TPM2_CH1
#endif
#if (PTA3_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  3> pwmIO_TPM0_CH0;
#endif
#if (PTA4_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  3> pwmIO_TPM0_CH1;
#define pwmIO_D4                 pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#endif
#if (PTA5_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  3> pwmIO_TPM0_CH2;
#define pwmIO_D5                 pwmIO_TPM0_CH2       //!< Alias for @ref USBDM::pwmIO_TPM0_CH2
#endif
#if (PTA12_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 0,  3> pwmIO_TPM1_CH0;
#define pwmIO_D3                 pwmIO_TPM1_CH0       //!< Alias for @ref USBDM::pwmIO_TPM1_CH0
#endif
#if (PTA13_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 1,  3> pwmIO_TPM1_CH1;
#define pwmIO_D8                 pwmIO_TPM1_CH1       //!< Alias for @ref USBDM::pwmIO_TPM1_CH1
#endif
#if (PTB0_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 0,  3> pwmIO_TPM1_CH0;
#define pwmIO_A0                 pwmIO_TPM1_CH0       //!< Alias for @ref USBDM::pwmIO_TPM1_CH0
#endif
#if (PTB1_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 1,  3> pwmIO_TPM1_CH1;
#define pwmIO_A1                 pwmIO_TPM1_CH1       //!< Alias for @ref USBDM::pwmIO_TPM1_CH1
#endif
#if (PTB2_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#define pwmIO_A2                 pwmIO_TPM2_CH0       //!< Alias for @ref USBDM::pwmIO_TPM2_CH0
#endif
#if (PTB3_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#define pwmIO_A3                 pwmIO_TPM2_CH1       //!< Alias for @ref USBDM::pwmIO_TPM2_CH1
#endif
#if (PTB18_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#define pwmIO_LED_RED            pwmIO_TPM2_CH0       //!< Alias for @ref USBDM::pwmIO_TPM2_CH0
#endif
#if (PTB19_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#define pwmIO_LED_GREEN          pwmIO_TPM2_CH1       //!< Alias for @ref USBDM::pwmIO_TPM2_CH1
#endif
#if (PTC1_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  4> pwmIO_TPM0_CH0;
#define pwmIO_A5                 pwmIO_TPM0_CH0       //!< Alias for @ref USBDM::pwmIO_TPM0_CH0
#endif
#if (PTC2_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  4> pwmIO_TPM0_CH1;
#define pwmIO_A4                 pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#endif
#if (PTC3_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  4> pwmIO_TPM0_CH2;
#define pwmIO_D18                pwmIO_TPM0_CH2       //!< Alias for @ref USBDM::pwmIO_TPM0_CH2
#endif
#if (PTC4_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  4> pwmIO_TPM0_CH3;
#define pwmIO_D19                pwmIO_TPM0_CH3       //!< Alias for @ref USBDM::pwmIO_TPM0_CH3
#endif
#if (PTC8_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  3> pwmIO_TPM0_CH4;
#define pwmIO_D6                 pwmIO_TPM0_CH4       //!< Alias for @ref USBDM::pwmIO_TPM0_CH4
#endif
#if (PTC9_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  3> pwmIO_TPM0_CH5;
#define pwmIO_D7                 pwmIO_TPM0_CH5       //!< Alias for @ref USBDM::pwmIO_TPM0_CH5
#endif
#if (PTD0_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[0]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  4> pwmIO_TPM0_CH0;
#define pwmIO_D10                pwmIO_TPM0_CH0       //!< Alias for @ref USBDM::pwmIO_TPM0_CH0
#endif
#if (PTD1_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  4> pwmIO_TPM0_CH1;
#define pwmIO_D13                pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#define pwmIO_LED_BLUE           pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#endif
#if (PTD2_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  4> pwmIO_TPM0_CH2;
#define pwmIO_D11                pwmIO_TPM0_CH2       //!< Alias for @ref USBDM::pwmIO_TPM0_CH2
#endif
#if (PTD3_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  4> pwmIO_TPM0_CH3;
#define pwmIO_D12                pwmIO_TPM0_CH3       //!< Alias for @ref USBDM::pwmIO_TPM0_CH3
#endif
#if (PTD4_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  4> pwmIO_TPM0_CH4;
#define pwmIO_D2                 pwmIO_TPM0_CH4       //!< Alias for @ref USBDM::pwmIO_TPM0_CH4
#endif
#if (PTD5_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 5,  4> pwmIO_TPM0_CH5;
#define pwmIO_D9                 pwmIO_TPM0_CH5       //!< Alias for @ref USBDM::pwmIO_TPM0_CH5
#endif
#if (PTE20_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 0,  3> pwmIO_TPM1_CH0;
#define pwmIO_A11                pwmIO_TPM1_CH0       //!< Alias for @ref USBDM::pwmIO_TPM1_CH0
#endif
#if (PTE21_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, 1,  3> pwmIO_TPM1_CH1;
#define pwmIO_A10                pwmIO_TPM1_CH1       //!< Alias for @ref USBDM::pwmIO_TPM1_CH1
#endif
#if (PTE22_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 0,  3> pwmIO_TPM2_CH0;
#define pwmIO_A9                 pwmIO_TPM2_CH0       //!< Alias for @ref USBDM::pwmIO_TPM2_CH0
#endif
#if (PTE23_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, 1,  3> pwmIO_TPM2_CH1;
#define pwmIO_A8                 pwmIO_TPM2_CH1       //!< Alias for @ref USBDM::pwmIO_TPM2_CH1
#endif
#if (PTE24_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 0,  3> pwmIO_TPM0_CH0;
#define pwmIO_ACCEL_SCL          pwmIO_TPM0_CH0       //!< Alias for @ref USBDM::pwmIO_TPM0_CH0
#endif
#if (PTE25_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 1,  3> pwmIO_TPM0_CH1;
#define pwmIO_ACCEL_SDA          pwmIO_TPM0_CH1       //!< Alias for @ref USBDM::pwmIO_TPM0_CH1
#endif
#if (PTE29_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 2,  3> pwmIO_TPM0_CH2;
#define pwmIO_A7                 pwmIO_TPM0_CH2       //!< Alias for @ref USBDM::pwmIO_TPM0_CH2
#endif
#if (PTE30_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 3,  3> pwmIO_TPM0_CH3;
#define pwmIO_A6                 pwmIO_TPM0_CH3       //!< Alias for @ref USBDM::pwmIO_TPM0_CH3
#endif
#if (PTE31_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[31]), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, 4,  3> pwmIO_TPM0_CH4;
#define pwmIO_D30                pwmIO_TPM0_CH4       //!< Alias for @ref USBDM::pwmIO_TPM0_CH4
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
CMP        SCGC4        SIM_SCGC4_CMP_MASK
DAC0       SCGC6        SIM_SCGC6_DAC0_MASK
DMA        SCGC7        SIM_SCGC7_DMA_MASK
DMAMUX     SCGC6        SIM_SCGC6_DMAMUX_MASK
I2C0       SCGC4        SIM_SCGC4_I2C0_MASK
I2C1       SCGC4        SIM_SCGC4_I2C1_MASK
LPTMR0     SCGC5        SIM_SCGC5_LPTMR_MASK
PIT        SCGC6        SIM_SCGC6_PIT_MASK
PORTA      SCGC5        SIM_SCGC5_PORTA_MASK
PORTB      SCGC5        SIM_SCGC5_PORTB_MASK
PORTC      SCGC5        SIM_SCGC5_PORTC_MASK
PORTD      SCGC5        SIM_SCGC5_PORTD_MASK
PORTE      SCGC5        SIM_SCGC5_PORTE_MASK
RTC        SCGC6        SIM_SCGC6_RTC_MASK
SPI0       SCGC4        SIM_SCGC4_SPI0_MASK
SPI1       SCGC4        SIM_SCGC4_SPI1_MASK
TPM0       SCGC6        SIM_SCGC6_TPM0_MASK
TPM1       SCGC6        SIM_SCGC6_TPM1_MASK
TPM2       SCGC6        SIM_SCGC6_TPM2_MASK
TSI        SCGC5        SIM_SCGC5_TSI_MASK
UART0      SCGC4        SIM_SCGC4_UART0_MASK
UART1      SCGC4        SIM_SCGC4_UART1_MASK
UART2      SCGC4        SIM_SCGC4_UART2_MASK
USBOTG     SCGC4        SIM_SCGC4_USBOTG_MASK
*/

#if USBDM_USE_NAMESPACES
} // End namespace USBDM
#endif

#endif /* GPIO_H_ */
