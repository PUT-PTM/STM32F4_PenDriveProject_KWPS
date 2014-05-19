
//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------


// suwanie_plikow_i_katalogow.c
//------------------------------------------------------------------------

#include <usuwanie_plikow_i_katalogow.h>

// usuwanie_plikow_i_katalogow
void usuwanie_plikow_i_katalogow()
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
