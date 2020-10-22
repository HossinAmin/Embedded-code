#ifndef USART_H_
#define USART_H_


		/* 8 bit is the max world size */
		/* Synchronous mode is not available in this driver  */
#include "USARTTypes.h"


#define F_CPU				16000000UL
#define USART_BAUDRATE		9600
#define USART_Mode			ASYNC
#define USART_PARITY		DIS_PARITY
#define USART_STOP_BIT		1
#define USART_CHAR_SIZE		8

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


//sets baud rate, operation mode, parity, stop bit and char size.
void USART_init();
void USART_setTxEable(Bool val);
void USART_setRxEable(Bool val);
void USART_setInterruptTxEable(Bool val);
void USART_setInterruptRxEable(Bool val);
void USART_sendChar(char val);
char USART_reciveChar();
Bool USART_getERflag();
Bool USART_getTCflag();
Bool USART_getRCflag();


#endif /* USART_H_ */