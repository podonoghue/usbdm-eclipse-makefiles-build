/*
 ============================================================================
 * @file   vl53l0x.cpp (180.ARM_Peripherals/Snippets)
 * @brief  Basic vl53l0x interface
 *
 * Lightly modified from https://github.com/pololu/vl53l0x-arduino
 ============================================================================
 */

// Most of the functionality of this library is based on the VL53L0X API
// provided by ST (STSW-IMG005), and some of the explanatory comments are quoted
// or paraphrased from the API source code, API user manual (UM2039), and the
// VL53L0X data-sheet.

#include <string.h>
#include "vl53l0x.h"

using namespace USBDM;

/** Default I2C Address (8-bit, LSB = R/W = 0) */
constexpr int  ADDRESS_DEFAULT  = 0b01010010;

/**
 * Record the current time to check an upcoming timeout against
 */
static void startTimeout() {
   //   (timeout_start_ms = millis())
}

/**
 * Check if timeout is enabled (set to nonzero value) and has expired
 *
 * @return
 */
static bool checkTimeoutExpired() {
   //   (io_timeout > 0 && ((uint16_t)millis() - timeout_start_ms) > io_timeout)
   return false;
}

/**
 * Decode VCSEL (vertical cavity surface emitting laser) pulse period in PCLKs
 * from register value.
 *
 * @note Based on VL53L0X_decode_vcsel_period()
 *
 * @param reg_val
 *
 * @return
 */
static constexpr uint32_t decodeVcselPeriod(uint32_t reg_val) {
   return (((reg_val) + 1) << 1);
}

/**
 * Encode VCSEL pulse period register value from period in PCLKs
 * based on VL53L0X_encode_vcsel_period()
 *
 * @param period_pclks
 * @return
 */
static constexpr uint32_t encodeVcselPeriod(uint32_t period_pclks) {
   return (((period_pclks) >> 1) - 1);
}

/**
 * Calculate macro period in *nanoseconds* from VCSEL period in PCLKs
 * based on VL53L0X_calc_macro_period_ps()
 * PLL_period_ps = 1655; macro_period_vclks = 2304
 *
 * @param vcsel_period_pclks
 * @return
 */
static constexpr uint32_t calcMacroPeriod(uint32_t vcsel_period_pclks) {
   return ((((uint32_t)2304 * (vcsel_period_pclks) * 1655) + 500) / 1000);
}

/**
 * Constructor
 *
 * @param i2c Interface to use
 */
VL53L0X::VL53L0X(I2c &i2c) :
         i2c(i2c),
         last_status(E_NO_ERROR),
         address(ADDRESS_DEFAULT),
         io_timeout(0),
         did_timeout(false),
         timeout_start_ms(0),
         stop_variable(0),
         measurement_timing_budget_us(0) {
}

/**
 * Set I2C device address
 *
 * @param[in] new_addr Address to set
 */
void VL53L0X::setAddress(uint8_t new_addr) {
   writeReg(I2C_SLAVE_DEVICE_ADDRESS, new_addr & 0x7F);
   address = new_addr;
}

/**
 * Initialise interface
 *
 * Initialize sensor using sequence based on:
 *   VL53L0X_DataInit(),
 *   VL53L0X_StaticInit() and
 *   VL53L0X_PerformRefCalibration().
 *
 * This function does not perform reference SPAD calibration (VL53L0X_PerformRefSpadManagement()),
 * since the API user manual says that it is performed by ST on the bare modules;
 * it seems like that should work well enough unless a cover glass is added.
 *
 * @param io_2v8 Whether to use 2.3V I/0 levels (otherwise 1.8V)
 *
 * @return E_NO_ERROR on success
 */
ErrorCode VL53L0X::init(bool io_2v8) {

   last_status = E_NO_ERROR;

   // VL53L0X_DataInit() begin

   // Sensor uses 1V8 mode for I/O by default; switch to 2V8 mode as required
   if (io_2v8) {
      writeReg(
            VHV_CONFIG_PAD_SCL_SDA__EXTSUP_HV,
            readReg(VHV_CONFIG_PAD_SCL_SDA__EXTSUP_HV) | 0b00000001);
      if (last_status != E_NO_ERROR) {
         return last_status;
      }
   }

   // Set I2C standard mode
   writeReg(0x88, 0x00);

   writeReg(0x80, 0x01);
   writeReg(0xFF, 0x01);
   writeReg(0x00, 0x00);
   stop_variable = readReg(0x91);
   writeReg(0x00, 0x01);
   writeReg(0xFF, 0x00);
   writeReg(0x80, 0x00);

   // Disable SIGNAL_RATE_MSRC (bit 1) and SIGNAL_RATE_PRE_RANGE (bit 4) limit checks
   writeReg(MSRC_CONFIG_CONTROL, readReg(MSRC_CONFIG_CONTROL) | 0b00010010);

   // Set final range signal rate limit to 0.25 MCPS (million counts per second)
   setSignalRateLimit(0.25);

   writeReg(SYSTEM_SEQUENCE_CONFIG, 0xFF);

   // VL53L0X_DataInit() end

   // VL53L0X_StaticInit() begin

   uint8_t spad_count;
   bool spad_type_is_aperture;
   if (!getSpadInfo(&spad_count, &spad_type_is_aperture)) {
      return E_CALIBRATE_FAIL;
   }

   // The SPAD map (RefGoodSpadMap) is read by VL53L0X_get_info_from_device() in
   // the API, but the same data seems to be more easily readable from
   // GLOBAL_CONFIG_SPAD_ENABLES_REF_0 through _6, so read it from there
   uint8_t ref_spad_map[6];
   readMulti(GLOBAL_CONFIG_SPAD_ENABLES_REF_0, ref_spad_map, 6);

   // -- VL53L0X_set_reference_spads() begin (assume NVM values are valid)

   writeReg(0xFF, 0x01);
   writeReg(DYNAMIC_SPAD_REF_EN_START_OFFSET, 0x00);
   writeReg(DYNAMIC_SPAD_NUM_REQUESTED_REF_SPAD, 0x2C);
   writeReg(0xFF, 0x00);
   writeReg(GLOBAL_CONFIG_REF_EN_START_SELECT, 0xB4);

   uint8_t first_spad_to_enable = spad_type_is_aperture ? 12 : 0; // 12 is the first aperture spad
   uint8_t spads_enabled = 0;

   for (uint8_t i = 0; i < 48; i++) {
      if (i < first_spad_to_enable || spads_enabled == spad_count) {
         // This bit is lower than the first one that should be enabled, or
         // (reference_spad_count) bits have already been enabled, so zero this bit
         ref_spad_map[i / 8] &= ~(1 << (i % 8));
      }
      else if ((ref_spad_map[i / 8] >> (i % 8)) & 0x1) {
         spads_enabled++;
      }
   }

   writeMulti(GLOBAL_CONFIG_SPAD_ENABLES_REF_0, ref_spad_map, 6);

   // -- VL53L0X_set_reference_spads() end

   // -- VL53L0X_load_tuning_settings() begin
   // DefaultTuningSettings from vl53l0x_tuning.h

   static const struct {
      uint8_t reg;
      uint8_t data;
   } calData[] = {
         // RegNum Data         RegNum Data         RegNum Data         RegNum Data
         {  0xFF,  0x01,  }, {  0x00,  0x00,  },

         {  0xFF,  0x00,  }, {  0x09,  0x00,  }, {  0x10,  0x00,  }, {  0x11,  0x00,  },

         {  0x24,  0x01,  }, {  0x25,  0xFF,  }, {  0x75,  0x00,  },

         {  0xFF,  0x01,  }, {  0x4E,  0x2C,  }, {  0x48,  0x00,  }, {  0x30,  0x20,  },

         {  0xFF,  0x00,  }, {  0x30,  0x09,  }, {  0x54,  0x00,  }, {  0x31,  0x04,  },
         {  0x32,  0x03,  }, {  0x40,  0x83,  }, {  0x46,  0x25,  }, {  0x60,  0x00,  },
         {  0x27,  0x00,  }, {  0x50,  0x06,  }, {  0x51,  0x00,  }, {  0x52,  0x96,  },
         {  0x56,  0x08,  }, {  0x57,  0x30,  }, {  0x61,  0x00,  }, {  0x62,  0x00,  },
         {  0x64,  0x00,  }, {  0x65,  0x00,  }, {  0x66,  0xA0,  },

         {  0xFF,  0x01,  }, {  0x22,  0x32,  }, {  0x47,  0x14,  }, {  0x49,  0xFF,  },
         {  0x4A,  0x00,  },

         {  0xFF,  0x00,  }, {  0x7A,  0x0A,  }, {  0x7B,  0x00,  }, {  0x78,  0x21,  },

         {  0xFF,  0x01,  }, {  0x23,  0x34,  }, {  0x42,  0x00,  }, {  0x44,  0xFF,  },
         {  0x45,  0x26,  }, {  0x46,  0x05,  }, {  0x40,  0x40,  }, {  0x0E,  0x06,  },
         {  0x20,  0x1A,  }, {  0x43,  0x40,  },

         {  0xFF,  0x00,  }, {  0x34,  0x03,  }, {  0x35,  0x44,  },

         {  0xFF,  0x01,  }, {  0x31,  0x04,  }, {  0x4B,  0x09,  }, {  0x4C,  0x05,  },
         {  0x4D,  0x04,  },

         {  0xFF,  0x00,  }, {  0x44,  0x00,  }, {  0x45,  0x20,  }, {  0x47,  0x08,  },
         {  0x48,  0x28,  }, {  0x67,  0x00,  }, {  0x70,  0x04,  }, {  0x71,  0x01,  },
         {  0x72,  0xFE,  }, {  0x76,  0x00,  }, {  0x77,  0x00,  },

         {  0xFF,  0x01,  }, {  0x0D,  0x01,  },

         {  0xFF,  0x00,  }, {  0x80,  0x01,  }, {  0x01,  0xF8,  },

         {  0xFF,  0x01,  }, {  0x8E,  0x01,  }, {  0x00,  0x01,  }, {  0xFF,  0x00,  },
         {  0x80,  0x00,  },
   };
   for (unsigned index=0; index<sizeof(calData)/sizeof(calData[0]); index++) {
      writeReg(calData[index].reg, calData[index].data);
   }

   // -- VL53L0X_load_tuning_settings() end

   // "Set interrupt config to new sample ready"
   // -- VL53L0X_SetGpioConfig() begin

   writeReg(SYSTEM_INTERRUPT_CONFIG_GPIO, 0x04);
   writeReg(GPIO_HV_MUX_ACTIVE_HIGH, readReg(GPIO_HV_MUX_ACTIVE_HIGH) & ~0x10); // active low
   writeReg(SYSTEM_INTERRUPT_CLEAR, 0x01);

   // -- VL53L0X_SetGpioConfig() end

   measurement_timing_budget_us = getMeasurementTimingBudget();

   // "Disable MSRC and TCC by default"
   // MSRC = Minimum Signal Rate Check
   // TCC = Target CentreCheck
   // -- VL53L0X_SetSequenceStepEnable() begin

   writeReg(SYSTEM_SEQUENCE_CONFIG, 0xE8);

   // -- VL53L0X_SetSequenceStepEnable() end

   // "Recalculate timing budget"
   setMeasurementTimingBudget(measurement_timing_budget_us);

   // VL53L0X_StaticInit() end

   // VL53L0X_PerformRefCalibration() begin (VL53L0X_perform_ref_calibration())

   // -- VL53L0X_perform_vhv_calibration() begin

   writeReg(SYSTEM_SEQUENCE_CONFIG, 0x01);
   if (performSingleRefCalibration(0x40) != E_NO_ERROR) {
      return E_CALIBRATE_FAIL;
   }

   // -- VL53L0X_perform_vhv_calibration() end

   // -- VL53L0X_perform_phase_calibration() begin

   writeReg(SYSTEM_SEQUENCE_CONFIG, 0x02);
   if (performSingleRefCalibration(0x00) != E_NO_ERROR) {
      return E_CALIBRATE_FAIL;
   }

   // -- VL53L0X_perform_phase_calibration() end

   // Restore the previous Sequence Configuration
   writeReg(SYSTEM_SEQUENCE_CONFIG, 0xE8);

   // VL53L0X_PerformRefCalibration() end

   return E_NO_ERROR;
}

/**
 * Write 8-bit value to device register
 *
 * @param regNum  Device register index
 * @param value   Value to write to register
 */
void VL53L0X::writeReg(uint8_t regNum, uint8_t value) {
   uint8_t command[] = {regNum, value};
   last_status = i2c.transmit(address, command);
}

/**
 * Write 16-bit value to device register(s)
 *
 * @param regNum  Starting device register index
 * @param value   Value to write to register
 */
void VL53L0X::writeReg16Bit(uint8_t regNum, uint16_t value) {
   uint8_t command[] = {regNum, (uint8_t)(value>>8), (uint8_t)value};
   last_status = i2c.transmit(address, command);
}

/**
 * Write 32-bit value to device register(s)
 *
 * @param regNum  Starting device register index
 * @param value   Value to write to register
 */
void VL53L0X::writeReg32Bit(uint8_t regNum, uint32_t value) {
   uint8_t command[] = {regNum, (uint8_t)(value>>24), (uint8_t)(value>>16), (uint8_t)(value>>8), (uint8_t)value};
   last_status = i2c.transmit(address, command);
}

/**
 * Read 8-bit value from device register
 *
 * @param regNum  Device register index
 *
 * @return Value read
 */
uint8_t VL53L0X::readReg(uint8_t regNum) {
   uint8_t response[1];
   last_status = i2c.txRx(address, 1, &regNum, response);
   return response[0];
}

/**
 * Read 16-bit value from device register(s)
 *
 * @param regNum  Starting device register index
 *
 * @return Value read
 */
uint16_t VL53L0X::readReg16Bit(uint8_t regNum) {
   uint8_t response[2];
   last_status = i2c.txRx(address, 1, &regNum, response);
   return (response[0]<<8)|response[1];
}

/**
 * Read 32-bit value from device register(s)
 *
 * @param regNum  Starting device register index
 *
 * @return Value read
 */
uint32_t VL53L0X::readReg32Bit(uint8_t regNum) {
   uint8_t response[4];
   last_status = i2c.txRx(address, 1, &regNum, response);
   return (response[0]<<24)|(response[1]<<16)|(response[2]<<8)|response[3];
}

/**
 * Write multi-byte value to device register(s)
 *
 * @param regNum  Starting device register index
 * @param src     Where to obtain data
 * @param count   Number of bytes to write
 */
void VL53L0X::writeMulti(uint8_t regNum, uint8_t const *src, uint8_t count) {
   uint8_t buff[count+2];
   buff[0] = address;
   buff[1] = regNum;
   memcpy(buff+2, src, count);
   last_status = i2c.transmit(address, count+2, buff);
}

/**
 * Read multi-byte value from device register(s)
 *
 * @param regNum  Starting device register index
 * @param dst     Where to write data
 * @param count   Number of bytes to read
 */
void VL53L0X::readMulti(uint8_t regNum, uint8_t *dst, uint8_t count) {
   last_status = i2c.txRx(address, 1, &regNum, count, dst);
}

/**
 * Set the return signal rate limit check value in units of MCPS (mega-counts
 * per second). "This represents the amplitude of the signal reflected from the
 * target and detected by the device"; setting this limit presumably determines
 * the minimum measurement necessary for the sensor to report a valid reading.
 * Setting a lower limit increases the potential range of the sensor but also
 * seems to increase the likelihood of getting an inaccurate reading because of
 * unwanted reflections from objects other than the intended target.
 *
 * Defaults to 0.25 MCPS as initialized by the ST API and this library.
 *
 * @param limit_Mcps
 *
 * @return E_NO_ERROR       No error
 * @return E_ILLEGAL_PARAM  Error limit_Mcps is out of range
 */
ErrorCode VL53L0X::setSignalRateLimit(float limit_Mcps) {
   if (limit_Mcps < 0 || limit_Mcps > 511.99) {
      return E_ILLEGAL_PARAM;
   }

   // Q9.7 fixed point format (9 integer bits, 7 fractional bits)
   writeReg16Bit(FINAL_RANGE_CONFIG_MIN_COUNT_RATE_RTN_LIMIT, (uint16_t)(limit_Mcps * (1 << 7)));

   return E_NO_ERROR;
}

/**
 *  Get the return signal rate limit check value in MCPS
 *
 * @return return signal rate
 */
float VL53L0X::getSignalRateLimit() {
   return (float)readReg16Bit(FINAL_RANGE_CONFIG_MIN_COUNT_RATE_RTN_LIMIT) / (1 << 7);
}

/**
 * Set the measurement timing budget in microseconds, which is the time allowed
 * for one measurement; the ST API and this library take care of splitting the
 * timing budget among the sub-steps in the ranging sequence. A longer timing
 * budget allows for more accurate measurements. Increasing the budget by a
 * factor of N decreases the range measurement standard deviation by a factor of
 * sqrt(N). Defaults to about 33 milliseconds; the minimum is 20 ms.
 * based on VL53L0X_set_measurement_timing_budget_micro_seconds()
 *
 * @param budget_us
 *
 * @return E_NO_ERROR       No error
 * @return E_ILLEGAL_PARAM  Error budget_us is out of range
 */
ErrorCode VL53L0X::setMeasurementTimingBudget(uint32_t budget_us) {
   SequenceStepEnables enables;
   SequenceStepTimeouts timeouts;

   uint16_t const StartOverhead      = 1320; // note that this is different than the value in get_
   uint16_t const EndOverhead        = 960;
   uint16_t const MsrcOverhead       = 660;
   uint16_t const TccOverhead        = 590;
   uint16_t const DssOverhead        = 690;
   uint16_t const PreRangeOverhead   = 660;
   uint16_t const FinalRangeOverhead = 550;

   uint32_t const MinTimingBudget = 20000;

   if (budget_us < MinTimingBudget) {
      return E_ILLEGAL_PARAM;
   }

   uint32_t used_budget_us = StartOverhead + EndOverhead;

   enables = getSequenceStepEnables();
   getSequenceStepTimeouts(enables, &timeouts);

   if (enables & TCC) {
      used_budget_us += (timeouts.msrc_dss_tcc_us + TccOverhead);
   }

   if (enables & DSS) {
      used_budget_us += 2 * (timeouts.msrc_dss_tcc_us + DssOverhead);
   }
   else if (enables & MSRC) {
      used_budget_us += (timeouts.msrc_dss_tcc_us + MsrcOverhead);
   }

   if (enables & PRE_RANGE) {
      used_budget_us += (timeouts.pre_range_us + PreRangeOverhead);
   }

   if (enables & FINAL_RANGE) {
      used_budget_us += FinalRangeOverhead;

      // "Note that the final range timeout is determined by the timing
      // budget and the sum of all other timeouts within the sequence.
      // If there is no room for the final range timeout, then an error
      // will be set. Otherwise the remaining time will be applied to
      // the final range."

      if (used_budget_us > budget_us) {
         // "Requested timeout too big."
         return E_ILLEGAL_PARAM;
      }

      uint32_t final_range_timeout_us = budget_us - used_budget_us;

      // set_sequence_step_timeout() begin
      // (SequenceStepId == VL53L0X_SEQUENCESTEP_FINAL_RANGE)

      // "For the final range timeout, the pre-range timeout
      //  must be added. To do this both final and pre-range
      //  timeouts must be expressed in macro periods MClks
      //  because they have different vcsel periods."

      uint16_t final_range_timeout_mclks =
            timeoutMicrosecondsToMclks(final_range_timeout_us,
                  timeouts.final_range_vcsel_period_pclks);

      if (enables & PRE_RANGE) {
         final_range_timeout_mclks += timeouts.pre_range_mclks;
      }

      writeReg16Bit(FINAL_RANGE_CONFIG_TIMEOUT_MACROP_HI,
            encodeTimeout(final_range_timeout_mclks));

      // set_sequence_step_timeout() end

      measurement_timing_budget_us = budget_us; // store for internal reuse
   }
   return E_NO_ERROR;
}

/**
 * Get the measurement timing budget in microseconds
 * based on VL53L0X_get_measurement_timing_budget_micro_seconds()
 * in us
 *
 * @return
 */
uint32_t VL53L0X::getMeasurementTimingBudget() {
   SequenceStepEnables enables;
   SequenceStepTimeouts timeouts;

   uint16_t const StartOverhead     = 1910; // note that this is different than the value in set_
   uint16_t const EndOverhead        = 960;
   uint16_t const MsrcOverhead       = 660;
   uint16_t const TccOverhead        = 590;
   uint16_t const DssOverhead        = 690;
   uint16_t const PreRangeOverhead   = 660;
   uint16_t const FinalRangeOverhead = 550;

   // "Start and end overhead times always present"
   uint32_t budget_us = StartOverhead + EndOverhead;

   enables = getSequenceStepEnables();
   getSequenceStepTimeouts(enables, &timeouts);

   if (enables & TCC) {
      budget_us += (timeouts.msrc_dss_tcc_us + TccOverhead);
   }
   if (enables & DSS) {
      budget_us += 2 * (timeouts.msrc_dss_tcc_us + DssOverhead);
   }
   else if (enables & MSRC) {
      budget_us += (timeouts.msrc_dss_tcc_us + MsrcOverhead);
   }
   if (enables & PRE_RANGE) {
      budget_us += (timeouts.pre_range_us + PreRangeOverhead);
   }
   if (enables & FINAL_RANGE) {
      budget_us += (timeouts.final_range_us + FinalRangeOverhead);
   }
   measurement_timing_budget_us = budget_us; // store for internal reuse
   return budget_us;
}

/**
 * Set the VCSEL (vertical cavity surface emitting laser) pulse period for the
 * given period type (pre-range or final range) to the given value in PCLKs.
 * Longer periods seem to increase the potential range of the sensor.
 *
 * Valid values are (even numbers only):
 *  pre:  12 to 18 (initialized default: 14)
 *  final: 8 to 14 (initialized default: 10)
 * based on VL53L0X_set_vcsel_pulse_period()
 *
 * @param type
 * @param period_pclks
 * @return
 */
bool VL53L0X::setVcselPulsePeriod(vcselPeriodType type, uint8_t period_pclks) {
   uint8_t vcsel_period_reg = encodeVcselPeriod(period_pclks);

   SequenceStepEnables enables;
   SequenceStepTimeouts timeouts;

   enables = getSequenceStepEnables();
   getSequenceStepTimeouts(enables, &timeouts);

   // "Apply specific settings for the requested clock period"
   // "Re-calculate and apply timeouts, in macro periods"

   // "When the VCSEL period for the pre or final range is changed,
   // the corresponding timeout must be read from the device using
   // the current VCSEL period, then the new VCSEL period can be
   // applied. The timeout then must be written back to the device
   // using the new VCSEL period.
   //
   // For the MSRC timeout, the same applies - this timeout being
   // dependant on the pre-range vcsel period."


   if (type == VcselPeriodPreRange) {
      // "Set phase check limits"
      switch (period_pclks) {
         case 12:
            writeReg(PRE_RANGE_CONFIG_VALID_PHASE_HIGH, 0x18);
            break;

         case 14:
            writeReg(PRE_RANGE_CONFIG_VALID_PHASE_HIGH, 0x30);
            break;

         case 16:
            writeReg(PRE_RANGE_CONFIG_VALID_PHASE_HIGH, 0x40);
            break;

         case 18:
            writeReg(PRE_RANGE_CONFIG_VALID_PHASE_HIGH, 0x50);
            break;

         default:
            // invalid period
            return false;
      }
      writeReg(PRE_RANGE_CONFIG_VALID_PHASE_LOW, 0x08);

      // apply new VCSEL period
      writeReg(PRE_RANGE_CONFIG_VCSEL_PERIOD, vcsel_period_reg);

      // update timeouts

      // set_sequence_step_timeout() begin
      // (SequenceStepId == VL53L0X_SEQUENCESTEP_PRE_RANGE)

      uint16_t new_pre_range_timeout_mclks =
            timeoutMicrosecondsToMclks(timeouts.pre_range_us, period_pclks);

      writeReg16Bit(PRE_RANGE_CONFIG_TIMEOUT_MACROP_HI,
            encodeTimeout(new_pre_range_timeout_mclks));

      // set_sequence_step_timeout() end

      // set_sequence_step_timeout() begin
      // (SequenceStepId == VL53L0X_SEQUENCESTEP_MSRC)

      uint16_t new_msrc_timeout_mclks =
            timeoutMicrosecondsToMclks(timeouts.msrc_dss_tcc_us, period_pclks);

      writeReg(MSRC_CONFIG_TIMEOUT_MACROP,
            (new_msrc_timeout_mclks > 256) ? 255 : (new_msrc_timeout_mclks - 1));

      // set_sequence_step_timeout() end
   }
   else if (type == VcselPeriodFinalRange) {
      switch (period_pclks) {
         case 8:
            writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x10);
            writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_LOW,  0x08);
            writeReg(GLOBAL_CONFIG_VCSEL_WIDTH, 0x02);
            writeReg(ALGO_PHASECAL_CONFIG_TIMEOUT, 0x0C);
            writeReg(0xFF, 0x01);
            writeReg(ALGO_PHASECAL_LIM, 0x30);
            writeReg(0xFF, 0x00);
            break;

         case 10:
            writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x28);
            writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_LOW,  0x08);
            writeReg(GLOBAL_CONFIG_VCSEL_WIDTH, 0x03);
            writeReg(ALGO_PHASECAL_CONFIG_TIMEOUT, 0x09);
            writeReg(0xFF, 0x01);
            writeReg(ALGO_PHASECAL_LIM, 0x20);
            writeReg(0xFF, 0x00);
            break;

         case 12:
            writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x38);
            writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_LOW,  0x08);
            writeReg(GLOBAL_CONFIG_VCSEL_WIDTH, 0x03);
            writeReg(ALGO_PHASECAL_CONFIG_TIMEOUT, 0x08);
            writeReg(0xFF, 0x01);
            writeReg(ALGO_PHASECAL_LIM, 0x20);
            writeReg(0xFF, 0x00);
            break;

         case 14:
            writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_HIGH, 0x48);
            writeReg(FINAL_RANGE_CONFIG_VALID_PHASE_LOW,  0x08);
            writeReg(GLOBAL_CONFIG_VCSEL_WIDTH, 0x03);
            writeReg(ALGO_PHASECAL_CONFIG_TIMEOUT, 0x07);
            writeReg(0xFF, 0x01);
            writeReg(ALGO_PHASECAL_LIM, 0x20);
            writeReg(0xFF, 0x00);
            break;

         default:
            // invalid period
            return false;
      }

      // apply new VCSEL period
      writeReg(FINAL_RANGE_CONFIG_VCSEL_PERIOD, vcsel_period_reg);

      // update timeouts

      // set_sequence_step_timeout() begin
      // (SequenceStepId == VL53L0X_SEQUENCESTEP_FINAL_RANGE)

      // "For the final range timeout, the pre-range timeout
      //  must be added. To do this both final and pre-range
      //  timeouts must be expressed in macro periods MClks
      //  because they have different vcsel periods."

      uint16_t new_final_range_timeout_mclks =
            timeoutMicrosecondsToMclks(timeouts.final_range_us, period_pclks);

      if (enables & PRE_RANGE) {
         new_final_range_timeout_mclks += timeouts.pre_range_mclks;
      }

      writeReg16Bit(FINAL_RANGE_CONFIG_TIMEOUT_MACROP_HI,
            encodeTimeout(new_final_range_timeout_mclks));

      // set_sequence_step_timeout end
   }
   else {
      // invalid type
      return false;
   }

   // "Finally, the timing budget must be re-applied"

   setMeasurementTimingBudget(measurement_timing_budget_us);

   // "Perform the phase calibration. This is needed after changing on vcsel period."
   // VL53L0X_perform_phase_calibration() begin

   uint8_t sequence_config = readReg(SYSTEM_SEQUENCE_CONFIG);
   writeReg(SYSTEM_SEQUENCE_CONFIG, 0x02);
   performSingleRefCalibration(0x0);
   writeReg(SYSTEM_SEQUENCE_CONFIG, sequence_config);

   // VL53L0X_perform_phase_calibration() end

   return true;
}

/**
 * Get the VCSEL pulse period in PCLKs for the given period type.
 * based on VL53L0X_get_vcsel_pulse_period()
 *
 * @param type
 *
 * @return
 */
uint8_t VL53L0X::getVcselPulsePeriod(vcselPeriodType type) {
   if (type == VcselPeriodPreRange) {
      return decodeVcselPeriod(readReg(PRE_RANGE_CONFIG_VCSEL_PERIOD));
   }
   else if (type == VcselPeriodFinalRange) {
      return decodeVcselPeriod(readReg(FINAL_RANGE_CONFIG_VCSEL_PERIOD));
   }
   else {
      return 255;
   }
}

/**
 *
 *  Start continuous ranging measurements. If period_ms (optional) is 0 or not
 *  given, continuous back-to-back mode is used (the sensor takes measurements as
 *  often as possible); otherwise, continuous timed mode is used, with the given
 *  inter-measurement period in milliseconds determining how often the sensor
 *  takes a measurement.
 *  based on VL53L0X_StartMeasurement()
 * @param period_ms
 */
void VL53L0X::startContinuous(uint32_t period_ms) {
   writeReg(0x80, 0x01);
   writeReg(0xFF, 0x01);
   writeReg(0x00, 0x00);
   writeReg(0x91, stop_variable);
   writeReg(0x00, 0x01);
   writeReg(0xFF, 0x00);
   writeReg(0x80, 0x00);

   if (period_ms != 0) {
      // continuous timed mode

      // VL53L0X_SetInterMeasurementPeriodMilliSeconds() begin

      uint16_t osc_calibrate_val = readReg16Bit(OSC_CALIBRATE_VAL);

      if (osc_calibrate_val != 0) {
         period_ms *= osc_calibrate_val;
      }

      writeReg32Bit(SYSTEM_INTERMEASUREMENT_PERIOD, period_ms);

      // VL53L0X_SetInterMeasurementPeriodMilliSeconds() end

      writeReg(SYSRANGE_START, 0x04); // VL53L0X_REG_SYSRANGE_MODE_TIMED
   }
   else {
      // continuous back-to-back mode
      writeReg(SYSRANGE_START, 0x02); // VL53L0X_REG_SYSRANGE_MODE_BACKTOBACK
   }
}

/**
 *
 * Stop continuous measurements
 * based on VL53L0X_StopMeasurement()
 */
void VL53L0X::stopContinuous() {
   writeReg(SYSRANGE_START, 0x01); // VL53L0X_REG_SYSRANGE_MODE_SINGLESHOT

   writeReg(0xFF, 0x01);
   writeReg(0x00, 0x00);
   writeReg(0x91, 0x00);
   writeReg(0x00, 0x01);
   writeReg(0xFF, 0x00);
}

/**
 *
 * Returns a range reading in millimetres when continuous mode is active
 * (readRangeSingleMillimetres() also calls this function after starting a
 * single-shot range measurement)
 *
 * @return
 */
uint16_t VL53L0X::readRangeContinuousMillimetres() {
   startTimeout();
   while ((readReg(RESULT_INTERRUPT_STATUS) & 0x07) == 0) {
      if (checkTimeoutExpired()) {
         did_timeout = true;
         return 65535;
      }
   }
   // assumptions: Linearity Corrective Gain is 1000 (default);
   // fractional ranging is not enabled
   uint16_t range = readReg16Bit(RESULT_RANGE_STATUS + 10);

   writeReg(SYSTEM_INTERRUPT_CLEAR, 0x01);

   return range;
}

/**
 *
 * Performs a single-shot range measurement and returns the reading in millimetres
 * based on VL53L0X_PerformSingleRangingMeasurement()
 *
 * @return
 */
uint16_t VL53L0X::readRangeSingleMillimetres() {
   writeReg(0x80, 0x01);
   writeReg(0xFF, 0x01);
   writeReg(0x00, 0x00);
   writeReg(0x91, stop_variable);
   writeReg(0x00, 0x01);
   writeReg(0xFF, 0x00);
   writeReg(0x80, 0x00);

   writeReg(SYSRANGE_START, 0x01);

   // "Wait until start bit has been cleared"
   startTimeout();
   while (readReg(SYSRANGE_START) & 0x01) {
      if (checkTimeoutExpired()) {
         did_timeout = true;
         return 65535;
      }
   }
   return readRangeContinuousMillimetres();
}

/**
 *  Did a timeout occur in one of the read functions since the last call to
 *  timeoutOccurred()?
 *
 *  @return
 */
bool VL53L0X::timeoutOccurred() {
   bool tmp = did_timeout;
   did_timeout = false;
   return tmp;
}

/**
 *
 * Get reference SPAD (single photon avalanche diode) count and type
 * based on VL53L0X_get_info_from_device(),
 * but only gets reference SPAD count and type
 *
 * @param count
 * @param type_is_aperture
 * @return
 */
bool VL53L0X::getSpadInfo(uint8_t *count, bool *type_is_aperture) {
   uint8_t tmp;

   writeReg(0x80, 0x01);
   writeReg(0xFF, 0x01);
   writeReg(0x00, 0x00);

   writeReg(0xFF, 0x06);
   writeReg(0x83, readReg(0x83) | 0x04);
   writeReg(0xFF, 0x07);
   writeReg(0x81, 0x01);

   writeReg(0x80, 0x01);

   writeReg(0x94, 0x6b);
   writeReg(0x83, 0x00);
   startTimeout();
   while (readReg(0x83) == 0x00) {
      if (checkTimeoutExpired()) {
         return false;
      }
   }
   writeReg(0x83, 0x01);
   tmp = readReg(0x92);

   *count = tmp & 0x7f;
   *type_is_aperture = (tmp >> 7) & 0x01;

   writeReg(0x81, 0x00);
   writeReg(0xFF, 0x06);
   writeReg(0x83, readReg(0x83)  & ~0x04);
   writeReg(0xFF, 0x01);
   writeReg(0x00, 0x01);

   writeReg(0xFF, 0x00);
   writeReg(0x80, 0x00);

   return true;
}

/**
 *
 * Get sequence step enables
 * based on VL53L0X_GetSequenceStepEnables()
 *
 * @return Bit mask for enables
 */
VL53L0X::SequenceStepEnables VL53L0X::getSequenceStepEnables() {
   return (SequenceStepEnables) readReg(SYSTEM_SEQUENCE_CONFIG);

//   enables->tcc          = (sequence_config >> 4) & 0x1;
//   enables->dss          = (sequence_config >> 3) & 0x1;
//   enables->msrc         = (sequence_config >> 2) & 0x1;
//   enables->pre_range    = (sequence_config >> 6) & 0x1;
//   enables->final_range  = (sequence_config >> 7) & 0x1;
}

/**
 *
 * Get sequence step timeouts
 * based on get_sequence_step_timeout(),
 * but gets all timeouts instead of just the requested one, and also stores
 * intermediate values
 *
 * @param enables
 * @param timeouts
 */
void VL53L0X::getSequenceStepTimeouts(SequenceStepEnables const enables, SequenceStepTimeouts * timeouts) {
   timeouts->pre_range_vcsel_period_pclks = getVcselPulsePeriod(VcselPeriodPreRange);

   timeouts->msrc_dss_tcc_mclks = readReg(MSRC_CONFIG_TIMEOUT_MACROP) + 1;
   timeouts->msrc_dss_tcc_us =
         timeoutMclksToMicroseconds(timeouts->msrc_dss_tcc_mclks,
               timeouts->pre_range_vcsel_period_pclks);

   timeouts->pre_range_mclks =
         decodeTimeout(readReg16Bit(PRE_RANGE_CONFIG_TIMEOUT_MACROP_HI));
   timeouts->pre_range_us =
         timeoutMclksToMicroseconds(timeouts->pre_range_mclks,
               timeouts->pre_range_vcsel_period_pclks);

   timeouts->final_range_vcsel_period_pclks = getVcselPulsePeriod(VcselPeriodFinalRange);

   timeouts->final_range_mclks =
         decodeTimeout(readReg16Bit(FINAL_RANGE_CONFIG_TIMEOUT_MACROP_HI));

   if (enables & PRE_RANGE) {
      timeouts->final_range_mclks -= timeouts->pre_range_mclks;
   }

   timeouts->final_range_us =
         timeoutMclksToMicroseconds(timeouts->final_range_mclks,
               timeouts->final_range_vcsel_period_pclks);
}

/**
 *
 * Decode sequence step timeout in MCLKs from register value
 * based on VL53L0X_decode_timeout()
 * Note: the original function returned a uint32_t, but the return value is
 * always stored in a uint16_t.
 *
 * @param reg_val
 * @return
 */
uint16_t VL53L0X::decodeTimeout(uint16_t reg_val) {
   // format: "(LSByte * 2^MSByte) + 1"
   return (uint16_t)((reg_val & 0x00FF) <<
         (uint16_t)((reg_val & 0xFF00) >> 8)) + 1;
}

/**
 *
 * Encode sequence step timeout register value from timeout in MCLKs
 * based on VL53L0X_encode_timeout()
 * Note: the original function took a uint16_t, but the argument passed to it
 * is always a uint16_t.
 *
 * @param timeout_mclks
 * @return
 */
uint16_t VL53L0X::encodeTimeout(uint16_t timeout_mclks) {
   // format: "(LSByte * 2^MSByte) + 1"

   uint32_t ls_byte = 0;
   uint16_t ms_byte = 0;

   if (timeout_mclks > 0) {
      ls_byte = timeout_mclks - 1;

      while ((ls_byte & 0xFFFFFF00) > 0) {
         ls_byte >>= 1;
         ms_byte++;
      }
      return (ms_byte << 8) | (ls_byte & 0xFF);
   }
   else { return 0; }
}

/**
 *
 * Convert sequence step timeout from MCLKs to microseconds with given VCSEL period in PCLKs
 * based on VL53L0X_calc_timeout_us()
 *
 * @param timeout_period_mclks
 * @param vcsel_period_pclks
 * @return
 */
uint32_t VL53L0X::timeoutMclksToMicroseconds(uint16_t timeout_period_mclks, uint8_t vcsel_period_pclks) {
   uint32_t macro_period_ns = calcMacroPeriod(vcsel_period_pclks);

   return ((timeout_period_mclks * macro_period_ns) + (macro_period_ns / 2)) / 1000;
}

/**
 *
 * Convert sequence step timeout from microseconds to MCLKs with given VCSEL period in PCLKs
 * based on VL53L0X_calc_timeout_mclks()
 *
 * @param timeout_period_us
 * @param vcsel_period_pclks
 * @return
 */
uint32_t VL53L0X::timeoutMicrosecondsToMclks(uint32_t timeout_period_us, uint8_t vcsel_period_pclks) {
   uint32_t macro_period_ns = calcMacroPeriod(vcsel_period_pclks);

   return (((timeout_period_us * 1000) + (macro_period_ns / 2)) / macro_period_ns);
}

/**
 *
 * Based on VL53L0X_perform_single_ref_calibration()
 *
 * @param vhv_init_byte
 * @return
 */
ErrorCode VL53L0X::performSingleRefCalibration(uint8_t vhv_init_byte) {
   writeReg(SYSRANGE_START, 0x01 | vhv_init_byte); // VL53L0X_REG_SYSRANGE_MODE_START_STOP

   startTimeout();
   while ((readReg(RESULT_INTERRUPT_STATUS) & 0x07) == 0) {
      if (checkTimeoutExpired()) {
         return E_NO_COMMUNICATION;
      }
   }
   writeReg(SYSTEM_INTERRUPT_CLEAR, 0x01);
   writeReg(SYSRANGE_START, 0x00);
   return E_NO_ERROR;
}
