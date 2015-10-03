 /**
  * @file     gpio.cpp (from gpio-MKE06Z4.cpp)
  *
  * @brief   Pin declarations for MKE06Z4
  */

#include "utilities.h"
#include "gpio.h"
#include "pin_mapping.h"

/**
 * @brief Create Timer Clock register name from timer number
 *
 * @param number Timer number e.g. 1 = FTM1_CLOCK_REG
 */
#define FTM_CLOCK_REG(number)  CONCAT3_(FTM,number,_CLOCK_REG)

/**
 * @brief Create Timer Clock register mask from timer number
 *
 * @param number Timer number e.g. 1 = FTM1_CLOCK_MASK
 */
#define FTM_CLOCK_MASK(number)  CONCAT3_(FTM,number,_CLOCK_MASK)

/**
 * @brief Create ADC Clock register name from ADC number
 *
 * @param number Timer number e.g. 1 = ADC1_CLOCK_REG
 */
#define ADC_CLOCK_REG(number)  CONCAT3_(ADC,number,_CLOCK_REG)

/**
 * @brief Create ADC Clock register mask from ADC number
 *
 * @param number Timer number e.g. 1 = ADC1_CLOCK_MASK
 */
#define ADC_CLOCK_MASK(number)  CONCAT3_(ADC,number,_CLOCK_MASK)

#define ADC(num)             CONCAT2_(ADC,num)   
#define FTM(num)             CONCAT2_(FTM,num)   
#define TPM(num)             CONCAT2_(TPM,num)   

const DigitalIO digitalIO_PTA0     = {(volatile GPIO_Type*)GPIO(PTA0_GPIO_NAME),(1UL<<PTA0_GPIO_BIT)};
const DigitalIO digitalIO_PTA1     = {(volatile GPIO_Type*)GPIO(PTA1_GPIO_NAME),(1UL<<PTA1_GPIO_BIT)};
const DigitalIO digitalIO_PTA2     = {(volatile GPIO_Type*)GPIO(PTA2_GPIO_NAME),(1UL<<PTA2_GPIO_BIT)};
const DigitalIO digitalIO_PTA3     = {(volatile GPIO_Type*)GPIO(PTA3_GPIO_NAME),(1UL<<PTA3_GPIO_BIT)};
const DigitalIO digitalIO_PTA5     = {(volatile GPIO_Type*)GPIO(PTA5_GPIO_NAME),(1UL<<PTA5_GPIO_BIT)};
const DigitalIO digitalIO_PTA6     = {(volatile GPIO_Type*)GPIO(PTA6_GPIO_NAME),(1UL<<PTA6_GPIO_BIT)};
const DigitalIO digitalIO_PTA7     = {(volatile GPIO_Type*)GPIO(PTA7_GPIO_NAME),(1UL<<PTA7_GPIO_BIT)};
const DigitalIO digitalIO_PTB0     = {(volatile GPIO_Type*)GPIO(PTB0_GPIO_NAME),(1UL<<PTB0_GPIO_BIT)};
const DigitalIO digitalIO_PTB1     = {(volatile GPIO_Type*)GPIO(PTB1_GPIO_NAME),(1UL<<PTB1_GPIO_BIT)};
const DigitalIO digitalIO_PTB2     = {(volatile GPIO_Type*)GPIO(PTB2_GPIO_NAME),(1UL<<PTB2_GPIO_BIT)};
const DigitalIO digitalIO_PTB3     = {(volatile GPIO_Type*)GPIO(PTB3_GPIO_NAME),(1UL<<PTB3_GPIO_BIT)};
const DigitalIO digitalIO_PTB4     = {(volatile GPIO_Type*)GPIO(PTB4_GPIO_NAME),(1UL<<PTB4_GPIO_BIT)};
const DigitalIO digitalIO_PTB5     = {(volatile GPIO_Type*)GPIO(PTB5_GPIO_NAME),(1UL<<PTB5_GPIO_BIT)};
const DigitalIO digitalIO_PTB6     = {(volatile GPIO_Type*)GPIO(PTB6_GPIO_NAME),(1UL<<PTB6_GPIO_BIT)};
const DigitalIO digitalIO_PTB7     = {(volatile GPIO_Type*)GPIO(PTB7_GPIO_NAME),(1UL<<PTB7_GPIO_BIT)};
const DigitalIO digitalIO_PTC0     = {(volatile GPIO_Type*)GPIO(PTC0_GPIO_NAME),(1UL<<PTC0_GPIO_BIT)};
const DigitalIO digitalIO_PTC1     = {(volatile GPIO_Type*)GPIO(PTC1_GPIO_NAME),(1UL<<PTC1_GPIO_BIT)};
const DigitalIO digitalIO_PTC2     = {(volatile GPIO_Type*)GPIO(PTC2_GPIO_NAME),(1UL<<PTC2_GPIO_BIT)};
const DigitalIO digitalIO_PTC3     = {(volatile GPIO_Type*)GPIO(PTC3_GPIO_NAME),(1UL<<PTC3_GPIO_BIT)};
const DigitalIO digitalIO_PTC4     = {(volatile GPIO_Type*)GPIO(PTC4_GPIO_NAME),(1UL<<PTC4_GPIO_BIT)};
const DigitalIO digitalIO_PTC5     = {(volatile GPIO_Type*)GPIO(PTC5_GPIO_NAME),(1UL<<PTC5_GPIO_BIT)};
const DigitalIO digitalIO_PTC6     = {(volatile GPIO_Type*)GPIO(PTC6_GPIO_NAME),(1UL<<PTC6_GPIO_BIT)};
const DigitalIO digitalIO_PTC7     = {(volatile GPIO_Type*)GPIO(PTC7_GPIO_NAME),(1UL<<PTC7_GPIO_BIT)};
const DigitalIO digitalIO_PTD0     = {(volatile GPIO_Type*)GPIO(PTD0_GPIO_NAME),(1UL<<PTD0_GPIO_BIT)};
const DigitalIO digitalIO_PTD1     = {(volatile GPIO_Type*)GPIO(PTD1_GPIO_NAME),(1UL<<PTD1_GPIO_BIT)};
const DigitalIO digitalIO_PTD2     = {(volatile GPIO_Type*)GPIO(PTD2_GPIO_NAME),(1UL<<PTD2_GPIO_BIT)};
const DigitalIO digitalIO_PTD3     = {(volatile GPIO_Type*)GPIO(PTD3_GPIO_NAME),(1UL<<PTD3_GPIO_BIT)};
const DigitalIO digitalIO_PTD4     = {(volatile GPIO_Type*)GPIO(PTD4_GPIO_NAME),(1UL<<PTD4_GPIO_BIT)};
const DigitalIO digitalIO_PTD5     = {(volatile GPIO_Type*)GPIO(PTD5_GPIO_NAME),(1UL<<PTD5_GPIO_BIT)};
const DigitalIO digitalIO_PTD6     = {(volatile GPIO_Type*)GPIO(PTD6_GPIO_NAME),(1UL<<PTD6_GPIO_BIT)};
const DigitalIO digitalIO_PTD7     = {(volatile GPIO_Type*)GPIO(PTD7_GPIO_NAME),(1UL<<PTD7_GPIO_BIT)};
const DigitalIO digitalIO_PTE0     = {(volatile GPIO_Type*)GPIO(PTE0_GPIO_NAME),(1UL<<PTE0_GPIO_BIT)};
const DigitalIO digitalIO_PTE1     = {(volatile GPIO_Type*)GPIO(PTE1_GPIO_NAME),(1UL<<PTE1_GPIO_BIT)};
const DigitalIO digitalIO_PTE2     = {(volatile GPIO_Type*)GPIO(PTE2_GPIO_NAME),(1UL<<PTE2_GPIO_BIT)};
const DigitalIO digitalIO_PTE3     = {(volatile GPIO_Type*)GPIO(PTE3_GPIO_NAME),(1UL<<PTE3_GPIO_BIT)};
const DigitalIO digitalIO_PTE4     = {(volatile GPIO_Type*)GPIO(PTE4_GPIO_NAME),(1UL<<PTE4_GPIO_BIT)};
const DigitalIO digitalIO_PTE5     = {(volatile GPIO_Type*)GPIO(PTE5_GPIO_NAME),(1UL<<PTE5_GPIO_BIT)};
const DigitalIO digitalIO_PTE6     = {(volatile GPIO_Type*)GPIO(PTE6_GPIO_NAME),(1UL<<PTE6_GPIO_BIT)};
const DigitalIO digitalIO_PTE7     = {(volatile GPIO_Type*)GPIO(PTE7_GPIO_NAME),(1UL<<PTE7_GPIO_BIT)};
const DigitalIO digitalIO_PTF0     = {(volatile GPIO_Type*)GPIO(PTF0_GPIO_NAME),(1UL<<PTF0_GPIO_BIT)};
const DigitalIO digitalIO_PTF1     = {(volatile GPIO_Type*)GPIO(PTF1_GPIO_NAME),(1UL<<PTF1_GPIO_BIT)};
const DigitalIO digitalIO_PTF2     = {(volatile GPIO_Type*)GPIO(PTF2_GPIO_NAME),(1UL<<PTF2_GPIO_BIT)};
const DigitalIO digitalIO_PTF3     = {(volatile GPIO_Type*)GPIO(PTF3_GPIO_NAME),(1UL<<PTF3_GPIO_BIT)};
const DigitalIO digitalIO_PTF4     = {(volatile GPIO_Type*)GPIO(PTF4_GPIO_NAME),(1UL<<PTF4_GPIO_BIT)};
const DigitalIO digitalIO_PTF5     = {(volatile GPIO_Type*)GPIO(PTF5_GPIO_NAME),(1UL<<PTF5_GPIO_BIT)};
const DigitalIO digitalIO_PTF6     = {(volatile GPIO_Type*)GPIO(PTF6_GPIO_NAME),(1UL<<PTF6_GPIO_BIT)};
const DigitalIO digitalIO_PTF7     = {(volatile GPIO_Type*)GPIO(PTF7_GPIO_NAME),(1UL<<PTF7_GPIO_BIT)};
const DigitalIO digitalIO_PTG0     = {(volatile GPIO_Type*)GPIO(PTG0_GPIO_NAME),(1UL<<PTG0_GPIO_BIT)};
const DigitalIO digitalIO_PTG1     = {(volatile GPIO_Type*)GPIO(PTG1_GPIO_NAME),(1UL<<PTG1_GPIO_BIT)};
const DigitalIO digitalIO_PTG2     = {(volatile GPIO_Type*)GPIO(PTG2_GPIO_NAME),(1UL<<PTG2_GPIO_BIT)};
const DigitalIO digitalIO_PTG3     = {(volatile GPIO_Type*)GPIO(PTG3_GPIO_NAME),(1UL<<PTG3_GPIO_BIT)};
const DigitalIO digitalIO_PTG4     = {(volatile GPIO_Type*)GPIO(PTG4_GPIO_NAME),(1UL<<PTG4_GPIO_BIT)};
const DigitalIO digitalIO_PTG5     = {(volatile GPIO_Type*)GPIO(PTG5_GPIO_NAME),(1UL<<PTG5_GPIO_BIT)};
const DigitalIO digitalIO_PTG6     = {(volatile GPIO_Type*)GPIO(PTG6_GPIO_NAME),(1UL<<PTG6_GPIO_BIT)};
const DigitalIO digitalIO_PTG7     = {(volatile GPIO_Type*)GPIO(PTG7_GPIO_NAME),(1UL<<PTG7_GPIO_BIT)};
const DigitalIO digitalIO_PTH0     = {(volatile GPIO_Type*)GPIO(PTH0_GPIO_NAME),(1UL<<PTH0_GPIO_BIT)};
const DigitalIO digitalIO_PTH1     = {(volatile GPIO_Type*)GPIO(PTH1_GPIO_NAME),(1UL<<PTH1_GPIO_BIT)};
const DigitalIO digitalIO_PTH2     = {(volatile GPIO_Type*)GPIO(PTH2_GPIO_NAME),(1UL<<PTH2_GPIO_BIT)};
const DigitalIO digitalIO_PTH3     = {(volatile GPIO_Type*)GPIO(PTH3_GPIO_NAME),(1UL<<PTH3_GPIO_BIT)};
const DigitalIO digitalIO_PTH4     = {(volatile GPIO_Type*)GPIO(PTH4_GPIO_NAME),(1UL<<PTH4_GPIO_BIT)};
const DigitalIO digitalIO_PTH5     = {(volatile GPIO_Type*)GPIO(PTH5_GPIO_NAME),(1UL<<PTH5_GPIO_BIT)};
const DigitalIO digitalIO_PTH6     = {(volatile GPIO_Type*)GPIO(PTH6_GPIO_NAME),(1UL<<PTH6_GPIO_BIT)};
const DigitalIO digitalIO_PTH7     = {(volatile GPIO_Type*)GPIO(PTH7_GPIO_NAME),(1UL<<PTH7_GPIO_BIT)};
const DigitalIO digitalIO_PTI0     = {(volatile GPIO_Type*)GPIO(PTI0_GPIO_NAME),(1UL<<PTI0_GPIO_BIT)};
const DigitalIO digitalIO_PTI1     = {(volatile GPIO_Type*)GPIO(PTI1_GPIO_NAME),(1UL<<PTI1_GPIO_BIT)};
const DigitalIO digitalIO_PTI2     = {(volatile GPIO_Type*)GPIO(PTI2_GPIO_NAME),(1UL<<PTI2_GPIO_BIT)};
const DigitalIO digitalIO_PTI3     = {(volatile GPIO_Type*)GPIO(PTI3_GPIO_NAME),(1UL<<PTI3_GPIO_BIT)};
const DigitalIO digitalIO_PTI4     = {(volatile GPIO_Type*)GPIO(PTI4_GPIO_NAME),(1UL<<PTI4_GPIO_BIT)};
const DigitalIO digitalIO_PTI5     = {(volatile GPIO_Type*)GPIO(PTI5_GPIO_NAME),(1UL<<PTI5_GPIO_BIT)};
const DigitalIO digitalIO_PTI6     = {(volatile GPIO_Type*)GPIO(PTI6_GPIO_NAME),(1UL<<PTI6_GPIO_BIT)};
const AnalogueIO analogueIO_PTA0              = {&digitalIO_PTA0,  ADC(PTA0_ADC_NUM),  &ADC_CLOCK_REG(PTA0_ADC_NUM),  ADC_CLOCK_MASK(PTA0_ADC_NUM),  PTA0_ADC_CH};
const AnalogueIO analogueIO_PTA1              = {&digitalIO_PTA1,  ADC(PTA1_ADC_NUM),  &ADC_CLOCK_REG(PTA1_ADC_NUM),  ADC_CLOCK_MASK(PTA1_ADC_NUM),  PTA1_ADC_CH};
const AnalogueIO analogueIO_PTA6              = {&digitalIO_PTA6,  ADC(PTA6_ADC_NUM),  &ADC_CLOCK_REG(PTA6_ADC_NUM),  ADC_CLOCK_MASK(PTA6_ADC_NUM),  PTA6_ADC_CH};
const AnalogueIO analogueIO_PTA7              = {&digitalIO_PTA7,  ADC(PTA7_ADC_NUM),  &ADC_CLOCK_REG(PTA7_ADC_NUM),  ADC_CLOCK_MASK(PTA7_ADC_NUM),  PTA7_ADC_CH};
const AnalogueIO analogueIO_PTB0              = {&digitalIO_PTB0,  ADC(PTB0_ADC_NUM),  &ADC_CLOCK_REG(PTB0_ADC_NUM),  ADC_CLOCK_MASK(PTB0_ADC_NUM),  PTB0_ADC_CH};
const AnalogueIO analogueIO_PTB1              = {&digitalIO_PTB1,  ADC(PTB1_ADC_NUM),  &ADC_CLOCK_REG(PTB1_ADC_NUM),  ADC_CLOCK_MASK(PTB1_ADC_NUM),  PTB1_ADC_CH};
const AnalogueIO analogueIO_PTB2              = {&digitalIO_PTB2,  ADC(PTB2_ADC_NUM),  &ADC_CLOCK_REG(PTB2_ADC_NUM),  ADC_CLOCK_MASK(PTB2_ADC_NUM),  PTB2_ADC_CH};
const AnalogueIO analogueIO_PTB3              = {&digitalIO_PTB3,  ADC(PTB3_ADC_NUM),  &ADC_CLOCK_REG(PTB3_ADC_NUM),  ADC_CLOCK_MASK(PTB3_ADC_NUM),  PTB3_ADC_CH};
const AnalogueIO analogueIO_PTC0              = {&digitalIO_PTC0,  ADC(PTC0_ADC_NUM),  &ADC_CLOCK_REG(PTC0_ADC_NUM),  ADC_CLOCK_MASK(PTC0_ADC_NUM),  PTC0_ADC_CH};
const AnalogueIO analogueIO_PTC1              = {&digitalIO_PTC1,  ADC(PTC1_ADC_NUM),  &ADC_CLOCK_REG(PTC1_ADC_NUM),  ADC_CLOCK_MASK(PTC1_ADC_NUM),  PTC1_ADC_CH};
const AnalogueIO analogueIO_PTC2              = {&digitalIO_PTC2,  ADC(PTC2_ADC_NUM),  &ADC_CLOCK_REG(PTC2_ADC_NUM),  ADC_CLOCK_MASK(PTC2_ADC_NUM),  PTC2_ADC_CH};
const AnalogueIO analogueIO_PTC3              = {&digitalIO_PTC3,  ADC(PTC3_ADC_NUM),  &ADC_CLOCK_REG(PTC3_ADC_NUM),  ADC_CLOCK_MASK(PTC3_ADC_NUM),  PTC3_ADC_CH};
const AnalogueIO analogueIO_PTF4              = {&digitalIO_PTF4,  ADC(PTF4_ADC_NUM),  &ADC_CLOCK_REG(PTF4_ADC_NUM),  ADC_CLOCK_MASK(PTF4_ADC_NUM),  PTF4_ADC_CH};
const AnalogueIO analogueIO_PTF5              = {&digitalIO_PTF5,  ADC(PTF5_ADC_NUM),  &ADC_CLOCK_REG(PTF5_ADC_NUM),  ADC_CLOCK_MASK(PTF5_ADC_NUM),  PTF5_ADC_CH};
const AnalogueIO analogueIO_PTF6              = {&digitalIO_PTF6,  ADC(PTF6_ADC_NUM),  &ADC_CLOCK_REG(PTF6_ADC_NUM),  ADC_CLOCK_MASK(PTF6_ADC_NUM),  PTF6_ADC_CH};
const AnalogueIO analogueIO_PTF7              = {&digitalIO_PTF7,  ADC(PTF7_ADC_NUM),  &ADC_CLOCK_REG(PTF7_ADC_NUM),  ADC_CLOCK_MASK(PTF7_ADC_NUM),  PTF7_ADC_CH};
#if FTM0_CH0_SEL == 1
const PwmIO  pwmIO_PTA0      = {&digitalIO_PTA0,   (volatile FTM_Type*)FTM(PTA0_FTM_NUM),  PTA0_FTM_CH,   PORT_PCR_MUX(PTA0_FTM_FN),  &FTM_CLOCK_REG(PTA0_FTM_NUM),  FTM_CLOCK_MASK(PTA0_FTM_NUM), FTM0_SC};
#endif
#if FTM0_CH1_SEL == 1
const PwmIO  pwmIO_PTA1      = {&digitalIO_PTA1,   (volatile FTM_Type*)FTM(PTA1_FTM_NUM),  PTA1_FTM_CH,   PORT_PCR_MUX(PTA1_FTM_FN),  &FTM_CLOCK_REG(PTA1_FTM_NUM),  FTM_CLOCK_MASK(PTA1_FTM_NUM), FTM0_SC};
#endif
#if FTM0_CH0_SEL == 2
const PwmIO  pwmIO_PTB2      = {&digitalIO_PTB2,   (volatile FTM_Type*)FTM(PTB2_FTM_NUM),  PTB2_FTM_CH,   PORT_PCR_MUX(PTB2_FTM_FN),  &FTM_CLOCK_REG(PTB2_FTM_NUM),  FTM_CLOCK_MASK(PTB2_FTM_NUM), FTM0_SC};
#endif
#if FTM0_CH1_SEL == 2
const PwmIO  pwmIO_PTB3      = {&digitalIO_PTB3,   (volatile FTM_Type*)FTM(PTB3_FTM_NUM),  PTB3_FTM_CH,   PORT_PCR_MUX(PTB3_FTM_FN),  &FTM_CLOCK_REG(PTB3_FTM_NUM),  FTM_CLOCK_MASK(PTB3_FTM_NUM), FTM0_SC};
#endif
#if FTM2_CH4_SEL == 1
const PwmIO  pwmIO_PTB4      = {&digitalIO_PTB4,   (volatile FTM_Type*)FTM(PTB4_FTM_NUM),  PTB4_FTM_CH,   PORT_PCR_MUX(PTB4_FTM_FN),  &FTM_CLOCK_REG(PTB4_FTM_NUM),  FTM_CLOCK_MASK(PTB4_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH5_SEL == 1
const PwmIO  pwmIO_PTB5      = {&digitalIO_PTB5,   (volatile FTM_Type*)FTM(PTB5_FTM_NUM),  PTB5_FTM_CH,   PORT_PCR_MUX(PTB5_FTM_FN),  &FTM_CLOCK_REG(PTB5_FTM_NUM),  FTM_CLOCK_MASK(PTB5_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH0_SEL == 1
const PwmIO  pwmIO_PTC0      = {&digitalIO_PTC0,   (volatile FTM_Type*)FTM(PTC0_FTM_NUM),  PTC0_FTM_CH,   PORT_PCR_MUX(PTC0_FTM_FN),  &FTM_CLOCK_REG(PTC0_FTM_NUM),  FTM_CLOCK_MASK(PTC0_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH1_SEL == 1
const PwmIO  pwmIO_PTC1      = {&digitalIO_PTC1,   (volatile FTM_Type*)FTM(PTC1_FTM_NUM),  PTC1_FTM_CH,   PORT_PCR_MUX(PTC1_FTM_FN),  &FTM_CLOCK_REG(PTC1_FTM_NUM),  FTM_CLOCK_MASK(PTC1_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH2_SEL == 1
const PwmIO  pwmIO_PTC2      = {&digitalIO_PTC2,   (volatile FTM_Type*)FTM(PTC2_FTM_NUM),  PTC2_FTM_CH,   PORT_PCR_MUX(PTC2_FTM_FN),  &FTM_CLOCK_REG(PTC2_FTM_NUM),  FTM_CLOCK_MASK(PTC2_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH3_SEL == 1
const PwmIO  pwmIO_PTC3      = {&digitalIO_PTC3,   (volatile FTM_Type*)FTM(PTC3_FTM_NUM),  PTC3_FTM_CH,   PORT_PCR_MUX(PTC3_FTM_FN),  &FTM_CLOCK_REG(PTC3_FTM_NUM),  FTM_CLOCK_MASK(PTC3_FTM_NUM), FTM2_SC};
#endif
#if FTM1_CH0_SEL == 1
const PwmIO  pwmIO_PTC4      = {&digitalIO_PTC4,   (volatile FTM_Type*)FTM(PTC4_FTM_NUM),  PTC4_FTM_CH,   PORT_PCR_MUX(PTC4_FTM_FN),  &FTM_CLOCK_REG(PTC4_FTM_NUM),  FTM_CLOCK_MASK(PTC4_FTM_NUM), FTM1_SC};
#endif
#if FTM1_CH1_SEL == 1
const PwmIO  pwmIO_PTC5      = {&digitalIO_PTC5,   (volatile FTM_Type*)FTM(PTC5_FTM_NUM),  PTC5_FTM_CH,   PORT_PCR_MUX(PTC5_FTM_FN),  &FTM_CLOCK_REG(PTC5_FTM_NUM),  FTM_CLOCK_MASK(PTC5_FTM_NUM), FTM1_SC};
#endif
#if FTM2_CH2_SEL == 2
const PwmIO  pwmIO_PTD0      = {&digitalIO_PTD0,   (volatile FTM_Type*)FTM(PTD0_FTM_NUM),  PTD0_FTM_CH,   PORT_PCR_MUX(PTD0_FTM_FN),  &FTM_CLOCK_REG(PTD0_FTM_NUM),  FTM_CLOCK_MASK(PTD0_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH3_SEL == 2
const PwmIO  pwmIO_PTD1      = {&digitalIO_PTD1,   (volatile FTM_Type*)FTM(PTD1_FTM_NUM),  PTD1_FTM_CH,   PORT_PCR_MUX(PTD1_FTM_FN),  &FTM_CLOCK_REG(PTD1_FTM_NUM),  FTM_CLOCK_MASK(PTD1_FTM_NUM), FTM2_SC};
#endif
#if FTM1_CH1_SEL == 2
const PwmIO  pwmIO_PTE7      = {&digitalIO_PTE7,   (volatile FTM_Type*)FTM(PTE7_FTM_NUM),  PTE7_FTM_CH,   PORT_PCR_MUX(PTE7_FTM_FN),  &FTM_CLOCK_REG(PTE7_FTM_NUM),  FTM_CLOCK_MASK(PTE7_FTM_NUM), FTM1_SC};
#endif
#if FTM2_CH0_SEL == 2
const PwmIO  pwmIO_PTF0      = {&digitalIO_PTF0,   (volatile FTM_Type*)FTM(PTF0_FTM_NUM),  PTF0_FTM_CH,   PORT_PCR_MUX(PTF0_FTM_FN),  &FTM_CLOCK_REG(PTF0_FTM_NUM),  FTM_CLOCK_MASK(PTF0_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH1_SEL == 2
const PwmIO  pwmIO_PTF1      = {&digitalIO_PTF1,   (volatile FTM_Type*)FTM(PTF1_FTM_NUM),  PTF1_FTM_CH,   PORT_PCR_MUX(PTF1_FTM_FN),  &FTM_CLOCK_REG(PTF1_FTM_NUM),  FTM_CLOCK_MASK(PTF1_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH2_SEL == 3
const PwmIO  pwmIO_PTG4      = {&digitalIO_PTG4,   (volatile FTM_Type*)FTM(PTG4_FTM_NUM),  PTG4_FTM_CH,   PORT_PCR_MUX(PTG4_FTM_FN),  &FTM_CLOCK_REG(PTG4_FTM_NUM),  FTM_CLOCK_MASK(PTG4_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH3_SEL == 3
const PwmIO  pwmIO_PTG5      = {&digitalIO_PTG5,   (volatile FTM_Type*)FTM(PTG5_FTM_NUM),  PTG5_FTM_CH,   PORT_PCR_MUX(PTG5_FTM_FN),  &FTM_CLOCK_REG(PTG5_FTM_NUM),  FTM_CLOCK_MASK(PTG5_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH4_SEL == 2
const PwmIO  pwmIO_PTG6      = {&digitalIO_PTG6,   (volatile FTM_Type*)FTM(PTG6_FTM_NUM),  PTG6_FTM_CH,   PORT_PCR_MUX(PTG6_FTM_FN),  &FTM_CLOCK_REG(PTG6_FTM_NUM),  FTM_CLOCK_MASK(PTG6_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH5_SEL == 2
const PwmIO  pwmIO_PTG7      = {&digitalIO_PTG7,   (volatile FTM_Type*)FTM(PTG7_FTM_NUM),  PTG7_FTM_CH,   PORT_PCR_MUX(PTG7_FTM_FN),  &FTM_CLOCK_REG(PTG7_FTM_NUM),  FTM_CLOCK_MASK(PTG7_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH0_SEL == 3
const PwmIO  pwmIO_PTH0      = {&digitalIO_PTH0,   (volatile FTM_Type*)FTM(PTH0_FTM_NUM),  PTH0_FTM_CH,   PORT_PCR_MUX(PTH0_FTM_FN),  &FTM_CLOCK_REG(PTH0_FTM_NUM),  FTM_CLOCK_MASK(PTH0_FTM_NUM), FTM2_SC};
#endif
#if FTM2_CH1_SEL == 3
const PwmIO  pwmIO_PTH1      = {&digitalIO_PTH1,   (volatile FTM_Type*)FTM(PTH1_FTM_NUM),  PTH1_FTM_CH,   PORT_PCR_MUX(PTH1_FTM_FN),  &FTM_CLOCK_REG(PTH1_FTM_NUM),  FTM_CLOCK_MASK(PTH1_FTM_NUM), FTM2_SC};
#endif
#if FTM1_CH0_SEL == 2
const PwmIO  pwmIO_PTH2      = {&digitalIO_PTH2,   (volatile FTM_Type*)FTM(PTH2_FTM_NUM),  PTH2_FTM_CH,   PORT_PCR_MUX(PTH2_FTM_FN),  &FTM_CLOCK_REG(PTH2_FTM_NUM),  FTM_CLOCK_MASK(PTH2_FTM_NUM), FTM1_SC};
#endif
