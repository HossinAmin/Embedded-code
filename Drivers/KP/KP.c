#include "KP.h"

//variables 
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
	setHighNibVal(KPPort,0x0F);//enable internal pull up
	//output pins
	setLowNibDir(KPPort,OUT);
}

char KP_getKey()
{
	for (uint8 i=0;i<4;i++)
	{
		setLowNibVal(KPPort,0xFF);
		setPinVal(KPPort,i,LOW);
		_delay_ms(10);
		for (uint8 j=4;j<8;j++)
		{
			if(getPinVal(KPPort,j)==0)
			{
				_delay_ms(100);
				if(getPinVal(KPPort,j)==0)
				{
					return (keys[i][j-4]);
				}
			}
		}
	}
	
	return '\0';
}


