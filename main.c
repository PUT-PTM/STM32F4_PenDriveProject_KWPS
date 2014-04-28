//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------

#include "main.h"


//////////////////////////////////////////////////
//Biblioteki do obs�ugi usb wyci�te (Grzej� p�ytk�) !!!!
/////////////////////////////////////////////////


////#PL# G��wna funkcja w programie
////#ENG#  Main function in program
int main(void)
{
//
//	uint8_t write_ok = 0;
//
//	FRESULT res;
//	char *path = "";
//
//	char *fn; // #PL# Zak�adamy, �e funkcja jest traktowana jako non-Unicode cfg.
//			  // #ENG# This function is assuming non-Unicode cfg.
//
//
//
//	//#PL#  inicjalizacja CPU
//	//#ENG# initiation of CPU
//
//	SystemInit();
//
//
//	//#PL#  inicjalizacja LED
//	//#ENG#  initiation of LED
//	 UB_Led_Init ( );
//
//
////===============================================================================================================
////===============================================================================================================
//
////#PL# G��wna p�tla w programie
////#ENG#  Main loop in program
//    while(1)
//    {
//    	if(/* warunek poprawno�ci po��czenia usb  */)
//    	{
//    		//#PL# Sprawdzenie w warunku poprawno�ci po��czenia
//    		//#ENG# Validation of connections in condition
//    		UB_Led_On(LED_GREEN);
//    		UB_Led_On(LED_RED);
//
//    		//#PL# Je�el zapisy s� poprawne to dzia�amy dalej
//    		//#ENG# If all is ok we go to the next condition.
//
//    		if ( write_ok == 0 )
//    		{
//    			write_ok = 1; //#PL# W trakcie zapisu �wieci pomara�czowa dioda
//    						  //#ENG# While writing orange LED shines
//    			UB_Led_On(LED_ORANGE);
//
//    			//#PL# Teraz montujemy pendrive
//    			//#ENG# Now we mounting PenDrive
//    			if (/* Sprawdzenie czy pendrive jest zamontowany  */)
//    			{
//    				// Pozostaje otwarcie pliku i i r�ne operacje na urz�dzeniu
//
//
//    	    		//=================================================================
//    	    		//=================================================================
//
//    				//#PL# Gdzie� tu na ko�cu odmontowanie pendrive
//    				//#ENG# Here should be unmount of PenDrive
//    			//UNMount function
//
//    	    		//=================================================================
//    	    		//=================================================================
//    			}//if
//
//    			//#PL# Na koniec operacji gaszenie pomara�czowej lampki.
//    			//#ENG# At the end of operation we shot down orange LED.
//    			UB_Led_Off(LED_ORANGE);
//			}
//
//    		//#PL# Niebieska dioda �wieci po zako�czeniu operacji.
//    		//#ENG# While blue LED shining we knows that operation is ended.
//    		UB_Led_On(LED_BLUE);
//
//    		//=================================================================
//    		//=================================================================
//    		// tu trzeba co zrobi� by podtrzyma� wiecenie niebieskiej diody i czeka� na reset
//
//    	}//if
//
//    	else
//    	{
//    		//#PL# W razie b��d�w za�wiecenie diody czerwonej i zgaszenie zielonej
//    		//#ENG# If we have some errors with our device we turn on red LED and turn of green LED.
//    		UB_Led_Off ( LED_GREEN );
//    		UB_Led_On ( LED_RED );
//		}//else
//    }//while

	usuwanie_plikow();  // wywo�anie funkcji odpowiedzialnej za usuwanie plik�w // bez katalog�w.

}//main
