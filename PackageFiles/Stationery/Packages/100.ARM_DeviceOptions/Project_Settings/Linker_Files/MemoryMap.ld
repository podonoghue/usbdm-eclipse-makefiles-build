/* MemoryMap.ld
 *
 * Memory map for devices without SRAM_U allocation for bit-band/bme
 */
 
/* ---- <<< Use Configuration Wizard in Context Menu >>> ---- */

/* <o> Stack Size
   <i> Required amount of stack space
   <i> In CMSIS this will determine the ISR stack size
   <0x0-$(linkerRamSize)> 
*/
__stack_size = $(linkerStackSize);

/* <o> Minimum Heap Size 
   <i> Actual heap may be larger as it fills all unused RAM up to STACK
   <0x0-$(linkerRamSize)> 
*/
__heap_size  = $(linkerHeapSize);
  
$(linkerInformation)

