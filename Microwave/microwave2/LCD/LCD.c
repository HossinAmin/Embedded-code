#include "LCD.h"

void ENB_pulse()
{
	DIO_setPinVal(LCD_CP,LCD_EN,HIGH);
	_delay_us(100);
	DIO_setPinVal(LCD_CP,LCD_EN,LOW);
}

void LCD_init()
{	
	DIO_setPinDir(LCD_CP,LCD_EN,OUT);
	DIO_setPinDir(LCD_CP,RS,OUT);
	DIO_setPinDir(LCD_CP,RW,OUT);
	
	DIO_setHighNibDir(LCD_DP,OUT);
	
	DIO_setPinVal(LCD_CP,RS,LOW);
	DIO_setPinVal(LCD_CP,RW,LOW);
	
	//initialization 4 bit
	
 	LCD_sendCom(0x33);
 	LCD_sendCom(0x32);
	
	_delay_ms(30);
	LCD_sendCom(LCD_FUNC_SET_4BIT_2LINES);
	_delay_us(39);	
	LCD_sendCom(LCD_DISP_ON_CURSOR_BLINK);
	_delay_us(39);
	LCD_sendCom(0x01);//clear display
	_delay_ms(1.53);
	LCD_sendCom(LCD_ENTRY_INC_);


}

void LCD_sendCom(char com)
{
	DIO_setPinVal(LCD_CP,RS,LOW);
	DIO_setPinVal(LCD_CP,RW,LOW);
	
	DIO_setHighNibVal(LCD_DP,com>>4);
	ENB_pulse();
	DIO_setHighNibVal(LCD_DP,com);
	ENB_pulse();
	
}

void LCD_sendData(char data)
{
	
	DIO_setPinVal(LCD_CP,RS,HIGH);
	DIO_setPinVal(LCD_CP,RW,LOW);
	
	DIO_setHighNibVal(LCD_DP,data>>4);
	ENB_pulse();
	DIO_setHighNibVal(LCD_DP,data);
	ENB_pulse();

}

Bool LCD_isBusy()
{
	//setting high nibble to input
	DIO_setHighNibDir(LCD_DP,IN);
	
	uint8 state=0;
	DIO_setPinVal(LCD_CP,RS,LOW);
	DIO_setPinVal(LCD_CP,RW,HIGH);
	
	//reading high 4 bits
	DIO_setPinVal(LCD_CP,LCD_EN,HIGH);
	state = DIO_getHighNibVal(LCD_DP);
	_delay_us(50);
	DIO_setPinVal(LCD_CP,LCD_EN,LOW);
	
	//dummy read
	DIO_setPinVal(LCD_CP,LCD_EN,HIGH);
	_delay_us(50);
	DIO_setPinVal(LCD_CP,LCD_EN,LOW);
	
	//setting high nibble to output
	DIO_setHighNibDir(LCD_DP,OUT);
	
	state=state>>3;
	return state;
}
void LCD_clearDisplay()
{
	LCD_sendCom(0x01);
}

void LCD_sendString(char *str)
{
	uint8 i=0;
	while (str[i]!='\0')
	{
		LCD_sendData(str[i]);
		i++;
		if(i==16)
		{
			LCD_sendCom(LCD_BEGIN_AT_SECOND_RAW);
		}
	}
	
}

void LCD_sendNum(uint16 num)
{
	int counter = 1;
	int x = 10;
	
	while (num/x != 0)
	{
		counter++;
		x *= 10;
		
	}
	
	for (int i = 0; i < counter; i++)
	{
		LCD_sendData((num%x)/(x/10)+48);
		x /= 10;
	}
}

void LCD_sendFloat(float num)
{
	uint16 befPoint = (uint16)num;
	float aftPoint = (float)(num-befPoint)*10000;
	LCD_sendNum(befPoint);
	LCD_sendData('.');
	LCD_sendNum(aftPoint); 
}

void LCD_GotoXY(uint8 x,uint8 y)
{
	if(y==0)
	{
		LCD_sendCom(LCD_BEGIN_AT_FIRST_RAW);
		for(uint8 i=0;i<x;i++)
		{
			LCD_sendCom(LCD_MOVE_CURSOR_RIGHT);
			
		}
	}
	else
	{
		LCD_sendCom(LCD_BEGIN_AT_SECOND_RAW);
		for(uint8 i=0;i<x;i++)
		{
			LCD_sendCom(LCD_MOVE_CURSOR_RIGHT);
			
		}
	}
}

void LCD_backSpace()
{
	LCD_sendCom(LCD_MOVE_CURSOR_LEFT);
  	LCD_sendData(' ');
  	LCD_sendCom(LCD_MOVE_CURSOR_LEFT);
}

uint8 LCD_createChar(char C[])
{
	static uint8 CGRAM_add = 0x00;
	LCD_sendCom(0x40+CGRAM_add);//set CGRAM and load AC with "CGRAM_add"
	_delay_ms(5);
	for(uint8 i=0;i<8;i++)
	{
		LCD_sendData(C[i]);
	}
	LCD_sendCom(0x80);// set CGRAM and load AC with 0x00
	_delay_ms(5);
	uint8 DDRAM_add = (CGRAM_add/0x07);
	CGRAM_add+=0x07;
	return DDRAM_add;
}