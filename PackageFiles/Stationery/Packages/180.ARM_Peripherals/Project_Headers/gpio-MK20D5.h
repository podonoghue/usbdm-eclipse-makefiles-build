/**
 * @file      gpio.h (derived from gpio-MK20D5.h)
 * @version   1.1.0
 * @brief     Pin declarations for MK20D5
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
#define digitalIO_D5             gpioA_1              //!< Alias for @ref USBDM::gpioA_1
extern const USBDM::GpioA<2>     gpioA_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D9             gpioA_2              //!< Alias for @ref USBDM::gpioA_2
#define digitalIO_LED_BLUE       gpioA_2              //!< Alias for @ref USBDM::gpioA_2
extern const USBDM::GpioA<3>     gpioA_3;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<4>     gpioA_4;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D21            gpioA_4              //!< Alias for @ref USBDM::gpioA_4
extern const USBDM::GpioA<5>     gpioA_5;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D2             gpioA_5              //!< Alias for @ref USBDM::gpioA_5
extern const USBDM::GpioA<12>    gpioA_12;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D8             gpioA_12             //!< Alias for @ref USBDM::gpioA_12
extern const USBDM::GpioA<13>    gpioA_13;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D24            gpioA_13             //!< Alias for @ref USBDM::gpioA_13
extern const USBDM::GpioA<18>    gpioA_18;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<19>    gpioA_19;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<0>     gpioB_0;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A5             gpioB_0              //!< Alias for @ref USBDM::gpioB_0
#define digitalIO_ACC_SCL        gpioB_0              //!< Alias for @ref USBDM::gpioB_0
extern const USBDM::GpioB<1>     gpioB_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A4             gpioB_1              //!< Alias for @ref USBDM::gpioB_1
#define digitalIO_ACC_SDA        gpioB_1              //!< Alias for @ref USBDM::gpioB_1
extern const USBDM::GpioB<2>     gpioB_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D15            gpioB_2              //!< Alias for @ref USBDM::gpioB_2
extern const USBDM::GpioB<3>     gpioB_3;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D14            gpioB_3              //!< Alias for @ref USBDM::gpioB_3
extern const USBDM::GpioB<16>    gpioB_16;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<17>    gpioB_17;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<18>    gpioB_18;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<19>    gpioB_19;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<0>     gpioC_0;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A0             gpioC_0              //!< Alias for @ref USBDM::gpioC_0
extern const USBDM::GpioC<1>     gpioC_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A1             gpioC_1              //!< Alias for @ref USBDM::gpioC_1
extern const USBDM::GpioC<2>     gpioC_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D10            gpioC_2              //!< Alias for @ref USBDM::gpioC_2
extern const USBDM::GpioC<3>     gpioC_3;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D6             gpioC_3              //!< Alias for @ref USBDM::gpioC_3
#define digitalIO_LED_RED        gpioC_3              //!< Alias for @ref USBDM::gpioC_3
extern const USBDM::GpioC<4>     gpioC_4;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D7             gpioC_4              //!< Alias for @ref USBDM::gpioC_4
extern const USBDM::GpioC<5>     gpioC_5;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D18            gpioC_5              //!< Alias for @ref USBDM::gpioC_5
extern const USBDM::GpioC<6>     gpioC_6;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D19            gpioC_6              //!< Alias for @ref USBDM::gpioC_6
#define digitalIO_ACC_INT2       gpioC_6              //!< Alias for @ref USBDM::gpioC_6
extern const USBDM::GpioC<7>     gpioC_7;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D20            gpioC_7              //!< Alias for @ref USBDM::gpioC_7
extern const USBDM::GpioC<8>     gpioC_8;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D4             gpioC_8              //!< Alias for @ref USBDM::gpioC_8
extern const USBDM::GpioC<9>     gpioC_9;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D23            gpioC_9              //!< Alias for @ref USBDM::gpioC_9
extern const USBDM::GpioC<10>    gpioC_10;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D25            gpioC_10             //!< Alias for @ref USBDM::gpioC_10
extern const USBDM::GpioC<11>    gpioC_11;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D17            gpioC_11             //!< Alias for @ref USBDM::gpioC_11
#define digitalIO_ACC_INT1       gpioC_11             //!< Alias for @ref USBDM::gpioC_11
extern const USBDM::GpioD<0>     gpioD_0;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D16            gpioD_0              //!< Alias for @ref USBDM::gpioD_0
extern const USBDM::GpioD<1>     gpioD_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D13            gpioD_1              //!< Alias for @ref USBDM::gpioD_1
extern const USBDM::GpioD<2>     gpioD_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D11            gpioD_2              //!< Alias for @ref USBDM::gpioD_2
extern const USBDM::GpioD<3>     gpioD_3;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D12            gpioD_3              //!< Alias for @ref USBDM::gpioD_3
extern const USBDM::GpioD<4>     gpioD_4;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D3             gpioD_4              //!< Alias for @ref USBDM::gpioD_4
#define digitalIO_LED_GREEN      gpioD_4              //!< Alias for @ref USBDM::gpioD_4
extern const USBDM::GpioD<5>     gpioD_5;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A3             gpioD_5              //!< Alias for @ref USBDM::gpioD_5
extern const USBDM::GpioD<6>     gpioD_6;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A2             gpioD_6              //!< Alias for @ref USBDM::gpioD_6
extern const USBDM::GpioD<7>     gpioD_7;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D22            gpioD_7              //!< Alias for @ref USBDM::gpioD_7
extern const USBDM::GpioE<0>     gpioE_0;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D1             gpioE_0              //!< Alias for @ref USBDM::gpioE_0
extern const USBDM::GpioE<1>     gpioE_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D0             gpioE_1              //!< Alias for @ref USBDM::gpioE_1
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
extern const USBDM::Adc0<0,                0,                                         19> adc0_se19;
extern const USBDM::Adc0<0,                0,                                         21> adc0_se21;
extern const USBDM::Adc0<0,                0,                                          0> adc0_se0;
extern const USBDM::Adc0<0,                0,                                          3> adc0_se3;
extern const USBDM::Adc0<0,                0,                                         23> adc0_se23;
#if (PTB0_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc0_se8;
#define analogueIO_A5            adc0_se8             //!< Alias for @ref USBDM::adc0_se8
#define analogueIO_ACC_SCL       adc0_se8             //!< Alias for @ref USBDM::adc0_se8
#endif
#if (PTB1_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc0_se9;
#define analogueIO_A4            adc0_se9             //!< Alias for @ref USBDM::adc0_se9
#define analogueIO_ACC_SDA       adc0_se9             //!< Alias for @ref USBDM::adc0_se9
#endif
#if (PTB2_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc0_se12;
#define analogueIO_D15           adc0_se12            //!< Alias for @ref USBDM::adc0_se12
#endif
#if (PTB3_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc0_se13;
#define analogueIO_D14           adc0_se13            //!< Alias for @ref USBDM::adc0_se13
#endif
#if (PTC0_SIG_SEL == 0)
extern const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  14> adc0_se14;
#define analogueIO_A0            adc0_se14            //!< Alias for @ref USBDM::adc0_se14
#endif
#if (PTC1_SIG_SEL == 0)
extern const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc0_se15;
#define analogueIO_A1            adc0_se15            //!< Alias for @ref USBDM::adc0_se15
#endif
#if (PTC2_SIG_SEL == 0)
extern const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4> adc0_se4;
#define analogueIO_D10           adc0_se4             //!< Alias for @ref USBDM::adc0_se4
#endif
#if (PTD1_SIG_SEL == 0)
extern const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc0_se5;
#define analogueIO_D13           adc0_se5             //!< Alias for @ref USBDM::adc0_se5
#endif
#if (PTD5_SIG_SEL == 0)
extern const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc0_se6;
#define analogueIO_A3            adc0_se6             //!< Alias for @ref USBDM::adc0_se6
#endif
#if (PTD6_SIG_SEL == 0)
extern const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc0_se7;
#define analogueIO_A2            adc0_se7             //!< Alias for @ref USBDM::adc0_se7
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
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  5>   ftm0_ch5;
#endif
#if (PTA1_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm0_ch6;
#define pwmIO_D5                 ftm0_ch6             //!< Alias for @ref USBDM::ftm0_ch6
#endif
#if (PTA2_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  7>   ftm0_ch7;
#define pwmIO_D9                 ftm0_ch7             //!< Alias for @ref USBDM::ftm0_ch7
#define pwmIO_LED_BLUE           ftm0_ch7             //!< Alias for @ref USBDM::ftm0_ch7
#endif
#if (PTA3_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),   3,  0>   ftm0_ch0;
#endif
#if (PTA4_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),   3,  1>   ftm0_ch1;
#define pwmIO_D21                ftm0_ch1             //!< Alias for @ref USBDM::ftm0_ch1
#endif
#if (PTA5_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),   3,  2>   ftm0_ch2;
#define pwmIO_D2                 ftm0_ch2             //!< Alias for @ref USBDM::ftm0_ch2
#endif
#if (PTA12_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]),  3,  0>   ftm1_ch0;
#define pwmIO_D8                 ftm1_ch0             //!< Alias for @ref USBDM::ftm1_ch0
#endif
#if (PTA13_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]),  3,  1>   ftm1_ch1;
#define pwmIO_D24                ftm1_ch1             //!< Alias for @ref USBDM::ftm1_ch1
#endif
#if (PTB0_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   ftm1_ch0;
#define pwmIO_A5                 ftm1_ch0             //!< Alias for @ref USBDM::ftm1_ch0
#define pwmIO_ACC_SCL            ftm1_ch0             //!< Alias for @ref USBDM::ftm1_ch0
#endif
#if (PTB1_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   ftm1_ch1;
#define pwmIO_A4                 ftm1_ch1             //!< Alias for @ref USBDM::ftm1_ch1
#define pwmIO_ACC_SDA            ftm1_ch1             //!< Alias for @ref USBDM::ftm1_ch1
#endif
#if (PTC1_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  0>   ftm0_ch0;
#define pwmIO_A1                 ftm0_ch0             //!< Alias for @ref USBDM::ftm0_ch0
#endif
#if (PTC2_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  1>   ftm0_ch1;
#define pwmIO_D10                ftm0_ch1             //!< Alias for @ref USBDM::ftm0_ch1
#endif
#if (PTC3_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   ftm0_ch2;
#define pwmIO_D6                 ftm0_ch2             //!< Alias for @ref USBDM::ftm0_ch2
#define pwmIO_LED_RED            ftm0_ch2             //!< Alias for @ref USBDM::ftm0_ch2
#endif
#if (PTC4_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  3>   ftm0_ch3;
#define pwmIO_D7                 ftm0_ch3             //!< Alias for @ref USBDM::ftm0_ch3
#endif
#if (PTD4_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   ftm0_ch4;
#define pwmIO_D3                 ftm0_ch4             //!< Alias for @ref USBDM::ftm0_ch4
#define pwmIO_LED_GREEN          ftm0_ch4             //!< Alias for @ref USBDM::ftm0_ch4
#endif
#if (PTD5_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   ftm0_ch5;
#define pwmIO_A3                 ftm0_ch5             //!< Alias for @ref USBDM::ftm0_ch5
#endif
#if (PTD6_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   4,  6>   ftm0_ch6;
#define pwmIO_A2                 ftm0_ch6             //!< Alias for @ref USBDM::ftm0_ch6
#endif
#if (PTD7_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),   4,  7>   ftm0_ch7;
#define pwmIO_D22                ftm0_ch7             //!< Alias for @ref USBDM::ftm0_ch7
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
CMT        SCGC4        SIM_SCGC4_CMT_MASK
CRC        SCGC6        SIM_SCGC6_CRC_MASK
DMA        SCGC7        SIM_SCGC7_DMA_MASK
DMAMUX     SCGC6        SIM_SCGC6_DMAMUX_MASK
EWM        SCGC4        SIM_SCGC4_EWM_MASK
FTM0       SCGC6        SIM_SCGC6_FTM0_MASK
FTM1       SCGC6        SIM_SCGC6_FTM1_MASK
I2C0       SCGC4        SIM_SCGC4_I2C0_MASK
I2S0       SCGC6        SIM_SCGC6_I2S0_MASK
LPTMR0     SCGC5        SIM_SCGC5_LPTMR_MASK
PDB0       SCGC6        SIM_SCGC6_PDB0_MASK
PIT        SCGC6        SIM_SCGC6_PIT_MASK
PORTA      SCGC5        SIM_SCGC5_PORTA_MASK
PORTB      SCGC5        SIM_SCGC5_PORTB_MASK
PORTC      SCGC5        SIM_SCGC5_PORTC_MASK
PORTD      SCGC5        SIM_SCGC5_PORTD_MASK
PORTE      SCGC5        SIM_SCGC5_PORTE_MASK
RTC        SCGC6        SIM_SCGC6_RTC_MASK
SPI0       SCGC6        SIM_SCGC6_SPI0_MASK
TSI        SCGC5        SIM_SCGC5_TSI_MASK
UART0      SCGC4        SIM_SCGC4_UART0_MASK
UART1      SCGC4        SIM_SCGC4_UART1_MASK
UART2      SCGC4        SIM_SCGC4_UART2_MASK
USBDCD     SCGC6        SIM_SCGC6_USBDCD_MASK
USBOTG     SCGC4        SIM_SCGC4_USBOTG_MASK
VREF       SCGC4        SIM_SCGC4_VREF_MASK
*/

#if USBDM_USE_NAMESPACES
} // End namespace USBDM
#endif

#endif /* GPIO_H_ */
