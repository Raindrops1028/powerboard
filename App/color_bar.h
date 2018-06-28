#ifndef __COLOR_BAR_H__
#define __COLOR_BAR_H__
#include "common.h"

void mode_command(uint8_t cmd);
void all_pwm_value(RGB value);
void red_led(void);
void green_led(void);
void blue_led(void);
void breath_blue_led(void);
void running_leds(void);
void bottom_led(led_color led_cl);
#endif
