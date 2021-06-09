#include "Timer_8.h"

void timer_init_8(Timer_8 t,TimerMode8 m)
{
	if (m==normal)
	{
		if (t==TIM0)
		{
			//enable overflow interrupt
			ON(TIMSK,TOIE0);
			//setting wave form
			OFF(TCCR0,WGM00);
			OFF(TCCR0,WGM01);			
		} 
		else //Timer 2 is the default timer
		{
			//enable overflow interrupt
			ON(TIMSK,TOIE2);
			//setting waveform
			OFF(TCCR2,WGM20);
			OFF(TCCR2,WGM21);
		}
	}
	else if (m==CTC)
	{
		
		if (t==TIM0)
		{	
			//enable compare interrupt
			ON(TIMSK,OCIE0);
			//setting waveform
			OFF(TCCR0,WGM00);
			ON(TCCR0,WGM01);
			
		}
		else //Timer 2 is the default timer
		{	
			//enable compare interrupt
			ON(TIMSK,OCIE2);
			//setting waveform
			OFF(TCCR2,WGM20);
			ON(TCCR2,WGM21);
		}
	}
	else if (m==PWM)
	{
		
		if (t==TIM0)
		{
			//setting waveform
			ON(TCCR0,WGM00);
			OFF(TCCR0,WGM01);
			//default  duty cycle 50%
			OCR0=127;
			//default PWM is non-inverting
			timer_setCOM_8(t,clearOnMatch);

		}
		else //Timer 2 is the default timer
		{
			//setting waveform
			ON(TCCR2,WGM20);
			OFF(TCCR2,WGM21);
			//default  duty cycle 50%
			OCR2=127;
			//default PWM is non-inverting
			timer_setCOM_8(t,clearOnMatch);
		}
	}
	else if (m==FastPWM)
	{
		
		if (t==TIM0)
		{
			//setting waveform
			ON(TCCR0,WGM00);
			ON(TCCR0,WGM01);
			//default  duty cycle 50%
			OCR0=127;
			//default PWM is non-inverting
			timer_setCOM_8(t,clearOnMatch);
			
		}
		else //Timer 2 is the default timer
		{
			//setting waveform
			ON(TCCR2,WGM20);
			ON(TCCR2,WGM21);
			//default  duty cycle 50%
			OCR2=127;
			////default PWM is non-inverting
			timer_setCOM_8(t,clearOnMatch);
		}
	}
}

void timer_setInterruptEnable_8(Timer_8 t,INTERUPT I,Bool val)
{
	if (t==TIM0)
	{
		if (I==COMA||I==COMB)//since timer_8 only has one comparator
		{
			SETBIT(TIMSK,OCIE0,val);
		}
		else//default  
		{
			SETBIT(TIMSK,TOIE0,val);
		}
	}
	else //Timer 2 is the default timer
	{
		if (I==COMA||I==COMB)//since timer_8 only has one comparator
		{
			SETBIT(TIMSK,OCIE2,val);
		}
		else//default
		{
			SETBIT(TIMSK,TOIE2,val);
		}	
	}
}

void timer_setCOM_8(Timer_8 t,COMMode m)
{
	if (t==TIM0)
	{
		if (m==clearOnMatch)
		{
			DIO_setPinDir(TIM0_Port,TIM0_OC0,OUT);
			OFF(TCCR0,COM00);
			ON(TCCR0,COM01);
		}
		else if (m==setOnMatch)
		{
			DIO_setPinDir(TIM0_Port,TIM0_OC0,OUT);
			ON(TCCR0,COM00);
			ON(TCCR0,COM01);
		}
		else if (m==toggOnMatch)//reserved in PWM modes
		{
			DIO_setPinDir(TIM0_Port,TIM0_OC0,OUT);
			ON(TCCR0,COM00);
			OFF(TCCR0,COM01);
		}
		else//disconnect is the default mode
		{
			
			OFF(TCCR0,COM00);
			OFF(TCCR0,COM01);
		}
	}
	else //default timer 2
	{
		if (m==clearOnMatch)
		{
			DIO_setPinDir(TIM1_Port,TIM1_OC1,OUT);
			OFF(TCCR2,COM20);
			ON(TCCR2,COM21);
		}
		else if (m==setOnMatch)
		{
			DIO_setPinDir(TIM1_Port,TIM1_OC1,OUT);
			ON(TCCR2,COM20);
			ON(TCCR2,COM21);
		}
		else if (m==toggOnMatch)//reserved in PWM modes
		{
			DIO_setPinDir(TIM1_Port,TIM1_OC1,OUT);
			ON(TCCR2,COM20);
			OFF(TCCR2,COM21);
		}
		else//disconnect is the default mode
		{
			OFF(TCCR2,COM20);
			OFF(TCCR2,COM21);
		}
	}
}

void timer_load_8(Timer_8 t,uint8 val)
{
		if (t==TIM0)
		{
			TCNT0 = val;
		}
		else //Timer 2 is the default timer
		{
			OFF(TCCR2,WGM20);
			ON(TCCR2,WGM21);
		}
}

void timer_CLKS_8(Timer_8 t,CLK clock)
{
	if (clock==CLK1)
	{
		if (t==TIM0)
		{
			ON(TCCR0,CS00);
			OFF(TCCR0,CS01);
			OFF(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			ON(TCCR2,CS20);
			OFF(TCCR2,CS21);
			OFF(TCCR2,CS22);
		}
	}
	else if (clock==CLK8)
	{
		if (t==TIM0)
		{
			OFF(TCCR0,CS00);
			ON(TCCR0,CS01);
			OFF(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			OFF(TCCR2,CS20);
			ON(TCCR2,CS21);
			OFF(TCCR2,CS22);
		}
	}
	else if (clock==CLK64)
	{
		if (t==TIM0)
		{
			ON(TCCR0,CS00);
			ON(TCCR0,CS01);
			OFF(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			ON(TCCR2,CS20);
			ON(TCCR2,CS21);
			OFF(TCCR2,CS22);
		}
	}
	else if (clock==CLK256)
	{
		if (t==TIM0)
		{
			OFF(TCCR0,CS00);
			OFF(TCCR0,CS01);
			ON(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			OFF(TCCR2,CS20);
			OFF(TCCR2,CS21);
			ON(TCCR2,CS22);
		}
	}
	else if (clock==CLK1024)
	{
		if (t==TIM0)
		{
			ON(TCCR0,CS00);
			OFF(TCCR0,CS01);
			ON(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			ON(TCCR2,CS20);
			OFF(TCCR2,CS21);
			ON(TCCR2,CS22);
		}
	}
	else if (clock==FE)
	{
		if (t==TIM0)
		{
			OFF(TCCR0,CS00);
			ON(TCCR0,CS01);
			ON(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			OFF(TCCR2,CS20);
			ON(TCCR2,CS21);
			ON(TCCR2,CS22);
		}
	}
	else if (clock==Re)
	{
		if (t==TIM0)
		{
			ON(TCCR0,CS00);
			ON(TCCR0,CS01);
			ON(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			ON(TCCR2,CS20);
			ON(TCCR2,CS21);
			ON(TCCR2,CS22);
		}
	}

}

void timer_loadComp_8(Timer_8 t,uint8 val)
{
		if (t==TIM0)
		{
			OCR0 = val;
		}
		else //Timer 2 is the default timer
		{
			OCR2 = val;
		}	

}

void timer_stop_8(Timer_8 t)
{
	if (t==TIM0)
	{
		//disconnect OC1 pins
		OFF(TCCR0,CS00);
		OFF(TCCR0,CS01);
		OFF(TCCR0,CS02);
	}
	else //Timer 2 is the default timer
	{
		//disconnect OC2 pin
		OFF(TCCR2,CS20);
		OFF(TCCR2,CS21);
		OFF(TCCR2,CS22);
	}
}

void timer_setDutyCycle_8(Timer_8 t,uint8 DCyc, Bool inverting)
{
	//guard
	if(DCyc>100)
	{
		DCyc=100;
	}
	if(DCyc<0)
	{
		DCyc=0;
	}
	//checks if inverting PWM or non inverting
	if (inverting)
	{
		DCyc=100-DCyc;
	}
	//
	if (t==TIM0)
	{
		OCR0=255*(DCyc/100.00);
	}
	else //Timer 2 is the default timer
	{
		OCR2=255*(DCyc/100.00);
	}

}
