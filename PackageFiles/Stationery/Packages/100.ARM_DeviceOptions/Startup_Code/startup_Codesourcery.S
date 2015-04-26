/*
 * start.S
 *
 * Generic start up code for Kinetis
 *
 * Copyright 2013 Peter O'Donoghue
 *
 * License GPL
 *
 * Based upon description in Codesourcery document Getting_Started.pdf
 *
 */

/*
 * Hard Reset Phase
 */
	.section .text.cs3.reset,"ax",%progbits
	.code 16
	.thumb_func
    .globl __cs3_reset, __cs3_start_asm
    .type __cs3_reset, %function
__cs3_reset:
	ldr	r1,=__cs3_start_asm
	bx	r1

/*
 * Assembly Initialization Phase
 */
    .section .text.cs3.init,"ax",%progbits
    .globl __cs3_stack,__cs3_interrupt_vector_coldfire
    .globl _start, __cs3_start_asm
	.code 16
	.thumb_func

    .globl __cs3_start_asm
    .type __cs3_start_asm, %function
_start:
__cs3_start_asm:
	ldr	r1,=__cs3_stack
	mov	sp,r1
	ldr	r1,=__cs3_start_c
	bx	r1

	.pool
