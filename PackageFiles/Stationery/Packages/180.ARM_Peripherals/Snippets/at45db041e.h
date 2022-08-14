/**
 ============================================================================
 * @file    at45db041e.h
 * @brief   Interface for SPI memory (AT45DB041E as used on KW41)
 *
 *  Created on: 15/8/2022
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "spi.h"

/**
 * Interface for SPI memory (AT45DB041E as used on KW41)
 */
class FlashInterface {

   // Configuration to use for simple transactions (1 transfer) and last transaction (de-asserts CS)
   USBDM::SpiCalculatedConfiguration spiConfig;

   // Configuration to use for transactions involving >1 transfer (keeps CS active)
   USBDM::SpiCalculatedConfiguration spiConfigContinuous;

   // SPI Interface to use
   USBDM::Spi &spi;

public:
   /**
    * Constructor
    *
    * @param spi        SPI Interface to use
    * @param select     PCS being used to select device
    */
   FlashInterface(USBDM::Spi &spi, USBDM::SpiPeripheralSelect select) : spi(spi) {
      using namespace USBDM;

      // Basic configuration
      static const USBDM::SpiConfiguration config { 1'000'000, SpiMode_0, SpiOrder_MsbFirst, SpiFrameSize_8 };

      // Set configuration
      spi.setConfiguration(config);

      // Save the derived configuration for single transfer in transaction
      spi.setPeripheralSelect(select, ActiveLow, SpiSelectMode_Idle, SpiCtarSelect_0);
      spiConfig = spi.getConfiguration();

      // Save the derived configuration
      spi.setPeripheralSelect(select, ActiveLow, SpiSelectMode_Continuous, SpiCtarSelect_0);
      spiConfigContinuous = spi.getConfiguration();
   }

   /**
    * Read ID
    *
    * @return DeviceId2:DeviceId1:ManufacturerId
    */
   uint32_t readId() {

      uint8_t data[] = {0x9F, 0, 0, 0,};

      spi.startTransaction(spiConfig);
      spi.txRx(data, data);
      spi.endTransaction();

      return (data[1]<<16)|(data[2]<<8)|data[3];
   }

   /**
    * Status bits in status registers viewed as single 16-bit value
    */
   enum Status {
      Ready        = (1<<15),     //  0 Device is busy with an internal operation / 1 Device is ready.
      Compare      = (1<<14),     //  0 Main memory page data matches buffer data / 1 Main memory page data does not match buffer data.
      Density      = (0xF<<10),   //  0b0111 = 4-Mbit
      Protect      = (1<<9),      //  0 Sector protection is disabled / 1 Sector protection is enabled.
      PageSize     = (1<<8),      //  0 DataFlash page size is (264 bytes) /1  DataFlash page size is (256 bytes)
      Error        = (1<<5),      //  0 Erase or program operation was successful / 1 Erase or program error detected
      SecLock      = (1<<3),      //  0 Sector Lockdown command is disabled / 1 Sector Lockdown command is enabled
      ProgSuspend2 = (1<<2),      //  Buffer 2 - 0 No program operation suspended / 1 A sector is program suspended
      ProgSuspend1 = (1<<1),      //  Buffer 1 - 0 No program operation suspended / 1 A sector is program suspended
      EraseSuspend = (1<<0),      //  0 No sectors are erase suspended. / 1 A sector is erase suspended
   };

   /**
    * Reads chip status registers
    *
    * @return Status register Byte1:Byte2 as 16-bit value
    */
   uint16_t getStatus() {

      uint8_t data[] = {0xD7, 0, 0,};

      spi.startTransaction(spiConfig);
      spi.txRx(data, data);
      spi.endTransaction();

      return (data[1]<<8)|data[2];
   }

   /**
    * Program the device to use power-of-2 size pages (256 bytes)
    *
    * @return true on success
    */
   bool programBinaryPageSize() {

      uint8_t data[] = {0x3D, 0x2A, 0x80, 0xA6,};

      spi.startTransaction(spiConfig);
      spi.tx(data);
      spi.endTransaction();

      uint16_t status = waitForIdle();
      if ((status & Error) != 0) {
         return false;
      }
      if ((status & PageSize) == 0) {
         return false;
      }
      return true;
   }

   /**
    * Initialise flash.
    * This includes re-programming to use power-of-2 size pages (256 bytes)
    *
    * @return true on success
    */
   bool initialise() {

      uint32_t id = readId();
      if (id != 0x1F2400) {
         // Wrong ID
         return false;
      }
      uint16_t status = getStatus();
      if ((status & PageSize) != 0) {
         // Correct binary (256 bytes) page size
         return true;
      }
      // Need to re-program page size to 256 bytes.
      return programBinaryPageSize();
   }

   /**
    * Wait until flash is idle
    *
    * @return The value from the last status read
    */
   uint16_t waitForIdle() {

      uint16_t status;
      do {
         status = getStatus();
      } while((status & Ready) == 0);

      return status;
   }

   /**
    * Initiate Chip Erase
    */
   void startChipErase() {

      uint8_t data[] = {0xC7, 0x94, 0x80, 0x9a,};

      spi.startTransaction(spiConfig);
      spi.tx(data);
      spi.endTransaction();
   }

   /**
    * Initiate Chip Erase and wait for completion
    *
    * @return true on success
    */
   bool eraseChip() {

      startChipErase();
      uint16_t status = waitForIdle();
      bool result = ((status & Error) == 0);
      return result?true:false;
   }

   /**
    * Initiate erasing a page (256 bytes)
    *
    * @param address  Address of start of page
    */
   void startPageErase(uint32_t address) {

      uint8_t data[] = {0x81, (uint8_t)(address>>16), (uint8_t)(address>>8), 0x00, };

      spi.startTransaction(spiConfig);
      spi.tx(data);
      spi.endTransaction();
   }

   /**
    * Erase a page (256 bytes)
    *
    * @param address  Address of start of page
    *
    * @return true on success
    */
   bool erasePage(uint32_t pageNo) {

      startPageErase(pageNo);
      uint16_t status = waitForIdle();
      bool result = ((status & Error) == 0);
      return result?true:false;
   }

   /**
    * Write a page (256 bytes) to the RAM buffer
    *
    * @param data Data to write
    */
   void writeDataBuffer(uint8_t data[256]) {

      uint8_t command[] = {0x84, 0x00, 0x00, 0x00, };

      spi.startTransaction(spiConfigContinuous);
      spi.tx(command);
      spi.setConfiguration(spiConfig);
      spi.txRx(256, data);

      spi.endTransaction();
   }

   /**
    * Read a page (256 bytes) from the RAM buffer
    *
    * @param data Data buffer
    */
   void readDataBuffer(uint8_t data[256]) {

      uint8_t command[] = {0xD4, 0x00, 0x00, 0x00, 0x00, };

      spi.startTransaction(spiConfigContinuous);
      spi.tx(command);
      spi.setConfiguration(spiConfig);
      spi.txRx(256, (uint8_t*)nullptr, data);

      spi.endTransaction();
   }

   /**
    * Start write of page of data to flash
    *
    * @param data     Data to write to flash
    * @param address  Address of start of page in flash
    */
   void startPageWrite(uint8_t data[256], uint32_t address) {

      uint8_t command[] = {0x82, (uint8_t)(address>>16), (uint8_t)(address>>8), (uint8_t)(address), };

      spi.startTransaction(spiConfigContinuous);
      spi.tx(command);
      spi.setConfiguration(spiConfig);
      spi.txRx(256, data);
      spi.endTransaction();
   }

   /**
    * Write a page of data to flash
    *
    * @param data     Data to write to flash
    * @param address  Address of start of page in flash
    */
   bool writePage(uint8_t data[256], uint32_t address) {
      startPageWrite(data, address);

      uint16_t status = waitForIdle();
      return ((status & Error) == 0)?true:false;
   }

   /**
    * Read a page (256 bytes) from flash
    *
    * @param data Data buffer
    */
   void readPage(uint8_t data[256], uint32_t address) {

      uint8_t command[] = {
            0xD2,
            (uint8_t)(address>>16), (uint8_t)(address>>8), (uint8_t)(address), 0,0,0,0,
      };

      spi.startTransaction(spiConfigContinuous);
      spi.tx(command);
      spi.setConfiguration(spiConfig);
      spi.txRx(256, (uint8_t*)nullptr, data);

      spi.endTransaction();
   }
};
