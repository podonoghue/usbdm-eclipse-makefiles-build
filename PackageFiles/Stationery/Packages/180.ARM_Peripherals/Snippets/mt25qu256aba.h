/*
 * @file Mt25qu256aba.h  (180.ARM_Peripherals/Snippets/Mt25qu256aba.h)
 *
 *  Created on: 25 Nov. 2021
 *      Author: peter
 */

#ifndef SOURCES_MT25QU256ABA_H_
#define SOURCES_MT25QU256ABA_H_

#include "qspi.h"

namespace USBDM {

/**
 * Micron MT25QU256ABA
 * ========================
 * 256 Mib (32 MiB)
 * 1-die
 * Dual/quad I/O commands for increased through-put up to 90 MB/s
 * Supported protocols: Extended, Dual and Quad I/O both STR and DTR
 * 256 byte page size
 *
 * https://media-www.micron.com/-/media/client/global/documents/products/data-sheet/nor-flash/serial-nor/mt25q/die-rev-a/mt25q_qljs_u_256_aba_0.pdf?rev=594079234c1b496496b062c21ce162d6
 */
class Mt25qu256aba {
private:
   Mt25qu256aba() = delete;
   virtual ~Mt25qu256aba() = delete;
   Mt25qu256aba(const Mt25qu256aba &other) = delete;
   Mt25qu256aba(Mt25qu256aba &&other) = delete;
   Mt25qu256aba& operator=(const Mt25qu256aba &other) = delete;

public:
   /// Size of flash page in bytes (maximum program unit)
   static constexpr unsigned FLASH_PAGE_SIZE = 256;

   /// Size of flash sector in bytes (minimum erase unit)
   static constexpr unsigned FLASH_SECTOR_SIZE = 4096;

   /// Size of entire flash in bytes 32 MiB (0x200'0000)
   static constexpr unsigned FLASH_SIZE = 1<<25;

   /// Base address of flash in MCU memory
   static constexpr unsigned FLASH_START = Qspi0::QSPI0_AMBA_BASE_ADDRESS;

private:
   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-4-4 ---   4-4-4 4   10   -    10   >=1
   static constexpr uint8_t QUAD_INPUT_OUTPUT_FAST_READ_4BYTE = 0xEC;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-1-1 2-2-2 4-4-4 4   0    0     0   [1..256]
   static constexpr uint8_t PAGE_PROGRAM_4BYTE          = 0x12;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-1-0 2-2-0 4-4-0 4   0    0     0   0
   static constexpr uint8_t SUBSECTOR_ERASE_4KB_4BYTE    = 0x21;


   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-1-1 2-2-2 4-4-4 3   8    8    10   >=1
   static constexpr uint8_t FAST_READ                   = 0x0B;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-4-4 ---   4-4-4 3  10    -    10   >=1
   static constexpr uint8_t QUAD_INPUT_OUTPUT_FAST_READ = 0xEB;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-1-2 2-2-2 ---   3   8    8     -   >=1
   static constexpr uint8_t DUAL_OUTPUT_FAST_READ       = 0x3B;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-0-1 2-0-2 4-0-4 0   0    0     0   >=1
   static constexpr uint8_t READ_STATUS_REGISTER        = 0x05;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-0-1 2-0-2 4-0-4 0   0    0     0   >=2
   static constexpr uint8_t READ_CONFIG_REGISTER        = 0xB5;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-0-0 2-0-0 4-0-0 0   0    0     0   0
   static constexpr uint8_t WRITE_ENABLE                = 0x06;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-0-1 2-0-2 4-0-4 0   0    0     0   1
   static constexpr uint8_t WRITE_STATUS_REGISTER       = 0x01;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-0-0 2-0-0 4-0-0 0   0    0     0   0
   static constexpr uint8_t ERASE_ALL                   = 0x60;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-1-0 2-2-0 4-4-0 3   0    0     0   0
   static constexpr uint8_t SUBSECTOR_ERASE_4KB         = 0x20;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-1-1 2-2-2 4-4-4 3   0    0     0   [1..256]
   static constexpr uint8_t PAGE_PROGRAM                = 0x02;

   /**
    * LUTs
    *
    * 3-byte addresses. Usable up to 2^24 = 16 MiB (132 Mib)
    *
    * These are grouped into sequences of up to 8 entries
    *
    * Based on Freescale/NXP example (with corrections)
    */
   static constexpr QspiLutInstruction luts_3ByteAddress[][8] = {
         /* Seq0: Quad Read */
         /* CMD:        0xEB - Quad Read, Single pad */
         /* ADDR:       0x18 - 24bit address, Quad pads */
         /* DUMMY:      0x06 - 10 clock cyles, Quad pads */
         /* READ:       0x80 - Read 128 bytes, Quad pads */
         /* JUMP_ON_CS: 0 */
         // {04EB, 0A18, 0E0A, 1E80, 2400}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, QUAD_INPUT_OUTPUT_FAST_READ),
               Qspi0::instruction_Addr(QspiLutPadInfo_4Pads, 24),
               Qspi0::instruction_Dummy(QspiLutPadInfo_4Pads, 10),
               Qspi0::instruction_Read(QspiLutPadInfo_4Pads, 128),
               Qspi0::instruction_JumpOnCs(0),
         },
         /* Seq1: Write Enable */
         /* CMD:      0x06 - Write Enable, Single pad */
         // {0406}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, WRITE_ENABLE),
         },
         /* Seq2: Erase All */
         /* CMD:    0x60 - Erase All chip, Single pad */
         //  {0406}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, ERASE_ALL),
         },
         /* Seq3: Read Status */
         /* CMD:    0x05 - Read Status, single pad */
         /* READ:   0x01 - Read 1 byte, single pad */
         // {0405, 1C01}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, READ_STATUS_REGISTER),
               Qspi0::instruction_Read(QspiLutPadInfo_1Pad, 1),
         },
         /* Seq4: Page Program */
         /* CMD:    0x02 - Page Program, Single pad */
         /* ADDR:   0x18 - 24bit address, Single pad */
         /* WRITE:  0x80 - Write 128 bytes at one pass, Single pad */
         // {0402, 0818, 2080}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, PAGE_PROGRAM),
               Qspi0::instruction_Addr(QspiLutPadInfo_1Pad, 24),
               Qspi0::instruction_Write(QspiLutPadInfo_1Pad, 128),
         },
         /* Seq5: Erase 4KiB Sector */
         /* CMD:  0x20 - Sector Erase, single pad */
         /* ADDR: 0x18 - 24 bit address, single pad */
         // {0420, 0818}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, SUBSECTOR_ERASE_4KB),
               Qspi0::instruction_Addr(QspiLutPadInfo_1Pad, 24),
         },
         /* Seq6: Write Status Register */
         /* CMD:    0x01 - Write Status Register, single pad */
         /* WRITE:  0x01 - Write 1 byte of data, single pad */
         // {0401, 2001}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, WRITE_STATUS_REGISTER),
               Qspi0::instruction_Write(QspiLutPadInfo_1Pad, 1),
         },
#if 0
         // Following unused

         /* Seq7: Read Config Register */
         /* CMD:  0x05 - Read Config register, single pad */
         /* READ: 0x01 - Read 2 bytes */
         // {04B5, 1C01}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, READ_CONFIG_REGISTER),
               Qspi0::instruction_Read(QspiLutPadInfo_1Pad, 2),
         },
         /* Seq8: Dummy */
         /* CMD:    0xFF - Dummy command, used to force SPI flash to exit continuous read mode */
         // {04FF}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, 0xFF),
         },
         /* Seq9: Fast Single read */
         /* CMD:        0x0B - Fast Read, Single Pad */
         /* ADDR:       0x18 - 24bit address, Single Pad */
         /* DUMMY:      0x08 - 8 clock cyles, Single Pad */
         /* READ:       0x80 - Read 128 bytes, Single Pad */
         /* JUMP_ON_CS: 0 */
         // {040B, 0818, 0C08, 1C80, 2400}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, FAST_READ),
               Qspi0::instruction_Addr(QspiLutPadInfo_1Pad, 24),
               Qspi0::instruction_Dummy(QspiLutPadInfo_1Pad, 8),
               Qspi0::instruction_Read(QspiLutPadInfo_1Pad, 128),
               Qspi0::instruction_JumpOnCs(0),
         },
         /* Seq10: Fast Dual read */
         /* CMD:        0x3B - Dual Read, Single Pad */
         /* ADDR:       0x18 - 24bit address, Single Pad */
         /* DUMMY:      0x08 - 8 clock cyles, Single Pad */
         /* READ:       0x80 - Read 128 bytes, Dual pads */
         /* JUMP_ON_CS: 0 */
         // {043B, 0818, 0C08, 1D80, 2400}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, DUAL_OUTPUT_FAST_READ),
               Qspi0::instruction_Addr(QspiLutPadInfo_1Pad, 24),
               Qspi0::instruction_Dummy(QspiLutPadInfo_1Pad, 8),
               Qspi0::instruction_Read(QspiLutPadInfo_2Pads, 128),
               Qspi0::instruction_JumpOnCs(0),
         },
#endif
   };

   /**
    * LUTs
    *
    * 4-byte addresses. Needed for above 2^24 = 16 MiB (132 Mib)
    *
    * These are grouped into sequences of up to 8 entries
    *
    * Based on Freescale/NXP example (changed to 4-byte addresses)
    */
   static constexpr QspiLutInstruction luts_4byteAddress[][8] = {
         /* Seq0: Quad Read */
         /* CMD:        0xEC - Quad Read, Single pad, 4-byte address*/
         /* ADDR:       0x20 - 32bit address, Quad pads */
         /* DUMMY:      0x06 - 10 clock cyles, Quad pads */
         /* READ:       0x80 - Read 128 bytes, Quad pads */
         /* JUMP_ON_CS: 0 */
         // {04EC, 0A20, 0E0A, 1E80, 2400}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, QUAD_INPUT_OUTPUT_FAST_READ_4BYTE),
               Qspi0::instruction_Addr(QspiLutPadInfo_4Pads, 32),
               Qspi0::instruction_Dummy(QspiLutPadInfo_4Pads, 10),
               Qspi0::instruction_Read(QspiLutPadInfo_4Pads, 128),
               Qspi0::instruction_JumpOnCs(0),
         },
         /* Seq1: Write Enable */
         /* CMD:      0x06 - Write Enable, Single pad */
         // {0406}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, WRITE_ENABLE),
         },
         /* Seq2: Erase All */
         /* CMD:    0x60 - Erase All chip, Single pad */
         //  {0406}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, ERASE_ALL),
         },
         /* Seq3: Read Status */
         /* CMD:    0x05 - Read Status, single pad */
         /* READ:   0x01 - Read 1 byte, single pad */
         // {0405, 1C01}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, READ_STATUS_REGISTER),
               Qspi0::instruction_Read(QspiLutPadInfo_1Pad, 1),
         },
         /* Seq4: Page Program */
         /* CMD:    0x12 - Page Program, Single pad */
         /* ADDR:   0x20 - 24bit address, Single pad */
         /* WRITE:  0x80 - Write 128 bytes at one pass, Single pad */
         // {0412, 0820, 2080}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, PAGE_PROGRAM_4BYTE),
               Qspi0::instruction_Addr(QspiLutPadInfo_1Pad, 32),
               Qspi0::instruction_Write(QspiLutPadInfo_1Pad, 128),
         },
         /* Seq5: Erase 4KiB Sector */
         /* CMD:  0x21 - Sector Erase, single pad */
         /* ADDR: 0x20 - 24 bit address, single pad */
         // {0421, 0820}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, SUBSECTOR_ERASE_4KB_4BYTE),
               Qspi0::instruction_Addr(QspiLutPadInfo_1Pad, 32),
         },
         /* Seq6: Write Status Register */
         /* CMD:    0x01 - Write Status Register, single pad */
         /* WRITE:  0x01 - Write 1 byte of data, single pad */
         // {0401, 2001}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, WRITE_STATUS_REGISTER),
               Qspi0::instruction_Write(QspiLutPadInfo_1Pad, 1),
         },
#if 0
         // Following unused

         /* Seq7: Read Config Register */
         /* CMD:  0x05 - Read Config register, single pad */
         /* READ: 0x01 - Read 2 bytes */
         // {04B5, 1C01}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, READ_CONFIG_REGISTER),
               Qspi0::instruction_Read(QspiLutPadInfo_1Pad, 2),
         },
         /* Seq8: Dummy */
         /* CMD:    0xFF - Dummy command, used to force SPI flash to exit continuous read mode */
         // {04FF}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, 0xFF),
         },
         /* Seq9: Fast Single read */
         /* CMD:        0x0B - Fast Read, Single Pad */
         /* ADDR:       0x18 - 24bit address, Single Pad */
         /* DUMMY:      0x08 - 8 clock cyles, Single Pad */
         /* READ:       0x80 - Read 128 bytes, Single Pad */
         /* JUMP_ON_CS: 0 */
         // {040B, 0818, 0C08, 1C80, 2400}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, FAST_READ),
               Qspi0::instruction_Addr(QspiLutPadInfo_1Pad, 24),
               Qspi0::instruction_Dummy(QspiLutPadInfo_1Pad, 8),
               Qspi0::instruction_Read(QspiLutPadInfo_1Pad, 128),
               Qspi0::instruction_JumpOnCs(0),
         },
         /* Seq10: Fast Dual read */
         /* CMD:        0x3B - Dual Read, Single Pad */
         /* ADDR:       0x18 - 24bit address, Single Pad */
         /* DUMMY:      0x08 - 8 clock cyles, Single Pad */
         /* READ:       0x80 - Read 128 bytes, Dual pads */
         /* JUMP_ON_CS: 0 */
         // {043B, 0818, 0C08, 1D80, 2400}
         {
               Qspi0::instruction_Command(QspiLutPadInfo_1Pad, DUAL_OUTPUT_FAST_READ),
               Qspi0::instruction_Addr(QspiLutPadInfo_1Pad, 24),
               Qspi0::instruction_Dummy(QspiLutPadInfo_1Pad, 8),
               Qspi0::instruction_Read(QspiLutPadInfo_2Pads, 128),
               Qspi0::instruction_JumpOnCs(0),
         },
#endif
   };

   static const QspiSequenceIdentity QspiSequenceIdentity_Read            = QspiSequenceIdentity_0;
   static const QspiSequenceIdentity QspiSequenceIdentity_WriteEnable     = QspiSequenceIdentity_1;
   static const QspiSequenceIdentity QspiSequenceIdentity_EraseAll        = QspiSequenceIdentity_2;
   static const QspiSequenceIdentity QspiSequenceIdentity_ReadStatusReg   = QspiSequenceIdentity_3;
   static const QspiSequenceIdentity QspiSequenceIdentity_PageProgram     = QspiSequenceIdentity_4;
   static const QspiSequenceIdentity QspiSequenceIdentity_EraseSector     = QspiSequenceIdentity_5;
   static const QspiSequenceIdentity QspiSequenceIdentity_WriteStatusReg  = QspiSequenceIdentity_6;
   //   static const QspiSequenceIdentity QspiSequenceIdentity_ReadConfig      = QspiSequenceIdentity_7;
   //   static const QspiSequenceIdentity QspiSequenceIdentity_Dummy           = QspiSequenceIdentity_8;
   //   static const QspiSequenceIdentity QspiSequenceIdentity_FastRead_1pad   = QspiSequenceIdentity_9;
   //   static const QspiSequenceIdentity QspiSequenceIdentity_FastRead_2pad   = QspiSequenceIdentity_10;

   enum MT25QU256ABA_Status {
      MT25QU256ABA_WriteInProgress  = 1<<0,
      MT25QU256ABA_WriteEnable      = 1<<1,
   };

   static constexpr uint8_t MT25QU256ABA_WriteProtect_MASK = 0b01011100;
   static constexpr uint8_t MT25QU256ABA_WriteProtect_None = 0b00000000;

   /**
    * Read flash status
    */
   static uint8_t readFlashStatus() {
      while (Qspi0::readStatusRegister() & QspiStatusMask_ModuleBusy) {
      }
      Qspi0::clearFifos(QspiFifoClear_Receive);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_ReadStatusReg);
      while (Qspi0::readStatusRegister() & QspiStatusMask_ModuleBusy) {
      }
      uint8_t status = Qspi0::readRxDataBuffer(0);
      Qspi0::clearFlags(QspiFlag_RxBufferDrain);
      return status;
   }

   /**
    * Poll flash until status indicates idle i.e. no write, program or erase operation is current
    */
   static void waitForFlashWriteComplete() {
      while (readFlashStatus() & MT25QU256ABA_WriteInProgress) {
      }
   }

   /**
    * Clear write-protect in status register.
    * The status register is only modified if necessary.
    */
   static void clearWriteProtect() {

      if ((readFlashStatus() & MT25QU256ABA_WriteProtect_MASK) == MT25QU256ABA_WriteProtect_None) {
         // Not write-protected
         return;
      }

      // Data to send - must be >= 16 bytes
      uint32_t buff[] = {0, 0, 0, 0};

      Qspi0::setSerialFlashAddress();
      Qspi0::initiateIpCommand(QspiSequenceIdentity_WriteEnable);
      waitForFlashWriteComplete();

      Qspi0::clearFifos(QspiFifoClear_Transmit);

      // Fill FIFO
      fillTransmitFifo(buff, sizeof(buff));

      // Write to config register
      Qspi0::initiateIpCommand(QspiSequenceIdentity_WriteStatusReg, 1);
      waitForFlashWriteComplete();
   }

public:

   /**
    * Erase sector in flash
    *
    * @param addr Address of sector to erase
    */
   static void eraseSector(uint32_t addr) {

      while (Qspi0::readStatusRegister() & QspiStatusMask_ModuleBusy) {
      }
      Qspi0::setSerialFlashAddress(addr);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_WriteEnable);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_EraseSector);
      waitForFlashWriteComplete();
   }

   /**
    * Erase all of flash
    *
    * @param addr Address of sector to erase
    */
   static void eraseAll()
   {
      while (Qspi0::readStatusRegister() & QspiStatusMask_ModuleBusy) {
      }
      Qspi0::setSerialFlashAddress();
      Qspi0::initiateIpCommand(QspiSequenceIdentity_WriteEnable);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_EraseAll);
      waitForFlashWriteComplete();
   }

   /**
    * Write data to Transmit buffer
    *
    * @param buffer  Buffer for data source
    * @param size    Maximum number of bytes to write
    *
    * @return Number of bytes written
    *
    * @note The transmit buffer is 32-bit access so a size that is not a multiple of 4
    *       will result in discarded data from the last used element of buffer.
    *
    */
   static unsigned fillTransmitFifo(uint32_t *buffer, size_t size) {
      usbdm_assert(size >= 16U, "Must write at least 16 bytes");

      unsigned i;
      for (i = 0; i < size; i += 4) {

         if(Qspi0::readStatusRegister() & QspiStatusMask_TxBuffer_Full) {
            // Buffer full - stop
            break;
         }
         Qspi0::writeTransmitBuffer(*buffer++);
      }
      return min(i, size);
   }

   /**
    * Program a page to flash
    *
    * @param flashAddress  Flash address (in MCU memory space)
    * @param buffer        Page of data to write
    */
   static void programPage(uint32_t flashAddress, uint32_t *buffer) {

      while (Qspi0::readStatusRegister() & QspiStatusMask_ModuleBusy) {
      }
      Qspi0::setSerialFlashAddress(flashAddress);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_WriteEnable);
      while (Qspi0::readStatusRegister() & QspiStatusMask_ModuleBusy) {
      }

      int remainingBytes = FLASH_PAGE_SIZE;
      bool startedWrite = false;

      Qspi0::clearFifos(QspiFifoClear_Transmit);

      while (remainingBytes>0) {

         // Fill FIFO
         unsigned sentBytes = fillTransmitFifo(buffer, remainingBytes);
         remainingBytes -= sentBytes;
         buffer       += sentBytes/4;

         if (!startedWrite) {
            // Start programming
            Qspi0::initiateIpCommand(QspiSequenceIdentity_PageProgram, FLASH_PAGE_SIZE);
            startedWrite = true;
         }
      }
      // Wait until flash finished program
      waitForFlashWriteComplete();
   }

   static constexpr QspiSettings qspiSettings = {
         /* AHB request buffers           BUFxIND */ {{},{},{},{FLASH_PAGE_SIZE},}, // Using single buffer
         /* Buffer Generic Configuration  BFGENCR */ QspiSequenceIdentity_Read,     // Sequence for AHB reads
         /* Tx buffer configuration       TBCT    */ QspiBufferWaterMark_32_Bytes,
         /* Rx buffer configuration       RBCT    */ {QspiBufferWaterMark_32_Bytes, QspiBufferReadoutVia_AHB, },
         /* Flash sizes                   SFxxAD  */ {FLASH_SIZE, 0, 0, 0,}, // Single flash
   };

   static void qspiInit() {
      Qspi0::configure();
      Qspi0::configureQspi();
      Qspi0::softwareReset();
      Qspi0::setFlashTiming(QspiDataInHoldTime_InternalPosEdge, QspiChipSelectHoldTime_1_sck, QspiChipSelectSetupTime_0_5sck);
      Qspi0::configure(qspiSettings);
      Qspi0::writeLookUpTable(FLASH_SIZE>(1<<24)?luts_4byteAddress:luts_3ByteAddress);
      Qspi0::enableModule();
      clearWriteProtect();
   }

};

} // End namespace USBDM

#endif /* SOURCES_MT25QU256ABA_H_ */
