/*
 * Freedom.h
 *
 *  Created on: 28/05/2013
 *      Author: Peter
 */

#ifndef FREEDOM_H_
#define FREEDOM_H_

#include "utilities.h"

#ifdef MCU_mcf51jf128
//=================================================================================
// LED Port bit masks
//
#define LED_ORANGE_PORT      C
#define LED_ORANGE_NUM       8

#define LED_GREEN_PORT       C
#define LED_GREEN_NUM        9

//=================================================================================
// UART Port bit masks
//
// D6, MXC_PTDPF1, FN=2
#define UART0_RX_PIN_PORT      D   // Port name
#define UART0_RX_PIN_NUM       6   // Bit on port
#define UART0_RX_MUX_NUM       1   // Mux reg # (4-(pin/2))
#define UART0_RX_PIN_FN        2   // Mux function number

#define UART0_TX_PIN_PORT      A
#define UART0_TX_PIN_NUM       7
#define UART0_TX_MUX_NUM       1
#define UART0_TX_PIN_FN        2
#endif

#if defined(MCU_MKM33Z5)
//=================================================================================
// LED Port bit masks
//
#define LED_RED_PORT         A   // A0
#define LED_RED_NUM          0

#define LED_GREEN_PORT       A   // A1
#define LED_GREEN_NUM        1

#endif

#if defined(MCU_MKE02Z2) || defined(MCU_MKE02Z4)
//=================================================================================
// LED Port bit masks
//
#define LED_RED_PORT         B   // H1
#define LED_RED_NUM          25

#define LED_GREEN_PORT       B   // H2
#define LED_GREEN_NUM        26

#define LED_BLUE_PORT        B   // E7
#define LED_BLUE_NUM         7
#endif

#if defined(MCU_MKE04Z8M4)
//=================================================================================
// LED Port bit masks
//
#define LED_RED_PORT         A   // C5
#define LED_RED_NUM          21

#define LED_GREEN_PORT       A   // C4
#define LED_GREEN_NUM        20

#define LED_BLUE_PORT        A   // B3
#define LED_BLUE_NUM         11
#endif

#if defined(MCU_MKE06Z4)
//=================================================================================
// LED Port bit masks
//
#define LED_RED_PORT         B   // G5
#define LED_RED_NUM          21

#define LED_GREEN_PORT       B   // G6
#define LED_GREEN_NUM        22

#define LED_BLUE_PORT        B   // G7
#define LED_BLUE_NUM         23
#endif

#if defined(MCU_MKL02Z4)
//=================================================================================
// LED Port bit masks
//
#define LED_GREEN_PORT       B
#define LED_GREEN_NUM        7

#define LED_RED_PORT         B
#define LED_RED_NUM          6

#define LED_BLUE_PORT        B
#define LED_BLUE_NUM         10
#endif

#if defined(MCU_MKL04Z4)
//=================================================================================
// UART Port bit masks
//
#define UART_RX_PIN_PORT      B
#define UART_RX_PIN_NUM       2
#define UART_RX_PIN_FN        2

#define UART_TX_PIN_PORT      B
#define UART_TX_PIN_NUM       1
#define UART_TX_PIN_FN        2
#endif

#if defined(MCU_MKL05Z4)
//=================================================================================
// LED Port bit masks
//
#define LED_GREEN_PORT         B
#define LED_GREEN_NUM          9

#define LED_RED_PORT           B
#define LED_RED_NUM            8

#define LED_BLUE_PORT          B
#define LED_BLUE_NUM           10
#endif

#if defined(MCU_MKL25Z4)
//=================================================================================
// LED Port bit masks
//

// PTB19(Fn3) = TPM2_CH1
#define LED_GREEN_PORT              B
#define LED_GREEN_NUM              19
#define LED_GREEN_FTM_FN            3
#define LED_GREEN_FTM_CHANNEL       1

// PTDB18(Fn3) = TPM2_CH0
#define LED_RED_PORT                B
#define LED_RED_NUM                18
#define LED_RED_FTM_FN              3
#define LED_RED_FTM_CHANNEL         0

// PTD1(Fn4) = TPM0_CH1
#define LED_BLUE_PORT               D
#define LED_BLUE_NUM                1
#define LED_BLUE_FTM_FN             4
#define LED_BLUE_FTM_CHANNEL        1

// Elec freaks LCD Shield buttons
#define NORTH_SWITCH_PORT           B    // North
#define NORTH_SWITCH_NUM            0
#define EAST_SWITCH_PORT            B    // East
#define EAST_SWITCH_NUM             1
#define SOUTH_SWITCH_PORT           B    // South
#define SOUTH_SWITCH_NUM            2
#define CENTRE_SWITCH_PORT          B    // Centre
#define CENTRE_SWITCH_NUM           3
#define WEST_SWITCH_PORT            C    // West
#define WEST_SWITCH_NUM             2

//=================================================================================
// I2C0  pins
//
// PTE24(Fn5) = SCL (PTB0(Fn2), PTB2(Fn2), PTC8(Fn2))
#define I2C0_SCL_PORT         E  // Accelerometer
#define I2C0_SCL_PIN_NUM      24
#define I2C0_SCL_FN           5

// PTE25(Fn5) = SDA (PTB1(Fn2), PTB3(Fn2), PTC9(Fn2))
#define I2C0_SDA_PORT         E
#define I2C0_SDA_PIN_NUM      25
#define I2C0_SDA_FN           5

//=================================================================================
// I2C1  pins
//
// Arduino                D15                   A5
// I2C1_SCL = PTE1(Fn6), PTE1(Fn6), PTA3(Fn2), PTC1(Fn2), PTC10(Fn2)
#define I2C1_SCL_PORT         C
#define I2C1_SCL_PIN_NUM      1
#define I2C1_SCL_FN           2

// Arduino                D14                   A4
// I2C1_SDA = PTE0(Fn6), PTE0(Fn6), PTA4(Fn2), PTC2(Fn2), PTC11(Fn2)
#define I2C1_SDA_PORT         C
#define I2C1_SDA_PIN_NUM      2
#define I2C1_SDA_FN           2

// SPI0 Pin definitions
//============================================================
// SPI data out pin                                      FRDM
#define SPI0_SIN_REG           D    // PTA17, PTC7, PTD3 (D12)
#define SPI0_SIN_NUM           3

// SPI data out pin
#define SPI0_SOUT_REG          D    // PTA16, PTC6, PTD2 (D11)
#define SPI0_SOUT_NUM          2

// SPI clock pin
#define SPI0_SCK_REG           D    // PTA15, PTC5, PTD1 (D13)
#define SPI0_SCK_NUM           1

// SPI CSn outputs
#define SPI0_PCS_REG           D    // PTA14, PTC4, PTD0 (D10)
#define SPI0_PCS_NUM           0

// Pin ALT function for SPI pins (SOUT,SCK,PCSn)
#define SPI0_ALT_FN            2

// SPI1 Pin definitions
//============================================================
// SPI data out pin         FRDM-ACCEL
#define SPI1_SIN_REG           E    // PTE3, PTB17, PTD7
#define SPI1_SIN_NUM           3

// SPI data out pin
#define SPI1_SOUT_REG          E    // PTE1, PTB16, PTD6
#define SPI1_SOUT_NUM          1

// SPI clock pin
#define SPI1_SCK_REG           E    // PTE2, PTB11, PTD5
#define SPI1_SCK_NUM           2

// SPI CSn outputs
#define SPI1_PCS_REG           E    // PTE4, PTB10, PTD4
#define SPI1_PCS_NUM           4

// Pin ALT function for SPI pins (SOUT,SCK,PCSn)
#define SPI1_ALT_FN            2

#endif

#if defined(MCU_MKL26Z4)
//=================================================================================
// LED Port bit masks
//
#define LED_GREEN_PORT         E
#define LED_GREEN_NUM         31

#define LED_RED_PORT           E
#define LED_RED_NUM           29

#define LED_BLUE_PORT          D
#define LED_BLUE_NUM          13
#endif

#if  defined(MCU_MKL14Z4) || defined(MCU_MKL15Z4) || defined(MCU_MKL16Z4) || defined(MCU_MKL24Z4) || defined(MCU_MKL34Z4) || defined(MCU_MKL36Z4)
#endif

#if defined(MCU_MKL46Z4)
//=================================================================================
// LED Port bit masks
//
#define LED_GREEN_PORT         D
#define LED_GREEN_NUM          5

#define LED_RED_PORT           E
#define LED_RED_NUM           29
#endif

#if defined(MCU_MK20D5) || defined(MCU_MK22F12)
//=================================================================================
// LED Port bit masks
//
// PTD4(Fn4) = FTM0_CH4
#define LED_GREEN_PORT         D
#define LED_GREEN_NUM          4
#define LED_GREEN_FTM_FN       4
#define LED_GREEN_FTM_CHANNEL  4

// PTC3(Fn4) = FTM0_CH2
#define LED_RED_PORT           C
#define LED_RED_NUM            3
#define LED_RED_FTM_FN         4
#define LED_RED_FTM_CHANNEL    2

// PTA2(Fn3) = FTM0_CH7
#define LED_BLUE_PORT          A
#define LED_BLUE_NUM           2
#define LED_BLUE_FTM_FN        3
#define LED_BLUE_FTM_CHANNEL   7

//=================================================================================
// I2C0 Port bit masks
//
// PTB0(Fn2) = SCL  (PTB2(Fn2))
#define I2C0_SCL_PORT         B
#define I2C0_SCL_PIN_NUM      0
#define I2C0_SCL_FN           2

// PTB1(Fn2) = SDA  (PTB3(Fn2))
#define I2C0_SDA_PORT         B
#define I2C0_SDA_PIN_NUM      1
#define I2C0_SDA_FN           2

// SPI0 Pin definitions
//============================================================
// SPI data out pin - PTC7(Fn2), PTD3(Fn2)
#define SPI0_SIN_REG           D
#define SPI0_SIN_NUM           3

// SPI data out pin - PTC6(Fn2), PTD2(Fn2)
#define SPI0_SOUT_REG          D
#define SPI0_SOUT_NUM          2

// SPI clock pin - PTC5(Fn2), PTD1(Fn2)
#define SPI0_SCK_REG           D
#define SPI0_SCK_NUM           1

// SPI CS0 outputs - PTD0(Fn2), PTC4(Fn2)
#define SPI0_PCS0_REG          C
#define SPI0_PCS0_NUM          4
// SPI CS1 outputs - PTD4(Fn2), PTC3(Fn2)
#define SPI0_PCS1_REG          C
#define SPI0_PCS1_NUM          3
// SPI CS2 outputs - PTD5(Fn2), PTC2(Fn2)
#define SPI0_PCS2_REG          C
#define SPI0_PCS2_NUM          2
// SPI CS3 outputs - PTD6(Fn2), PTC1(Fn2)
#define SPI0_PCS3_REG          C
#define SPI0_PCS3_NUM          1
// SPI CS4 outputs - PTD4(Fn2)
#define SPI0_PCS4_REG          C
#define SPI0_PCS4_NUM          0

// Pin ALT function for SPI pins (SOUT,SCK,PCSn)
#define SPI0_ALT_FN     2

//=================================================================================
// Elec freaks LCD Shield buttons
//
#define NORTH_SWITCH_PORT           B    // (A4) North
#define NORTH_SWITCH_NUM            1
#define EAST_SWITCH_PORT            C    // (A0) East
#define EAST_SWITCH_NUM             0
#define WEST_SWITCH_PORT            D    // (A2) West
#define WEST_SWITCH_NUM             6
#define SOUTH_SWITCH_PORT           C    // (A1) South
#define SOUTH_SWITCH_NUM            1
#define CENTRE_SWITCH_PORT          D    // (A3) Centre
#define CENTRE_SWITCH_NUM           5

//=================================================================================
// ADC Channel numbers
//
#define ADC_IN_LIGHT_SENSOR (adc_channel_dm0) // Note - No PCR
#define ADC_IN_TEMP_SENSOR  (adc_channel_dm3) // Note - No PCR
#endif

#if defined(MCU_MK22F51212)
//=================================================================================
// LED Port bit masks
//
// PTA2(Fn3) = GREEN_LED = PTA2/UART0_TX/FTM0_CH7
#define LED_GREEN_PORT         A
#define LED_GREEN_NUM          2
#define LED_GREEN_FTM_FN       3
#define LED_GREEN_FTM_CHANNEL  7

// PTA1(Fn2) = RED_LED = PTA1/UART0_RX/FTM0_CH6
#define LED_RED_PORT           A
#define LED_RED_NUM            1
#define LED_RED_FTM_FN         2
#define LED_RED_FTM_CHANNEL    6

// PTD5(Fn4) = BLUE_LED = PTD5/FTM0_CH5
#define LED_BLUE_PORT          D
#define LED_BLUE_NUM           5
#define LED_BLUE_FTM_FN        4
#define LED_BLUE_FTM_CHANNEL   5

//=================================================================================
// I2C0  pins
//
// Arduino A5 (PTB2) via R88
// I2C_SCL_FXOS8700CQ (PTB2) via R4
// I2C0_SCL = PTB0(Fn2), PTB2(Fn2), PTD2(Fn7)
#define I2C0_SCL_PORT         B
#define I2C0_SCL_PIN_NUM      2
#define I2C0_SCL_FN           2

// Arduino A4 (PTB3)  via R89
// I2C_SDA_FXOS8700CQ (PTB3) via R16
// I2C0_SDA = PTB1(Fn2), PTB3(Fn2), PTD7(Fn7)
#define I2C0_SDA_PORT         B
#define I2C0_SDA_PIN_NUM      3
#define I2C0_SDA_FN           2

//=================================================================================
// I2C1  pins
//
// Arduino  D15
// I2C1_SCL = PTE1(Fn6), PTC10(Fn2)
#define I2C1_SCL_PORT         E
#define I2C1_SCL_PIN_NUM      1
#define I2C1_SCL_FN           6

// Arduino  D14
// I2C0_SDA = PTE0(Fn6), PTC11(Fn2)
#define I2C1_SDA_PORT         E
#define I2C1_SDA_PIN_NUM      0
#define I2C1_SDA_FN           6

// SPI0 Pin definitions
//============================================================
// SPI0_SIN = PTC7(Fn2), PTD3(Fn2)(uSD_SPI_MISO, nRF24L01+)
#define SPI0_SIN_REG           D
#define SPI0_SIN_NUM           3

// SPI0_SOUT = PTC6(Fn2), PTD2(Fn2)(uSD_SPI_MOSI, nRF24L01+)
#define SPI0_SOUT_REG          D
#define SPI0_SOUT_NUM          2

// SPI0_SCK = PTC5(Fn2), PTD1(Fn2)(uSD_SPI_CLK, nRF24L01+)
#define SPI0_SCK_REG           D
#define SPI0_SCK_NUM           1

// SPI0_PCS0 = PTC4(Fn2)(uSD card CS), PTD0(Fn2)
#define SPI0_PCS0_REG          C
#define SPI0_PCS0_NUM          4
// SPI0_PCS1 = PTC3(Fn2), PTD4(Fn2)(nRF24L01+ CS)
#define SPI0_PCS1_REG          C
#define SPI0_PCS1_NUM          3
// SPI0_PCS2 = PTC2(Fn2), PTD5(Fn2)
#define SPI0_PCS2_REG          C
#define SPI0_PCS2_NUM          2
// SPI0_PCS3 = PTC1(Fn2), PTD6(Fn2)
#define SPI0_PCS3_REG          C
#define SPI0_PCS3_NUM          1
// SPI0_PCS4 = PTD4(Fn2)
#define SPI0_PCS4_REG          C
#define SPI0_PCS4_NUM          0

// SPI1 Pin definitions
//============================================================
// SPI1_SIN = PTD7(Fn2), PTE(Fn?), PTB17(Fn?)
#define SPI1_SIN_REG           D
#define SPI1_SIN_NUM           7

// SPI1_SOUT = PTD6(Fn2), PTE1(Fn?), PTB16(Fn?)
#define SPI1_SOUT_REG          D
#define SPI1_SOUT_NUM          6

// SPI1_SCK = PTD5(Fn2)
#define SPI1_SCK_REG           D
#define SPI1_SCK_NUM           5

//=================================================================================
// ADC Channel numbers
//
#define ADC_IN_LIGHT_SENSOR (adc_channel_dm1) // Note - No PCR

#endif

#if defined(MCU_MK10D7) || defined(MCU_MK22D5) || defined(MCU_MK20D7) || defined(MCU_MK22D7)
//=================================================================================
// LED Port bit masks
//
#define LED_RED_PORT        E
#define LED_RED_NUM         0

#define LED_GREEN_PORT      E
#define LED_GREEN_NUM       1
#endif

#if defined(MCU_MK40D10) || defined(MCU_MK40DZ10)
//=================================================================================
// LED Port bit masks
//
#define LED_RED_PORT         C
#define LED_RED_NUM          7

#define LED_ORANGE_PORT      C
#define LED_ORANGE_NUM       8

#define LED_GREEN_PORT       C
#define LED_GREEN_NUM        9

#define LED_BLUE_PORT        B
#define LED_BLUE_NUM        11
#endif

#if defined(MCU_MK60DZ10) || defined(MCU_MK60DZ10)
//=================================================================================
// LED Port bit masks
//
#define LED_RED_PORT         A
#define LED_RED_NUM         11

#define LED_ORANGE_PORT      A
#define LED_ORANGE_NUM      28

#define LED_GREEN_PORT       A
#define LED_GREEN_NUM       29

#define LED_BLUE_PORT        A
#define LED_BLUE_NUM        10
#endif

#if defined(MCU_MK10F12) || defined(MCU_MK60F12)
//=================================================================================
// LED Port bit masks
//
#define LED_RED_PORT         C
#define LED_RED_NUM          0

#define LED_GREEN_PORT       C
#define LED_GREEN_NUM        1

#endif

#if defined(MCU_MK64F12)
//=================================================================================
// LED Port bit masks
//
#define LED_RED_PORT         B
#define LED_RED_NUM          22

#define LED_GREEN_PORT       E
#define LED_GREEN_NUM        26

#define LED_BLUE_PORT        B
#define LED_BLUE_NUM         21

//=================================================================================
// I2C0 Port bit masks
//
// PTE24(Fn5) = SCL  (PTB0(Fn2), PTB2(Fn2), PTD2(Fn7), PTD8(Fn2))
#define I2C0_SCL_PORT         E
#define I2C0_SCL_PIN_NUM      24
#define I2C0_SCL_FN           5

// PTE25(Fn5) = SDA  (PTB1(Fn2), PTB3(Fn2), PTD3(Fn7), PTD9(Fn2))
#define I2C0_SDA_PORT         E
#define I2C0_SDA_PIN_NUM      25
#define I2C0_SDA_FN           5

//=================================================================================
// I2C1 Port bit masks
//
// PTC10(Fn2) = SCL  (PTE1(Fn6))
#define I2C1_SCL_PORT         C
#define I2C1_SCL_PIN_NUM      10
#define I2C1_SCL_FN           2

// PTC11(Fn2) = SDA  (PTE0(Fn6))
#define I2C1_SDA_PORT         C
#define I2C1_SDA_PIN_NUM      11
#define I2C1_SDA_FN           2

//=================================================================================
// I2C2 Port bit masks
//
// PTA12(Fn5) = SCL (PTA14(Fn5))
#define I2C2_SCL_PORT         A     // A
#define I2C2_SCL_PIN_NUM      12    // 14
#define I2C2_SCL_FN           5     // 5

// PTA11(Fn5) = SDA  (PTA13(Fn5))
#define I2C2_SDA_PORT         A     // A
#define I2C2_SDA_PIN_NUM      11    // 13
#define I2C2_SDA_FN           5     // 5

// SPI0 Pin definitions
//============================================================
// SPI data out pin
#define SPI0_SIN_REG           D
#define SPI0_SIN_NUM           3

// SPI data out pin
#define SPI0_SOUT_REG          D
#define SPI0_SOUT_NUM          2

// SPI clock pin
#define SPI0_SCK_REG           D
#define SPI0_SCK_NUM           1

// SPI CSn outputs
#define SPI0_PCS0_REG          C //
#define SPI0_PCS0_NUM          4
#define SPI0_PCS1_REG          C // or D4
#define SPI0_PCS1_NUM          3
#define SPI0_PCS2_REG          C // or D5
#define SPI0_PCS2_NUM          2
#define SPI0_PCS3_REG          C // or D6
#define SPI0_PCS3_NUM          1

// Pin ALT function for SPI pins (SOUT,SCK,PCSn)
#define SPI0_ALT_FN     7

// SPI1 Pin definitions
//============================================================
// SPI data out pin
#define SPI1_SIN_REG           D
#define SPI1_SIN_NUM           7

// SPI data out pin
#define SPI1_SOUT_REG          D
#define SPI1_SOUT_NUM          6

// SPI clock pin
#define SPI1_SCK_REG           D
#define SPI1_SCK_NUM           5

// SPI CSn outputs
#define SPI1_PCS0_REG          D
#define SPI1_PCS0_NUM          4
#define SPI1_PCS1_REG
#define SPI1_PCS1_NUM
#define SPI1_PCS2_REG
#define SPI1_PCS2_NUM
#define SPI1_PCS3_REG
#define SPI1_PCS3_NUM

// Pin ALT function for SPI pins (SOUT,SCK,PCSn)
#define SPI1_ALT_FN     7

//=================================================================================
// ADC Channel numbers
//
#define ADC_IN_LIGHT_SENSOR (adc_channel_dm0) // Note - No PCR
#define ADC_IN_TEMP_SENSOR  (adc_channel_dm3) // Note - No PCR
#endif

#endif /* FREEDOM_H_ */
