#include "Timer_16.h"

void timer_init_16(TimerMode16 m)
{

	if (m==CTC_A)
	{
		//setting waveform
		OFF(TCCR1B,WGM13);
		ON(TCCR1B,WGM12);
		OFF(TCCR1A,WGM11);
		OFF(TCCR1A,WGM10);
		//default load a with max
		OCR1AH = 0xFFFF>>8;
		OCR1AL = (0xFFFF<<8)>>8;
	}
	else if (m==CTC_ICR)
	{
		//setting waveform
		ON(TCCR1B,WGM13);
		OFF(TCCR1B,WGM12);
		OFF(TCCR1A,WGM11);
		OFF(TCCR1A,WGM10);
		//default load a with max
		ICR1H = 0xFFFF>>8;
		ICR1L = (0xFFFF<<8)>>8;
		
	}
	else if (m==PWM_8)
	{
		//setting waveform
		OFF(TCCR1B,WGM13);
		OFF(TCCR1B,WGM12);
		OFF(TCCR1A,WGM11);
		ON(TCCR1A,WGM10);
		//default duty cycle 50%
		OCR1AH=127>>8;
		OCR1AL=(127<<8)>>8;
		
		//setting com
		timer_setCOMA_16(clearOnMatch);
	}
	else if (m==PWM_9)
	{
		//setting waveform
		OFF(TCCR1B,WGM13);
		OFF(TCCR1B,WGM12);
		ON(TCCR1A,WGM11);
		OFF(TCCR1A,WGM10);
		//default duty cycle 50%
		OCR1AH=255>>8;
		OCR1AL=(255<<8)>>8;
		//setting com
		timer_setCOMA_16(clearOnMatch);
	}
	else if (m==PWM_10)
	{
		//setting waveform
		OFF(TCCR1B,WGM13);
		OFF(TCCR1B,WGM12);
		ON(TCCR1A,WGM11);
		ON(TCCR1A,WGM10);
		//default duty cycle 50%
		OCR1AH=511>>8;
		OCR1AL=(511<<8)>>8;
		
		//setting com
		timer_setCOMA_16(clearOnMatch);
	}
	else if (m==PWM_A)
	{
		//setting waveform
		ON(TCCR1B,WGM13);
		OFF(TCCR1B,WGM12);
		ON(TCCR1A,WGM11);
		ON(TCCR1A,WGM10);

		//setting com
		timer_setCOMA_16(clearOnMatch);
	}
	else if (m==PWM_ICR)
	{
		//setting waveform
		ON(TCCR1B,WGM13);
		OFF(TCCR1B,WGM12);
		ON(TCCR1A,WGM11);
		OFF(TCCR1A,WGM10);
		//setting com
		timer_setCOMA_16(clearOnMatch);
	}
	else if (m==FastPWM_8)
	{
		//setting waveform
		OFF(TCCR1B,WGM13);
		ON(TCCR1B,WGM12);
		OFF(TCCR1A,WGM11);
		ON(TCCR1A,WGM10);
		//default duty cycle 50%
		OCR1AH=127>>8;
		OCR1AL=(127<<8)>>8;
		//setting com
		timer_setCOMA_16(clearOnMatch);
	}
	else if(m==FastPWM_9)
	{
		//setting waveform
		OFF(TCCR1B,WGM13);
		ON(TCCR1B,WGM12);
		ON(TCCR1A,WGM11);
		OFF(TCCR1A,WGM10);
		//default duty cycle 50%
		OCR1AH=255>>8;
		OCR1AL=(255<<8)>>8;		
		//setting com
		timer_setCOMA_16(clearOnMatch);
	}
	else if(m==FastPWM_10)
	{
		//setting waveform
		OFF(TCCR1B,WGM13);
		ON(TCCR1B,WGM12);
		ON(TCCR1A,WGM11);
		ON(TCCR1A,WGM10);
		OCR1AH=511>>8;
		OCR1AL=(511<<8)>>8;
		
		//setting com
		timer_setCOMA_16(clearOnMatch);
	}
	else if(m==PWM_FC_A)
	{
		//setting waveform
		ON(TCCR1B,WGM13);
		OFF(TCCR1B,WGM12);
		OFF(TCCR1A,WGM11);
		OFF(TCCR1A,WGM10);
		
	}
	else if(m==PWM_FC_ICR)
	{
		//setting waveform
		ON(TCCR1B,WGM13);
		OFF(TCCR1B,WGM12);
		OFF(TCCR1A,WGM11);
		ON(TCCR1A,WGM10);
		
	}
	else if(m==FastPWM_A)
	{
		//setting waveform
		ON(TCCR1B,WGM13);
		ON(TCCR1B,WGM12);
		ON(TCCR1A,WGM11);
		ON(TCCR1A,WGM10);
	}
	else if (m==FastPWM_ICR)
	{
		//setting waveform
		ON(TCCR1B,WGM13);
		ON(TCCR1B,WGM12);
		ON(TCCR1A,WGM11);
		OFF(TCCR1A,WGM10);
	}
	else//default mode is normal timer
	{
		//setting waveform
		OFF(TCCR1B,WGM13);
		OFF(TCCR1B,WGM12);
		OFF(TCCR1A,WGM11);
		OFF(TCCR1A,WGM10);
	}

}

void timer_setInterruptEnable_16(INTERUPT I,Bool val)
{
	if (I==COMB)
	{
		SETBIT(TIMSK,OCIE1B,val);
	}
	else if (I==COMA)
	{
		SETBIT(TIMSK,OCIE1A,val);
	}
	else//default overflow
	{
		SETBIT(TIMSK,TOIE1,val);
	}
}

void timer_setCOMA_16(COMMode m)
{
	if (m==clearOnMatch)
	{
		//setting output pin
		ON(DDRD,5);
		
		OFF(TCCR1A,COM1A0);
		ON(TCCR1A,COM1A1);		
	}
	else if (m==setOnMatch)
	{
		//setting output pin
		ON(DDRD,5);
		
		ON(TCCR1A,COM1A0);
		ON(TCCR1A,COM1A1);		
	}
	else if (m==toggOnMatch)//reserved in PWM modes
	{
		//setting output pin
		ON(DDRD,5);
			
		ON(TCCR1A,COM1A0);
		OFF(TCCR1A,COM1A1);		
	}
	else//disconnect is the default mode
	{
		OFF(TCCR1A,COM1A0);
		OFF(TCCR1A,COM1A1);
	}

}

void timer_setCOMB_16(COMMode m)
{
	if (m==clearOnMatch)
	{
		//setting output pin
		ON(DDRD,4);
				
		OFF(TCCR1A,COM1B0);
		ON(TCCR1A,COM1B1);
	}
	else if (m==setOnMatch)
	{
		//setting output pin
		ON(DDRD,4);
		
		ON(TCCR1A,COM1B0);
		ON(TCCR1A,COM1B1);
	}
	else if (m==toggOnMatch)//reserved in PWM modes
	{
		//setting output pin
		ON(DDRD,4);
		
		ON(TCCR1A,COM1B0);
		OFF(TCCR1A,COM1B1);
	}
	else//disconnect is the default mode
	{
		OFF(TCCR1A,COM1B0);
		OFF(TCCR1A,COM1B1);
	}

}

void timer_load_16(uint16 val)
{
	TCNT1H=val>>8;
	TCNT1L=(val<<8)>>8;
}

void timer_CLKS_16(CLK clock)
{
	if (clock==CLK1)
	{
		ON(TCCR1B,CS10);
		OFF(TCCR1B,CS11);
		OFF(TCCR1B,CS12);
	}
	else if (clock==CLK8)
	{
		OFF(TCCR1B,CS10);
		ON(TCCR1B,CS11);
		OFF(TCCR1B,CS12);
	}
	else if (clock==CLK64)
	{
		ON(TCCR1B,CS10);
		ON(TCCR1B,CS11);
		OFF(TCCR1B,CS12);
	}
	else if (clock==CLK256)
	{
		OFF(TCCR1B,CS10);
		OFF(TCCR1B,CS11);
		ON(TCCR1B,CS12);
	}
	else if (clock==CLK1024)
	{
		ON(TCCR1B,CS10);
		OFF(TCCR1B,CS11);
		ON(TCCR1B,CS12);
	}
	else if (clock==FE)
	{
		ON(TCCR1B,CS10);
		OFF(TCCR1B,CS11);
		OFF(TCCR1B,CS12);
	}
	else if (clock==Re)
	{
		ON(TCCR1B,CS10);
		ON(TCCR1B,CS11);
		ON(TCCR1B,CS12);
	}

}

void timer_loadComp_16(Comp c,uint16 val)
{
	if(c==B)
	{
		OCR1BH = val>>8;
		OCR1BL = (val<<8)>>8;
	}
	else if(c==ICR)
	{
		ICR1H = val>>8;
		ICR1L = (val<<8)>>8;
	}
	else//default comparator is A
	{
		OCR1AH = val>>8;
		OCR1AL = (val<<8)>>8;
	}
}

void timer_stop_16()
{
	OFF(TCCR1B,CS10);
	OFF(TCCR1B,CS11);
	OFF(TCCR1B,CS12);
}

void timer_setDutyCycle_16(Comp c,float DCyc,uint16 max, Bool inverting)
{
	//guard
	if (DCyc>max)
	{
		DCyc=max;
	}
	if (DCyc<0)
	{
		DCyc=0;
	}
	///
	//checks if the PWM is inverting or non
	if (inverting)
	{
		DCyc=100-DCyc;
	}
	//
	if (c==B)
	{
		timer_loadComp_16(B,max*(DCyc/100.00));
	} 
	else//default mode is dual slope
	{
		timer_loadComp_16(A,max*(DCyc/100.00));
	}
}

uint16 timer_setFre_16(Comp topReg,CLK clock,uint16 frequency,Bool fast)
{
	uint16 timerMax;
	//selecting mode
	if (fast)
	{
		//pass
	}
	else//default not normal PWM
	{
		frequency*=2;
	}
	
	//selecting CLK and cal timer max
	if (clock==CLK1)
	{
		timerMax = F_CPU/frequency;
	}
	else if (clock==CLK8)
	{
		timerMax = F_CPU/(8.00*frequency);
	}
	else if (clock==CLK64)
	{
		timerMax = F_CPU/(64.00*frequency);
	}
	else if (clock==CLK256)
	{
		timerMax = F_CPU/(256.00*frequency);
	}
	else//default mode is clk1024
	{
		timerMax = F_CPU/(1024.00*frequency);
	}
	
	//loading comparator with timer max
	if(topReg==B)
	{
		timer_loadComp_16(B,timerMax);
	}
	else if(topReg==ICR)
	{
		timer_loadComp_16(ICR,timerMax);
	}
	else//default comparator is A
	{
		timer_loadComp_16(A,timerMax);
	}
	
	return timerMax;
}
