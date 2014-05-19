//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------

// menu.h
//------------------------------------------------------------------------
#ifndef MENU_H
#define MENU_H

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
#include "usuwanie_plikow_i_katalogow.h"
#include "lista_plikow_i_katalogow.h"
//------------------------------------------------------------------------


//Funkcje z pliku funkcje.c
void menu(void);

//-------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------
