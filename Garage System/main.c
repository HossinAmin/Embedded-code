#include "USART/USART.h"
#include "LCD/LCD.h"
#include "KP/KP.h"
#include "Door/Door.h"
#include <avr/interrupt.h>

//Defining maximum size of password
#define PasswordMaxLen	8

//Defining indicators port and pins
#define LEDport		   'd'
#define RedLED			5
#define GreenLED		6
#define YellowLED		7

//Defining modes
#define Remote		   'r'
#define Local		   'l'


//Function prototypes
Bool checkPass(char pass[]);
void clearBuffer(char Buffer[]);
void clearPassDisp();
Bool checkQuit(char Buffer[]);

//Global variable
const char password[PasswordMaxLen] = "1234";
uint8 accessMode = 'l';
char  inputChar = '\0';
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
		
		//Checking on mode of operation
		if (accessMode==Local)
		{
			inputChar = KP_getKey();
		}
		else
		{
			//pass
		}
		
		
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
		else if ((inputChar == '\r'))// * is F2 in my keypad
		{
			//checking if the password is correct
			if (checkPass(inputBuffer)==True)
			{
				//Blink green LED and open door
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
			
			//Turn off
			setPinVal(LEDport,YellowLED,LOW);
			
			//clear the Buffer and LCD
			inputChar = '\0';
			clearBuffer(inputBuffer);
			clearPassDisp();
			BufferCounter = 0;
			
		}
		else
		{
			//filling buffer form local access point
			if (accessMode==Local)
			{
				if (BufferCounter<PasswordMaxLen)
				{
					inputBuffer[BufferCounter]=inputChar;
					LCD_sendData(inputChar);
					BufferCounter++;
				}
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
	
	//changing access mode to remote
	accessMode = Remote;
	
	//clear Buffer and counter
	BufferCounter=0;
	clearBuffer(inputBuffer);
	
	//disable interrupt so i can fill Buffer
	USART_setInterruptRxEable(False);

	while (1)
	{
		//filling Buffer from remote access
		while(USART_getRCflag()==0);
		if (BufferCounter<9)
		{
			inputChar=USART_reciveChar();
			if (inputChar=='\r')
			{
				break;
			}
			inputBuffer[BufferCounter]=inputChar;
			BufferCounter++;
		}
		else
		{
			inputChar = '\r';
			break;
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