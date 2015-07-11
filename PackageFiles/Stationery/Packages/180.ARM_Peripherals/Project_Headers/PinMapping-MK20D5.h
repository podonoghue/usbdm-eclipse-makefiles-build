/**
 * @file      PinMapping.h
 * @version   1.0.0
 * @brief     Pin declarations for MK20D5
 */

#ifndef PINMAPPING_H_
#define PINMAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

// <h> FTM Clock settings

// FTM_SC.CLKS ================================
//
//   <o> FTM_SC.CLKS Clock source 
//   <i> Selects the clock source for the FTM module. [FTM_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM_SC.PS ================================
//
//   <o1> FTM_SC.PS Clock prescaler 
//   <i> Selects the prescaler for the FTM module. [FTM_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
#define FTM_SC               (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0))

// </h>

#define ADC0_CLOCK_REG       SIM->SCGC6          
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC0_MASK 
#define I2C0_CLOCK_REG       SIM->SCGC4          
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK 
#define SPI0_CLOCK_REG       SIM->SCGC6          
#define SPI0_CLOCK_MASK      SIM_SCGC6_SPI0_MASK 
#define FTM0_CLOCK_REG       SIM->SCGC6          
#define FTM0_CLOCK_MASK      SIM_SCGC6_FTM0_MASK 
#define FTM1_CLOCK_REG       SIM->SCGC6          
#define FTM1_CLOCK_MASK      SIM_SCGC6_FTM1_MASK 

// <h> Pin Peripheral mapping

// ADC0_12 maps to [Disabled, PTB2]
//   <o> ADC0_12 Pin Selection [PTB2(D15)] <constant>
//   <i> Selects which pin is used for ADC0_12
//     <0=> Disabled
//     <1=> PTB2 (Alias: D15)
//     <1=> Default
#define ADC0_12_SEL          1                   

// ADC0_13 maps to [Disabled, PTB3]
//   <o> ADC0_13 Pin Selection [PTB3(D14)] <constant>
//   <i> Selects which pin is used for ADC0_13
//     <0=> Disabled
//     <1=> PTB3 (Alias: D14)
//     <1=> Default
#define ADC0_13_SEL          1                   

// ADC0_14 maps to [Disabled, PTC0]
//   <o> ADC0_14 Pin Selection [PTC0(A0)] <constant>
//   <i> Selects which pin is used for ADC0_14
//     <0=> Disabled
//     <1=> PTC0 (Alias: A0)
//     <1=> Default
#define ADC0_14_SEL          1                   

// ADC0_15 maps to [Disabled, PTC1]
//   <o> ADC0_15 Pin Selection [PTC1(A1)] <constant>
//   <i> Selects which pin is used for ADC0_15
//     <0=> Disabled
//     <1=> PTC1 (Alias: A1)
//     <1=> Default
#define ADC0_15_SEL          1                   

// ADC0_23 maps to [Disabled, ADC0_SE23]
//   <o> ADC0_23 Pin Selection [ADC0_SE23] <constant>
//   <i> Selects which pin is used for ADC0_23
//     <0=> Disabled
//     <1=> ADC0_SE23
//     <1=> Default
#define ADC0_23_SEL          1                   

// ADC0_4 maps to [Disabled, PTC2]
//   <o> ADC0_4 Pin Selection [PTC2(D10)] <constant>
//   <i> Selects which pin is used for ADC0_4
//     <0=> Disabled
//     <1=> PTC2 (Alias: D10)
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
//   <o> ADC0_6 Pin Selection [PTD5(A3)] <constant>
//   <i> Selects which pin is used for ADC0_6
//     <0=> Disabled
//     <1=> PTD5 (Alias: A3)
//     <1=> Default
#define ADC0_6_SEL           1                   

// ADC0_7 maps to [Disabled, PTD6]
//   <o> ADC0_7 Pin Selection [PTD6(A2)] <constant>
//   <i> Selects which pin is used for ADC0_7
//     <0=> Disabled
//     <1=> PTD6 (Alias: A2)
//     <1=> Default
#define ADC0_7_SEL           1                   

// ADC0_8 maps to [Disabled, PTB0]
//   <o> ADC0_8 Pin Selection [PTB0(A5)] <constant>
//   <i> Selects which pin is used for ADC0_8
//     <0=> Disabled
//     <1=> PTB0 (Alias: A5)
//     <1=> Default
#define ADC0_8_SEL           1                   

// ADC0_9 maps to [Disabled, PTB1]
//   <o> ADC0_9 Pin Selection [PTB1(A4)] <constant>
//   <i> Selects which pin is used for ADC0_9
//     <0=> Disabled
//     <1=> PTB1 (Alias: A4)
//     <1=> Default
#define ADC0_9_SEL           1                   

// FTM0_0 maps to [Disabled, PTA3, PTC1]
//   <o> FTM0_0 Pin Selection [PTA3, PTC1(A1)] 
//   <i> Selects which pin is used for FTM0_0
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTC1 (Alias: A1)
//     <2=> Default
#define FTM0_0_SEL           2                   

// FTM0_1 maps to [Disabled, PTA4, PTC2]
//   <o> FTM0_1 Pin Selection [PTA4(D21), PTC2(D10)] 
//   <i> Selects which pin is used for FTM0_1
//     <0=> Disabled
//     <1=> PTA4 (Alias: D21)
//     <2=> PTC2 (Alias: D10)
//     <2=> Default
#define FTM0_1_SEL           2                   

// FTM0_2 maps to [Disabled, PTA5, PTC3]
//   <o> FTM0_2 Pin Selection [PTA5(D2), PTC3(D6)] 
//   <i> Selects which pin is used for FTM0_2
//     <0=> Disabled
//     <1=> PTA5 (Alias: D2)
//     <2=> PTC3 (Alias: D6)
//     <2=> Default
#define FTM0_2_SEL           2                   

// FTM0_3 maps to [Disabled, PTC4]
//   <o> FTM0_3 Pin Selection [PTC4(D7)] <constant>
//   <i> Selects which pin is used for FTM0_3
//     <0=> Disabled
//     <1=> PTC4 (Alias: D7)
//     <1=> Default
#define FTM0_3_SEL           1                   

// FTM0_4 maps to [Disabled, PTD4]
//   <o> FTM0_4 Pin Selection [PTD4(D3)] <constant>
//   <i> Selects which pin is used for FTM0_4
//     <0=> Disabled
//     <1=> PTD4 (Alias: D3)
//     <1=> Default
#define FTM0_4_SEL           1                   

// FTM0_5 maps to [Disabled, PTA0, PTD5]
//   <o> FTM0_5 Pin Selection [PTA0, PTD5(A3)] 
//   <i> Selects which pin is used for FTM0_5
//     <0=> Disabled
//     <1=> PTA0
//     <2=> PTD5 (Alias: A3)
//     <2=> Default
#define FTM0_5_SEL           2                   

// FTM0_6 maps to [Disabled, PTA1, PTD6]
//   <o> FTM0_6 Pin Selection [PTA1(D5), PTD6(A2)] 
//   <i> Selects which pin is used for FTM0_6
//     <0=> Disabled
//     <1=> PTA1 (Alias: D5)
//     <2=> PTD6 (Alias: A2)
//     <1=> Default
#define FTM0_6_SEL           1                   

// FTM0_7 maps to [Disabled, PTA2, PTD7]
//   <o> FTM0_7 Pin Selection [PTA2(D9), PTD7(D22)] 
//   <i> Selects which pin is used for FTM0_7
//     <0=> Disabled
//     <1=> PTA2 (Alias: D9)
//     <2=> PTD7 (Alias: D22)
//     <1=> Default
#define FTM0_7_SEL           1                   

// FTM1_0 maps to [Disabled, PTA12, PTB0]
//   <o> FTM1_0 Pin Selection [PTA12(D8), PTB0(A5)] 
//   <i> Selects which pin is used for FTM1_0
//     <0=> Disabled
//     <1=> PTA12 (Alias: D8)
//     <2=> PTB0 (Alias: A5)
//     <1=> Default
#define FTM1_0_SEL           1                   

// FTM1_1 maps to [Disabled, PTA13, PTB1]
//   <o> FTM1_1 Pin Selection [PTA13(D24), PTB1(A4)] 
//   <i> Selects which pin is used for FTM1_1
//     <0=> Disabled
//     <1=> PTA13 (Alias: D24)
//     <2=> PTB1 (Alias: A4)
//     <1=> Default
#define FTM1_1_SEL           1                   

// I2C0_SCL maps to [Disabled, PTB0, PTB2]
//   <o> I2C0_SCL Pin Selection [PTB0(A5), PTB2(D15)] 
//   <i> Selects which pin is used for I2C0_SCL
//     <0=> Disabled
//     <1=> PTB0 (Alias: A5)
//     <2=> PTB2 (Alias: D15)
//     <1=> Default
#define I2C0_SCL_SEL         1                   

// I2C0_SDA maps to [Disabled, PTB1, PTB3]
//   <o> I2C0_SDA Pin Selection [PTB1(A4), PTB3(D14)] 
//   <i> Selects which pin is used for I2C0_SDA
//     <0=> Disabled
//     <1=> PTB1 (Alias: A4)
//     <2=> PTB3 (Alias: D14)
//     <1=> Default
#define I2C0_SDA_SEL         1                   

// SPI0_PCS0 maps to [Disabled, PTC4, PTD0]
//   <o> SPI0_PCS0 Pin Selection [PTC4(D7), PTD0(D16)] 
//   <i> Selects which pin is used for SPI0_PCS0
//     <0=> Disabled
//     <1=> PTC4 (Alias: D7)
//     <2=> PTD0 (Alias: D16)
//     <0=> Default
#define SPI0_PCS0_SEL        0                   

// SPI0_PCS1 maps to [Disabled, PTC3, PTD4]
//   <o> SPI0_PCS1 Pin Selection [PTC3(D6), PTD4(D3)] 
//   <i> Selects which pin is used for SPI0_PCS1
//     <0=> Disabled
//     <1=> PTC3 (Alias: D6)
//     <2=> PTD4 (Alias: D3)
//     <0=> Default
#define SPI0_PCS1_SEL        0                   

// SPI0_PCS2 maps to [Disabled, PTC2, PTD5]
//   <o> SPI0_PCS2 Pin Selection [PTC2(D10), PTD5(A3)] 
//   <i> Selects which pin is used for SPI0_PCS2
//     <0=> Disabled
//     <1=> PTC2 (Alias: D10)
//     <2=> PTD5 (Alias: A3)
//     <0=> Default
#define SPI0_PCS2_SEL        0                   

// SPI0_PCS3 maps to [Disabled, PTC1, PTD6]
//   <o> SPI0_PCS3 Pin Selection [PTC1(A1), PTD6(A2)] 
//   <i> Selects which pin is used for SPI0_PCS3
//     <0=> Disabled
//     <1=> PTC1 (Alias: A1)
//     <2=> PTD6 (Alias: A2)
//     <0=> Default
#define SPI0_PCS3_SEL        0                   

// SPI0_PCS4 maps to [Disabled, PTC0]
//   <o> SPI0_PCS4 Pin Selection [PTC0(A0)] 
//   <i> Selects which pin is used for SPI0_PCS4
//     <0=> Disabled
//     <1=> PTC0 (Alias: A0)
//     <0=> Default
#define SPI0_PCS4_SEL        0                   

// SPI0_SCK maps to [Disabled, PTC5, PTD1]
//   <o> SPI0_SCK Pin Selection [PTC5(D18), PTD1(D13)] 
//   <i> Selects which pin is used for SPI0_SCK
//     <0=> Disabled
//     <1=> PTC5 (Alias: D18)
//     <2=> PTD1 (Alias: D13)
//     <2=> Default
#define SPI0_SCK_SEL         2                   

// SPI0_SIN maps to [Disabled, PTC7, PTD3]
//   <o> SPI0_SIN Pin Selection [PTC7(D20), PTD3(D12)] 
//   <i> Selects which pin is used for SPI0_SIN
//     <0=> Disabled
//     <1=> PTC7 (Alias: D20)
//     <2=> PTD3 (Alias: D12)
//     <2=> Default
#define SPI0_SIN_SEL         2                   

// SPI0_SOUT maps to [Disabled, PTC6, PTD2]
//   <o> SPI0_SOUT Pin Selection [PTC6(D19), PTD2(D11)] 
//   <i> Selects which pin is used for SPI0_SOUT
//     <0=> Disabled
//     <1=> PTC6 (Alias: D19)
//     <2=> PTD2 (Alias: D11)
//     <2=> Default
#define SPI0_SOUT_SEL        2                   

// ADC0_DM0

// ADC0_DM3

// ADC0_DP0

// ADC0_DP3

// ADC0_SE23 = ADC0_23
#define ADC0_SE23_ADC_NUM          0     //!< ADC0_SE23 ADC number
#define ADC0_SE23_ADC_CH           23    //!< ADC0_SE23 ADC channel

// PTA0 = FTM0_5
#define PTA0_PORT                  A     //!< PTA0 Port name
#define PTA0_NUM                   0     //!< PTA0 Port number
#if FTM0_5_SEL == 1
#define PTA0_FTM_NUM               0     //!< PTA0 FTM number
#define PTA0_FTM_CH                5     //!< PTA0 FTM channel
#define PTA0_FTM_FN                3     //!< PTA0 Pin multiplexor for FTM
#endif

// PTA1 = FTM0_6 (Alias: D5)
#define PTA1_PORT                  A     //!< PTA1 Port name
#define PTA1_NUM                   1     //!< PTA1 Port number
#if FTM0_6_SEL == 1
#define PTA1_FTM_NUM               0     //!< PTA1 FTM number
#define PTA1_FTM_CH                6     //!< PTA1 FTM channel
#define PTA1_FTM_FN                3     //!< PTA1 Pin multiplexor for FTM
#endif

// PTA2 = FTM0_7 (Alias: D9)
#define PTA2_PORT                  A     //!< PTA2 Port name
#define PTA2_NUM                   2     //!< PTA2 Port number
#if FTM0_7_SEL == 1
#define PTA2_FTM_NUM               0     //!< PTA2 FTM number
#define PTA2_FTM_CH                7     //!< PTA2 FTM channel
#define PTA2_FTM_FN                3     //!< PTA2 Pin multiplexor for FTM
#endif

// PTA3 = FTM0_0
#define PTA3_PORT                  A     //!< PTA3 Port name
#define PTA3_NUM                   3     //!< PTA3 Port number
#if FTM0_0_SEL == 1
#define PTA3_FTM_NUM               0     //!< PTA3 FTM number
#define PTA3_FTM_CH                0     //!< PTA3 FTM channel
#define PTA3_FTM_FN                3     //!< PTA3 Pin multiplexor for FTM
#endif

// PTA4 = FTM0_1 (Alias: D21)
#define PTA4_PORT                  A     //!< PTA4 Port name
#define PTA4_NUM                   4     //!< PTA4 Port number
#if FTM0_1_SEL == 1
#define PTA4_FTM_NUM               0     //!< PTA4 FTM number
#define PTA4_FTM_CH                1     //!< PTA4 FTM channel
#define PTA4_FTM_FN                3     //!< PTA4 Pin multiplexor for FTM
#endif

// PTA5 = FTM0_2 (Alias: D2)
#define PTA5_PORT                  A     //!< PTA5 Port name
#define PTA5_NUM                   5     //!< PTA5 Port number
#if FTM0_2_SEL == 1
#define PTA5_FTM_NUM               0     //!< PTA5 FTM number
#define PTA5_FTM_CH                2     //!< PTA5 FTM channel
#define PTA5_FTM_FN                3     //!< PTA5 Pin multiplexor for FTM
#endif

// PTA12 = FTM1_0 (Alias: D8)
#define PTA12_PORT                 A     //!< PTA12 Port name
#define PTA12_NUM                  12    //!< PTA12 Port number
#if FTM1_0_SEL == 1
#define PTA12_FTM_NUM              1     //!< PTA12 FTM number
#define PTA12_FTM_CH               0     //!< PTA12 FTM channel
#define PTA12_FTM_FN               3     //!< PTA12 Pin multiplexor for FTM
#endif

// PTA13 = FTM1_1 (Alias: D24)
#define PTA13_PORT                 A     //!< PTA13 Port name
#define PTA13_NUM                  13    //!< PTA13 Port number
#if FTM1_1_SEL == 1
#define PTA13_FTM_NUM              1     //!< PTA13 FTM number
#define PTA13_FTM_CH               1     //!< PTA13 FTM channel
#define PTA13_FTM_FN               3     //!< PTA13 Pin multiplexor for FTM
#endif

// PTA18
#define PTA18_PORT                 A     //!< PTA18 Port name
#define PTA18_NUM                  18    //!< PTA18 Port number

// PTA19
#define PTA19_PORT                 A     //!< PTA19 Port name
#define PTA19_NUM                  19    //!< PTA19 Port number

// PTB0 = ADC0_8,FTM1_0,I2C0_SCL (Alias: A5)
#define PTB0_PORT                  B     //!< PTB0 Port name
#define PTB0_NUM                   0     //!< PTB0 Port number
#define PTB0_ADC_NUM               0     //!< PTB0 ADC number
#define PTB0_ADC_CH                8     //!< PTB0 ADC channel
#if FTM1_0_SEL == 2
#define PTB0_FTM_NUM               1     //!< PTB0 FTM number
#define PTB0_FTM_CH                0     //!< PTB0 FTM channel
#define PTB0_FTM_FN                3     //!< PTB0 Pin multiplexor for FTM
#endif
#if I2C0_SCL_SEL == 1
#define I2C0_SCL_FN                2     //!< Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB0  //!< PTB0 = I2C
#endif

// PTB1 = ADC0_9,FTM1_1,I2C0_SDA (Alias: A4)
#define PTB1_PORT                  B     //!< PTB1 Port name
#define PTB1_NUM                   1     //!< PTB1 Port number
#define PTB1_ADC_NUM               0     //!< PTB1 ADC number
#define PTB1_ADC_CH                9     //!< PTB1 ADC channel
#if FTM1_1_SEL == 2
#define PTB1_FTM_NUM               1     //!< PTB1 FTM number
#define PTB1_FTM_CH                1     //!< PTB1 FTM channel
#define PTB1_FTM_FN                3     //!< PTB1 Pin multiplexor for FTM
#endif
#if I2C0_SDA_SEL == 1
#define I2C0_SDA_FN                2     //!< Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB1  //!< PTB1 = I2C
#endif

// PTB2 = ADC0_12,I2C0_SCL (Alias: D15)
#define PTB2_PORT                  B     //!< PTB2 Port name
#define PTB2_NUM                   2     //!< PTB2 Port number
#define PTB2_ADC_NUM               0     //!< PTB2 ADC number
#define PTB2_ADC_CH                12    //!< PTB2 ADC channel
#if I2C0_SCL_SEL == 2
#define I2C0_SCL_FN                2     //!< Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB2  //!< PTB2 = I2C
#endif

// PTB3 = ADC0_13,I2C0_SDA (Alias: D14)
#define PTB3_PORT                  B     //!< PTB3 Port name
#define PTB3_NUM                   3     //!< PTB3 Port number
#define PTB3_ADC_NUM               0     //!< PTB3 ADC number
#define PTB3_ADC_CH                13    //!< PTB3 ADC channel
#if I2C0_SDA_SEL == 2
#define I2C0_SDA_FN                2     //!< Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB3  //!< PTB3 = I2C
#endif

// PTB16
#define PTB16_PORT                 B     //!< PTB16 Port name
#define PTB16_NUM                  16    //!< PTB16 Port number

// PTB17
#define PTB17_PORT                 B     //!< PTB17 Port name
#define PTB17_NUM                  17    //!< PTB17 Port number

// PTB18
#define PTB18_PORT                 B     //!< PTB18 Port name
#define PTB18_NUM                  18    //!< PTB18 Port number

// PTB19
#define PTB19_PORT                 B     //!< PTB19 Port name
#define PTB19_NUM                  19    //!< PTB19 Port number

// PTC0 = ADC0_14,SPI0_PCS4 (Alias: A0)
#define PTC0_PORT                  C     //!< PTC0 Port name
#define PTC0_NUM                   0     //!< PTC0 Port number
#define PTC0_ADC_NUM               0     //!< PTC0 ADC number
#define PTC0_ADC_CH                14    //!< PTC0 ADC channel
#if SPI0_PCS4_SEL == 1
#define SPI0_PCS4_FN               2     //!< PTC0 Pin multiplexor for SPI
#define SPI0_PCS4_GPIO             digitalIO_PTC0  //!< PTC0 = SPI
#endif

// PTC1 = ADC0_15,FTM0_0,SPI0_PCS3 (Alias: A1)
#define PTC1_PORT                  C     //!< PTC1 Port name
#define PTC1_NUM                   1     //!< PTC1 Port number
#define PTC1_ADC_NUM               0     //!< PTC1 ADC number
#define PTC1_ADC_CH                15    //!< PTC1 ADC channel
#if FTM0_0_SEL == 2
#define PTC1_FTM_NUM               0     //!< PTC1 FTM number
#define PTC1_FTM_CH                0     //!< PTC1 FTM channel
#define PTC1_FTM_FN                4     //!< PTC1 Pin multiplexor for FTM
#endif
#if SPI0_PCS3_SEL == 1
#define SPI0_PCS3_FN               2     //!< PTC1 Pin multiplexor for SPI
#define SPI0_PCS3_GPIO             digitalIO_PTC1  //!< PTC1 = SPI
#endif

// PTC2 = ADC0_4,FTM0_1,SPI0_PCS2 (Alias: D10)
#define PTC2_PORT                  C     //!< PTC2 Port name
#define PTC2_NUM                   2     //!< PTC2 Port number
#define PTC2_ADC_NUM               0     //!< PTC2 ADC number
#define PTC2_ADC_CH                4     //!< PTC2 ADC channel
#if FTM0_1_SEL == 2
#define PTC2_FTM_NUM               0     //!< PTC2 FTM number
#define PTC2_FTM_CH                1     //!< PTC2 FTM channel
#define PTC2_FTM_FN                4     //!< PTC2 Pin multiplexor for FTM
#endif
#if SPI0_PCS2_SEL == 1
#define SPI0_PCS2_FN               2     //!< PTC2 Pin multiplexor for SPI
#define SPI0_PCS2_GPIO             digitalIO_PTC2  //!< PTC2 = SPI
#endif

// PTC3 = FTM0_2,SPI0_PCS1 (Alias: D6)
#define PTC3_PORT                  C     //!< PTC3 Port name
#define PTC3_NUM                   3     //!< PTC3 Port number
#if FTM0_2_SEL == 2
#define PTC3_FTM_NUM               0     //!< PTC3 FTM number
#define PTC3_FTM_CH                2     //!< PTC3 FTM channel
#define PTC3_FTM_FN                4     //!< PTC3 Pin multiplexor for FTM
#endif
#if SPI0_PCS1_SEL == 1
#define SPI0_PCS1_FN               2     //!< PTC3 Pin multiplexor for SPI
#define SPI0_PCS1_GPIO             digitalIO_PTC3  //!< PTC3 = SPI
#endif

// PTC4 = FTM0_3,SPI0_PCS0 (Alias: D7)
#define PTC4_PORT                  C     //!< PTC4 Port name
#define PTC4_NUM                   4     //!< PTC4 Port number
#define PTC4_FTM_NUM               0     //!< PTC4 FTM number
#define PTC4_FTM_CH                3     //!< PTC4 FTM channel
#define PTC4_FTM_FN                4     //!< PTC4 Pin multiplexor for FTM
#if SPI0_PCS0_SEL == 1
#define SPI0_PCS0_FN               2     //!< PTC4 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTC4  //!< PTC4 = SPI
#endif

// PTC5 = SPI0_SCK (Alias: D18)
#define PTC5_PORT                  C     //!< PTC5 Port name
#define PTC5_NUM                   5     //!< PTC5 Port number
#if SPI0_SCK_SEL == 1
#define SPI0_SCK_FN                2     //!< PTC5 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTC5  //!< PTC5 = SPI
#endif

// PTC6 = SPI0_SOUT (Alias: D19)
#define PTC6_PORT                  C     //!< PTC6 Port name
#define PTC6_NUM                   6     //!< PTC6 Port number
#if SPI0_SOUT_SEL == 1
#define SPI0_SOUT_FN               2     //!< PTC6 Pin multiplexor for SPI
#define SPI0_SOUT_GPIO             digitalIO_PTC6  //!< PTC6 = SPI
#endif

// PTC7 = SPI0_SIN (Alias: D20)
#define PTC7_PORT                  C     //!< PTC7 Port name
#define PTC7_NUM                   7     //!< PTC7 Port number
#if SPI0_SIN_SEL == 1
#define SPI0_SIN_FN                2     //!< PTC7 Pin multiplexor for SPI
#define SPI0_SIN_GPIO              digitalIO_PTC7  //!< PTC7 = SPI
#endif

// PTC8 (Alias: D4)
#define PTC8_PORT                  C     //!< PTC8 Port name
#define PTC8_NUM                   8     //!< PTC8 Port number

// PTC9 (Alias: D23)
#define PTC9_PORT                  C     //!< PTC9 Port name
#define PTC9_NUM                   9     //!< PTC9 Port number

// PTC10 (Alias: D25)
#define PTC10_PORT                 C     //!< PTC10 Port name
#define PTC10_NUM                  10    //!< PTC10 Port number

// PTC11 (Alias: D17)
#define PTC11_PORT                 C     //!< PTC11 Port name
#define PTC11_NUM                  11    //!< PTC11 Port number

// PTD0 = SPI0_PCS0 (Alias: D16)
#define PTD0_PORT                  D     //!< PTD0 Port name
#define PTD0_NUM                   0     //!< PTD0 Port number
#if SPI0_PCS0_SEL == 2
#define SPI0_PCS0_FN               2     //!< PTD0 Pin multiplexor for SPI
#define SPI0_PCS0_GPIO             digitalIO_PTD0  //!< PTD0 = SPI
#endif

// PTD1 = ADC0_5,SPI0_SCK (Alias: D13)
#define PTD1_PORT                  D     //!< PTD1 Port name
#define PTD1_NUM                   1     //!< PTD1 Port number
#define PTD1_ADC_NUM               0     //!< PTD1 ADC number
#define PTD1_ADC_CH                5     //!< PTD1 ADC channel
#if SPI0_SCK_SEL == 2
#define SPI0_SCK_FN                2     //!< PTD1 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTD1  //!< PTD1 = SPI
#endif

// PTD2 = SPI0_SOUT (Alias: D11)
#define PTD2_PORT                  D     //!< PTD2 Port name
#define PTD2_NUM                   2     //!< PTD2 Port number
#if SPI0_SOUT_SEL == 2
#define SPI0_SOUT_FN               2     //!< PTD2 Pin multiplexor for SPI
#define SPI0_SOUT_GPIO             digitalIO_PTD2  //!< PTD2 = SPI
#endif

// PTD3 = SPI0_SIN (Alias: D12)
#define PTD3_PORT                  D     //!< PTD3 Port name
#define PTD3_NUM                   3     //!< PTD3 Port number
#if SPI0_SIN_SEL == 2
#define SPI0_SIN_FN                2     //!< PTD3 Pin multiplexor for SPI
#define SPI0_SIN_GPIO              digitalIO_PTD3  //!< PTD3 = SPI
#endif

// PTD4 = FTM0_4,SPI0_PCS1 (Alias: D3)
#define PTD4_PORT                  D     //!< PTD4 Port name
#define PTD4_NUM                   4     //!< PTD4 Port number
#define PTD4_FTM_NUM               0     //!< PTD4 FTM number
#define PTD4_FTM_CH                4     //!< PTD4 FTM channel
#define PTD4_FTM_FN                4     //!< PTD4 Pin multiplexor for FTM
#if SPI0_PCS1_SEL == 2
#define SPI0_PCS1_FN               2     //!< PTD4 Pin multiplexor for SPI
#define SPI0_PCS1_GPIO             digitalIO_PTD4  //!< PTD4 = SPI
#endif

// PTD5 = ADC0_6,FTM0_5,SPI0_PCS2 (Alias: A3)
#define PTD5_PORT                  D     //!< PTD5 Port name
#define PTD5_NUM                   5     //!< PTD5 Port number
#define PTD5_ADC_NUM               0     //!< PTD5 ADC number
#define PTD5_ADC_CH                6     //!< PTD5 ADC channel
#if FTM0_5_SEL == 2
#define PTD5_FTM_NUM               0     //!< PTD5 FTM number
#define PTD5_FTM_CH                5     //!< PTD5 FTM channel
#define PTD5_FTM_FN                4     //!< PTD5 Pin multiplexor for FTM
#endif
#if SPI0_PCS2_SEL == 2
#define SPI0_PCS2_FN               2     //!< PTD5 Pin multiplexor for SPI
#define SPI0_PCS2_GPIO             digitalIO_PTD5  //!< PTD5 = SPI
#endif

// PTD6 = ADC0_7,FTM0_6,SPI0_PCS3 (Alias: A2)
#define PTD6_PORT                  D     //!< PTD6 Port name
#define PTD6_NUM                   6     //!< PTD6 Port number
#define PTD6_ADC_NUM               0     //!< PTD6 ADC number
#define PTD6_ADC_CH                7     //!< PTD6 ADC channel
#if FTM0_6_SEL == 2
#define PTD6_FTM_NUM               0     //!< PTD6 FTM number
#define PTD6_FTM_CH                6     //!< PTD6 FTM channel
#define PTD6_FTM_FN                4     //!< PTD6 Pin multiplexor for FTM
#endif
#if SPI0_PCS3_SEL == 2
#define SPI0_PCS3_FN               2     //!< PTD6 Pin multiplexor for SPI
#define SPI0_PCS3_GPIO             digitalIO_PTD6  //!< PTD6 = SPI
#endif

// PTD7 = FTM0_7 (Alias: D22)
#define PTD7_PORT                  D     //!< PTD7 Port name
#define PTD7_NUM                   7     //!< PTD7 Port number
#if FTM0_7_SEL == 2
#define PTD7_FTM_NUM               0     //!< PTD7 FTM number
#define PTD7_FTM_CH                7     //!< PTD7 FTM channel
#define PTD7_FTM_FN                4     //!< PTD7 Pin multiplexor for FTM
#endif

// PTE0 (Alias: D1)
#define PTE0_PORT                  E     //!< PTE0 Port name
#define PTE0_NUM                   0     //!< PTE0 Port number

// PTE1 (Alias: D0)
#define PTE1_PORT                  E     //!< PTE1 Port name
#define PTE1_NUM                   1     //!< PTE1 Port number

// </h>


#endif /* PINMAPPING_H_ */
