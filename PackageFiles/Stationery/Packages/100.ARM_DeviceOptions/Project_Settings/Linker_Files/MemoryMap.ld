/* MemoryMap.ld (Packages\100.ARM_DeviceOptions\Project_Settings\Linker_Files)
 *
 * Memory map for devices without SRAM_U allocation for bit-band/bme
 */
 
/* ---- <<< Use Configuration Wizard in Context Menu >>> ---- */

/* <o> Stack Size
   <i> Required amount of stack space
   <i> In CMSIS this will determine the ISR stack size
   <0x0-$(linkerRamSize):4> 
*/
__stack_size = $(linkerStackSize);

/* <o> Heap Size 
   <0x0-$(linkerRamSize):4> 
*/
__heap_size  = $(linkerHeapSize);
  
$(linkerInformation)



