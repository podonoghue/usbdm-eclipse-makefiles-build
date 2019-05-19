/* MemoryMap-mk.ld (Packages\100.ARM_DeviceOptions\Project_Settings\Linker_Files)
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

/* <o> Minimum Heap Size 
   <i> This is the minimum allocated.  
   <i> Available heap may be larger.
   <0x0-$(linkerRamSize):4> 
*/
__heap_size  = $(linkerHeapSize);
  
$(linkerInformation)

/*
  <h> Section placement in RAM
  <i> The RAM on Cortex-M4 Kinetis devices is divided into upper and lower memory regions.
  <i> These settings control which region is used for various linker sections.
*/
/*  <s1>  Micro Trace Buffer                <"ram_low"=> ram_low <"ram_high"=> ram_high <i> mtb_ram        */
REGION_ALIAS("mtb_ram", 	   "ram_low");
/*  <s1>  Vector table relocated to RAM     <"ram_low"=> ram_low <"ram_high"=> ram_high <i> interrupts_ram */
REGION_ALIAS("interrupts_ram", "ram_low");
/*  <s1>  USB Endpoint buffers              <"ram_low"=> ram_low <"ram_high"=> ram_high <i> bdts_ram       */
REGION_ALIAS("bdts_ram",       "ram_low");
/*  <s1>  DATA                              <"ram_low"=> ram_low <"ram_high"=> ram_high <i> data_ram       */
REGION_ALIAS("data_ram",       "ram_low");
/*  <s1>  BSS                               <"ram_low"=> ram_low <"ram_high"=> ram_high <i> bss_ram        */
REGION_ALIAS("bss_ram",        "ram_low");
/*  <s1>  HEAP                              <"ram_low"=> ram_low <"ram_high"=> ram_high <i> heap_ram       */
REGION_ALIAS("heap_ram",       "ram_low");
/*  <s1>  STACK                             <"ram_low"=> ram_low <"ram_high"=> ram_high <i> stack_ram      */
REGION_ALIAS("stack_ram",      "ram_high");
/* </h> */

/* These must be in upper RAM */
REGION_ALIAS("sram_u_ram",     "ram_high");
REGION_ALIAS("bitband_ram",    "ram_high");


