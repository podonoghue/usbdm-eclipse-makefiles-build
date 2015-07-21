/**
 * @file     MMA845x.h
 * @brief    Interface for MMA845x accelerometer
 *
 * @version  V4.11.1.70
 * @date     18 June 2015
 */

#ifndef MMA845X_H_
#define MMA845X_H_

#include <stdint.h>
#include "i2c.h"

/**
 * @addtogroup MMA845x_Group MMA845x 3-axis accelerometer
 * @brief C++ Class prividing interface to MMA845x
 * @{
 */

/**
 * @brief class representing a Interface for MMA845x 3-axis accelerometer over I2C
 *
 * <b>Example</b>
 * @code
 *
 *   I2C     *i2c   = new I2C_0();
 *   MMA845x *accel = new MMA845x(i2c, MMA845x::MMA45x_2Gmode);
 *
 *   int      status;
 *   int16_t  x, y, z;
 *
 *   accel->setMode(MMA845x::MMA45x_2Gmode);
 *   accel->readXYZ(&status, &x, &y, &z);
 *
 * @endcode
 */
class MMA845x {

#define MMA45x_XYZ_DATA_CFG_FS(x)          (((x)<<0)&0x03)
#define MMA45x_XYZ_DATA_CFG_HPF_OUT_MASK   (1<<4)

private:
   I2C *i2c;
   static const uint8_t deviceAddress = 0x1D<<1;

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

public:

   enum Mode {
      MMA45x_2Gmode      = MMA45x_XYZ_DATA_CFG_FS(0),                                  // 2g Full-scale, no high-pass filter
      MMA45x_4Gmode      = MMA45x_XYZ_DATA_CFG_FS(1),                                  // 4g Full-scale, no high-pass filter
      MMA45x_8Gmode      = MMA45x_XYZ_DATA_CFG_FS(2),                                  // 8g Full-scale, no high-pass filter
      MMA45x_2G_HPF_mode = MMA45x_XYZ_DATA_CFG_FS(0)|MMA45x_XYZ_DATA_CFG_HPF_OUT_MASK, // 2g Full-scale, high-pass filter
      MMA45x_4G_HPF_mode = MMA45x_XYZ_DATA_CFG_FS(1)|MMA45x_XYZ_DATA_CFG_HPF_OUT_MASK, // 4g Full-scale, high-pass filter
      MMA45x_8G_HPF_mode = MMA45x_XYZ_DATA_CFG_FS(2)|MMA45x_XYZ_DATA_CFG_HPF_OUT_MASK, // 8g Full-scale, high-pass filter
   } ;

   /**
    * Constructor
    *
    * @param i2c  - The I2C interface to use
    * @param mode - Mode of operation (gain and filtering)
    */
   MMA845x(I2C *i2c, Mode mode);
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
   void readXYZ(int *status, int16_t *x, int16_t *y, int16_t *z);
   /**
    * Set accelerometer mode (gain and filtering)
    *
    * @param mode - one of MMA45x_2Gmode etc.
    */
   void setMode(Mode mode);
};

/**
 * @}
 */
#endif /* MMA845X_H_ */
