
#include "config.h"

#include <stddef.h>
#include "cocoos.h"
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "lcd.h"

void setupHardware(void)
{
	uart_init();
	lcd_init();
	uart_print("system staretd\r\n");
	uart_print("hw init success\r\n");
}

static void scankey(void)
{
	/* open the task */
	task_open();

	for(;;)
	{
		;
	}

	/* close the task */
	task_close();
}


int main(void)
{
	/* setup the hardware */
	setupHardware();

	/* initiate OS */
	os_init();

	/* Create tasks */
	task_create(	scankey,		// Function pointer to the task procedure. 
					1,				// Task priority on a scale 0-255 where 0 is the highest priority.
					NULL,			// Pointer to the message pool, containing messages. Ignored if poolSize is 0
					0,				// Size of the message pool. Set to 0 if no message pool needed for the task 
					0 				// Size of the message type held in the message queue 
				);	

	/* start os */
	os_start();

	/* we never reach here */
	return 0;
}