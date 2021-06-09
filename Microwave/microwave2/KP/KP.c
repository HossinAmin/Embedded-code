#include "KP.h"

//Keys variables 
char keys[4][4]=
{
	{'1','2','3','-'},
	{'4','5','6','*'},
	{'7','8','9','/'},
	{'c','0','=','+'},
};

//functions
void KP_init()
{
	//input pins
	DIO_setHighNibVal(KPPort,0x0F);//enable internal pull up
	//output pins
	DIO_setLowNibDir(KPPort,OUT);
}

char KP_getKey()
{
	for (uint8 i=0;i<4;i++)
	{
		DIO_setLowNibVal(KPPort,0xFF);
		DIO_setPinVal(KPPort,i,LOW);
		_delay_ms(10);
		for (uint8 j=4;j<8;j++)
		{
			if(DIO_getPinVal(KPPort,j)==0)
			{
				_delay_ms(150);
				if(DIO_getPinVal(KPPort,j)==0)
				{
					return (keys[i][j-4]);
				}
			}
		}
	}
	
	return '\0';
}


