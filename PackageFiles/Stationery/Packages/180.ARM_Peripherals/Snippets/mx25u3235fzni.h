/*
 * @file Mx25u3235fzni.h  (180.ARM_Peripherals/Snippets/Mx25u3235fzni.h)
 *
 *  Created on: 25 Nov. 2021
 *      Author: peter
 */

#ifndef SOURCES_MX25U3235FZNI_H_
#define SOURCES_MX25U3235FZNI_H_

#include "qspi.h"

namespace USBDM {

/**
 * Maxronix MX25U3235F Serial NOR Flash Memory (2 of)
 * ===================================================
 * 32 Mib (4 MiB)
 * 1-die
 * Dual/quad I/O commands for increased through-put
 * Supported protocols: Extended, Dual and Quad I/O both STR and DTR
 * 256 byte page size
 *
 * https://www.macronix.com/Lists/Datasheet/Attachments/7438/MX25U3235F,%201.8V,%2032Mb,%20v1.6.pdf
 */
class Mx25u3235fzni {
private:
   Mx25u3235fzni() = delete;
   virtual ~Mx25u3235fzni() = delete;
   Mx25u3235fzni(const Mx25u3235fzni &other) = delete;
   Mx25u3235fzni(Mx25u3235fzni &&other) = delete;
   Mx25u3235fzni& operator=(const Mx25u3235fzni &other) = delete;

   /// Size of Flash A1 in bytes 4 MiB (0x40'0000)
   static constexpr unsigned FLASHA1_SIZE = 1<<22;

   /// Size of Flash A1 in bytes 0 MiB
   static constexpr unsigned FLASHA2_SIZE = 0;

   /// Size of Flash B1 in bytes 4 MiB (0x40'0000)
   static constexpr unsigned FLASHB1_SIZE = 1<<22;

   /// Size of Flash B1 in bytes 0 MiB
   static constexpr unsigned FLASHB2_SIZE = 0;

public:
   /// Size of flash page in bytes (maximum program unit)
   static constexpr unsigned FLASH_PAGE_SIZE = 256;

   /// Size of flash sector in bytes (minimum erase unit)
   static constexpr unsigned FLASH_SECTOR_SIZE = 4096;

   /// Size of entire flash in bytes
   static constexpr unsigned FLASH_SIZE = FLASHA1_SIZE+FLASHA2_SIZE+FLASHB1_SIZE+FLASHB2_SIZE;

   /// Base address of flash in MCU memory
   static constexpr unsigned FLASH_START = Qspi0::QSPI0_AMBA_BASE_ADDRESS;

   /**
    * Used to declare an array mapping to the flash in memory\n
    * Read access only
    *
    * @tparam AccessType Access type for the array e.g. int
    */
   template<typename AccessType>
   using FlashArrayType = MemoryAddressWrapper<const AccessType, FLASH_START, FLASH_SIZE/sizeof(AccessType)>;

private:
   /// Com-addr-data Dummy Cycles
   /// Ext.    Adr    Quad Data
   /// SPI     By     SPI  Bytes
   /// 1-1-4   3      8    >=1
   static constexpr uint8_t QUAD_READ  = 0x6B; // Requires enabling Quad-mode in status register

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-1-0 2-2-0 4-4-0 4   0    0     0   0
   static constexpr uint8_t SUBSECTOR_ERASE_4KB_4BYTE    = 0x21; // (SE)

   /// Com-addr-data   Dummy Cycles
   /// Ext.      Adr   Ext.          Data
   /// SPI       By    SPI           Bytes
   /// 1-1-1     3     8             >=1
   static constexpr uint8_t FAST_READ                   = 0x0B;

   /// Com-addr-data        Dummy Cycles
   /// Ext.  Dual  Quad  Adr Ext. Dual Quad Data
   /// SPI   SPI   SPI   By  SPI  SPI  SPI  Bytes
   /// 1-0-1 2-0-2 4-0-4 0   0    0     0   >=1
   static constexpr uint8_t READ_STATUS_REGISTER        = 0x05;

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
#if 1
         /* Seq0: Quad Read */
         /* CMD:        0x6B - QUAD_READ,      Single pad */
         /* ADDR:       0x18 - 24bit address,  Single pad */
         /* DUMMY:      0x08 - 8 clock cycles             */
         /* READ:       0x80 - Read 128 bytes, Quad pads  */
         /* JUMP_ON_CS: 0 */
         // {04EC, 0A18, 0E08, 1E80, 2400}
         {
               Qspi0::lutEntry_Command(QspiLutPadInfo_1Pad, QUAD_READ),
               Qspi0::lutEntry_Addr(QspiLutPadInfo_1Pad, 24),
               Qspi0::lutEntry_Dummy(QspiLutPadInfo_1Pad, 8),
               Qspi0::lutEntry_Read(QspiLutPadInfo_4Pads, 128),
               Qspi0::lutEntry_JumpOnCs(0),
         },
#else
         /* Seq0: Fast Read */
         /* CMD:        0x6B - FAST_READ,      Single pad */
         /* ADDR:       0x18 - 24bit address,  Single pad */
         /* DUMMY:      0x06 - 8 clock cycles             */
         /* READ:       0x80 - Read 128 bytes, Single pads  */
         /* JUMP_ON_CS: 0 */
         // {04EB, 0A18, 0E0A, 1E80, 2400}
         {
               Qspi0::lutEntry_Command(QspiLutPadInfo_1Pad, FAST_READ),
               Qspi0::lutEntry_Addr(QspiLutPadInfo_1Pad, 24),
               Qspi0::lutEntry_Dummy(QspiLutPadInfo_1Pad, 8),
               Qspi0::lutEntry_Read(QspiLutPadInfo_1Pad, 128),
               Qspi0::lutEntry_JumpOnCs(0),
         },
#endif
         /* Seq1: Write Enable */
         /* CMD:      0x06 - Write Enable, Single pad */
         // {0406}
         {
               Qspi0::lutEntry_Command(QspiLutPadInfo_1Pad, WRITE_ENABLE),
         },
         /* Seq2: Erase All */
         /* CMD:    0x60 - Erase All chip, Single pad */
         //  {0406}
         {
               Qspi0::lutEntry_Command(QspiLutPadInfo_1Pad, ERASE_ALL),
         },
         /* Seq3: Read Status */
         /* CMD:    0x05 - Read Status, single pad */
         /* READ:   0x01 - Read 1 byte, single pad */
         // {0405, 1C01}
         {
               Qspi0::lutEntry_Command(QspiLutPadInfo_1Pad, READ_STATUS_REGISTER),
               Qspi0::lutEntry_Read(QspiLutPadInfo_1Pad, 1),
         },
         /* Seq4: Page Program */
         /* CMD:    0x02 - Page Program, Single pad */
         /* ADDR:   0x18 - 24bit address, Single pad */
         /* WRITE:  0x80 - Write 128 bytes at one pass, Single pad */
         // {0402, 0818, 2080}
         {
               Qspi0::lutEntry_Command(QspiLutPadInfo_1Pad, PAGE_PROGRAM),
               Qspi0::lutEntry_Addr(QspiLutPadInfo_1Pad, 24),
               Qspi0::lutEntry_Write(QspiLutPadInfo_1Pad, 128),
         },
         /* Seq5: Erase 4KiB Sector */
         /* CMD:  0x20 - Sector Erase, single pad */
         /* ADDR: 0x18 - 24 bit address, single pad */
         // {0420, 0818}
         {
               Qspi0::lutEntry_Command(QspiLutPadInfo_1Pad, SUBSECTOR_ERASE_4KB),
               Qspi0::lutEntry_Addr(QspiLutPadInfo_1Pad, 24),
         },
         /* Seq6: Write Status Register */
         /* CMD:    0x01 - Write Status Register, single pad */
         /* WRITE:  0x01 - Write 1 byte of data, single pad */
         // {0401, 2001}
         {
               Qspi0::lutEntry_Command(QspiLutPadInfo_1Pad, WRITE_STATUS_REGISTER),
               Qspi0::lutEntry_Write(QspiLutPadInfo_1Pad, 1),
         },
   };

   static const QspiSequenceIdentity QspiSequenceIdentity_Read            = QspiSequenceIdentity_0;
   static const QspiSequenceIdentity QspiSequenceIdentity_WriteEnable     = QspiSequenceIdentity_1;
   static const QspiSequenceIdentity QspiSequenceIdentity_EraseAll        = QspiSequenceIdentity_2;
   static const QspiSequenceIdentity QspiSequenceIdentity_ReadStatusReg   = QspiSequenceIdentity_3;
   static const QspiSequenceIdentity QspiSequenceIdentity_PageProgram     = QspiSequenceIdentity_4;
   static const QspiSequenceIdentity QspiSequenceIdentity_EraseSector     = QspiSequenceIdentity_5;
   static const QspiSequenceIdentity QspiSequenceIdentity_WriteStatusReg  = QspiSequenceIdentity_6;

   enum MX25U3235F_Status {
      MX25U3235F_WriteInProgress  = 1<<0,
      MX25U3235F_WriteEnable      = 1<<1,
      MX25U3235F_QuadEnable       = 1<<6,
   };

   static constexpr uint8_t MX25U3235F_WriteProtect_MASK = 0b00111100;
   static constexpr uint8_t MX25U3235F_WriteProtect_None = 0b00000000;

   /**
    * Read flash status
    */
   static uint8_t readFlashStatus() {
      Qspi0::waitForIdle();
      Qspi0::clearFifos(QspiFifoClear_Receive);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_ReadStatusReg);
      Qspi0::waitForIdle();
      uint8_t status = Qspi0::readRxDataBuffer(0);
      Qspi0::clearFlags(QspiFlag_RxBufferDrain);
      return status;
   }

   /**
    * Poll flash until status indicates idle i.e. no write, program or erase operation is current
    */
   static void waitForFlashWriteComplete() {
      while (readFlashStatus() & MX25U3235F_WriteInProgress) {
      }
   }

   /**
    * Clear write-protect and enable QUAD in status register
    */
   static void configureFlash() {

      // Data to send - must be >= 16 bytes
      uint32_t buff[] = {
            MX25U3235F_WriteProtect_None|MX25U3235F_QuadEnable,
            0, 0, 0};

      Qspi0::setSerialFlashAddress(FLASH_START);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_WriteEnable);
      waitForFlashWriteComplete();

      Qspi0::clearFifos(QspiFifoClear_Transmit);

      // Fill FIFO
      fillTransmitFifo(buff, sizeof(buff));

      // Write to config register
      Qspi0::initiateIpCommand(QspiSequenceIdentity_WriteStatusReg, 1);
      waitForFlashWriteComplete();

      uint8_t status = readFlashStatus();
      (void) status;

      usbdm_assert((status & MX25U3235F_WriteProtect_MASK) == MX25U3235F_WriteProtect_None, "Write protect clearing failed");
      usbdm_assert(((status & MX25U3235F_QuadEnable) == MX25U3235F_QuadEnable), "Quad mode init failed");
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
    * Main settings
    */
   static constexpr QspiSettings settings = {
         /* Clock source                          */ QspiClockSource_MCGPLL,
         /* Baud rate                             */ 24000000U,
         /* AHB request buffers           BUFxIND */ {{},{},{},{FLASH_PAGE_SIZE},}, // Using single buffer
         /* Buffer Generic Configuration  BFGENCR */ QspiSequenceIdentity_Read,     // Sequence for AHB reads
         /* Tx buffer configuration       TBCT    */ QspiBufferWaterMark_32_Bytes,
         /* Rx buffer configuration       RBCT    */ {QspiBufferWaterMark_32_Bytes, QspiBufferReadoutVia_AHB, },
         /* Flash sizes A1, A2, B1, B2    SFxxAD  */ {FLASHA1_SIZE, FLASHA2_SIZE, FLASHB1_SIZE, FLASHB2_SIZE,},
   };

   /**
    * Advanced settings example - unused
    */
   static constexpr QspiAdvancedSettings advancedSettings {
      QspiDDR_Disable,
      QspiEndian_64bit_LE,
      QspiFlashClock2Pin_Disabled,
      QspiDiffClockEnable_Disabled,
      QspiOctalDataPins_Disabled,
   };

   /**
    * DQS settings example - unused
    */
   static constexpr QspiDqsSettings dqsSettings {
      QspiDqsLatency_Disable,
      QspiLoopDqs_External,
      QspiPhaseSelectDqs_None,
      QspiDqsClockPolarity_NonInverted,
      qspiDelayTabSelectA(0),
      qspiDelayTabSelectB(0)
   };

public:

   /**
    * Erase sector in flash
    *
    * @param flashAddress  Flash address within sector (relative to start of flash memory)
    */
   static void eraseSector(uint32_t flashAddress) {

      Qspi0::waitForIdle();
      Qspi0::setSerialFlashAddress(flashAddress+FLASH_START);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_WriteEnable);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_EraseSector);
      waitForFlashWriteComplete();
   }

   /**
    * Erase all of flash
    */
   static void eraseAll() {

      Qspi0::waitForIdle();
      Qspi0::setSerialFlashAddress(FLASH_START);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_WriteEnable);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_EraseAll);
      waitForFlashWriteComplete();
   }

   /**
    * Program a page to flash
    *
    * @param flashAddress  Flash address (relative to start of flash memory)
    *                      Must be on flash page boundary (see @ref FLASH_PAGE_SIZE)
    * @param buffer        Page of data to write
    */
   static void programPage(uint32_t flashAddress, uint32_t buffer[FLASH_PAGE_SIZE]) {

      usbdm_assert((flashAddress&(FLASH_PAGE_SIZE-1))==0,"Start address must be on a flash page boundary");

      Qspi0::waitForIdle();
      Qspi0::setSerialFlashAddress(flashAddress+FLASH_START);
      Qspi0::initiateIpCommand(QspiSequenceIdentity_WriteEnable);
      Qspi0::waitForIdle();

      int remainingBytes = FLASH_PAGE_SIZE;
      bool startedWrite = false;

      Qspi0::clearFifos(QspiFifoClear_Transmit);

      while (remainingBytes>0) {

         // Fill FIFO
         unsigned sentBytes = fillTransmitFifo(buffer, remainingBytes);
         remainingBytes -= sentBytes;
         buffer         += sentBytes/4;

         if (!startedWrite) {
            // Start programming
            Qspi0::initiateIpCommand(QspiSequenceIdentity_PageProgram, FLASH_PAGE_SIZE);
            startedWrite = true;
         }
      }
      // Wait until flash finished program
      waitForFlashWriteComplete();
   }

   /**
    * Initialise the QSPI interface for the flash chip
    */
   static void initialise() {
      Qspi0::configure(settings);
//      Qspi0::configureAdvanced(advancedSettings);
//      Qspi0::configureDqs(dqsSettings);
      Qspi0::setFlashTiming(QspiDataInHoldTime_InternalPosEdge, QspiChipSelectHoldTime_1_sck, QspiChipSelectSetupTime_0_5sck);
      Qspi0::writeLookUpTable(luts_3ByteAddress);
      Qspi0::enableModule();
      configureFlash();
   }

};

} // End namespace USBDM

#endif /* SOURCES_MX25U3235FZNI_H_ */
