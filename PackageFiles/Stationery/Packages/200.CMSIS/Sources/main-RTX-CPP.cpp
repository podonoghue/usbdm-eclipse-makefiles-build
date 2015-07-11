/*----------------------------------------------------------------------------
 *   RTX example program
 *----------------------------------------------------------------------------
 */
#include "cmsis_os.h"                   // CMSIS RTX
#include "derivative.h"                 // Device header
#include "GPIO.h"

osThreadId tid_redThread;               // Thread id of redThread
osThreadId tid_blueThread;              // Thread id of blueThread
osThreadId tid_clockThread;             // Thread id of clockThread

#define MAIN_SIGNAL  (1<<1)
#define CLOCK_SIGNAL (1<<8)

#ifdef MCU_MKL25Z4
#define RED_LED   digitalIO_PTB18
#define GREEN_LED digitalIO_PTB19
#define BLUE_LED  digitalIO_PTD1
#endif
#ifdef MCU_MK20D5
#define RED_LED   digitalIO_PTC3
#define GREEN_LED digitalIO_PTD4
#define BLUE_LED  digitalIO_PTA2
#endif
#ifdef MCU_MK22F51212
#define RED_LED   digitalIO_PTA1
#define GREEN_LED digitalIO_PTA2
#define BLUE_LED  digitalIO_PTD5
#endif
#ifdef MCU_MK64F12
#define RED_LED   digitalIO_PTB22
#define GREEN_LED digitalIO_PTE26
#define BLUE_LED  digitalIO_PTB21
#endif

/*----------------------------------------------------------------------------
     Function that turns on Red LED
 *----------------------------------------------------------------------------*/
void LEDRed_On (void) {
   RED_LED.clear();
   GREEN_LED.set();
   BLUE_LED.set();
}

/*----------------------------------------------------------------------------
     Function that turns on Green LED
 *----------------------------------------------------------------------------*/
void LEDGreen_On (void) {
   RED_LED.set();
   GREEN_LED.clear();
   BLUE_LED.set();
}

/*----------------------------------------------------------------------------
     Function that turns on Blue LED
 *----------------------------------------------------------------------------*/
void LEDBlue_On (void) {
   RED_LED.set();
   GREEN_LED.set();
   BLUE_LED.clear();
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

void led_initialise(void) {
   RED_LED.setDigitalOutput();
   GREEN_LED.setDigitalOutput();
   BLUE_LED.setDigitalOutput();
   RED_LED.set();
   GREEN_LED.set();
   BLUE_LED.set();
}

osThreadDef(redThread,     osPriorityNormal, 1, 0);
osThreadDef(blueThread,    osPriorityNormal, 1, 0);
osThreadDef(threadClock,   osPriorityNormal, 1, 0);

/*----------------------------------------------------------------------------
 *      Main: Initialise and start RTX Kernel
 *---------------------------------------------------------------------------*/
int main (void) {

   led_initialise();

   tid_redThread     = osThreadCreate(osThread(redThread),   NULL);
   tid_blueThread    = osThreadCreate(osThread(blueThread),  NULL);
   tid_clockThread   = osThreadCreate(osThread(threadClock), NULL);

   osSignalSet(tid_redThread, MAIN_SIGNAL);          // set signal to phaseA thread

   osDelay(osWaitForever);
   while(1);
}
