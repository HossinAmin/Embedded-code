#ifndef _7SEG_H_
#define _7SEG_H_

#include "../DIO/DIO.h"
#define F_CPU  16000000ul
#include <util/delay.h>

#define DP 'A'//data port

#define CP 'B'//control port 

//in control port
#define EN2 2 
#define EN1 1
#define DIP 3


void init_7Seg();

void setEB1_7Seg(Bool state);
void setEB2_7Seg(Bool state);

void displaySingleDig_7Seg(uint8 num);

//the number will appear only if you keep calling the function (put it in a loop)
void displayDoubleDig_7Seg(char *num);

#endif