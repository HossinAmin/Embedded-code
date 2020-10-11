#ifndef BITMATH_H_
#define BITMATH_H_


#define ON(x,Pin)		x |= (1<<Pin)
#define OFF(x,Pin)		x &=~(1<<Pin)
#define TOGGLE(x,Pin)	x ^= (1<<Pin)
#define CHECKBIT(x,Pin) (x&(1<<Pin)) == (1<<Pin)
#define SETBIT(x,Pin,state)		 x = state==0 ? x&~(1<<Pin):x|(1<<Pin)
#define FILLREG(x,state)		 x = state==0 ?  0x0:0xFF;







#endif 