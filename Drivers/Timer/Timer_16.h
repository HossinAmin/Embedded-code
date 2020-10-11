#ifndef TIMER_16_H_
#define TIMER_16_H_

//defines controller frequency to calculate the PWM frequency in frequency controlled mode
#ifndef F_CPU
#define F_CPU 16000000ul
#endif

//files i need
#include "../Headers/Register.h"
#include "../Headers/myTypes.h"
#include "../Headers/BitMath.h"

#include "TimerTypes.h"

//initialize 16 bit timer
void timer_init_16(TimerMode16 m);
//enable and disable interrupts
void timer_setInterruptEnable_16(INTERUPT I,Bool val);
//setting COMX0 COMX1
void timer_setCOMA_16(COMMode m);
void timer_setCOMB_16(COMMode m);
//pre load timer
void timer_load_16(uint16 val);
//clock selection
void timer_CLKS_16(CLK clock);
//load comparator value
void timer_loadComp_16(Comp c,uint16 val);
//stop timer
void timer_stop_16();
//set duty cycle of PWM 0-100
void timer_setDutyCycle_16(Comp c,uint8 DCyc,uint16 max, Bool inverting);
//set frequency of PWM if top controlled modes and returns the max value of that the timer can count up to
uint16 timer_setFre_16(Comp topReg,CLK clock,uint16 frequency,Bool fast);



#endif /* TIMER_16_H_ */