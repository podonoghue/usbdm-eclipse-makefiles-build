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

namespace USBDM {
/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
const USBDM::GpioA<0>     gpioA_0;
const USBDM::GpioA<1>     gpioA_1;
const USBDM::GpioA<1>     gpio_D5;
const USBDM::GpioA<2>     gpioA_2;
const USBDM::GpioA<2>     gpio_D9;
const USBDM::GpioA<2>     gpio_LED_BLUE;
const USBDM::GpioA<3>     gpioA_3;
const USBDM::GpioA<4>     gpioA_4;
const USBDM::GpioA<4>     gpio_D21;
const USBDM::GpioA<5>     gpioA_5;
const USBDM::GpioA<5>     gpio_D2;
const USBDM::GpioA<12>    gpioA_12;
const USBDM::GpioA<12>    gpio_D8;
const USBDM::GpioA<13>    gpioA_13;
const USBDM::GpioA<13>    gpio_D24;
const USBDM::GpioA<18>    gpioA_18;
const USBDM::GpioA<19>    gpioA_19;
const USBDM::GpioB<0>     gpioB_0;
const USBDM::GpioB<0>     gpio_A5;
const USBDM::GpioB<0>     gpio_ACC_SCL;
const USBDM::GpioB<1>     gpioB_1;
const USBDM::GpioB<1>     gpio_A4;
const USBDM::GpioB<1>     gpio_ACC_SDA;
const USBDM::GpioB<2>     gpioB_2;
const USBDM::GpioB<2>     gpio_D15;
const USBDM::GpioB<3>     gpioB_3;
const USBDM::GpioB<3>     gpio_D14;
const USBDM::GpioB<16>    gpioB_16;
const USBDM::GpioB<16>    gpio_ConRx;
const USBDM::GpioB<17>    gpioB_17;
const USBDM::GpioB<17>    gpio_ConTx;
const USBDM::GpioB<18>    gpioB_18;
const USBDM::GpioB<19>    gpioB_19;
const USBDM::GpioC<0>     gpioC_0;
const USBDM::GpioC<0>     gpio_A0;
const USBDM::GpioC<1>     gpioC_1;
const USBDM::GpioC<1>     gpio_A1;
const USBDM::GpioC<2>     gpioC_2;
const USBDM::GpioC<2>     gpio_D10;
const USBDM::GpioC<3>     gpioC_3;
const USBDM::GpioC<3>     gpio_D6;
const USBDM::GpioC<3>     gpio_LED_RED;
const USBDM::GpioC<4>     gpioC_4;
const USBDM::GpioC<4>     gpio_D7;
const USBDM::GpioC<5>     gpioC_5;
const USBDM::GpioC<5>     gpio_D18;
const USBDM::GpioC<6>     gpioC_6;
const USBDM::GpioC<6>     gpio_D19;
const USBDM::GpioC<6>     gpio_ACC_INT2;
const USBDM::GpioC<7>     gpioC_7;
const USBDM::GpioC<7>     gpio_D20;
const USBDM::GpioC<8>     gpioC_8;
const USBDM::GpioC<8>     gpio_D4;
const USBDM::GpioC<9>     gpioC_9;
const USBDM::GpioC<9>     gpio_D23;
const USBDM::GpioC<10>    gpioC_10;
const USBDM::GpioC<10>    gpio_D25;
const USBDM::GpioC<11>    gpioC_11;
const USBDM::GpioC<11>    gpio_D17;
const USBDM::GpioC<11>    gpio_ACC_INT1;
const USBDM::GpioD<0>     gpioD_0;
const USBDM::GpioD<0>     gpio_D16;
const USBDM::GpioD<1>     gpioD_1;
const USBDM::GpioD<1>     gpio_D13;
const USBDM::GpioD<2>     gpioD_2;
const USBDM::GpioD<2>     gpio_D11;
const USBDM::GpioD<3>     gpioD_3;
const USBDM::GpioD<3>     gpio_D12;
const USBDM::GpioD<4>     gpioD_4;
const USBDM::GpioD<4>     gpio_D3;
const USBDM::GpioD<4>     gpio_LED_GREEN;
const USBDM::GpioD<5>     gpioD_5;
const USBDM::GpioD<5>     gpio_A3;
const USBDM::GpioD<6>     gpioD_6;
const USBDM::GpioD<6>     gpio_A2;
const USBDM::GpioD<7>     gpioD_7;
const USBDM::GpioD<7>     gpio_D22;
const USBDM::GpioE<0>     gpioE_0;
const USBDM::GpioE<0>     gpio_D1;
const USBDM::GpioE<1>     gpioE_1;
const USBDM::GpioE<1>     gpio_D0;
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
const USBDM::Adc0<0,                0,                                         19> adc0_se19;
const USBDM::Adc0<0,                0,                                         21> adc0_se21;
const USBDM::Adc0<0,                0,                                          0> adc0_se0;
const USBDM::Adc0<0,                0,                                          3> adc0_se3;
const USBDM::Adc0<0,                0,                                         23> adc0_se23;
#if (PTB0_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc0_se8;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc_A5;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc_ACC_SCL;
#endif
#if (PTB1_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc0_se9;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc_A4;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc_ACC_SDA;
#endif
#if (PTB2_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc0_se12;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc_D15;
#endif
#if (PTB3_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc0_se13;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc_D14;
#endif
#if (PTC0_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  14> adc0_se14;
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  14> adc_A0;
#endif
#if (PTC1_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc0_se15;
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc_A1;
#endif
#if (PTC2_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4> adc0_se4;
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4> adc_D10;
#endif
#if (PTD1_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc0_se5;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc_D13;
#endif
#if (PTD5_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc0_se6;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc_A3;
#endif
#if (PTD6_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc0_se7;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc_A2;
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
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  5>   ftm0_ch5;
#endif
#if (PTA1_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm0_ch6;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm_D5;
#endif
#if (PTA2_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  7>   ftm0_ch7;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  7>   ftm_D9;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  7>   ftm_LED_BLUE;
#endif
#if (PTA3_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),   3,  0>   ftm0_ch0;
#endif
#if (PTA4_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),   3,  1>   ftm0_ch1;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),   3,  1>   ftm_D21;
#endif
#if (PTA5_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),   3,  2>   ftm0_ch2;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),   3,  2>   ftm_D2;
#endif
#if (PTA12_SIG_SEL == 3)
const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]),  3,  0>   ftm1_ch0;
const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]),  3,  0>   ftm_D8;
#endif
#if (PTA13_SIG_SEL == 3)
const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]),  3,  1>   ftm1_ch1;
const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]),  3,  1>   ftm_D24;
#endif
#if (PTB0_SIG_SEL == 3)
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   ftm1_ch0;
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   ftm_A5;
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   ftm_ACC_SCL;
#endif
#if (PTB1_SIG_SEL == 3)
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   ftm1_ch1;
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   ftm_A4;
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   ftm_ACC_SDA;
#endif
#if (PTC1_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  0>   ftm0_ch0;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  0>   ftm_A1;
#endif
#if (PTC2_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  1>   ftm0_ch1;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  1>   ftm_D10;
#endif
#if (PTC3_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   ftm0_ch2;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   ftm_D6;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   ftm_LED_RED;
#endif
#if (PTC4_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  3>   ftm0_ch3;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  3>   ftm_D7;
#endif
#if (PTD4_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   ftm0_ch4;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   ftm_D3;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   ftm_LED_GREEN;
#endif
#if (PTD5_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   ftm0_ch5;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   ftm_A3;
#endif
#if (PTD6_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   4,  6>   ftm0_ch6;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   4,  6>   ftm_A2;
#endif
#if (PTD7_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),   4,  7>   ftm0_ch7;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),   4,  7>   ftm_D22;
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

} // End namespace USBDM

#endif /* GPIO_H_ */
