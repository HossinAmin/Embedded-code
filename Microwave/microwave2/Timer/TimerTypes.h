#ifndef TIMERTYPESH_H_
#define TIMERTYPESH_H_

typedef enum TimerMode8
{
	normal,
	CTC,
	PWM,
	FastPWM
}TimerMode8;

typedef enum Timer_8
{
	TIM0,
	TIM2
}Timer_8;

typedef enum TimerMode16
{
	normal_16,
	PWM_8,
	PWM_9,
	PWM_10,
	CTC_A,
	FastPWM_8,
	FastPWM_9,
	FastPWM_10,
	PWM_FC_ICR,
	PWM_FC_A,
	PWM_A,
	PWM_ICR,
	CTC_ICR,
	FastPWM_ICR,
	FastPWM_A,
		
}TimerMode16;

typedef enum CLK
{
	Re,
	Fe,
	CLK1,
	CLK8,
	CLK64,
	CLK256,
	CLK1024
}CLK;

typedef enum COMMode
{
	disconnect,
	toggOnMatch,
	setOnMatch,
	clearOnMatch
}COMMode;

typedef enum Comp
{
	A,
	B,
	ICR
}Comp;

typedef enum INTERUPT
{
	OVF,
	COMA,
	COMB
}INTERUPT;
#endif