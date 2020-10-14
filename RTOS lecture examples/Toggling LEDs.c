#include <avr/io.h>

#include "FreeRTOS.h"
#include "task.h"

//my tasks
//toggles an LED every 10ms
void vTask1()
{
	//setting port
	DDRD|=1;
	
	//task loop
	while(1)
	{
		vTaskDelay(10/portTICK_PERIOD_MS);
		PORTD^=1;
	}
}
//toggles an LED every 150ms
void vTask2()
{
	//setting port
	DDRD|=(1<<1);
	
	//task loop
	while(1)
	{
		PORTD^=(1<<1);
		vTaskDelay(150/portTICK_PERIOD_MS);
	}	
}
//toggles an LED every 50ms
void vTask3()
{
	//setting port
	DDRD|=(1<<2);
	
	//task loop
	while(1)
	{
		PORTD^=(1<<2);
		vTaskDelay(50/portTICK_PERIOD_MS);
	}
}


int main(void)
{

	//create my tasks
	xTaskCreate(vTask1,"Task1",100,NULL,1,NULL);
	xTaskCreate(vTask2,"Task2",100,NULL,2,NULL);
	xTaskCreate(vTask3,"Task3",100,NULL,3,NULL);
	vTaskStartScheduler();
    /* Replace with your application code */
    while (1) 
    {

    }
	return 0;
}
