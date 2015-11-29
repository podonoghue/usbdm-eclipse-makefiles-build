/**
 * @file      gpio.h (derived from gpio-MKM33Z5.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKM33Z5
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
const USBDM::GpioA<0>     gpio_LED_RED;
const USBDM::GpioA<1>     gpioA_1;
const USBDM::GpioA<1>     gpio_LED_GREEN;
const USBDM::GpioA<2>     gpioA_2;
const USBDM::GpioA<3>     gpioA_3;
const USBDM::GpioA<4>     gpioA_4;
const USBDM::GpioA<5>     gpioA_5;
const USBDM::GpioA<6>     gpioA_6;
const USBDM::GpioA<7>     gpioA_7;
const USBDM::GpioB<0>     gpioB_0;
const USBDM::GpioB<1>     gpioB_1;
const USBDM::GpioB<2>     gpioB_2;
const USBDM::GpioB<3>     gpioB_3;
const USBDM::GpioB<4>     gpioB_4;
const USBDM::GpioB<5>     gpioB_5;
const USBDM::GpioB<6>     gpioB_6;
const USBDM::GpioB<7>     gpioB_7;
const USBDM::GpioC<0>     gpioC_0;
const USBDM::GpioC<1>     gpioC_1;
const USBDM::GpioC<2>     gpioC_2;
const USBDM::GpioC<3>     gpioC_3;
const USBDM::GpioC<4>     gpioC_4;
const USBDM::GpioC<5>     gpioC_5;
const USBDM::GpioC<6>     gpioC_6;
const USBDM::GpioC<7>     gpioC_7;
const USBDM::GpioD<0>     gpioD_0;
const USBDM::GpioD<1>     gpioD_1;
const USBDM::GpioD<1>     gpio_LED_BLUE;
const USBDM::GpioD<2>     gpioD_2;
const USBDM::GpioD<3>     gpioD_3;
const USBDM::GpioD<4>     gpioD_4;
const USBDM::GpioD<5>     gpioD_5;
const USBDM::GpioD<6>     gpioD_6;
const USBDM::GpioD<7>     gpioD_7;
const USBDM::GpioE<0>     gpioE_0;
const USBDM::GpioE<1>     gpioE_1;
const USBDM::GpioE<2>     gpioE_2;
const USBDM::GpioE<3>     gpioE_3;
const USBDM::GpioE<4>     gpioE_4;
const USBDM::GpioE<5>     gpioE_5;
const USBDM::GpioE<6>     gpioE_6;
const USBDM::GpioE<7>     gpioE_7;
const USBDM::GpioF<0>     gpioF_0;
const USBDM::GpioF<1>     gpioF_1;
const USBDM::GpioF<2>     gpioF_2;
const USBDM::GpioF<3>     gpioF_3;
const USBDM::GpioF<4>     gpioF_4;
const USBDM::GpioF<5>     gpioF_5;
const USBDM::GpioF<6>     gpioF_6;
const USBDM::GpioF<7>     gpioF_7;
const USBDM::GpioG<0>     gpioG_0;
const USBDM::GpioG<1>     gpioG_1;
const USBDM::GpioG<2>     gpioG_2;
const USBDM::GpioG<3>     gpioG_3;
const USBDM::GpioG<4>     gpioG_4;
const USBDM::GpioG<5>     gpioG_5;
const USBDM::GpioG<6>     gpioG_6;
const USBDM::GpioG<7>     gpioG_7;
const USBDM::GpioH<0>     gpioH_0;
const USBDM::GpioH<1>     gpioH_1;
const USBDM::GpioH<2>     gpioH_2;
const USBDM::GpioH<3>     gpioH_3;
const USBDM::GpioH<4>     gpioH_4;
const USBDM::GpioH<5>     gpioH_5;
const USBDM::GpioH<6>     gpioH_6;
const USBDM::GpioH<7>     gpioH_7;
const USBDM::GpioI<0>     gpioI_0;
const USBDM::GpioI<1>     gpioI_1;
const USBDM::GpioI<2>     gpioI_2;
const USBDM::GpioI<3>     gpioI_3;
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
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
ADC0       SCGC6        SIM_SCGC6_ADC_MASK
AFE        SCGC6        SIM_SCGC6_AFE_MASK
CMP0       SCGC4        SIM_SCGC4_CMP0_MASK
CMP1       SCGC4        SIM_SCGC4_CMP1_MASK
CRC        SCGC6        SIM_SCGC6_CRC_MASK
DMA        SCGC7        SIM_SCGC7_DMA_MASK
DMAMUX0    SCGC6        SIM_SCGC6_DMAMUX0_MASK
DMAMUX1    SCGC6        SIM_SCGC6_DMAMUX1_MASK
DMAMUX2    SCGC6        SIM_SCGC6_DMAMUX2_MASK
DMAMUX3    SCGC6        SIM_SCGC6_DMAMUX3_MASK
EWM        SCGC4        SIM_SCGC4_EWM_MASK
I2C0       SCGC4        SIM_SCGC4_I2C0_MASK
I2C1       SCGC4        SIM_SCGC4_I2C1_MASK
IRTC       SCGC5        SIM_SCGC5_IRTC_MASK
IRTCREGFILE SCGC5        SIM_SCGC5_IRTCREGFILE_MASK
LPTMR0     SCGC6        SIM_SCGC6_LPTMR_MASK
MCG        SCGC4        SIM_SCGC4_MCG_MASK
MPU        SCGC7        SIM_SCGC7_MPU_MASK
OSC        SCGC4        SIM_SCGC4_OSC_MASK
PIT0       SCGC6        SIM_SCGC6_PIT0_MASK
PIT1       SCGC6        SIM_SCGC6_PIT1_MASK
PORTA      SCGC5        SIM_SCGC5_PORTA_MASK
PORTB      SCGC5        SIM_SCGC5_PORTB_MASK
PORTC      SCGC5        SIM_SCGC5_PORTC_MASK
PORTD      SCGC5        SIM_SCGC5_PORTD_MASK
PORTE      SCGC5        SIM_SCGC5_PORTE_MASK
PORTF      SCGC5        SIM_SCGC5_PORTF_MASK
PORTG      SCGC5        SIM_SCGC5_PORTG_MASK
PORTH      SCGC5        SIM_SCGC5_PORTH_MASK
PORTI      SCGC5        SIM_SCGC5_PORTI_MASK
RNGA       SCGC6        SIM_SCGC6_RNGA_MASK
SIM_HP     SCGC6        SIM_SCGC6_SIM_HP_MASK
SIM_LP     SCGC6        SIM_SCGC6_SIM_LP_MASK
SLCD       SCGC5        SIM_SCGC5_SLCD_MASK
SPI0       SCGC4        SIM_SCGC4_SPI0_MASK
SPI1       SCGC4        SIM_SCGC4_SPI1_MASK
TMR0       SCGC5        SIM_SCGC5_TMR0_MASK
TMR1       SCGC5        SIM_SCGC5_TMR1_MASK
TMR2       SCGC5        SIM_SCGC5_TMR2_MASK
TMR3       SCGC5        SIM_SCGC5_TMR3_MASK
UART0      SCGC4        SIM_SCGC4_UART0_MASK
UART1      SCGC4        SIM_SCGC4_UART1_MASK
UART2      SCGC4        SIM_SCGC4_UART2_MASK
UART3      SCGC4        SIM_SCGC4_UART3_MASK
VREF       SCGC4        SIM_SCGC4_VREF_MASK
WDOG       SCGC5        SIM_SCGC5_WDOG_MASK
XBAR       SCGC5        SIM_SCGC5_XBAR_MASK
*/

} // End namespace USBDM

#endif /* GPIO_H_ */
