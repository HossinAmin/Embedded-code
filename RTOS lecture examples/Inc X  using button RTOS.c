/*#include <avr/io.h>*/

#include "LCD/LCD.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "util/delay.h"
#define Button0 0

void vIncSendXTask(void *p);
void vDisReceiveXTask(void *p);

//my Queue
QueueHandle_t myQ;

int main(void)
{
	//initialize LCD
	LCD_init();
	//create Queue
	myQ = xQueueCreate(1,sizeof(uint8));
	//check if there is enough memory to allocate for the Queue
	if(myQ!=NULL)
	{
		//creating tasks
		xTaskCreate(vIncSendXTask,"senderTask",90,NULL,1,NULL);
		xTaskCreate(vDisReceiveXTask,"reciverTask",90,NULL,2,NULL);
		vTaskStartScheduler();
	}
	else
	{
		/*in case no memory available*/
	}

	/* Replace with your application code */
	while (1)
	{
	
	}
}

void vIncSendXTask(void *p)
{
	//setting data direction
	
	uint8 x = '0';
	setPinDir('b',Button0,IN);
	while (1)
	{
			
		if (getPinVal('b',Button0))
		{	
			LCD_clearDisplay();
			vTaskDelay(20/portTICK_PERIOD_MS);//to insure that LCD is not busy before sending data
			xQueueSendToBack(myQ,&x,20/portTICK_PERIOD_MS);
			x++;
			vTaskDelay(300/portTICK_PERIOD_MS);
		}

	}
	
}
void vDisReceiveXTask(void *p)
{
	uint8 data = '\0';
	while(1)
	{
		xQueueReceive(myQ,&data,portMAX_DELAY);
		if (data!='\0')
		{
			LCD_sendData(data);
		}

	}

}