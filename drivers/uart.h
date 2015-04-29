#ifndef __uart_h__
#define __uart_h__

#define BAUD 9600

extern void 	uart_init(void);
extern void 	uart_putc(char);
extern void 	uart_puts(char *, uint16_t);
extern void 	uart_print(char *);
extern char 	uart_getc(void);

#endif