//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------

#include <stdio.h>
#include<string.h>
#include "stm32f4xx.h"

///////////////////////////////////////////////////
#include "ff.c"
//////////////////////////////////////////////////

///////////////////////////////////////////////////
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
///////////////////////////////////////////////////

//////////////////////////////////////////////////
//Biblioteki do obs�ugi usb wyci�te (Grzej� p�ytk�) !!!!
/////////////////////////////////////////////////

//Zmienne globalne do obs�ugi
static FILINFO fno;
static DIR dir;
static FIL myFile;

char lfnBuffer[512];

char sBuffer[256];
char sBuffer2Write[1024];

int main(void)
{

	//uint8_t write_ok = 0;

	FRESULT res;
	char *path = "";
	char *fn; // This function is assuming non-Unicode cfg.

	// � CPU
	SystemInit();



    while(1)
    {
    }
}
