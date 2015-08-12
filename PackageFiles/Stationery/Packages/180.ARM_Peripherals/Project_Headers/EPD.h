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

#include "Gpio.h"
#include "SPI.h"

enum EPD_size {
   EPD_1_44,        // 128 x 96
   EPD_2_0,         // 200 x 96
   EPD_2_7          // 264 x 176
};

enum EPD_stage {    // Image pixel -> Display pixel
   EPD_compensate,  // B -> W, W -> B (Current Image)
   EPD_white,       // B -> N, W -> W (Current Image)
   EPD_inverse,     // B -> N, W -> B (New Image)
   EPD_normal       // B -> B, W -> W (New Image)
};

struct EPD_Data {
   uint16_t        stage_time;
   uint16_t        dots_per_line;
   uint16_t        lines_per_display;
   uint16_t        bytes_per_line;
   uint16_t        bytes_per_scan;
   bool            filler;
   const uint8_t   channel_select[9];
   uint8_t         gate_source;
};

typedef void EPD_reader(void *buffer, uint32_t address, uint16_t length);

class EPD {

private:
   SPI             *spi;                  // SPI to use
   EPD_size         size;                 // EPD screen size
   const EPD_Data  *epdData;              // EPD parameters
   unsigned         factored_stage_time;  // Stage time in ms

   void txByteAndWait(uint8_t c);
   void txWriteReg1Byte(const uint8_t regNum, uint8_t data);
   uint8_t rxReadReg1Byte(const uint8_t regNum);
   void txWriteRegNBytes(const uint8_t regNum, unsigned length, const uint8_t data[]);
   void txBytes(uint32_t dataSize, const uint8_t *dataOut);
   int getFactoredStageTime(int temperature);

   // single line display - very low-level
   void sendLine(uint16_t line, const uint8_t *data, uint8_t fixed_value, EPD_stage stage);


public:

   EPD(SPI *spi, EPD_size sz);

   void setFactor(int temperature) {
      this->factored_stage_time = getFactoredStageTime(temperature);
   }
   unsigned getWidth()  { return epdData->dots_per_line; }
   unsigned getHeight() { return epdData->lines_per_display; }
   void powerOnAndInitialise();
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
    *  @note Assumes clear (white) screen
    */
   void image(const uint8_t *image) {
      this->frame_fixed_repeat(0xaa, EPD_compensate);
      this->frame_fixed_repeat(0xaa, EPD_white);
      this->frame_data_repeat(image, EPD_inverse);
      this->frame_data_repeat(image, EPD_normal);
   }

   /*
    *  Change from old image to new image (data)
    *  Old image is in RAM buffer
    *  @param new_image Image data for new image
    */
   void image_sram(unsigned char *new_image) {
      this->frame_fixed_repeat(0xaa, EPD_compensate);
      this->frame_fixed_repeat(0xaa, EPD_white);
      this->frame_sram_repeat(new_image, EPD_inverse);
      this->frame_sram_repeat(new_image, EPD_normal);
   }

   // Low level API calls
   // ===================

   // single frame refresh
   void frame_fixed(uint8_t fixed_value, EPD_stage stage);
   void frame_data(const uint8_t *new_image, EPD_stage stage);

   void frame_sram(const uint8_t *new_image, EPD_stage stage);
   void frame_cb(uint32_t address, EPD_reader *reader, EPD_stage stage);

   // stage_time frame refresh
   void frame_fixed_repeat(uint8_t fixed_value, EPD_stage stage);
   void frame_data_repeat(const uint8_t *new_image, EPD_stage stage);

   void frame_sram_repeat(const uint8_t *new_image, EPD_stage stage);
   void frame_cb_repeat(uint32_t address, EPD_reader *reader, EPD_stage stage);

};

#endif

