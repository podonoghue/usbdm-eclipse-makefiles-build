/**
 * @file MMA845x.cpp
 *
 *  Created on: 22/11/2013
 *      Author: podonoghue
 */
#include "MMA845x.h"

#define MMA45x_CTRL_REG1_ACTIVE_MASK (1<<0)

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
   FF_MT_CFG,
   FF_MT_SRC,
   FF_MT_THS,
   FF_MT_COUNT,
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
};

/*
 * Constructor
 *
 * @param i2c  - The I2C interface to use
 * @param mode - Mode of operation (gain and filtering)
 */
MMA845x::MMA845x(I2C *i2c, Mode mode) : i2c(i2c) {
   reset();
   setMode(mode);
}

/**
 * Read Accelerometer register
 *
 * @param regNum  - Register number
 */
uint8_t MMA845x::readReg(uint8_t regNum) {
   uint8_t command[] = {regNum};

   i2c->receive(deviceAddress, command, sizeof(command));
   return command[0];
}

/**
 * Write Accelerometer register
 *
 * @param regNum  - Register number
 * @param value   - Value to write
 */
void MMA845x::writeReg(uint8_t regNum, uint8_t value) {
   uint8_t command[] = {regNum, value};

   i2c->transmit(deviceAddress, command, sizeof(command));
}

#define CTRL_REG2_RESET_MASK (1<<6) // Reset accelerometer

/**
 * Reset Accelerometer
 */
void MMA845x::reset(void) {

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
void MMA845x::standby() {

   writeReg(CTRL_REG1, readReg(CTRL_REG1)&~MMA45x_CTRL_REG1_ACTIVE_MASK);
}

/**
 * Put accelerometer into Active mode
 */
void MMA845x::active() {

   writeReg(CTRL_REG1, readReg(CTRL_REG1)|MMA45x_CTRL_REG1_ACTIVE_MASK);
}

/**
 * Obtains measurements from the accelerometer
 *
 * @param status  - Indicates status of x, y & z measurements
 * @param x       - X axis value
 * @param y       - Y axis value
 * @param z       - Z axis value
 */
void MMA845x::readXYZ(int *status, int16_t *x, int16_t *y, int16_t *z) {
   uint8_t dataXYZ[7] = {STATUS};

   // Receive 7 registers (status, X-high, X-low, Y-high, Y-low, Z-high & Z-low)
   i2c->receive(deviceAddress, dataXYZ, sizeof(dataXYZ));

   // Unpack data and return (data is sign extended)
   *status = dataXYZ[0];
   *x = ((dataXYZ[1]<<8)+dataXYZ[2]);
   *y = ((dataXYZ[3]<<8)+dataXYZ[4]);
   *z = ((dataXYZ[5]<<8)+dataXYZ[6]);
}

/**
 * Set device mode (gain and filtering)
 *
 * @param mode - one of MMA45x_2Gmode etc.
 */
void MMA845x::setMode(Mode mode) {
   standby();
   writeReg(XYZ_DATA_CFG, mode);
   active();
}

/*!
 * Read ID from accelerometer
 *
 * @return ID value as 8-bit number (0x1A for MMA8451Q)
 */
uint32_t MMA845x::readID(void) {
   uint8_t values[] = {WHO_AM_I};
   i2c->receive(deviceAddress, values, sizeof(values));
   return values[0];
}

