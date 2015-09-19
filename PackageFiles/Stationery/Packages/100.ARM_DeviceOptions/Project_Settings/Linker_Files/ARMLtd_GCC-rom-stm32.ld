/* ARMLtd_GCC-rom-stm32.ld 
 *
 * STM32 version without SRAM_U allocation or bitband
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
SEARCH_DIR(../Standard_Peripheral_Library)
SEARCH_DIR(../Project_Settings)

/* Standard Peripheral Library
 
Use the appropriate library file in the GROUP statement according to chip in use 

libstm32_CL.a
libstm32_HD.a
libstm32_HD_VL.a
libstm32_LD.a
libstm32_LD_VL.a
libstm32_MD.a
libstm32_MD_VL.a
libstm32_XL.a

GROUP(libstm32_MD.a)
*/

/* Include external memory map defining ram and Flash memory etc */
INCLUDE "MemoryMap-$(targetDeviceName).ld"

ENTRY(Reset_Handler)

PROVIDE(__stack_size__ = __stack_size);
PROVIDE(__heap_size__  = __heap_size);

PROVIDE(__HardReset = Reset_Handler);

/* Needed for -nostartfiles linker option call main directly */
PROVIDE(_start = main);

SECTIONS
{
   .text :
   {
      __flash_start = .;

      /* Vector table */
      KEEP(*(.interrupt_vectors))
      /* Make sure we pulled in at least a reset vector.  */
      ASSERT (. != __flash_start, "No interrupt vector");


      *(.text*)

      KEEP(*(.init))
      KEEP(*(.fini))

      /* .ctors */
      *crtbegin.o(.ctors)
      *crtbegin?.o(.ctors)
      *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
      *(SORT(.ctors.*))
      *(.ctors)

      /* .dtors */
      *crtbegin.o(.dtors)
      *crtbegin?.o(.dtors)
      *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
      *(SORT(.dtors.*))
      *(.dtors)

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
    } > rom

   .ARM.extab : 
   {
      *(.ARM.extab* .gnu.linkonce.armextab.*)
   } > rom

   __exidx_start = .;
   .ARM.exidx :
   {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
   } > rom
   __exidx_end = .;

   __etext = .;    /* define a global symbol at end of code */
   __DATA_ROM = .; /* Symbol is used by startup for data initialization */

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
  +----------------------+ __data_start__                    0x1FFFFF00
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
