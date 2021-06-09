#include "DIO.h"

void DIO_setPinDir(char port,uint8 pin,Bool dir)
{
	
	if (port == 'A' || port == 'a')
	{
		SETBIT(DDRA,pin,dir);
	}
	else if(port == 'B' || port == 'b') 
	{
		SETBIT(DDRB,pin,dir);
	}
	else if(port == 'C' || port == 'c')
	{
		SETBIT(DDRC,pin,dir);
	}
	else //  portD is the default port
	{
		SETBIT(DDRD,pin,dir);
	}
	

}
//missing default 
void DIO_setPinVal(char port,uint8 pin,Bool state)
{	
	if (port == 'A' || port == 'a')
	{
		SETBIT(PORTA,pin,state);
	}
	else if(port == 'B' || port == 'b')
	{
		SETBIT(PORTB,pin,state);
	}
	else if(port == 'C' || port == 'c')
	{
		SETBIT(PORTC,pin,state);
	}
	else //  portD is the default port
	{
		SETBIT(PORTD,pin,state);
	}
}

void DIO_setPortDir(char port,Bool dir)
{	
	if (port == 'A' || port == 'a')
	{
		FILLREG(DDRA,dir);
	}
	else if(port == 'B' || port == 'b')
	{
		FILLREG(DDRB,dir);
	}
	else if(port == 'C' || port == 'c')
	{
		FILLREG(DDRC,dir);
	}
	else //  portD is the default port
	{
		FILLREG(DDRD,dir);
	}
}

void DIO_setPortVal(char port,uint8 val)
{	
	if (port == 'A' || port == 'a')
	{
		PORTA = val;
	}
	else if(port == 'B' || port == 'b')
	{
		PORTB = val;
	}
	else if(port == 'C' || port == 'c')
	{
		PORTC = val;
	}
	else //  portD is the default port
	{
		PORTA = val;
	}
}

//default returns false
Bool DIO_getPinVal(char port,uint8 pin)
{
	switch(port)
	{
		case 'A':
		case 'a':
		return CHECKBIT(PINA,pin);
		case 'B':
		case 'b':
		return CHECKBIT(PINB,pin);
		case 'C':
		case 'c':
		return CHECKBIT(PINC,pin);
		case 'D':
		case 'd':
		return CHECKBIT(PIND,pin);
		break;
		default:
		return False;
		break;
	}
}

//default returns 0x0
uint8 DIO_getPortVal(char port)
{
	switch(port)
	{
		case 'A':
		case 'a':
		return PINA;
		case 'B':
		case 'b':
		return PINB;
		case 'C':
		case 'c':
		return PINB;
		case 'D':
		case 'd':
		return PIND;
		default:
		return 0x0;
		break;
	}
}


void DIO_setLowNibVal(char port,uint8 val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		for (uint8 i = 0; i < 4; i++)
		{
			if ((CHECKBIT(PORTA,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORTA,i);
			}
		}
		break;
		case 'B':
		case 'b':
		for (uint8 i = 0; i < 4; i++)
		{
			if ((CHECKBIT(PORTB,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORTB,i);
			}
		}
		break;
		case 'C':
		case 'c':
		for (uint8 i = 0; i < 4; i++)
		{
			if ((CHECKBIT(PORTC,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORTC,i);
			}
		}
		break;
		default:
		for (uint8 i = 0; i < 4; i++)
		{
			if ((CHECKBIT(PORTD,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORTD,i);
			}
		}
		break;
	}

}


void DIO_setHighNibVal(char port,uint8 val)
{
	val=val<<4;
	switch(port)
	{
		case 'A':
		case 'a':
		for (uint8 i = 4; i < 8; i++)
		{
			if ((CHECKBIT(PORTA,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORTA,i);
			}
		}
		break;
		case 'B':
		case 'b':
		for (uint8 i = 4; i < 8; i++)
		{
			if ((CHECKBIT(PORTB,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORTB,i);
			}
		}
		break;
		case 'C':
		case 'c':
		for (uint8 i = 4; i < 8; i++)
		{
			if ((CHECKBIT(PORTC,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORTC,i);
			}
		}
		break;
		default:
		for (uint8 i = 4; i < 8; i++)
		{
			if ((CHECKBIT(PORTD,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORTD,i);
			}
		}
		break;
	}

}

uint8 DIO_getLowNibVal(char port)
{
switch(port)
{
	case 'A':
	case 'a':
	return (PINA<<4)>>4;
	break;
	case 'B':
	case 'b':
	return (PINB<<4)>>4;
	break;
	case 'C':
	case 'c':
	return (PINC<<4)>>4;
	break;
	default:
	return (PIND<<4)>>4;
	break;
}	
}
uint8 DIO_getHighNibVal(char port)
{
	switch(port)
	{
		case 'A':
		case 'a':
		return (PINA>>4);
		break;
		case 'B':
		case 'b':
		return (PINB>>4);
		break;
		case 'C':
		case 'c':
		return (PINC>>4);
		break;
		default:
		return (PIND>>4);
		break;
	}
}

void DIO_setLowNibDir(char port,Bool dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		for (uint8 i = 0; i < 4; i++)
		{
			SETBIT(DDRA,i,dir);
		}
		break;
		case 'B':
		case 'b':
		for (uint8 i = 0; i < 4; i++)
		{
			SETBIT(DDRB,i,dir);
		}
		break;
		case 'C':
		case 'c':
		for (uint8 i = 0; i < 4; i++)
		{
			SETBIT(DDRC,i,dir);
			
		}
		break;
		default:
		for (uint8 i = 0; i < 4; i++)
		{
			SETBIT(DDRD,i,dir);
		}
		break;
	}

}


void DIO_setHighNibDir(char port,Bool dir)
{	
	switch(port)
	{
		case 'A':
		case 'a':
		for (uint8 i = 4; i < 8; i++)
		{
			SETBIT(DDRA,i,dir);
		}
		break;
		case 'B':
		case 'b':
		for (uint8 i = 4; i < 8; i++)
		{
			SETBIT(DDRB,i,dir);
		}
		break;
		case 'C':
		case 'c':
		for (uint8 i = 4; i < 8; i++)
		{
			SETBIT(DDRC,i,dir);
			
		}
		break;
		default:
		for (uint8 i = 4; i < 8; i++)
		{
			SETBIT(DDRD,i,dir);
		}
		break;

	}
}
