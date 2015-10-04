/*
 * HMC5883L.cpp
 *
 *  Created on: 10/07/2014
 *      Author: podonoghue
 */

#include "HMC5883L.h"

enum {
   CRA,
   CRB,
   MR,
   XMSB,
   XLSB,
   YMSB,
   YLSB,
   ZMSB,
   ZLSB,
   SR,
   IRA,
   IRB,
   IRC,
};

   /*!
    * Constructor
    *
    * @param i2c - I2C interface to use
    *
    */
   HMC5883L::HMC5883L(I2C *i2c) : i2c(i2c) {
      // Set default settings
      static const uint8_t settings[] = {
         CRA,
         HMC5883L_CRA_MA(0)|HMC5883L_CRA_DO(2)|HMC5883L_CRA_MS(0), // Averaging, Data rate (not relevant to single measurement?), Idle,
         HMC5883L_CRB_GN(1),                                       // Gain : Range = +/- 1.3Ga, Resolution=0.92 (default)
         HMC5883L_MR_MD(1),                                        // Mode = Single-Measurement Mode
      };
      i2c->transmit(deviceAddress, settings, sizeof(settings));
   }

   /*!
    * Read ID from compass
    *
    * @return ID value as 24-bit number (0x483433 for HMC5883L)
    */
   uint32_t HMC5883L::readID(void) {
      uint8_t values[] = {IRA, 0x00, 0x00, 0x00};
      i2c->receive(deviceAddress, values, sizeof(values)-1);
      return (values[0]<<16)|(values[1]<<8)|values[2];
   }

   /*!
    * Set compass gain on all channels
    *
    * @param gain                                     \n
    * G    Recommended   Gain        Resolution       \n
    * 321  Sensor Range  (LSB/Gauss) (mGauss/LSB)     \n
    * 000   +/- 0.88 Ga    1370        0.73             \n
    * 001   +/- 1.3  Ga    1090        0.92 (default)   \n
    * 010   +/- 1.9  Ga     820        1.22             \n
    * 011   +/- 2.5  Ga     660        1.52             \n
    * 100   +/- 4.0  Ga     440        2.27             \n
    * 101   +/- 4.7  Ga     390        2.56             \n
    * 110   +/- 5.6  Ga     330        3.03             \n
    * 111   +/- 8.1  Ga     230        4.35
    */
   void HMC5883L::setGain(uint8_t gain) {
      // Set Gain
      static const uint8_t controlRegB_Setting[] = {CRB, (uint8_t)HMC5883L_CRB_GN(gain)};
      i2c->transmit(deviceAddress, controlRegB_Setting, sizeof(controlRegB_Setting));
   }

   /*!
    * Set Control register values
    *
    * @param cra                                      \n
    *    Use HMC5883L_CRA_MA(), HMC5883L_CRA_DO(), HMC5883L_CRA_MS() macros to construct value
    * @param crb                                      \n
    *    Use HMC5883L_CRB_GN() macro to construct value
    */
   void HMC5883L::setConfiguration(uint8_t cra, uint8_t crb) {
      // Set CRA & CRB
      static const uint8_t controlReg_Settings[] = {CRA, cra, crb};
      i2c->transmit(deviceAddress, controlReg_Settings, sizeof(controlReg_Settings));
   }

   /*!
    * Do a single triggered measurement of magnetic field
    *
    * @param x - X intensity
    * @param y - Y intensity
    * @param z - Z intensity
    */
   void HMC5883L::doMeasurement(int16_t *x, int16_t *y, int16_t *z) {
      uint8_t modeReg_Setting[] = {MR, HMC5883L_MR_MD(1)};
      i2c->transmit(deviceAddress, modeReg_Setting, sizeof(modeReg_Setting));
      uint8_t dataOutIn[] = {SR};
      do {
         dataOutIn[0] = SR;
         i2c->receive(deviceAddress, dataOutIn, sizeof(dataOutIn));
      } while ((dataOutIn[0]&HMC5883L_SR_RDY) == 0);
      uint8_t values[] = {XMSB, 0x00, 0x00, 0x00, 0x00, 0x00};
      i2c->receive(deviceAddress, values, sizeof(values));
      *x = (values[0]<<8)+values[1];
      *z = (values[2]<<8)+values[3];
      *y = (values[4]<<8)+values[5];
   }
