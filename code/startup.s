.thumb
@This turns on Unified Assembly Language which is required to get all the features of Thumb-2.
.syntax unified					@ without this line "orr r0, r0, #0x200000" will give an error "unshifted register required" 
.cpu cortex-m3

.equ STACKINIT, 0x20005000		@ end of SRAM 20kb
.extern _mainCRTStartup

.section .text
.org 0x00000000					
SP: .word STACKINIT				@ 20kb of RAM, so I will put stack pointer to the end of it
RESET: .word main
NMI_HANDLER: .word nmi_fault 
HARD_FAULT: .word hard_fault
MEMORY_FAULT: .word memory_fault
BUS_FAULT: .word bus_fault
USAGE_FAULT: .word usage_fault + 1

nmi_fault:
	@ breakpoint
	bkpt
	bx lr
	
hard_fault:
	@ breakpoint
	bkpt
	ldr r7, [sp, #0x18]
	bx lr

memory_fault:
	@ breakpoint
	bkpt
	bx lr

bus_fault:
	@ breakpoint
	bkpt
	bx lr

usage_fault:
	@ breakpoint
	bkpt
	bx lr
	
.end
