/**
 * @file     pn532.h
 * @brief    Interface for PN532 NFC Chip
 *
 * @version  V4.11.1.70
 * @date     28 Dec 2015
 */

#ifndef PROJECT_HEADERS_PN532_H_
#define PROJECT_HEADERS_PN532_H_

#include <stdint.h>
#include <spi.h>
#include "delay.h"

namespace USBDM {

/**
 * @addtogroup PN532_Group PN532 NFC Chip
 * @brief C++ Class allowing interface to PN532
 * @{
 */

/**
 * Base class representing an interface to a PN532 NFC chip
 */
class PN532Base {
public:
   static constexpr unsigned DEFAULT_READY_TIMEOUT = 1000; //!< Ready timeout in ms

protected:
   static constexpr uint8_t STATUS_READ   = 0x02;
   static constexpr uint8_t DATA_WRITE    = 0x01;
   static constexpr uint8_t DATA_READ     = 0x03;
   static constexpr uint8_t IDLE          = 0x00;
   static constexpr uint8_t PREAMBLE      = 0xFF;
   static constexpr uint8_t HOST_TO_NFC   = 0xD4;
   static constexpr uint8_t NFC_TO_HOST   = 0xD5;
   static const     uint8_t ACK_MSG[6];
   static const     uint8_t NACK_MSG[6];

   static constexpr uint8_t CMD_DIAGNOSE                 = 0x00;
   static constexpr uint8_t CMD_GET_FIRMWARE_VERSION     = 0x02;
   static constexpr uint8_t CMD_GET_GENERAL_STATUS       = 0x04;
   static constexpr uint8_t CMD_READ_REGISTER            = 0x06;
   static constexpr uint8_t CMD_WRITE_REGISTER           = 0x08;
   static constexpr uint8_t CMD_READ_GPIO                = 0x0C;
   static constexpr uint8_t CMD_WRITE_GPIO               = 0x0E;
   static constexpr uint8_t CMD_SET_SERIAL_BAUDRATE      = 0x10;
   static constexpr uint8_t CMD_SET_PARAMETERS           = 0x12;
   static constexpr uint8_t CMD_SAM_CONFIGURATION        = 0x14;
   static constexpr uint8_t CMD_POWER_DOWN               = 0x16;

   static constexpr uint8_t CMD_RF_CONFIGURATION         = 0x32;
   static constexpr uint8_t CMD_RF_REGULATION_TEST       = 0x58;
   static constexpr uint8_t CMD_IN_JUMP_FOR_DEP          = 0x56;
   static constexpr uint8_t CMD_IN_JUMP_FOR_PSL          = 0x46;
   static constexpr uint8_t CMD_IN_LIST_PASSIVE_TARGET   = 0x4A;
   static constexpr uint8_t CMD_IN_ATR                   = 0x50;
   static constexpr uint8_t CMD_IN_PSL                   = 0x4E;
   static constexpr uint8_t CMD_IN_DATA_EXCHANGE         = 0x40;

   static constexpr uint8_t CMD_IN_COMMUNICATE_THRU      = 0x42;
   static constexpr uint8_t CMD_IN_DESELECT              = 0x44;
   static constexpr uint8_t CMD_IN_RELEASE               = 0x52;
   static constexpr uint8_t CMD_IN_SELECT                = 0x54;
   static constexpr uint8_t CMD_IN_AUTO_POLL             = 0x60;
   static constexpr uint8_t CMD_TG_INIT_AS_TARGET        = 0x8C;
   static constexpr uint8_t CMD_TG_SET_GENERAL_BYTES     = 0x92;
   static constexpr uint8_t CMD_TG_GET_DATA              = 0x86;
   static constexpr uint8_t CMD_TG_SET_DATA              = 0x8E;
   static constexpr uint8_t CMD_TG_SET_META_DATA         = 0x94;
   static constexpr uint8_t CMD_TG_GET_INITIATOR_COMMAND = 0x88;
   static constexpr uint8_t CMD_TG_RESPONSE_TO_INITIATOR = 0x90;
   static constexpr uint8_t CMD_TG_GET_TARGET_STATUS     = 0x8A;

   USBDM::Spi *spi;

   /**
    * Assert cs_n
    */
   virtual void enable() = 0;
   /**
    * De-assert cs_n
    */
   virtual void disable() = 0;
   /**
    * Wait for PN532 ready
    *
    * @param  timeout Timeout value to use in milliseconds
    *
    * @return true => NFC is ready, false => timeout waiting for ready
    */
   bool waitReady(int timeout = DEFAULT_READY_TIMEOUT);
   /**
    * Get data from NFC
    *
    * @param length     Length of data
    * @param dataIn     Buffer for data received
    * @param timeout    Timeout value to use in milliseconds
    *
    * @return true => data received, false => Reception failed
    */
   bool rxData(unsigned length, uint8_t dataIn[], int timeout=DEFAULT_READY_TIMEOUT);
   /**
    * Get response from NFC
    *
    * @param expectedCmd  Expected command value in response
    * @param length       Length of data
    * @param dataIn       Buffer for data received
    * @param timeout      Timeout value to use in milliseconds
    *
    * @return true => data received, false => Reception failed
    */
   bool rxResponse(uint8_t expectedCmd, int length, uint8_t dataIn[], int timeout=DEFAULT_READY_TIMEOUT);
   /**
    * Get confirmation response from NFC.\n
    * Used to confirm commands with no return data value.
    *
    * @param expectedCmd  Expected command value in response
    * @param timeout      Timeout value to use in milliseconds
    *
    * @return true => data received, false => Reception failed
    */
   bool rxResponse(uint8_t expectedCmd, int timeout=DEFAULT_READY_TIMEOUT) {
      return rxResponse(expectedCmd, 0, 0, timeout);
   }
   /**
    * Send ACK to PN532
    */
   void sendAck() {
      spi->txRxBytes(sizeof(ACK_MSG), ACK_MSG, 0);
   }
   /**
    * Send NACK to PN532
    */
   void sendNack() {
      spi->txRxBytes(sizeof(NACK_MSG), NACK_MSG, 0);
   }
   /**
    * Gets ACK message from NFC
    *
    * @return true => ACK received, false => No ACK
    */
   bool getAck();
   /**
    * Transmit command to PN532.
    * The command is wrapped in the required pre/post-amble
    *
    * @code
    * Format of data sent:
    *        0     1     2     3     4     5     6    7                    L-3   L-2   L-1
    *       00    00    FF   LEN   LCS   TFI   cmd  (data[0]...data[length-1])]  DCS    00
    *
    * bytes 0..7, L-3..L-1 are determined by routine
    * @endcode
    *
    * @param command    Command byte to transmit
    * @param length     Length of data (data[0]...data[length-1])
    * @param dataOut    Data to transmit
    */
   void txCommand(uint8_t command, unsigned length, const uint8_t dataOut[]);
   /**
    * Transmit command to PN532.
    * The command is wrapped in the required pre/post-amble
    *
    * @code
    * Format of data sent:
    *        0     1     2     3     4     5     6   L-2   L-1
    *       00    00    FF   LEN   LCS   TFI   cmd   DCS    00
    *
    * bytes 0..7, L-3..L-1 are determined by routine
    * @endcode
    *
    * @param command    Command byte to transmit
    */
   void txCommand(uint8_t command);
   /**
    * Transmit command to PN532 and check ACK.\n
    * The command is wrapped in the required pre/post-amble
    *
    * @code
    * Format of data sent:
    *        0     1     2     3     4     5     6    7                    L-3   L-2   L-1
    *       00    00    FF   LEN   LCS   TFI   cmd  (data[0]...data[length-1])]  DCS    00
    *
    * bytes 0..7, L-3..L-1 are determined by routine
    * @endcode
    *
    * @param command    Command byte to transmit
    * @param length     Length of data (data[0]...data[length-1])
    * @param dataOut    Data to transmit
    */
   bool txCommandWithAck(uint8_t command, unsigned length, const uint8_t dataOut[]) {
      txCommand(command, length, dataOut);
      return getAck();
   }
   /**
    * Transmit command to PN532 and check ACK. No parameters.\n
    * The command is wrapped in the required pre/post-amble
    *
    * @code
    * Format of data sent:
    *        0     1     2     3     4     5     6   L-2   L-1
    *       00    00    FF   LEN   LCS   TFI   cmd   DCS    00
    *
    * bytes 0..7, L-2..L-1 are determined by routine
    * @endcode
    *
    * @param command    Command byte to transmit
    */
   bool txCommandWithAck(uint8_t command) {
      txCommand(command, 0, 0);
      return getAck();
   }
   /**
    * Constructor
    *
    * @param spi The SPI interface to use
    */
   PN532Base(USBDM::Spi *spi) : spi(spi) {
      spi->setSpeed(2000000);
      spi->setMode(SPI_LSBF|SPI_MODE0);
//      spi->setCTAR0Value(SPI_CTAR_SLAVE_FMSZ(8-1)|SPI_CTAR_LSBFE_MASK|USBDM::SPI_MODE0|SPI_CTAR_PASC(1)|SPI_CTAR_ASC(1));
      USBDM::waitUS(1000);
   }

public:
   /**
    * Struct for getFirmwareVersion()
    */
   struct FirmwareVersion {
      uint8_t ic;       //!< Version of the IC    (expected 0x32)
      uint8_t ver;      //!< Firmware version
      uint8_t rev;      //!< Firmware revision
      uint8_t support;  //!< Functions supported  (b2=ISO18092, b1=ISO/IEC14443 Type B, b0=ISO/IEC14443 Type A)
   };
   /**
    * Struct for getGeneralStatus()
    */
   struct GeneralStatus {
      uint8_t err;         //!< Error code
      uint8_t field;       //!< RF field indicator
      uint8_t nbTg;        //!< Number of targets currently controlled (<= 2)
      uint8_t samStatus;   //!< SAM status targets
      struct {
         uint8_t tg;       //!< Logical number
         uint8_t brRx;     //!< Reception bit rate
         uint8_t brTx;     //!< Transmission bit rate
         uint8_t type;     //!< modulation type
      } targetStatus[2];   //!< Status for each connected target (see @ref nbTg)
   };
   /**
    * Struct for readGpio(), writeGpio()
    */
   struct GpioValues {
      uint8_t p3;    //!< port P.3 [P.35..P.30]
      uint8_t p7;    //!< port P.7 [P.72..P.71]
      uint8_t ioi1;  //!< port ioi1 [I.1..I.0]
   };
   /**
    * Struct for samConfiguration()
    */
   struct SamConfiguration {
      uint8_t mode;     //!< SAM mode 1=normal, 2=virtual card, 3=wired card, 4=dualcard
      uint8_t timeout;  //!< Timeout in 50ms increments, 0=No timeout
      uint8_t irq;      //!< P70_IRQ control, 0=Not used (high), 1=driven by PN532
   };
   /**
    * Struct for powerDown()
    */
   struct PowerDown {
      uint8_t wakeupEnable;   //!< Wake-up sources see @ref WAKEUP_INT0 etc
      uint8_t generateIrq;    //!< Generate IRQ on wake-up due to RF level change
   };
   /**
    * Struct for readPassiveTargetID()
    */
   class Uid {
   public:
      uint8_t length;   //!< Length of uid (0 => invalid)
      uint8_t uid[8];   //!< UID bytes
      int compareTo(Uid other) {
         int len = length;
         if (other.length<len) {
            len = other.length;
         }
         for (int index=0; index<len; index++) {
            int diff = uid[index] - other.uid[index];
            if (diff != 0) {
               return diff;
            }
         }
         return length-other.length;
      }
   };
   /**
    * Register addresses for readRegister(), writeRegister()
    */
   static constexpr uint16_t PCON         = 0xFF87;
   static constexpr uint16_t RWL          = 0xFF9A;
   static constexpr uint16_t TWL          = 0xFF9B;
   static constexpr uint16_t FIFOFS       = 0xFF9C;
   static constexpr uint16_t FIFOFF       = 0xFF9D;
   static constexpr uint16_t SFF          = 0xFF9E;
   static constexpr uint16_t FIT          = 0xFF9F;
   static constexpr uint16_t FITEN        = 0xFFA1;
   static constexpr uint16_t FDATA        = 0xFFA2;
   static constexpr uint16_t FSIZE        = 0xFFA3;
   static constexpr uint16_t IE0          = 0xFFA8;
   static constexpr uint16_t SPIcontrol   = 0xFFA9;
   static constexpr uint16_t SPIstatus    = 0xFFAA;
   static constexpr uint16_t HSU_STA      = 0xFFAB;
   static constexpr uint16_t HSU_CTR      = 0xFFAC;
   static constexpr uint16_t HSU_PRE      = 0xFFAD;
   static constexpr uint16_t HSU_CNT      = 0xFFAE;
   static constexpr uint16_t P3           = 0xFFB0;
   static constexpr uint16_t IP0          = 0xFFB8;
   static constexpr uint16_t CIU_COMMAND  = 0xFFD1;
   static constexpr uint16_t IEN1         = 0xFFE8;
   static constexpr uint16_t P7CFGA       = 0xFFF4;
   static constexpr uint16_t P7CFGB       = 0xFFF5;
   static constexpr uint16_t P7           = 0xFFF7;
   static constexpr uint16_t IP1          = 0xFFF8;
   static constexpr uint16_t P3CFGA       = 0xFFFC;
   static constexpr uint16_t P3CFGB       = 0xFFFD;

   /*
    * Bit masks for setParameters()
    */
   static constexpr uint8_t fNADUsed            = (1<<0);
   static constexpr uint8_t fDIDUsed            = (1<<1);
   static constexpr uint8_t fAutomaticATR_RES   = (1<<2);
   static constexpr uint8_t fAutomaticRATS      = (1<<4);
   static constexpr uint8_t fISO14443_4_PICC    = (1<<5);
   static constexpr uint8_t fRemovePrePostAmble = (1<<6);

   /*
    * Config Item numbers for rfConfiguration()
    */
   static const uint8_t RF_CONFIG_RF_FIELD      = 0x1;
   static const uint8_t RF_CONFIG_TIMING        = 0x2;
   static const uint8_t RF_MAX_RETRY_COM        = 0x4;
   static const uint8_t RF_MAX_RETRY            = 0x5;
   static const uint8_t RF_ANALOGUE_106KPS_A    = 0xA;
   static const uint8_t RF_ANALOGUE_212_424KPS  = 0xA;
   static const uint8_t RF_ANALOGUE_B           = 0xC;
   static const uint8_t RF_ANALOGUE_848KPS      = 0xD;

   /*
    * Bit masks for powerDown() wakeupEnable byte
    */
   static const uint8_t WAKEUP_INT0       = (1<<0);
   static const uint8_t WAKEUP_INT1       = (1<<1);
   static const uint8_t WAKEUP_RF_LEVEL   = (1<<3);
   static const uint8_t WAKEUP_HSU        = (1<<4);
   static const uint8_t WAKEUP_SPI        = (1<<5);
   static const uint8_t WAKEUP_GPIO       = (1<<6);
   static const uint8_t WAKEUP_I2C        = (1<<7);

   /*
    * Card types for readPassiveTargetID()
    */
   static const uint8_t CARD_MIFARE_ISO14443A  = 0; // 106kbps TypeA
   static const uint8_t CARD_106_TYPE_A        = 0; // 106kbps TypeA
   static const uint8_t CARD_212               = 1; // 212kbps
   static const uint8_t CARD_424               = 2; // 424kbps
   static const uint8_t CARD_106_TYPE_B        = 3; // 106kbps TypeB
   static const uint8_t CARD_INNOVISION        = 4; // 106kbps Innovision
   /**
    * Get firmware information
    *
    * @param firmwareVersion Struct to contain information
    *
    * @return true => success, false => fail
    */
   bool getFirmwareVersion(FirmwareVersion &firmwareVersion) {
      if (!txCommandWithAck(CMD_GET_FIRMWARE_VERSION)) {
         return false;
      }
      return rxResponse(CMD_GET_FIRMWARE_VERSION+1, sizeof(PN532Base::FirmwareVersion), (uint8_t*)&firmwareVersion);
   }
   /**
    * Get General Status
    *
    * @param status Status from PN532
    *
    * @return true => success, false => fail
    */
   bool getGeneralStatus(GeneralStatus &status);
   /**
    * Read NFC register (8051 registers!)
    *
    * @param address          Address to read (see PCON etc for SFR values, may also be XRAM address)
    * @param registerValue    Register value read
    *
    * @return true => success, false => fail
    */
   bool readRegister(uint16_t address, uint8_t &registerValue) {
      const uint8_t dataOut[] =  {(uint8_t)(address>>8), (uint8_t)address};
      if (!txCommandWithAck(CMD_READ_REGISTER, sizeof(dataOut), dataOut)) {
         return false;
      }
      return rxResponse(CMD_READ_REGISTER+1, sizeof(registerValue), &registerValue);
   }
   /**
    * Write NFC register (8051 registers!)
    *
    * @param address          Address to read (see PCON etc for SFR values, may also be XRAM address)
    * @param registerValue    Register value read
    *
    * @return true => success, false => fail
    */
   bool writeRegister(uint16_t address, uint8_t registerValue) {
      const uint8_t dataOut[] =  {(uint8_t)(address>>8), (uint8_t)address, registerValue};
      if (!txCommandWithAck(CMD_WRITE_REGISTER, sizeof(dataOut), dataOut)) {
         return false;
      }
      return rxResponse(CMD_WRITE_REGISTER+1);
   }
   /**
    * Read GPIOs
    *
    * @param gpioValues Value read from PN532 (8051 ports)
    *
    * @return true => success, false => fail
    */
   bool readGpio(GpioValues &gpioValues) {
      if (!txCommandWithAck(CMD_READ_GPIO)) {
         return false;
      }
      return rxResponse(CMD_READ_GPIO+1, sizeof(gpioValues), (uint8_t *)&gpioValues);
   }
   /**
    * Write value to GPIOs
    *
    * @param gpioValues Value to write\n
    *                   Only P3[5..0] are accepted as P7 is use for SPI
    *
    * @return true => success, false => fail
    */
   bool writeGpio(const GpioValues &gpioValues) {
      constexpr uint8_t VALIDATE = (1<<7);
      const uint8_t dataOut[] =  {(uint8_t)(VALIDATE|gpioValues.p3), 0x00};
      if (!txCommandWithAck(CMD_WRITE_GPIO, sizeof(dataOut), dataOut)) {
         return false;
      }
      return rxResponse(CMD_WRITE_GPIO+1);
   }
   /**
    * Write value to GPIOs
    *
    * @param flags Flag value to write (@ref fNADUsed)
    *
    * @return true => success, false => fail
    */
   bool setParameters(const uint8_t flags) {
      if (!txCommandWithAck(CMD_SET_PARAMETERS, sizeof(flags), &flags)) {
         return false;
      }
      return rxResponse(CMD_SET_PARAMETERS+1);
   }
   /**
    * This command is used to select the data flow path by
    * configuring the internal serial data switch.
    *
    * @param config Configuration to set
    *
    * @return true => success, false => fail
    */
   bool samConfiguration(const SamConfiguration &config) {
      if (!txCommandWithAck(CMD_SAM_CONFIGURATION, sizeof(config), (uint8_t*)&config)) {
         return false;
      }
      return rxResponse(CMD_SAM_CONFIGURATION+1);
   }
   /**
    * This command can be used to put the PN532 (including the contact-less analogue front end)
    * into Power Down mode in order to save power consumption.
    *
    * @param powerDownControl Control value
    * @param status           Status value from command
    *
    * @return true => success, false => fail
    */
   bool powerDown(const PowerDown &powerDownControl, uint8_t &status) {
      if (!txCommandWithAck(CMD_POWER_DOWN, sizeof(powerDownControl), (uint8_t*)&powerDownControl)) {
         return false;
      }
      return rxResponse(CMD_POWER_DOWN+1, sizeof(status), &status);
   }
   /**
    * This command is used to configure the different settings of the PN532
    *
    * @param length  Length of data
    * @param data    Configuration to set (varies, 1st byte determines command)
    *
    * @return true => success, false => fail
    */
   bool rfConfiguration(int length, const uint8_t data[]) {
      if (!txCommandWithAck(CMD_RF_CONFIGURATION, length, data)) {
         return false;
      }
      return rxResponse(CMD_RF_CONFIGURATION+1);
   }
   /**
    * Configure Secure Access Module
    */
   bool samConfig() {
      static const SamConfiguration configuration = {
            0x01, // normal mode
            20,   // timeout = 1s
            true, // use IRQ pin
      };
      return samConfiguration(configuration);
   }
   /**
    * Get firmware version as 32-bit number
    *
    * @return Firmware version as 4 bytes = ic:ver:rev:support
    */
   uint32_t getFirmwareVersion(void) {
      FirmwareVersion firmwareVersion;
      if (getFirmwareVersion(firmwareVersion)) {
         return (firmwareVersion.ic<<24)|(firmwareVersion.ver<<16)|(firmwareVersion.rev<<8)|(firmwareVersion.support);
      }
   }
   /**
    *  Poll for passive targets
    *
    *  @param  cardType      Type/baud rate of the card (0=106kbps TypeA, 1=212kbps, 2=424kbps, 3=106kbps TypeB, 4=106kbps Innovision)
    *  @param  numTargets    Maximum number if cards to accept
    *  @param  dataSize      Maximum number of bytes to receive (size of data buffer). If zero no response is waited for.
    *  @param  data          Data buffer
    *  @param  timeout       Timeout in milliseconds
    *
    *  @return true => success, false => fail
    */
   bool inListPassiveTarget(uint8_t cardType, uint8_t numTargets, int dataSize, uint8_t data[], int timeout) {
      uint8_t buffer[] = {numTargets, cardType};
      if (!txCommandWithAck(CMD_IN_LIST_PASSIVE_TARGET, sizeof(buffer), buffer)) {
         return false;
      }
      if (dataSize == 0) {
         // Don't wait for response
         return true;
      }
      return rxResponse(CMD_IN_LIST_PASSIVE_TARGET+1, dataSize, data, timeout);
   }
   /**
    *  Poll for passive targets.  Doesn't wait for response\n
    *  It is assumed that the response will be obtained later after IRQ is triggered.
    *
    *  @param  cardType      Type/baud rate of the card (0=106kbps TypeA, 1=212kbps, 2=424kbps, 3=106kbps TypeB, 4=106kbps Innovision)
    *  @param  numTargets    Maximum number if cards to accept
    *
    *  @return true => success, false => fail
    */
   bool inListPassiveTarget(uint8_t cardType, uint8_t numTargets) {
      return inListPassiveTarget(cardType, numTargets, 0, 0, 0);
   }
   /**
    *  Waits for an ISO14443A target to enter the field
    *
    *  @param  uid           Struct to return UID of detected card (if any)
    *  @param  timeout       Timeout in milliseconds
    *
    *  @return true => success, false => fail
    */
   bool readPassiveTargetID(Uid &uid, uint16_t timeout) {
      // Set up for no card
      memset(&uid, 0, sizeof(uid));

      uint8_t buffer[10];
      if (!inListPassiveTarget(CARD_MIFARE_ISO14443A, 1, sizeof(buffer), buffer, timeout)) {
         return false;
      }
      /*
       * ISO14443A card response assumed:
       * index            Description
       * -------------   ------------------------------------------
       * 0              Tags Found
       * 1              Tag Number
       * 2..3           SENS_RES
       * 4              SEL_RES
       * 5              NFC ID Length
       * 6..length      NFC ID
       */
      if (buffer[0] != 1) {
         // Only handle 1 target
         return false;
      }
      /* Assume card Mifare Classic */
      uid.length = buffer[5];
      for (uint8_t i=0; i < uid.length; i++) {
         uid.uid[i] = buffer[6+i];
      }
      return true;
   }
};

/**
 * Class representing an interface to a PN532 NFC chip
 *
 * @tparam cs_n Gpio to use as CS* to PN532
 */
template<typename cs_n>
class PN532_T : public PN532Base {
public:
   /**
    * Constructor
    *
    * @param spi The SPI interface to use
    */
   PN532_T(USBDM::Spi *spi) : PN532Base(spi) {
      cs_n::setOutput();
      cs_n::set();
   }
protected:
   /**
    * Assert cs_n
    */
   virtual void enable() {
      cs_n::clear();
   }
   /**
    * De-assert cs_n
    */
   virtual void disable() {
      cs_n::set();
   }
};

/**
 * @}
 */

} // End namespace USBDM

#endif /* PROJECT_HEADERS_PN532_H_ */
