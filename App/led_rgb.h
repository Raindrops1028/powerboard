#ifndef __LED_RGB_H
#define __LED_RGB_H

#include <stdint.h>
#include "stm32f1xx_hal.h"

typedef struct rgb_val
{
	uint16_t r_val;
	uint16_t g_val;
	uint16_t b_val;
}RGB;

void mode_command(uint8_t cmd);
void user_pwm_setvalue(RGB value);
void red_led(void);
void green_led(void);
void blud_led(void);
void breath_leds(void);
void conver_leds(void);
#endif
