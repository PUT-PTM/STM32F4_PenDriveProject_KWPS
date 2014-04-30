//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------


//------------------------------------------------------------------------
#ifndef MAIN_H
#define MAIN_H
//------------------------------------------------------------------------

#include <stdio.h>
#include<string.h>
#include "stm32f4xx.h"

///////////////////////////////////////////////////

//////////////////////////////////////////////////
#include "stm32_ub_led.h"
#include "stm32_ub_usb_msc_host.h"
///////////////////////////////////////////////////
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
///////////////////////////////////////////////////


//#PL# Zmienne globalne do obs³ugi// deklarowane ni¿ej w poszczegolnych funkcjach
//#ENG# Main variables
//static FILINFO fno;
//static DIR dir;
//static FIL myFile;
//
//char lfnBuffer[512];
//
//char sBuffer[256];
//char sBuffer2Write[1024];
//



void usuwanie_plikow(void)
{


	FILINFO fno;
	DIR dir;


  uint8_t write_ok = 0;

  FRESULT res;
  char *path="";
  char *fn; // #PL# Zak³adamy, ¿e funkcja jest traktowana jako non-Unicode cfg.
  	  	  	  // #ENG# This function is assuming non-Unicode cfg.


  //	//#PL#  inicjalizacja CPU
  //	//#ENG# initiation of CPU
  SystemInit ( );

  //	//#PL#  inicjalizacja LED
  //	//#ENG#  initiation of LED
  UB_Led_Init ( );

  //  inicjacja usb jako HOST
  UB_USB_MSC_HOST_Init ( );

  // LFN - rozmiar nazwy pliku
  char lfnBuffer[512];
  fno.lfname = lfnBuffer;
  fno.lfsize = sizeof ( lfnBuffer );

  while ( 1 )
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
				if (fno.fname[0] == '.')
				  continue; // Ignore dot entry
#if _USE_LFN
				fn = *fno.lfname ? fno.lfname : fno.fname;
#else
				fn = fno.fname;
#endif

				//
				if ( !(fno.fattrib & AM_DIR) )
				{
					f_unlink(fn);
				} // if
			  } // for
    		} // if

          // Odmontowanie usb po wykonaniu akcji
          UB_Fatfs_UnMount ( USB_0 );
        } // if

        UB_Led_Off ( LED_ORANGE );
      } // Kiedy koniec operacji gaszenie ¿ó³tej lampki

      // stop
      UB_Led_On ( LED_BLUE );




      ////////////////////////////////////
      ///////////////////////////////////    TU POTRZEBNA ZMIANA/ale nie teraz
      ///////////////////////////////////
      while ( 1 ); // pentla nieskoñczona po wykonaniu operacji mo¿liwy reset
      ////////////////////////////////////
      //////////////////////////////////
      ///////////////////////////////////



    } // if
    else
    { // W razie b³êdów zawiecenie diody czerwone i zgaszenie zielonej
        UB_Led_Off ( LED_GREEN );
        UB_Led_On ( LED_RED );
    } // else
  } // while
} // main








//-------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------
