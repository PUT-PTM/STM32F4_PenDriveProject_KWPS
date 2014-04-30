#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "stm32f4xx_exti.h"
#include "stm32_ub_usb_msc_host.h"
#include "stm32_ub_led.h"
#include "funkcje.h"



char lfnBuffer[512];
char sBuffer[256];
char sBuffer2Write[1024];


void usuwanie_plikow(void)
{


	FILINFO fno;
	DIR dir;

  uint8_t write_ok = 0;

  FRESULT res;
  char *path="";
  char *fn; // This function is assuming non-Unicode cfg.

  SystemInit ( );
  UB_Led_Init ( );
  UB_USB_MSC_HOST_Init ( );



  fno.lfname = lfnBuffer;
  fno.lfsize = sizeof ( lfnBuffer );
  unsigned int counter =0;
  while ( counter<5000000 )
  {

    if ( UB_USB_MSC_HOST_Do ( ) == USB_MSC_DEV_CONNECTED )
    { // Sprawdzenie poprawnsoci po³¹czenia
      UB_Led_On ( LED_GREEN );
      UB_Led_Off ( LED_RED );

      // Je¿eli zapisy s¹ poprawne to:
      if ( write_ok == 0 )
      {
       	write_ok = 1; // W trakcie zapisu wieci pomarañczowa dioda.
       	UB_Led_On ( LED_ORANGE );

       	if ( UB_Fatfs_Mount ( USB_0 ) == FATFS_OK ) // Montowanie pendraiva
       	{


    		res = f_opendir(&dir, path); // Open the directory
    		if (res == FR_OK)
    		{
			  for (;;)
			  {
				res = f_readdir(&dir, &fno); // Read a directory item
				if (res != FR_OK || fno.fname[0] == 0)
				  break; // Break on error or end of dir

#if _USE_LFN
				fn = *fno.lfname ? fno.lfname : fno.fname;
#else
				fn = fno.fname;
#endif

				f_unlink(fn);
			  } // for


    		} // if



          // Odmontowanie usb po wykonaniu akcji
          UB_Fatfs_UnMount ( USB_0 );
        } // if

        UB_Led_Off ( LED_ORANGE );
      } // Kiedy koniec operacji gaszenie ¿ó³tej lampki

      // stop
      UB_Led_On ( LED_BLUE );
      //mozna tu dac jakies opoznienie
      counter=5000001;
    } // if
    else
    { // W razie b³êdów zawiecenie diody czerwone i zgaszenie zielonej
        UB_Led_Off ( LED_GREEN );
        UB_Led_On ( LED_RED );
        //tu trzeba dac jakies opoznienie
        counter++;
    } // else
  } // while
} // main



















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
		}
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

		}
		else if(p<7500000)//RED
		{

		}
		else if(p<10000000)//BLUE
		{

		}

	}
}






