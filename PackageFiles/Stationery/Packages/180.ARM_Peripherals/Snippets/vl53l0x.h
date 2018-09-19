/*
 ============================================================================
 * @file   vl53l0x.h (180.ARM_Peripherals/Snippets)
 * @brief  Basic vl53l0x interface
 *
 * Lightly modified from https://github.com/pololu/vl53l0x-arduino
 ============================================================================
 */
#ifndef INCLUDE_VL53L0X_H
#define INCLUDE_VL53L0X_H

#include <stdint.h>
#include "i2c.h"

class VL53L0X
{
private:

   /** Handle on interface */
   USBDM::I2c &i2c;

   /** Status of last transaction */
   USBDM::ErrorCode last_status;

   /** Device address */
   uint8_t    address;

   uint16_t   io_timeout;
   bool       did_timeout;
   uint16_t   timeout_start_ms;

   // Read by init and used when starting measurement; is StopVariable field of VL53L0X_DevData_t structure in API
   uint8_t    stop_variable;
   uint32_t   measurement_timing_budget_us;

public:
   /**
    * Register addresses from API vl53l0x_device.h (ordered as listed there)
    */
   enum regAddr {
      SYSRANGE_START                              = 0x00,

      SYSTEM_THRESH_HIGH                          = 0x0C,
      SYSTEM_THRESH_LOW                           = 0x0E,

      SYSTEM_SEQUENCE_CONFIG                      = 0x01,
      SYSTEM_RANGE_CONFIG                         = 0x09,
      SYSTEM_INTERMEASUREMENT_PERIOD              = 0x04,

      SYSTEM_INTERRUPT_CONFIG_GPIO                = 0x0A,

      GPIO_HV_MUX_ACTIVE_HIGH                     = 0x84,

      SYSTEM_INTERRUPT_CLEAR                      = 0x0B,

      RESULT_INTERRUPT_STATUS                     = 0x13,
      RESULT_RANGE_STATUS                         = 0x14,

      RESULT_CORE_AMBIENT_WINDOW_EVENTS_RTN       = 0xBC,
      RESULT_CORE_RANGING_TOTAL_EVENTS_RTN        = 0xC0,
      RESULT_CORE_AMBIENT_WINDOW_EVENTS_REF       = 0xD0,
      RESULT_CORE_RANGING_TOTAL_EVENTS_REF        = 0xD4,
      RESULT_PEAK_SIGNAL_RATE_REF                 = 0xB6,

      ALGO_PART_TO_PART_RANGE_OFFSET_MM           = 0x28,

      I2C_SLAVE_DEVICE_ADDRESS                    = 0x8A,

      MSRC_CONFIG_CONTROL                         = 0x60,

      PRE_RANGE_CONFIG_MIN_SNR                    = 0x27,
      PRE_RANGE_CONFIG_VALID_PHASE_LOW            = 0x56,
      PRE_RANGE_CONFIG_VALID_PHASE_HIGH           = 0x57,
      PRE_RANGE_MIN_COUNT_RATE_RTN_LIMIT          = 0x64,

      FINAL_RANGE_CONFIG_MIN_SNR                  = 0x67,
      FINAL_RANGE_CONFIG_VALID_PHASE_LOW          = 0x47,
      FINAL_RANGE_CONFIG_VALID_PHASE_HIGH         = 0x48,
      FINAL_RANGE_CONFIG_MIN_COUNT_RATE_RTN_LIMIT = 0x44,

      PRE_RANGE_CONFIG_SIGMA_THRESH_HI            = 0x61,
      PRE_RANGE_CONFIG_SIGMA_THRESH_LO            = 0x62,

      PRE_RANGE_CONFIG_VCSEL_PERIOD               = 0x50,
      PRE_RANGE_CONFIG_TIMEOUT_MACROP_HI          = 0x51,
      PRE_RANGE_CONFIG_TIMEOUT_MACROP_LO          = 0x52,

      SYSTEM_HISTOGRAM_BIN                        = 0x81,
      HISTOGRAM_CONFIG_INITIAL_PHASE_SELECT       = 0x33,
      HISTOGRAM_CONFIG_READOUT_CTRL               = 0x55,

      FINAL_RANGE_CONFIG_VCSEL_PERIOD             = 0x70,
      FINAL_RANGE_CONFIG_TIMEOUT_MACROP_HI        = 0x71,
      FINAL_RANGE_CONFIG_TIMEOUT_MACROP_LO        = 0x72,
      CROSSTALK_COMPENSATION_PEAK_RATE_MCPS       = 0x20,

      MSRC_CONFIG_TIMEOUT_MACROP                  = 0x46,

      SOFT_RESET_GO2_SOFT_RESET_N                 = 0xBF,
      IDENTIFICATION_MODEL_ID                     = 0xC0,
      IDENTIFICATION_REVISION_ID                  = 0xC2,

      OSC_CALIBRATE_VAL                           = 0xF8,

      GLOBAL_CONFIG_VCSEL_WIDTH                   = 0x32,
      GLOBAL_CONFIG_SPAD_ENABLES_REF_0            = 0xB0,
      GLOBAL_CONFIG_SPAD_ENABLES_REF_1            = 0xB1,
      GLOBAL_CONFIG_SPAD_ENABLES_REF_2            = 0xB2,
      GLOBAL_CONFIG_SPAD_ENABLES_REF_3            = 0xB3,
      GLOBAL_CONFIG_SPAD_ENABLES_REF_4            = 0xB4,
      GLOBAL_CONFIG_SPAD_ENABLES_REF_5            = 0xB5,

      GLOBAL_CONFIG_REF_EN_START_SELECT           = 0xB6,
      DYNAMIC_SPAD_NUM_REQUESTED_REF_SPAD         = 0x4E,
      DYNAMIC_SPAD_REF_EN_START_OFFSET            = 0x4F,
      POWER_MANAGEMENT_GO1_POWER_FORCE            = 0x80,

      VHV_CONFIG_PAD_SCL_SDA__EXTSUP_HV           = 0x89,

      ALGO_PHASECAL_LIM                           = 0x30,
      ALGO_PHASECAL_CONFIG_TIMEOUT                = 0x30,
   };

   enum vcselPeriodType {
      VcselPeriodPreRange,
      VcselPeriodFinalRange,
   };

   /**
    * Constructor
    *
    * @param i2c Interface to use
    */
   VL53L0X(USBDM::I2c &i2c);

   /**
    * Get I2C device address
    *
    * @return Device address
    */
   uint8_t getAddress() {
      return address;
   }

   /**
    * Set I2C device address
    *
    * @param[in] new_addr Address to set
    */
   void setAddress(uint8_t new_addr);

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
   USBDM::ErrorCode init(bool io_2v8 = true);

private:
   /**
    * Write 8-bit value to device register
    *
    * @param regNum  Device register index
    * @param value   Value to write to register
    */
   void writeReg(uint8_t regNum, uint8_t value);

   /**
    * Write 16-bit value to device register(s)
    *
    * @param regNum  Starting device register index
    * @param value   Value to write to register
    */
   void writeReg16Bit(uint8_t regNum, uint16_t value);

   /**
    * Write 32-bit value to device register(s)
    *
    * @param regNum  Starting device register index
    * @param value   Value to write to register
    */
   void writeReg32Bit(uint8_t regNum, uint32_t value);

   /**
    * Read 8-bit value from device register
    *
    * @param regNum  Device register index
    *
    * @return Value read
    */
   uint8_t readReg(uint8_t regNum);

   /**
    * Read 16-bit value from device register(s)
    *
    * @param regNum  Starting device register index
    *
    * @return Value read
    */
   uint16_t readReg16Bit(uint8_t regNum);

   /**
    * Read 32-bit value from device register(s)
    *
    * @param regNum  Starting device register index
    *
    * @return Value read
    */
   uint32_t readReg32Bit(uint8_t regNum);

   /**
    * Write multi-byte value to device register(s)
    *
    * @param regNum  Starting device register index
    * @param src     Where to obtain data
    * @param count   Number of bytes to write
    */
   void writeMulti(uint8_t regNum, uint8_t const * src, uint8_t count);

   /**
    * Read multi-byte value from device register(s)
    *
    * @param regNum  Starting device register index
    * @param dst     Where to write data
    * @param count   Number of bytes to read
    */
   void readMulti(uint8_t regNum, uint8_t * dst, uint8_t count);

public:
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
    * @return E_NO_ERROR No error
    */
   USBDM::ErrorCode setSignalRateLimit(float limit_Mcps);

   /**
    *  Get the return signal rate limit check value in MCPS
    *
    * @return return signal rate
    */
   float getSignalRateLimit();

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
   USBDM::ErrorCode setMeasurementTimingBudget(uint32_t budget_us);

   /**
    * Get the measurement timing budget in microseconds
    * based on VL53L0X_get_measurement_timing_budget_micro_seconds()
    * in us
    *
    * @return
    */
   uint32_t getMeasurementTimingBudget();

   /**
    * Set the VCSEL (vertical cavity surface emitting laser) pulse period for the
    * given period type (pre-range or final range) to the given value in PCLKs.
    * Longer periods seem to increase the potential range of the sensor.
    * Valid values are (even numbers only):
    *  pre:  12 to 18 (initialized default: 14)
    *  final: 8 to 14 (initialized default: 10)
    * based on VL53L0X_set_vcsel_pulse_period()
    *
    * @param type
    * @param period_pclks
    * @return
    */
   bool setVcselPulsePeriod(vcselPeriodType type, uint8_t period_pclks);

   /**
    * Get the VCSEL pulse period in PCLKs for the given period type.
    * based on VL53L0X_get_vcsel_pulse_period()
    *
    * @param type
    *
    * @return
    */
   uint8_t getVcselPulsePeriod(vcselPeriodType type);

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
   void startContinuous(uint32_t period_ms = 0);

   /**
    *
    * Stop continuous measurements
    * based on VL53L0X_StopMeasurement()
    */
   void stopContinuous();

   /**
    * Returns a range reading in millimetres when continuous mode is active
    * (readRangeSingleMillimetres() also calls this function after starting a
    * single-shot range measurement)
    *
    * @return
    */
   uint16_t readRangeContinuousMillimetres();

   /**
    *
    * Performs a single-shot range measurement and returns the reading in millimetres
    * based on VL53L0X_PerformSingleRangingMeasurement()
    *
    * @return
    */
   uint16_t readRangeSingleMillimetres();

   /**
    * Set measurement timeout
    *
    * @param timeout Timeout to set
    */
   void setTimeout(uint16_t timeout) {
      io_timeout = timeout;
   }

   /**
    * Get measurement timeout
    *
    * @return Timeout
    */
   uint16_t getTimeout() {
      return io_timeout;
   }

   /**
    *  Did a timeout occur in one of the read functions since the last call to
    *  timeoutOccurred()?
    *
    *  @return
    */
   bool timeoutOccurred();

private:

   enum SequenceStepEnables {
      MSRC        = 1<<2, //!< Minimum Signal Rate Check
      DSS         = 1<<3, //!< Dynamic Spad Selection
      TCC         = 1<<4, //!< Target CentreCheck
      PRE_RANGE   = 1<<6,
      FINAL_RANGE = 1<<7,
   };
   
   struct SequenceStepTimeouts {
      uint16_t pre_range_vcsel_period_pclks;
      uint16_t final_range_vcsel_period_pclks;
      uint16_t msrc_dss_tcc_mclks;
      uint16_t pre_range_mclks;
      uint16_t final_range_mclks;

      uint32_t msrc_dss_tcc_us;
      uint32_t pre_range_us;
      uint32_t final_range_us;
   };

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
   bool getSpadInfo(uint8_t * count, bool * type_is_aperture);

   /**
    *
    * Get sequence step enables
    * based on VL53L0X_GetSequenceStepEnables()
    *
    * @return Bit mask for enables
    */
   SequenceStepEnables getSequenceStepEnables();

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
   void getSequenceStepTimeouts(SequenceStepEnables const enables, SequenceStepTimeouts * timeouts);

   /**
    *
    * Based on VL53L0X_perform_single_ref_calibration()
    *
    * @param vhv_init_byte
    * @return
    */
   USBDM::ErrorCode performSingleRefCalibration(uint8_t vhv_init_byte);

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
   static uint16_t decodeTimeout(uint16_t value);

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
   static uint16_t encodeTimeout(uint16_t timeout_mclks);

   /**
    *
    * Convert sequence step timeout from MCLKs to microseconds with given VCSEL period in PCLKs
    * based on VL53L0X_calc_timeout_us()
    *
    * @param timeout_period_mclks
    * @param vcsel_period_pclks
    * @return
    */
   static uint32_t timeoutMclksToMicroseconds(uint16_t timeout_period_mclks, uint8_t vcsel_period_pclks);

   /**
    *
    * Convert sequence step timeout from microseconds to MCLKs with given VCSEL period in PCLKs
    * based on VL53L0X_calc_timeout_mclks()
    *
    * @param timeout_period_us
    * @param vcsel_period_pclks
    * @return
    */
   static uint32_t timeoutMicrosecondsToMclks(uint32_t timeout_period_us, uint8_t vcsel_period_pclks);
};

#endif // INCLUDE_VL53L0X_H
