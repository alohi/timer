
#ifndef __lcd_h__
#define __lcd_h__

#define EN_TRIGGER_DELAY 	20

#define LCD_RS_DIR 			DDRD
#define LCD_RS_PORT			PORTD
#define LCD_RS_PINNUM		0

#define LCD_EN_DIR 			DDRD
#define LCD_EN_PORT			PORTD
#define LCD_EN_PINNUM		0

#define LCD_D4_DIR 			DDRD
#define LCD_D4_PORT			PORTD
#define LCD_D4_PINNUM		0

#define LCD_D5_DIR 			DDRD
#define LCD_D5_PORT			PORTD
#define LCD_D5_PINNUM		0

#define LCD_D6_DIR 			DDRD
#define LCD_D6_PORT			PORTD
#define LCD_D6_PINNUM		0

#define LCD_D7_DIR 			DDRD
#define LCD_D7_PORT			PORTD
#define LCD_D7_PINNUM		0

#define LCD_ENABLE_LOW 		LCD_EN_PORT |= 	(1 << LCD_EN_PINNUM)
#define LCD_ENABLE_HIGH 	LCD_EN_PORT &= 	~(1 << LCD_EN_PINNUM)
#define LCD_RS_LOW 			LCD_RS_PORT |= 	(1 << LCD_RS_PINNUM)
#define LCD_RS_HIGH 		LCD_RS_PORT &= 	~(1 << LCD_RS_PINNUM)

// LCD instructions
#define lcd_Clear           0b00000001          // replace all characters with ASCII 'space'
#define lcd_Home            0b00000010          // return cursor to first position on first line
#define lcd_EntryMode       0b00000110          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0b00001000          // turn display off
#define lcd_DisplayOn       0b00001100          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0b00110000          // reset the LCD
#define lcd_FunctionSet4bit 0b00101000          // 4-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0b10000000          // set cursor position


extern void lcd_init(void);
extern void lcd_write_4bits(uint8_t);
extern void lcd_write_inst(uint8_t);
extern void lcd_write_char(uint8_t);
extern void lcd_print(char *);
extern void lcd_set_xy(uint8_t, uint8_t);

#endif