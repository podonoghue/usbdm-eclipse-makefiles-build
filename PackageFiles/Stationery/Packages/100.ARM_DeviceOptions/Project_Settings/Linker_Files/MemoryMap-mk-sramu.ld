/* MemoryMap-mk-sramu.ld (Packages\100.ARM_DeviceOptions\Project_Settings\Linker_Files)
 *
 * Memory map for devices with SRAM_U allocation for bit-band/bme
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

/* <o0> Size of RAM region reserved for bit-band or bit-manipulation-engine (bytes) 
   <i>  Space is allocated in SRAM_U memory region
   <i>  Each byte as also mapped to 8 words in .bitband memory region (if present)
   <i>
   <i>  C Example:
   <i>    // Variable allocated in bitband/bme accessible region (SRAM_U)
   <i>    // May be uint8_t, uint16_t or uint32_t
   <i>    __attribute__ ((section(".sram_u"))) uint32_t variable;
   <i>
   <i>    // Each word of array maps to an individual bit in bit-band
   <i>    __attribute__ ((section(".bitband"))) uint32_t variable_bits[8*sizeof(variable)];
   <i>
   <i>  See bme.h and bitband.h for more information
   <0x0-0x1000:4> 
*/
__sram_u_size = 0;
   
/*
 <e1> Enable Bootloader
 <i>  Enable custom USBDM bootloader
*/
FORCE_BOOT_LOADER = DEFINED(bootInformation) ? 1 : 0;
/*
    <o>  Bootloader size (usually 0x4000 if used) <constant>
    <i>  The bootloader is located at the bottom of the flash region
    <i>  This value is used to automatically adjust the available flash area 
 */
BOOT_LOADER_SIZE  = DEFINED(BOOT_LOADER_SIZE)  ? BOOT_LOADER_SIZE : 0x4000 * FORCE_BOOT_LOADER;
/*
    <o>  Bootloader information block size (usually 0x10 if used) <constant>
    <i>  The bootloader information block is located at the top of the flash region
    <i>  This value is used to automatically adjust the available flash area 
 */
BOOT_INFO_SIZE    = DEFINED(BOOT_INFO_SIZE)    ? BOOT_INFO_SIZE   : 0x10 * (BOOT_LOADER_SIZE > 0);
/* </e> */

$(linkerInformation)

/*
  <h> Section placement in RAM
  <i> The RAM on Cortex-M4 Kinetis devices is divided into upper and lower memory regions.
  <i> These settings control which region is used for various linker sections.
  <i> These sections cannot cross regions as unaligned half-word and long-word accesses are not supported.
*/
/*  <s1>  Micro Trace Buffer                <"ram_low"=> ram_low <"ram_high"=> ram_high <i> mtb_ram        */
REGION_ALIAS("mtb_ram", 	   "ram_low");
/*  <s1>  Vector table relocated to RAM     <"ram_low"=> ram_low <"ram_high"=> ram_high <i> interrupts_ram */
REGION_ALIAS("interrupts_ram", "ram_low");
/*  <s1>  USB Endpoint buffers              <"ram_low"=> ram_low <"ram_high"=> ram_high <i> bdts_ram       */
REGION_ALIAS("bdts_ram",       "ram_low");
/*  <s1>  Initialised DATA                  <"ram_low"=> ram_low <"ram_high"=> ram_high <i> data_ram       */
REGION_ALIAS("data_ram",       "ram_low");
/*  <s1>  Non-initialised DATA              <"ram_low"=> ram_low <"ram_high"=> ram_high <i> noinit_ram     */
REGION_ALIAS("noinit_ram",     "ram_low");
/*  <s1>  Zeroed Data (BSS)                 <"ram_low"=> ram_low <"ram_high"=> ram_high <i> bss_ram        */
REGION_ALIAS("bss_ram",        "ram_low");
/*  <s1>  Heap                              <"ram_low"=> ram_low <"ram_high"=> ram_high <i> heap_ram       */
REGION_ALIAS("heap_ram",       "ram_low");
/*  <s1>  Stack                             <"ram_low"=> ram_low <"ram_high"=> ram_high <i> stack_ram      */
REGION_ALIAS("stack_ram",      "ram_high");
/* </h> */

/* These must be in upper RAM */
REGION_ALIAS("sram_u_ram",     "ram_high");
REGION_ALIAS("bitband_ram",    "ram_high");

INCLUDE Linker-rom.ld

