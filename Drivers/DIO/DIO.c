#include "DIO.h"

void setPinDir(char port,uint8 pin,Bool dir)
{
	
	switch(port)
	{
		case 'A':
		case 'a':
		SETBIT(DDR_A,pin,dir);
		break;
		case 'B':
		case 'b':
		SETBIT(DDR_B,pin,dir);
		break;
		case 'C':
		case 'c':
		SETBIT(DDR_C,pin,dir);
		break;
		case 'D':
		case 'd':
		SETBIT(DDR_D,pin,dir);
		break;

	}

}
//missing default 
void setPinVal(char port,uint8 pin,Bool val)
{	
	switch(port)
	{
		case 'A':
		case 'a':
		SETBIT(PORT_A,pin,val);
		break;
		case 'B':
		case 'b':
		SETBIT(PORT_B,pin,val);
		break;
		case 'C':
		case 'c':
		SETBIT(PORT_C,pin,val);
		break;
		case 'D':
		case 'd':
		SETBIT(PORT_D,pin,val);
		break;
	}
}

//missing default
void setPortDir(char port,Bool dir)
{	
	switch(port)
	{
		case 'A':
		case 'a':
		FILLREG(DDR_A,dir);
		break;
		case 'B':
		case 'b':
		FILLREG(DDR_B,dir);
		break;
		case 'C':
		case 'c':
		FILLREG(DDR_C,dir);
		break;
		case 'D':
		case 'd':
		FILLREG(DDR_D,dir);
		break;
	}
}

//missing default
void setPortVal(char port,uint8 val)
{	
switch(port)
{
	case 'A':
	case 'a':
	PORT_A=val;
	break;
	case 'B':
	case 'b':
	PORT_B=val;
	break;
	case 'C':
	case 'c':
	PORT_C=val;
	break;
	case 'D':
	case 'd':
	PORT_D=val;
	break;
}
}

//default returns false
Bool getPinVal(char port,uint8 pin)
{
	switch(port)
	{
		case 'A':
		case 'a':
		return CHECKBIT(PIN_A,pin);
		case 'B':
		case 'b':
		return CHECKBIT(PIN_B,pin);
		case 'C':
		case 'c':
		return CHECKBIT(PIN_C,pin);
		case 'D':
		case 'd':
		return CHECKBIT(PIN_D,pin);
		break;
		default:
		return False;
		break;
	}
}

//default returns 0x0
uint8 getPortVal(char port)
{
	switch(port)
	{
		case 'A':
		case 'a':
		return PIN_A;
		case 'B':
		case 'b':
		return PIN_B;
		case 'C':
		case 'c':
		return PIN_B;
		case 'D':
		case 'd':
		return PIN_D;
		default:
		return 0x0;
		break;
	}
}

//missing default
void setLowNibVal(char port,uint8 val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		for (uint8 i = 0; i < 4; i++)
		{
			if ((CHECKBIT(PORT_A,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORT_A,i);
			}
		}
		break;
		case 'B':
		case 'b':
		for (uint8 i = 0; i < 4; i++)
		{
			if ((CHECKBIT(PORT_B,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORT_B,i);
			}
		}
		break;
		case 'C':
		case 'c':
		for (uint8 i = 0; i < 4; i++)
		{
			if ((CHECKBIT(PORT_C,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORT_C,i);
			}
		}
		break;
		case 'D':
		case 'd':
		for (uint8 i = 0; i < 4; i++)
		{
			if ((CHECKBIT(PORT_D,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORT_D,i);
			}
		}
		break;
	}

}

//missing default
void setHighNibVal(char port,uint8 val)
{
	val=val<<4;
	switch(port)
	{
		case 'A':
		case 'a':
		for (uint8 i = 4; i < 8; i++)
		{
			if ((CHECKBIT(PORT_A,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORT_A,i);
			}
		}
		break;
		case 'B':
		case 'b':
		for (uint8 i = 4; i < 8; i++)
		{
			if ((CHECKBIT(PORT_B,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORT_B,i);
			}
		}
		break;
		case 'C':
		case 'c':
		for (uint8 i = 4; i < 8; i++)
		{
			if ((CHECKBIT(PORT_C,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORT_C,i);
			}
		}
		break;
		case 'D':
		case 'd':
		for (uint8 i = 4; i < 8; i++)
		{
			if ((CHECKBIT(PORT_D,i))==(CHECKBIT(val,i)))
			{
			}
			else
			{
				TOGGLE(PORT_D,i);
			}
		}
		break;
	}

}

uint8 getLowNibVal(char port)
{
switch(port)
{
	case 'A':
	case 'a':
	return (PIN_A<<4)>>4;
	break;
	case 'B':
	case 'b':
	return (PIN_B<<4)>>4;
	break;
	case 'C':
	case 'c':
	return (PIN_C<<4)>>4;
	break;
	case 'D':
	case 'd':
	return (PIN_D<<4)>>4;
	break;
}	
}
uint8 getHighNibVal(char port)
{
	switch(port)
	{
		case 'A':
		case 'a':
		return (PIN_A>>4);
		break;
		case 'B':
		case 'b':
		return (PIN_B>>4);
		break;
		case 'C':
		case 'c':
		return (PIN_C>>4);
		break;
		case 'D':
		case 'd':
		return (PIN_D>>4);
		break;
	}
}
//missing default
void setLowNibDir(char port,Bool dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		for (uint8 i = 0; i < 4; i++)
		{
			SETBIT(DDR_A,i,dir);
		}
		break;
		case 'B':
		case 'b':
		for (uint8 i = 0; i < 4; i++)
		{
			SETBIT(DDR_B,i,dir);
		}
		break;
		case 'C':
		case 'c':
		for (uint8 i = 0; i < 4; i++)
		{
			SETBIT(DDR_C,i,dir);
			
		}
		break;
		case 'D':
		case 'd':
		for (uint8 i = 0; i < 4; i++)
		{
			SETBIT(DDR_D,i,dir);
		}
		break;
	}

}

//missing default
void setHighNibDir(char port,uint8 dir)
{	
	switch(port)
	{
		case 'A':
		case 'a':
		for (uint8 i = 4; i < 8; i++)
		{
			SETBIT(DDR_A,i,dir);
		}
		break;
		case 'B':
		case 'b':
		for (uint8 i = 4; i < 8; i++)
		{
			SETBIT(DDR_B,i,dir);
		}
		break;
		case 'C':
		case 'c':
		for (uint8 i = 4; i < 8; i++)
		{
			SETBIT(DDR_C,i,dir);
			
		}
		break;
		case 'D':
		case 'd':
		for (uint8 i = 4; i < 8; i++)
		{
			SETBIT(DDR_D,i,dir);
		}
		break;
		default:
		
		break;
	}
}
