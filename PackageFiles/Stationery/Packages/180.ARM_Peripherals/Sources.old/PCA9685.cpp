/*
 ============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : Basic C Main
 ============================================================================
 */
#include "derivative.h"
#include "utilities.h"
#include "I2C.h"
#include "PCA9685.h"

#define I2C_SWRST_ADDRESS        (0x00<<1) // General I2C Software reset address

//============== PCA9685 register addresses
#define PCA9685_RESET            (0x06)   // Used in conjunction with I2C_SWRST_ADDR

#define PCA9685_MODE1            (0x00)   // READ/WRITE Mode register 1
#define PCA9685_MODE2            (0x01)   // READ/WRITE Mode register 2
#define PCA9685_SUBADR1          (0x02)   // READ/WRITE I2C-bus sub-address 1
#define PCA9685_SUBADR2          (0x03)   // READ/WRITE I2C-bus sub-address 2
#define PCA9685_SUBADR3          (0x04)   // READ/WRITE I2C-bus sub-address 3
#define PCA9685_ALLCALLADR       (0x05)   // READ/WRITE LED All Call I2C-bus address
#define PCA9685_LED0_ON_L        (0x06)   // READ/WRITE LED0  output and brightness control byte 0
#define PCA9685_LED0_ON_H        (0x07)   // READ/WRITE LED0  output and brightness control byte 1
#define PCA9685_LED0_OFF_L       (0x08)   // READ/WRITE LED0  output and brightness control byte 2
#define PCA9685_LED0_OFF_H       (0x09)   // READ/WRITE LED0  output and brightness control byte 3
#define PCA9685_LED1_ON_L        (0x0A)   // READ/WRITE LED1  output and brightness control byte 0
#define PCA9685_LED1_ON_H        (0x0B)   // READ/WRITE LED1  output and brightness control byte 1
#define PCA9685_LED1_OFF_L       (0x0C)   // READ/WRITE LED1  output and brightness control byte 2
#define PCA9685_LED1_OFF_H       (0x0D)   // READ/WRITE LED1  output and brightness control byte 3
#define PCA9685_LED2_ON_L        (0x0E)   // READ/WRITE LED2  output and brightness control byte 0
#define PCA9685_LED2_ON_H        (0x0F)   // READ/WRITE LED2  output and brightness control byte 1
#define PCA9685_LED2_OFF_L       (0x10)   // READ/WRITE LED2  output and brightness control byte 2
#define PCA9685_LED2_OFF_H       (0x11)   // READ/WRITE LED2  output and brightness control byte 3
#define PCA9685_LED3_ON_L        (0x12)   // READ/WRITE LED3  output and brightness control byte 0
#define PCA9685_LED3_ON_H        (0x13)   // READ/WRITE LED3  output and brightness control byte 1
#define PCA9685_LED3_OFF_L       (0x14)   // READ/WRITE LED3  output and brightness control byte 2
#define PCA9685_LED3_OFF_H       (0x15)   // READ/WRITE LED3  output and brightness control byte 3
#define PCA9685_LED4_ON_L        (0x16)   // READ/WRITE LED4  output and brightness control byte 0
#define PCA9685_LED4_ON_H        (0x17)   // READ/WRITE LED4  output and brightness control byte 1
#define PCA9685_LED4_OFF_L       (0x18)   // READ/WRITE LED4  output and brightness control byte 2
#define PCA9685_LED4_OFF_H       (0x19)   // READ/WRITE LED4  output and brightness control byte 3
#define PCA9685_LED5_ON_L        (0x1A)   // READ/WRITE LED5  output and brightness control byte 0
#define PCA9685_LED5_ON_H        (0x1B)   // READ/WRITE LED5  output and brightness control byte 1
#define PCA9685_LED5_OFF_L       (0x1C)   // READ/WRITE LED5  output and brightness control byte 2
#define PCA9685_LED5_OFF_H       (0x1D)   // READ/WRITE LED5  output and brightness control byte 3
#define PCA9685_LED6_ON_L        (0x1E)   // READ/WRITE LED6  output and brightness control byte 0
#define PCA9685_LED6_ON_H        (0x1F)   // READ/WRITE LED6  output and brightness control byte 1
#define PCA9685_LED6_OFF_L       (0x20)   // READ/WRITE LED6  output and brightness control byte 2
#define PCA9685_LED6_OFF_H       (0x21)   // READ/WRITE LED6  output and brightness control byte 3
#define PCA9685_LED7_ON_L        (0x22)   // READ/WRITE LED7  output and brightness control byte 0
#define PCA9685_LED7_ON_H        (0x23)   // READ/WRITE LED7  output and brightness control byte 1
#define PCA9685_LED7_OFF_L       (0x24)   // READ/WRITE LED7  output and brightness control byte 2
#define PCA9685_LED7_OFF_H       (0x25)   // READ/WRITE LED7  output and brightness control byte 3
#define PCA9685_LED8_ON_L        (0x26)   // READ/WRITE LED8  output and brightness control byte 0
#define PCA9685_LED8_ON_H        (0x27)   // READ/WRITE LED8  output and brightness control byte 1
#define PCA9685_LED8_OFF_L       (0x28)   // READ/WRITE LED8  output and brightness control byte 2
#define PCA9685_LED8_OFF_H       (0x29)   // READ/WRITE LED8  output and brightness control byte 3
#define PCA9685_LED9_ON_L        (0x2A)   // READ/WRITE LED9  output and brightness control byte 0
#define PCA9685_LED9_ON_H        (0x2B)   // READ/WRITE LED9  output and brightness control byte 1
#define PCA9685_LED9_OFF_L       (0x2C)   // READ/WRITE LED9  output and brightness control byte 2
#define PCA9685_LED9_OFF_H       (0x2D)   // READ/WRITE LED9  output and brightness control byte 3
#define PCA9685_LED10_ON_L       (0x2E)   // READ/WRITE LED10 output and brightness control byte 0
#define PCA9685_LED10_ON_H       (0x2F)   // READ/WRITE LED10 output and brightness control byte 1
#define PCA9685_LED10_OFF_L      (0x30)   // READ/WRITE LED10 output and brightness control byte 2
#define PCA9685_LED10_OFF_H      (0x31)   // READ/WRITE LED10 output and brightness control byte 3
#define PCA9685_LED11_ON_L       (0x32)   // READ/WRITE LED11 output and brightness control byte 0
#define PCA9685_LED11_ON_H       (0x33)   // READ/WRITE LED11 output and brightness control byte 1
#define PCA9685_LED11_OFF_L      (0x34)   // READ/WRITE LED11 output and brightness control byte 2
#define PCA9685_LED11_OFF_H      (0x35)   // READ/WRITE LED11 output and brightness control byte 3
#define PCA9685_LED12_ON_L       (0x36)   // READ/WRITE LED12 output and brightness control byte 0
#define PCA9685_LED12_ON_H       (0x37)   // READ/WRITE LED12 output and brightness control byte 1
#define PCA9685_LED12_OFF_L      (0x38)   // READ/WRITE LED12 output and brightness control byte 2
#define PCA9685_LED12_OFF_H      (0x39)   // READ/WRITE LED12 output and brightness control byte 3
#define PCA9685_LED13_ON_L       (0x3A)   // READ/WRITE LED13 output and brightness control byte 0
#define PCA9685_LED13_ON_H       (0x3B)   // READ/WRITE LED13 output and brightness control byte 1
#define PCA9685_LED13_OFF_L      (0x3C)   // READ/WRITE LED13 output and brightness control byte 2
#define PCA9685_LED13_OFF_H      (0x3D)   // READ/WRITE LED13 output and brightness control byte 3
#define PCA9685_LED14_ON_L       (0x3E)   // READ/WRITE LED14 output and brightness control byte 0
#define PCA9685_LED14_ON_H       (0x3F)   // READ/WRITE LED14 output and brightness control byte 1
#define PCA9685_LED14_OFF_L      (0x40)   // READ/WRITE LED14 output and brightness control byte 2
#define PCA9685_LED14_OFF_H      (0x41)   // READ/WRITE LED14 output and brightness control byte 3
#define PCA9685_LED15_ON_L       (0x42)   // READ/WRITE LED15 output and brightness control byte 0
#define PCA9685_LED15_ON_H       (0x43)   // READ/WRITE LED15 output and brightness control byte 1
#define PCA9685_LED15_OFF_L      (0x44)   // READ/WRITE LED15 output and brightness control byte 2
#define PCA9685_LED15_OFF_H      (0x45)   // READ/WRITE LED15 output and brightness control byte 3
//...
#define PCA9685_ALL_LED_ON_L     (0xFA)   // READ 0/WRITE load all the LEDn_ON  registers, byte 0
#define PCA9685_ALL_LED_ON_H     (0xFB)   // READ 0/WRITE load all the LEDn_ON  registers, byte 1
#define PCA9685_ALL_LED_OFF_L    (0xFC)   // READ 0/WRITE load all the LEDn_OFF registers, byte 2
#define PCA9685_ALL_LED_OFF_H    (0xFD)   // READ 0/WRITE load all the LEDn_OFF registers, byte 3

#define PCA9685_PRE_SCALE        (0xFE)   // READ/WRITE pre-scaler for output frequency
#define PCA9685_TestMode         (0xFF)   // READ/WRITE defines the test mode to be entered

// LEDx_ON_L
//             7:0 LEDx_ON count for LEDx, 8 LSBs
#define LEDx_ON_L_COUNT_MASK  (0xFF<<0)
// LEDx_ON_H
#define LEDx_ON_H_FULL_MASK   (1<<4)
#define LEDx_ON_H_COUNT_MASK  (0xF<<0)
//               4 LEDx full ON
//             3:0 LEDx_ON count for LEDx, 4 MSBs
// LEDx_OFF_L
#define LEDx_OFF_L_COUNT_MASK  (0xFF<<0)
//             7:0 LEDx_OFF count for LEDx, 8 LSBs
// LEDx_OFF_H
#define LEDx_OFF_H_FULL_MASK   (1<<4)
#define LEDx_OFF_H_COUNT_MASK  (0xF<<0)
//               4 LEDx full OFF
//             3:0 LEDx_OFF count for LEDx, 4 MSBs

#define ALL_CALL_ADDDRESS (0xE0)

/*!
 * Constructor with default values
 *
 * @param deviceAddress    Device I2C address
 * @param prescaleValue    Prescale value for the internal clock
 * @param mode1Value       Mode register 1 value
 * @param mode2Value       Mode Register 2 value
 *
 */
PCA9685::PCA9685(I2C *i2cInterface, uint8_t slaveAddress, uint8_t prescaleValue, uint8_t mode1Value, uint8_t mode2Value) {
   this->slaveAddress = slaveAddress;

   if (!i2cInterface) {
      i2cInterface = new I2C_0(0x00);
   }
   this->i2cInterface = i2cInterface;

//   uint8_t resetdata[] = {RESET};
//   i2c_transmit(I2C_SWRST_ADDRESS, resetdata, sizeof(resetdata));
   //
   uint8_t mode1data[] = {
       /* register address */   PCA9685_MODE1,
       /* mode1            */   mode1Value,
       /* mode2            */   mode2Value,
       /* subaddr1         */   0,
       /* subaddr2         */   0,
       /* subaddr3         */   0,
       /* all call address */   ALL_CALL_ADDDRESS
   };
   i2cInterface->transmit(slaveAddress, mode1data, sizeof(mode1data));
   //
   uint8_t prescaleData[] = {
      PCA9685_PRE_SCALE,
      prescaleValue   // Prescale value for clock
   };
   i2cInterface->transmit(slaveAddress, prescaleData, sizeof(prescaleData));
   // All outputs off
   allHigh();
}

/*!
 * Set all outputs high
 */
void PCA9685::allHigh(void) {
   uint8_t data[] = {
      /* register */ (uint8_t) PCA9685_ALL_LED_ON_L,
      /* onLow    */ (uint8_t) 0,
      /* onHigh   */ (uint8_t) 0,
      /* offLow   */ (uint8_t) 0,
      /* offHigh  */ (uint8_t) LEDx_OFF_H_FULL_MASK,
   };
   i2cInterface->transmit(ALL_CALL_ADDDRESS, data, sizeof(data));
}

/*!
 * Set all outputs low
 */
void PCA9685::allLow(void) {
   uint8_t data[] = {
      /* register */ (uint8_t) PCA9685_ALL_LED_ON_L,
      /* onLow    */ (uint8_t) 0,
      /* onHigh   */ (uint8_t) LEDx_ON_H_FULL_MASK,
      /* offLow   */ (uint8_t) 0,
      /* offHigh  */ (uint8_t) 0,
   };
   i2cInterface->transmit(ALL_CALL_ADDDRESS, data, sizeof(data));
}

/*!
 * Sets the dutyCycle of the given pin
 *
 * @param pinNum     Pin to modify
 * @param dutyCycle  Duty-cycle to set (0-4095)
 *
 */
void PCA9685::set_pin_pwm(unsigned pinNum, unsigned dutyCycle) {
   if (dutyCycle>MAX_PWM) {
      dutyCycle = MAX_PWM;
   }
   uint16_t onCount  = 0;
   uint16_t offCount = dutyCycle;
   uint8_t data[] = {
      /* register */ (uint8_t) PCA9685_PIN_REG(pinNum),
      /* onLow    */ (uint8_t) onCount,
      /* onHigh   */ (uint8_t) ((onCount>>8)&LEDx_ON_H_COUNT_MASK),
      /* offLow   */ (uint8_t) offCount,
      /* offHigh  */ (uint8_t) ((offCount>>8)&LEDx_OFF_H_COUNT_MASK),
   };
   i2cInterface->transmit(slaveAddress, data, sizeof(data));
}

/*!
 * Set given pin low
 *
 * @param pinNum Pin to change
 */
void PCA9685::set_pin_low(unsigned pinNum) {
   uint8_t data[] = {
      /* register */ (uint8_t) PCA9685_PIN_REG(pinNum),
      /* onLow    */ (uint8_t) 0,
      /* onHigh   */ (uint8_t) LEDx_ON_H_FULL_MASK,
      /* offLow   */ (uint8_t) 0,
      /* offHigh  */ (uint8_t) 0,
   };
   i2cInterface->transmit(slaveAddress, data, sizeof(data));
}

/*!
 * Set given pin high
 *
 * @param pinNum Pin to change
 */
void PCA9685::set_pin_high(unsigned pinNum) {
   uint8_t data[] = {
      /* register */ (uint8_t) PCA9685_PIN_REG(pinNum),
      /* onLow    */ (uint8_t) 0,
      /* onHigh   */ (uint8_t) 0,
      /* offLow   */ (uint8_t) 0,
      /* offHigh  */ (uint8_t) LEDx_OFF_H_FULL_MASK,
   };
   i2cInterface->transmit(slaveAddress, data, sizeof(data));
}
