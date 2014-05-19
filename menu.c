//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------

// menu.c
//------------------------------------------------------------------------

#include "menu.h"
// Menu

void menu(void)
{

	SystemInit ( );
	UB_Led_Init ( );
	initButton();
	while(1){

		UB_Led_Off(LED_GREEN);
		UB_Led_Off(LED_RED);
		UB_Led_Off(LED_ORANGE);
		UB_Led_Off(LED_BLUE);
	unsigned int p=0;
		while(!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
		{
			p++;
			if(p==1)
			{
				UB_Led_On ( LED_GREEN );
				UB_Led_Off(LED_BLUE);
			}
			if(p==2500000)
			{
				UB_Led_On ( LED_ORANGE );
				UB_Led_Off(LED_GREEN);
			}
			if(p==5000000)
			{
				UB_Led_On ( LED_RED );
				UB_Led_Off(LED_ORANGE);
			}
			if(p==7500000)
			{
				UB_Led_On ( LED_BLUE );
				UB_Led_Off(LED_RED);
			}
			if(p==10000000)
				p=0;
		}//while(!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))

		UB_Led_Off(LED_GREEN);
		UB_Led_Off(LED_RED);
		UB_Led_Off(LED_ORANGE);
		UB_Led_Off(LED_BLUE);

		if(p<2500000)//GREEN
		{
			usuwanie_plikow();
		}
		else if(p<5000000)//ORANGE
		{
			lista_plikow();
		}
		else if(p<7500000)//RED
		{

		}
		else if(p<10000000)//BLUE
		{

		}

	}// while(1)
}// menu
