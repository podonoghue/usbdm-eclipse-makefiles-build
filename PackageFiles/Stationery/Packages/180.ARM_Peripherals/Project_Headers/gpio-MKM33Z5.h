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
using gpioA_0              = const USBDM::GpioA<0>;
using gpio_LED_RED         = const USBDM::GpioA<0>;
using gpioA_1              = const USBDM::GpioA<1>;
using gpio_LED_GREEN       = const USBDM::GpioA<1>;
using gpioA_2              = const USBDM::GpioA<2>;
using gpioA_3              = const USBDM::GpioA<3>;
using gpioA_4              = const USBDM::GpioA<4>;
using gpioA_5              = const USBDM::GpioA<5>;
using gpioA_6              = const USBDM::GpioA<6>;
using gpioA_7              = const USBDM::GpioA<7>;
using gpioB_0              = const USBDM::GpioB<0>;
using gpioB_1              = const USBDM::GpioB<1>;
using gpioB_2              = const USBDM::GpioB<2>;
using gpioB_3              = const USBDM::GpioB<3>;
using gpioB_4              = const USBDM::GpioB<4>;
using gpioB_5              = const USBDM::GpioB<5>;
using gpioB_6              = const USBDM::GpioB<6>;
using gpioB_7              = const USBDM::GpioB<7>;
using gpioC_0              = const USBDM::GpioC<0>;
using gpioC_1              = const USBDM::GpioC<1>;
using gpioC_2              = const USBDM::GpioC<2>;
using gpioC_3              = const USBDM::GpioC<3>;
using gpioC_4              = const USBDM::GpioC<4>;
using gpioC_5              = const USBDM::GpioC<5>;
using gpioC_6              = const USBDM::GpioC<6>;
using gpioC_7              = const USBDM::GpioC<7>;
using gpioD_0              = const USBDM::GpioD<0>;
using gpioD_1              = const USBDM::GpioD<1>;
using gpio_LED_BLUE        = const USBDM::GpioD<1>;
using gpioD_2              = const USBDM::GpioD<2>;
using gpioD_3              = const USBDM::GpioD<3>;
using gpioD_4              = const USBDM::GpioD<4>;
using gpioD_5              = const USBDM::GpioD<5>;
using gpioD_6              = const USBDM::GpioD<6>;
using gpioD_7              = const USBDM::GpioD<7>;
using gpioE_0              = const USBDM::GpioE<0>;
using gpioE_1              = const USBDM::GpioE<1>;
using gpioE_2              = const USBDM::GpioE<2>;
using gpioE_3              = const USBDM::GpioE<3>;
using gpioE_4              = const USBDM::GpioE<4>;
using gpioE_5              = const USBDM::GpioE<5>;
using gpioE_6              = const USBDM::GpioE<6>;
using gpioE_7              = const USBDM::GpioE<7>;
using gpioF_0              = const USBDM::GpioF<0>;
using gpioF_1              = const USBDM::GpioF<1>;
using gpioF_2              = const USBDM::GpioF<2>;
using gpioF_3              = const USBDM::GpioF<3>;
using gpioF_4              = const USBDM::GpioF<4>;
using gpioF_5              = const USBDM::GpioF<5>;
using gpioF_6              = const USBDM::GpioF<6>;
using gpioF_7              = const USBDM::GpioF<7>;
using gpioG_0              = const USBDM::GpioG<0>;
using gpioG_1              = const USBDM::GpioG<1>;
using gpioG_2              = const USBDM::GpioG<2>;
using gpioG_3              = const USBDM::GpioG<3>;
using gpioG_4              = const USBDM::GpioG<4>;
using gpioG_5              = const USBDM::GpioG<5>;
using gpioG_6              = const USBDM::GpioG<6>;
using gpioG_7              = const USBDM::GpioG<7>;
using gpioH_0              = const USBDM::GpioH<0>;
using gpioH_1              = const USBDM::GpioH<1>;
using gpioH_2              = const USBDM::GpioH<2>;
using gpioH_3              = const USBDM::GpioH<3>;
using gpioH_4              = const USBDM::GpioH<4>;
using gpioH_5              = const USBDM::GpioH<5>;
using gpioH_6              = const USBDM::GpioH<6>;
using gpioH_7              = const USBDM::GpioH<7>;
using gpioI_0              = const USBDM::GpioI<0>;
using gpioI_1              = const USBDM::GpioI<1>;
using gpioI_2              = const USBDM::GpioI<2>;
using gpioI_3              = const USBDM::GpioI<3>;
/**
 * @}
 */
constexpr PcrInfo Adc0Info[32] = {
#if (PTC5_SIG_SEL == 0)
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),  0},
#else
 /*  0 */  { 0, 0, 0 },
#endif
#if (PTC6_SIG_SEL == 0)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[6]),  0},
#else
 /*  1 */  { 0, 0, 0 },
#endif
#if (PTC7_SIG_SEL == 0)
 /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[7]),  0},
#else
 /*  2 */  { 0, 0, 0 },
#endif
#if (PTD4_SIG_SEL == 0)
 /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  0},
#else
 /*  3 */  { 0, 0, 0 },
#endif
#if (PTD5_SIG_SEL == 0)
 /*  4 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  0},
#else
 /*  4 */  { 0, 0, 0 },
#endif
#if (PTD6_SIG_SEL == 0)
 /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  0},
#else
 /*  5 */  { 0, 0, 0 },
#endif
#if (PTE7_SIG_SEL == 0)
 /*  6 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[7]),  0},
#else
 /*  6 */  { 0, 0, 0 },
#endif
#if (PTF0_SIG_SEL == 0)
 /*  7 */  { PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[0]),  0},
#else
 /*  7 */  { 0, 0, 0 },
#endif
#if (PTF1_SIG_SEL == 0)
 /*  8 */  { PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[1]),  0},
#else
 /*  8 */  { 0, 0, 0 },
#endif
#if (PTF2_SIG_SEL == 0)
 /*  9 */  { PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[2]),  0},
#else
 /*  9 */  { 0, 0, 0 },
#endif
#if (PTG1_SIG_SEL == 0)
 /* 10 */  { PORTG_CLOCK_MASK, PORTG_BasePtr+offsetof(PORT_Type,PCR[1]),  0},
#else
 /* 10 */  { 0, 0, 0 },
#endif
#if (PTG2_SIG_SEL == 0)
 /* 11 */  { PORTG_CLOCK_MASK, PORTG_BasePtr+offsetof(PORT_Type,PCR[2]),  0},
#else
 /* 11 */  { 0, 0, 0 },
#endif
};

/**
 * Convenience templated class representing an ADC
 *
 * Example
 * @code
 *  // Instantiate ADC0 single-ended channel #8
 *  const adc0<8> adc0_se8;
 *
 *  // Initialise ADC
 *  adc0_se8.initialiseADC(USBDM::resolution_12bit_se);
 *
 *  // Set as analogue input
 *  adc0_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc0_se8.readAnalogue();
 *  @endcode
 *
 * @tparam adcChannel    ADC channel
 */
template<uint8_t adcChannel> using Adc0 =
   AnalogueIOT<getPortClockMask(adcChannel,Adc0Info), getPcrReg(adcChannel,Adc0Info), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;

/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTC5_SIG_SEL == 0)
using adc0_se0             = const USBDM::Adc0< 0>;
#endif
#if (PTC6_SIG_SEL == 0)
using adc0_se1             = const USBDM::Adc0< 1>;
#endif
#if (PTC7_SIG_SEL == 0)
using adc0_se2             = const USBDM::Adc0< 2>;
#endif
#if (PTD4_SIG_SEL == 0)
using adc0_se3             = const USBDM::Adc0< 3>;
#endif
#if (PTD5_SIG_SEL == 0)
using adc0_se4             = const USBDM::Adc0< 4>;
#endif
#if (PTD6_SIG_SEL == 0)
using adc0_se5             = const USBDM::Adc0< 5>;
#endif
#if (PTE7_SIG_SEL == 0)
using adc0_se6             = const USBDM::Adc0< 6>;
#endif
#if (PTF0_SIG_SEL == 0)
using adc0_se7             = const USBDM::Adc0< 7>;
#endif
#if (PTF1_SIG_SEL == 0)
using adc0_se8             = const USBDM::Adc0< 8>;
#endif
#if (PTF2_SIG_SEL == 0)
using adc0_se9             = const USBDM::Adc0< 9>;
#endif
#if (PTG1_SIG_SEL == 0)
using adc0_se10            = const USBDM::Adc0<10>;
#endif
#if (PTG2_SIG_SEL == 0)
using adc0_se11            = const USBDM::Adc0<11>;
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
