#include "USART.h"

void USART_init()
{
	
	//Enable Tx and Rx
	USART_setTxEable(True);
	USART_setRxEable(True);
 	
	//setting character size
 	if (USART_CHAR_SIZE==5)
 	{
	 	OFF(UCSRB,UCSZ2);

 	}
 	else if (USART_CHAR_SIZE==6)
 	{
	 	OFF(UCSRB,UCSZ2);
		UCSRC |= (1 << URSEL) | (1 << UCSZ0);
	
 	}
 	else if (USART_CHAR_SIZE==7)
 	{
	 	OFF(UCSRB,UCSZ2);
		UCSRC |= (1 << URSEL) | (1 << UCSZ1);

 	}
 	else //default size is 8 bit
 	{
		OFF(UCSRB,UCSZ2);
		UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit character sizes */
 	}
	 
	//setting baud rate
	UBRRL = BAUD_PRESCALE;			/* Load lower 8-bits of the baud rate value */
	UBRRH = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/
	
	//setting parity
	if (USART_PARITY==ODD_PARITY)
	{
		UCSRC |= (1 << URSEL) | (1 << UPM0) | (1 << UPM1);/* Use 8-bit character sizes */
	}
	else if (USART_PARITY==EVEN_PARITY)
	{
		UCSRC |= (1 << URSEL) | (1 << UPM1);
	}
	else// default is disable parity
	{
		//pass
	}

}

void USART_setTxEable(Bool val)
{
	SETBIT(UCSRB,TXEN,val);
}

void USART_setRxEable(Bool val)
{
	SETBIT(UCSRB,RXEN,val);
}

void USART_setInterruptTxEable(Bool val)
{
	SETBIT(UCSRB,RXCIE,val);
}

void USART_setInterruptRxEable(Bool val)
{
	SETBIT(UCSRB,TXEN,val);
}

void USART_sendChar(char val)
{
	UDR=val;
}

char USART_reciveChar()
{
	return UDR;
}

Bool USART_getERflag()
{
 return CHECKBIT(UCSRA,UDRE);
}

Bool USART_getTCflag()
{
 return CHECKBIT(UCSRA,TXC);
}

Bool USART_getRCflag()
{
 return CHECKBIT(UCSRA,RXC);
}
