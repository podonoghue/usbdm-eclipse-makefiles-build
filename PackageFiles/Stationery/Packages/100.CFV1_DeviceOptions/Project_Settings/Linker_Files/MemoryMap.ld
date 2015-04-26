
/* ---- <<< Use Configuration Wizard in Context Menu >>> ---- */

/* <o> Stack Size
   <i> Required amount of stack space  
   <0x0-$(linkerRamSize)> 
*/
__stack_size = $(linkerStackSize);

/* <o> GDB stack fix 
   <i> A small amount of reserve RAM used to prevent an Eclipse GDB bug that occurs when the stack is near unallocated memory
   <0-32> 
*/
__gdbstack_fix = 8;

/* <o> Minimum Heap Size 
   <i> Actual heap may be larger as it fills all unused RAM 
   <0x0-$(linkerRamSize)> 
*/
__heap_size  = $(linkerHeapSize);

/* <h>RAM region used for stack and heap   <o0>  start <o1> length  </h> */
/* <h>Flash region used for code, data etc.<o2>  start <o3> length  </h> */
$(linkerInformation)

