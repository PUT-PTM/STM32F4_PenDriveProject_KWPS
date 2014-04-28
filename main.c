//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------

#include "main.h"


//////////////////////////////////////////////////
//Biblioteki do obs³ugi usb wyciête (Grzej¹ p³ytkê) !!!!
/////////////////////////////////////////////////


////#PL# G³ówna funkcja w programie
////#ENG#  Main function in program
int main(void)
{
//
//	uint8_t write_ok = 0;
//
//	FRESULT res;
//	char *path = "";
//
//	char *fn; // #PL# Zak³adamy, ¿e funkcja jest traktowana jako non-Unicode cfg.
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
////#PL# G³ówna pêtla w programie
////#ENG#  Main loop in program
//    while(1)
//    {
//    	if(/* warunek poprawnoœci po³¹czenia usb  */)
//    	{
//    		//#PL# Sprawdzenie w warunku poprawnoœci po³¹czenia
//    		//#ENG# Validation of connections in condition
//    		UB_Led_On(LED_GREEN);
//    		UB_Led_On(LED_RED);
//
//    		//#PL# Je¿el zapisy s¹ poprawne to dzia³amy dalej
//    		//#ENG# If all is ok we go to the next condition.
//
//    		if ( write_ok == 0 )
//    		{
//    			write_ok = 1; //#PL# W trakcie zapisu œwieci pomarañczowa dioda
//    						  //#ENG# While writing orange LED shines
//    			UB_Led_On(LED_ORANGE);
//
//    			//#PL# Teraz montujemy pendrive
//    			//#ENG# Now we mounting PenDrive
//    			if (/* Sprawdzenie czy pendrive jest zamontowany  */)
//    			{
//    				// Pozostaje otwarcie pliku i i ró¿ne operacje na urz¹dzeniu
//
//
//    	    		//=================================================================
//    	    		//=================================================================
//
//    				//#PL# Gdzieœ tu na koñcu odmontowanie pendrive
//    				//#ENG# Here should be unmount of PenDrive
//    			//UNMount function
//
//    	    		//=================================================================
//    	    		//=================================================================
//    			}//if
//
//    			//#PL# Na koniec operacji gaszenie pomarañczowej lampki.
//    			//#ENG# At the end of operation we shot down orange LED.
//    			UB_Led_Off(LED_ORANGE);
//			}
//
//    		//#PL# Niebieska dioda œwieci po zakoñczeniu operacji.
//    		//#ENG# While blue LED shining we knows that operation is ended.
//    		UB_Led_On(LED_BLUE);
//
//    		//=================================================================
//    		//=================================================================
//    		// tu trzeba co zrobiæ by podtrzymaæ wiecenie niebieskiej diody i czekaæ na reset
//
//    	}//if
//
//    	else
//    	{
//    		//#PL# W razie b³êdów zaœwiecenie diody czerwonej i zgaszenie zielonej
//    		//#ENG# If we have some errors with our device we turn on red LED and turn of green LED.
//    		UB_Led_Off ( LED_GREEN );
//    		UB_Led_On ( LED_RED );
//		}//else
//    }//while

	usuwanie_plikow();  // wywo³anie funkcji odpowiedzialnej za usuwanie plików // bez katalogów.

}//main
