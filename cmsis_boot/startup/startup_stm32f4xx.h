#ifndef __STARTUP_STM32F4XX_H
#define __STARTUP_STM32F4XX_H

#ifdef __cplusplus
	extern "C" {
#endif

/*
 * This module performs following operations:
 * 	- Set the initial SP
 * 	- Set the initial PC == Reset_Handler,
 * 	- Set the vector table entries with the exceptions ISR address
 * 	- Configure the clock system and the external SRAM mounted on STM324xG-EVA
 * 	  board to be used as data memory (optional, to be enabled by user)
 * 	- Branches to main in the C library (which eventually calls main()).
 * After Reset the Cortex-M4 processor is in Thread mode, priority is
 * Privileged, and the Stack is set to Main.
 *
 * Memory model provided by this file along with linker script is "two-region".
 * Stack overflow will result in Hard Fault. Heap overflow will result in
 * ENOMEM.
 */

/* Dependancy includes ----------------------------------------------------- */
//PLACEHOLDER

/* Constants --------------------------------------------------------------- */
#define STACK_SIZE	0x00000800	//stack size (8KB aligned on 4B boundary)
#define HEAP_SIZE	0x00004000	//stack size (64KB aligned on 4B boundary)

/* Type definitions -------------------------------------------------------- */
//PLACEHOLDER

/* Exported variables ------------------------------------------------------ */
//PLACEHOLDER

/* Function prototypes ----------------------------------------------------- */
//PLACEHOLDER

#ifdef __cplusplus
	}
#endif

#endif
