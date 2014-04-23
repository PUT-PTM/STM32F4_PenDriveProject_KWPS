//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32_ub_sdcard.h"



//--------------------------------------------------------------
// init der Hardware fuer die SDCard-Funktionen
// muss vor der Benutzung einmal gemacht werden
//--------------------------------------------------------------
void UB_SDCard_Init(void)
{

}


//--------------------------------------------------------------
// Check ob Medium eingelegt ist
// Return Wert :
//   > 0  = wenn Medium eingelegt ist
//     0  = wenn kein Medium eingelegt ist
//--------------------------------------------------------------
uint8_t UB_SDCard_CheckMedia(void) 
{
  uint8_t ret_wert=0;

  return(ret_wert);
}

//--------------------------------------------------------------
// init der Disk
// Return Wert :
//    0 = alles ok
//  < 0 = Fehler
//--------------------------------------------------------------
int MMC_disk_initialize(void)
{
  int ret_wert=-1;

  return(ret_wert);
}


//--------------------------------------------------------------
// Disk Status abfragen
// Return Wert :
//    0 = alles ok
//  < 0 = Fehler
//--------------------------------------------------------------
int MMC_disk_status(void)
{
  int ret_wert=-1;

  return(ret_wert);
}


//--------------------------------------------------------------
// READ-Funktion
// Return Wert :
//    0 = alles ok
//  < 0 = Fehler
//--------------------------------------------------------------
int MMC_disk_read(BYTE *buff, DWORD sector, BYTE count)
{
  int ret_wert=-1;

  return(ret_wert);
}


//--------------------------------------------------------------
// WRITE-Funktion
// Return Wert :
//    0 = alles ok
//  < 0 = Fehler
//--------------------------------------------------------------
int MMC_disk_write(const BYTE *buff, DWORD sector, BYTE count)
{
  int ret_wert=-1;

  return(ret_wert);
}


//--------------------------------------------------------------
// IOCTL-Funktion
// Return Wert :
//    0 = alles ok
//  < 0 = Fehler
//--------------------------------------------------------------
int MMC_disk_ioctl(BYTE cmd, void *buff)
{
  int ret_wert=-1;

  return(ret_wert);
}


