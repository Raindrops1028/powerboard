#ifndef __COMMON_H__
#define __COMMON_H__
#include <stdint.h>
#include "stm32f1xx_hal.h"

typedef enum
{
  red = 0,
	green = 1,
	blue = 2,
	purple,
	yellow,
	white,
	black,
	RoyalBlue,
	DarkVoilet
}led_color;

typedef struct rgb_val
{
	uint16_t r_val;
	uint16_t g_val;
	uint16_t b_val;
}RGB;

#endif
