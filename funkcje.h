//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------

// funkcje.h
//------------------------------------------------------------------------
#ifndef FUNKCJE_H
#define FUNKCJE_H

//Biblioteki standardowe:
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

//Biblioteki z funkcjami do obs³ugi pamiêci masowej:
//------------------------------------------------------------------------
#include "usuwanie_plikow.h"
#include "lista_plikow.h"
//------------------------------------------------------------------------


//Funkcje z pliku funkcje.c
void menu(void);

//-------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------
