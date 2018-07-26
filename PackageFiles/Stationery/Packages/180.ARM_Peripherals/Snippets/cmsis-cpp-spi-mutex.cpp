/**
 ============================================================================
 * @file cmsis-cpp-spi-mutex.cpp (180.ARM_Peripherals/Snippets)
 * @brief RTX Thread/SPI/MUTEX example program
 *
 *  Created on: 23/7/2018
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"  // Hardware interface
#include "cmsis.h"     // CMSIS RTX
#include "spi.h"

using namespace USBDM;

using RED_LED   = GpioC<3>;

/**
 * This is a Thread class that generates SPI transactions
 */
class MyThread : public CMSIS::ThreadClass  {
   Spi &spi;
   SpiConfig config;

public:
   /**
    * Constructor
    *
    * @param spi     SPI to use
    * @param speed   SPI speed
    */
   MyThread(Spi &spi, uint32_t speed) : spi(spi) {
      RED_LED::toggle();

      // Configure SPI as required and save configuration
      spi.setSpeed(speed);
      spi.setMode(SpiMode_0);
      spi.setPeripheralSelect(SpiPeripheralSelect_2, ActiveLow);
      config = spi.getConfiguration();
   }

private:
   /**
    * This method becomes the thread
    */
   void task() override {
      static const uint8_t data[] = {1,2,3,4,5,6,7,8,9,0};

      for(;;) {
         // Obtain shared SPI
         if (spi.startTransaction(config) != osOK) {
            setAndCheckErrorCode(E_LOST_ARBITRATION);
         }
         // Use SPI
         spi.txRx(sizeof(data),data);

         // Release shared SPI
         if (spi.endTransaction() != osOK) {
            setAndCheckErrorCode(E_LOST_ARBITRATION);
         }
      }
   }
};

/**
 * SPI threads example
 */
static void spiExample() {

   // Set the LEDs as outputs
   RED_LED::setOutput();

   static Spi0 spi{};

   // Create two threads
   static MyThread thread1(spi, 10*MHz);
   static MyThread thread2(spi, 1000*kHz);

   // Start the two threads
   thread1.run();
   thread2.run();

   // Report the IDs
   console.write("thread1::getId()  = 0x").writeln(thread1.getId(), Radix_16);
   console.write("thread2::getId()  = 0x").writeln(thread2.getId(), Radix_16);
}

int main() {
   spiExample();

   for(;;) {
      CMSIS::Thread::delay(1000);
      console.writeln("This is the main-line looping");
   }
   return 0;
}

