#ifndef TIMER_8_H_
#define TIMER_8_H_

//
#define	TIM0_Port  'b'
#define	TIM1_Port  'd'
#define TIM0_OC0	3	   
#define TIM1_OC1	7
 
//files i need
#include "TimerTypes.h"
#include "../DIO/DIO.h"
#include <avr/io.h>
#include "../Headers/myTypes.h"
#include "../Headers/BitMath.h"

//initialize  8 bit timer
void timer_init_8(Timer_8 t,TimerMode8 m);
//enable and disable interrupts
void timer_setInterruptEnable_8(Timer_8 t,INTERUPT I,Bool val);
//setting COMx0 COMx1
void timer_setCOM_8(Timer_8 t,COMMode m);
//pre load timer
void timer_load_8(Timer_8 t,uint8 val);
//clock selection
void timer_CLKS_8(Timer_8 t,CLK clock);
//load compare value
void timer_loadComp_8(Timer_8 t,uint8 val);
//stop timer
void timer_stop_8(Timer_8 t);
//set duty cycle of PWM 0-100
void timer_setDutyCycle_8(Timer_8 t,uint8 DCyc, Bool inverting);

#endif 