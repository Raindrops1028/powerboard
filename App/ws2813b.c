#include "ws2813b.h"

#define DinH	GPIOA->BSRR = ((uint16_t)0x0008)  /* Set 1 for the pin of DI on ic(ws2813b)*/
#define DinL	GPIOA->BSRR = ((uint32_t)0x0008) << 16U /* clear 0 */
#define DELAY_100NS __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP()
#define DELAY_200NS DELAY_100NS;DELAY_100NS
#define DELAY_500NS DELAY_200NS;DELAY_200NS;DELAY_100NS
#define T0H DELAY_200NS;DELAY_100NS/*"0",hight level delay time*/
#define T0L DELAY_500NS;DELAY_500NS/*"0",low level delay time*/
#define T1L DELAY_200NS;DELAY_100NS/*"1",low level delay time*/
#define T1H DELAY_500NS;DELAY_500NS/*"1",hight level delay time*/
#define ZERO DinH;T0H;DinL;T0L
#define ONE  DinH;T1H;DinL;T1L
#define RESET DinL;HAL_Delay(1)/*delay 1ms to reset the ic*/

void turn_on_led(uint8_t led_num,uint32_t rgb_val)
{
//	RESET;
	for(uint8_t i = 0; i < led_num; i++)
	{
		for(uint32_t j = 24; j > 0; j--)
			{
				if(rgb_val&(0x01UL<<(j-1)))
				{ONE;}
				else
				{ZERO;}		
			}	
	}
//	DinH;	
}

void front_led(led_color led_cl)
{
	uint32_t rgb_val = 0x0;
	switch(led_cl)
	{
		case red:rgb_val = 0x00ff00;break;
		case green:rgb_val = 0xff0000;break;
		case blue:rgb_val = 0x0000ff;break;
		case purple:rgb_val = 0x800080;break;
		case yellow:rgb_val = 0xffff00;break;
		case white:rgb_val = 0xffffff;break;
		case black:rgb_val = 0x000000;break;
		case RoyalBlue:rgb_val = 0x4169e1;break;
		case DarkVoilet:rgb_val = 0x9400D3;break;		
		default:break;
	}
	turn_on_led(25,rgb_val);
}

 void running_led(void)
{
	front_led(white);
	HAL_Delay(5);
	front_led(black);
	HAL_Delay(5);	
//	set_led_color(green);
//	HAL_Delay(1000);
//	set_led_color(blude);
//	HAL_Delay(1000);	
//	set_led_color(purple);
//	HAL_Delay(1000);
//	set_led_color(yellow);
//	HAL_Delay(1000);
//	set_led_color(white);
//	HAL_Delay(1000); 
//	set_led_color(RoyalBlue);
//	HAL_Delay(1000);
//	set_led_color(DarkVoilet);
//	HAL_Delay(1000);		
}
