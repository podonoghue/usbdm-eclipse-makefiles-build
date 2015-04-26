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
#define UART0_RX_PIN_FN        2   // Mux function number
#define UART0_RX_MUX_NUM       1   // Mux reg # (4-(pin/2))

#define UART0_TX_PIN_PORT      A
#define UART0_TX_PIN_NUM       7
#define UART0_TX_PIN_FN        2
#define UART0_TX_MUX_NUM       1
#endif

#ifdef MCU_mcf51ju128
//=================================================================================
// LED Port bit masks
//
#define LED_ORANGE_PORT      A
#define LED_ORANGE_NUM       0

#define LED_GREEN_PORT       A
#define LED_GREEN_NUM        1

//=================================================================================
// UART Port bit masks
//
// D6, MXC_PTDPF1, FN=2
#define UART0_RX_PIN_PORT      C   // Port name
#define UART0_RX_PIN_NUM       7   // Bit on port
#define UART0_RX_PIN_FN        2   // Mux function number
#define UART0_RX_MUX_NUM       1   // Mux reg # (4-(pin/2))

#define UART0_TX_PIN_PORT      C
#define UART0_TX_PIN_NUM       6
#define UART0_TX_PIN_FN        2
#define UART0_TX_MUX_NUM       1
#endif

#if defined(MCU_MKE02Z2)
//=================================================================================
// LED Port bit masks
//
#define LED_RED_PORT         H
#define LED_RED_NUM          1

#define LED_GREEN_PORT       H
#define LED_GREEN_NUM        2

#define LED_BLUE_PORT        E
#define LED_BLUE_NUM         7
#endif

#if defined(MCU_MKL02Z4)
//=================================================================================
// LED Port bit masks
//
#define LED_GREEN_PORT         B
#define LED_GREEN_NUM          7

#define LED_RED_PORT           B
#define LED_RED_NUM            6

#define LED_BLUE_PORT          B
#define LED_BLUE_NUM           10
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
#define LED_BLUE_NUM          10
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
// I2C  pins
//
// PTE24(Fn5) = SCL
#define I2C_SCL_PORT         E
#define I2C_SCL_PIN_NUM      24
#define I2C_SCL_FN           5
#define I2C_SCL_CLOCK_MASK   SIM_SCGC5_PORTE_MASK

// PTE25(Fn5) = SDA
#define I2C_SDA_PORT         E
#define I2C_SDA_PIN_NUM      25
#define I2C_SDA_FN           5
#define I2C_SDA_CLOCK_MASK   SIM_SCGC5_PORTE_MASK
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

#if defined(MCU_MK20D5)
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
// I2C Port bit masks
//
// PTB0(Fn2) = SCL
#define I2C_SCL_PORT         B
#define I2C_SCL_PIN_NUM      0
#define I2C_SCL_FN           2
#define I2C_SCL_CLOCK_MASK   SIM_SCGC5_PORTB_MASK

// PTB1(Fn2) = SDA
#define I2C_SDA_PORT         B
#define I2C_SDA_PIN_NUM      1
#define I2C_SDA_FN           2
#define I2C_SDA_CLOCK_MASK   SIM_SCGC5_PORTB_MASK

//=================================================================================
// Elec freaks LCD Shield buttons
//
#define NORTH_SWITCH_PORT          C    // (A0) North
#define NORTH_SWITCH_NUM           0
#define EAST_SWITCH_PORT           C    // (A1) East
#define EAST_SWITCH_NUM            1
#define SOUTH_SWITCH_PORT          D    // (A2) South
#define SOUTH_SWITCH_NUM           6
#define CENTRE_SWITCH_PORT         D    // (A3) Centre
#define CENTRE_SWITCH_NUM          5
#define WEST_SWITCH_PORT           B    // (A4) West
#define WEST_SWITCH_NUM            1

//=================================================================================
// ADC Channel numbers
//
#define ADC_IN_LIGHT_SENSOR (adc_channel_dm0) // Note - No PCR
#define ADC_IN_TEMP_SENSOR  (adc_channel_dm3) // Note - No PCR
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

#endif /* FREEDOM_H_ */
