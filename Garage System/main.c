#include "USART/USART.h"
#include "LCD/LCD.h"
#include "KP/KP.h"
#include "Door/Door.h"
#include <avr/interrupt.h>

//defining maximum size of password
#define PasswordMaxLen	8

//defining indicators port and pins
#define LEDport		   'd'
#define RedLED			5
#define GreenLED		6
#define YellowLED		7

//function prototypes
Bool checkPass(char pass[]);
void clearBuffer(char Buffer[]);
void clearPassDisp();
Bool checkQuit(char Buffer[]);

//global variable
const char password[PasswordMaxLen] = "1234";
char  inputChar = '\n';
char  inputBuffer[PasswordMaxLen];
uint8 BufferCounter = 0 ;

int main()
{
	//initializing hardware
	setPinDir(LEDport,RedLED,OUT);
	setPinDir(LEDport,GreenLED,OUT);
	setPinDir(LEDport,YellowLED,OUT);
	
	initDoor();
	LCD_init();
	KP_init();
	
	//initializing communication
	sei();
	USART_init();
	
	//Print user instructions
	LCD_sendString("Enter Password:");
	_delay_ms(5);
	LCD_sendCom(LCD_BEGIN_AT_SECOND_RAW);
	
	//main loop
	while(1)
	{	
		//Enable receiver interrupt
		USART_setInterruptRxEable(True);
		
		//getting Keypad input
		inputChar = KP_getKey();
		
		//checking input
		if(inputChar == '\0')
		{
			//pass
		}
		else if (inputChar == '-')// - is F1 in my keypad
		{
			if (BufferCounter!=0)
			{
				LCD_backSpace();
				BufferCounter--;				
			}
			else
			{
				//pass
			}

		}
		else if (inputChar == '*')// * is F2 in my keypad
		{
			//checking if the password is correct
			if (checkPass(inputBuffer)==True)
			{
				setPinVal(LEDport,GreenLED,HIGH);				
				openDoor();
				_delay_ms(1500);
				setPinVal(LEDport,GreenLED,LOW);
				closeDoor();
			}
			else
			{
				//blink red LED
				setPinVal(LEDport,RedLED,HIGH);
				_delay_ms(200);
				setPinVal(LEDport,RedLED,LOW);
				_delay_ms(200);
				setPinVal(LEDport,RedLED,HIGH);
				_delay_ms(200);
				setPinVal(LEDport,RedLED,LOW);
				_delay_ms(200);
			}
			
			//clear the Buffer and LCD
			clearBuffer(inputBuffer);
			clearPassDisp();
			BufferCounter=0;
			
		}
		else
		{
			if (BufferCounter<PasswordMaxLen)
			{
				inputBuffer[BufferCounter]=inputChar;
				LCD_sendData(inputChar);
				BufferCounter++;
			}
			else
			{
				//pass
			}
		}
	}
}

ISR(USART_RXC_vect)
{
	//indicator that you are in remote access mode
	setPinVal(LEDport,YellowLED,HIGH);
	
	//clear Buffer and LCD
	BufferCounter=0;
	clearBuffer(inputBuffer);
	
	//disable interrupt so i can fill Buffer 
	USART_setInterruptRxEable(False);
	
	while (1)
	{
		while (1)
		{
			//filling Buffer with message
			while(USART_getRCflag()==0);
			if (BufferCounter<9)
			{
				inputChar=USART_reciveChar();
				if (inputChar=='\n')
				{
					break;
				}
				inputBuffer[BufferCounter]=inputChar;
				BufferCounter++;
			}
			else
			{
				break;
			}
			
		}
		
		
		//checking if the buffer is equal to the password
		if(checkPass(inputBuffer)==True)
		{
			//action to be taken if
			setPinVal(LEDport,GreenLED,HIGH);
			openDoor();
			_delay_ms(1500);
			setPinVal(LEDport,GreenLED,LOW);
			closeDoor();
			
			//clear Buffer and counter
			clearPassDisp();
			BufferCounter = 0;
			clearBuffer(inputBuffer);
			
			//indicator of exiting remote mode
			setPinVal(LEDport,YellowLED,LOW);
			break;
		}
		else if(checkQuit(inputBuffer)==True)//checks if you want to exist remote mode
		{
			//clear buffer and counter
			clearPassDisp();
			BufferCounter = 0;
			clearBuffer(inputBuffer);
			//indicator of exiting remote mode			
			setPinVal(LEDport,YellowLED,LOW);
			break;
		}
		else
		{
			//blink red LED
			setPinVal(LEDport,RedLED,HIGH);
			_delay_ms(150);
			setPinVal(LEDport,RedLED,LOW);
			_delay_ms(150);
			setPinVal(LEDport,RedLED,HIGH);
			_delay_ms(150);
			setPinVal(LEDport,RedLED,LOW);
			_delay_ms(150);
			
			//clear Buffer and counter
			clearPassDisp();
			BufferCounter = 0;
			clearBuffer(inputBuffer);
			
		}
	}
	
}

Bool checkPass(char pass[])
{
	uint8 count = 0;
	for (uint8 i = 0; i<PasswordMaxLen;i++)
	{
		if (pass[i]==password[i])
		{
			count++;
		}
	}

	if (count==PasswordMaxLen)
	{
		return True;
	}
	else
	{
		return False;
	}
}

void clearBuffer(char Buffer[])
{
	for (uint8 i = 0; i<PasswordMaxLen ; i++)
	{
		Buffer[i] = 0;
	}
}

void clearPassDisp()
{
	LCD_GotoXY(0,1);
	while(LCD_isBusy()==1);
	LCD_sendString("        ");
	LCD_GotoXY(0,1);
}

Bool checkQuit(char Buffer[])
{
	const char inst[] = "quit";
	uint8 count = 0;
	for (uint8 i = 0; i<4;i++)
	{
		if (Buffer[i]==inst[i])
		{
			count++;
		}
	}
	if (count==4)
	{
		return True;
	}
	else
	{
		return False;
	}
}