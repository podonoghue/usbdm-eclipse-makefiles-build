/* MemoryMap-mk.ld (180.ARM_Peripherals/Project_Settings/Linker_Files/)
 *
 */
 
/* ---- <<< Use Configuration Wizard in Context Menu >>> ---- */

/* <o> Stack Size
   <i> Required amount of stack space
   <i> In CMSIS this will determine the ISR stack size
   <0x0-$(/LINKER/ramSize):4>  <constant>
*/
__stack_size = $(/LINKER/stackSize);

/* <o> Minimum Heap Size 
   <i> This is the minimum allocated.  
   <i> Available heap may be larger.
   <0x0-$(/LINKER/ramSize):4>  <constant>
*/
__heap_size  = $(/LINKER/heapSize);

/* <o0> Bit-band / bit-manipulation-engine RAM size
   <i>  Space is allocated in SRAM_U memory region
   <i>  Each byte as also mapped to 8 words in .bitband memory region (if present)
   <i>
   <i>  C Example:
   <i>    // Variable allocated in bitband/bme accessible region (SRAM_U)
   <i>    // May be uint8_t, uint16_t or uint32_t
   <i>    __attribute__ ((section(".bitband_ram"))) uint32_t variable;
   <i>
   <i>    // Each word of array maps to an individual bit in bit-band
   <i>    __attribute__ ((section(".bitband"))) uint32_t variable_bits[8*sizeof(variable)];
   <i>
   <i>  See bme.h and bitband.h for more information
   <0x0-0x1000:4>  <constant>
*/
__sram_u_size = $(/LINKER/bitbandSize);
   
/*
 <e1> Enable Bootloader
 <i>  Enable custom USBDM bootloader  <constant>
*/
FORCE_BOOT_LOADER = DEFINED(bootloaderInformation) ? 1 : $(/LINKER/enableBootloader);
/*
    <o>  Bootloader size (usually 0x4000 if used) <constant>
    <i>  The bootloader is located at the bottom of the flash region
    <i>  This value is used to automatically adjust the available flash area 
 */
BOOT_LOADER_SIZE  = DEFINED(BOOT_LOADER_SIZE)  ? BOOT_LOADER_SIZE : $(/LINKER/bootloaderSize) * FORCE_BOOT_LOADER;
/*
    <o>  Bootloader information block size (usually 0x10 if used) <constant>
    <i>  The bootloader information block is located at the top of the flash region
    <i>  This value is used to automatically adjust the available flash area 
 */
BOOT_INFO_SIZE    = DEFINED(BOOT_INFO_SIZE)    ? BOOT_INFO_SIZE   : 0x10 * (BOOT_LOADER_SIZE > 0);
/* </e> */

$(/LINKER/information)

/*
  <h> Section placement in Flash
  <i> Some Cortex-M4 Kinetis devices have additional Flash that may be used to hold code or constant data, or 
  <i> as backing storage for non-volatile memory (FlexRAM -> FlexNVM.)
  <i> These settings control which region (regular flash or FlexNVM) is used for various linker sections.
*/
/*  <s1>  Text (main code apart from reset)  <constant> text_rom      */
REGION_ALIAS("text_rom",         "$(/LINKER/text_rom)");
/*  <s1>  Read-only data                     <constant> rodata_rom    */
REGION_ALIAS("rodata_rom",       "$(/LINKER/rodata_rom)");
/*  <s1>  Flash image for initialised data   <constant> data_rom      */
REGION_ALIAS("data_rom",         "$(/LINKER/data_rom)");
/* </h> */
/*
  <h> Section placement in RAM
  <i> The RAM on Cortex-M4 Kinetis devices is divided into upper and lower memory regions.
  <i> These settings control which region is used for various linker sections.
  <i> These sections cannot cross regions as unaligned half-word and long-word accesses are not supported.
*/
/*  <s1>  Stack                              <constant> stack_ram      */
REGION_ALIAS("stack_ram",      "$(/LINKER/stack_ram)");
/*  <s1>  Heap                               <constant> heap_ram       */
REGION_ALIAS("heap_ram",       "$(/LINKER/heap_ram)");
/*  <s1>  Vector table relocated to RAM      <constant> interrupts_ram */
REGION_ALIAS("interrupts_ram", "$(/LINKER/interrupts_ram)");
/*  <s1>  Initialised DATA                   <constant>  data_ram      */
REGION_ALIAS("data_ram",       "$(/LINKER/data_ram)");
/*  <s1>  Zeroed Data (BSS)                  <constant> bss_ram        */
REGION_ALIAS("bss_ram",        "$(/LINKER/bss_ram)");
/*  <s1>  Non-initialised DATA               <constant> noinit_ram     */
REGION_ALIAS("noinit_ram",     "$(/LINKER/noinit_ram)");
/*  <s1>  Micro Trace Buffer                 <constant> mtb_ram        */
REGION_ALIAS("mtb_ram",        "$(/LINKER/mtb_ram)");
/*  <s1>  USB Endpoint buffers               <constant> bdts_ram       */
REGION_ALIAS("bdts_ram",       "$(/LINKER/bdts_ram)");
/*  <s1>  Bitband RAM - must be in ram_high  <constant> bitband_ram       */
REGION_ALIAS("bitband_ram",    "ram_high")
/* </h> */


INCLUDE Linker-rom.ld

