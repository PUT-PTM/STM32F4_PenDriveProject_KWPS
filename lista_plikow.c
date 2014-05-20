//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------


// lista_plikow.c
//------------------------------------------------------------------------

#include "lista_plikow_i_katalogow.h"

// lista_plikow
void lista_plikow(void)
{

	FILINFO fno;
	DIR dir;
	FIL myFile;
	uint8_t write_ok = 0;

  FRESULT res;
  char *path="";
  char *fn;

  SystemInit ( );
  UB_Led_Init ( );
  UB_USB_MSC_HOST_Init ( );
  fno.lfname = lfnBuffer;
  fno.lfsize = sizeof ( lfnBuffer );
unsigned int counter = 0;
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
          if ( UB_Fatfs_OpenFile ( &myFile, "USB_File_LIST.txt", F_WR_CLEAR ) == FATFS_OK )
          { //Poprawne utworzenie pliku
              //Zapisywanie do pliku danych
  	UB_Fatfs_WriteString ( &myFile, "\t\tSzczap Piotr i Witkowski Konrad \n   		\t  PREZENTUJ¥\n" );
      UB_Fatfs_WriteString ( &myFile, "		STM32F4_PenDriveProject_KWPS\n" );
      UB_Fatfs_WriteString ( &myFile, "\n		 Program nr.3 Lista plików\n" );

            UB_Fatfs_WriteString ( &myFile, "NAZWY PLIKÓW\t Rozmiar[KB]\t katalog/plik\n\n" );

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

				//
				if ( !(fno.fattrib & AM_DIR) )
				{
					sprintf ( sBuffer, "%s/%s\t%lu plik\n", path, fn, fno.fsize );
				  strcat ( sBuffer2Write, sBuffer );
				} // if

			  } // for


              UB_Fatfs_WriteString ( &myFile, sBuffer2Write );
    		} // if


            UB_Fatfs_CloseFile ( &myFile );
          } // if


          UB_Fatfs_UnMount ( USB_0 );
        } // if

        UB_Led_Off ( LED_ORANGE );
      } // Kiedy koniec operacji gaszenie ¿ó³tej lampki

      // stop
      UB_Led_On ( LED_BLUE );
      counter = 5000001;

    } // if
    else
    { // W razie b³êdów zawiecenie diody czerwone i zgaszenie zielonej
        UB_Led_Off ( LED_GREEN );
        UB_Led_On ( LED_RED );
        counter ++;
    }
  }
}
