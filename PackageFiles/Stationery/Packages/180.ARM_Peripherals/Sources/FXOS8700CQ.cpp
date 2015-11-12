/**
 * @file FXOS8700CQ.cpp
 *
 *  Created on: 22/11/2013
 *      Author: podonoghue
 */
#include "FXOS8700CQ.h"

// Accelerometer registers
enum {
   STATUS,
   F_STATUS = STATUS,
   OUT_X_MSB,
   OUT_X_LSB,
   OUT_Y_MSB,
   OUT_Y_LSB,
   OUT_Z_MSB,
   OUT_Z_LSB,
   Reservedx07,
   Reservedx08,
   F_SETUP,
   TRIG_CFG,
   SYSMOD,
   INT_SOURCE,
   WHO_AM_I,
   XYZ_DATA_CFG,
   HP_FILTER_CUTOFF,
   PL_STATUS,
   PL_CFG,
   PL_COUNT,
   PL_BF_ZCOMP,
   P_L_THS_REG,
   A_FFMT_CFG,
   A_FFMT_SRC,
   A_FFMT_THS,
   A_FFMT_COUNT,
   reservedx19,
   reservedx1A,
   reservedx1B,
   reservedx1C,
   TRANSIENT_CFG,
   TRANSIENT_SCR,
   TRANSIENT_THS,
   TRANSIENT_COUNT,
   PULSE_CFG,
   PULSE_SRC,
   PULSE_THSX,
   PULSE_THSY,
   PULSE_THSZ,
   PULSE_TMLT,
   PULSE_LTCY,
   PULSE_WIND,
   ASLP_COUNT,
   CTRL_REG1,
   CTRL_REG2,
   CTRL_REG3,
   CTRL_REG4,
   CTRL_REG5,
   OFF_X,
   OFF_Y,
   OFF_Z,

   // Magnetometer registers (0x32 onwards)
   M_DR_STATUS,
   M_OUT_X_MSB,
   M_OUT_X_LSB,
   M_OUT_Y_MSB,
   M_OUT_Y_LSB,
   M_OUT_Z_MSB,
   M_OUT_Z_LSB,
   CMP_X_MSB,
   CMP_X_LSB,
   CMP_Y_MSB,
   CMP_Y_LSB,
   CMP_Z_MSB,
   CMP_Z_LSB,
   M_OFF_X_MSB,
   M_OFF_X_LSB,
   M_OFF_Y_MSB,
   M_OFF_Y_LSB,
   M_OFF_Z_MSB,
   M_OFF_Z_LSB,
   MAX_X_MSB,
   MAX_X_LSB,
   MAX_Y_MSB,
   MAX_Y_LSB,
   MAX_Z_MSB,
   MAX_Z_LSB,
   MIN_X_MSB,
   MIN_X_LSB,
   MIN_Y_MSB,
   MIN_Y_LSB,
   MIN_Z_MSB,
   MIN_Z_LSB,
   TEMP,
   M_THS_CFG,
   M_THS_SRC,
   M_THS_X_MSB,
   M_THS_X_LSB,
   M_THS_Y_MSB,
   M_THS_Y_LSB,
   M_THS_Z_MSB,
   M_THS_Z_LSB,
   M_THS_COUNT,
   M_CTRL_REG1,
   M_CTRL_REG2,
   M_CTRL_REG3,
   M_INT_SRC,
   A_VECM_CFG,
   A_VECM_THS_MSB,
   A_VECM_THS_LSB,
   A_VECM_CNT,
   A_VECM_INITX_MSB,
   A_VECM_INITX_LSB,
   A_VECM_INITY_MSB,
   A_VECM_INITY_LSB,
   A_VECM_INITZ_MSB,
   A_VECM_INITZ_LSB,
   M_VECM_CFG,
   M_VECM_THS_MSB,
   M_VECM_THS_LSB,
   M_VECM_CNT,
   M_VECM_INITX_MSB,
   M_VECM_INITX_LSB,
   M_VECM_INITY_MSB,
   M_VECM_INITY_LSB,
   M_VECM_INITZ_MSB,
   M_VECM_INITZ_LSB,
   A_FFMT_THS_X_MSB,
   A_FFMT_THS_X_LSB,
   A_FFMT_THS_Y_MSB,
   A_FFMT_THS_Y_LSB,
   A_FFMT_THS_Z_MSB,
   A_FFMT_THS_Z_LSB,
   Reservedx79,
};

/*
 * Constructor
 *
 * @param i2c  - The I2C interface to use
 * @param mode - Mode of operation (gain and filtering)
 */
FXOS8700CQ::FXOS8700CQ(I2C *i2c, AccelerometerMode mode) : i2c(i2c) {
   if (readReg(WHO_AM_I) != WHO_AM_I_VALUE) {
      failedInit = true;
      return;
   }
//   reset();
   setAccelerometerMode(mode);
   failedInit = false;
}

/**
 * Enable accelerometer and/or magnetometer
 *
 * @param mode ACCEL_ONLY, MAG_ONLY or ACCEL_MAG
 */
void FXOS8700CQ::enable(Mode mode) {
   writeReg(M_CTRL_REG1, FXOS8700CQ_M_CTRL_REG1_M_HMS(mode));
}

/**
 * Read Accelerometer register
 *
 * @param regNum  - Register number
 */
uint8_t FXOS8700CQ::readReg(uint8_t regNum) {
   uint8_t command[] = {regNum};

   i2c->txRx(DEVICE_ADDRESS, command, 1, sizeof(command));
   return command[0];
}

/**
 * Write Accelerometer register
 *
 * @param regNum  - Register number
 * @param value   - Value to write
 */
void FXOS8700CQ::writeReg(uint8_t regNum, uint8_t value) {
   uint8_t command[] = {regNum, value};

   i2c->transmit(DEVICE_ADDRESS, command, sizeof(command));
}

/**
 * Reset Accelerometer
 */
void FXOS8700CQ::reset(void) {

   writeReg(CTRL_REG2, FXOS8700CQ_CTRL_REG2_RST_MASK);
   // Device is not accessible after RESET
   // Wait a while
   int i;
   for(i=0; i<20000; i++) {
      __asm__("nop");
   }
}

/**
 * Put accelerometer into Standby mode
 */
void FXOS8700CQ::standby() {

   writeReg(CTRL_REG1, readReg(CTRL_REG1)&~FXOS8700CQ_CTRL_REG1_ACTIVE_MASK);
}

/**
 * Put accelerometer into Active mode
 */
void FXOS8700CQ::active() {

   writeReg(CTRL_REG1, readReg(CTRL_REG1)|FXOS8700CQ_CTRL_REG1_ACTIVE_MASK);
}

/**
 * Obtains measurements from the accelerometer
 *
 * @param status  - Indicates status of x, y & z measurements
 * @param x       - X axis value
 * @param y       - Y axis value
 * @param z       - Z axis value
 */
void FXOS8700CQ::readAccelerometerXYZ(int *status, int16_t *x, int16_t *y, int16_t *z) {
   uint8_t dataXYZ[7] = {STATUS};

   // Receive 7 registers (status, X-high, X-low, Y-high, Y-low, Z-high & Z-low)
   i2c->txRx(DEVICE_ADDRESS, dataXYZ, 1, sizeof(dataXYZ));

   // Unpack data and return
   *status = dataXYZ[0];
   *x = ((int16_t)((dataXYZ[1]<<8)+dataXYZ[2]))>>2;
   *y = ((int16_t)((dataXYZ[3]<<8)+dataXYZ[4]))>>2;
   *z = ((int16_t)((dataXYZ[5]<<8)+dataXYZ[6]))>>2;
}

/**
 * Set accelerometer mode (gain and filtering)
 *
 * @param mode - one of ACCEL_2Gmode etc.
 */
void FXOS8700CQ::setAccelerometerMode(AccelerometerMode mode) {
   writeReg(CTRL_REG1, 0x00);

   writeReg(XYZ_DATA_CFG, FXOS8700CQ_XYZ_DATA_CFG_FS(mode));

   writeReg(M_CTRL_REG2, FXOS8700CQ_M_CTRL_REG2_M_HYB_AUTOINC_MODE_MASK);

   writeReg(CTRL_REG1,
         FXOS8700CQ_CTRL_REG1_ASLP_RATE(0) | /* 50 Hz auto-sleep rate */
         FXOS8700CQ_CTRL_REG1_DR(2) |        /* 200 Hz update rate    */
         FXOS8700CQ_CTRL_REG1_ACTIVE_MASK);  /* Active     */
}

/*
 * Obtains measurements from the Magnetometer
 *
 * @param status  - Indicates status of x, y & z measurements
 * @param x       - X axis value
 * @param y       - Y axis value
 * @param z       - Z axis value
 */
void FXOS8700CQ::readMagnetometerXYZ(int *status, int16_t *x, int16_t *y, int16_t *z) {
   uint8_t dataXYZ[7] = {M_DR_STATUS};

   // Receive 7 registers (status, X-high, X-low, Y-high, Y-low, Z-high & Z-low)
   i2c->txRx(DEVICE_ADDRESS, dataXYZ, 1, sizeof(dataXYZ));

   // Unpack data and return (data is sign extended)
   *status = dataXYZ[0];
   *x = ((dataXYZ[1]<<8)+dataXYZ[2]);
   *y = ((dataXYZ[3]<<8)+dataXYZ[4]);
   *z = ((dataXYZ[5]<<8)+dataXYZ[6]);
}

/**
 * Set magnetometer mode (gain and filtering)
 *
 * @param mode - one of 2Gmode etc.
 */
void FXOS8700CQ::setMagnetometerMode(ControlReg2Mode mode) {
   writeReg(M_CTRL_REG2, mode);
}

/*
 * Obtains measurements from the Accelerometer & Magnetometer
 *
 * @param data  Reference to structure to contain values read
 */
void FXOS8700CQ::readAll(Data &data) {
   uint8_t dataXYZ[13] = {XYZ_DATA_CFG};

   // Receive 14 registers (accelerometerStatus, X-high/low, Y-high/low, Z-high/low,
   //                       magnetometerStatus, X-high/low, Y-high/low, Z-high/low)
   i2c->txRx(DEVICE_ADDRESS, dataXYZ, 1, sizeof(dataXYZ));
   data.accelerometerStatus = dataXYZ[0];
   data.accelerometer_X     = ((dataXYZ[1]<<8)+dataXYZ[2]);
   data.accelerometer_Y     = ((dataXYZ[3]<<8)+dataXYZ[4]);
   data.accelerometer_Z     = ((dataXYZ[5]<<8)+dataXYZ[6]);
   data.magnetometerStatus = dataXYZ[7];
   data.magnetometer_X      = ((dataXYZ[7]<<8)+dataXYZ[8]);
   data.magnetometer_Y      = ((dataXYZ[9]<<8)+dataXYZ[10]);
   data.magnetometer_Z      = ((dataXYZ[10]<<8)+dataXYZ[11]);
}

/*!
 * Read ID from accelerometer
 *
 * @return ID value as 8-bit number (0x1A for MMA8451Q)
 */
uint32_t FXOS8700CQ::readID(void) {
   uint8_t values[] = {WHO_AM_I};
   i2c->txRx(DEVICE_ADDRESS, values, 1, sizeof(values));
   return values[0];
}

/**
 * Calibrate accelerometer
 * (2g mode)
 */
void FXOS8700CQ::calibrateAccelerometer() {

   uint8_t originalControlReg1Value = readReg(CTRL_REG1);
   uint8_t originalXYXDataConfigValue = readReg(XYZ_DATA_CFG);

   // Make inactive so setting can be modified
   writeReg(CTRL_REG1, 0x00);

   // Clear existing offsets
   writeReg(OFF_X, 0);
   writeReg(OFF_Y, 0);
   writeReg(OFF_Z, 0);

   int mode = (originalXYXDataConfigValue&FXOS8700CQ_XYZ_DATA_CFG_FS_MASK)>>FXOS8700CQ_XYZ_DATA_CFG_FS_OFF;

   static const int calibration2Gs[]     = {4096*8, 2048*8, 1024*8};
   static const int calibrationFactors[] = {8*8, 4*8, 2*8};

   int calibration2G     = calibration2Gs[mode];
   int calibrationFactor = calibrationFactors[mode];

   writeReg(CTRL_REG1,
         FXOS8700CQ_CTRL_REG1_ASLP_RATE(0) | /* 50 Hz auto-sleep rate */
         FXOS8700CQ_CTRL_REG1_DR(2) |        /* 200 Hz update rate    */
         FXOS8700CQ_CTRL_REG1_ACTIVE_MASK);  /* Active     */

   int16_t Xout_Accel_14_bit, Yout_Accel_14_bit, Zout_Accel_14_bit;
   int     Xout_Accel=0, Yout_Accel=0, Zout_Accel=0;

   // Average 8 samples to reduce noise
   for (int i=0; i<8; i++) {
      int status;
      do {
         readAccelerometerXYZ(&status, &Xout_Accel_14_bit, &Yout_Accel_14_bit, &Zout_Accel_14_bit);
      } while ((status & FXOS8700CQ_STATUS_ZYXDR_MASK) == 0);
      Xout_Accel += Xout_Accel_14_bit;
      Yout_Accel += Yout_Accel_14_bit;
      Zout_Accel += Zout_Accel_14_bit;
   }

   // Make inactive so setting can be modified
   writeReg(CTRL_REG1, 0x00);

   char X_Accel_offset = -(Xout_Accel / calibrationFactor);                    // Compute X-axis offset correction value
   char Y_Accel_offset = -(Yout_Accel / calibrationFactor);                    // Compute Y-axis offset correction value
   char Z_Accel_offset = -((Zout_Accel - calibration2G) / calibrationFactor);  // Compute Z-axis offset correction value

   writeReg(OFF_X, X_Accel_offset);
   writeReg(OFF_Y, Y_Accel_offset);
   writeReg(OFF_Z, Z_Accel_offset);

   // Restore original settings
   writeReg(CTRL_REG1, originalControlReg1Value);
}
