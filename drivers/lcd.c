
#include "config.h"
#include <stdint.h>
#include "lcd.h"
#include <util/delay.h>
#include <avr/io.h>

void lcd_write_4bits(uint8_t __byte)
{
	LCD_D7_PORT &= ~(1 << LCD_D7_PINNUM);
	if(__byte & (1 << 7))
		LCD_D7_PORT |= (1 << LCD_D7_PINNUM);

	LCD_D6_PORT &= ~(1 << LCD_D6_PINNUM);
	if(__byte & (1 << 7))
		LCD_D6_PORT |= (1 << LCD_D6_PINNUM);

	LCD_D5_PORT &= ~(1 << LCD_D5_PINNUM);
	if(__byte & (1 << 7))
		LCD_D5_PORT |= (1 << LCD_D5_PINNUM);

	LCD_D4_PORT &= ~(1 << LCD_D4_PINNUM);
	if(__byte & (1 << 7))
		LCD_D4_PORT |= (1 << LCD_D4_PINNUM);

	LCD_ENABLE_HIGH;
	_delay_us(EN_TRIGGER_DELAY);
	LCD_ENABLE_LOW;
	_delay_us(EN_TRIGGER_DELAY);
}

void lcd_write_inst(uint8_t __byte)
{
	LCD_RS_LOW;
	LCD_ENABLE_LOW;
	lcd_write_4bits(__byte);
	lcd_write_4bits(__byte << 4);
}

void lcd_write_char(uint8_t __byte)
{
	LCD_RS_HIGH;
	LCD_ENABLE_LOW;
	lcd_write_4bits(__byte);
	lcd_write_4bits(__byte << 4);
}

void lcd_set_xy(uint8_t _x, uint8_t _y)
{
	if(_x == 1)
		lcd_write_inst(0x80 + _y);
	else if(_x == 2)
		lcd_write_inst(0xC0 + _y);
}

void lcd_init(void)
{
	LCD_RS_DIR |= (1 << LCD_RS_PINNUM);
	LCD_EN_DIR |= (1 << LCD_EN_PINNUM);
	LCD_D7_DIR |= (1 << LCD_D7_PINNUM);
	LCD_D6_DIR |= (1 << LCD_D6_PINNUM);
	LCD_D5_DIR |= (1 << LCD_D5_PINNUM);
	LCD_D4_DIR |= (1 << LCD_D4_PINNUM);

	/* power up delay */
	_delay_ms(100);

	/* pull low RS */
	LCD_RS_LOW;

	/* pull low EN */
	LCD_ENABLE_LOW;

	lcd_write_4bits(lcd_FunctionReset);
	_delay_ms(10);

	lcd_write_4bits(lcd_FunctionReset);
	_delay_us(200);

	lcd_write_4bits(lcd_FunctionReset);
	_delay_us(200);

	lcd_write_4bits(lcd_FunctionSet4bit);
	_delay_us(80);

	lcd_write_char(lcd_DisplayOff);
	_delay_us(80);

	lcd_write_char(lcd_Clear);
	_delay_ms(4);

	lcd_write_char(lcd_EntryMode);
	_delay_us(80);

	lcd_write_char(lcd_DisplayOn);
	_delay_us(80);
}

void lcd_print(char * buff)
{
	uint8_t i;
	for(i = 0;buff[i] != '\0';i++)
	{
		if(buff[i] != '\r' && buff[i] != '\n')
		{
			lcd_write_char((uint8_t)buff[i]);
		}	
	}
}