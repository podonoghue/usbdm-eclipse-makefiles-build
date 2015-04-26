/*
 * startup_gcc_m68k_elf.S
 *
 * Generic start up code for Coldfire V1
 *
 * Copyright 2013 Peter O'Donoghue
 *
 * License GPL
 *
 */
 	.extern main
	.extern exit
	.extern hardware_init_hook
	.extern software_init_hook
	.extern atexit
	.extern call___do_global_dtors_aux

	.extern __bss_start__
	.extern __bss_end__
	.extern __data_load
	.extern __data_start
	.extern _edata

	.extern __CTOR_LIST__
	.extern	__DTOR_LIST__

    .globl	SystemInit

    .section .text.init,"ax",%progbits
    .globl	__StackTop,vectors
    .globl	__HardReset
    .type	__HardReset,%function

/*
 * Hard Reset
 */
__HardReset:
	/*
	 * Set up stack
	 */
	move.l	#__StackTop,%sp
	/*
	 * Set up initial stack frame
	 */
	link	%a6, #-8
	/*
	 * Set the interrupt vector table position
	 */
	move.l	#__vector_table,%d0
	movec.l	%d0,%VBR
	/*
	 * Zero out the bss section.
	 * Assumes aligned multiple of 4 bytes
	 */
	move.l	#__bss_start__,%a3
	move.l	#__bss_end__,%a4
	bra.s	2f
1:
	clr.l	(%a3)+
2:
	cmp.l	%a3,%a4
	bhi.s	1b
	/*
	 * Initialise the data area
	 * Assumes aligned multiple of 4 bytes
	 */
	move.l	#__data_load,%a3
	move.l	#__data_start,%a4
	move.l	#_edata,%a5
	bra.s	4f
3:
	move.l	(%a3)+,(%a4)+
4:
	cmp.l	%a4,%a5
	bhi.s	3b
	/*
	 * Do machine initialisation
	 */
	jsr		SystemInit
	/*
	 * Initialize target specific stuff.
	 * Only execute these functions it they exist.
	 */
	lea.l	hardware_init_hook,%a3
	tst.l	%a3
	beq.s	5f
	jsr     (%a3)
5:

	lea.l	software_init_hook,%a3
	tst.l	%a3
	beq.s	6f
	jsr     (%a3)
6:
	/*
	 * Do pre-init array
	 */
	lea.l	__preinit_array_start,%a3
	lea.l	__preinit_array_end,%a4
	bra.s	8f

7:
	move.l	(%a3),%a5
	jsr     (%a5)
8:
	cmp.l	%a3,%a4
	bhi.s	7b
	/*
	 * Do _init()
	 */
	lea.l	_init,%a3
	tst.l	%a3
	beq.s	9f
	jsr     (%a3)
9:
	/*
	 * Do init array
	 */
	lea.l	__init_array_start,%a3
	lea.l	__init_array_end,%a4
	bra.s	11f

10:
	move.l	(%a3),%a5
	jsr     (%a5)
11:
	cmp.l	%a3,%a4
	bhi.s	10b

#ifdef ADD_DTORS
	/* put __do_global_dtors in the atexit list so the destructors get run */
	move.l	#__do_global_dtors,(%sp)
	jsr		atexit

	move.l	#__FINI_SECTION__,(%sp)
	jsr		atexit
#endif
	/*
	 * Do constructors
	 */
	lea.l	__CTOR_LIST__,%a3
	move.l	(%a3)+,%a4
	cmp.l	#-1,%a4
	bne		13f
12:
	tst.l	(%a3)+
	bne.s	12b
	sub.l	#4,%a3
	bra.s	14f

13:	add.l	%a4,%a3
14:
	move.l	-(%a3),%a4
	cmp.l	#-1,%a4
	beq.s	15f
	jsr		(%a4)
	bra.s	14b
15:
	/*
	 *  Call the main routine from the application to get it going.
	 * 		main (int argc, char *argv[])
	 */
    pea.l   argv
    pea.l   1
	jsr     main
	move.l	%d0,%sp@-	// Save rc from main()

	jsr		__libc_fini_array

	jsr		exit  // Pass rc to exit

	.align 4
argv:
	dc.l	0,0

