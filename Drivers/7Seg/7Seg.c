#include "7Seg.h"

void init_7Seg()
{
		setHighNibDir(DP,OUT);
		
		setPinDir(CP,EN1,OUT);
		setPinDir(CP,EN2,OUT);		
		setPinDir(CP,DIP,OUT);
		
		setPinVal(CP,EN1,HIGH);
		setPinVal(CP,EN2,HIGH);
		setPinVal(CP,DIP,LOW);
}

void setEB1_7Seg(Bool state)
{
	setPinVal(CP,EN1,state);
}

void setEB2_7Seg(Bool state)
{
	setPinVal(CP,EN2,state);
}

void displaySingleDig_7Seg(uint8 num)
{
	setHighNibVal(DP,num);
}

void displayDoubleDig_7Seg(char *num)
{
	//48 is the difference between ASCII and decimal
		setHighNibVal(DP,num[1]-48);
		setPinVal(CP,EN2,HIGH);
		setPinVal(CP,EN1,LOW);
		_delay_ms(10);
		setHighNibVal(DP,num[0]-48);
		setPinVal(CP,EN2,LOW);
		setPinVal(CP,EN1,HIGH);
		_delay_ms(10);
}

