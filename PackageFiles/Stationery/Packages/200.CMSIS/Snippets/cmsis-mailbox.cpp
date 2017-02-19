/*----------------------------------------------------------------------------
 * RTX example program - Mailbox
 *
 * Based on examples at https://developer.mbed.org/handbook/CMSIS-RTOS
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

#include "cmsis_os.h"                   // CMSIS RTX
#include "hardware.h"                   // Hardware interface


// Directly access USBDM routines
using namespace USBDM;

typedef struct {
  float    voltage; /* AD result of measured voltage */
  float    current; /* AD result of measured current */
  uint32_t counter; /* A counter value               */
} mail_t;

osMailQDef(mail_box, 16, mail_t);
osMailQId  mail_box;

void send_thread (void const *) {
    uint32_t i = 0;
    while (true) {
        i++; // fake data update
        mail_t *mail = (mail_t*)osMailAlloc(mail_box, osWaitForever);
        mail->voltage = (i * 0.1) * 33;
        mail->current = (i * 0.1) * 11;
        mail->counter = i;
        osMailPut(mail_box, mail);
        osDelay(1000);
    }
}

osThreadDef(send_thread, osPriorityNormal, 1, 0);

int main (void) {
    mail_box = osMailCreate(osMailQ(mail_box), NULL);
    osThreadCreate(osThread(send_thread), NULL);

    while (true) {
        osEvent evt = osMailGet(mail_box, osWaitForever);
        if (evt.status == osEventMail) {
            mail_t *mail = (mail_t*)evt.value.p;
            printf("\nVoltage: %.2f V\n\r"    , mail->voltage);
            printf("Current: %.2f A\n\r"      , mail->current);
            printf("Number of cycles: %lu\n\r", mail->counter);

            osMailFree(mail_box, mail);
        }
    }
}
