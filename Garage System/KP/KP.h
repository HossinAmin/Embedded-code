#ifndef INCFILE1_H_
#define INCFILE1_H_
//headers
#include "../DIO/DIO.h"
#ifndef F_CPU
#define F_CPU 16000000ul
#endif
#include <util/delay.h>

//keypad dimensions 

#define KPPort 'c'

//functions
void KP_init();
char KP_getKey();




#endif