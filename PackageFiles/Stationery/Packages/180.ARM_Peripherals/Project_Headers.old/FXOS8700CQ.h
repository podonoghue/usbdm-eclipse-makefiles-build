/**
 * @file     FXOS8700CQ.h
 * @brief    Interface for FXOS8700CQ 3-axis accelerometer and magnetometer
 *
 * @version  V4.11.1.70
 * @date     18 June 2015
 */

#ifndef FXOS8700CQ_H_
#define FXOS8700CQ_H_

#include <stdint.h>
#include "I2C.h"

/**
 * @addtogroup FXOS8700CQ_Group FXOS8700CQ 3-axis accelerometer and magnetometer
 * @brief C++ Class allowing interface to FXOS8700CQ
 * @{
 */

#define FXOS8700CQ_CTRL_REG1_ACTIVE_MASK         (1<<0)
#define FXOS8700CQ_CTRL_REG1_F_READ_MASK         (1<<1)
#define FXOS8700CQ_CTRL_REG1_LNOISE_MASK         (1<<2)
#define FXOS8700CQ_CTRL_REG1_DR_OFF              (3)
#define FXOS8700CQ_CTRL_REG1_DR_MASK             (0x7<<FXOS8700CQ__CTRL_REG1_DR_OFF)
#define FXOS8700CQ_CTRL_REG1_DR(x)               (((x)<<FXOS8700CQ__CTRL_REG1_DR_OFF)&FXOS8700CQ__CTRL_REG1_DR_MASK)
#define FXOS8700CQ_CTRL_REG1_ASLP_RATE_OFF       (6)
#define FXOS8700CQ_CTRL_REG1_ASLP_RATE_MASK      (0x3FXOS8700CQ__CTRL_REG1_ASLP_RATE_OFF)
#define FXOS8700CQ_CTRL_REG1_ASLP_RATE(x)        (((x)<<FXOS8700CQ__CTRL_REG1_ASLP_RATE_OFF)&FXOS8700CQ__CTRL_REG1_ASLP_RATE_MASK)

#define FXOS8700CQ_CTRL_REG2_MODS_OFF            (0)
#define FXOS8700CQ_CTRL_REG2_MODS_MASK           (0x3<<FXOS8700CQ__CTRL_REG1_DR_OFF)
#define FXOS8700CQ_CTRL_REG2_MODS(x)             (((x)<<FXOS8700CQ__CTRL_REG1_DR_OFF)&FXOS8700CQ__CTRL_REG1_DR_MASK)
#define FXOS8700CQ_CTRL_REG2_SLPE_MASK           (1<<2)
#define FXOS8700CQ_CTRL_REG2_SMODS_OFF           (3)
#define FXOS8700CQ_CTRL_REG2_SMODS_MASK          (0x3<<FXOS8700CQ__CTRL_REG1_DR_OFF)
#define FXOS8700CQ_CTRL_REG2_SMODS(x)            (((x)<<FXOS8700CQ__CTRL_REG1_DR_OFF)&FXOS8700CQ__CTRL_REG1_DR_MASK)
#define FXOS8700CQ_CTRL_REG2_RST_MASK            (1<<6)
#define FXOS8700CQ_CTRL_REG2_ST_MASK             (1<<7)

#define FXOS8700CQ_CTRL_REG3_PP_OD_MASK          (1<<0)
#define FXOS8700CQ_CTRL_REG3_IPOL_MASK           (1<<1)
#define FXOS8700CQ_CTRL_REG3_WAKE_A_VECM_MASK    (1<<2)
#define FXOS8700CQ_CTRL_REG3_WAKE_FFMT_MASK      (1<<3)
#define FXOS8700CQ_CTRL_REG3_WAKE_PULSE_MASK     (1<<4)
#define FXOS8700CQ_CTRL_REG3_WAKE_INDPRT_MASK    (1<<5)
#define FXOS8700CQ_CTRL_REG3_WAKE_TRANS_MASK     (1<<6)
#define FXOS8700CQ_CTRL_REG3_FIFO_GATE_MASK      (1<<7)

#define FXOS8700CQ_CTRL_REG3_INT_EN_DRDY_MASK    (1<<0)
#define FXOS8700CQ_CTRL_REG3_INT_EN_A_VECM_MASK  (1<<1)
#define FXOS8700CQ_CTRL_REG3_INT_EN_EN_FFMT_MASK (1<<2)
#define FXOS8700CQ_CTRL_REG3_INT_EN_PULSE_MASK   (1<<3)
#define FXOS8700CQ_CTRL_REG3_INT_EN_INDPRT_MASK  (1<<4)
#define FXOS8700CQ_CTRL_REG3_INT_EN_TRANS_MASK   (1<<5)
#define FXOS8700CQ_CTRL_REG3_INT_EN_FIFO_MASK    (1<<6)
#define FXOS8700CQ_CTRL_REG3_INT_EN_ASLP_MASK    (1<<7)
/**
 * @brief Class representing an interface for FXOS8700CQ 3-axis accelerometer and magnetometer over I2C
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  I2C     *i2c   = new I2C_0();
 *  FXOS8700CQ *accelMag = new FXOS8700CQ(i2c, FXOS8700CQ::ACCEL_2Gmode);
 *
 *  int      status;
 *  int16_t  x, y, z;
 *
 *  accelMag->setAccelerometerMode(FXOS8700CQ::ACCEL_2Gmode);
 *  accelMag->readAccelerometerXYZ(&status, &x, &y, &z);
 *  accelMag->readMagnetometerXYZ(&status, &x, &y, &z);
 *
 *  FXOS8700CQ::Data data;
 *  accelMag->readAll(data);
 *
 * @endcode
 */
class FXOS8700CQ {

#define FXOS8700CQ_XYZ_DATA_CFG_FS(x)          (((x)<<0)&0x03)
#define FXOS8700CQ_XYZ_DATA_CFG_HPF_OUT_MASK   (1<<4)

private:
   I2C *i2c;
#ifdef MCU_MK22F51212
   static const uint8_t  DEVICE_ADDRESS = 0x1C<<1;  // SA1,0 pins : 00=>0x1E, 01=>1D, 10=>1C, 11=>1F
#else
   static const uint8_t  DEVICE_ADDRESS = 0x1D<<1;  // SA1,0 pins : 00=>0x1E, 01=>1D, 10=>1C, 11=>1F
#endif
   static const uint8_t  WHO_AM_I_VALUE = 0xC7;

   /**
    * Read Accelerometer register
    *
    * @param regNum  - Register number
    */
   uint8_t readReg(uint8_t regNum);
   /**
    * Write Accelerometer register
    *
    * @param regNum  - Register number
    * @param value   - Value to write
    */
   void    writeReg(uint8_t regNum, uint8_t value);
   /**
    * Reset Accelerometer
    */
   void    reset(void);
   bool    failedInit;

public:

   enum AccelerometerMode {
      ACCEL_2Gmode      = FXOS8700CQ_XYZ_DATA_CFG_FS(0),                                      // 2g Full-scale, no high-pass filter
      ACCEL_4Gmode      = FXOS8700CQ_XYZ_DATA_CFG_FS(1),                                      // 4g Full-scale, no high-pass filter
      ACCEL_8Gmode      = FXOS8700CQ_XYZ_DATA_CFG_FS(2),                                      // 8g Full-scale, no high-pass filter
      ACCEL_2G_HPF_mode = FXOS8700CQ_XYZ_DATA_CFG_FS(0)|FXOS8700CQ_XYZ_DATA_CFG_HPF_OUT_MASK, // 2g Full-scale, high-pass filter
      ACCEL_4G_HPF_mode = FXOS8700CQ_XYZ_DATA_CFG_FS(1)|FXOS8700CQ_XYZ_DATA_CFG_HPF_OUT_MASK, // 4g Full-scale, high-pass filter
      ACCEL_8G_HPF_mode = FXOS8700CQ_XYZ_DATA_CFG_FS(2)|FXOS8700CQ_XYZ_DATA_CFG_HPF_OUT_MASK, // 8g Full-scale, high-pass filter
   } ;

   enum ControlReg2Mode {
      HYB_AUTOINC_MODE = (1<<5),
      M_MAXMIN_DIS     = (1<<4),
      M_MAXMIN_DIS_THS = (1<<3),
      M_MAXMIN_RST     = (1<<2),
      M_RST_CNT_1      = (0),
      M_RST_CNT_16     = (1),
      M_RST_CNT_512    = (2),
      M_RST_CNT_NEVER  = (3),
   };

   struct Data {
      uint8_t accelerometerStatus;
      uint8_t accelerometer_X;
      uint8_t accelerometer_Y;
      uint8_t accelerometer_Z;
      uint8_t magnetometerStatus;
      uint8_t magnetometer_X;
      uint8_t magnetometer_Y;
      uint8_t magnetometer_Z;
   };

   /**
    * Constructor
    *
    * @param i2c  - The I2C interface to use
    * @param mode - Mode of operation (gain and filtering)
    */
   FXOS8700CQ(I2C *i2c, AccelerometerMode mode);
   /**
    * Put accelerometer into Standby mode
    */
   void standby();
   /**
    * Put accelerometer into Active mode
    */
   void active();
   /**
    * Obtains measurements from the accelerometer
    *
    * @param status  - Indicates status of x, y & z measurements
    * @param x       - X axis value
    * @param y       - Y axis value
    * @param z       - Z axis value
    */
   void readAccelerometerXYZ(int *status, int16_t *x, int16_t *y, int16_t *z);
   /**
    * Set accelerometer mode (gain and filtering)
    *
    * @param mode - one of 2Gmode etc.
    */
   void setAccelerometerMode(AccelerometerMode mode);
   /**
    * Set magnetometer mode (gain and filtering)
    *
    * @param mode - one of 2Gmode etc.
    */
   void setMagnetometerMode(ControlReg2Mode mode);
   /*
    * Obtains measurements from the Magnetometer
    *
    * @param status  - Indicates status of x, y & z measurements
    * @param x       - X axis value
    * @param y       - Y axis value
    * @param z       - Z axis value
    */
   void readMagnetometerXYZ(int *status, int16_t *x, int16_t *y, int16_t *z);
   /*
    * Obtains measurements from the Accelerometer & Magnetometer
    *
    * @param data  Reference to structure to contain values read
    */
   void readAll(Data &data);
};

/**
 * @}
 */
#endif /* FXOS8700CQ_H_ */
