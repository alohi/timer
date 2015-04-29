# Toolchain
CC 		= 	avr-

# CPU
CPU 	= 	atmega8

# Fuses
LFUSE 	= 	0xE4
HFUSE 	= 	0xD9

# Image name
IMAGE	=	app.elf
HEXFILE =	app.hex

# Programming hardware
PROGRAMMER	= 	avrispmkII

# Include paths
INC 	= 	-Ios \
			-Iapp \
			-Idrivers

# Virtual paths
VPATH	=	app:os:drivers
			
# Compiler Flags
CFLAGS 	= 	-g -c -Wall -Os -mmcu=$(CPU) $(INC)
# Linker flags
LFLAGS 	=	-g -Wall -Os -mmcu=$(CPU)
# Object Files
OBJS	= 	os_assert.o os_cbk.o os_event.o os_kernel.o os_msgqueue.o os_sem.o os_task.o \
			main.o uart.o

# target all
all: $(OBJS)
	$(CC)gcc $(LFLAGS) $(OBJS) -o $(IMAGE)
	$(CC)objcopy -O ihex $(IMAGE) $(HEXFILE)
	$(CC)size $(IMAGE)

# Clean
clean: $(OBJS)
	-rm $(OBJS)
	-rm $(IMAGE)
	-rm $(HEXFILE)

# Load to target
load: 	$(HEXFILE)
		avrdude -c $(PROGRAMMER) -p $(MCU) -U lfuse:w:$(LFUSE):m \
		-U hfuse:w:$(HFUSE):m -U flash:w:$(HEXFILE)

os_assert.o: os_assert.c
	$(CC)gcc $(CFLAGS) $^ -o $@

os_cbk.o: os_cbk.c
	$(CC)gcc $(CFLAGS) $^ -o $@

os_event.o: os_event.c
	$(CC)gcc $(CFLAGS) $^ -o $@

os_kernel.o: os_kernel.c
	$(CC)gcc $(CFLAGS) $^ -o $@

os_msgqueue.o: os_msgqueue.c
	$(CC)gcc $(CFLAGS) $^ -o $@

os_sem.o: os_sem.c
	$(CC)gcc $(CFLAGS) $^ -o $@

os_task.o: os_task.c
	$(CC)gcc $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC)gcc $(CFLAGS) $^ -o $@

uart.o: uart.c
	$(CC)gcc $(CFLAGS) $^ -o $@

