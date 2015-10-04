 /**
  * @file     gpio.cpp (from gpio-MKE06Z4.cpp)
  *
  * @brief   Pin declarations for MKE06Z4
  */

#include "utilities.h"
#include "gpio.h"
#include "pin_mapping.h"

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
