/*
 * CircularBuffer.h
 *
 *  Created on: 15 Jun 2017
 *      Author: podonoghue
 */

#ifndef SOURCES_CIRCULARBUFFER_H_
#define SOURCES_CIRCULARBUFFER_H_

#include "system.h"

/**
 * Implements a circular buffer with a fence dividing the buffer in to
 * a region that is being updated (added to) and another that is being processed (read).
 *
 * @tparam size      Total size of buffer
 * @tparam reserved  The portion that is writable at any time
 * @tparam T         Type of buffer contents
 */
template<uint32_t size, uint32_t reserved, typename T>
class CircularBuffer {
   static_assert(reserved<size, "The reserved range must be < buffer size");

   T buffer[size];
   T *fence, *tail;
   int freeCount;
   int fullCount;

public:

   /** Amount of data available for processing after initial fill */
   static constexpr int32_t DATA_SIZE = (size-reserved);

   /**
    * Constructor
    */
   CircularBuffer() : fence(buffer), tail(buffer), freeCount(size), fullCount(0) {
   }

   /**
    * Checks if buffer is full
    *
    * @return true  Buffer is full
    * @return false Buffer is not full
    */
   bool isFull() {
      return freeCount == 0;
   }

   /**
    * Checks if working space in the buffer is available
    * This basically means that the buffer is full up to at least the fence.
    *
    * @return true   Working buffer is available\n
    *                Items[0...(size-reserved-1)] are available
    * @return false  Working buffer is not available
    */
   bool workingBufferAvailable() {
      return fullCount>=(size-reserved);
   }

   /**
    * Add item to buffer
    *
    * @note The item is copied to the buffer
    *
    * @param item The item to add
    *
    * @return true  Success, item has been added
    * @return false Failure, the buffer is full
    */
   bool push(T &item) {
      if (isFull()) {
         return false;
      }
      disableInterrupts();
      *tail++ = item;
      if (tail>=(buffer+size)) {
         tail = buffer;
      }
      --freeCount;
      ++fullCount;
      enableInterrupts();
      return true;
   }

   /**
    * Advance the fence by the reserved amount.
    * This discards 'reserved' number of items.
    *
    * @return true Success
    * @return false Failure (Less than 'reserved' items in buffer)
    */
   bool advance() {
      disableInterrupts();
      if (fullCount<reserved) {
         enableInterrupts();
         return false;
      }
      fullCount -= reserved;
      freeCount += reserved;
      fence     += reserved;
      if (fence>=(buffer+size)) {
         fence = buffer;
      }
      enableInterrupts();
      return true;
   }

   /**
    * Get item from buffer\n
    * The index should be less than (size-reserved)\n
    * The buffer should not be accessed unless workingBufferAvailable() returns true.
    *
    * @return Item from buffer
    */
   T operator [](int index) const {
      disableInterrupts();
      const T *p = fence+index;
      if (p>=(buffer+size)) {
         p = buffer;
      }
      enableInterrupts();
      return *p;
   }
};

#endif /* SOURCES_CIRCULARBUFFER_H_ */
