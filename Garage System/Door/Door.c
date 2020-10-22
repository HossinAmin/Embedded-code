#include "Door.h"

void initDoor()
{
	timer_init_16(PWM_ICR);
	RegMax = timer_setFre_16(ICR,CLK64,50,False);
	timer_setCOMA_16(disconnect);
	timer_setCOMB_16(clearOnMatch);
	timer_CLKS_16(CLK64);
}

void openDoor()
{
	timer_setDutyCycle_16(B,5,RegMax,False);
}
void closeDoor()
{
	timer_setDutyCycle_16(B,10,RegMax,False);
}