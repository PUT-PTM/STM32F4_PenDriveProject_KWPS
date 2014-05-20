//------------------------------------------------------------------------
// Authors: Konrad Witkowski  &  Piotr Szczap
//------------------------------------------------------------------------

// funkcje.c
//------------------------------------------------------------------------

#include "funkcje.h"

void czysc(){
	int var;
	for (var = 0; var < 1024; ++var) {
		 sBuffer2Write[var]=sBuffer2Write2[var];
	}
}
