/*
 * CR20ADrv.h
 *
 *  Created on: 27Oct.,2017
 *      Author: podonoghue
 */

#ifndef SOURCES_CR20ADRV_H_
#define SOURCES_CR20ADRV_H_

#include "spi.h"
#include "cr20a.h"

namespace USBDM {

class CR20ADrv {

protected:
   Spi0 &spi;

   SpiConfig spiModemConfig_8Bit;
   SpiConfig spiModemConfig_8BitContinuous;
   SpiConfig spiModemConfig_16Bit;
   SpiConfig spiModemConfig_16BitContinuous;

   /**
    * Configure CR20A interface
    */
   void configureInterface();

public:
   /**
    * Constructor
    *
    * @param spi  SPI to use for communication
    */
   CR20ADrv(Spi0 &spi) : spi(spi) {
      configureInterface();
      resetModem();
   }

   /**
    * Reset Modem
    */
   void resetModem();

   /**
    * Write Register
    *
    * @param modemReg Indicates register to write
    * @param value    Value to write
    *
    * @return IRQSTS1 from modem
    */
   uint8_t writeRegister(ModemReg modemReg, uint8_t value);

   /**
    * Read Register
    *
    * @param modemReg Indicates register to read
    * @param value    Value read
    *
    * @return IRQSTS1 from modem
    */
   uint8_t readRegister(ModemReg modemReg, uint8_t &value);

   /**
    * Write Indirect Register
    *
    * @param modemIndirectReg   Indicates register to write
    * @param value    Value to write
    *
    * @return IRQSTS1 from modem
    */
   uint8_t writeIndirectRegister(ModemIndirectReg modemIndirectReg, uint8_t value);

   /**
    * Read Indirect Register
    *
    * @param modemIndirectReg   Indicates register to read
    *
    * @return Value read
    */
   uint8_t readIndirectRegister(ModemIndirectReg modemIndirectReg, uint8_t &value);

   /**
    *  Burst write to packet buffer.
    *  This write will commence at the start of the buffer
    *
    * @param size Number of bytes to write
    * @param data Data to write
    *
    * @return IRQSTS1 from modem
    */
   uint8_t writePacketBuffer(uint8_t size, uint8_t *data);

   /**
    *  Burst read from packet buffer.
    *  This read will commence at the start of the buffer
    *
    * @param size Number of bytes to read
    * @param data Data read
    *
    * @return IRQSTS1 from modem
    */
   uint8_t readPacketBuffer(uint8_t size, uint8_t *data);
};

} /* namespace USBDM */

#endif /* SOURCES_CR20ADRV_H_ */
