/*
 *  @file motor.h
 *
 *  Created on: 10/07/2014
 *      Author: podonoghue
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "pca9685.h"

class Motor : private PCA9685 {

public:
   Motor(I2C *i2cInterface,
         uint8_t slaveAddress  = PCA9685_DEFAULT_SLAVE_BASE_ADDRESS,
         uint8_t prescaleValue = PCA9685_DEFAULT_OSC_PRESCALE) :
            PCA9685(i2cInterface, slaveAddress, prescaleValue, PCA9685_MODE1_AI_MASK, PCA9685_MODE2_OUTDRV_MASK) {
   }

   enum Direction {
      CCW,  // Counter-clockwise
      CW,   // Clockwise
   };

   // Mapping of PCA9685 PWMs => TB6612FNG
   // PWMA  AIN1 AIN2   PWMB  BIN1 BIN2
   //   2    4    3       7    5    6
   //   8    10   9       13   11   12

   /*
    * @param dutyCycle - Duty cycle for motor \n
    */
   void setMotor0(Direction clockwise, int dutyCycle) {
      if (clockwise) {
         // PIN2 = PWMA = pwm
         // PIN3 = AIN2 = L
         // PIN4 = AIN1 = H
         uint8_t cw[] = {PCA9685_PIN_REG(2),
         /*  PWM  on=0     off=dutyCycle */ 0, 0,   (uint8_t)dutyCycle, (uint8_t)((dutyCycle>>8)&PCA9685_LEDx_OFF_H_COUNT_MASK),
         /*  IN2  ccw=full off=X         */ 0, PCA9685_LEDx_ON_H_FULL_MASK,   0, 0,
         /*  IN1  on=X     off=full      */ 0, 0,   0, PCA9685_LEDx_OFF_H_FULL_MASK,
         };
         i2cInterface->transmit(slaveAddress, cw, sizeof(cw));
      }
      else {
         // PIN2 = PWMA = pwm
         // PIN3 = AIN2 = H
         // PIN4 = AIN1 = L
         uint8_t ccw[] = {PCA9685_PIN_REG(2),
         /*  PWM  on=0    off=dutyCycle */ 0, 0,   (uint8_t)dutyCycle, (uint8_t)((dutyCycle>>8)&PCA9685_LEDx_OFF_H_COUNT_MASK),
         /*  IN2  on=X    off=full      */ 0, 0,   0, PCA9685_LEDx_OFF_H_FULL_MASK,
         /*  IN1  on=full off=X         */ 0, PCA9685_LEDx_ON_H_FULL_MASK,   0, 0,
         };
         i2cInterface->transmit(slaveAddress, ccw, sizeof(ccw));
      }
   }
   /*
    * @param dutyCycle - Duty cycle for motor \n
    */
   void setMotor1(Direction direction, int dutyCycle) {
      if (direction == CW) {
         // PIN5 = BIN1 = H
         // PIN5 = BIN2 = L
         // PIN5 = PWMB = pwm
         uint8_t cw[] = {PCA9685_PIN_REG(5),
         /*  IN1 on=X     off=full      */ 0, 0,   0, PCA9685_LEDx_OFF_H_FULL_MASK,
         /*  IN2 ccw=full off=X         */ 0, PCA9685_LEDx_ON_H_FULL_MASK,   0, 0,
         /*  PWM on=0     off=dutyCycle */ 0, 0,   (uint8_t)dutyCycle, (uint8_t)((dutyCycle>>8)&PCA9685_LEDx_OFF_H_COUNT_MASK),
         };
         i2cInterface->transmit(slaveAddress, cw, sizeof(cw));
      }
      else {
         // PIN5 = BIN1 = L
         // PIN5 = BIN2 = H
         // PIN5 = PWMB = pwm
         uint8_t ccw[] = {PCA9685_PIN_REG(5),
         /*  IN1  on=full off=X         */ 0, PCA9685_LEDx_ON_H_FULL_MASK,   0, 0,
         /*  IN2  on=X    off=full      */ 0, 0,   0, PCA9685_LEDx_OFF_H_FULL_MASK,
         /*  PWM  on=0    off=dutyCycle */ 0, 0,   (uint8_t)dutyCycle, (uint8_t)((dutyCycle>>8)&PCA9685_LEDx_OFF_H_COUNT_MASK),
         };
         i2cInterface->transmit(slaveAddress, ccw, sizeof(ccw));
      }
   }
   /*
    * @param dutyCycle - Duty cycle for motor \n
    */
   void setMotor2(Direction direction, int dutyCycle) {
      if (direction == CW) {
         // PIN8  = PWMA = pwm
         // PIN9  = AIN2 = L
         // PIN10 = AIN1 = H
         uint8_t cw[] = {PCA9685_PIN_REG(8),
         /*  PWM  on=0     off=dutyCycle */ 0, 0,   (uint8_t)dutyCycle, (uint8_t)((dutyCycle>>8)&PCA9685_LEDx_OFF_H_COUNT_MASK),
         /*  IN2  ccw=full off=X         */ 0, PCA9685_LEDx_ON_H_FULL_MASK,   0, 0,
         /*  IN1  on=X     off=full      */ 0, 0,   0, PCA9685_LEDx_OFF_H_FULL_MASK,
         };
         i2cInterface->transmit(slaveAddress, cw, sizeof(cw));
      }
      else {
         // PIN8  = PWMA = pwm
         // PIN9  = AIN2 = H
         // PIN10 = AIN1 = L
         uint8_t ccw[] = {PCA9685_PIN_REG(8),
         /*  PWM on=0    off=dutyCycle */ 0, 0,   (uint8_t)dutyCycle, (uint8_t)((dutyCycle>>8)&PCA9685_LEDx_OFF_H_COUNT_MASK),
         /*  IN2 on=X    off=full      */ 0, 0,   0, PCA9685_LEDx_OFF_H_FULL_MASK,
         /*  IN1 on=full off=X         */ 0, PCA9685_LEDx_ON_H_FULL_MASK,   0, 0,
         };
         i2cInterface->transmit(slaveAddress, ccw, sizeof(ccw));
      }
   }
   /*
    * @param dutyCycle - Duty cycle for motor \n
    */
   void setMotor3(Direction direction, int dutyCycle) {
      if (direction == CW) {
         // PIN11 = BIN1 = H
         // PIN12 = BIN2 = L
         // PIN13 = PWMB = pwm
         uint8_t cw[] = {PCA9685_PIN_REG(11),
         /*  IN1  on=X     off=full      */ 0, 0,   0, PCA9685_LEDx_OFF_H_FULL_MASK,
         /*  IN2  ccw=full off=X         */ 0, PCA9685_LEDx_ON_H_FULL_MASK,   0, 0,
         /*  PWM  on=0     off=dutyCycle */ 0, 0,   (uint8_t)dutyCycle, (uint8_t)((dutyCycle>>8)&PCA9685_LEDx_OFF_H_COUNT_MASK),
         };
         i2cInterface->transmit(slaveAddress, cw, sizeof(cw));
      }
      else {
         // PIN11 = BIN1 = L
         // PIN12 = BIN2 = H
         // PIN13 = PWMB = pwm
         uint8_t ccw[] = {PCA9685_PIN_REG(11),
         /*  IN1  on=full off=X         */ 0, PCA9685_LEDx_ON_H_FULL_MASK,   0, 0,
         /*  IN2  on=X    off=full      */ 0, 0,   0, PCA9685_LEDx_OFF_H_FULL_MASK,
         /*  PWM  on=0    off=dutyCycle */ 0, 0,   (uint8_t)dutyCycle, (uint8_t)((dutyCycle>>8)&PCA9685_LEDx_OFF_H_COUNT_MASK),
         };
         i2cInterface->transmit(slaveAddress, ccw, sizeof(ccw));
      }
   }
};

#endif /* MOTOR_H_ */
