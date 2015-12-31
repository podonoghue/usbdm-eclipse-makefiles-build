// Copyright 2013 Pervasive Displays, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied.  See the License for the specific language
// governing permissions and limitations under the License.

#ifndef EPD_H
#define EPD_H

#include "gpio.h"
#include "spi.h"

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
   EpdSize        epdSize;
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
      this->frame_fixed_repeat(0xff, EPD_compensate);
      this->frame_fixed_repeat(0xff, EPD_white);
      this->frame_fixed_repeat(0xaa, EPD_inverse);
      this->frame_fixed_repeat(0xaa, EPD_normal);
   }
   /*
    *  Write an image to display
    *
    *  @param image Image data
    *
    *  @note Assumes clear (white) screen
    */
   void image(const uint8_t *image) {
      this->frame_fixed_repeat(0xaa, EPD_compensate);
      this->frame_fixed_repeat(0xaa, EPD_white);
      this->frame_data_repeat(image, EPD_inverse);
      this->frame_data_repeat(image, EPD_normal);
   }
};

/**
 * @}
 */

} // End namespace USBDM
#endif

