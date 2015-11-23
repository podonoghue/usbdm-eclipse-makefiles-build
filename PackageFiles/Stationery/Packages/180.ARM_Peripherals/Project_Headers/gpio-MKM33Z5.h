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

#if defined(USE_USBDM_NAMESPACE) && USE_USBDM_NAMESPACE
namespace USBDM {
#endif
/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
extern const USBDM::PortA_T<0>   digitalIO_PTA0;      //!< See @ref DigitalIO
#define digitalIO_LED_RED        digitalIO_PTA0       //!< Alias for @ref USBDM::digitalIO_PTA0
extern const USBDM::PortA_T<1>   digitalIO_PTA1;      //!< See @ref DigitalIO
#define digitalIO_LED_GREEN      digitalIO_PTA1       //!< Alias for @ref USBDM::digitalIO_PTA1
extern const USBDM::PortA_T<2>   digitalIO_PTA2;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<3>   digitalIO_PTA3;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<4>   digitalIO_PTA4;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<5>   digitalIO_PTA5;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<6>   digitalIO_PTA6;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<7>   digitalIO_PTA7;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<0>   digitalIO_PTB0;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<1>   digitalIO_PTB1;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<2>   digitalIO_PTB2;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<3>   digitalIO_PTB3;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<4>   digitalIO_PTB4;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<5>   digitalIO_PTB5;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<6>   digitalIO_PTB6;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<7>   digitalIO_PTB7;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<0>   digitalIO_PTC0;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<1>   digitalIO_PTC1;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<2>   digitalIO_PTC2;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<3>   digitalIO_PTC3;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<4>   digitalIO_PTC4;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<5>   digitalIO_PTC5;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<6>   digitalIO_PTC6;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<7>   digitalIO_PTC7;      //!< See @ref DigitalIO
extern const USBDM::PortD_T<0>   digitalIO_PTD0;      //!< See @ref DigitalIO
extern const USBDM::PortD_T<1>   digitalIO_PTD1;      //!< See @ref DigitalIO
#define digitalIO_LED_BLUE       digitalIO_PTD1       //!< Alias for @ref USBDM::digitalIO_PTD1
extern const USBDM::PortD_T<2>   digitalIO_PTD2;      //!< See @ref DigitalIO
extern const USBDM::PortD_T<3>   digitalIO_PTD3;      //!< See @ref DigitalIO
extern const USBDM::PortD_T<4>   digitalIO_PTD4;      //!< See @ref DigitalIO
extern const USBDM::PortD_T<5>   digitalIO_PTD5;      //!< See @ref DigitalIO
extern const USBDM::PortD_T<6>   digitalIO_PTD6;      //!< See @ref DigitalIO
extern const USBDM::PortD_T<7>   digitalIO_PTD7;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<0>   digitalIO_PTE0;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<1>   digitalIO_PTE1;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<2>   digitalIO_PTE2;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<3>   digitalIO_PTE3;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<4>   digitalIO_PTE4;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<5>   digitalIO_PTE5;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<6>   digitalIO_PTE6;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<7>   digitalIO_PTE7;      //!< See @ref DigitalIO
extern const USBDM::PortF_T<0>   digitalIO_PTF0;      //!< See @ref DigitalIO
extern const USBDM::PortF_T<1>   digitalIO_PTF1;      //!< See @ref DigitalIO
extern const USBDM::PortF_T<2>   digitalIO_PTF2;      //!< See @ref DigitalIO
extern const USBDM::PortF_T<3>   digitalIO_PTF3;      //!< See @ref DigitalIO
extern const USBDM::PortF_T<4>   digitalIO_PTF4;      //!< See @ref DigitalIO
extern const USBDM::PortF_T<5>   digitalIO_PTF5;      //!< See @ref DigitalIO
extern const USBDM::PortF_T<6>   digitalIO_PTF6;      //!< See @ref DigitalIO
extern const USBDM::PortF_T<7>   digitalIO_PTF7;      //!< See @ref DigitalIO
extern const USBDM::PortG_T<0>   digitalIO_PTG0;      //!< See @ref DigitalIO
extern const USBDM::PortG_T<1>   digitalIO_PTG1;      //!< See @ref DigitalIO
extern const USBDM::PortG_T<2>   digitalIO_PTG2;      //!< See @ref DigitalIO
extern const USBDM::PortG_T<3>   digitalIO_PTG3;      //!< See @ref DigitalIO
extern const USBDM::PortG_T<4>   digitalIO_PTG4;      //!< See @ref DigitalIO
extern const USBDM::PortG_T<5>   digitalIO_PTG5;      //!< See @ref DigitalIO
extern const USBDM::PortG_T<6>   digitalIO_PTG6;      //!< See @ref DigitalIO
extern const USBDM::PortG_T<7>   digitalIO_PTG7;      //!< See @ref DigitalIO
extern const USBDM::PortH_T<0>   digitalIO_PTH0;      //!< See @ref DigitalIO
extern const USBDM::PortH_T<1>   digitalIO_PTH1;      //!< See @ref DigitalIO
extern const USBDM::PortH_T<2>   digitalIO_PTH2;      //!< See @ref DigitalIO
extern const USBDM::PortH_T<3>   digitalIO_PTH3;      //!< See @ref DigitalIO
extern const USBDM::PortH_T<4>   digitalIO_PTH4;      //!< See @ref DigitalIO
extern const USBDM::PortH_T<5>   digitalIO_PTH5;      //!< See @ref DigitalIO
extern const USBDM::PortH_T<6>   digitalIO_PTH6;      //!< See @ref DigitalIO
extern const USBDM::PortH_T<7>   digitalIO_PTH7;      //!< See @ref DigitalIO
extern const USBDM::PortI_T<0>   digitalIO_PTI0;      //!< See @ref DigitalIO
extern const USBDM::PortI_T<1>   digitalIO_PTI1;      //!< See @ref DigitalIO
extern const USBDM::PortI_T<2>   digitalIO_PTI2;      //!< See @ref DigitalIO
extern const USBDM::PortI_T<3>   digitalIO_PTI3;      //!< See @ref DigitalIO
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTC5_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 0> analogueIO_ADC0_SE0;
#endif
#if (PTC6_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[6]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 1> analogueIO_ADC0_SE1;
#endif
#if (PTC7_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[7]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 2> analogueIO_ADC0_SE2;
#endif
#if (PTD4_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 3> analogueIO_ADC0_SE3;
#endif
#if (PTD5_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 4> analogueIO_ADC0_SE4;
#endif
#if (PTD6_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 5> analogueIO_ADC0_SE5;
#endif
#if (PTE7_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[7]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 6> analogueIO_ADC0_SE6;
#endif
#if (PTF0_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[0]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 7> analogueIO_ADC0_SE7;
#endif
#if (PTF1_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 8> analogueIO_ADC0_SE8;
#endif
#if (PTF2_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 9> analogueIO_ADC0_SE9;
#endif
#if (PTG1_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTG_CLOCK_MASK, PORTG_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,10> analogueIO_ADC0_SE10;
#endif
#if (PTG2_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTG_CLOCK_MASK, PORTG_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,11> analogueIO_ADC0_SE11;
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

#if defined(USE_USBDM_NAMESPACE) && USE_USBDM_NAMESPACE
} // End namespace USBDM
#endif

#endif /* GPIO_H_ */
