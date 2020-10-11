#ifndef REGISTER_H_
#define REGISTER_H_

//registers
#define PORT_A		*((volatile uint8*)0x3B)
#define PORT_B		*((volatile uint8*)0x38)
#define PORT_C		*((volatile uint8*)0x35)
#define PORT_D		*((volatile uint8*)0x32)

#define PIN_A		*((const volatile uint8*)0x39 )
#define PIN_B		*((const volatile uint8*)0x36 )
#define PIN_C		*((const volatile uint8*)0x33 )
#define PIN_D		*((const volatile uint8*)0x30 )

#define DDR_A		*((volatile uint8*)0x3A)
#define DDR_B		*((volatile uint8*)0x37)
#define DDR_C		*((volatile uint8*)0x34)
#define DDR_D		*((volatile uint8*)0x31)



#endif