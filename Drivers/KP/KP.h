#ifndef INCFILE1_H_
#define INCFILE1_H_
//headers
#include "../DIO/DIO.h"
#define F_CPU 16000000ul
#include <util/delay.h>

//keypad dimensions 

#define KPPort 'b'

//functions
void KP_init();
char KP_getKey();




#endif