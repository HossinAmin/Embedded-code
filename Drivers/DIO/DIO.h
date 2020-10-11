#ifndef DIO_H_
#define DIO_H_

//files i need
#include "../Headers/Register.h"
#include "../Headers/myTypes.h"
#include "../Headers/BitMath.h"

//my macros
#define HIGH 1
#define LOW  0

#define IN  0
#define OUT 1

//functions
void setPinDir(char port,uint8 pin,Bool dir);
void setPinVal(char port,uint8 pin,Bool state);

void setPortDir(char port,Bool dir);
void setPortVal(char port,uint8 val);

Bool getPinVal(char port,uint8 pin);//checks weather a certain pin is on or off and returns a boolean
uint8 getPortVal(char port);//returns the whole port

void setLowNibDir(char port,Bool dir);
void setHighNibDir(char port,Bool dir);

void setLowNibVal(char port,uint8 val);
void setHighNibVal(char port,uint8 val);







#endif /* DIO_H_ */