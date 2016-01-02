/* @file epd.h
 *
 * @brief Low-level driver for ePaper display
 *
 * Display type: Vizplex (V110) (G1 COG driver)
 *
 * Copyright 2013 Pervasive Displays, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied.  See the License for the specific language
 * governing permissions and limitations under the License.
 *
 *
 * Modified for Kinetis FRDM boards by Peter O'Donoghue
 * 2014
 *
 *
 */
#ifndef EPD_H
#define EPD_H

#include "gpio.h"
#include "spi.h"
#include "delay.h"

namespace USBDM {

/**
 * @addtogroup EPaper_Group E-paper interface
 * @brief C++ Class allowing access to E-paper display
 * @{
 */

/** Display sizes */
enum EpdSize {
   EPD_1_44,        // 128 x 96
   EPD_2_0,         // 200 x 96
   EPD_2_7          // 264 x 176
};

/** Stages in updating display */
enum EpdStage {    // Image pixel -> Display pixel
   EPD_compensate,  // B -> W, W -> B (Current Image)
   EPD_white,       // B -> N, W -> W (Current Image)
   EPD_inverse,     // B -> N, W -> B (New Image)
   EPD_normal       // B -> B, W -> W (New Image)
};

/** Data for a specific size display */
struct EpdData {
   EpdSize         epdSize;
   uint16_t        stage_time;
   uint16_t        dots_per_line;
   uint16_t        lines_per_display;
   uint16_t        bytes_per_line;
   uint16_t        bytes_per_scan;
   bool            filler;
   const uint8_t   channel_select[9];
   uint8_t         gate_source;
};

static constexpr EpdData EPD_1_44_DATA = {
      /* EpdSize size           */ EPD_1_44,
      /* stage_time             */ 480,
      /* dots_per_line;         */ 128,
      /* lines_per_display;     */ 96,
      /* bytes_per_line;        */ 128 / 8,
      /* bytes_per_scan;        */ 96 / 4,
      /* filler;                */ false,
      /* channel_select;        */ {0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00},
      /* gate_source;           */ 0x03,
};

static constexpr EpdData EPD_2_0_DATA = {
      /* EpdSize size           */ EPD_2_0,
      /* stage_time             */ 480,
      /* dots_per_line;         */ 200,
      /* lines_per_display;     */ 96,
      /* bytes_per_line;        */ 200 / 8,
      /* bytes_per_scan;        */ 96 / 4,
      /* filler;                */ true,
      /* channel_select;        */ {0x72, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x00},
      /* gate_source;           */ 0x03,
};

static constexpr EpdData EPD_2_7_DATA = {
      /* EpdSize size           */ EPD_2_7,
      /* stage_time             */ 630,
      /* dots_per_line;         */ 264,
      /* lines_per_display;     */ 176,
      /* bytes_per_line;        */ 264 / 8,
      /* bytes_per_scan;        */ 176 / 4,
      /* filler;                */ true,
      /* channel_select;        */ {0x72, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00},
      /* gate_source;           */ 0x00,
};

/**
 * Class representing a E-paper display
 */
class Epd {

protected:
   Spi            *spi;                  //!< SPI to use
   const EpdData  &epdData;              //!< EPD parameters
   unsigned        factored_stage_time;  //!< Stage time in ms

   virtual bool isBusy()    = 0;
   virtual void csEnable(bool enable)  = 0;
   virtual void pulseBorder() = 0;
   virtual void pwmEnable(bool enable) = 0;
   /**
    * Turns on interface
    */
   virtual void interfaceOn() = 0;
   /**
    * Turns off interface
    */
   virtual void interfaceOff() = 0;
   /**
    * Calculates the factored stage time for frame_*_repeat methods
    * from temperature.
    *
    *  @param  temperature Temperature in Celsius
    *
    *  @return Scaled stage time in ms
    */
   int getFactoredStageTime(int temperature);
   /**
    *  Send a single byte to EPD and wait for not busy
    *
    *  @param data Byte to send
    */
   void txByteAndWait(uint8_t data);
   /**
    *  Write byte to register
    *
    *  @param regNum    Register to write to
    *  @param data      Data byte for register
    */
   void txWriteReg1Byte(const uint8_t regNum, uint8_t data);
   /**
    *  Driver ID
    *  Note: Only implemented on later e-Paper?
    *
    *  @return ID byte
    */
   uint8_t rxReadId();
   /**
    *  Read 1 byte from register
    *
    *  @param regNum    Register to read from
    *
    *  @return          Data byte from register
    */
   uint8_t rxReadReg1Byte(const uint8_t regNum);
   /**
    *  Transmit bytes to EPD
    *
    *  @param dataSize  Number of bytes to transfer
    *  @param dataOut   Transmit bytes
    */
   void txBytes(uint32_t dataSize, const uint8_t *dataOut);
   /**
    * Send line of data to display
    *
    * @param   line        Which line of display
    * @param   data        Data to write (may be NULL)
    * @param   fixed_value Fixed value used if data == NULL
    * @param   stage       Stage of the screen rewrite
    */
   void sendLine(uint16_t line, const uint8_t *data, uint8_t fixed_value, EpdStage stage);
   /**
    * Write full frame of fixed data value
    *
    * @param fixedValue Value to write
    * @param stage      Stage of update process
    */
   void frame_fixed(uint8_t fixedValue, EpdStage stage);
   /**
    * Write full frame from an image
    *
    * @param image   Image to write
    * @param stage   Stage of update process
    */
   void frame_data(const uint8_t *image, EpdStage stage);
   /**
    * Write full frame of fixed data value multiple times (over repeat period)
    *
    * @param fixedValue Value to write
    * @param stage      Stage of update process
    */
   void frame_fixed_repeat(uint8_t fixedValue, EpdStage stage);

   /**
    * Write full frame from an image multiple times (over repeat period)
    *
    * @param image   Image to write
    * @param stage   Stage of update process
    */
   void frame_data_repeat(const uint8_t *image, EpdStage stage);

public:
   /**
    *  Constructor
    *
    *  @param spi       SPI interface to use
    *  @param epdData   Data describing the EPD panel
    */
   Epd(Spi *spi, const EpdData &epdData);
   /**
    * Get width of display
    */
   unsigned getWidth()  { return epdData.dots_per_line; }
   /**
    * Get height of display
    */
   unsigned getHeight() { return epdData.lines_per_display; }
   /**
    * Sets the temperature dependent parameters of the display\n
    * If not called then a default temperature of 25C is assumed
    *
    * @param temperature The temperature of the display
    */
   void setDisplayTemperature(int temperature) {
      // Set factored_stage_time based on temperature
      this->factored_stage_time = getFactoredStageTime(temperature);
   }
   /**
    * Power-on and Initialise COG driver
    */
   void powerOnAndInitialise();
   /**
    * Power-off COG driver
    */
   void powerOff();
   /*
    * Clear display
    */
   void clear() {
      frame_fixed_repeat(0xff, EPD_compensate);
      frame_fixed_repeat(0xff, EPD_white);
      frame_fixed_repeat(0xaa, EPD_inverse);
      frame_fixed_repeat(0xaa, EPD_normal);
   }
   /*
    *  Write an image to display
    *
    *  @param image Image data
    *
    *  @note Assumes clear (white) screen
    */
   void image(const uint8_t *image) {
      frame_fixed_repeat(0xaa, EPD_compensate);
      frame_fixed_repeat(0xaa, EPD_white);
      frame_data_repeat(image, EPD_inverse);
      frame_data_repeat(image, EPD_normal);
   }
};

/**
 * Templatre class representing a E-paper display
 *
 * This takes care of the pin dependent I/O
 */
template <
class epdBusy,        //!< Busy flag from EPD
class epdReset_n,     //!< Reset to EPD
class epdDischarge,   //!< Discharge to EPD
class epdBorder,      //!< Border to EPD
class epdPower,       //!< ON/OFF EPD Power
class epdPwm,         //!< PWM to EPD
class epdCs_n         //!< EPD SPI CS*
>
class Epd_T : public Epd {
public:
   Epd_T(Spi *spi, const EpdData &epdData) : Epd(spi, epdData) {
      // Initialise pins
      epdCs_n::setOutput();
      epdPower::setOutput();
      epdBorder::setOutput();
      epdDischarge::setOutput();
      epdPwm::setMode(5 /* us */, USBDM::ftm_leftAlign);
      epdReset_n::setOutput();
      epdBusy::setInput();

      epdCs_n::low();
      epdPower::low();
      epdBorder::low();
      epdDischarge::low();
      epdReset_n::low();
   }

protected:
   /**
    * Checks the busy status of the EPD
    *
    * @return true=Busy, false=Not busy
    */
   virtual bool isBusy()     {
      return epdBusy::read();
   }
   /**
    * Controls the enable pin to the EPD (Note: Active low)
    *
    * @param enable Required enable state (true=>asserted, false=>negated)
    */
   virtual void csEnable(bool enable) {
      if (enable) {
         epdCs_n::low();
      }
      else {
         epdCs_n::high();
      }
   }
   /**
    * Drive the border signal to the EPD low for 300 ms
    */
   virtual void pulseBorder() {
      epdBorder::low();
      waitMS(300);
      epdBorder::high();
   }
   /**
    * Controls the PWM drive to the PWM pin of the EPD
    *
    * @param enable Required enable state (true=>PWM on, false=>nPWM off)
    */
   virtual void pwmEnable(bool enable) {
      epdPwm::setDutyCycle(enable?50:0);
   }
   /**
    * Turns on interface
    */
   virtual void interfaceOn() {
      // ===========================================
      // See Application Note Doc. No. 4P008-00
      // 3. Power On COG Driver

      // Everything low & no power
      epdReset_n::low();
      epdPower::low();
      epdDischarge::low();
      epdBorder::low();
      epdCs_n::low();

      // Apply PWM >5ms before powering panel
      epdPwm::setDutyCycle(50);
      waitMS(5);

      // Power to panel
      epdPower::high();

      // PWM toggle 5ms
      waitMS(10);

      epdCs_n::high();
      spi->enablePins();

      epdBorder::high();
      epdReset_n::high();

      // PWM toggle 5ms
      waitMS(5);

      epdReset_n::low();

      // PWM toggle 5ms
      waitMS(5);

      epdReset_n::high();

      // PWM toggle 5ms
      waitMS(5);

      // PWM toggle off????

      //   uint8_t value = rxReadReg1Byte(0);
   }

   /**
    * Turns off interface
    */
   virtual void interfaceOff() {

      // Turn off power and all signals
      epdPower::low();
      epdReset_n::low();
//      epdCs_n::low();
//      spi->disablePins();
      epdBorder::low();

      // Discharge pulse
      epdDischarge::high();
      waitMS(1000);
      epdDischarge::low();
   }
};
/**
 * @}
 */

} // End namespace USBDM
#endif

