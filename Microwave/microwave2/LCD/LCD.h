#ifndef LCD_H_
#define LCD_H_

#include "../DIO/DIO.h"
#define F_CPU 16000000ul
#include <util/delay.h>

#define LCD_CP 'B' //LCD Control Port 
#define LCD_DP 'A' //LCD Date Port

//In CP
//lower nibble of the control Port
#define RS 1
#define RW 2
#define LCD_EN 3

//In DP
//higher nibble in data port
#define D4 4
#define D5 5
#define D6 6
#define D7 7


#define LCD_FUNC_SET_4BIT_2LINES   					(0x28)
#define LCD_FUNC_SET_4BIT_1LINE 					(0x22)

#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)

#define LCD_DISP_ON   								(0x0C)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_CLEAR_DISP								(0x01)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)


//Triggers the enable of LCD with a pulse
void ENB_pulse ();

//initialize LCD
void LCD_init();
//sends commands to the LCD
void LCD_sendCom(char com);
//sends on char to the LCD
void LCD_sendData(char data);
//checks if LCD is busy
Bool LCD_isBusy();
//clears your display
void LCD_clearDisplay();
//displays a string on LCD
void LCD_sendString(char *s);
//displays a number on LCD
void LCD_sendNum(uint16 num);
//displays a float on LCD
void LCD_sendFloat(float num);
//moves cursor to (x,y) location on the LCD
void LCD_GotoXY(uint8 x,uint8 y);
//removes on char from LCD
void LCD_backSpace();
//creates a custom char and returns it location so you can make it appear on the LCD
uint8 LCD_createChar(char C[]);






#endif /* LCD_H_ */