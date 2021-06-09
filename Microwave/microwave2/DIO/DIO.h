#ifndef DIO_H_
#define DIO_H_

//Files I need
#include <avr/io.h>
#include "../Headers/myTypes.h"
#include "../Headers/BitMath.h"


//My MACROS
#define HIGH 1
#define LOW  0

#define IN  0
#define OUT 1

//Functions
/* if you choose a port that does exist the default port to every function is portD */

void DIO_setPinDir(char port,uint8 pin,Bool dir);		//sets pin direction to in or out
void DIO_setPinVal(char port,uint8 pin,Bool state);		//sets pin value to high or low

void DIO_setPortDir(char port,Bool dir);
void DIO_setPortVal(char port,uint8 val);

Bool DIO_getPinVal(char port,uint8 pin);				//returns the pin value high or low
uint8 DIO_getPortVal(char port);						//returns the whole port value

void DIO_setLowNibDir(char port,Bool dir);				//sets direction of lower half of port
void DIO_setHighNibDir(char port,Bool dir);				//sets direction of higher half of port

void DIO_setLowNibVal(char port,uint8 val);				//sets value of lower half of port
void DIO_setHighNibVal(char port,uint8 val);			//sets value of higher half of port

uint8 DIO_getLowNibVal(char port);						//returns value of lower half of port
uint8 DIO_getHighNibVal(char port);						//returns value of higher half of port





#endif /* DIO_H_ */