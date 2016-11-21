/*
 * queue.h
 *
 *  Created on: 12Nov.,2016
 *      Author: podonoghue
 */

#ifndef PROJECT_HEADERS_QUEUE_H_
#define PROJECT_HEADERS_QUEUE_H_

#include <assert.h>

/**
 * Simple queue implementation
 *
 * @tparam QUEUE_SIZE Size of queue
 */
template<int QUEUE_SIZE>
class Queue {
   uint8_t fBuff[QUEUE_SIZE];
   uint8_t *fHead, *fTail;
   int fNumberOfElements;

public:
   /*
    * Create empty Queue
    */
   Queue() : fHead(fBuff), fTail(fBuff), fNumberOfElements(0) {
   }

   /*
    * Check if empty
    *
    * @return true => empty
    */
   bool isEmpty() {
      return fNumberOfElements == 0;
   }
   /*
    * Check if full
    *
    * @return true => full
    */
   bool isFull() {
      return fNumberOfElements == QUEUE_SIZE;
   }
   /*
    * Add element to queue
    *
    * @param element Element to add
    */
   void enQueue(uint8_t element) {
      assert(!isFull());
      *fTail++ = element;
      fNumberOfElements++;
      if (fTail>=(fBuff+QUEUE_SIZE)) {
         fTail = fBuff;
      }
   }
   /*
    * Remove & return element from queue
    *
    * @param element Element to add
    */
   uint8_t deQueue() {
      assert(!isEmpty());
      uint8_t t = *fHead++;
      fNumberOfElements--;
      if (fHead>=(fBuff+QUEUE_SIZE)) {
         fHead = fBuff;
      }
      return t;
   }

};

#endif /* PROJECT_HEADERS_QUEUE_H_ */
