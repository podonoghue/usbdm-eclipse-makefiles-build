/**
 * @file      PinMapping.h
 * @version   1.0.0
 * @brief     Pin declarations for MKL25Z4
 */

#ifndef PINMAPPING_H_
#define PINMAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

// <h> TPM Clock settings

// TPM_SC.CMOD ================================
//
//   <o> TPM_SC.CMOD Clock source 
//   <i> Selects the clock source for the TPM module. [TPM_SC.CMOD]
//     <0=> Disabled
//     <1=> Internal clock
//     <2=> External clock
//     <3=> Reserved
//     <1=> Default
// TPM_SC.PS ================================
//
//   <o1> TPM_SC.PS Clock prescaler 
//   <i> Selects the prescaler for the TPM module. [TPM_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
#define TPM_SC               (TPM_SC_CMOD(0x1)|TPM_SC_PS(0x0))

// </h>

#define TPM0_CLOCK_REG       SIM->SCGC6          
#define TPM0_CLOCK_MASK      SIM_SCGC6_TPM0_MASK 
#define TPM1_CLOCK_REG       SIM->SCGC6          
#define TPM1_CLOCK_MASK      SIM_SCGC6_TPM1_MASK 
#define TPM2_CLOCK_REG       SIM->SCGC6          
#define TPM2_CLOCK_MASK      SIM_SCGC6_TPM2_MASK 
#define ADC0_CLOCK_REG       SIM->SCGC6          
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC0_MASK 
#define I2C0_CLOCK_REG       SIM->SCGC4          
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK 
#define I2C1_CLOCK_REG       SIM->SCGC4          
#define I2C1_CLOCK_MASK      SIM_SCGC4_I2C1_MASK 
#define SPI0_CLOCK_REG       SIM->SCGC4          
#define SPI0_CLOCK_MASK      SIM_SCGC4_SPI0_MASK 
#define SPI1_CLOCK_REG       SIM->SCGC4          
#define SPI1_CLOCK_MASK      SIM_SCGC4_SPI1_MASK 

// <h> Pin Peripheral mapping

// ADC0_0 maps to [Disabled, PTE20]
//   <o> ADC0_0 Pin Selection [PTE20(A11)] <constant>
//   <i> Selects which pin is used for ADC0_0
//     <0=> Disabled
//     <1=> PTE20 (Alias: A11)
//     <1=> Default
#define ADC0_0_SEL           1                   

// ADC0_11 maps to [Disabled, PTC2]
//   <o> ADC0_11 Pin Selection [PTC2(A4)] <constant>
//   <i> Selects which pin is used for ADC0_11
//     <0=> Disabled
//     <1=> PTC2 (Alias: A4)
//     <1=> Default
#define ADC0_11_SEL          1                   

// ADC0_12 maps to [Disabled, PTB2]
//   <o> ADC0_12 Pin Selection [PTB2(A2)] <constant>
//   <i> Selects which pin is used for ADC0_12
//     <0=> Disabled
//     <1=> PTB2 (Alias: A2)
//     <1=> Default
#define ADC0_12_SEL          1                   

// ADC0_13 maps to [Disabled, PTB3]
//   <o> ADC0_13 Pin Selection [PTB3(A3)] <constant>
//   <i> Selects which pin is used for ADC0_13
//     <0=> Disabled
//     <1=> PTB3 (Alias: A3)
//     <1=> Default
#define ADC0_13_SEL          1                   

// ADC0_14 maps to [Disabled, PTC0]
//   <o> ADC0_14 Pin Selection [PTC0(D17)] <constant>
//   <i> Selects which pin is used for ADC0_14
//     <0=> Disabled
//     <1=> PTC0 (Alias: D17)
//     <1=> Default
#define ADC0_14_SEL          1                   

// ADC0_15 maps to [Disabled, PTC1]
//   <o> ADC0_15 Pin Selection [PTC1(A5)] <constant>
//   <i> Selects which pin is used for ADC0_15
//     <0=> Disabled
//     <1=> PTC1 (Alias: A5)
//     <1=> Default
#define ADC0_15_SEL          1                   

// ADC0_23 maps to [Disabled, PTE30]
//   <o> ADC0_23 Pin Selection [PTE30(A6)] <constant>
//   <i> Selects which pin is used for ADC0_23
//     <0=> Disabled
//     <1=> PTE30 (Alias: A6)
//     <1=> Default
#define ADC0_23_SEL          1                   

// ADC0_3 maps to [Disabled, PTE22]
//   <o> ADC0_3 Pin Selection [PTE22(A9)] <constant>
//   <i> Selects which pin is used for ADC0_3
//     <0=> Disabled
//     <1=> PTE22 (Alias: A9)
//     <1=> Default
#define ADC0_3_SEL           1                   

// ADC0_4 maps to [Disabled, PTE29]
//   <o> ADC0_4 Pin Selection [PTE29(A7)] <constant>
//   <i> Selects which pin is used for ADC0_4
//     <0=> Disabled
//     <1=> PTE29 (Alias: A7)
//     <1=> Default
#define ADC0_4_SEL           1                   

// ADC0_5 maps to [Disabled, PTD1]
//   <o> ADC0_5 Pin Selection [PTD1(D13)] <constant>
//   <i> Selects which pin is used for ADC0_5
//     <0=> Disabled
//     <1=> PTD1 (Alias: D13)
//     <1=> Default
#define ADC0_5_SEL           1                   

// ADC0_6 maps to [Disabled, PTD5]
//   <o> ADC0_6 Pin Selection [PTD5(D9)] <constant>
//   <i> Selects which pin is used for ADC0_6
//     <0=> Disabled
//     <1=> PTD5 (Alias: D9)
//     <1=> Default
#define ADC0_6_SEL           1                   

// ADC0_7 maps to [Disabled, PTD6]
//   <o> ADC0_7 Pin Selection [PTD6(D32)] <constant>
//   <i> Selects which pin is used for ADC0_7
//     <0=> Disabled
//     <1=> PTD6 (Alias: D32)
//     <1=> Default
#define ADC0_7_SEL           1                   

// ADC0_8 maps to [Disabled, PTB0]
//   <o> ADC0_8 Pin Selection [PTB0(A0)] <constant>
//   <i> Selects which pin is used for ADC0_8
//     <0=> Disabled
//     <1=> PTB0 (Alias: A0)
//     <1=> Default
#define ADC0_8_SEL           1                   

// ADC0_9 maps to [Disabled, PTB1]
//   <o> ADC0_9 Pin Selection [PTB1(A1)] <constant>
//   <i> Selects which pin is used for ADC0_9
//     <0=> Disabled
//     <1=> PTB1 (Alias: A1)
//     <1=> Default
#define ADC0_9_SEL           1                   

// I2C0_SCL maps to [Disabled, PTB0, PTB2, PTC8, PTE24]
//   <o> I2C0_SCL Pin Selection [PTB0(A0), PTB2(A2), PTC8(D6), PTE24] 
//   <i> Selects which pin is used for I2C0_SCL
//     <0=> Disabled
//     <1=> PTB0 (Alias: A0)
//     <2=> PTB2 (Alias: A2)
//     <3=> PTC8 (Alias: D6)
//     <4=> PTE24
//     <4=> Default
#define I2C0_SCL_SEL         4                   

// I2C0_SDA maps to [Disabled, PTB1, PTB3, PTC9, PTE25]
//   <o> I2C0_SDA Pin Selection [PTB1(A1), PTB3(A3), PTC9(D7), PTE25] 
//   <i> Selects which pin is used for I2C0_SDA
//     <0=> Disabled
//     <1=> PTB1 (Alias: A1)
//     <2=> PTB3 (Alias: A3)
//     <3=> PTC9 (Alias: D7)
//     <4=> PTE25
//     <4=> Default
#define I2C0_SDA_SEL         4                   

// I2C1_SCL maps to [Disabled, PTA3, PTC1, PTC10, PTE1]
//   <o> I2C1_SCL Pin Selection [PTA3, PTC1(A5), PTC10(D22), PTE1(D14)] 
//   <i> Selects which pin is used for I2C1_SCL
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTC1 (Alias: A5)
//     <3=> PTC10 (Alias: D22)
//     <4=> PTE1 (Alias: D14)
//     <4=> Default
#define I2C1_SCL_SEL         4                   

// I2C1_SDA maps to [Disabled, PTA4, PTC2, PTC11, PTE0]
//   <o> I2C1_SDA Pin Selection [PTA4(D4), PTC2(A4), PTC11(D23), PTE0(D15)] 
//   <i> Selects which pin is used for I2C1_SDA
//     <0=> Disabled
//     <1=> PTA4 (Alias: D4)
//     <2=> PTC2 (Alias: A4)
//     <3=> PTC11 (Alias: D23)
//     <4=> PTE0 (Alias: D15)
//     <4=> Default
#define I2C1_SDA_SEL         4                   

// SPI0_MISO maps to [Disabled, PTA16, PTA17, PTC6, PTC7, PTD2, PTD3]
//   <o> SPI0_MISO Pin Selection [PTA16(D28), PTA17(D29), PTC6(D21), PTC7(D16), PTD2(D11), PTD3(D12)] 
//   <i> Selects which pin is used for SPI0_MISO
//     <0=> Disabled
//     <1=> PTA16 (Alias: D28)
//     <2=> PTA17 (Alias: D29)
//     <3=> PTC6 (Alias: D21)
//     <4=> PTC7 (Alias: D16)
//     <5=> PTD2 (Alias: D11)
//     <6=> PTD3 (Alias: D12)
//     <6=> Default
#define SPI0_MISO_SEL        6                   

// SPI0_MOSI maps to [Disabled, PTA16, PTA17, PTC6, PTC7, PTD2, PTD3]
//   <o> SPI0_MOSI Pin Selection [PTA16(D28), PTA17(D29), PTC6(D21), PTC7(D16), PTD2(D11), PTD3(D12)] 
//   <i> Selects which pin is used for SPI0_MOSI
//     <0=> Disabled
//     <1=> PTA16 (Alias: D28)
//     <2=> PTA17 (Alias: D29)
//     <3=> PTC6 (Alias: D21)
//     <4=> PTC7 (Alias: D16)
//     <5=> PTD2 (Alias: D11)
//     <6=> PTD3 (Alias: D12)
//     <5=> Default
#define SPI0_MOSI_SEL        5                   

// SPI0_PCS0 maps to [Disabled, PTA14, PTC4, PTD0]
//   <o> SPI0_PCS0 Pin Selection [PTA14, PTC4(D19), PTD0(D10)] 
//   <i> Selects which pin is used for SPI0_PCS0
//     <0=> Disabled
//     <1=> PTA14
//     <2=> PTC4 (Alias: D19)
//     <3=> PTD0 (Alias: D10)
//     <0=> Default
#define SPI0_PCS0_SEL        0                   

// SPI0_SCK maps to [Disabled, PTA15, PTC5, PTD1]
//   <o> SPI0_SCK Pin Selection [PTA15, PTC5(D20), PTD1(D13)] 
//   <i> Selects which pin is used for SPI0_SCK
//     <0=> Disabled
//     <1=> PTA15
//     <2=> PTC5 (Alias: D20)
//     <3=> PTD1 (Alias: D13)
//     <3=> Default
#define SPI0_SCK_SEL         3                   

// SPI1_MISO maps to [Disabled, PTB16, PTB17, PTD6, PTD7, PTE1, PTE3]
//   <o> SPI1_MISO Pin Selection [PTB16, PTB17, PTD6(D32), PTD7(D33), PTE1(D14), PTE3(A15)] 
//   <i> Selects which pin is used for SPI1_MISO
//     <0=> Disabled
//     <1=> PTB16
//     <2=> PTB17
//     <3=> PTD6 (Alias: D32)
//     <4=> PTD7 (Alias: D33)
//     <5=> PTE1 (Alias: D14)
//     <6=> PTE3 (Alias: A15)
//     <1=> Default
#define SPI1_MISO_SEL        1                   

// SPI1_MOSI maps to [Disabled, PTB16, PTB17, PTD6, PTD7, PTE1, PTE3]
//   <o> SPI1_MOSI Pin Selection [PTB16, PTB17, PTD6(D32), PTD7(D33), PTE1(D14), PTE3(A15)] 
//   <i> Selects which pin is used for SPI1_MOSI
//     <0=> Disabled
//     <1=> PTB16
//     <2=> PTB17
//     <3=> PTD6 (Alias: D32)
//     <4=> PTD7 (Alias: D33)
//     <5=> PTE1 (Alias: D14)
//     <6=> PTE3 (Alias: A15)
//     <2=> Default
#define SPI1_MOSI_SEL        2                   

// SPI1_PCS0 maps to [Disabled, PTB10, PTD4, PTE4]
//   <o> SPI1_PCS0 Pin Selection [PTB10(A18), PTD4(D2), PTE4(A14)] 
//   <i> Selects which pin is used for SPI1_PCS0
//     <0=> Disabled
//     <1=> PTB10 (Alias: A18)
//     <2=> PTD4 (Alias: D2)
//     <3=> PTE4 (Alias: A14)
//     <0=> Default
#define SPI1_PCS0_SEL        0                   

// SPI1_SCK maps to [Disabled, PTB11, PTD5, PTE2]
//   <o> SPI1_SCK Pin Selection [PTB11(A17), PTD5(D9), PTE2(A16)] 
//   <i> Selects which pin is used for SPI1_SCK
//     <0=> Disabled
//     <1=> PTB11 (Alias: A17)
//     <2=> PTD5 (Alias: D9)
//     <3=> PTE2 (Alias: A16)
//     <1=> Default
#define SPI1_SCK_SEL         1                   

// TPM0_0 maps to [Disabled, PTA3, PTC1, PTD0, PTE24]
//   <o> TPM0_0 Pin Selection [PTA3, PTC1(A5), PTD0(D10), PTE24] 
//   <i> Selects which pin is used for TPM0_0
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTC1 (Alias: A5)
//     <3=> PTD0 (Alias: D10)
//     <4=> PTE24
//     <3=> Default
#define TPM0_0_SEL           3                   

// TPM0_1 maps to [Disabled, PTA4, PTC2, PTD1, PTE25]
//   <o> TPM0_1 Pin Selection [PTA4(D4), PTC2(A4), PTD1(D13), PTE25] 
//   <i> Selects which pin is used for TPM0_1
//     <0=> Disabled
//     <1=> PTA4 (Alias: D4)
//     <2=> PTC2 (Alias: A4)
//     <3=> PTD1 (Alias: D13)
//     <4=> PTE25
//     <3=> Default
#define TPM0_1_SEL           3                   

// TPM0_2 maps to [Disabled, PTA5, PTC3, PTD2, PTE29]
//   <o> TPM0_2 Pin Selection [PTA5(D5), PTC3(D18), PTD2(D11), PTE29(A7)] 
//   <i> Selects which pin is used for TPM0_2
//     <0=> Disabled
//     <1=> PTA5 (Alias: D5)
//     <2=> PTC3 (Alias: D18)
//     <3=> PTD2 (Alias: D11)
//     <4=> PTE29 (Alias: A7)
//     <1=> Default
#define TPM0_2_SEL           1                   

// TPM0_3 maps to [Disabled, PTC4, PTD3, PTE30]
//   <o> TPM0_3 Pin Selection [PTC4(D19), PTD3(D12), PTE30(A6)] 
//   <i> Selects which pin is used for TPM0_3
//     <0=> Disabled
//     <1=> PTC4 (Alias: D19)
//     <2=> PTD3 (Alias: D12)
//     <3=> PTE30 (Alias: A6)
//     <1=> Default
#define TPM0_3_SEL           1                   

// TPM0_4 maps to [Disabled, PTC8, PTD4, PTE31]
//   <o> TPM0_4 Pin Selection [PTC8(D6), PTD4(D2), PTE31(D30)] 
//   <i> Selects which pin is used for TPM0_4
//     <0=> Disabled
//     <1=> PTC8 (Alias: D6)
//     <2=> PTD4 (Alias: D2)
//     <3=> PTE31 (Alias: D30)
//     <1=> Default
#define TPM0_4_SEL           1                   

// TPM0_5 maps to [Disabled, PTA0, PTC9, PTD5]
//   <o> TPM0_5 Pin Selection [PTA0, PTC9(D7), PTD5(D9)] 
//   <i> Selects which pin is used for TPM0_5
//     <0=> Disabled
//     <1=> PTA0
//     <2=> PTC9 (Alias: D7)
//     <3=> PTD5 (Alias: D9)
//     <2=> Default
#define TPM0_5_SEL           2                   

// TPM1_0 maps to [Disabled, PTA12, PTB0, PTE20]
//   <o> TPM1_0 Pin Selection [PTA12(D3), PTB0(A0), PTE20(A11)] 
//   <i> Selects which pin is used for TPM1_0
//     <0=> Disabled
//     <1=> PTA12 (Alias: D3)
//     <2=> PTB0 (Alias: A0)
//     <3=> PTE20 (Alias: A11)
//     <1=> Default
#define TPM1_0_SEL           1                   

// TPM1_1 maps to [Disabled, PTA13, PTB1, PTE21]
//   <o> TPM1_1 Pin Selection [PTA13(D8), PTB1(A1), PTE21(A10)] 
//   <i> Selects which pin is used for TPM1_1
//     <0=> Disabled
//     <1=> PTA13 (Alias: D8)
//     <2=> PTB1 (Alias: A1)
//     <3=> PTE21 (Alias: A10)
//     <1=> Default
#define TPM1_1_SEL           1                   

// TPM2_0 maps to [Disabled, PTA1, PTB2, PTB18, PTE22]
//   <o> TPM2_0 Pin Selection [PTA1(D0), PTB2(A2), PTB18, PTE22(A9)] 
//   <i> Selects which pin is used for TPM2_0
//     <0=> Disabled
//     <1=> PTA1 (Alias: D0)
//     <2=> PTB2 (Alias: A2)
//     <3=> PTB18
//     <4=> PTE22 (Alias: A9)
//     <1=> Default
#define TPM2_0_SEL           1                   

// TPM2_1 maps to [Disabled, PTA2, PTB3, PTB19, PTE23]
//   <o> TPM2_1 Pin Selection [PTA2(D1), PTB3(A3), PTB19, PTE23(A8)] 
//   <i> Selects which pin is used for TPM2_1
//     <0=> Disabled
//     <1=> PTA2 (Alias: D1)
//     <2=> PTB3 (Alias: A3)
//     <3=> PTB19
//     <4=> PTE23 (Alias: A8)
//     <1=> Default
#define TPM2_1_SEL           1                   

// PTA0 = TPM0_5
#define PTA0_PORT                  A     //!< PTA0 Port name
#define PTA0_NUM                   0     //!< PTA0 Port number
#if TPM0_5_SEL == 1
#define PTA0_TPM_NUM               0     //!< PTA0 TPM number
#define PTA0_TPM_CH                5     //!< PTA0 TPM channel
#define PTA0_TPM_FN                3     //!< PTA0 Pin multiplexor for TPM
#endif

// PTA1 = TPM2_0 (Alias: D0)
#define PTA1_PORT                  A     //!< PTA1 Port name
#define PTA1_NUM                   1     //!< PTA1 Port number
#if TPM2_0_SEL == 1
#define PTA1_TPM_NUM               2     //!< PTA1 TPM number
#define PTA1_TPM_CH                0     //!< PTA1 TPM channel
#define PTA1_TPM_FN                3     //!< PTA1 Pin multiplexor for TPM
#endif

// PTA2 = TPM2_1 (Alias: D1)
#define PTA2_PORT                  A     //!< PTA2 Port name
#define PTA2_NUM                   2     //!< PTA2 Port number
#if TPM2_1_SEL == 1
#define PTA2_TPM_NUM               2     //!< PTA2 TPM number
#define PTA2_TPM_CH                1     //!< PTA2 TPM channel
#define PTA2_TPM_FN                3     //!< PTA2 Pin multiplexor for TPM
#endif

// PTA3 = TPM0_0,I2C1_SCL
#define PTA3_PORT                  A     //!< PTA3 Port name
#define PTA3_NUM                   3     //!< PTA3 Port number
#if TPM0_0_SEL == 1
#define PTA3_TPM_NUM               0     //!< PTA3 TPM number
#define PTA3_TPM_CH                0     //!< PTA3 TPM channel
#define PTA3_TPM_FN                3     //!< PTA3 Pin multiplexor for TPM
#endif
#if I2C1_SCL_SEL == 1
#define I2C1_SCL_FN                2     //!< Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTA3  //!< PTA3 = I2C
#endif

// PTA4 = TPM0_1,I2C1_SDA (Alias: D4)
#define PTA4_PORT                  A     //!< PTA4 Port name
#define PTA4_NUM                   4     //!< PTA4 Port number
#if TPM0_1_SEL == 1
#define PTA4_TPM_NUM               0     //!< PTA4 TPM number
#define PTA4_TPM_CH                1     //!< PTA4 TPM channel
#define PTA4_TPM_FN                3     //!< PTA4 Pin multiplexor for TPM
#endif
#if I2C1_SDA_SEL == 1
#define I2C1_SDA_FN                2     //!< Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTA4  //!< PTA4 = I2C
#endif

// PTA5 = TPM0_2 (Alias: D5)
#define PTA5_PORT                  A     //!< PTA5 Port name
#define PTA5_NUM                   5     //!< PTA5 Port number
#if TPM0_2_SEL == 1
#define PTA5_TPM_NUM               0     //!< PTA5 TPM number
#define PTA5_TPM_CH                2     //!< PTA5 TPM channel
#define PTA5_TPM_FN                3     //!< PTA5 Pin multiplexor for TPM
#endif

// PTA12 = TPM1_0 (Alias: D3)
#define PTA12_PORT                 A     //!< PTA12 Port name
#define PTA12_NUM                  12    //!< PTA12 Port number
#if TPM1_0_SEL == 1
#define PTA12_TPM_NUM              1     //!< PTA12 TPM number
#define PTA12_TPM_CH               0     //!< PTA12 TPM channel
#define PTA12_TPM_FN               3     //!< PTA12 Pin multiplexor for TPM
#endif

// PTA13 = TPM1_1 (Alias: D8)
#define PTA13_PORT                 A     //!< PTA13 Port name
#define PTA13_NUM                  13    //!< PTA13 Port number
#if TPM1_1_SEL == 1
#define PTA13_TPM_NUM              1     //!< PTA13 TPM number
#define PTA13_TPM_CH               1     //!< PTA13 TPM channel
#define PTA13_TPM_FN               3     //!< PTA13 Pin multiplexor for TPM
#endif

// PTA14 = SPI0_PCS0
#define PTA14_PORT                 A     //!< PTA14 Port name
#define PTA14_NUM                  14    //!< PTA14 Port number
#if SPI0_PCS0_SEL == 1
#define SPI0_PCS0_FN               2     //!< PTA14 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTA14  //!< PTA14 = SPI
#endif

// PTA15 = SPI0_SCK
#define PTA15_PORT                 A     //!< PTA15 Port name
#define PTA15_NUM                  15    //!< PTA15 Port number
#if SPI0_SCK_SEL == 1
#define SPI0_SCK_FN                2     //!< PTA15 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTA15  //!< PTA15 = SPI
#endif

// PTA16 = SPI0_MOSI,SPI0_MISO (Alias: D28)
#define PTA16_PORT                 A     //!< PTA16 Port name
#define PTA16_NUM                  16    //!< PTA16 Port number
#if SPI0_MOSI_SEL == 1
#define SPI0_MOSI_FN               2     //!< PTA16 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTA16  //!< PTA16 = SPI
#endif
#if SPI0_MISO_SEL == 1
#define SPI0_MISO_FN               5     //!< PTA16 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTA16  //!< PTA16 = SPI
#endif

// PTA17 = SPI0_MISO,SPI0_MOSI (Alias: D29)
#define PTA17_PORT                 A     //!< PTA17 Port name
#define PTA17_NUM                  17    //!< PTA17 Port number
#if SPI0_MISO_SEL == 2
#define SPI0_MISO_FN               2     //!< PTA17 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTA17  //!< PTA17 = SPI
#endif
#if SPI0_MOSI_SEL == 2
#define SPI0_MOSI_FN               5     //!< PTA17 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTA17  //!< PTA17 = SPI
#endif

// PTA18
#define PTA18_PORT                 A     //!< PTA18 Port name
#define PTA18_NUM                  18    //!< PTA18 Port number

// PTA19
#define PTA19_PORT                 A     //!< PTA19 Port name
#define PTA19_NUM                  19    //!< PTA19 Port number

// PTA20
#define PTA20_PORT                 A     //!< PTA20 Port name
#define PTA20_NUM                  20    //!< PTA20 Port number

// PTB0 = ADC0_8,TPM1_0,I2C0_SCL (Alias: A0)
#define PTB0_PORT                  B     //!< PTB0 Port name
#define PTB0_NUM                   0     //!< PTB0 Port number
#define PTB0_ADC_NUM               0     //!< PTB0 ADC number
#define PTB0_ADC_CH                8     //!< PTB0 ADC channel
#if TPM1_0_SEL == 2
#define PTB0_TPM_NUM               1     //!< PTB0 TPM number
#define PTB0_TPM_CH                0     //!< PTB0 TPM channel
#define PTB0_TPM_FN                3     //!< PTB0 Pin multiplexor for TPM
#endif
#if I2C0_SCL_SEL == 1
#define I2C0_SCL_FN                2     //!< Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB0  //!< PTB0 = I2C
#endif

// PTB1 = ADC0_9,TPM1_1,I2C0_SDA (Alias: A1)
#define PTB1_PORT                  B     //!< PTB1 Port name
#define PTB1_NUM                   1     //!< PTB1 Port number
#define PTB1_ADC_NUM               0     //!< PTB1 ADC number
#define PTB1_ADC_CH                9     //!< PTB1 ADC channel
#if TPM1_1_SEL == 2
#define PTB1_TPM_NUM               1     //!< PTB1 TPM number
#define PTB1_TPM_CH                1     //!< PTB1 TPM channel
#define PTB1_TPM_FN                3     //!< PTB1 Pin multiplexor for TPM
#endif
#if I2C0_SDA_SEL == 1
#define I2C0_SDA_FN                2     //!< Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB1  //!< PTB1 = I2C
#endif

// PTB2 = ADC0_12,TPM2_0,I2C0_SCL (Alias: A2)
#define PTB2_PORT                  B     //!< PTB2 Port name
#define PTB2_NUM                   2     //!< PTB2 Port number
#define PTB2_ADC_NUM               0     //!< PTB2 ADC number
#define PTB2_ADC_CH                12    //!< PTB2 ADC channel
#if TPM2_0_SEL == 2
#define PTB2_TPM_NUM               2     //!< PTB2 TPM number
#define PTB2_TPM_CH                0     //!< PTB2 TPM channel
#define PTB2_TPM_FN                3     //!< PTB2 Pin multiplexor for TPM
#endif
#if I2C0_SCL_SEL == 2
#define I2C0_SCL_FN                2     //!< Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB2  //!< PTB2 = I2C
#endif

// PTB3 = ADC0_13,TPM2_1,I2C0_SDA (Alias: A3)
#define PTB3_PORT                  B     //!< PTB3 Port name
#define PTB3_NUM                   3     //!< PTB3 Port number
#define PTB3_ADC_NUM               0     //!< PTB3 ADC number
#define PTB3_ADC_CH                13    //!< PTB3 ADC channel
#if TPM2_1_SEL == 2
#define PTB3_TPM_NUM               2     //!< PTB3 TPM number
#define PTB3_TPM_CH                1     //!< PTB3 TPM channel
#define PTB3_TPM_FN                3     //!< PTB3 Pin multiplexor for TPM
#endif
#if I2C0_SDA_SEL == 2
#define I2C0_SDA_FN                2     //!< Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB3  //!< PTB3 = I2C
#endif

// PTB8 (Alias: A20)
#define PTB8_PORT                  B     //!< PTB8 Port name
#define PTB8_NUM                   8     //!< PTB8 Port number

// PTB9 (Alias: A19)
#define PTB9_PORT                  B     //!< PTB9 Port name
#define PTB9_NUM                   9     //!< PTB9 Port number

// PTB10 = SPI1_PCS0 (Alias: A18)
#define PTB10_PORT                 B     //!< PTB10 Port name
#define PTB10_NUM                  10    //!< PTB10 Port number
#if SPI1_PCS0_SEL == 1
#define SPI1_PCS0_FN               2     //!< PTB10 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTB10  //!< PTB10 = SPI
#endif

// PTB11 = SPI1_SCK (Alias: A17)
#define PTB11_PORT                 B     //!< PTB11 Port name
#define PTB11_NUM                  11    //!< PTB11 Port number
#if SPI1_SCK_SEL == 1
#define SPI1_SCK_FN                2     //!< PTB11 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTB11  //!< PTB11 = SPI
#endif

// PTB16 = SPI1_MOSI,SPI1_MISO
#define PTB16_PORT                 B     //!< PTB16 Port name
#define PTB16_NUM                  16    //!< PTB16 Port number
#if SPI1_MOSI_SEL == 1
#define SPI1_MOSI_FN               2     //!< PTB16 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTB16  //!< PTB16 = SPI
#endif
#if SPI1_MISO_SEL == 1
#define SPI1_MISO_FN               5     //!< PTB16 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTB16  //!< PTB16 = SPI
#endif

// PTB17 = SPI1_MISO,SPI1_MOSI
#define PTB17_PORT                 B     //!< PTB17 Port name
#define PTB17_NUM                  17    //!< PTB17 Port number
#if SPI1_MISO_SEL == 2
#define SPI1_MISO_FN               2     //!< PTB17 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTB17  //!< PTB17 = SPI
#endif
#if SPI1_MOSI_SEL == 2
#define SPI1_MOSI_FN               5     //!< PTB17 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTB17  //!< PTB17 = SPI
#endif

// PTB18 = TPM2_0
#define PTB18_PORT                 B     //!< PTB18 Port name
#define PTB18_NUM                  18    //!< PTB18 Port number
#if TPM2_0_SEL == 3
#define PTB18_TPM_NUM              2     //!< PTB18 TPM number
#define PTB18_TPM_CH               0     //!< PTB18 TPM channel
#define PTB18_TPM_FN               3     //!< PTB18 Pin multiplexor for TPM
#endif

// PTB19 = TPM2_1
#define PTB19_PORT                 B     //!< PTB19 Port name
#define PTB19_NUM                  19    //!< PTB19 Port number
#if TPM2_1_SEL == 3
#define PTB19_TPM_NUM              2     //!< PTB19 TPM number
#define PTB19_TPM_CH               1     //!< PTB19 TPM channel
#define PTB19_TPM_FN               3     //!< PTB19 Pin multiplexor for TPM
#endif

// PTC0 = ADC0_14 (Alias: D17)
#define PTC0_PORT                  C     //!< PTC0 Port name
#define PTC0_NUM                   0     //!< PTC0 Port number
#define PTC0_ADC_NUM               0     //!< PTC0 ADC number
#define PTC0_ADC_CH                14    //!< PTC0 ADC channel

// PTC1 = ADC0_15,TPM0_0,I2C1_SCL (Alias: A5)
#define PTC1_PORT                  C     //!< PTC1 Port name
#define PTC1_NUM                   1     //!< PTC1 Port number
#define PTC1_ADC_NUM               0     //!< PTC1 ADC number
#define PTC1_ADC_CH                15    //!< PTC1 ADC channel
#if TPM0_0_SEL == 2
#define PTC1_TPM_NUM               0     //!< PTC1 TPM number
#define PTC1_TPM_CH                0     //!< PTC1 TPM channel
#define PTC1_TPM_FN                4     //!< PTC1 Pin multiplexor for TPM
#endif
#if I2C1_SCL_SEL == 2
#define I2C1_SCL_FN                2     //!< Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTC1  //!< PTC1 = I2C
#endif

// PTC2 = ADC0_11,TPM0_1,I2C1_SDA (Alias: A4)
#define PTC2_PORT                  C     //!< PTC2 Port name
#define PTC2_NUM                   2     //!< PTC2 Port number
#define PTC2_ADC_NUM               0     //!< PTC2 ADC number
#define PTC2_ADC_CH                11    //!< PTC2 ADC channel
#if TPM0_1_SEL == 2
#define PTC2_TPM_NUM               0     //!< PTC2 TPM number
#define PTC2_TPM_CH                1     //!< PTC2 TPM channel
#define PTC2_TPM_FN                4     //!< PTC2 Pin multiplexor for TPM
#endif
#if I2C1_SDA_SEL == 2
#define I2C1_SDA_FN                2     //!< Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTC2  //!< PTC2 = I2C
#endif

// PTC3 = TPM0_2 (Alias: D18)
#define PTC3_PORT                  C     //!< PTC3 Port name
#define PTC3_NUM                   3     //!< PTC3 Port number
#if TPM0_2_SEL == 2
#define PTC3_TPM_NUM               0     //!< PTC3 TPM number
#define PTC3_TPM_CH                2     //!< PTC3 TPM channel
#define PTC3_TPM_FN                4     //!< PTC3 Pin multiplexor for TPM
#endif

// PTC4 = TPM0_3,SPI0_PCS0 (Alias: D19)
#define PTC4_PORT                  C     //!< PTC4 Port name
#define PTC4_NUM                   4     //!< PTC4 Port number
#if TPM0_3_SEL == 1
#define PTC4_TPM_NUM               0     //!< PTC4 TPM number
#define PTC4_TPM_CH                3     //!< PTC4 TPM channel
#define PTC4_TPM_FN                4     //!< PTC4 Pin multiplexor for TPM
#endif
#if SPI0_PCS0_SEL == 2
#define SPI0_PCS0_FN               2     //!< PTC4 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTC4  //!< PTC4 = SPI
#endif

// PTC5 = SPI0_SCK (Alias: D20)
#define PTC5_PORT                  C     //!< PTC5 Port name
#define PTC5_NUM                   5     //!< PTC5 Port number
#if SPI0_SCK_SEL == 2
#define SPI0_SCK_FN                2     //!< PTC5 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTC5  //!< PTC5 = SPI
#endif

// PTC6 = SPI0_MOSI,SPI0_MISO (Alias: D21)
#define PTC6_PORT                  C     //!< PTC6 Port name
#define PTC6_NUM                   6     //!< PTC6 Port number
#if SPI0_MOSI_SEL == 3
#define SPI0_MOSI_FN               2     //!< PTC6 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTC6  //!< PTC6 = SPI
#endif
#if SPI0_MISO_SEL == 3
#define SPI0_MISO_FN               5     //!< PTC6 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTC6  //!< PTC6 = SPI
#endif

// PTC7 = SPI0_MISO,SPI0_MOSI (Alias: D16)
#define PTC7_PORT                  C     //!< PTC7 Port name
#define PTC7_NUM                   7     //!< PTC7 Port number
#if SPI0_MISO_SEL == 4
#define SPI0_MISO_FN               2     //!< PTC7 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTC7  //!< PTC7 = SPI
#endif
#if SPI0_MOSI_SEL == 4
#define SPI0_MOSI_FN               5     //!< PTC7 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTC7  //!< PTC7 = SPI
#endif

// PTC8 = TPM0_4,I2C0_SCL (Alias: D6)
#define PTC8_PORT                  C     //!< PTC8 Port name
#define PTC8_NUM                   8     //!< PTC8 Port number
#if TPM0_4_SEL == 1
#define PTC8_TPM_NUM               0     //!< PTC8 TPM number
#define PTC8_TPM_CH                4     //!< PTC8 TPM channel
#define PTC8_TPM_FN                3     //!< PTC8 Pin multiplexor for TPM
#endif
#if I2C0_SCL_SEL == 3
#define I2C0_SCL_FN                2     //!< Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTC8  //!< PTC8 = I2C
#endif

// PTC9 = TPM0_5,I2C0_SDA (Alias: D7)
#define PTC9_PORT                  C     //!< PTC9 Port name
#define PTC9_NUM                   9     //!< PTC9 Port number
#if TPM0_5_SEL == 2
#define PTC9_TPM_NUM               0     //!< PTC9 TPM number
#define PTC9_TPM_CH                5     //!< PTC9 TPM channel
#define PTC9_TPM_FN                3     //!< PTC9 Pin multiplexor for TPM
#endif
#if I2C0_SDA_SEL == 3
#define I2C0_SDA_FN                2     //!< Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTC9  //!< PTC9 = I2C
#endif

// PTC10 = I2C1_SCL (Alias: D22)
#define PTC10_PORT                 C     //!< PTC10 Port name
#define PTC10_NUM                  10    //!< PTC10 Port number
#if I2C1_SCL_SEL == 3
#define I2C1_SCL_FN                2     //!< Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTC10  //!< PTC10 = I2C
#endif

// PTC11 = I2C1_SDA (Alias: D23)
#define PTC11_PORT                 C     //!< PTC11 Port name
#define PTC11_NUM                  11    //!< PTC11 Port number
#if I2C1_SDA_SEL == 3
#define I2C1_SDA_FN                2     //!< Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTC11  //!< PTC11 = I2C
#endif

// PTC12 (Alias: D24)
#define PTC12_PORT                 C     //!< PTC12 Port name
#define PTC12_NUM                  12    //!< PTC12 Port number

// PTC13 (Alias: D25)
#define PTC13_PORT                 C     //!< PTC13 Port name
#define PTC13_NUM                  13    //!< PTC13 Port number

// PTC16 (Alias: D26)
#define PTC16_PORT                 C     //!< PTC16 Port name
#define PTC16_NUM                  16    //!< PTC16 Port number

// PTC17 (Alias: D27)
#define PTC17_PORT                 C     //!< PTC17 Port name
#define PTC17_NUM                  17    //!< PTC17 Port number

// PTD0 = TPM0_0,SPI0_PCS0 (Alias: D10)
#define PTD0_PORT                  D     //!< PTD0 Port name
#define PTD0_NUM                   0     //!< PTD0 Port number
#if TPM0_0_SEL == 3
#define PTD0_TPM_NUM               0     //!< PTD0 TPM number
#define PTD0_TPM_CH                0     //!< PTD0 TPM channel
#define PTD0_TPM_FN                4     //!< PTD0 Pin multiplexor for TPM
#endif
#if SPI0_PCS0_SEL == 3
#define SPI0_PCS0_FN               2     //!< PTD0 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTD0  //!< PTD0 = SPI
#endif

// PTD1 = ADC0_5,TPM0_1,SPI0_SCK (Alias: D13)
#define PTD1_PORT                  D     //!< PTD1 Port name
#define PTD1_NUM                   1     //!< PTD1 Port number
#define PTD1_ADC_NUM               0     //!< PTD1 ADC number
#define PTD1_ADC_CH                5     //!< PTD1 ADC channel
#if TPM0_1_SEL == 3
#define PTD1_TPM_NUM               0     //!< PTD1 TPM number
#define PTD1_TPM_CH                1     //!< PTD1 TPM channel
#define PTD1_TPM_FN                4     //!< PTD1 Pin multiplexor for TPM
#endif
#if SPI0_SCK_SEL == 3
#define SPI0_SCK_FN                2     //!< PTD1 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTD1  //!< PTD1 = SPI
#endif

// PTD2 = TPM0_2,SPI0_MOSI,SPI0_MISO (Alias: D11)
#define PTD2_PORT                  D     //!< PTD2 Port name
#define PTD2_NUM                   2     //!< PTD2 Port number
#if TPM0_2_SEL == 3
#define PTD2_TPM_NUM               0     //!< PTD2 TPM number
#define PTD2_TPM_CH                2     //!< PTD2 TPM channel
#define PTD2_TPM_FN                4     //!< PTD2 Pin multiplexor for TPM
#endif
#if SPI0_MOSI_SEL == 5
#define SPI0_MOSI_FN               2     //!< PTD2 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTD2  //!< PTD2 = SPI
#endif
#if SPI0_MISO_SEL == 5
#define SPI0_MISO_FN               5     //!< PTD2 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTD2  //!< PTD2 = SPI
#endif

// PTD3 = TPM0_3,SPI0_MISO,SPI0_MOSI (Alias: D12)
#define PTD3_PORT                  D     //!< PTD3 Port name
#define PTD3_NUM                   3     //!< PTD3 Port number
#if TPM0_3_SEL == 2
#define PTD3_TPM_NUM               0     //!< PTD3 TPM number
#define PTD3_TPM_CH                3     //!< PTD3 TPM channel
#define PTD3_TPM_FN                4     //!< PTD3 Pin multiplexor for TPM
#endif
#if SPI0_MISO_SEL == 6
#define SPI0_MISO_FN               2     //!< PTD3 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTD3  //!< PTD3 = SPI
#endif
#if SPI0_MOSI_SEL == 6
#define SPI0_MOSI_FN               5     //!< PTD3 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTD3  //!< PTD3 = SPI
#endif

// PTD4 = TPM0_4,SPI1_PCS0 (Alias: D2)
#define PTD4_PORT                  D     //!< PTD4 Port name
#define PTD4_NUM                   4     //!< PTD4 Port number
#if TPM0_4_SEL == 2
#define PTD4_TPM_NUM               0     //!< PTD4 TPM number
#define PTD4_TPM_CH                4     //!< PTD4 TPM channel
#define PTD4_TPM_FN                4     //!< PTD4 Pin multiplexor for TPM
#endif
#if SPI1_PCS0_SEL == 2
#define SPI1_PCS0_FN               2     //!< PTD4 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTD4  //!< PTD4 = SPI
#endif

// PTD5 = ADC0_6,TPM0_5,SPI1_SCK (Alias: D9)
#define PTD5_PORT                  D     //!< PTD5 Port name
#define PTD5_NUM                   5     //!< PTD5 Port number
#define PTD5_ADC_NUM               0     //!< PTD5 ADC number
#define PTD5_ADC_CH                6     //!< PTD5 ADC channel
#if TPM0_5_SEL == 3
#define PTD5_TPM_NUM               0     //!< PTD5 TPM number
#define PTD5_TPM_CH                5     //!< PTD5 TPM channel
#define PTD5_TPM_FN                4     //!< PTD5 Pin multiplexor for TPM
#endif
#if SPI1_SCK_SEL == 2
#define SPI1_SCK_FN                2     //!< PTD5 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTD5  //!< PTD5 = SPI
#endif

// PTD6 = ADC0_7,SPI1_MOSI,SPI1_MISO (Alias: D32)
#define PTD6_PORT                  D     //!< PTD6 Port name
#define PTD6_NUM                   6     //!< PTD6 Port number
#define PTD6_ADC_NUM               0     //!< PTD6 ADC number
#define PTD6_ADC_CH                7     //!< PTD6 ADC channel
#if SPI1_MOSI_SEL == 3
#define SPI1_MOSI_FN               2     //!< PTD6 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTD6  //!< PTD6 = SPI
#endif
#if SPI1_MISO_SEL == 3
#define SPI1_MISO_FN               5     //!< PTD6 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTD6  //!< PTD6 = SPI
#endif

// PTD7 = SPI1_MISO,SPI1_MOSI (Alias: D33)
#define PTD7_PORT                  D     //!< PTD7 Port name
#define PTD7_NUM                   7     //!< PTD7 Port number
#if SPI1_MISO_SEL == 4
#define SPI1_MISO_FN               2     //!< PTD7 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTD7  //!< PTD7 = SPI
#endif
#if SPI1_MOSI_SEL == 4
#define SPI1_MOSI_FN               5     //!< PTD7 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTD7  //!< PTD7 = SPI
#endif

// PTE0 = I2C1_SDA (Alias: D15)
#define PTE0_PORT                  E     //!< PTE0 Port name
#define PTE0_NUM                   0     //!< PTE0 Port number
#if I2C1_SDA_SEL == 4
#define I2C1_SDA_FN                6     //!< Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTE0  //!< PTE0 = I2C
#endif

// PTE1 = SPI1_MOSI,SPI1_MISO,I2C1_SCL (Alias: D14)
#define PTE1_PORT                  E     //!< PTE1 Port name
#define PTE1_NUM                   1     //!< PTE1 Port number
#if SPI1_MOSI_SEL == 5
#define SPI1_MOSI_FN               2     //!< PTE1 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTE1  //!< PTE1 = SPI
#endif
#if SPI1_MISO_SEL == 5
#define SPI1_MISO_FN               5     //!< PTE1 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTE1  //!< PTE1 = SPI
#endif
#if I2C1_SCL_SEL == 4
#define I2C1_SCL_FN                6     //!< Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTE1  //!< PTE1 = I2C
#endif

// PTE2 = SPI1_SCK (Alias: A16)
#define PTE2_PORT                  E     //!< PTE2 Port name
#define PTE2_NUM                   2     //!< PTE2 Port number
#if SPI1_SCK_SEL == 3
#define SPI1_SCK_FN                2     //!< PTE2 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTE2  //!< PTE2 = SPI
#endif

// PTE3 = SPI1_MISO,SPI1_MOSI (Alias: A15)
#define PTE3_PORT                  E     //!< PTE3 Port name
#define PTE3_NUM                   3     //!< PTE3 Port number
#if SPI1_MISO_SEL == 6
#define SPI1_MISO_FN               2     //!< PTE3 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTE3  //!< PTE3 = SPI
#endif
#if SPI1_MOSI_SEL == 6
#define SPI1_MOSI_FN               5     //!< PTE3 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTE3  //!< PTE3 = SPI
#endif

// PTE4 = SPI1_PCS0 (Alias: A14)
#define PTE4_PORT                  E     //!< PTE4 Port name
#define PTE4_NUM                   4     //!< PTE4 Port number
#if SPI1_PCS0_SEL == 3
#define SPI1_PCS0_FN               2     //!< PTE4 Pin multiplexor for SPI
#define SPI1_PCS0_GPIO             digitalIO_PTE4  //!< PTE4 = SPI
#endif

// PTE5 (Alias: A13)
#define PTE5_PORT                  E     //!< PTE5 Port name
#define PTE5_NUM                   5     //!< PTE5 Port number

// PTE20 = ADC0_0,TPM1_0 (Alias: A11)
#define PTE20_PORT                 E     //!< PTE20 Port name
#define PTE20_NUM                  20    //!< PTE20 Port number
#define PTE20_ADC_NUM              0     //!< PTE20 ADC number
#define PTE20_ADC_CH               0     //!< PTE20 ADC channel
#if TPM1_0_SEL == 3
#define PTE20_TPM_NUM              1     //!< PTE20 TPM number
#define PTE20_TPM_CH               0     //!< PTE20 TPM channel
#define PTE20_TPM_FN               3     //!< PTE20 Pin multiplexor for TPM
#endif

// PTE21 = TPM1_1 (Alias: A10)
#define PTE21_PORT                 E     //!< PTE21 Port name
#define PTE21_NUM                  21    //!< PTE21 Port number
#if TPM1_1_SEL == 3
#define PTE21_TPM_NUM              1     //!< PTE21 TPM number
#define PTE21_TPM_CH               1     //!< PTE21 TPM channel
#define PTE21_TPM_FN               3     //!< PTE21 Pin multiplexor for TPM
#endif

// PTE22 = ADC0_3,TPM2_0 (Alias: A9)
#define PTE22_PORT                 E     //!< PTE22 Port name
#define PTE22_NUM                  22    //!< PTE22 Port number
#define PTE22_ADC_NUM              0     //!< PTE22 ADC number
#define PTE22_ADC_CH               3     //!< PTE22 ADC channel
#if TPM2_0_SEL == 4
#define PTE22_TPM_NUM              2     //!< PTE22 TPM number
#define PTE22_TPM_CH               0     //!< PTE22 TPM channel
#define PTE22_TPM_FN               3     //!< PTE22 Pin multiplexor for TPM
#endif

// PTE23 = TPM2_1 (Alias: A8)
#define PTE23_PORT                 E     //!< PTE23 Port name
#define PTE23_NUM                  23    //!< PTE23 Port number
#if TPM2_1_SEL == 4
#define PTE23_TPM_NUM              2     //!< PTE23 TPM number
#define PTE23_TPM_CH               1     //!< PTE23 TPM channel
#define PTE23_TPM_FN               3     //!< PTE23 Pin multiplexor for TPM
#endif

// PTE24 = TPM0_0,I2C0_SCL
#define PTE24_PORT                 E     //!< PTE24 Port name
#define PTE24_NUM                  24    //!< PTE24 Port number
#if TPM0_0_SEL == 4
#define PTE24_TPM_NUM              0     //!< PTE24 TPM number
#define PTE24_TPM_CH               0     //!< PTE24 TPM channel
#define PTE24_TPM_FN               3     //!< PTE24 Pin multiplexor for TPM
#endif
#if I2C0_SCL_SEL == 4
#define I2C0_SCL_FN                5     //!< Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTE24  //!< PTE24 = I2C
#endif

// PTE25 = TPM0_1,I2C0_SDA
#define PTE25_PORT                 E     //!< PTE25 Port name
#define PTE25_NUM                  25    //!< PTE25 Port number
#if TPM0_1_SEL == 4
#define PTE25_TPM_NUM              0     //!< PTE25 TPM number
#define PTE25_TPM_CH               1     //!< PTE25 TPM channel
#define PTE25_TPM_FN               3     //!< PTE25 Pin multiplexor for TPM
#endif
#if I2C0_SDA_SEL == 4
#define I2C0_SDA_FN                5     //!< Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTE25  //!< PTE25 = I2C
#endif

// PTE29 = ADC0_4,TPM0_2 (Alias: A7)
#define PTE29_PORT                 E     //!< PTE29 Port name
#define PTE29_NUM                  29    //!< PTE29 Port number
#define PTE29_ADC_NUM              0     //!< PTE29 ADC number
#define PTE29_ADC_CH               4     //!< PTE29 ADC channel
#if TPM0_2_SEL == 4
#define PTE29_TPM_NUM              0     //!< PTE29 TPM number
#define PTE29_TPM_CH               2     //!< PTE29 TPM channel
#define PTE29_TPM_FN               3     //!< PTE29 Pin multiplexor for TPM
#endif

// PTE30 = ADC0_23,TPM0_3 (Alias: A6)
#define PTE30_PORT                 E     //!< PTE30 Port name
#define PTE30_NUM                  30    //!< PTE30 Port number
#define PTE30_ADC_NUM              0     //!< PTE30 ADC number
#define PTE30_ADC_CH               23    //!< PTE30 ADC channel
#if TPM0_3_SEL == 3
#define PTE30_TPM_NUM              0     //!< PTE30 TPM number
#define PTE30_TPM_CH               3     //!< PTE30 TPM channel
#define PTE30_TPM_FN               3     //!< PTE30 Pin multiplexor for TPM
#endif

// PTE31 = TPM0_4 (Alias: D30)
#define PTE31_PORT                 E     //!< PTE31 Port name
#define PTE31_NUM                  31    //!< PTE31 Port number
#if TPM0_4_SEL == 3
#define PTE31_TPM_NUM              0     //!< PTE31 TPM number
#define PTE31_TPM_CH               4     //!< PTE31 TPM channel
#define PTE31_TPM_FN               3     //!< PTE31 Pin multiplexor for TPM
#endif

// </h>


#endif /* PINMAPPING_H_ */
