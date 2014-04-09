#include "startup_stm32f4xx.h"

/* Library includes -------------------------------------------------------- */
#include "stm32f4xx.h"			//required for *int*_t data types
#include "system_stm32f4xx.h"	//required for SystemInit() function
#include "core_cm4.h"			//required for __ASM macro definition

/* Custom includes --------------------------------------------------------- */
//PLACEHOLDER

/* Exported variables ------------------------------------------------------ */
//PLACEHOLDER

/* Internal function prototypes -------------------------------------------- */
/* Locally defined functions */
void						Default_Reset_Handler(void);				//default reset handler
static void					Default_Handler(void);						//default exception handler (if none else specified)
/* Imported functions */
extern int					main(void);									//application's entry point
/* Reset handler */
__attribute__ ((used)) void __attribute__ ((weak)) Reset_Handler(void);
/* Core interrupt handlers */
void __attribute__ ((weak)) NMI_Handler(void);
void __attribute__ ((weak)) HardFault_Handler(void);
void __attribute__ ((weak)) MemManage_Handler(void);
void __attribute__ ((weak)) BusFault_Handler(void);
void __attribute__ ((weak)) UsageFault_Handler(void);
void __attribute__ ((weak)) SVC_Handler(void);
void __attribute__ ((weak)) DebugMon_Handler(void);
void __attribute__ ((weak)) PendSV_Handler(void);
void __attribute__ ((weak)) SysTick_Handler(void);
/* Peripheral handlers */
void __attribute__ ((weak)) WWDG_IRQHandler(void);
void __attribute__ ((weak)) PVD_IRQHandler(void);
void __attribute__ ((weak)) TAMP_STAMP_IRQHandler(void);
void __attribute__ ((weak)) RTC_WKUP_IRQHandler(void);
void __attribute__ ((weak)) FLASH_IRQHandler(void);
void __attribute__ ((weak)) RCC_IRQHandler(void);
void __attribute__ ((weak)) EXTI0_IRQHandler(void);
void __attribute__ ((weak)) EXTI1_IRQHandler(void);
void __attribute__ ((weak)) EXTI2_IRQHandler(void);
void __attribute__ ((weak)) EXTI3_IRQHandler(void);
void __attribute__ ((weak)) EXTI4_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Stream0_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Stream1_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Stream2_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Stream3_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Stream4_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Stream5_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Stream6_IRQHandler(void);
void __attribute__ ((weak)) ADC_IRQHandler(void);
void __attribute__ ((weak)) CAN1_TX_IRQHandler(void);
void __attribute__ ((weak)) CAN1_RX0_IRQHandler(void);
void __attribute__ ((weak)) CAN1_RX1_IRQHandler(void);
void __attribute__ ((weak)) CAN1_SCE_IRQHandler(void);
void __attribute__ ((weak)) EXTI9_5_IRQHandler(void);
void __attribute__ ((weak)) TIM1_BRK_TIM9_IRQHandler(void);
void __attribute__ ((weak)) TIM1_UP_TIM10_IRQHandler(void);
void __attribute__ ((weak)) TIM1_TRG_COM_TIM11_IRQHandler(void);
void __attribute__ ((weak)) TIM1_CC_IRQHandler(void);
void __attribute__ ((weak)) TIM2_IRQHandler(void);
void __attribute__ ((weak)) TIM3_IRQHandler(void);
void __attribute__ ((weak)) TIM4_IRQHandler(void);
void __attribute__ ((weak)) I2C1_EV_IRQHandler(void);
void __attribute__ ((weak)) I2C1_ER_IRQHandler(void);
void __attribute__ ((weak)) I2C2_EV_IRQHandler(void);
void __attribute__ ((weak)) I2C2_ER_IRQHandler(void);
void __attribute__ ((weak)) SPI1_IRQHandler(void);
void __attribute__ ((weak)) SPI2_IRQHandler(void);
void __attribute__ ((weak)) USART1_IRQHandler(void);
void __attribute__ ((weak)) USART2_IRQHandler(void);
void __attribute__ ((weak)) USART3_IRQHandler(void);
void __attribute__ ((weak)) EXTI15_10_IRQHandler(void);
void __attribute__ ((weak)) RTC_Alarm_IRQHandler(void);
void __attribute__ ((weak)) OTG_FS_WKUP_IRQHandler(void);
void __attribute__ ((weak)) TIM8_BRK_TIM12_IRQHandler(void);
void __attribute__ ((weak)) TIM8_UP_TIM13_IRQHandler(void);
void __attribute__ ((weak)) TIM8_TRG_COM_TIM14_IRQHandler(void);
void __attribute__ ((weak)) TIM8_CC_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Stream7_IRQHandler(void);
void __attribute__ ((weak)) FSMC_IRQHandler(void);
void __attribute__ ((weak)) SDIO_IRQHandler(void);
void __attribute__ ((weak)) TIM5_IRQHandler(void);
void __attribute__ ((weak)) SPI3_IRQHandler(void);
void __attribute__ ((weak)) UART4_IRQHandler(void);
void __attribute__ ((weak)) UART5_IRQHandler(void);
void __attribute__ ((weak)) TIM6_DAC_IRQHandler(void);
void __attribute__ ((weak)) TIM7_IRQHandler(void);
void __attribute__ ((weak)) DMA2_Stream0_IRQHandler(void);
void __attribute__ ((weak)) DMA2_Stream1_IRQHandler(void);
void __attribute__ ((weak)) DMA2_Stream2_IRQHandler(void);
void __attribute__ ((weak)) DMA2_Stream3_IRQHandler(void);
void __attribute__ ((weak)) DMA2_Stream4_IRQHandler(void);
void __attribute__ ((weak)) ETH_IRQHandler(void);
void __attribute__ ((weak)) ETH_WKUP_IRQHandler(void);
void __attribute__ ((weak)) CAN2_TX_IRQHandler(void);
void __attribute__ ((weak)) CAN2_RX0_IRQHandler(void);
void __attribute__ ((weak)) CAN2_RX1_IRQHandler(void);
void __attribute__ ((weak)) CAN2_SCE_IRQHandler(void);
void __attribute__ ((weak)) OTG_FS_IRQHandler(void);
void __attribute__ ((weak)) DMA2_Stream5_IRQHandler(void);
void __attribute__ ((weak)) DMA2_Stream6_IRQHandler(void);
void __attribute__ ((weak)) DMA2_Stream7_IRQHandler(void);
void __attribute__ ((weak)) USART6_IRQHandler(void);
void __attribute__ ((weak)) I2C3_EV_IRQHandler(void);
void __attribute__ ((weak)) I2C3_ER_IRQHandler(void);
void __attribute__ ((weak)) OTG_HS_EP1_OUT_IRQHandler(void);
void __attribute__ ((weak)) OTG_HS_EP1_IN_IRQHandler(void);
void __attribute__ ((weak)) OTG_HS_WKUP_IRQHandler(void);
void __attribute__ ((weak)) OTG_HS_IRQHandler(void);
void __attribute__ ((weak)) DCMI_IRQHandler(void);
void __attribute__ ((weak)) CRYP_IRQHandler(void);
void __attribute__ ((weak)) HASH_RNG_IRQHandler(void);
void __attribute__ ((weak)) FPU_IRQHandler(void);

/* Internal variables ------------------------------------------------------ */
extern unsigned long											_sidata;							//start address for the initialization values of the .data section
extern unsigned long											_sdata;								//start address of the .data section
extern unsigned long											_edata;								//end address for the .data section
extern unsigned long											_sbss;								//start address for the .bss section (0-initialized part of .data section)
extern unsigned long											_ebss;								//end address for the .bss section
extern void														_eram;								//end address for ram
extern unsigned long											_sheap;								//start address of the heap
extern unsigned long											_eheap;								//end address of the heap
__attribute__ ((section(".stack")))				unsigned long 	pulStack[STACK_SIZE];				//the stack
__attribute__ ((section(".heap"))) 				unsigned long	pulHeap[HEAP_SIZE];					//the heap
__attribute__ ((used,section(".isr_vector")))	void 			(* const g_pfnVectors[])(void) = {	//interrupt service routines vector (table of 32-bit function pointers)
	(void*) &pulStack[STACK_SIZE],	//initial stack pointer; points to the top of stack
	Reset_Handler,					//Reset handler
	NMI_Handler,					//Non-Maskable Interrupts handler
	HardFault_Handler,				//Hard Fault handler
	MemManage_Handler,				//MPU Fault handler
	BusFault_Handler,				//Bus Fault handler
	UsageFault_Handler,				//Usage Fault handler
	0x00000000,						//reserved
	0x00000000,						//reserved
	0x00000000,						//reserved
	0x00000000,						//reserved
	SVC_Handler,					//System Vector Call handler
	DebugMon_Handler,				//Debug Monitor handler
	0x00000000,						//reserved
	PendSV_Handler,					//Pending/pendable SV Call handler
	SysTick_Handler,				//System Tick handler
	WWDG_IRQHandler,				//Window Watchdog handler
	PVD_IRQHandler,					//PVD through EXTI line detection handler
	TAMP_STAMP_IRQHandler,			//Tamper and TimeStamps through the EXTI line handler
	RTC_WKUP_IRQHandler,			//RTC Wakeup through the EXTI line handler
	FLASH_IRQHandler,				//FLASH handler
	RCC_IRQHandler,					//RCC handler
	EXTI0_IRQHandler,				//EXTI Line0 handler
	EXTI1_IRQHandler,				//EXTI Line1 handler
	EXTI2_IRQHandler,				//EXTI Line2 handler
	EXTI3_IRQHandler,				//EXTI Line3 handler
	EXTI4_IRQHandler,				//EXTI Line4 handler
	DMA1_Stream0_IRQHandler,		//DMA1 Stream 0 handler
	DMA1_Stream1_IRQHandler,		//DMA1 Stream 1 handler
	DMA1_Stream2_IRQHandler,		//DMA1 Stream 2 handler
	DMA1_Stream3_IRQHandler,		//DMA1 Stream 3 handler
	DMA1_Stream4_IRQHandler,		//DMA1 Stream 4 handler
	DMA1_Stream5_IRQHandler,		//DMA1 Stream 5 handler
	DMA1_Stream6_IRQHandler,		//DMA1 Stream 6 handler
	ADC_IRQHandler,					//ADC1, ADC2 and ADC3 handler
	CAN1_TX_IRQHandler,				//CAN1 TX handler
	CAN1_RX0_IRQHandler,			//CAN1 RX0 handler
	CAN1_RX1_IRQHandler,			//CAN1 RX1 handler
	CAN1_SCE_IRQHandler,			//CAN1 SCE handler
	EXTI9_5_IRQHandler,				//External Line[9:5] handlers
	TIM1_BRK_TIM9_IRQHandler,		//TIM1 Break and TIM9 handlers
	TIM1_UP_TIM10_IRQHandler,		//TIM1 Update and TIM10 handlers
	TIM1_TRG_COM_TIM11_IRQHandler,	//TIM1 Trigger and Commutation and TIM11 handlers
	TIM1_CC_IRQHandler,				//TIM1 Capture Compare handler
	TIM2_IRQHandler,				//TIM2 handler
	TIM3_IRQHandler,				//TIM3 handler
	TIM4_IRQHandler,				//TIM4 handler
	I2C1_EV_IRQHandler,				//I2C1 Event handler
	I2C1_ER_IRQHandler,				//I2C1 Error handler
	I2C2_EV_IRQHandler,				//I2C2 Event handler
	I2C2_ER_IRQHandler,				//I2C2 Error handler
	SPI1_IRQHandler,				//SPI1 handler
	SPI2_IRQHandler,				//SPI2 handler
	USART1_IRQHandler,				//USART1 handler
	USART2_IRQHandler,				//USART2 handler
	USART3_IRQHandler,				//USART3 handler
	EXTI15_10_IRQHandler,			//External Line[15:10] handlers
	RTC_Alarm_IRQHandler,			//RTC Alarm (A and B) through EXTI line handler
	OTG_FS_WKUP_IRQHandler,			//USB OTG FS Wakeup through EXTI line handler
	TIM8_BRK_TIM12_IRQHandler,		//TIM8 Break and TIM12 handlers
	TIM8_UP_TIM13_IRQHandler,		//TIM8 Update and TIM13 handlers
	TIM8_TRG_COM_TIM14_IRQHandler,	//TIM8 Trigger and Commutation and TIM14 handlers
	TIM8_CC_IRQHandler,				//TIM8 Capture Compare handler
	DMA1_Stream7_IRQHandler,		//DMA1 Stream7 handler
	FSMC_IRQHandler,				//FSMC handler
	SDIO_IRQHandler,				//SDIO handler
	TIM5_IRQHandler,				//TIM5 handler
	SPI3_IRQHandler,				//SPI3 handler
	UART4_IRQHandler,				//UART4 handler
	UART5_IRQHandler,				//UART5 handler
	TIM6_DAC_IRQHandler,			//TIM6 and DAC1&2 underrun error handlers
	TIM7_IRQHandler,				//TIM7 handler
	DMA2_Stream0_IRQHandler,		//DMA2 Stream 0 handler
	DMA2_Stream1_IRQHandler,		//DMA2 Stream 1 handler
	DMA2_Stream2_IRQHandler,		//DMA2 Stream 2 handler
	DMA2_Stream3_IRQHandler,		//DMA2 Stream 3 handler
	DMA2_Stream4_IRQHandler,		//DMA2 Stream 4 handler
	ETH_IRQHandler,					//Ethernet handler
	ETH_WKUP_IRQHandler,			//Ethernet Wakeup through EXTI line handler
	CAN2_TX_IRQHandler,				//CAN2 TX handler
	CAN2_RX0_IRQHandler,			//CAN2 RX0 handler
	CAN2_RX1_IRQHandler,			//CAN2 RX1 handler
	CAN2_SCE_IRQHandler,			//CAN2 SCE handler
	OTG_FS_IRQHandler,				//USB OTG FS handler
	DMA2_Stream5_IRQHandler,		//DMA2 Stream 5 handler
	DMA2_Stream6_IRQHandler,		//DMA2 Stream 6 handler
	DMA2_Stream7_IRQHandler,		//DMA2 Stream 7 handler
	USART6_IRQHandler,				//USART6 handler
	I2C3_EV_IRQHandler,				//I2C3 event handler
	I2C3_ER_IRQHandler,				//I2C3 error handler
	OTG_HS_EP1_OUT_IRQHandler,		//USB OTG HS End Point 1 Out handler
	OTG_HS_EP1_IN_IRQHandler,		//USB OTG HS End Point 1 In handler
	OTG_HS_WKUP_IRQHandler,			//USB OTG HS Wakeup through EXTI handler
	OTG_HS_IRQHandler,				//USB OTG HS handler
	DCMI_IRQHandler,				//DCMI handler
	CRYP_IRQHandler,				//CRYP crypto handler
	HASH_RNG_IRQHandler,			//Hash and Rng handlers
	FPU_IRQHandler					//FPU handler
};

/* Function definitions ---------------------------------------------------- */


/**
  * @brief  This is the code that gets called when the processor first starts
  *         execution following a reset event. Only the absolutely necessary set
  *         is performed, after which the application supplied main() routine is
  *         called.
  * @retval None.
  */
void Default_Reset_Handler(void) {
	unsigned long *pulSrc, *pulDest;

	//prevent .heap segment from being optimized out by providing at least one access to it
	pulHeap[0] = 0xFFFFFFFF;

	//copy the .data segment initialization values from flash to ram
	pulSrc = &_sidata;
	for (pulDest=&_sdata; pulDest<&_edata;) {
		*(pulDest++) = *(pulSrc++);
	}

	//zero-fill the .bss segment
	/*
	 * This is done with inline assembly since this will clear the value of
	 * pulDest if it is not kept in a register.
	 *
	 * Inline assembly symbol is compiler-dependent, so here __ASM macro from
	 * core_cm4.h is used. It is  probably not necessary since this file is
	 * compiler-dependent too.
	 */
	__ASM(
			"	LDR		R0, =_sbss				\n"
			"	LDR		R1, =_ebss				\n"
			"	MOV		R2, #0					\n"
			"	.thumb_func						\n"
			"zero_loop:							\n"
			"	CMP		R0, R1					\n"
			"	IT		LT						\n"
			"	STRLT   R2, [R0], #4			\n"
			"	BLT		zero_loop				\n"
	);

	//if project is configured to use Floating Point Unit, enable it here
	/*
	 * CoIDE uses __FPU_USED to signal FPU should be enabled. SystemInit can
	 * enable FPU too but requires __FPU_USED = 1 to do so. Both ways are left
	 * intact, do either defining __FPU_USED or __FPU_USED = 1 will (probably)
	 * work.
	 */
#ifdef __FPU_USED
	__ASM(
			"	LDR.W	R0, =0xE000ED88			\n"
			"	LDR		R1,	[R0]				\n"
			"	ORR		R1, R1, #(0xF << 20)	\n"
			"	STR		R1, [R0]				\n"
	);
#endif	

  //call vendor-specific SystemInit()
  SystemInit();

  //call the application's entry point
  main();
}


/**
  * @brief  This is the code that gets called when the processor receives an
  *         unexpected interrupt.  This simply enters an infinite loop,
  *         preserving the system state for examination by a debugger.
  * @retval None.
  */
static void Default_Handler(void) {
	while (1) {}
}


/*
 * Custom Reset Handler can be specified elsewhere in the code.
 */
#pragma weak Reset_Handler					= Default_Reset_Handler
/*
 * These are weak aliases for the default handler. Aliases have names matching
 * interrupt handlers so if there is no specific handler provided and yet
 * interrupt is somehow enabled, system will end up halted inside
 * Default_Handler().
 */
#pragma weak NMI_Handler					= Default_Handler
#pragma weak HardFault_Handler				= Default_Handler
#pragma weak MemManage_Handler				= Default_Handler
#pragma weak BusFault_Handler				= Default_Handler
#pragma weak UsageFault_Handler				= Default_Handler
#pragma weak SVC_Handler					= Default_Handler
#pragma weak DebugMon_Handler				= Default_Handler
#pragma weak PendSV_Handler					= Default_Handler
#pragma weak SysTick_Handler				= Default_Handler
#pragma weak WWDG_IRQHandler				= Default_Handler
#pragma weak PVD_IRQHandler					= Default_Handler
#pragma weak TAMP_STAMP_IRQHandler			= Default_Handler
#pragma weak RTC_WKUP_IRQHandler			= Default_Handler
#pragma weak FLASH_IRQHandler				= Default_Handler
#pragma weak RCC_IRQHandler					= Default_Handler
#pragma weak EXTI0_IRQHandler				= Default_Handler
#pragma weak EXTI1_IRQHandler				= Default_Handler
#pragma weak EXTI2_IRQHandler				= Default_Handler
#pragma weak EXTI3_IRQHandler				= Default_Handler
#pragma weak EXTI4_IRQHandler				= Default_Handler
#pragma weak DMA1_Stream0_IRQHandler		= Default_Handler
#pragma weak DMA1_Stream1_IRQHandler		= Default_Handler
#pragma weak DMA1_Stream2_IRQHandler		= Default_Handler
#pragma weak DMA1_Stream3_IRQHandler		= Default_Handler
#pragma weak DMA1_Stream4_IRQHandler		= Default_Handler
#pragma weak DMA1_Stream5_IRQHandler		= Default_Handler
#pragma weak DMA1_Stream6_IRQHandler		= Default_Handler
#pragma weak ADC_IRQHandler					= Default_Handler
#pragma weak CAN1_TX_IRQHandler				= Default_Handler
#pragma weak CAN1_RX0_IRQHandler			= Default_Handler
#pragma weak CAN1_RX1_IRQHandler			= Default_Handler
#pragma weak CAN1_SCE_IRQHandler			= Default_Handler
#pragma weak EXTI9_5_IRQHandler				= Default_Handler
#pragma weak TIM1_BRK_TIM9_IRQHandler		= Default_Handler
#pragma weak TIM1_UP_TIM10_IRQHandler		= Default_Handler
#pragma weak TIM1_TRG_COM_TIM11_IRQHandler	= Default_Handler
#pragma weak TIM1_CC_IRQHandler				= Default_Handler
#pragma weak TIM2_IRQHandler				= Default_Handler
#pragma weak TIM3_IRQHandler				= Default_Handler
#pragma weak TIM4_IRQHandler				= Default_Handler
#pragma weak I2C1_EV_IRQHandler				= Default_Handler
#pragma weak I2C1_ER_IRQHandler				= Default_Handler
#pragma weak I2C2_EV_IRQHandler				= Default_Handler
#pragma weak I2C2_ER_IRQHandler				= Default_Handler
#pragma weak SPI1_IRQHandler				= Default_Handler
#pragma weak SPI2_IRQHandler				= Default_Handler
#pragma weak USART1_IRQHandler				= Default_Handler
#pragma weak USART2_IRQHandler				= Default_Handler
#pragma weak USART3_IRQHandler				= Default_Handler
#pragma weak EXTI15_10_IRQHandler			= Default_Handler
#pragma weak RTC_Alarm_IRQHandler			= Default_Handler
#pragma weak OTG_FS_WKUP_IRQHandler			= Default_Handler
#pragma weak TIM8_BRK_TIM12_IRQHandler		= Default_Handler
#pragma weak TIM8_UP_TIM13_IRQHandler		= Default_Handler
#pragma weak TIM8_TRG_COM_TIM14_IRQHandler	= Default_Handler
#pragma weak TIM8_CC_IRQHandler				= Default_Handler
#pragma weak DMA1_Stream7_IRQHandler		= Default_Handler
#pragma weak FSMC_IRQHandler				= Default_Handler
#pragma weak SDIO_IRQHandler				= Default_Handler
#pragma weak TIM5_IRQHandler				= Default_Handler
#pragma weak SPI3_IRQHandler				= Default_Handler
#pragma weak UART4_IRQHandler				= Default_Handler
#pragma weak UART5_IRQHandler				= Default_Handler
#pragma weak TIM6_DAC_IRQHandler			= Default_Handler
#pragma weak TIM7_IRQHandler				= Default_Handler
#pragma weak DMA2_Stream0_IRQHandler		= Default_Handler
#pragma weak DMA2_Stream1_IRQHandler		= Default_Handler
#pragma weak DMA2_Stream2_IRQHandler		= Default_Handler
#pragma weak DMA2_Stream3_IRQHandler		= Default_Handler
#pragma weak DMA2_Stream4_IRQHandler		= Default_Handler
#pragma weak ETH_IRQHandler					= Default_Handler
#pragma weak ETH_WKUP_IRQHandler			= Default_Handler
#pragma weak CAN2_TX_IRQHandler				= Default_Handler
#pragma weak CAN2_RX0_IRQHandler			= Default_Handler
#pragma weak CAN2_RX1_IRQHandler			= Default_Handler
#pragma weak CAN2_SCE_IRQHandler			= Default_Handler
#pragma weak OTG_FS_IRQHandler				= Default_Handler
#pragma weak DMA2_Stream5_IRQHandler		= Default_Handler
#pragma weak DMA2_Stream6_IRQHandler		= Default_Handler
#pragma weak DMA2_Stream7_IRQHandler		= Default_Handler
#pragma weak USART6_IRQHandler				= Default_Handler
#pragma weak I2C3_EV_IRQHandler				= Default_Handler
#pragma weak I2C3_ER_IRQHandler				= Default_Handler
#pragma weak OTG_HS_EP1_OUT_IRQHandler		= Default_Handler
#pragma weak OTG_HS_EP1_IN_IRQHandler		= Default_Handler
#pragma weak OTG_HS_WKUP_IRQHandler			= Default_Handler
#pragma weak OTG_HS_IRQHandler				= Default_Handler
#pragma weak DCMI_IRQHandler				= Default_Handler
#pragma weak CRYP_IRQHandler				= Default_Handler
#pragma weak HASH_RNG_IRQHandler			= Default_Handler
#pragma weak FPU_IRQHandler					= Default_Handler
