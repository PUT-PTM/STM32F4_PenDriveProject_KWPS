//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------

// lista_plikow_i_katalogow.h
//------------------------------------------------------------------------
#ifndef LISTA_PLIKOW_I_KATALOGOW_H
#define LISTA_PLIKOW_I_KATALOGOW_H

//------------------------------------------------------------------------
#include "init.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "stm32f4xx_exti.h"
#include "stm32_ub_usb_msc_host.h"
#include "stm32_ub_led.h"
//------------------------------------------------------------------------

//LFN - rozmiar nazwy pliku
char lfnBuffer[512];
char sBuffer[256];
char sBuffer2Write[1024], sBuffer2Write2[1024];

//Funkcje z pliku lista_plikow_i_katalogow.c
void lista_plikow_i_katalogow(void);

//-------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------
