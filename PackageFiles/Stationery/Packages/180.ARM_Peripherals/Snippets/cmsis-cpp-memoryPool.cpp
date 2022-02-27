/**
 ============================================================================
 * @file cmsis-cpp-memoryPool.cpp (180.ARM_Peripherals/Snippets)
 * @brief RTX Memory Pool example program
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"                   // Hardware interface
#include "cmsis.h"                      // CMSIS RTX

using namespace USBDM;

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

   console.writeln(" memory pool::getId() = ", pool.getId());

   Data *ar[30] = {0};
   for (unsigned i=0; i<(sizeof(ar)/sizeof(ar[0])); i++) {
      ar[i] = pool.alloc();
      if (ar[i] == nullptr) {
         break;
      }
      else {
         console.writeln(i, ": Allocated ", ar[i]);
      }
      ar[i]->a = i;
      ar[i]->b = i*i;
   }
   for (unsigned i=0; i<(sizeof(ar)/sizeof(ar[0])); i++) {
      if (ar[i] != nullptr) {
         console.writeln(i, ": free ").write(ar[i], " (", ar[i]->a, ",", ar[i]->b, ")");
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

