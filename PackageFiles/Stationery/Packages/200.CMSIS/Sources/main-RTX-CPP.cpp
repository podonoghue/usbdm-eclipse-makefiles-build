/*----------------------------------------------------------------------------
 * @file main.cpp (derived from main-RTX-CPP.c) 
 *  
 * RTX example program
 *----------------------------------------------------------------------------
 */
#include "cmsis_os.h"                   // CMSIS RTX
#include "derivative.h"                 // Device header
#include "gpio.h"

osThreadId tid_redThread;               // Thread id of redThread
osThreadId tid_blueThread;              // Thread id of blueThread
osThreadId tid_clockThread;             // Thread id of clockThread
osThreadId tid_lcdThread;               // Thread id of lcdThread

#define MAIN_SIGNAL  (1<<1)
#define CLOCK_SIGNAL (1<<8)

#define RED_LED   USBDM::gpio_$(demo.cpp.red.led)
#define GREEN_LED USBDM::gpio_$(demo.cpp.green.led)
#define BLUE_LED  USBDM::gpio_$(demo.cpp.blue.led)

/*----------------------------------------------------------------------------
     Function that turns on Red LED
 *----------------------------------------------------------------------------*/
void LEDRed_On (void) {
   RED_LED::clear();
   GREEN_LED::set();
   BLUE_LED::set();
}

/*----------------------------------------------------------------------------
     Function that turns on Green LED
 *----------------------------------------------------------------------------*/
void LEDGreen_On (void) {
   RED_LED::set();
   GREEN_LED::clear();
   BLUE_LED::set();
}

/*----------------------------------------------------------------------------
     Function that turns on Blue LED
 *----------------------------------------------------------------------------*/
void LEDBlue_On (void) {
   RED_LED::set();
   GREEN_LED::set();
   BLUE_LED::clear();
}

/*----------------------------------------------------------------------------
 *   Clock thread
 *---------------------------------------------------------------------------*/
void threadClock (void const *argument __attribute__((unused))) {
   for (;;) {
      osSignalWait(CLOCK_SIGNAL, osWaitForever);   // Wait until signalled
      LEDGreen_On();
   }
}

/*----------------------------------------------------------------------------
 *    Function thread
 *---------------------------------------------------------------------------*/
void signal_func (osThreadId tid)  {
   osDelay(1000);                                  // delay 1000ms
   osSignalSet(tid_clockThread, CLOCK_SIGNAL);     // set signal to clock thread
   osDelay(1000);                                  // delay 50ms
   osSignalSet(tid, MAIN_SIGNAL);                  // set signal to thread 'tid'
}

/*----------------------------------------------------------------------------
 *    Read thread
 *---------------------------------------------------------------------------*/
void redThread (void const *argument __attribute__((unused))) {
   for (;;) {
      osSignalWait(MAIN_SIGNAL, osWaitForever);    // Wait for event
      LEDRed_On();                                 // Turn on LED
      signal_func(tid_blueThread);                 // Call common signal function
   }
}

/*----------------------------------------------------------------------------
 *    Blue thread
 *---------------------------------------------------------------------------*/
void blueThread (void const *argument __attribute__((unused))) {
   for (;;) {
      osSignalWait(MAIN_SIGNAL, osWaitForever);    // Wait for event
      LEDBlue_On();                                // Turn on LED
      signal_func(tid_redThread);                  // Call common signal function
   }
}

/*----------------------------------------------------------------------------
 *    LCD thread
 *---------------------------------------------------------------------------*/
#ifdef LCD_AVAILABLE
#include "LCD.h"
#include "SPI.h"

void lcdThread (void const *argument __attribute__((unused))) {
   // Instantiate interface
   SPI *spi = new $(demo.cpp.lcd.spi)();
   spi->setSpeed(1000000);
   LCD *lcd = new LCD(spi);

   for (;;) {
      lcd->clear(RED);
      lcd->drawCircle(65, 65, 20, WHITE);
      lcd->drawCircle(65, 65, 30, WHITE);
      lcd->drawCircle(65, 65, 40, WHITE);
      lcd->putStr("Some Circles", 30, 10, Fonts::FontSmall, WHITE, RED);
      osDelay(1000);
   }
}
#endif

void led_initialise(void) {
   RED_LED::setOutput();
   GREEN_LED::setOutput();
   BLUE_LED::setOutput();
   RED_LED::set();
   GREEN_LED::set();
   BLUE_LED::set();
}

osThreadDef(redThread,     osPriorityNormal, 1, 0);
osThreadDef(blueThread,    osPriorityNormal, 1, 0);
osThreadDef(threadClock,   osPriorityNormal, 1, 0);
#ifdef LCD_AVAILABLE
osThreadDef(lcdThread,     osPriorityNormal, 1, 0);
#endif

/*----------------------------------------------------------------------------
 *      Main: Initialise and start RTX Kernel
 *---------------------------------------------------------------------------*/
int main (void) {

   led_initialise();

   tid_redThread     = osThreadCreate(osThread(redThread),   NULL);
   tid_blueThread    = osThreadCreate(osThread(blueThread),  NULL);
   tid_clockThread   = osThreadCreate(osThread(threadClock), NULL);
#ifdef LCD_AVAILABLE
   tid_lcdThread     = osThreadCreate(osThread(lcdThread),   NULL);
#endif

   osSignalSet(tid_redThread, MAIN_SIGNAL);          // set signal to phaseA thread

   osDelay(osWaitForever);

   while(1);
}
