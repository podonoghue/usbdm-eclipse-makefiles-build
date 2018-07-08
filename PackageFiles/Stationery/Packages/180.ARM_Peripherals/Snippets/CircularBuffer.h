/*
 * @file CircularBuffer.h
 *
 *  Created on: 15 Jun 2017
 *      Author: podonoghue
 */

#ifndef SOURCES_CIRCULARBUFFER_H_
#define SOURCES_CIRCULARBUFFER_H_

#include "system.h"

/**
 * Implements a circular buffer with array based access.\n
 * It maintains a base index used to offset the array access.\n
 * The offset may be incremented (in a circular fashion).
 * This is convenient for accessing a window into the filling buffer.
 *
 * @tparam size  Size of buffer
 * @tparam T     Type of buffer contents
 */
template<uint32_t size, typename T>
class CircularBuffer {
   T buffer[size];
   T *base, *tail;
   int freeCount;
   int fullCount;

public:

   /**
    * Constructor
    */
   constexpr CircularBuffer() : base(buffer), tail(buffer), freeCount(size), fullCount(0) {
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
    * Get number of items in buffer
    *
    * @return Count of items
    */
   uint32_t count() {
      return fullCount;
   }

   /**
    * Add item to buffer
    *
    * @note The item is copied to the buffer
    *
    * @param[in] item The item to add
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
    * Advance the base by the given amount.
    * This discards that number of items from the start of the buffer.
    * The array access now start at the advanced index.
    *
    * @param[in] increment The amount to advance the base by.
    *
    * @return true  Success
    * @return false Failure (Less than 'increment' items in buffer)
    */
   bool advance(uint32_t increment) {
      disableInterrupts();
      if (fullCount<increment) {
         enableInterrupts();
         return false;
      }
      fullCount -= increment;
      freeCount += increment;
      base      += increment;
      if (base>=(buffer+size)) {
         base = buffer;
      }
      enableInterrupts();
      return true;
   }

   /**
    * Get item from buffer\n
    * The index is relative to the current base.
    *
    * @param[in] index Index of item to retrieve
    *
    * @return Item from buffer
    */
   T operator [](int index) const {
      disableInterrupts();
      const T *p = base+index;
      if (p>=(buffer+size)) {
         p = buffer;
      }
      enableInterrupts();
      return *p;
   }
};

#endif /* SOURCES_CIRCULARBUFFER_H_ */
