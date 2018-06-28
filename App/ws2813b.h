#ifndef __WS2813B_H__
#define __WS2813B_H__
#include "common.h"

void turn_on_led(uint8_t led_num,uint32_t rgb_val);
void front_led(led_color led_cl);
void running_led(void);
#endif
