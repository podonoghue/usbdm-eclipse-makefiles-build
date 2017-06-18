/**
 ============================================================================
 * @file cmsis-cpp-memoryPool.cpp
 * @brief RTX Memory Pool example program
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "cmsis.h"                      // CMSIS RTX
#include "hardware.h"                   // Hardware interface

/*
 * Memory pools example
 *
 * Allocates a frees items in a memory pool
 */
static void memoryPoolExample() {
   struct Data {
      int a;
      int b;
   };

   static CMSIS::Pool<Data, 10> pool;

   printf(" memory pool::getId() = %p\n\r", pool.getId());

   Data *ar[30] = {0};
   for (unsigned i=0; i<(sizeof(ar)/sizeof(ar[0])); i++) {
      ar[i] = pool.alloc();
      if (ar[i] == nullptr) {
         break;
      }
      else {
         printf("%d: Allocated %p\n\r", i, ar[i]);
      }
      ar[i]->a = i;
      ar[i]->b = i*i;
   }
   for (unsigned i=0; i<(sizeof(ar)/sizeof(ar[0])); i++) {
      if (ar[i] != nullptr) {
         printf("%d: free %p (%d, %d)\n\r", i, ar[i], ar[i]->a, ar[i]->b);
         pool.free(ar[i]);
      }
   }
}

int main() {
   memoryPoolExample();

   for(;;) {
   }
   return 0;
}

