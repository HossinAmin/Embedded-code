/* main.c
 * Created: 31-Mar-21 8:24:11 PM
 * Author : Alhossin Mohamed*/ 
#include "microwave.h"

int main(void)
{
	//Initializing variables
	uint8 data = '\0';		//char coming from KP
	pos = M2_POS;			//cursor position 
	inputTime.MM=0;			//minutes
	inputTime.SS=0;			//seconds
	rotDir=False;			//rotation direction
	
	//Initializing hardware.
	LCD_init();
	KP_init();
	plate_init();
	
	
	//User instructions.
	LCD_sendString("Welcome :)");
	_delay_ms(1000);
	
	//Sounds and lights indicating the device is on.
	playSound();
	Redlight(LOW);
	Greenlight(HIGH);
			
	clearTime();
	
	//start program
    while (1) 
    {
		//getting input data from keypad
		data = KP_getKey();
		
		//checking keypad input
		if (data=='/')//F1	clear
		{
			clearTime();
		}
		else if (data=='c')//Start
		{
			//Enable external interrupt
			extInterruptEN(True);
			//Alert user using lights
			Redlight(HIGH);
			Greenlight(LOW);
			//Start moving plate
			plate_move(rotDir,100);
			//Start count down
			while (!(inputTime.MM == 0 && inputTime.SS == 0))
			{
				decTime();
				printTime();
				_delay_ms(990);
			}
			clearTime();//assuming the interrupt was never triggered
			//Stop plate rotation
			plate_stop();			
			//playing sounds and lights to alert the user
			Redlight(LOW);
			Greenlight(HIGH);
			playSound();

			//Disable external interrupt
			extInterruptEN(False);
			//Bounce "change rotation direction every time"
			rotDir ^= 1;
		}
		else if (data=='=')//defrost
		{
			//Enable external interrupt
			extInterruptEN(True);
			//Alert user using lights
			Redlight(HIGH);
			Greenlight(LOW);
			//Start moving plate
			plate_move(rotDir,100);
			//Start count down
			while (!(inputTime.MM == 0 && inputTime.SS == 0))
			{
				decTime();
				printTimeDeforst();
				_delay_ms(990);
			}
			clearTime();//assuming the interrupt was never triggered
			//Stop plate rotation
			plate_stop();
			//playing sounds and lights to alert the user
			Redlight(LOW);
			Greenlight(HIGH);
			playSound();
			//Disable external interrupt
			extInterruptEN(False);
			//Bounce "change rotation direction every time"
			rotDir ^= 1;			
			
		}
		//all this inputs do nothing
		else if (data=='*'){}//F2
		else if (data=='-'){}//F3
		else if (data=='+'){}//F4
		else//all numbers and NULL
		{
			
			if ((pos==M2_POS || pos==S2_POS	)&& data != '\0')
			{
				if (data-48>=6)//seconds and minutes must not exceed 60
				{
					//do nothing
				}
				else
				{
					LCD_sendData(data);
					readTime(data);
					pos++;
				}
			}
			else if (pos == Dot_POS)
			{
				pos++;
				LCD_GotoXY(pos,0);
			}
			else if(pos != Dot_POS && pos <= S1_POS && data != '\0')
			{
				LCD_sendData(data);
				readTime(data);
				pos++;
			}
			else
			{
				//do nothing
			}
		}
		
	}
	
	
	
}


ISR (INT0_vect)
{
	clearTime();	
}