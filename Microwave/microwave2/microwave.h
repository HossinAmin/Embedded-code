#ifndef MICOWAVE_H_
#define MICOWAVE_H_

#include <avr/interrupt.h>
#include "LCD/LCD.h"
#include "KP/KP.h"
#include "Plate/plate.h"

//Macros
#define LEDPort		'a'
#define REDLED		 2
#define GRELED		 1

#define BuzzerPort		'a'
#define BuzzerPin		 3


#define M2_POS		7
#define M1_POS		8
#define Dot_POS		9
#define S2_POS		10
#define S1_POS		11

//Defining global variables
typedef struct
{
	uint8 SS;
	uint8 MM;
}Time_MM_SS;

Time_MM_SS inputTime;
uint8 pos;
Bool rotDir;

//Indicators functions (sounds and lights)
void playSound();
void Greenlight(Bool state);
void Redlight(Bool state);

//Time functions
void readTime(uint8 data);
void decTime();
void printTime();
void printTimeDeforst();
void clearTime();

//interrupt enable
void extInterruptEN(Bool state);

#endif /* MICOWAVE_H_ */