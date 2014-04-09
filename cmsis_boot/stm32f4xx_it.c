#include "stm32f4xx_it.h"

/* Library includes -------------------------------------------------------- */
//PLACEHOLDER

/* Custom includes --------------------------------------------------------- */
#include "main.h"

/* Exported variables ------------------------------------------------------ */
//PLACEHOLDER

/* Internal variables ------------------------------------------------------ */
//PLACEHOLDER

/* Internal function prototypes -------------------------------------------- */
//PLACEHOLDER

/* Function definitions ---------------------------------------------------- */


/**
  * @brief  Non maskable interrupt handler.
  * @retval None.
  */
void NMI_Handler(void) {
}


/**
  * @brief  Fault handler.
  * @retval None.
  */
void HardFault_Handler(void) {
	while (1) {}
}


/**
  * @brief  Memory management handler.
  * @retval None.
  */
void MemManage_Handler(void) {
	while (1) {}
}


/**
  * @brief  Pre-fetch fault, memory access fault handler.
  * @retval None.
  */
void BusFault_Handler(void) {
	while (1) {}
}


/**
  * @brief  Undefined instruction or illegal state handler.
  * @retval None.
  */
void UsageFault_Handler(void) {
	while (1) {}
}


/**
  * @brief  System service call via SWI instruction handler.
  * @retval None.
  */
void SVC_Handler(void) {
	//nothing here
}


/**
  * @brief  Debug monitor handler.
  * @retval None.
  */
void DebugMon_Handler(void) {
	//nothing here
}


/**
  * @brief  Pendable request for system service handler.
  * @retval None.
  */
void PendSV_Handler(void){
	//nothing here
}


/**
  * @brief  System timer tick handler.
  * @retval None.
  */
void SysTick_Handler(void) {
	//used to implement Delay function defined in main.c
	TimingDelay_Decrement();
}
