/*
 * heap.c
 *
 *  Created on: 10 May 2019
 *      Author: podonoghue
 */
#include <stdint.h>

#include "FreeRTOSConfig.cfg"

#if   configFRTOS_MEMORY_SCHEME == 1
#include "portable/MemMang/heap_1.c"
#elif configFRTOS_MEMORY_SCHEME == 2
#include "portable/MemMang/heap_2.c"
#elif configFRTOS_MEMORY_SCHEME == 3
#include "portable/MemMang/heap_3.c"
#elif configFRTOS_MEMORY_SCHEME == 4
#include "portable/MemMang/heap_4.c"
#else
#include "portable/MemMang/heap_5.c"
#endif

__attribute__ ((section(".freertos_information")))
const uint8_t freeRTOSMemoryScheme = configFRTOS_MEMORY_SCHEME;

