/* ARMLtd_GCC-rom-mk.ld (180.ARM_Peripherals/Project_Settings/Linker_Files/)
 *
 * Kinetis version with bitband
 *
 * Linker script based on example scripts provided with ARM Ltd GCC
 *
 * It references the following symbols, which must be defined in code:
 * 
 *      Reset_Handler : Entry of reset handler
 * 
 * 
 * It defines the following symbols, which code can use without definition:
 *      __exidx_start
 *      __exidx_end
 *      __etext
 *      __preinit_array_start
 *      __preinit_array_end
 *      __init_array_start
 *      __init_array_end
 *      __fini_array_start
 *      __fini_array_end
 *      __data_start__
 *      __data_end__
 *      __bss_start__
 *      __bss_end__
 *      __end__
 *      end
 *      __HeapBase
 *      __HeapLimit
 *      __StackLimit
 *      __StackTop
 *      __stack
 */
 
OUTPUT_FORMAT ("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
SEARCH_DIR(.)

ENTRY(Reset_Handler)

PROVIDE(__stack_size__ = __stack_size);
PROVIDE(__heap_size__  = __heap_size);

PROVIDE(__HardReset = Reset_Handler);

/* Needed for -nostartfiles linker option call main directly */
PROVIDE(_start = main);

SECTIONS
{
   .interrupts :
   {
      __flash_start = .;

      /* Vector table */
      __VECTOR_TABLE = .;
      KEEP(*(.interrupt_vectors))
      KEEP(*(.isr_vector))         /* KDS vector table */
      /* Make sure we pulled in at least a reset vector.  */
      ASSERT (. != __flash_start, "No reset vector found");
      __VECTOR_TABLE_END = .;
      
      /* Emit a Freescale Bootloader configuration @0x3C0 if present */
      . = __flash_start + 0x3C0;
      KEEP(*(.bootloader_configuration))
      
      /* Emit USBDM Bootloader information @0x3C0 if present */
      __bootloaderInformation = .;
      KEEP(*(.bootloaderInformation))
      ASSERT ((BOOT_LOADER_SIZE == 0) || (. != __bootloaderInformation), "No bootloader information");

      /* Emit a Security field */
      . = __flash_start + 0x400;
      KEEP(*(.security_information))
      ASSERT (. == __flash_start + 0x410, "No Freescale security information");
      KEEP(*(.FlashConfig))    /* KDS Flash Configuration Field (FCF) */
      KEEP(*(.freertos_information))
   } > flash

/* Size of RAM vector table (if needed) */
M_VECTOR_RAM_SIZE = DEFINED(__ram_vector_table__) ? (__VECTOR_TABLE_END - __VECTOR_TABLE) : 0x0000;

   .text :
   {
      *(.text)                 /* .text sections (code) */
      *(.text*)                /* .text* sections (code) */
      KEEP(*(.init))
      KEEP(*(.fini))

      /* .ctors */
      __CTOR_LIST__ = .;
      KEEP (*crtbegin.o(.ctors))
      KEEP (*crtbegin?.o(.ctors))
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors))
      KEEP (*(SORT(.ctors.*)))
      KEEP (*(.ctors))
      __CTOR_END__ = .;

      /* .dtors */
      __DTOR_LIST__ = .;
      KEEP (*crtbegin.o(.dtors))
      KEEP (*crtbegin?.o(.dtors))
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))
      KEEP (*(SORT(.dtors.*)))
      KEEP (*(.dtors))
      __DTOR_END__ = .;
      . = ALIGN(4);
      /* preinit data */
      PROVIDE_HIDDEN (__preinit_array_start = .);
      KEEP(*(.preinit_array*))
      PROVIDE_HIDDEN (__preinit_array_end = .);

      . = ALIGN(4);
      /* init data */
      PROVIDE_HIDDEN (__init_array_start = .);
      KEEP(*(SORT(.init_array.*)))
      KEEP(*(.init_array*))
      PROVIDE_HIDDEN (__init_array_end = .);

      . = ALIGN(4);
      /* finit data */
      PROVIDE_HIDDEN (__fini_array_start = .);
      KEEP(*(SORT(.fini_array.*)))
      KEEP(*(.fini_array*))
      PROVIDE_HIDDEN (__fini_array_end = .);

      KEEP(*(.jcr*))

      KEEP(*(.eh_frame*))
   } > text_rom

   .rodata :
   {
      *(.rodata)               /* .rodata sections (constants, strings, etc.) */
      *(.rodata*)              /* .rodata* sections (constants, strings, etc.) */
   } > rodata_rom
   
   .ARM.extab : 
   {
      *(.ARM.extab* .gnu.linkonce.armextab.*)
   } > rodata_rom

   __exidx_start = .;
   .ARM.exidx :
   {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
   } > rodata_rom
   __exidx_end = .;

   /* Flash region for programming */
   .flash (NOLOAD) : 
   {
      . = ALIGN(4);
      KEEP(*(.flash))
   } > rodata_rom

   __etext = .;     /* Symbol for .data image at end of .rodata */
   __DATA_ROM = .;  /* Symbol is used by startup for data initialization */

  /* reserve MTB memory at the beginning of data */
  .mtb : /* MTB buffer no0load */
  {
    . = ALIGN(8);
    _mtb_start = .;
    KEEP(*(.mtb_buf)) /* May not be referenced by application */
    . = ALIGN(8);
    _mtb_end = .;
  } > mtb_ram

  .interrupts_ram :
  {
    . = ALIGN(4);
    __VECTOR_RAM__ = .;
    __interrupts_ram_start__ = .;
    *(.m_interrupts_ram)     
    . += M_VECTOR_RAM_SIZE;
    . = ALIGN(4);
    __interrupts_ram_end__ = .; 
  } > interrupts_ram

  __VECTOR_RAM = DEFINED(__ram_vector_table__) ? __VECTOR_RAM__ : __VECTOR_TABLE;
  __RAM_VECTOR_TABLE_SIZE_BYTES = __interrupts_ram_end__ - __interrupts_ram_start__;
  
   .bdts :
   {
      *(.bss*endPointBdts*) /* Load USB BDTs here as they are aligned */
   } > bdts_ram
  
   /* Initialised data in RAM copied from flash */
   .data : 
   {
      __data_start__ = .;
      __DATA_RAM = .;
      *(vtable)
      *(.data*)

      . = ALIGN(4);
      KEEP(*(.ram_functions))
      . = ALIGN(4);
      /* All data end */
      __data_end__ = .;
   } > data_ram AT> data_rom
   
  /* KDS defines __DATA_END as the end of DATA in Flash */
  __DATA_END = __DATA_ROM + SIZEOF(.data);
  __data_image_start__ = LOADADDR(.data);
  
   /* Start of not initialised region */
   .noinit :
   {
      . = ALIGN(4);
      *(.noinit)
   } > noinit_ram
   
   /* Start of BSS */
   .bss :
   {
      . = ALIGN(4);
      __START_BSS = .;
      __bss_start__ = .;
      *(.bss)
      *(.bss*)
      *(COMMON)
      . = ALIGN(4);
      __bss_end__ = .;
      __END_BSS = .;
   } > bss_ram
    
   /* Start of HEAP - usually from top of BSS */
   .heap :
   {
      . = ALIGN(4);
      PROVIDE ( __end__ = . );
      PROVIDE ( end = . );
      PROVIDE ( _end = . );
      __HeapBase = .;
      __heap_addr = .;
      . = . + __heap_size__;
      /* Heap limit is at Top of ram_low or bottom of stack */
      __HeapLimit = MIN( ABSOLUTE(ORIGIN(heap_ram)+LENGTH(heap_ram)-1), __StackLimit);
   } > heap_ram

   /* STACK space - between HEAP and end of RAM (or bitband_bytes) */
   PROVIDE ( __sram_u_size = 0 );
   .stack :
   {
      /* Make sure location doesn't move backwards as causes cryptic messages */
      . = MAX( ., ABSOLUTE(ORIGIN(stack_ram) + LENGTH(stack_ram) - __stack_size__ - __sram_u_size - 3));
      . = ALIGN(4);
      __StackLimit = .;
      . = . + __stack_size__;
      __StackTop = .;
   } > stack_ram

   /* 
    * Bitband region
    *
    * This area is partitioned from the top of SRAM
    *
    * Each bit in this region maps to a word in the .bitband region (if present)
    * This region is also accessible to BME (if present and supports RAM access) 
    */
   .bitband_ram (NOLOAD) :
   {
   __start_bitband = .;
      *(.bitband_ram)
   } > bitband_ram

   /*
    * Bitband region
    *
    * Each word in this region maps to a bit in the .bitband_ram region 
    */
   .bitband (NOLOAD) :
   {
      /* Allocate variables with an offset scaled from bitband_ram offset */
      . = ORIGIN(bitband) + 32*(ABSOLUTE(__start_bitband) - ABSOLUTE(ORIGIN(bitband_ram)));
      *(.bitband)
   } > bitband
    
  PROVIDE(__stack = __StackTop);
  PROVIDE(__cs3_stack = __StackTop);
  
  $(/LINKER/extraRegions:)
  /*
   * These are very 'weak' to ensure semi-hosting version 
   * will be used for rdimon.specs option
   */
  PROVIDE(_write = _usbdm_write);
  PROVIDE(_read  = _usbdm_read);

  /*
   Typcal RAM Memory map                                     Example
  +----------------------+                                   0x1FFFFF00
  | Micro Trace Buffer   |
  | (if declared)        |
  +----------------------+ __interrupts_ram_start__          0x1FFFFF00+???
  | RAM vector table     |
  | (if declared)        |
  +----------------------+ __data_start__                    0x1FFFFF00+???
  | DATA                 |
  |                      |
  +----------------------+ __data_end__ = __bss_start__      0x1FFFFF68
  | BSS                  |
  |                      |
  +----------------------+ __bss_end__ = __HeapBase          0x1FFFFF84
  | Heap                 |
  | (__heap_size__)      |  (minimum heap)                   (size=0x120)
  +----------------------+                                   0x200000A4
  |//////////////////////|
  |----------------------| <-- RAM Lower/Upper boundary
  |//////////////////////|
  +----------------------+ __HeapLimit = __StackLimit        0x200001fc
  | Stack                |
  | (__stack_size__)     |                                   (size=0x100)
  +----------------------+ __StackTop                        0x200002ff
  | Bitband/BME (sram_u) |                                   (if present)
  | (__sram_u_size)      |                                   (size=1)
  +----------------------+                                   0x20000300
  
  */
}
