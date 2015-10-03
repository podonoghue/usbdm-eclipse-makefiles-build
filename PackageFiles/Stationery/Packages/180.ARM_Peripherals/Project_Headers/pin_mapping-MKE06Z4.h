/**
 * @file      pin_mapping.h (derived from pin_mapping-MKE06Z4.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKE06Z4
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

// <h> Clock settings for FTM0

// FTM0_SC.CLKS ================================
//
//   <o> FTM0_SC.CLKS Clock source 
//   <i> Selects the clock source for the FTM0 module. [FTM0_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM0_SC.PS ================================
//
//   <o1> FTM0_SC.PS Clock prescaler 
//   <i> Selects the prescaler for the FTM0 module. [FTM0_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
#define FTM0_SC              (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0))

// </h>

// <h> Clock settings for FTM1

// FTM1_SC.CLKS ================================
//
//   <o> FTM1_SC.CLKS Clock source 
//   <i> Selects the clock source for the FTM1 module. [FTM1_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM1_SC.PS ================================
//
//   <o1> FTM1_SC.PS Clock prescaler 
//   <i> Selects the prescaler for the FTM1 module. [FTM1_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
#define FTM1_SC              (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0))

// </h>

// <h> Clock settings for FTM2

// FTM2_SC.CLKS ================================
//
//   <o> FTM2_SC.CLKS Clock source 
//   <i> Selects the clock source for the FTM2 module. [FTM2_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM2_SC.PS ================================
//
//   <o1> FTM2_SC.PS Clock prescaler 
//   <i> Selects the prescaler for the FTM2 module. [FTM2_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
#define FTM2_SC              (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0))

// </h>

#define ACMP0_CLOCK_REG      SIM->SCGC           
#define ACMP0_CLOCK_MASK     SIM_SCGC_ACMP0_MASK 
#define ACMP1_CLOCK_REG      SIM->SCGC           
#define ACMP1_CLOCK_MASK     SIM_SCGC_ACMP1_MASK 
#define ADC0_CLOCK_REG       SIM->SCGC           
#define ADC0_CLOCK_MASK      SIM_SCGC_ADC0_MASK  
#define CRC_CLOCK_REG        SIM->SCGC           
#define CRC_CLOCK_MASK       SIM_SCGC_CRC_MASK   
#define FTM0_CLOCK_REG       SIM->SCGC           
#define FTM0_CLOCK_MASK      SIM_SCGC_FTM0_MASK  
#define FTM1_CLOCK_REG       SIM->SCGC           
#define FTM1_CLOCK_MASK      SIM_SCGC_FTM1_MASK  
#define FTM2_CLOCK_REG       SIM->SCGC           
#define FTM2_CLOCK_MASK      SIM_SCGC_FTM2_MASK  
#define I2C0_CLOCK_REG       SIM->SCGC           
#define I2C0_CLOCK_MASK      SIM_SCGC_I2C0_MASK  
#define I2C1_CLOCK_REG       SIM->SCGC           
#define I2C1_CLOCK_MASK      SIM_SCGC_I2C1_MASK  
#define IRQ_CLOCK_REG        SIM->SCGC           
#define IRQ_CLOCK_MASK       SIM_SCGC_IRQ_MASK   
#define KBI0_CLOCK_REG       SIM->SCGC           
#define KBI0_CLOCK_MASK      SIM_SCGC_KBI0_MASK  
#define KBI1_CLOCK_REG       SIM->SCGC           
#define KBI1_CLOCK_MASK      SIM_SCGC_KBI1_MASK  
#define MSCAN_CLOCK_REG      SIM->SCGC           
#define MSCAN_CLOCK_MASK     SIM_SCGC_MSCAN_MASK 
#define PIT_CLOCK_REG        SIM->SCGC           
#define PIT_CLOCK_MASK       SIM_SCGC_PIT_MASK   
#define PWT_CLOCK_REG        SIM->SCGC           
#define PWT_CLOCK_MASK       SIM_SCGC_PWT_MASK   
#define RTC_CLOCK_REG        SIM->SCGC           
#define RTC_CLOCK_MASK       SIM_SCGC_RTC_MASK   
#define SPI0_CLOCK_REG       SIM->SCGC           
#define SPI0_CLOCK_MASK      SIM_SCGC_SPI0_MASK  
#define SPI1_CLOCK_REG       SIM->SCGC           
#define SPI1_CLOCK_MASK      SIM_SCGC_SPI1_MASK  
#define SWD_CLOCK_REG        SIM->SCGC           
#define SWD_CLOCK_MASK       SIM_SCGC_SWD_MASK   
#define UART0_CLOCK_REG      SIM->SCGC           
#define UART0_CLOCK_MASK     SIM_SCGC_UART0_MASK 
#define UART1_CLOCK_REG      SIM->SCGC           
#define UART1_CLOCK_MASK     SIM_SCGC_UART1_MASK 
#define UART2_CLOCK_REG      SIM->SCGC           
#define UART2_CLOCK_MASK     SIM_SCGC_UART2_MASK 
#define PORT_CLOCK_REG       SIM->SCGC5          

// <h> Pin Peripheral mapping

// ADC0_SE0 Pin Mapping
//   <o> ADC0_SE0 Pin Selection [PTA0] <constant>
//   <i> Selects which pin is used for ADC0_SE0
//     <0=> Disabled
//     <1=> PTA0
//     <1=> Default
#define ADC0_SE0_SEL         1                   

// ADC0_SE1 Pin Mapping
//   <o> ADC0_SE1 Pin Selection [PTA1] <constant>
//   <i> Selects which pin is used for ADC0_SE1
//     <0=> Disabled
//     <1=> PTA1
//     <1=> Default
#define ADC0_SE1_SEL         1                   

// ADC0_SE2 Pin Mapping
//   <o> ADC0_SE2 Pin Selection [PTA6] <constant>
//   <i> Selects which pin is used for ADC0_SE2
//     <0=> Disabled
//     <1=> PTA6
//     <1=> Default
#define ADC0_SE2_SEL         1                   

// ADC0_SE3 Pin Mapping
//   <o> ADC0_SE3 Pin Selection [PTA7] <constant>
//   <i> Selects which pin is used for ADC0_SE3
//     <0=> Disabled
//     <1=> PTA7
//     <1=> Default
#define ADC0_SE3_SEL         1                   

// ADC0_SE4 Pin Mapping
//   <o> ADC0_SE4 Pin Selection [PTB0] <constant>
//   <i> Selects which pin is used for ADC0_SE4
//     <0=> Disabled
//     <1=> PTB0
//     <1=> Default
#define ADC0_SE4_SEL         1                   

// ADC0_SE5 Pin Mapping
//   <o> ADC0_SE5 Pin Selection [PTB1] <constant>
//   <i> Selects which pin is used for ADC0_SE5
//     <0=> Disabled
//     <1=> PTB1
//     <1=> Default
#define ADC0_SE5_SEL         1                   

// ADC0_SE6 Pin Mapping
//   <o> ADC0_SE6 Pin Selection [PTB2] <constant>
//   <i> Selects which pin is used for ADC0_SE6
//     <0=> Disabled
//     <1=> PTB2
//     <1=> Default
#define ADC0_SE6_SEL         1                   

// ADC0_SE7 Pin Mapping
//   <o> ADC0_SE7 Pin Selection [PTB3] <constant>
//   <i> Selects which pin is used for ADC0_SE7
//     <0=> Disabled
//     <1=> PTB3
//     <1=> Default
#define ADC0_SE7_SEL         1                   

// ADC0_SE8 Pin Mapping
//   <o> ADC0_SE8 Pin Selection [PTC0] <constant>
//   <i> Selects which pin is used for ADC0_SE8
//     <0=> Disabled
//     <1=> PTC0
//     <1=> Default
#define ADC0_SE8_SEL         1                   

// ADC0_SE9 Pin Mapping
//   <o> ADC0_SE9 Pin Selection [PTC1] <constant>
//   <i> Selects which pin is used for ADC0_SE9
//     <0=> Disabled
//     <1=> PTC1
//     <1=> Default
#define ADC0_SE9_SEL         1                   

// ADC0_SE10 Pin Mapping
//   <o> ADC0_SE10 Pin Selection [PTC2] <constant>
//   <i> Selects which pin is used for ADC0_SE10
//     <0=> Disabled
//     <1=> PTC2
//     <1=> Default
#define ADC0_SE10_SEL        1                   

// ADC0_SE11 Pin Mapping
//   <o> ADC0_SE11 Pin Selection [PTC3] <constant>
//   <i> Selects which pin is used for ADC0_SE11
//     <0=> Disabled
//     <1=> PTC3
//     <1=> Default
#define ADC0_SE11_SEL        1                   

// ADC0_SE12 Pin Mapping
//   <o> ADC0_SE12 Pin Selection [PTF4] <constant>
//   <i> Selects which pin is used for ADC0_SE12
//     <0=> Disabled
//     <1=> PTF4
//     <1=> Default
#define ADC0_SE12_SEL        1                   

// ADC0_SE13 Pin Mapping
//   <o> ADC0_SE13 Pin Selection [PTF5] <constant>
//   <i> Selects which pin is used for ADC0_SE13
//     <0=> Disabled
//     <1=> PTF5
//     <1=> Default
#define ADC0_SE13_SEL        1                   

// ADC0_SE14 Pin Mapping
//   <o> ADC0_SE14 Pin Selection [PTF6] <constant>
//   <i> Selects which pin is used for ADC0_SE14
//     <0=> Disabled
//     <1=> PTF6
//     <1=> Default
#define ADC0_SE14_SEL        1                   

// ADC0_SE15 Pin Mapping
//   <o> ADC0_SE15 Pin Selection [PTF7] <constant>
//   <i> Selects which pin is used for ADC0_SE15
//     <0=> Disabled
//     <1=> PTF7
//     <1=> Default
#define ADC0_SE15_SEL        1                   

// FTM0_CH0 Pin Mapping
//   <o> FTM0_CH0 Pin Selection [PTA0, PTB2] 
//   <i> Selects which pin is used for FTM0_CH0
//     <0=> Disabled
//     <1=> PTA0
//     <2=> PTB2
//     <0=> Default
#define FTM0_CH0_SEL         0                   

// FTM0_CH1 Pin Mapping
//   <o> FTM0_CH1 Pin Selection [PTA1, PTB3] 
//   <i> Selects which pin is used for FTM0_CH1
//     <0=> Disabled
//     <1=> PTA1
//     <2=> PTB3
//     <0=> Default
#define FTM0_CH1_SEL         0                   

// FTM1_CH0 Pin Mapping
//   <o> FTM1_CH0 Pin Selection [PTC4, PTH2] 
//   <i> Selects which pin is used for FTM1_CH0
//     <0=> Disabled
//     <1=> PTC4
//     <2=> PTH2
//     <0=> Default
#define FTM1_CH0_SEL         0                   

// FTM1_CH1 Pin Mapping
//   <o> FTM1_CH1 Pin Selection [PTC5, PTE7] 
//   <i> Selects which pin is used for FTM1_CH1
//     <0=> Disabled
//     <1=> PTC5
//     <2=> PTE7
//     <0=> Default
#define FTM1_CH1_SEL         0                   

// FTM2_CH0 Pin Mapping
//   <o> FTM2_CH0 Pin Selection [PTC0, PTF0, PTH0] 
//   <i> Selects which pin is used for FTM2_CH0
//     <0=> Disabled
//     <1=> PTC0
//     <2=> PTF0
//     <3=> PTH0
//     <0=> Default
#define FTM2_CH0_SEL         0                   

// FTM2_CH1 Pin Mapping
//   <o> FTM2_CH1 Pin Selection [PTC1, PTF1, PTH1] 
//   <i> Selects which pin is used for FTM2_CH1
//     <0=> Disabled
//     <1=> PTC1
//     <2=> PTF1
//     <3=> PTH1
//     <0=> Default
#define FTM2_CH1_SEL         0                   

// FTM2_CH2 Pin Mapping
//   <o> FTM2_CH2 Pin Selection [PTC2, PTD0, PTG4] 
//   <i> Selects which pin is used for FTM2_CH2
//     <0=> Disabled
//     <1=> PTC2
//     <2=> PTD0
//     <3=> PTG4
//     <0=> Default
#define FTM2_CH2_SEL         0                   

// FTM2_CH3 Pin Mapping
//   <o> FTM2_CH3 Pin Selection [PTC3, PTD1, PTG5] 
//   <i> Selects which pin is used for FTM2_CH3
//     <0=> Disabled
//     <1=> PTC3
//     <2=> PTD1
//     <3=> PTG5
//     <0=> Default
#define FTM2_CH3_SEL         0                   

// FTM2_CH4 Pin Mapping
//   <o> FTM2_CH4 Pin Selection [PTB4, PTG6] 
//   <i> Selects which pin is used for FTM2_CH4
//     <0=> Disabled
//     <1=> PTB4
//     <2=> PTG6
//     <0=> Default
#define FTM2_CH4_SEL         0                   

// FTM2_CH5 Pin Mapping
//   <o> FTM2_CH5 Pin Selection [PTB5, PTG7] 
//   <i> Selects which pin is used for FTM2_CH5
//     <0=> Disabled
//     <1=> PTB5
//     <2=> PTG7
//     <0=> Default
#define FTM2_CH5_SEL         0                   

// I2C0_SCL Pin Mapping
//   <o> I2C0_SCL Pin Selection [PTA3, PTB7] 
//   <i> Selects which pin is used for I2C0_SCL
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTB7
//     <0=> Default
#define I2C0_SCL_SEL         0                   

// I2C0_4WSDAOUT Pin Mapping
//   <o> I2C0_4WSDAOUT Pin Selection [PTA1] 
//   <i> Selects which pin is used for I2C0_4WSDAOUT
//     <0=> Disabled
//     <1=> PTA1
//     <0=> Default
#define I2C0_4WSDAOUT_SEL    0                   

// I2C0_SDA Pin Mapping
//   <o> I2C0_SDA Pin Selection [PTA2, PTB6] 
//   <i> Selects which pin is used for I2C0_SDA
//     <0=> Disabled
//     <1=> PTA2
//     <2=> PTB6
//     <0=> Default
#define I2C0_SDA_SEL         0                   

// I2C0_4WSCLOUT Pin Mapping
//   <o> I2C0_4WSCLOUT Pin Selection [PTA0] 
//   <i> Selects which pin is used for I2C0_4WSCLOUT
//     <0=> Disabled
//     <1=> PTA0
//     <0=> Default
#define I2C0_4WSCLOUT_SEL    0                   

// I2C1_SDA Pin Mapping
//   <o> I2C1_SDA Pin Selection [PTE0, PTH3] 
//   <i> Selects which pin is used for I2C1_SDA
//     <0=> Disabled
//     <1=> PTE0
//     <2=> PTH3
//     <0=> Default
#define I2C1_SDA_SEL         0                   

// I2C1_SCL Pin Mapping
//   <o> I2C1_SCL Pin Selection [PTE1, PTH4] 
//   <i> Selects which pin is used for I2C1_SCL
//     <0=> Disabled
//     <1=> PTE1
//     <2=> PTH4
//     <0=> Default
#define I2C1_SCL_SEL         0                   

// SPI0_MISO Pin Mapping
//   <o> SPI0_MISO Pin Selection [PTB4, PTE2] 
//   <i> Selects which pin is used for SPI0_MISO
//     <0=> Disabled
//     <1=> PTB4
//     <2=> PTE2
//     <0=> Default
#define SPI0_MISO_SEL        0                   

// SPI0_MOSI Pin Mapping
//   <o> SPI0_MOSI Pin Selection [PTB3, PTE1] 
//   <i> Selects which pin is used for SPI0_MOSI
//     <0=> Disabled
//     <1=> PTB3
//     <2=> PTE1
//     <0=> Default
#define SPI0_MOSI_SEL        0                   

// SPI0_PCS Pin Mapping
//   <o> SPI0_PCS Pin Selection [PTB5, PTE3] 
//   <i> Selects which pin is used for SPI0_PCS
//     <0=> Disabled
//     <1=> PTB5
//     <2=> PTE3
//     <0=> Default
#define SPI0_PCS_SEL         0                   

// SPI0_SCK Pin Mapping
//   <o> SPI0_SCK Pin Selection [PTB2, PTE0] 
//   <i> Selects which pin is used for SPI0_SCK
//     <0=> Disabled
//     <1=> PTB2
//     <2=> PTE0
//     <0=> Default
#define SPI0_SCK_SEL         0                   

// SPI1_MISO Pin Mapping
//   <o> SPI1_MISO Pin Selection [PTD2, PTG6] 
//   <i> Selects which pin is used for SPI1_MISO
//     <0=> Disabled
//     <1=> PTD2
//     <2=> PTG6
//     <0=> Default
#define SPI1_MISO_SEL        0                   

// SPI1_MOSI Pin Mapping
//   <o> SPI1_MOSI Pin Selection [PTD1, PTG5] 
//   <i> Selects which pin is used for SPI1_MOSI
//     <0=> Disabled
//     <1=> PTD1
//     <2=> PTG5
//     <0=> Default
#define SPI1_MOSI_SEL        0                   

// SPI1_PCS Pin Mapping
//   <o> SPI1_PCS Pin Selection [PTD3, PTG7] 
//   <i> Selects which pin is used for SPI1_PCS
//     <0=> Disabled
//     <1=> PTD3
//     <2=> PTG7
//     <0=> Default
#define SPI1_PCS_SEL         0                   

// SPI1_SCK Pin Mapping
//   <o> SPI1_SCK Pin Selection [PTD0, PTG4] 
//   <i> Selects which pin is used for SPI1_SCK
//     <0=> Disabled
//     <1=> PTD0
//     <2=> PTG4
//     <0=> Default
#define SPI1_SCK_SEL         0                   

// </h>

//-------- <<< end of configuration section >>> -----------------  

// PTA0 = GPIOA_0,FTM0_CH0,I2C0_4WSCLOUT,ADC0_SE0
#define PTA0_GPIO_NAME             A     //!< PTA0 GPIO name
#define PTA0_GPIO_BIT              0     //!< PTA0 GPIO bit number
#define PTA0_GPIO_FN               0     //!< PTA0 Pin multiplexor for GPIO
#define PTA0_ADC_NUM               0     //!< PTA0 ADC number
#define PTA0_ADC_CH                0     //!< PTA0 ADC channel
#define PTA0_ADC_FN                5     //!< PTA0 Pin multiplexor for ADC
#if FTM0_CH0_SEL == 1
#define PTA0_FTM_NUM               0     //!< PTA0 FTM number
#define PTA0_FTM_CH                0     //!< PTA0 FTM channel
#define PTA0_FTM_FN                2     //!< PTA0 Pin multiplexor for FTM
#endif
#if I2C0_4WSCLOUT_SEL == 1
#define I2C0_4WSCLOUT_FN           3     //!< PTA0 Pin multiplexor for I2C
#define I2C0_4WSCLOUT_GPIO         digitalIO_PTA0   //!< PTA0 I2C GPIO
#endif

// PTA1 = GPIOA_1,FTM0_CH1,I2C0_4WSDAOUT,ADC0_SE1
#define PTA1_GPIO_NAME             A     //!< PTA1 GPIO name
#define PTA1_GPIO_BIT              1     //!< PTA1 GPIO bit number
#define PTA1_GPIO_FN               0     //!< PTA1 Pin multiplexor for GPIO
#define PTA1_ADC_NUM               0     //!< PTA1 ADC number
#define PTA1_ADC_CH                1     //!< PTA1 ADC channel
#define PTA1_ADC_FN                5     //!< PTA1 Pin multiplexor for ADC
#if FTM0_CH1_SEL == 1
#define PTA1_FTM_NUM               0     //!< PTA1 FTM number
#define PTA1_FTM_CH                1     //!< PTA1 FTM channel
#define PTA1_FTM_FN                2     //!< PTA1 Pin multiplexor for FTM
#endif
#if I2C0_4WSDAOUT_SEL == 1
#define I2C0_4WSDAOUT_FN           3     //!< PTA1 Pin multiplexor for I2C
#define I2C0_4WSDAOUT_GPIO         digitalIO_PTA1   //!< PTA1 I2C GPIO
#endif

// PTA2 = GPIOA_2,I2C0_SDA
#define PTA2_GPIO_NAME             A     //!< PTA2 GPIO name
#define PTA2_GPIO_BIT              2     //!< PTA2 GPIO bit number
#define PTA2_GPIO_FN               0     //!< PTA2 Pin multiplexor for GPIO
#if I2C0_SDA_SEL == 1
#define I2C0_SDA_FN                3     //!< PTA2 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTA2   //!< PTA2 I2C GPIO
#endif

// PTA3 = GPIOA_3,I2C0_SCL
#define PTA3_GPIO_NAME             A     //!< PTA3 GPIO name
#define PTA3_GPIO_BIT              3     //!< PTA3 GPIO bit number
#define PTA3_GPIO_FN               0     //!< PTA3 Pin multiplexor for GPIO
#if I2C0_SCL_SEL == 1
#define I2C0_SCL_FN                3     //!< PTA3 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTA3   //!< PTA3 I2C GPIO
#endif

// PTA5 = GPIOA_5
#define PTA5_GPIO_NAME             A     //!< PTA5 GPIO name
#define PTA5_GPIO_BIT              5     //!< PTA5 GPIO bit number
#define PTA5_GPIO_FN               0     //!< PTA5 Pin multiplexor for GPIO

// PTA6 = GPIOA_6,ADC0_SE2
#define PTA6_GPIO_NAME             A     //!< PTA6 GPIO name
#define PTA6_GPIO_BIT              6     //!< PTA6 GPIO bit number
#define PTA6_GPIO_FN               0     //!< PTA6 Pin multiplexor for GPIO
#define PTA6_ADC_NUM               0     //!< PTA6 ADC number
#define PTA6_ADC_CH                2     //!< PTA6 ADC channel
#define PTA6_ADC_FN                4     //!< PTA6 Pin multiplexor for ADC

// PTA7 = GPIOA_7,ADC0_SE3
#define PTA7_GPIO_NAME             A     //!< PTA7 GPIO name
#define PTA7_GPIO_BIT              7     //!< PTA7 GPIO bit number
#define PTA7_GPIO_FN               0     //!< PTA7 Pin multiplexor for GPIO
#define PTA7_ADC_NUM               0     //!< PTA7 ADC number
#define PTA7_ADC_CH                3     //!< PTA7 ADC channel
#define PTA7_ADC_FN                4     //!< PTA7 Pin multiplexor for ADC

// PTB0 = GPIOA_8,ADC0_SE4
#define PTB0_GPIO_NAME             A     //!< PTB0 GPIO name
#define PTB0_GPIO_BIT              8     //!< PTB0 GPIO bit number
#define PTB0_GPIO_FN               0     //!< PTB0 Pin multiplexor for GPIO
#define PTB0_ADC_NUM               0     //!< PTB0 ADC number
#define PTB0_ADC_CH                4     //!< PTB0 ADC channel
#define PTB0_ADC_FN                4     //!< PTB0 Pin multiplexor for ADC

// PTB1 = GPIOA_9,ADC0_SE5
#define PTB1_GPIO_NAME             A     //!< PTB1 GPIO name
#define PTB1_GPIO_BIT              9     //!< PTB1 GPIO bit number
#define PTB1_GPIO_FN               0     //!< PTB1 Pin multiplexor for GPIO
#define PTB1_ADC_NUM               0     //!< PTB1 ADC number
#define PTB1_ADC_CH                5     //!< PTB1 ADC channel
#define PTB1_ADC_FN                4     //!< PTB1 Pin multiplexor for ADC

// PTB2 = GPIOA_10,SPI0_SCK,FTM0_CH0,ADC0_SE6
#define PTB2_GPIO_NAME             A     //!< PTB2 GPIO name
#define PTB2_GPIO_BIT              10    //!< PTB2 GPIO bit number
#define PTB2_GPIO_FN               0     //!< PTB2 Pin multiplexor for GPIO
#define PTB2_ADC_NUM               0     //!< PTB2 ADC number
#define PTB2_ADC_CH                6     //!< PTB2 ADC channel
#define PTB2_ADC_FN                4     //!< PTB2 Pin multiplexor for ADC
#if FTM0_CH0_SEL == 2
#define PTB2_FTM_NUM               0     //!< PTB2 FTM number
#define PTB2_FTM_CH                0     //!< PTB2 FTM channel
#define PTB2_FTM_FN                3     //!< PTB2 Pin multiplexor for FTM
#endif
#if SPI0_SCK_SEL == 1
#define SPI0_SCK_FN                2     //!< PTB2 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTB2   //!< PTB2 SPI GPIO
#endif

// PTB3 = GPIOA_11,SPI0_MOSI,FTM0_CH1,ADC0_SE7
#define PTB3_GPIO_NAME             A     //!< PTB3 GPIO name
#define PTB3_GPIO_BIT              11    //!< PTB3 GPIO bit number
#define PTB3_GPIO_FN               0     //!< PTB3 Pin multiplexor for GPIO
#define PTB3_ADC_NUM               0     //!< PTB3 ADC number
#define PTB3_ADC_CH                7     //!< PTB3 ADC channel
#define PTB3_ADC_FN                4     //!< PTB3 Pin multiplexor for ADC
#if FTM0_CH1_SEL == 2
#define PTB3_FTM_NUM               0     //!< PTB3 FTM number
#define PTB3_FTM_CH                1     //!< PTB3 FTM channel
#define PTB3_FTM_FN                3     //!< PTB3 Pin multiplexor for FTM
#endif
#if SPI0_MOSI_SEL == 1
#define SPI0_MOSI_FN               2     //!< PTB3 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTB3   //!< PTB3 SPI GPIO
#endif

// PTB4 = GPIOA_12,FTM2_CH4,SPI0_MISO
#define PTB4_GPIO_NAME             A     //!< PTB4 GPIO name
#define PTB4_GPIO_BIT              12    //!< PTB4 GPIO bit number
#define PTB4_GPIO_FN               0     //!< PTB4 Pin multiplexor for GPIO
#if FTM2_CH4_SEL == 1
#define PTB4_FTM_NUM               2     //!< PTB4 FTM number
#define PTB4_FTM_CH                4     //!< PTB4 FTM channel
#define PTB4_FTM_FN                2     //!< PTB4 Pin multiplexor for FTM
#endif
#if SPI0_MISO_SEL == 1
#define SPI0_MISO_FN               3     //!< PTB4 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTB4   //!< PTB4 SPI GPIO
#endif

// PTB5 = GPIOA_13,FTM2_CH5,SPI0_PCS
#define PTB5_GPIO_NAME             A     //!< PTB5 GPIO name
#define PTB5_GPIO_BIT              13    //!< PTB5 GPIO bit number
#define PTB5_GPIO_FN               0     //!< PTB5 Pin multiplexor for GPIO
#if FTM2_CH5_SEL == 1
#define PTB5_FTM_NUM               2     //!< PTB5 FTM number
#define PTB5_FTM_CH                5     //!< PTB5 FTM channel
#define PTB5_FTM_FN                2     //!< PTB5 Pin multiplexor for FTM
#endif
#if SPI0_PCS_SEL == 1
#define SPI0_PCS_FN                3     //!< PTB5 Pin multiplexor for SPI
#define SPI0_PCS_GPIO              digitalIO_PTB5   //!< PTB5 SPI GPIO
#endif

// PTB6 = GPIOA_14,I2C0_SDA
#define PTB6_GPIO_NAME             A     //!< PTB6 GPIO name
#define PTB6_GPIO_BIT              14    //!< PTB6 GPIO bit number
#define PTB6_GPIO_FN               0     //!< PTB6 Pin multiplexor for GPIO
#if I2C0_SDA_SEL == 2
#define I2C0_SDA_FN                2     //!< PTB6 Pin multiplexor for I2C
#define I2C0_SDA_GPIO              digitalIO_PTB6   //!< PTB6 I2C GPIO
#endif

// PTB7 = GPIOA_15,I2C0_SCL
#define PTB7_GPIO_NAME             A     //!< PTB7 GPIO name
#define PTB7_GPIO_BIT              15    //!< PTB7 GPIO bit number
#define PTB7_GPIO_FN               0     //!< PTB7 Pin multiplexor for GPIO
#if I2C0_SCL_SEL == 2
#define I2C0_SCL_FN                2     //!< PTB7 Pin multiplexor for I2C
#define I2C0_SCL_GPIO              digitalIO_PTB7   //!< PTB7 I2C GPIO
#endif

// PTC0 = GPIOA_16,FTM2_CH0,ADC0_SE8
#define PTC0_GPIO_NAME             A     //!< PTC0 GPIO name
#define PTC0_GPIO_BIT              16    //!< PTC0 GPIO bit number
#define PTC0_GPIO_FN               0     //!< PTC0 Pin multiplexor for GPIO
#define PTC0_ADC_NUM               0     //!< PTC0 ADC number
#define PTC0_ADC_CH                8     //!< PTC0 ADC channel
#define PTC0_ADC_FN                4     //!< PTC0 Pin multiplexor for ADC
#if FTM2_CH0_SEL == 1
#define PTC0_FTM_NUM               2     //!< PTC0 FTM number
#define PTC0_FTM_CH                0     //!< PTC0 FTM channel
#define PTC0_FTM_FN                2     //!< PTC0 Pin multiplexor for FTM
#endif

// PTC1 = GPIOA_17,FTM2_CH1,ADC0_SE9
#define PTC1_GPIO_NAME             A     //!< PTC1 GPIO name
#define PTC1_GPIO_BIT              17    //!< PTC1 GPIO bit number
#define PTC1_GPIO_FN               0     //!< PTC1 Pin multiplexor for GPIO
#define PTC1_ADC_NUM               0     //!< PTC1 ADC number
#define PTC1_ADC_CH                9     //!< PTC1 ADC channel
#define PTC1_ADC_FN                4     //!< PTC1 Pin multiplexor for ADC
#if FTM2_CH1_SEL == 1
#define PTC1_FTM_NUM               2     //!< PTC1 FTM number
#define PTC1_FTM_CH                1     //!< PTC1 FTM channel
#define PTC1_FTM_FN                2     //!< PTC1 Pin multiplexor for FTM
#endif

// PTC2 = GPIOA_18,FTM2_CH2,ADC0_SE10
#define PTC2_GPIO_NAME             A     //!< PTC2 GPIO name
#define PTC2_GPIO_BIT              18    //!< PTC2 GPIO bit number
#define PTC2_GPIO_FN               0     //!< PTC2 Pin multiplexor for GPIO
#define PTC2_ADC_NUM               0     //!< PTC2 ADC number
#define PTC2_ADC_CH                10    //!< PTC2 ADC channel
#define PTC2_ADC_FN                4     //!< PTC2 Pin multiplexor for ADC
#if FTM2_CH2_SEL == 1
#define PTC2_FTM_NUM               2     //!< PTC2 FTM number
#define PTC2_FTM_CH                2     //!< PTC2 FTM channel
#define PTC2_FTM_FN                2     //!< PTC2 Pin multiplexor for FTM
#endif

// PTC3 = GPIOA_19,FTM2_CH3,ADC0_SE11
#define PTC3_GPIO_NAME             A     //!< PTC3 GPIO name
#define PTC3_GPIO_BIT              19    //!< PTC3 GPIO bit number
#define PTC3_GPIO_FN               0     //!< PTC3 Pin multiplexor for GPIO
#define PTC3_ADC_NUM               0     //!< PTC3 ADC number
#define PTC3_ADC_CH                11    //!< PTC3 ADC channel
#define PTC3_ADC_FN                4     //!< PTC3 Pin multiplexor for ADC
#if FTM2_CH3_SEL == 1
#define PTC3_FTM_NUM               2     //!< PTC3 FTM number
#define PTC3_FTM_CH                3     //!< PTC3 FTM channel
#define PTC3_FTM_FN                2     //!< PTC3 Pin multiplexor for FTM
#endif

// PTC4 = GPIOA_20,FTM1_CH0
#define PTC4_GPIO_NAME             A     //!< PTC4 GPIO name
#define PTC4_GPIO_BIT              20    //!< PTC4 GPIO bit number
#define PTC4_GPIO_FN               0     //!< PTC4 Pin multiplexor for GPIO
#if FTM1_CH0_SEL == 1
#define PTC4_FTM_NUM               1     //!< PTC4 FTM number
#define PTC4_FTM_CH                0     //!< PTC4 FTM channel
#define PTC4_FTM_FN                3     //!< PTC4 Pin multiplexor for FTM
#endif

// PTC5 = GPIOA_21,FTM1_CH1
#define PTC5_GPIO_NAME             A     //!< PTC5 GPIO name
#define PTC5_GPIO_BIT              21    //!< PTC5 GPIO bit number
#define PTC5_GPIO_FN               0     //!< PTC5 Pin multiplexor for GPIO
#if FTM1_CH1_SEL == 1
#define PTC5_FTM_NUM               1     //!< PTC5 FTM number
#define PTC5_FTM_CH                1     //!< PTC5 FTM channel
#define PTC5_FTM_FN                3     //!< PTC5 Pin multiplexor for FTM
#endif

// PTC6 = GPIOA_22
#define PTC6_GPIO_NAME             A     //!< PTC6 GPIO name
#define PTC6_GPIO_BIT              22    //!< PTC6 GPIO bit number
#define PTC6_GPIO_FN               0     //!< PTC6 Pin multiplexor for GPIO

// PTC7 = GPIOA_23
#define PTC7_GPIO_NAME             A     //!< PTC7 GPIO name
#define PTC7_GPIO_BIT              23    //!< PTC7 GPIO bit number
#define PTC7_GPIO_FN               0     //!< PTC7 Pin multiplexor for GPIO

// PTD0 = GPIOA_24,FTM2_CH2,SPI1_SCK
#define PTD0_GPIO_NAME             A     //!< PTD0 GPIO name
#define PTD0_GPIO_BIT              24    //!< PTD0 GPIO bit number
#define PTD0_GPIO_FN               0     //!< PTD0 Pin multiplexor for GPIO
#if FTM2_CH2_SEL == 2
#define PTD0_FTM_NUM               2     //!< PTD0 FTM number
#define PTD0_FTM_CH                2     //!< PTD0 FTM channel
#define PTD0_FTM_FN                2     //!< PTD0 Pin multiplexor for FTM
#endif
#if SPI1_SCK_SEL == 1
#define SPI1_SCK_FN                3     //!< PTD0 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTD0   //!< PTD0 SPI GPIO
#endif

// PTD1 = GPIOA_25,FTM2_CH3,SPI1_MOSI
#define PTD1_GPIO_NAME             A     //!< PTD1 GPIO name
#define PTD1_GPIO_BIT              25    //!< PTD1 GPIO bit number
#define PTD1_GPIO_FN               0     //!< PTD1 Pin multiplexor for GPIO
#if FTM2_CH3_SEL == 2
#define PTD1_FTM_NUM               2     //!< PTD1 FTM number
#define PTD1_FTM_CH                3     //!< PTD1 FTM channel
#define PTD1_FTM_FN                2     //!< PTD1 Pin multiplexor for FTM
#endif
#if SPI1_MOSI_SEL == 1
#define SPI1_MOSI_FN               3     //!< PTD1 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTD1   //!< PTD1 SPI GPIO
#endif

// PTD2 = GPIOA_26,SPI1_MISO
#define PTD2_GPIO_NAME             A     //!< PTD2 GPIO name
#define PTD2_GPIO_BIT              26    //!< PTD2 GPIO bit number
#define PTD2_GPIO_FN               0     //!< PTD2 Pin multiplexor for GPIO
#if SPI1_MISO_SEL == 1
#define SPI1_MISO_FN               2     //!< PTD2 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTD2   //!< PTD2 SPI GPIO
#endif

// PTD3 = GPIOA_27,SPI1_PCS
#define PTD3_GPIO_NAME             A     //!< PTD3 GPIO name
#define PTD3_GPIO_BIT              27    //!< PTD3 GPIO bit number
#define PTD3_GPIO_FN               0     //!< PTD3 Pin multiplexor for GPIO
#if SPI1_PCS_SEL == 1
#define SPI1_PCS_FN                2     //!< PTD3 Pin multiplexor for SPI
#define SPI1_PCS_GPIO              digitalIO_PTD3   //!< PTD3 SPI GPIO
#endif

// PTD4 = GPIOA_28
#define PTD4_GPIO_NAME             A     //!< PTD4 GPIO name
#define PTD4_GPIO_BIT              28    //!< PTD4 GPIO bit number
#define PTD4_GPIO_FN               0     //!< PTD4 Pin multiplexor for GPIO

// PTD5 = GPIOA_29
#define PTD5_GPIO_NAME             A     //!< PTD5 GPIO name
#define PTD5_GPIO_BIT              29    //!< PTD5 GPIO bit number
#define PTD5_GPIO_FN               0     //!< PTD5 Pin multiplexor for GPIO

// PTD6 = GPIOA_30
#define PTD6_GPIO_NAME             A     //!< PTD6 GPIO name
#define PTD6_GPIO_BIT              30    //!< PTD6 GPIO bit number
#define PTD6_GPIO_FN               0     //!< PTD6 Pin multiplexor for GPIO

// PTD7 = GPIOA_31
#define PTD7_GPIO_NAME             A     //!< PTD7 GPIO name
#define PTD7_GPIO_BIT              31    //!< PTD7 GPIO bit number
#define PTD7_GPIO_FN               0     //!< PTD7 Pin multiplexor for GPIO

// PTE0 = GPIOB_0,SPI0_SCK,I2C1_SDA
#define PTE0_GPIO_NAME             B     //!< PTE0 GPIO name
#define PTE0_GPIO_BIT              0     //!< PTE0 GPIO bit number
#define PTE0_GPIO_FN               0     //!< PTE0 Pin multiplexor for GPIO
#if SPI0_SCK_SEL == 2
#define SPI0_SCK_FN                2     //!< PTE0 Pin multiplexor for SPI
#define SPI0_SCK_GPIO              digitalIO_PTE0   //!< PTE0 SPI GPIO
#endif
#if I2C1_SDA_SEL == 1
#define I2C1_SDA_FN                4     //!< PTE0 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTE0   //!< PTE0 I2C GPIO
#endif

// PTE1 = GPIOB_1,SPI0_MOSI,I2C1_SCL
#define PTE1_GPIO_NAME             B     //!< PTE1 GPIO name
#define PTE1_GPIO_BIT              1     //!< PTE1 GPIO bit number
#define PTE1_GPIO_FN               0     //!< PTE1 Pin multiplexor for GPIO
#if SPI0_MOSI_SEL == 2
#define SPI0_MOSI_FN               2     //!< PTE1 Pin multiplexor for SPI
#define SPI0_MOSI_GPIO             digitalIO_PTE1   //!< PTE1 SPI GPIO
#endif
#if I2C1_SCL_SEL == 1
#define I2C1_SCL_FN                4     //!< PTE1 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTE1   //!< PTE1 I2C GPIO
#endif

// PTE2 = GPIOB_2,SPI0_MISO
#define PTE2_GPIO_NAME             B     //!< PTE2 GPIO name
#define PTE2_GPIO_BIT              2     //!< PTE2 GPIO bit number
#define PTE2_GPIO_FN               0     //!< PTE2 Pin multiplexor for GPIO
#if SPI0_MISO_SEL == 2
#define SPI0_MISO_FN               2     //!< PTE2 Pin multiplexor for SPI
#define SPI0_MISO_GPIO             digitalIO_PTE2   //!< PTE2 SPI GPIO
#endif

// PTE3 = GPIOB_3,SPI0_PCS
#define PTE3_GPIO_NAME             B     //!< PTE3 GPIO name
#define PTE3_GPIO_BIT              3     //!< PTE3 GPIO bit number
#define PTE3_GPIO_FN               0     //!< PTE3 Pin multiplexor for GPIO
#if SPI0_PCS_SEL == 2
#define SPI0_PCS_FN                2     //!< PTE3 Pin multiplexor for SPI
#define SPI0_PCS_GPIO              digitalIO_PTE3   //!< PTE3 SPI GPIO
#endif

// PTE4 = GPIOB_4
#define PTE4_GPIO_NAME             B     //!< PTE4 GPIO name
#define PTE4_GPIO_BIT              4     //!< PTE4 GPIO bit number
#define PTE4_GPIO_FN               0     //!< PTE4 Pin multiplexor for GPIO

// PTE5 = GPIOB_5
#define PTE5_GPIO_NAME             B     //!< PTE5 GPIO name
#define PTE5_GPIO_BIT              5     //!< PTE5 GPIO bit number
#define PTE5_GPIO_FN               0     //!< PTE5 Pin multiplexor for GPIO

// PTE6 = GPIOB_6
#define PTE6_GPIO_NAME             B     //!< PTE6 GPIO name
#define PTE6_GPIO_BIT              6     //!< PTE6 GPIO bit number
#define PTE6_GPIO_FN               0     //!< PTE6 Pin multiplexor for GPIO

// PTE7 = GPIOB_7,FTM1_CH1
#define PTE7_GPIO_NAME             B     //!< PTE7 GPIO name
#define PTE7_GPIO_BIT              7     //!< PTE7 GPIO bit number
#define PTE7_GPIO_FN               0     //!< PTE7 Pin multiplexor for GPIO
#if FTM1_CH1_SEL == 2
#define PTE7_FTM_NUM               1     //!< PTE7 FTM number
#define PTE7_FTM_CH                1     //!< PTE7 FTM channel
#define PTE7_FTM_FN                4     //!< PTE7 Pin multiplexor for FTM
#endif

// PTF0 = GPIOB_8,FTM2_CH0
#define PTF0_GPIO_NAME             B     //!< PTF0 GPIO name
#define PTF0_GPIO_BIT              8     //!< PTF0 GPIO bit number
#define PTF0_GPIO_FN               0     //!< PTF0 Pin multiplexor for GPIO
#if FTM2_CH0_SEL == 2
#define PTF0_FTM_NUM               2     //!< PTF0 FTM number
#define PTF0_FTM_CH                0     //!< PTF0 FTM channel
#define PTF0_FTM_FN                2     //!< PTF0 Pin multiplexor for FTM
#endif

// PTF1 = GPIOB_9,FTM2_CH1
#define PTF1_GPIO_NAME             B     //!< PTF1 GPIO name
#define PTF1_GPIO_BIT              9     //!< PTF1 GPIO bit number
#define PTF1_GPIO_FN               0     //!< PTF1 Pin multiplexor for GPIO
#if FTM2_CH1_SEL == 2
#define PTF1_FTM_NUM               2     //!< PTF1 FTM number
#define PTF1_FTM_CH                1     //!< PTF1 FTM channel
#define PTF1_FTM_FN                2     //!< PTF1 Pin multiplexor for FTM
#endif

// PTF2 = GPIOB_10
#define PTF2_GPIO_NAME             B     //!< PTF2 GPIO name
#define PTF2_GPIO_BIT              10    //!< PTF2 GPIO bit number
#define PTF2_GPIO_FN               0     //!< PTF2 Pin multiplexor for GPIO

// PTF3 = GPIOB_11
#define PTF3_GPIO_NAME             B     //!< PTF3 GPIO name
#define PTF3_GPIO_BIT              11    //!< PTF3 GPIO bit number
#define PTF3_GPIO_FN               0     //!< PTF3 Pin multiplexor for GPIO

// PTF4 = GPIOB_12,ADC0_SE12
#define PTF4_GPIO_NAME             B     //!< PTF4 GPIO name
#define PTF4_GPIO_BIT              12    //!< PTF4 GPIO bit number
#define PTF4_GPIO_FN               0     //!< PTF4 Pin multiplexor for GPIO
#define PTF4_ADC_NUM               0     //!< PTF4 ADC number
#define PTF4_ADC_CH                12    //!< PTF4 ADC channel
#define PTF4_ADC_FN                4     //!< PTF4 Pin multiplexor for ADC

// PTF5 = GPIOB_13,ADC0_SE13
#define PTF5_GPIO_NAME             B     //!< PTF5 GPIO name
#define PTF5_GPIO_BIT              13    //!< PTF5 GPIO bit number
#define PTF5_GPIO_FN               0     //!< PTF5 Pin multiplexor for GPIO
#define PTF5_ADC_NUM               0     //!< PTF5 ADC number
#define PTF5_ADC_CH                13    //!< PTF5 ADC channel
#define PTF5_ADC_FN                4     //!< PTF5 Pin multiplexor for ADC

// PTF6 = GPIOB_14,ADC0_SE14
#define PTF6_GPIO_NAME             B     //!< PTF6 GPIO name
#define PTF6_GPIO_BIT              14    //!< PTF6 GPIO bit number
#define PTF6_GPIO_FN               0     //!< PTF6 Pin multiplexor for GPIO
#define PTF6_ADC_NUM               0     //!< PTF6 ADC number
#define PTF6_ADC_CH                14    //!< PTF6 ADC channel
#define PTF6_ADC_FN                4     //!< PTF6 Pin multiplexor for ADC

// PTF7 = GPIOB_15,ADC0_SE15
#define PTF7_GPIO_NAME             B     //!< PTF7 GPIO name
#define PTF7_GPIO_BIT              15    //!< PTF7 GPIO bit number
#define PTF7_GPIO_FN               0     //!< PTF7 Pin multiplexor for GPIO
#define PTF7_ADC_NUM               0     //!< PTF7 ADC number
#define PTF7_ADC_CH                15    //!< PTF7 ADC channel
#define PTF7_ADC_FN                4     //!< PTF7 Pin multiplexor for ADC

// PTG0 = GPIOB_16
#define PTG0_GPIO_NAME             B     //!< PTG0 GPIO name
#define PTG0_GPIO_BIT              16    //!< PTG0 GPIO bit number
#define PTG0_GPIO_FN               0     //!< PTG0 Pin multiplexor for GPIO

// PTG1 = GPIOB_17
#define PTG1_GPIO_NAME             B     //!< PTG1 GPIO name
#define PTG1_GPIO_BIT              17    //!< PTG1 GPIO bit number
#define PTG1_GPIO_FN               0     //!< PTG1 Pin multiplexor for GPIO

// PTG2 = GPIOB_18
#define PTG2_GPIO_NAME             B     //!< PTG2 GPIO name
#define PTG2_GPIO_BIT              18    //!< PTG2 GPIO bit number
#define PTG2_GPIO_FN               0     //!< PTG2 Pin multiplexor for GPIO

// PTG3 = GPIOB_19
#define PTG3_GPIO_NAME             B     //!< PTG3 GPIO name
#define PTG3_GPIO_BIT              19    //!< PTG3 GPIO bit number
#define PTG3_GPIO_FN               0     //!< PTG3 Pin multiplexor for GPIO

// PTG4 = GPIOB_20,FTM2_CH2,SPI1_SCK
#define PTG4_GPIO_NAME             B     //!< PTG4 GPIO name
#define PTG4_GPIO_BIT              20    //!< PTG4 GPIO bit number
#define PTG4_GPIO_FN               0     //!< PTG4 Pin multiplexor for GPIO
#if FTM2_CH2_SEL == 3
#define PTG4_FTM_NUM               2     //!< PTG4 FTM number
#define PTG4_FTM_CH                2     //!< PTG4 FTM channel
#define PTG4_FTM_FN                2     //!< PTG4 Pin multiplexor for FTM
#endif
#if SPI1_SCK_SEL == 2
#define SPI1_SCK_FN                3     //!< PTG4 Pin multiplexor for SPI
#define SPI1_SCK_GPIO              digitalIO_PTG4   //!< PTG4 SPI GPIO
#endif

// PTG5 = GPIOB_21,FTM2_CH3,SPI1_MOSI
#define PTG5_GPIO_NAME             B     //!< PTG5 GPIO name
#define PTG5_GPIO_BIT              21    //!< PTG5 GPIO bit number
#define PTG5_GPIO_FN               0     //!< PTG5 Pin multiplexor for GPIO
#if FTM2_CH3_SEL == 3
#define PTG5_FTM_NUM               2     //!< PTG5 FTM number
#define PTG5_FTM_CH                3     //!< PTG5 FTM channel
#define PTG5_FTM_FN                2     //!< PTG5 Pin multiplexor for FTM
#endif
#if SPI1_MOSI_SEL == 2
#define SPI1_MOSI_FN               3     //!< PTG5 Pin multiplexor for SPI
#define SPI1_MOSI_GPIO             digitalIO_PTG5   //!< PTG5 SPI GPIO
#endif

// PTG6 = GPIOB_22,FTM2_CH4,SPI1_MISO
#define PTG6_GPIO_NAME             B     //!< PTG6 GPIO name
#define PTG6_GPIO_BIT              22    //!< PTG6 GPIO bit number
#define PTG6_GPIO_FN               0     //!< PTG6 Pin multiplexor for GPIO
#if FTM2_CH4_SEL == 2
#define PTG6_FTM_NUM               2     //!< PTG6 FTM number
#define PTG6_FTM_CH                4     //!< PTG6 FTM channel
#define PTG6_FTM_FN                2     //!< PTG6 Pin multiplexor for FTM
#endif
#if SPI1_MISO_SEL == 2
#define SPI1_MISO_FN               3     //!< PTG6 Pin multiplexor for SPI
#define SPI1_MISO_GPIO             digitalIO_PTG6   //!< PTG6 SPI GPIO
#endif

// PTG7 = GPIOB_23,FTM2_CH5,SPI1_PCS
#define PTG7_GPIO_NAME             B     //!< PTG7 GPIO name
#define PTG7_GPIO_BIT              23    //!< PTG7 GPIO bit number
#define PTG7_GPIO_FN               0     //!< PTG7 Pin multiplexor for GPIO
#if FTM2_CH5_SEL == 2
#define PTG7_FTM_NUM               2     //!< PTG7 FTM number
#define PTG7_FTM_CH                5     //!< PTG7 FTM channel
#define PTG7_FTM_FN                2     //!< PTG7 Pin multiplexor for FTM
#endif
#if SPI1_PCS_SEL == 2
#define SPI1_PCS_FN                3     //!< PTG7 Pin multiplexor for SPI
#define SPI1_PCS_GPIO              digitalIO_PTG7   //!< PTG7 SPI GPIO
#endif

// PTH0 = GPIOB_24,FTM2_CH0
#define PTH0_GPIO_NAME             B     //!< PTH0 GPIO name
#define PTH0_GPIO_BIT              24    //!< PTH0 GPIO bit number
#define PTH0_GPIO_FN               0     //!< PTH0 Pin multiplexor for GPIO
#if FTM2_CH0_SEL == 3
#define PTH0_FTM_NUM               2     //!< PTH0 FTM number
#define PTH0_FTM_CH                0     //!< PTH0 FTM channel
#define PTH0_FTM_FN                2     //!< PTH0 Pin multiplexor for FTM
#endif

// PTH1 = GPIOB_25,FTM2_CH1
#define PTH1_GPIO_NAME             B     //!< PTH1 GPIO name
#define PTH1_GPIO_BIT              25    //!< PTH1 GPIO bit number
#define PTH1_GPIO_FN               0     //!< PTH1 Pin multiplexor for GPIO
#if FTM2_CH1_SEL == 3
#define PTH1_FTM_NUM               2     //!< PTH1 FTM number
#define PTH1_FTM_CH                1     //!< PTH1 FTM channel
#define PTH1_FTM_FN                2     //!< PTH1 Pin multiplexor for FTM
#endif

// PTH2 = GPIOB_26,FTM1_CH0
#define PTH2_GPIO_NAME             B     //!< PTH2 GPIO name
#define PTH2_GPIO_BIT              26    //!< PTH2 GPIO bit number
#define PTH2_GPIO_FN               0     //!< PTH2 Pin multiplexor for GPIO
#if FTM1_CH0_SEL == 2
#define PTH2_FTM_NUM               1     //!< PTH2 FTM number
#define PTH2_FTM_CH                0     //!< PTH2 FTM channel
#define PTH2_FTM_FN                4     //!< PTH2 Pin multiplexor for FTM
#endif

// PTH3 = GPIOB_27,I2C1_SDA
#define PTH3_GPIO_NAME             B     //!< PTH3 GPIO name
#define PTH3_GPIO_BIT              27    //!< PTH3 GPIO bit number
#define PTH3_GPIO_FN               0     //!< PTH3 Pin multiplexor for GPIO
#if I2C1_SDA_SEL == 2
#define I2C1_SDA_FN                2     //!< PTH3 Pin multiplexor for I2C
#define I2C1_SDA_GPIO              digitalIO_PTH3   //!< PTH3 I2C GPIO
#endif

// PTH4 = GPIOB_28,I2C1_SCL
#define PTH4_GPIO_NAME             B     //!< PTH4 GPIO name
#define PTH4_GPIO_BIT              28    //!< PTH4 GPIO bit number
#define PTH4_GPIO_FN               0     //!< PTH4 Pin multiplexor for GPIO
#if I2C1_SCL_SEL == 2
#define I2C1_SCL_FN                2     //!< PTH4 Pin multiplexor for I2C
#define I2C1_SCL_GPIO              digitalIO_PTH4   //!< PTH4 I2C GPIO
#endif

// PTH5 = GPIOB_29
#define PTH5_GPIO_NAME             B     //!< PTH5 GPIO name
#define PTH5_GPIO_BIT              29    //!< PTH5 GPIO bit number
#define PTH5_GPIO_FN               0     //!< PTH5 Pin multiplexor for GPIO

// PTH6 = GPIOB_30
#define PTH6_GPIO_NAME             B     //!< PTH6 GPIO name
#define PTH6_GPIO_BIT              30    //!< PTH6 GPIO bit number
#define PTH6_GPIO_FN               0     //!< PTH6 Pin multiplexor for GPIO

// PTH7 = GPIOB_31
#define PTH7_GPIO_NAME             B     //!< PTH7 GPIO name
#define PTH7_GPIO_BIT              31    //!< PTH7 GPIO bit number
#define PTH7_GPIO_FN               0     //!< PTH7 Pin multiplexor for GPIO

// PTI0 = GPIOC_0
#define PTI0_GPIO_NAME             C     //!< PTI0 GPIO name
#define PTI0_GPIO_BIT              0     //!< PTI0 GPIO bit number
#define PTI0_GPIO_FN               0     //!< PTI0 Pin multiplexor for GPIO

// PTI1 = GPIOC_1
#define PTI1_GPIO_NAME             C     //!< PTI1 GPIO name
#define PTI1_GPIO_BIT              1     //!< PTI1 GPIO bit number
#define PTI1_GPIO_FN               0     //!< PTI1 Pin multiplexor for GPIO

// PTI2 = GPIOC_2
#define PTI2_GPIO_NAME             C     //!< PTI2 GPIO name
#define PTI2_GPIO_BIT              2     //!< PTI2 GPIO bit number
#define PTI2_GPIO_FN               0     //!< PTI2 Pin multiplexor for GPIO

// PTI3 = GPIOC_3
#define PTI3_GPIO_NAME             C     //!< PTI3 GPIO name
#define PTI3_GPIO_BIT              3     //!< PTI3 GPIO bit number
#define PTI3_GPIO_FN               0     //!< PTI3 Pin multiplexor for GPIO

// PTI4 = GPIOC_4
#define PTI4_GPIO_NAME             C     //!< PTI4 GPIO name
#define PTI4_GPIO_BIT              4     //!< PTI4 GPIO bit number
#define PTI4_GPIO_FN               0     //!< PTI4 Pin multiplexor for GPIO

// PTI5 = GPIOC_5
#define PTI5_GPIO_NAME             C     //!< PTI5 GPIO name
#define PTI5_GPIO_BIT              5     //!< PTI5 GPIO bit number
#define PTI5_GPIO_FN               0     //!< PTI5 Pin multiplexor for GPIO

// PTI6 = GPIOC_6
#define PTI6_GPIO_NAME             C     //!< PTI6 GPIO name
#define PTI6_GPIO_BIT              6     //!< PTI6 GPIO bit number
#define PTI6_GPIO_FN               0     //!< PTI6 Pin multiplexor for GPIO

#define ADC_FN_CHANGES      //!< Indicates ADC Multiplexing varies with pin
#define GPIO_FN_CHANGES     //!< Indicates GPIO Multiplexing varies with pin
#define DEFAULT_PORT_CLOCK_REG  SIM->SCGC5 //!< Fixed PORT Clock varies with port

#endif /* PIN_MAPPING_H_ */
