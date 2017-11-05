/*
 * CR20ADrv.cpp
 *
 *  Created on: 27Oct.,2017
 *      Author: podonoghue
 */

#include <string.h>
#include <random>

#include "CR20ADrv.h"
#include "cr20a.h"

namespace USBDM {

// FRDM-CR20A
using BlueLed  = GpioD<5, ActiveLow>;
using GreenLed = GpioB<1, ActiveLow>;
using RedLed   = GpioB<0, ActiveLow>;
using Switch1  = GpioC<8, ActiveLow>;
using Switch2  = GpioD<4, ActiveLow>;

// To use these interfaces is necessary to populate components on board
// R18, R19
using Serial   = Uart1;

using ClkOut   = GpioD<5, ActiveHigh>;
using RxSwitch = GpioC<3, ActiveHigh>;
using RstXcvr  = GpioA<1, ActiveLow>;
using Irqb     = GpioA<5, ActiveLow>;

// To use these interfaces is necessary to populate components on board
//
//using Gpio3  = GpioC<4,  ActiveHigh>;
//using Gpio4  = GpioA<12, ActiveHigh>;
//using Gpio5  = GpioA<2,  ActiveHigh>;
//using Gpio6  = GpioB<3,  ActiveHigh>;

void measureBoardVoltages() {
   // To use these it is necessary to populate components on board
   // L2-L7, C24-C26
   //using VddRegd_Monitor = Adc0Channel<14>;
   //using P3V3_Monitor    = Adc0Channel<15>;
   //using VddRF_Monitor   = Adc0Channel<7>;

   //   Adc0::configure(AdcResolution_12bit_se);
   //   Adc0::setAveraging(AdcAveraging_8);
   //   Adc0::calibrate();
   //
   //   console.write("VddRegd = ").writeln(VddRegd_Monitor::readAnalogue()*3.3/(1<<12));
   //   console.write("P3V3    = ").writeln(P3V3_Monitor::readAnalogue()*3.3/(1<<12));
   //   console.write("VddRF   = ").writeln(VddRF_Monitor::readAnalogue()*3.3/(1<<12));
}

/**
 * Configure CR20A interface
 */
void CR20ADrv::configureInterface() {

   // Configure SPI
   spi.setSpeed(5*MHz);
   spi.setDelays(31.25*ns, 32.25*ns, 62.5*ns);
   spi.setMode(SpiMode_0);
   spi.setPeripheralSelect(SpiPeripheralSelect_2, ActiveLow, SpiSelectMode_Idle);
   spi.setFrameSize(8);
   // Save configuration
   spiModemConfig_8Bit = spi.getConfig();

   // Configure SPI
   spi.setFrameSize(16);
   // Save configuration
   spiModemConfig_16Bit = spi.getConfig();

   // Configure SPI
   spi.setPeripheralSelect(SpiPeripheralSelect_2, ActiveLow, SpiSelectMode_Continuous);
   // Save configuration
   spiModemConfig_16BitContinuous = spi.getConfig();

   // Configure SPI
   spi.setFrameSize(8);
   // Save configuration
   spiModemConfig_8BitContinuous = spi.getConfig();

   RedLed::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);
   GreenLed::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);
   BlueLed::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);

   Switch1::setInput(PinPull_Up, PinIrq_None, PinFilter_Passive);
   Switch2::setInput(PinPull_Up, PinIrq_None, PinFilter_Passive);

   RstXcvr::setOutput(PinDriveStrength_Low, PinDriveMode_PushPull, PinSlewRate_Slow);
   Irqb::setInput(PinPull_Up, PinIrq_None, PinFilter_Passive);
}

/**
 * Write Register
 *
 * @param modemReg Indicates register to write
 * @param value    Value to write
 *
 * @return IRQSTS1 from modem
 */
uint8_t CR20ADrv::writeRegister(ModemReg modemReg, uint8_t value) {
   spi.startTransaction(spiModemConfig_16Bit);
   uint8_t status = (uint8_t)(spi.txRx(((REGISTER_WRITE|modemReg)<<8)|value)>>8);
   spi.endTransaction();
   return status;
}

/**
 * Read Register
 *
 * @param modemReg Indicates register to read
 * @param value    Value read
 *
 * @return IRQSTS1 from modem
 */
uint8_t CR20ADrv::readRegister(ModemReg modemReg, uint8_t &value) {
   spi.startTransaction(spiModemConfig_16Bit);
   uint16_t temp = spi.txRx(((REGISTER_READ|modemReg)<<8));
   spi.endTransaction();
   value = (uint8_t)(temp&0xFF);
   return (uint8_t)(temp>>8);
}

/**
 * Write Indirect Register
 *
 * @param modemIndirectReg   Indicates register to write
 * @param value    Value to write
 *
 * @return IRQSTS1 from modem
 */
uint8_t CR20ADrv::writeIndirectRegister(ModemIndirectReg modemIndirectReg, uint8_t value) {
   uint8_t buffer[] = {(uint8_t)(REGISTER_WRITE|ModemReg_IAR_INDEX), modemIndirectReg, value};
   spi.startTransaction(spiModemConfig_8Bit);
   spi.txRx(3, buffer, buffer);
   spi.endTransaction();
   return buffer[0];
}

/**
 * Read Indirect Register
 *
 * @param modemIndirectReg   Indicates register to read
 *
 * @return Value read
 */
uint8_t CR20ADrv::readIndirectRegister(ModemIndirectReg modemIndirectReg, uint8_t &value) {
   uint8_t buffer[] = {(uint8_t)(REGISTER_READ|ModemReg_IAR_INDEX), modemIndirectReg, 0};
   spi.startTransaction(spiModemConfig_8Bit);
   spi.txRx(3, buffer, buffer);
   spi.endTransaction();
   value = buffer[2];
   return buffer[0];
}

/**
 *  Burst write to packet buffer.
 *  This write will commence at the start of the buffer
 *
 * @param size Number of bytes to write
 * @param data Data to write
 *
 * @return IRQSTS1 from modem
 */
uint8_t CR20ADrv::writePacketBuffer(uint8_t size, uint8_t *data) {
   spi.startTransaction(spiModemConfig_8BitContinuous);
   uint8_t status = (uint8_t)spi.txRx(PKT_BUFFER_BURST_WRITE);
   spi.setConfig(spiModemConfig_8Bit);
   spi.txRx(size, data, (uint8_t *)nullptr);
   spi.endTransaction();
   return status;
}

/**
 *  Burst read from packet buffer.
 *  This read will commence at the start of the buffer
 *
 * @param size Number of bytes to read
 * @param data Data read
 *
 * @return IRQSTS1 from modem
 */
uint8_t CR20ADrv::readPacketBuffer(uint8_t size, uint8_t *data) {
   spi.startTransaction(spiModemConfig_8BitContinuous);
   uint8_t status = (uint8_t)spi.txRx(PKT_BUFFER_BURST_READ);
   spi.setConfig(spiModemConfig_8Bit);
   spi.txRx(size, (uint8_t *)nullptr, data);
   spi.endTransaction();
   return status;
}

#ifdef DEBUG_BUILD
void writeStatus(const char *name, uint8_t status) {
   console.write(name).setPadding(Padding_LeadingZeroes).setWidth(8).writeln(status, Radix_2).reset();
}
#else
void writeStatus(const char *, uint8_t) {}
#endif

/**
 * Reset Modem
 */
void CR20ADrv::resetModem() {

   // Select 32.787 kHz clock output
   ClkOut::setActive();

   // Hardware reset modem
   RstXcvr::setActive();
   waitMS(10);
   RstXcvr::setInactive();
   do {
      // Wait for modem to wake-up
   } while (Irqb::isInactive());

   // Get and clear IRQ status
   uint8_t value;
   readRegister(ModemReg_IRQSTS1, value);
   writeStatus("IRQSTS1 = 0b", value);
   readRegister(ModemReg_IRQSTS2, value);
   writeStatus("IRQSTS2 = 0b", value);
   readRegister(ModemReg_IRQSTS3, value);
   writeStatus("IRQSTS3 = 0b", value);

   writeRegister(ModemReg_IRQSTS1, 0xFF);
   writeRegister(ModemReg_IRQSTS2, 0xFF);
   writeRegister(ModemReg_IRQSTS3, 0xFF);
}

} /* namespace USBDM */

#if 1
using namespace USBDM;

Spi0 spi;

static CR20ADrv cr20{spi};

bool testDirectRegister() {
   // 8-bit read/write direct register
   ModemReg reg = ModemReg_PLL_FRAC0_LSB;
   // Fail test
   //   reg = ModemReg_PLL_INT0;
   bool success = true;
   for(int i=0;i<256;i++) {
      cr20.writeRegister(reg, i);
      uint8_t value;
      uint8_t status = cr20.readRegister(reg, value);
      success = (value == i);
      if (!success) {
         uint8_t value2;
         cr20.readRegister(reg, value2);
         console.write("Failed Direct Register Read/Write: ")
                     .write("Status = 0b").setPadding(Padding_LeadingZeroes).setWidth(8).write(status, Radix_2)
                     .write(", Write Value = 0x").setWidth(2).write(i, Radix_16)
                     .write(", Read Value1 = 0x").write(value, Radix_16).reset()
                     .write(", Read Value2 = 0x").writeln(value, Radix_16).reset();
         return false;
      }
   }
//   console.writeln("Passed Direct Register Read/Write Test");
   return true;
}

bool testIndirectRegister() {
   // 8-bit read/write indirect register
   ModemIndirectReg reg = ModemIndirectReg_RX_WTR_MARK;
   // Fail test
   //   reg = ModemIndirectReg_TXDELAY;
   bool success = true;
   for(int i=0;i<256;i++) {
      cr20.writeIndirectRegister(reg, i);
      uint8_t value;
      uint8_t status = cr20.readIndirectRegister(reg, value);
      success = (value == i);
      if (!success) {
         console.write("Failed Indirect Register Read/Write: ")
                     .write("Status = 0b").setPadding(Padding_LeadingZeroes).setWidth(8).write(status, Radix_2)
                     .write(", Write Value  = 0x").setWidth(2).write(i, Radix_16)
                     .write(", Read Value  = 0x").writeln(value, Radix_16).reset();
         return false;
      }
   }
//   console.writeln("Passed Indirect Register Read/Write Test");
   return true;
}

bool testBuffer() {
   bool success = true;
   static constexpr unsigned BUFFER_SIZE = 128;
   uint8_t sendPacketBuffer[BUFFER_SIZE];
   uint8_t receivePacketBuffer[BUFFER_SIZE] = {0};

   for(unsigned i=0;i<BUFFER_SIZE;i++) {
      sendPacketBuffer[i] = rand();
   }
   uint8_t status;
   status = cr20.writePacketBuffer(BUFFER_SIZE, sendPacketBuffer);
   //   writeStatus("Status after write = 0b", status);
   status = cr20.readPacketBuffer(BUFFER_SIZE, receivePacketBuffer);
   //   writeStatus("Status after read  = 0b", status);
   for(unsigned i=0;i<BUFFER_SIZE;i++) {
      success = sendPacketBuffer[i] == receivePacketBuffer[i];
      if (!success) {
         console.write("Failed Indirect Register Write: ")
               .write("Status = 0b").setPadding(Padding_LeadingZeroes).setWidth(8).write(status, Radix_2)
               .write(", Write Value  = 0x").setWidth(2).write(sendPacketBuffer[i], Radix_16)
               .write(", Value  = 0x").setWidth(2).writeln(receivePacketBuffer[i], Radix_16).reset();
         return false;
      }
   }
//   console.writeln("Passed TxRx Buffer Read/Write Test");
   return success;
}

int main() {
   BlueLed::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);

   for (int i=0;;i++) {
      if ((i%100) == 0) {
         BlueLed::toggle();
      }
      console.write("Test ").writeln(i);
      bool success =
            testDirectRegister() &&
            testIndirectRegister() &&
            testBuffer();
      if (!success) {
         break;
      }
   }

   for (;;) {
   }
   return 0;
}
#endif
