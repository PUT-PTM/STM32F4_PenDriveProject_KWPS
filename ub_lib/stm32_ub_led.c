//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32_ub_led.h"


//--------------------------------------------------------------
// Definition of all LEDs
// Sequence as LED_NAME_t
//
// Init : [LED_OFF,LED_ON]
//--------------------------------------------------------------
LED_t LED[] = {
  // Name    ,PORT , PIN       , CLOCK              , Init
  {LED_GREEN ,GPIOD,GPIO_Pin_12,RCC_AHB1Periph_GPIOD,LED_OFF},   // PD12=Green LED on the Discovery-Board
  {LED_ORANGE,GPIOD,GPIO_Pin_13,RCC_AHB1Periph_GPIOD,LED_OFF},   // PD13=Orange LED on the Discovery-Board
  {LED_RED   ,GPIOD,GPIO_Pin_14,RCC_AHB1Periph_GPIOD,LED_OFF},   // PD14=Red LED auf on the Discovery-Board
  {LED_BLUE  ,GPIOD,GPIO_Pin_15,RCC_AHB1Periph_GPIOD,LED_OFF},   // PD15=Blue LED on the Discovery-Board
};



//--------------------------------------------------------------
// Initiation all of LEDs
//--------------------------------------------------------------
void UB_Led_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  LED_NAME_t led_name;
  
  for(led_name=0;led_name<LED_ANZ;led_name++) {
    // Clock Enable
    RCC_AHB1PeriphClockCmd(LED[led_name].LED_CLK, ENABLE);

    // Configuration of all Digital Output
    GPIO_InitStructure.GPIO_Pin = LED[led_name].LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED[led_name].LED_PORT, &GPIO_InitStructure);

    // Default settings
    if(LED[led_name].LED_INIT==LED_OFF) {
    	 UB_Led_Off(led_name);
    }
    else {
    	UB_Led_On(led_name);
    }
  }
}


//--------------------------------------------------------------
// Turn off LED
//--------------------------------------------------------------
void UB_Led_Off(LED_NAME_t led_name)
{
  LED[led_name].LED_PORT->BSRRH = LED[led_name].LED_PIN;
}

//--------------------------------------------------------------
// Turn on LED
//--------------------------------------------------------------
void UB_Led_On(LED_NAME_t led_name)
{
  LED[led_name].LED_PORT->BSRRL = LED[led_name].LED_PIN;
} 

//--------------------------------------------------------------
// LED toggle
//--------------------------------------------------------------
void UB_Led_Toggle(LED_NAME_t led_name)
{
  LED[led_name].LED_PORT->ODR ^= LED[led_name].LED_PIN;
}

//--------------------------------------------------------------
// LED Switch on or off
//--------------------------------------------------------------
void UB_Led_Switch(LED_NAME_t led_name, LED_STATUS_t wert)
{
  if(wert==LED_OFF) {
    UB_Led_Off(led_name);
  }
  else {
    UB_Led_On(led_name);
  }
}
