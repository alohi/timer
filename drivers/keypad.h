#ifndef __keypad_h__
#define __keypad_h__

#include <stdint.h>

/* switch debounce delay in milli seconds */
#define _SWITCH_DEB_DELAY 10

/* Keypad columns */
#define KEY_C0_DIR 			DDRD
#define KEY_C0_PORT			PORTD
#define KEY_C0_PIN 			PIND
#define KEY_C0_PINNUM		0

#define KEY_C1_DIR 			DDRD
#define KEY_C1_PORT			PORTD
#define KEY_C1_PIN 			PIND
#define KEY_C1_PINNUM		0

#define KEY_C2_DIR 			DDRD
#define KEY_C2_PORT			PORTD
#define KEY_C2_PIN 			PIND
#define KEY_C2_PINNUM		0

#define KEY_C3_DIR 			DDRD
#define KEY_C3_PORT			PORTD
#define KEY_C3_PIN 			PIND
#define KEY_C3_PINNUM		0

/* Keypad rows */
#define KEY_R0_DIR 			DDRD
#define KEY_R0_PORT			PORTD
#define KEY_R0_PIN 			PIND
#define KEY_R0_PINNUM		0

#define KEY_R1_DIR 			DDRD
#define KEY_R1_PORT			PORTD
#define KEY_R1_PIN 			PIND
#define KEY_R1_PINNUM		0

#define KEY_R2_DIR 			DDRD
#define KEY_R2_PORT			PORTD
#define KEY_R2_PIN 			PIND
#define KEY_R2_PINNUM		0

#define KEY_R3_DIR 			DDRD
#define KEY_R3_PORT			PORTD
#define KEY_R3_PIN 			PIND
#define KEY_R3_PINNUM		0

extern const uint8_t key_map[];

extern int8_t read_keypad(void);

#endif