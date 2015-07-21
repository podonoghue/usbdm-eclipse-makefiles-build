 /**
  * @file     gpio.cpp
  *
  * @brief   Pin declarations for MK20D5
  */

#include "utilities.h"
#include "gpio.h"
#include "pin_mapping.h"

/**
 * @brief Create Timer Clock register name from timer number
 *
 * @param number Timer number e.g. 1 => FTM1_CLOCK_REG
 */
#define FTM_CLOCK_REG(number)  CONCAT3_(FTM,number,_CLOCK_REG)

/**
 * @brief Create Timer Clock register mask from timer number
 *
 * @param number Timer number e.g. 1 => FTM1_CLOCK_MASK
 */
#define FTM_CLOCK_MASK(number)  CONCAT3_(FTM,number,_CLOCK_MASK)

/**
 * @brief Create Timer Clock register name from timer number
 *
 * @param number Timer number e.g. 1 => TPM1_CLOCK_REG
 */
#define TPM_CLOCK_REG(number)  CONCAT3_(TPM,number,_CLOCK_REG)

/**
 * @brief Create Timer Clock register mask from timer number
 *
 * @param number Timer number e.g. 1 => TPM1_CLOCK_MASK
 */
#define TPM_CLOCK_MASK(number)  CONCAT3_(TPM,number,_CLOCK_MASK)

/**
 * @brief Create Timer Clock register name from timer number
 *
 * @param number Timer number e.g. 1 => ADC1_CLOCK_REG
 */
#define ADC_CLOCK_REG(number)  CONCAT3_(ADC,number,_CLOCK_REG)

/**
 * @brief Create Timer Clock register mask from timer number
 *
 * @param number Timer number e.g. 1 => ADC1_CLOCK_MASK
 */
#define ADC_CLOCK_MASK(number)  CONCAT3_(ADC,number,_CLOCK_MASK)

#define ADC(num)             CONCAT2_(ADC,num)   
#define FTM(num)             CONCAT2_(FTM,num)   
#define TPM(num)             CONCAT2_(TPM,num)   

const DigitalIO digitalIO_PTA0     = {&PCR(PTA0_PORT,   PTA0_NUM),  GPIO(PTA0_PORT),  PORT_CLOCK_MASK(PTA0_PORT),  (1UL<<PTA0_NUM)};
const DigitalIO digitalIO_PTA1     = {&PCR(PTA1_PORT,   PTA1_NUM),  GPIO(PTA1_PORT),  PORT_CLOCK_MASK(PTA1_PORT),  (1UL<<PTA1_NUM)};
const DigitalIO digitalIO_PTA2     = {&PCR(PTA2_PORT,   PTA2_NUM),  GPIO(PTA2_PORT),  PORT_CLOCK_MASK(PTA2_PORT),  (1UL<<PTA2_NUM)};
const DigitalIO digitalIO_PTA3     = {&PCR(PTA3_PORT,   PTA3_NUM),  GPIO(PTA3_PORT),  PORT_CLOCK_MASK(PTA3_PORT),  (1UL<<PTA3_NUM)};
const DigitalIO digitalIO_PTA4     = {&PCR(PTA4_PORT,   PTA4_NUM),  GPIO(PTA4_PORT),  PORT_CLOCK_MASK(PTA4_PORT),  (1UL<<PTA4_NUM)};
const DigitalIO digitalIO_PTA5     = {&PCR(PTA5_PORT,   PTA5_NUM),  GPIO(PTA5_PORT),  PORT_CLOCK_MASK(PTA5_PORT),  (1UL<<PTA5_NUM)};
const DigitalIO digitalIO_PTA12    = {&PCR(PTA12_PORT,  PTA12_NUM), GPIO(PTA12_PORT), PORT_CLOCK_MASK(PTA12_PORT), (1UL<<PTA12_NUM)};
const DigitalIO digitalIO_PTA13    = {&PCR(PTA13_PORT,  PTA13_NUM), GPIO(PTA13_PORT), PORT_CLOCK_MASK(PTA13_PORT), (1UL<<PTA13_NUM)};
const DigitalIO digitalIO_PTA18    = {&PCR(PTA18_PORT,  PTA18_NUM), GPIO(PTA18_PORT), PORT_CLOCK_MASK(PTA18_PORT), (1UL<<PTA18_NUM)};
const DigitalIO digitalIO_PTA19    = {&PCR(PTA19_PORT,  PTA19_NUM), GPIO(PTA19_PORT), PORT_CLOCK_MASK(PTA19_PORT), (1UL<<PTA19_NUM)};
const DigitalIO digitalIO_PTB0     = {&PCR(PTB0_PORT,   PTB0_NUM),  GPIO(PTB0_PORT),  PORT_CLOCK_MASK(PTB0_PORT),  (1UL<<PTB0_NUM)};
const DigitalIO digitalIO_PTB1     = {&PCR(PTB1_PORT,   PTB1_NUM),  GPIO(PTB1_PORT),  PORT_CLOCK_MASK(PTB1_PORT),  (1UL<<PTB1_NUM)};
const DigitalIO digitalIO_PTB2     = {&PCR(PTB2_PORT,   PTB2_NUM),  GPIO(PTB2_PORT),  PORT_CLOCK_MASK(PTB2_PORT),  (1UL<<PTB2_NUM)};
const DigitalIO digitalIO_PTB3     = {&PCR(PTB3_PORT,   PTB3_NUM),  GPIO(PTB3_PORT),  PORT_CLOCK_MASK(PTB3_PORT),  (1UL<<PTB3_NUM)};
const DigitalIO digitalIO_PTB16    = {&PCR(PTB16_PORT,  PTB16_NUM), GPIO(PTB16_PORT), PORT_CLOCK_MASK(PTB16_PORT), (1UL<<PTB16_NUM)};
const DigitalIO digitalIO_PTB17    = {&PCR(PTB17_PORT,  PTB17_NUM), GPIO(PTB17_PORT), PORT_CLOCK_MASK(PTB17_PORT), (1UL<<PTB17_NUM)};
const DigitalIO digitalIO_PTB18    = {&PCR(PTB18_PORT,  PTB18_NUM), GPIO(PTB18_PORT), PORT_CLOCK_MASK(PTB18_PORT), (1UL<<PTB18_NUM)};
const DigitalIO digitalIO_PTB19    = {&PCR(PTB19_PORT,  PTB19_NUM), GPIO(PTB19_PORT), PORT_CLOCK_MASK(PTB19_PORT), (1UL<<PTB19_NUM)};
const DigitalIO digitalIO_PTC0     = {&PCR(PTC0_PORT,   PTC0_NUM),  GPIO(PTC0_PORT),  PORT_CLOCK_MASK(PTC0_PORT),  (1UL<<PTC0_NUM)};
const DigitalIO digitalIO_PTC1     = {&PCR(PTC1_PORT,   PTC1_NUM),  GPIO(PTC1_PORT),  PORT_CLOCK_MASK(PTC1_PORT),  (1UL<<PTC1_NUM)};
const DigitalIO digitalIO_PTC2     = {&PCR(PTC2_PORT,   PTC2_NUM),  GPIO(PTC2_PORT),  PORT_CLOCK_MASK(PTC2_PORT),  (1UL<<PTC2_NUM)};
const DigitalIO digitalIO_PTC3     = {&PCR(PTC3_PORT,   PTC3_NUM),  GPIO(PTC3_PORT),  PORT_CLOCK_MASK(PTC3_PORT),  (1UL<<PTC3_NUM)};
const DigitalIO digitalIO_PTC4     = {&PCR(PTC4_PORT,   PTC4_NUM),  GPIO(PTC4_PORT),  PORT_CLOCK_MASK(PTC4_PORT),  (1UL<<PTC4_NUM)};
const DigitalIO digitalIO_PTC5     = {&PCR(PTC5_PORT,   PTC5_NUM),  GPIO(PTC5_PORT),  PORT_CLOCK_MASK(PTC5_PORT),  (1UL<<PTC5_NUM)};
const DigitalIO digitalIO_PTC6     = {&PCR(PTC6_PORT,   PTC6_NUM),  GPIO(PTC6_PORT),  PORT_CLOCK_MASK(PTC6_PORT),  (1UL<<PTC6_NUM)};
const DigitalIO digitalIO_PTC7     = {&PCR(PTC7_PORT,   PTC7_NUM),  GPIO(PTC7_PORT),  PORT_CLOCK_MASK(PTC7_PORT),  (1UL<<PTC7_NUM)};
const DigitalIO digitalIO_PTC8     = {&PCR(PTC8_PORT,   PTC8_NUM),  GPIO(PTC8_PORT),  PORT_CLOCK_MASK(PTC8_PORT),  (1UL<<PTC8_NUM)};
const DigitalIO digitalIO_PTC9     = {&PCR(PTC9_PORT,   PTC9_NUM),  GPIO(PTC9_PORT),  PORT_CLOCK_MASK(PTC9_PORT),  (1UL<<PTC9_NUM)};
const DigitalIO digitalIO_PTC10    = {&PCR(PTC10_PORT,  PTC10_NUM), GPIO(PTC10_PORT), PORT_CLOCK_MASK(PTC10_PORT), (1UL<<PTC10_NUM)};
const DigitalIO digitalIO_PTC11    = {&PCR(PTC11_PORT,  PTC11_NUM), GPIO(PTC11_PORT), PORT_CLOCK_MASK(PTC11_PORT), (1UL<<PTC11_NUM)};
const DigitalIO digitalIO_PTD0     = {&PCR(PTD0_PORT,   PTD0_NUM),  GPIO(PTD0_PORT),  PORT_CLOCK_MASK(PTD0_PORT),  (1UL<<PTD0_NUM)};
const DigitalIO digitalIO_PTD1     = {&PCR(PTD1_PORT,   PTD1_NUM),  GPIO(PTD1_PORT),  PORT_CLOCK_MASK(PTD1_PORT),  (1UL<<PTD1_NUM)};
const DigitalIO digitalIO_PTD2     = {&PCR(PTD2_PORT,   PTD2_NUM),  GPIO(PTD2_PORT),  PORT_CLOCK_MASK(PTD2_PORT),  (1UL<<PTD2_NUM)};
const DigitalIO digitalIO_PTD3     = {&PCR(PTD3_PORT,   PTD3_NUM),  GPIO(PTD3_PORT),  PORT_CLOCK_MASK(PTD3_PORT),  (1UL<<PTD3_NUM)};
const DigitalIO digitalIO_PTD4     = {&PCR(PTD4_PORT,   PTD4_NUM),  GPIO(PTD4_PORT),  PORT_CLOCK_MASK(PTD4_PORT),  (1UL<<PTD4_NUM)};
const DigitalIO digitalIO_PTD5     = {&PCR(PTD5_PORT,   PTD5_NUM),  GPIO(PTD5_PORT),  PORT_CLOCK_MASK(PTD5_PORT),  (1UL<<PTD5_NUM)};
const DigitalIO digitalIO_PTD6     = {&PCR(PTD6_PORT,   PTD6_NUM),  GPIO(PTD6_PORT),  PORT_CLOCK_MASK(PTD6_PORT),  (1UL<<PTD6_NUM)};
const DigitalIO digitalIO_PTD7     = {&PCR(PTD7_PORT,   PTD7_NUM),  GPIO(PTD7_PORT),  PORT_CLOCK_MASK(PTD7_PORT),  (1UL<<PTD7_NUM)};
const DigitalIO digitalIO_PTE0     = {&PCR(PTE0_PORT,   PTE0_NUM),  GPIO(PTE0_PORT),  PORT_CLOCK_MASK(PTE0_PORT),  (1UL<<PTE0_NUM)};
const DigitalIO digitalIO_PTE1     = {&PCR(PTE1_PORT,   PTE1_NUM),  GPIO(PTE1_PORT),  PORT_CLOCK_MASK(PTE1_PORT),  (1UL<<PTE1_NUM)};
const AnalogueIO analogueIO_ADC0_SE23   = {0,                ADC(ADC0_SE23_ADC_NUM),&ADC_CLOCK_REG(ADC0_SE23_ADC_NUM),ADC_CLOCK_MASK(ADC0_SE23_ADC_NUM),ADC0_SE23_ADC_CH};
const AnalogueIO analogueIO_PTB0        = {&digitalIO_PTB0,  ADC(PTB0_ADC_NUM),  &ADC_CLOCK_REG(PTB0_ADC_NUM),  ADC_CLOCK_MASK(PTB0_ADC_NUM),  PTB0_ADC_CH};
const AnalogueIO analogueIO_PTB1        = {&digitalIO_PTB1,  ADC(PTB1_ADC_NUM),  &ADC_CLOCK_REG(PTB1_ADC_NUM),  ADC_CLOCK_MASK(PTB1_ADC_NUM),  PTB1_ADC_CH};
const AnalogueIO analogueIO_PTB2        = {&digitalIO_PTB2,  ADC(PTB2_ADC_NUM),  &ADC_CLOCK_REG(PTB2_ADC_NUM),  ADC_CLOCK_MASK(PTB2_ADC_NUM),  PTB2_ADC_CH};
const AnalogueIO analogueIO_PTB3        = {&digitalIO_PTB3,  ADC(PTB3_ADC_NUM),  &ADC_CLOCK_REG(PTB3_ADC_NUM),  ADC_CLOCK_MASK(PTB3_ADC_NUM),  PTB3_ADC_CH};
const AnalogueIO analogueIO_PTC0        = {&digitalIO_PTC0,  ADC(PTC0_ADC_NUM),  &ADC_CLOCK_REG(PTC0_ADC_NUM),  ADC_CLOCK_MASK(PTC0_ADC_NUM),  PTC0_ADC_CH};
const AnalogueIO analogueIO_PTC1        = {&digitalIO_PTC1,  ADC(PTC1_ADC_NUM),  &ADC_CLOCK_REG(PTC1_ADC_NUM),  ADC_CLOCK_MASK(PTC1_ADC_NUM),  PTC1_ADC_CH};
const AnalogueIO analogueIO_PTC2        = {&digitalIO_PTC2,  ADC(PTC2_ADC_NUM),  &ADC_CLOCK_REG(PTC2_ADC_NUM),  ADC_CLOCK_MASK(PTC2_ADC_NUM),  PTC2_ADC_CH};
const AnalogueIO analogueIO_PTD1        = {&digitalIO_PTD1,  ADC(PTD1_ADC_NUM),  &ADC_CLOCK_REG(PTD1_ADC_NUM),  ADC_CLOCK_MASK(PTD1_ADC_NUM),  PTD1_ADC_CH};
const AnalogueIO analogueIO_PTD5        = {&digitalIO_PTD5,  ADC(PTD5_ADC_NUM),  &ADC_CLOCK_REG(PTD5_ADC_NUM),  ADC_CLOCK_MASK(PTD5_ADC_NUM),  PTD5_ADC_CH};
const AnalogueIO analogueIO_PTD6        = {&digitalIO_PTD6,  ADC(PTD6_ADC_NUM),  &ADC_CLOCK_REG(PTD6_ADC_NUM),  ADC_CLOCK_MASK(PTD6_ADC_NUM),  PTD6_ADC_CH};
#if FTM0_5_SEL == 1
const PwmIO  pwmIO_PTA0      = {&digitalIO_PTA0,   (volatile FTM_Type*)FTM(PTA0_FTM_NUM),  PTA0_FTM_CH,   PORT_PCR_MUX(PTA0_FTM_FN),  &FTM_CLOCK_REG(PTA0_FTM_NUM),  FTM_CLOCK_MASK(PTA0_FTM_NUM)};
#endif
#if FTM0_6_SEL == 1
const PwmIO  pwmIO_PTA1      = {&digitalIO_PTA1,   (volatile FTM_Type*)FTM(PTA1_FTM_NUM),  PTA1_FTM_CH,   PORT_PCR_MUX(PTA1_FTM_FN),  &FTM_CLOCK_REG(PTA1_FTM_NUM),  FTM_CLOCK_MASK(PTA1_FTM_NUM)};
#endif
#if FTM0_7_SEL == 1
const PwmIO  pwmIO_PTA2      = {&digitalIO_PTA2,   (volatile FTM_Type*)FTM(PTA2_FTM_NUM),  PTA2_FTM_CH,   PORT_PCR_MUX(PTA2_FTM_FN),  &FTM_CLOCK_REG(PTA2_FTM_NUM),  FTM_CLOCK_MASK(PTA2_FTM_NUM)};
#endif
#if FTM0_0_SEL == 1
const PwmIO  pwmIO_PTA3      = {&digitalIO_PTA3,   (volatile FTM_Type*)FTM(PTA3_FTM_NUM),  PTA3_FTM_CH,   PORT_PCR_MUX(PTA3_FTM_FN),  &FTM_CLOCK_REG(PTA3_FTM_NUM),  FTM_CLOCK_MASK(PTA3_FTM_NUM)};
#endif
#if FTM0_1_SEL == 1
const PwmIO  pwmIO_PTA4      = {&digitalIO_PTA4,   (volatile FTM_Type*)FTM(PTA4_FTM_NUM),  PTA4_FTM_CH,   PORT_PCR_MUX(PTA4_FTM_FN),  &FTM_CLOCK_REG(PTA4_FTM_NUM),  FTM_CLOCK_MASK(PTA4_FTM_NUM)};
#endif
#if FTM0_2_SEL == 1
const PwmIO  pwmIO_PTA5      = {&digitalIO_PTA5,   (volatile FTM_Type*)FTM(PTA5_FTM_NUM),  PTA5_FTM_CH,   PORT_PCR_MUX(PTA5_FTM_FN),  &FTM_CLOCK_REG(PTA5_FTM_NUM),  FTM_CLOCK_MASK(PTA5_FTM_NUM)};
#endif
#if FTM1_0_SEL == 1
const PwmIO  pwmIO_PTA12     = {&digitalIO_PTA12,  (volatile FTM_Type*)FTM(PTA12_FTM_NUM), PTA12_FTM_CH,  PORT_PCR_MUX(PTA12_FTM_FN), &FTM_CLOCK_REG(PTA12_FTM_NUM), FTM_CLOCK_MASK(PTA12_FTM_NUM)};
#endif
#if FTM1_1_SEL == 1
const PwmIO  pwmIO_PTA13     = {&digitalIO_PTA13,  (volatile FTM_Type*)FTM(PTA13_FTM_NUM), PTA13_FTM_CH,  PORT_PCR_MUX(PTA13_FTM_FN), &FTM_CLOCK_REG(PTA13_FTM_NUM), FTM_CLOCK_MASK(PTA13_FTM_NUM)};
#endif
#if FTM1_0_SEL == 2
const PwmIO  pwmIO_PTB0      = {&digitalIO_PTB0,   (volatile FTM_Type*)FTM(PTB0_FTM_NUM),  PTB0_FTM_CH,   PORT_PCR_MUX(PTB0_FTM_FN),  &FTM_CLOCK_REG(PTB0_FTM_NUM),  FTM_CLOCK_MASK(PTB0_FTM_NUM)};
#endif
#if FTM1_1_SEL == 2
const PwmIO  pwmIO_PTB1      = {&digitalIO_PTB1,   (volatile FTM_Type*)FTM(PTB1_FTM_NUM),  PTB1_FTM_CH,   PORT_PCR_MUX(PTB1_FTM_FN),  &FTM_CLOCK_REG(PTB1_FTM_NUM),  FTM_CLOCK_MASK(PTB1_FTM_NUM)};
#endif
#if FTM0_0_SEL == 2
const PwmIO  pwmIO_PTC1      = {&digitalIO_PTC1,   (volatile FTM_Type*)FTM(PTC1_FTM_NUM),  PTC1_FTM_CH,   PORT_PCR_MUX(PTC1_FTM_FN),  &FTM_CLOCK_REG(PTC1_FTM_NUM),  FTM_CLOCK_MASK(PTC1_FTM_NUM)};
#endif
#if FTM0_1_SEL == 2
const PwmIO  pwmIO_PTC2      = {&digitalIO_PTC2,   (volatile FTM_Type*)FTM(PTC2_FTM_NUM),  PTC2_FTM_CH,   PORT_PCR_MUX(PTC2_FTM_FN),  &FTM_CLOCK_REG(PTC2_FTM_NUM),  FTM_CLOCK_MASK(PTC2_FTM_NUM)};
#endif
#if FTM0_2_SEL == 2
const PwmIO  pwmIO_PTC3      = {&digitalIO_PTC3,   (volatile FTM_Type*)FTM(PTC3_FTM_NUM),  PTC3_FTM_CH,   PORT_PCR_MUX(PTC3_FTM_FN),  &FTM_CLOCK_REG(PTC3_FTM_NUM),  FTM_CLOCK_MASK(PTC3_FTM_NUM)};
#endif
const PwmIO  pwmIO_PTC4      = {&digitalIO_PTC4,   (volatile FTM_Type*)FTM(PTC4_FTM_NUM),  PTC4_FTM_CH,   PORT_PCR_MUX(PTC4_FTM_FN),  &FTM_CLOCK_REG(PTC4_FTM_NUM),  FTM_CLOCK_MASK(PTC4_FTM_NUM)};
const PwmIO  pwmIO_PTD4      = {&digitalIO_PTD4,   (volatile FTM_Type*)FTM(PTD4_FTM_NUM),  PTD4_FTM_CH,   PORT_PCR_MUX(PTD4_FTM_FN),  &FTM_CLOCK_REG(PTD4_FTM_NUM),  FTM_CLOCK_MASK(PTD4_FTM_NUM)};
#if FTM0_5_SEL == 2
const PwmIO  pwmIO_PTD5      = {&digitalIO_PTD5,   (volatile FTM_Type*)FTM(PTD5_FTM_NUM),  PTD5_FTM_CH,   PORT_PCR_MUX(PTD5_FTM_FN),  &FTM_CLOCK_REG(PTD5_FTM_NUM),  FTM_CLOCK_MASK(PTD5_FTM_NUM)};
#endif
#if FTM0_6_SEL == 2
const PwmIO  pwmIO_PTD6      = {&digitalIO_PTD6,   (volatile FTM_Type*)FTM(PTD6_FTM_NUM),  PTD6_FTM_CH,   PORT_PCR_MUX(PTD6_FTM_FN),  &FTM_CLOCK_REG(PTD6_FTM_NUM),  FTM_CLOCK_MASK(PTD6_FTM_NUM)};
#endif
#if FTM0_7_SEL == 2
const PwmIO  pwmIO_PTD7      = {&digitalIO_PTD7,   (volatile FTM_Type*)FTM(PTD7_FTM_NUM),  PTD7_FTM_CH,   PORT_PCR_MUX(PTD7_FTM_FN),  &FTM_CLOCK_REG(PTD7_FTM_NUM),  FTM_CLOCK_MASK(PTD7_FTM_NUM)};
#endif
