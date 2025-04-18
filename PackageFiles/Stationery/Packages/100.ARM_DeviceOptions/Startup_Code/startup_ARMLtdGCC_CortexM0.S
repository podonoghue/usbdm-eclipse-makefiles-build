/* File: startup_ARMCM0.S
 * Purpose: startup file for Cortex-M0 devices. Should use with 
 *   GCC for ARM Embedded Processors
 * Version: V1.4
 * Date: 09 July 2012
 * 
 * Copyright (c) 2011, 2012, ARM Limited
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the ARM Limited nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ARM LIMITED BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
    .syntax unified
    .arch armv6-m

#define __STARTUP_CLEAR_BSS

#if 0
/*
 *  Stack space
 */
    .section .stack
    .align 3
#ifdef __STACK_SIZE
    .equ    Stack_Size, __STACK_SIZE
#else
    .equ    Stack_Size, 0xc00
#endif
    .globl    __StackTop
    .globl    __StackLimit
__StackLimit:
    .space    Stack_Size
    .size __StackLimit, . - __StackLimit
__StackTop:
    .size __StackTop, . - __StackTop

/*
 *  Heap space
 */
    .section .heap
    .align 3
#ifdef __HEAP_SIZE
    .equ    Heap_Size, __HEAP_SIZE
#else
    .equ    Heap_Size, 0
#endif
    .globl    __HeapBase
    .globl    __HeapLimit
__HeapBase:
    .if    Heap_Size
    .space    Heap_Size
    .endif
    .size __HeapBase, . - __HeapBase
__HeapLimit:
    .size __HeapLimit, . - __HeapLimit

#endif

/*
 *  Low-level reset
 */
    .text
    .thumb
    .thumb_func
    .align 1
    .globl    Reset_Handler
    .type    Reset_Handler, %function
Reset_Handler:

#ifndef __NO_SYSTEM_INIT
    // Low-level system initialise must be done here so to avoid WDOG timeout
    bl    SystemInitLowLevel
#endif
/*
 *     Loop to copy data from read only memory to RAM. The ranges of copy from/to are
 *     specified by following symbols evaluated in linker script (4-byte aligned).
 *
 *      __data_image_start__ : Beginning of data sections to copy from. (Usually end of code section).
 *      __data_start__       : Start of data area (in RAM) that data should be copied to.
 *      __data_end__         : End of data area (in RAM) that data should be copied to.
 *
 *     [__data_image_start__ ... ] => [__data_start__ .. __data_end__]
 */

    ldr    r1, =__data_image_start__
    ldr    r2, =__data_start__
    ldr    r3, =__data_end__

    subs    r3, r2
    ble    .LC1    
.LC0:
    subs    r3, #4
    ldr     r0, [r1, r3]
    str     r0, [r2, r3]
    bgt    .LC0
.LC1:

#ifdef __STARTUP_CLEAR_BSS
/*     This part of work usually is done in C library startup code. Otherwise,
 *     define this macro to enable it in this startup.
 *
 *     Loop to zero out BSS section, which uses following symbols
 *     in linker script:
 *      __bss_start__ : start of BSS section. Must align to 4
 *      __bss_end__   : end of BSS section. Must align to 4
 */
    ldr r1, =__bss_start__
    ldr r2, =__bss_end__

    subs    r2, r1
    ble .LC3

    movs    r0, 0
.LC2:
    str r0, [r1, r2]
    subs    r2, 4
    bge .LC2
.LC3:
#endif

#ifndef __START
#define __START _start
#endif
#ifndef __NO_SYSTEM_INIT
   // Now done as constructor after __START
   // May need some objects created by C startup
   // bl    SystemInit
#endif

    // Make sure hook is provided for CMSIS (fix for KDS compiler)
    bl	  	software_init_hook

    b       __START
    .pool
    .size Reset_Handler, . - Reset_Handler
    
    .end
