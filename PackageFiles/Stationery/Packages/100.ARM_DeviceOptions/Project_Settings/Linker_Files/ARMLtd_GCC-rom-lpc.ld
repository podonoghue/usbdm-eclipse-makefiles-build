/* ARMLtd_GCC-rom-lpc.ld (Packages\100.ARM_DeviceOptions\Project_Settings\Linker_Files)`
 *
 * LPC version without SRAM_U allocation or bitband
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
 *      __data_start__
 *      __preinit_array_start
 *      __preinit_array_end
 *      __init_array_start
 *      __init_array_end
 *      __fini_array_start
 *      __fini_array_end
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

/* Include external memory map defining ram and Flash memory etc */
INCLUDE "MemoryMap.ld"

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
      /* Make sure we pulled in at least a reset vector.  */
      ASSERT (. != __flash_start, "No reset vector found");
      __VECTOR_TABLE_END = .;

      /* Emit a Security field */
      . = __flash_start + 0x2FC;
      KEEP(*(.security_information))/* LPC Code Read Protection (CRP) */
      ASSERT (. == __flash_start + 0x300, "No LPC CRP security information");
    } > flash

/* Size of RAM vector table (if needed) */
M_VECTOR_RAM_SIZE = DEFINED(__ram_vector_table__) ? (__VECTOR_TABLE_END - __VECTOR_TABLE) : 0x0000;

   .text :
   {
      *(.text)                 /* .text sections (code) */
      *(.text*)                /* .text* sections (code) */
      *(.rodata)               /* .rodata sections (constants, strings, etc.) */
      *(.rodata*)              /* .rodata* sections (constants, strings, etc.) */
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

      *(.rodata*)

      KEEP(*(.eh_frame*))
    } > flash

   .ARM.extab : 
   {
      *(.ARM.extab* .gnu.linkonce.armextab.*)
   } > flash

   __exidx_start = .;
   .ARM.exidx :
   {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
   } > flash
   __exidx_end = .;

   __etext = .;    /* define a global symbol at end of code */
   __DATA_ROM = .; /* Symbol is used by startup for data initialization */

   /* Flash region for programming */
   .flash (NOLOAD) : 
   {
      . = ALIGN(4);
      KEEP(*(.flash))
   } > flash

  /* reserve MTB memory at the beginning of data */
  .mtb : /* MTB buffer no0load */
  {
    . = ALIGN(8);
    _mtb_start = .;
    KEEP(*(.mtb_buf)) /* May not referenced by application */
    . = ALIGN(8);
    _mtb_end = .;
  } > ram

  .interrupts_ram :
  {
    . = ALIGN(4);
    __VECTOR_RAM__ = .;
    __interrupts_ram_start__ = .;
    *(.m_interrupts_ram)     
    . += M_VECTOR_RAM_SIZE;
    . = ALIGN(4);
    __interrupts_ram_end__ = .; 
  } > ram

  __VECTOR_RAM = DEFINED(__ram_vector_table__) ? __VECTOR_RAM__ : __VECTOR_TABLE;
  __RAM_VECTOR_TABLE_SIZE_BYTES = __interrupts_ram_end__ - __interrupts_ram_start__;
  
   .data : AT (__etext)
   {
      __data_start__ = .;
      __DATA_RAM = .;
      *(vtable)
      *(.data*)

      . = ALIGN(4);
      /* All data end */
      __data_end__ = .;
   } > ram
   
  /* KDS defines __DATA_END as the end of DATA in Flash */
  __DATA_END = __DATA_ROM + SIZEOF(.data);

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
   } > ram
    
   /* Minimum HEAP - from top of BSS */
   .heap :
   {
      . = ALIGN(4);
      PROVIDE ( __end__ = . );
      PROVIDE ( end = . );
      PROVIDE ( _end = . );
      __HeapBase = .;
      __heap_addr = .;
      . = . + __heap_size__;
   } > ram

$(linkerExtraRegions:)
   /* STACK space - between HEAP and end of RAM (or bitband_bytes) */
   .stack :
   {
      /* Make sure location doesn't move backwards as causes cryptic messages */
      . = MAX( ., ABSOLUTE(ORIGIN(ram) + LENGTH(ram) - __stack_size - 3));
      . = ALIGN(4);
      __HeapLimit = .;
      __StackLimit = .;
      . = . + __stack_size__;
      __StackTop = .;
   } > ram

  PROVIDE(__stack = __StackTop);
  PROVIDE(__cs3_stack = __StackTop);
  
  /*
   * These are very 'weak' to ensure semi-hosting version 
   * will be used for rdimon.specs option
   */
  PROVIDE(_write = _usbdm_write);
  PROVIDE(_read  = _usbdm_read);

  /*
   RAM Memory map                                            Example
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
  +----------------------+ __HeapLimit = __StackLimit        0x200001fc
  | Stack                |
  | (__stack_size__)     |                                   (size=0x100)
  +----------------------+ __StackTop                        0x200002ff
  
  */
}
