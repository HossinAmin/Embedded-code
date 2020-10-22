#ifndef REGISTER_H_
#define REGISTER_H_
#include "MyTypes.h"
//Output registers
#define PORT_A		*((volatile uint8*)0x3B)
#define PORT_B		*((volatile uint8*)0x38)
#define PORT_C		*((volatile uint8*)0x35)
#define PORT_D		*((volatile uint8*)0x32)

//input registers
#define PIN_A		*((const volatile uint8*)0x39 )
#define PIN_B		*((const volatile uint8*)0x36 )
#define PIN_C		*((const volatile uint8*)0x33 )
#define PIN_D		*((const volatile uint8*)0x30 )

//Data direction registers
#define DDR_A		*((volatile uint8*)0x3A)
#define DDR_B		*((volatile uint8*)0x37)
#define DDR_C		*((volatile uint8*)0x34)
#define DDR_D		*((volatile uint8*)0x31)

//Timer registers
//timer 0
#define TCNT0		*((volatile uint8*)0x52)

#define TCCR0		*((volatile uint8*)0x53)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

#define OCR0		*((volatile uint8*)0x5C)

//timer 1
#define TCNT1H		*((volatile uint8*)0x4D)
#define TCNT1L		*((volatile uint8*)0x4C)

#define TCCR1A		*((volatile uint8*)0x4F)
#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define TCCR1B		*((volatile uint8*)0x4E)
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define OCR1AH		*((volatile uint8*)0x4B)
#define OCR1AL		*((volatile uint8*)0x4A)

#define OCR1BH		*((volatile uint8*)0x49)
#define OCR1BL		*((volatile uint8*)0x48)

#define ICR1H		*((volatile uint8*)0x47)
#define ICR1L		*((volatile uint8*)0x46)

//timer 2
#define TCNT2		*((volatile uint8*)0x44)

#define TCCR2		*((volatile uint8*)0x45)
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM20   4
#define COM21   5
#define WGM20   6
#define FOC2    7

#define OCR2		*((volatile uint8*)0x43)

///////
#define TIMSK		*((volatile uint8*)0x59)
#define TOIE0   0
#define OCIE0   1
#define TOIE2   6
#define OCIE2   7
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5

//USART Registers
#define UDR			*((volatile uint8*)0x2C)

#define UCSRA		*((volatile uint8*)0x2B)
#define MPCM    0
#define U2X     1
#define UPE     2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

#define UCSRB		*((volatile uint8*)0x2A)
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UCSRC		*((volatile uint8*)0x40)
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL   6
#define URSEL   7

#define UBRRH		*((volatile uint8*)0x40)
#define UBRRL		*((volatile uint8*)0x29)


//USART Registers
#define UDR			*((volatile uint8*)0x2C)

#define UCSRA		*((volatile uint8*)0x2B)
#define MPCM    0
#define U2X     1
#define UPE     2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

#define UCSRB		*((volatile uint8*)0x2A)
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UCSRC		*((volatile uint8*)0x40)
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL   6
#define URSEL   7

#define UBRRH		*((volatile uint8*)0x40)
#define UBRRL		*((volatile uint8*)0x29)





//

#endif