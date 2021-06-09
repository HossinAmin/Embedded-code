#include "microwave.h"

void playSound()
{
	DIO_setPinDir(BuzzerPort,BuzzerPin,OUT);
	
	for (uint8 i = 0;i<3;i++)
	{
		DIO_setPinVal(BuzzerPort,BuzzerPin,HIGH);
		_delay_ms(110);
		DIO_setPinVal(BuzzerPort,BuzzerPin,LOW);
		_delay_ms(110);
	}
}

void Greenlight(Bool state)
{
	DIO_setPinDir(LEDPort,GRELED,OUT);
	DIO_setPinVal(LEDPort,GRELED,state);
}

void Redlight(Bool state)
{
	DIO_setPinDir(LEDPort,REDLED,OUT);
	DIO_setPinVal(LEDPort,REDLED,state);
}

void readTime(uint8 data)
{
	if (pos == M2_POS)
	{
		inputTime.MM += (data-48)*10;
	}
	else if (pos == M1_POS)
	{
		inputTime.MM += (data-48);
	}
	else if (pos == S2_POS)
	{
		inputTime.SS += (data-48)*10;
	}
	else if (pos == S1_POS)
	{
		inputTime.SS += (data-48);
	}
}

void decTime()
{
	if (inputTime.SS>0)
	{
		inputTime.SS--;
	}
	else if(inputTime.SS==0)
	{
		inputTime.MM--;
		inputTime.SS=59;
	}
	else
	{
		//do nothing
	}
}

void printTime()
{
	LCD_GotoXY(M2_POS,0);
	LCD_sendString("     ");
	LCD_GotoXY(M2_POS,0);
	LCD_sendNum(inputTime.MM);
	LCD_sendData(':');
	LCD_sendNum(inputTime.SS);

}

void printTimeDeforst()
{
	LCD_GotoXY(M2_POS,0);
	LCD_sendString("     ");
	LCD_GotoXY(M2_POS,0);
	LCD_sendNum(inputTime.MM);
	LCD_sendData(':');
	LCD_sendNum(inputTime.SS);
	LCD_sendString("  *");
}

void clearTime()
{
	
	LCD_clearDisplay();
	while(LCD_isBusy());
	pos = M2_POS;
	LCD_sendString("Time = 00:00");
	LCD_GotoXY(pos,0);
	inputTime.MM=0;
	inputTime.SS=0;
}

void extInterruptEN(Bool state)
{
	sei();//Enable Global Interrupt
	DIO_setPinDir('d',2,IN);
	//Trigger INT0 on rising edge
	ON(MCUCR,ISC01);
	ON(MCUCR,ISC00);
	//Enable or disable external interrupt
	SETBIT(GICR,INT0,state);
}
