
#include "config.h"

#include <stddef.h>
#include "cocoos.h"
#include <avr/io.h>
#include <util/delay.h>

void setupHardware(void)
{
	;
}

static void taskA(void)
{
	task_open();
	for(;;)
	{
		;
	}
	task_close();
}

int main(void)
{
	setupHardware();
	os_init();
	task_create(taskA,1,NULL,0,0);
	os_start();

	// We never reach here
	return 0;
}