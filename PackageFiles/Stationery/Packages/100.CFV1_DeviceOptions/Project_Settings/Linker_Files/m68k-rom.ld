OUTPUT_ARCH(m68k)
ENTRY(__HardReset)
SEARCH_DIR(.)
GROUP(-lc -lunhosted -lcf)
__DYNAMIC  =  0;

/* Include external memory map defining ram and Flash memory etc */
INCLUDE "MemoryMap-$(targetDeviceName).ld"

SECTIONS
{
  .text :
  {
	__flash_start = .;
	
	/* Vector table */
	KEEP(*(.interrupt_vectors))
	/* Make sure we pulled in at least a reset vector.  */
	ASSERT (. != __flash_start, "No interrupt vector");

	/* Emit a Security field */
	. = __flash_start + 0x400;
	KEEP(*(.security_information))
	ASSERT (. == __flash_start + 0x410, "No security information");

    *(.text .text.*)
    *(.gnu.linkonce.t.*)
	
		KEEP(*(.init))
		KEEP(*(.fini))
		
    . = ALIGN(0x4);
    /*
     * Constructors
     */
    __CTOR_LIST__ = .;
    KEEP (*crtbegin.o(.ctors))
    KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*crtend.o(.ctors))
    /*
     * Destructors
     */
    __DTOR_LIST__ = .;
    KEEP (*crtbegin.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*crtend.o(.dtors))

    . = ALIGN(0x4);
    KEEP (*crtbegin.o(.jcr))
    KEEP (*(EXCLUDE_FILE (*crtend.o) .jcr))
    KEEP (*crtend.o(.jcr))

    *(.rodata .rodata.*)
    *(.gnu.linkonce.r.*)

    . = ALIGN(0x4);
    *(.gcc_except_table) 

    . = ALIGN(0x4);
    *(.eh_frame)

	. = ALIGN(4);
	/* preinit data */
	PROVIDE_HIDDEN (__preinit_array_start = .);
	KEEP(*(.preinit_array))
	PROVIDE_HIDDEN (__preinit_array_end = .);

	. = ALIGN(4);
	/* init data */
	PROVIDE_HIDDEN (__init_array_start = .);
	KEEP(*(SORT(.init_array.*)))
	KEEP(*(.init_array))
	PROVIDE_HIDDEN (__init_array_end = .);

	. = ALIGN(4);
	/* finit data */
	PROVIDE_HIDDEN (__fini_array_start = .);
	KEEP(*(SORT(.fini_array.*)))
	KEEP(*(.fini_array))
	PROVIDE_HIDDEN (__fini_array_end = .);

    . = ALIGN(0x4);
    _init = . ;
    LONG (0x4e560000)	/* linkw %fp,#0 */
    *(.init)
    SHORT (0x4e5e)		/* unlk %fp */
    SHORT (0x4e75)		/* rts */

    . = ALIGN(0x4);
    _fini = . ;
    LONG (0x4e560000)	/* linkw %fp,#0 */
    *(.fini)
    SHORT (0x4e5e)		/* unlk %fp */
    SHORT (0x4e75)		/* rts */

    *(.lit)

    . = ALIGN(4);
    _etext = .;
  } >rom

  .data :
  {
    __data_load = LOADADDR (.data);
    __data_start = .;
    *(.got.plt) *(.got)
    *(.shdata)
    *(.data .data.*)
    *(.gnu.linkonce.d.*)
    . = ALIGN (4);
    _edata = .;
  } >ram AT>rom

  .bss :
  {
    __bss_start__ = . ;
    __bss_start = __bss_start__;
    *(.shbss)
    *(.bss .bss.*)
    *(.gnu.linkonce.b.*)
    *(COMMON)
    . = ALIGN (8);
    __bss_end__ = . ;
    _end = __bss_end__;
    __end = __bss_end__;
  } >ram AT>rom

   /* Minimum HEAP - from top of BSS */
  .heap_dummy :
  {
    . = ALIGN(4);
    PROVIDE ( end = . );
    PROVIDE ( __end__ = . );
    PROVIDE ( _end = . );
    __HeapBottom = .;
	__heap_addr = .;
    . = . + __heap_size;
  } > ram

  /* Set stack top to end of ram, and stack limit move down by
   * size of stack_dummy section 
   */
  __StackTop   = ORIGIN(ram) + LENGTH(ram) - __gdbstack_fix; /* subtract fix for GDB bug */
  __HeapLimit  = ORIGIN(ram) + LENGTH(ram) - __stack_size;
  __StackLimit = ORIGIN(ram) + LENGTH(ram) - __stack_size;
  
  .stab 0 (NOLOAD) :
  {
    *(.stab)
  }

  .stabstr 0 (NOLOAD) :
  {
    *(.stabstr)
  }

  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
}
