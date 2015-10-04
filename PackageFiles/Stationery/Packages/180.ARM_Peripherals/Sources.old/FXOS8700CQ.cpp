/**
 * @file FXOS8700CQ.cpp
 *
 *  Created on: 22/11/2013
 *      Author: podonoghue
 */
#include "FXOS8700CQ.h"

#define FXOS8700CQ_CTRL_REG1_ACTIVE_MASK (1<<0)

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
FXOS8700CQ::FXOS8700CQ(I2C *i2c, AccelerometerMode AccelerometerMode) : i2c(i2c) {
   if (readReg(WHO_AM_I) != WHO_AM_I_VALUE) {
      failedInit = true;
   }
   reset();
   setAccelerometerMode(AccelerometerMode);
   failedInit = false;
}

/**
 * Read Accelerometer register
 *
 * @param regNum  - Register number
 */
uint8_t FXOS8700CQ::readReg(uint8_t regNum) {
   uint8_t command[] = {regNum};

   i2c->receive(DEVICE_ADDRESS, command, sizeof(command));
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

#define CTRL_REG2_RESET_MASK (1<<6) // Reset accelerometer

/**
 * Reset Accelerometer
 */
void FXOS8700CQ::reset(void) {

   writeReg(CTRL_REG2, CTRL_REG2_RESET_MASK);
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
   i2c->receive(DEVICE_ADDRESS, dataXYZ, sizeof(dataXYZ));

   // Unpack data and return (data is sign extended)
   *status = dataXYZ[0];
   *x = ((dataXYZ[1]<<8)+dataXYZ[2]);
   *y = ((dataXYZ[3]<<8)+dataXYZ[4]);
   *z = ((dataXYZ[5]<<8)+dataXYZ[6]);
}

/**
 * Set accelerometer mode (gain and filtering)
 *
 * @param mode - one of 2Gmode etc.
 */
void FXOS8700CQ::setAccelerometerMode(AccelerometerMode mode) {
   standby();
   writeReg(XYZ_DATA_CFG, mode);
   writeReg(M_CTRL_REG1, 0x1F);
   writeReg(M_CTRL_REG2, HYB_AUTOINC_MODE);
   active();
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
   i2c->receive(DEVICE_ADDRESS, dataXYZ, sizeof(dataXYZ));

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
   i2c->receive(DEVICE_ADDRESS, dataXYZ, sizeof(dataXYZ));
   data.accelerometerStatus = dataXYZ[0];
   data.accelerometer_X     = ((dataXYZ[1]<<8)+dataXYZ[2]);
   data.accelerometer_Y     = ((dataXYZ[3]<<8)+dataXYZ[4]);
   data.accelerometer_Z     = ((dataXYZ[5]<<8)+dataXYZ[6]);
   data.magnetometerStatus = dataXYZ[7];
   data.magnetometer_X      = ((dataXYZ[7]<<8)+dataXYZ[8]);
   data.magnetometer_Y      = ((dataXYZ[9]<<8)+dataXYZ[10]);
   data.magnetometer_Z      = ((dataXYZ[10]<<8)+dataXYZ[11]);
}
