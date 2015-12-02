/*
 * pca9685.h
 *
 *  Created on: 24/06/2014
 *      Author: podonoghue
 */

#ifndef H_
#define H_

#include <stdint.h>
#include <stddef.h>
#include "i2c.h"

// Default address of first (only) motor board
#define PCA9685_DEFAULT_SLAVE_BASE_ADDRESS   ((uint8_t)(0x60<<1)) // PCA9685 Slave address

// Mode register 1, MODE1
#define PCA9685_MODE1_RESTART_MASK    (1<<7) // 0*/1 => Shows state of RESTART logic.
#define PCA9685_MODE1_EXTCLK_MASK     (1<<6) // 0*/1 => Use internal/EXTCLK pin clock.
#define PCA9685_MODE1_AI_MASK         (1<<5) // 0*/1 => Register Auto-Increment enable/disabled.
#define PCA9685_MODE1_SLEEP_MASK      (1<<4) // 0/1* => Low power mode on/off (Oscillator on/off)
#define PCA9685_MODE1_SUB1_MASK       (1<<3) // 0/1* => PCA9685 responds to I2C-bus sub-address 1.
#define PCA9685_MODE1_SUB2_MASK       (1<<2) // 0/1* => PCA9685 responds to I2C-bus sub-address 1.
#define PCA9685_MODE1_SUB3_MASK       (1<<1) // 0/1* => PCA9685 responds to I2C-bus sub-address 1.
#define PCA9685_MODE1_ALLCALL_MASK    (1<<0) // 0/1* => Does not/does respond to LED All Call I2C-bus address.

// Mode register 2, MODE2
#define PCA9685_MODE2_INVRT_MASK      (1<<4) // 0*   => Output logic state not inverted. Value to use when external driver used.
//                                           //         Applicable when OE = 0.
//                                           // 1    => Output logic state inverted. Value to use when no external driver used.
//                                           //         Applicable when OE = 0.
#define PCA9685_MODE2_OCH_MASK        (1<<3) // 0*   => Outputs change on STOP command.
//                                           // 1    => Outputs change on ACK.
#define PCA9685_MODE2_OUTDRV_MASK     (1<<2) // 0    => The 16 LEDn outputs are configured with an open-drain structure.
//                                           // 1*   => The 16 LEDn outputs are configured with a totem pole structure.
#define PCA9685_MODE2_OUTNE_MASK      (3<<0) // 00*  => When OE = 1 (output drivers not enabled), LEDn = 0.
//                                           // 01   => When OE = 1 (output drivers not enabled):
//                                           //         LEDn = 1 when OUTDRV = 1
//                                           //         LEDn = high-impedance when OUTDRV = 0 (same as OUTNE[1:0] = 10)
//                                           // 1X   => When OE = 1 (output drivers not enabled), LEDn = high-impedance.

// LEDx_ON_L
//             7:0 LEDx_ON count for LEDx, 8 LSBs
#define PCA9685_LEDx_ON_L_COUNT_MASK  (0xFF<<0)
// LEDx_ON_H
#define PCA9685_LEDx_ON_H_FULL_MASK   (1<<4)
#define PCA9685_LEDx_ON_H_COUNT_MASK  (0xF<<0)
//               4 LEDx full ON
//             3:0 LEDx_ON count for LEDx, 4 MSBs
// LEDx_OFF_L
#define PCA9685_LEDx_OFF_L_COUNT_MASK  (0xFF<<0)
//             7:0 LEDx_OFF count for LEDx, 8 LSBs
// LEDx_OFF_H
#define PCA9685_LEDx_OFF_H_FULL_MASK   (1<<4)
#define PCA9685_LEDx_OFF_H_COUNT_MASK  (0xF<<0)
//               4 LEDx full OFF
//             3:0 LEDx_OFF count for LEDx, 4 MSBs

// Default PWM oscillator parameters
#define PCA9685_OSC_CLOCK_FREQ (25000000UL)
#define PCA9685_PWM_FREQ       (200UL)
#define PCA9685_DEFAULT_OSC_PRESCALE   (((PCA9685_OSC_CLOCK_FREQ+2048UL*PCA9685_PWM_FREQ)/(4096UL*PCA9685_PWM_FREQ))-1)
#if ((PCA9685_OSC_PRESCALE & ~0xFFU) != 0)
#error "OSC_PRESCALE is too large"
#endif

// First Pin Control register
#define PCA9685_PIN_CONTROL_BASE        (0x06)   // READ/WRITE LED0  output and brightness control byte 0

// Calculates base register address for pin register set
#define PCA9685_PIN_REG(pinNum)  ((uint8_t)(PCA9685_PIN_CONTROL_BASE+4*(pinNum)))

class PCA9685 {

protected:
   I2C     *i2cInterface;
   uint8_t  slaveAddress;

   /*!
    * Constructor with default values
    *
    * @param i2cInterface  - The I2C interface to use
    * @param deviceAddress - Slave device address (PCA9685_DEFAULT_SLAVE_BASE_ADDRESS+0,1,2,3)
    * @param prescaleValue - Clock pre-scaler
    * @param mode1Value    - Mode 1 value (use PCA9685_MODE1_x macros)
    * @param mode2Value    - Mode 2 value (use PCA9685_MODE2_x macros)
    */
   PCA9685(I2C     *i2cInterface,
           uint8_t  deviceAddress = PCA9685_DEFAULT_SLAVE_BASE_ADDRESS,
           uint8_t  prescaleValue = PCA9685_DEFAULT_OSC_PRESCALE,
           uint8_t  mode1Value    = PCA9685_MODE1_AI_MASK,
           uint8_t  mode2Value    = PCA9685_MODE2_OUTDRV_MASK
           );

   static const int MAX_PWM = 4095;  // Maximum duty cycle value MAX_PWM = 100%

   void allLow(void);
   void allHigh(void);
   void set_pin_pwm(unsigned pinNum, unsigned dutyCycle);
   void set_pin_high(unsigned pinNum);
   void set_pin_low(unsigned pinNum);
};

#endif /* H_ */
