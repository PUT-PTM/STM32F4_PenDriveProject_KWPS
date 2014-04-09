This directory contains all device-related files:

system_stm32f4xx.c/.h : 	contains definitions of system setup functions
							called by startup routine (reset vector)

stm32f4xx.h :				CMSIS Cortex-M4 device peripheral access layer
							header file

stm32f4xx_conf.h :			STM32F4XX Standard Peripherals Library configuration
							file

stm32f4xx_it.c/.h :			contains ISR definitions and their basic
							implementations for STM32F407VG
