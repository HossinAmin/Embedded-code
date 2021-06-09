#include "plate.h"


void plate_init()
{
	timer_init_16(PWM_8);
	timer_setCOMA_16(clearOnMatch);
	timer_setCOMB_16(clearOnMatch);
}

void plate_move(Bool dir,uint8 speed)
{
	timer_setCOMA_16(clearOnMatch);
	timer_setCOMB_16(clearOnMatch);
	if (dir)
	{
		timer_setDutyCycle_16(A,speed,255,False);
		timer_setDutyCycle_16(B,0,255,False);
	}
	else
	{
		timer_setDutyCycle_16(A,0,255,False);
		timer_setDutyCycle_16(B,speed,255,False);
	}
	timer_CLKS_16(CLK1024);
}
void plate_stop()
{
	timer_stop_16();
	timer_setCOMA_16(disconnect);
	timer_setCOMB_16(disconnect);
	DIO_setPinVal(ControlPort,In1,LOW);
	DIO_setPinVal(ControlPort,In2,LOW);

}
